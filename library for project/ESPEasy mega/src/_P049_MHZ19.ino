/*

  This plug in is written by Dmitry (rel22 ___ inbox.ru)
  Plugin is based upon SenseAir plugin by Daniel Tedenljung info__AT__tedenljungconsulting.com
  Additional features based on https://geektimes.ru/post/285572/ by Gerben (infernix__AT__gmail.com)

  This plugin reads the CO2 value from MH-Z19 NDIR Sensor
  DevicePin1 - is RX for ESP
  DevicePin2 - is TX for ESP
*/

#define PLUGIN_049
#define PLUGIN_ID_049         49
#define PLUGIN_NAME_049       "Gases - CO2 MH-Z19"
#define PLUGIN_VALUENAME1_049 "PPM"
#define PLUGIN_VALUENAME2_049 "Temperature" // Temperature in C
#define PLUGIN_VALUENAME3_049 "U" // Undocumented, minimum measurement per time period?
#define PLUGIN_READ_TIMEOUT   3000

#define PLUGIN_049_FILTER_OFF        1
#define PLUGIN_049_FILTER_OFF_ALLSAMPLES 2
#define PLUGIN_049_FILTER_FAST       3
#define PLUGIN_049_FILTER_MEDIUM     4
#define PLUGIN_049_FILTER_SLOW       5

boolean Plugin_049_init = false;
// Default of the sensor is to run ABC
boolean Plugin_049_ABC_Disable = false;
boolean Plugin_049_ABC_MustApply = false;

#include <ESPeasySoftwareSerial.h>
ESPeasySoftwareSerial *Plugin_049_SoftSerial;

enum mhzCommands : byte { mhzCmdReadPPM,
                          mhzCmdCalibrateZero,
                          mhzCmdABCEnable,
                          mhzCmdABCDisable,
                          mhzCmdReset,
                          mhzCmdMeasurementRange1000,
                          mhzCmdMeasurementRange2000,
                          mhzCmdMeasurementRange3000,
                          mhzCmdMeasurementRange5000 };
// 9 byte commands:
// mhzCmdReadPPM[]              = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
// mhzCmdCalibrateZero[]        = {0xFF,0x01,0x87,0x00,0x00,0x00,0x00,0x00,0x78};
// mhzCmdABCEnable[]            = {0xFF,0x01,0x79,0xA0,0x00,0x00,0x00,0x00,0xE6};
// mhzCmdABCDisable[]           = {0xFF,0x01,0x79,0x00,0x00,0x00,0x00,0x00,0x86};
// mhzCmdReset[]                = {0xFF,0x01,0x8d,0x00,0x00,0x00,0x00,0x00,0x72};
// mhzCmdMeasurementRange1000[] = {0xFF,0x01,0x99,0x03,0xE8,0x00,0x00,0x00,0x7B};
// mhzCmdMeasurementRange2000[] = {0xFF,0x01,0x99,0x07,0xD0,0x00,0x00,0x00,0x8F};
// mhzCmdMeasurementRange3000[] = {0xFF,0x01,0x99,0x0B,0xB8,0x00,0x00,0x00,0xA3};
// mhzCmdMeasurementRange5000[] = {0xFF,0x01,0x99,0x13,0x88,0x00,0x00,0x00,0xCB};
// Removing redundant data, just keeping offsets [2]..[4]:
const PROGMEM byte mhzCmdData[][3] = {
  {0x86,0x00,0x00},
  {0x87,0x00,0x00},
  {0x79,0xA0,0x00},
  {0x79,0x00,0x00},
  {0x8d,0x00,0x00},
  {0x99,0x03,0xE8},
  {0x99,0x07,0xD0},
  {0x99,0x0B,0xB8},
  {0x99,0x13,0x88}};

byte mhzResp[9];    // 9 byte response buffer

enum
{
  ABC_enabled  = 0x01,
  ABC_disabled = 0x02
};

boolean Plugin_049_Check_and_ApplyFilter(unsigned int prevVal, unsigned int &newVal, uint32_t s, const int filterValue, String& log) {
  if (s == 1) {
    // S==1 => "A" version sensor bootup, do not use values.
    return false;
  }
  if (prevVal < 400 || prevVal > 5000) {
    // Prevent unrealistic values during start-up with filtering enabled.
    // Just assume the entered value is correct.
    return true;
  }
  boolean filterApplied = filterValue > PLUGIN_049_FILTER_OFF_ALLSAMPLES;
  int32_t difference = newVal - prevVal;
  if (s > 0 && s < 64 && filterValue != PLUGIN_049_FILTER_OFF) {
    // Not the "B" version of the sensor, S value is used.
    // S==0 => "B" version, else "A" version
    // The S value is an indication of the stability of the reading.
    // S == 64 represents a stable reading and any lower value indicates (unusual) fast change.
    // Now we increase the delay filter for low values of S and increase response time when the
    // value is more stable.
    // This will make the reading useful in more turbulent environments,
    // where the sensor would report more rapid change of measured values.
    difference = difference * s;
    difference /= 64;
    log += F("Compensate Unstable ");
    filterApplied = true;
  }
  switch (filterValue) {
    case PLUGIN_049_FILTER_OFF: {
      if (s != 0 && s != 64) {
        log += F("Skip Unstable ");
        return false;
      }
      filterApplied = false;
      break;
    }
                                                  // #Samples to reach >= 75% of step response
    case PLUGIN_049_FILTER_OFF_ALLSAMPLES: filterApplied = false; break; // No Delay
    case PLUGIN_049_FILTER_FAST:    difference /= 2; break; // Delay: 2 samples
    case PLUGIN_049_FILTER_MEDIUM:  difference /= 4; break; // Delay: 5 samples
    case PLUGIN_049_FILTER_SLOW:    difference /= 8; break; // Delay: 11 samples
  }
  if (filterApplied) {
    log += F("Raw PPM: ");
    log += newVal;
    log += F(" Filtered ");
  }
  newVal = static_cast<unsigned int>(prevVal + difference);
  return true;
}

boolean Plugin_049(byte function, struct EventStruct *event, String& string)
{
  bool success = false;

  switch (function)
  {

    case PLUGIN_DEVICE_ADD:
      {
        Device[++deviceCount].Number = PLUGIN_ID_049;
        Device[deviceCount].Type = DEVICE_TYPE_DUAL;
        Device[deviceCount].VType = SENSOR_TYPE_TRIPLE;
        Device[deviceCount].Ports = 0;
        Device[deviceCount].PullUpOption = false;
        Device[deviceCount].InverseLogicOption = false;
        Device[deviceCount].FormulaOption = true;
        Device[deviceCount].ValueCount = 3;
        Device[deviceCount].SendDataOption = true;
        Device[deviceCount].TimerOption = true;
        Device[deviceCount].GlobalSyncOption = true;
        break;
      }

    case PLUGIN_GET_DEVICENAME:
      {
        string = F(PLUGIN_NAME_049);
        break;
      }

    case PLUGIN_GET_DEVICEVALUENAMES:
      {
        strcpy_P(ExtraTaskSettings.TaskDeviceValueNames[0], PSTR(PLUGIN_VALUENAME1_049));
        strcpy_P(ExtraTaskSettings.TaskDeviceValueNames[1], PSTR(PLUGIN_VALUENAME2_049));
        strcpy_P(ExtraTaskSettings.TaskDeviceValueNames[2], PSTR(PLUGIN_VALUENAME3_049));
        break;
      }

    case PLUGIN_WEBFORM_LOAD:
      {
        byte choice = Settings.TaskDevicePluginConfig[event->TaskIndex][0];
        String options[2] = { F("Normal"), F("ABC disabled") };
        int optionValues[2] = { ABC_enabled, ABC_disabled };
        addFormSelector(string, F("Auto Base Calibration"), F("plugin_049_abcdisable"), 2, options, optionValues, choice);
        byte choiceFilter = Settings.TaskDevicePluginConfig[event->TaskIndex][1];
        String filteroptions[5] = { F("Skip Unstable"), F("Use Unstable"), F("Fast Response"), F("Medium Response"), F("Slow Response") };
        int filteroptionValues[5] = {
          PLUGIN_049_FILTER_OFF,
          PLUGIN_049_FILTER_OFF_ALLSAMPLES,
          PLUGIN_049_FILTER_FAST,
          PLUGIN_049_FILTER_MEDIUM,
          PLUGIN_049_FILTER_SLOW };
        addFormSelector(string, F("Filter"), F("plugin_049_filter"), 5, filteroptions, filteroptionValues, choiceFilter);

        success = true;
        break;
      }

    case PLUGIN_WEBFORM_SAVE:
      {
        const int formValue = getFormItemInt(F("plugin_049_abcdisable"));
        boolean new_ABC_disable = (formValue == ABC_disabled);
        if (Plugin_049_ABC_Disable != new_ABC_disable) {
          // Setting changed in the webform.
          Plugin_049_ABC_MustApply = true;
          Plugin_049_ABC_Disable = new_ABC_disable;
        }
        Settings.TaskDevicePluginConfig[event->TaskIndex][0] = formValue;
        const int filterValue = getFormItemInt(F("plugin_049_filter"));
        Settings.TaskDevicePluginConfig[event->TaskIndex][1] = filterValue;
        success = true;
        break;
      }

    case PLUGIN_INIT:
      {
        Plugin_049_ABC_Disable = Settings.TaskDevicePluginConfig[event->TaskIndex][0] == ABC_disabled;
        if (Plugin_049_ABC_Disable) {
          // No guarantee the correct state is active on the sensor after reboot.
          Plugin_049_ABC_MustApply = true;
        }
        Plugin_049_SoftSerial = new ESPeasySoftwareSerial(Settings.TaskDevicePin1[event->TaskIndex], Settings.TaskDevicePin2[event->TaskIndex]);
        Plugin_049_SoftSerial->begin(9600);
        addLog(LOG_LEVEL_INFO, F("MHZ19: Init OK "));

        //delay first read, because hardware needs to initialize on cold boot
        //otherwise we get a weird value or read error
        timerSensor[event->TaskIndex] = millis() + 15000;

        Plugin_049_init = true;
        success = true;
        break;
      }

    case PLUGIN_WRITE:
      {
        String command = parseString(string, 1);

        if (command == F("mhzcalibratezero"))
        {
          _P049_send_mhzCmd(mhzCmdCalibrateZero);
          addLog(LOG_LEVEL_INFO, F("MHZ19: Calibrated zero point!"));
          success = true;
        }

        if (command == F("mhzreset"))
        {
          _P049_send_mhzCmd(mhzCmdReset);
          addLog(LOG_LEVEL_INFO, F("MHZ19: Sent sensor reset!"));
          success = true;
        }

        if (command == F("mhzabcenable"))
        {
          _P049_send_mhzCmd(mhzCmdABCEnable);
          addLog(LOG_LEVEL_INFO, F("MHZ19: Sent sensor ABC Enable!"));
          success = true;
        }

        if (command == F("mhzabcdisable"))
        {
          _P049_send_mhzCmd(mhzCmdABCDisable);
          addLog(LOG_LEVEL_INFO, F("MHZ19: Sent sensor ABC Disable!"));
          success = true;
        }

        if (command == F("mhzmeasurementrange1000"))
        {
          _P049_send_mhzCmd(mhzCmdMeasurementRange1000);
          addLog(LOG_LEVEL_INFO, F("MHZ19: Sent measurement range 0-1000PPM!"));
          success = true;
        }

        if (command == F("mhzmeasurementrange2000"))
        {
          _P049_send_mhzCmd(mhzCmdMeasurementRange2000);
          addLog(LOG_LEVEL_INFO, F("MHZ19: Sent measurement range 0-2000PPM!"));
          success = true;
        }

        if (command == F("mhzmeasurementrange3000"))
        {
          _P049_send_mhzCmd(mhzCmdMeasurementRange3000);
          addLog(LOG_LEVEL_INFO, F("MHZ19: Sent measurement range 0-3000PPM!"));
          success = true;
        }

        if (command == F("mhzmeasurementrange5000"))
        {
          _P049_send_mhzCmd(mhzCmdMeasurementRange5000);
          addLog(LOG_LEVEL_INFO, F("MHZ19: Sent measurement range 0-5000PPM!"));
          success = true;
        }
        break;

      }

    case PLUGIN_READ:
      {

        if (Plugin_049_init)
        {
          //send read PPM command
          byte nbBytesSent = _P049_send_mhzCmd(mhzCmdReadPPM);
          if (nbBytesSent != 9) {
            String log = F("MHZ19: Error, nb bytes sent != 9 : ");
              log += nbBytesSent;
              addLog(LOG_LEVEL_INFO, log);
          }

          // get response
          memset(mhzResp, 0, sizeof(mhzResp));

          long timer = millis() + PLUGIN_READ_TIMEOUT;
          int counter = 0;
          while (!timeOutReached(timer) && (counter < 9)) {
            if (Plugin_049_SoftSerial->available() > 0) {
              mhzResp[counter++] = Plugin_049_SoftSerial->read();
            } else {
              delay(10);
            }
          }
          if (counter < 9){
              addLog(LOG_LEVEL_INFO, F("MHZ19: Error, timeout while trying to read"));
          }

          unsigned int ppm = 0;
          signed int temp = 0;
          unsigned int s = 0;
          float u = 0;
          byte checksum = _P049_calculateChecksum(mhzResp);

          if ( !(mhzResp[8] == checksum) ) {
             String log = F("MHZ19: Read error: checksum = ");
             log += String(checksum); log += " / "; log += String(mhzResp[8]);
             log += " bytes read  => ";for (byte i = 0; i < 9; i++) {log += mhzResp[i];log += "/" ;}
             addLog(LOG_LEVEL_ERROR, log);

             // Sometimes there is a misalignment in the serial read
             // and the starting byte 0xFF isn't the first read byte.
             // This goes on forever.
             // There must be a better way to handle this, but here
             // we're trying to shift it so that 0xFF is the next byte
             byte checksum_shift;
             for (byte i = 1; i < 8; i++) {
                checksum_shift = Plugin_049_SoftSerial->peek();
                if (checksum_shift == 0xFF) {
                  String log = F("MHZ19: Shifted ");
                  log += i;
                  log += F(" bytes to attempt to fix buffer alignment");
                  addLog(LOG_LEVEL_ERROR, log);
                  break;
                } else {
                 checksum_shift = Plugin_049_SoftSerial->read();
                }
             }
             success = false;
             break;

          // Process responses to 0x86
          } else if (mhzResp[0] == 0xFF && mhzResp[1] == 0x86 && mhzResp[8] == checksum)  {

              //calculate CO2 PPM
              unsigned int mhzRespHigh = (unsigned int) mhzResp[2];
              unsigned int mhzRespLow = (unsigned int) mhzResp[3];
              ppm = (256*mhzRespHigh) + mhzRespLow;

              // set temperature (offset 40)
              unsigned int mhzRespTemp = (unsigned int) mhzResp[4];
              temp = mhzRespTemp - 40;

              // set 's' (stability) value
              unsigned int mhzRespS = (unsigned int) mhzResp[5];
              s = mhzRespS;

              // calculate 'u' value
              unsigned int mhzRespUHigh = (unsigned int) mhzResp[6];
              unsigned int mhzRespULow = (unsigned int) mhzResp[7];
              u = (256*mhzRespUHigh) + mhzRespULow;

              String log = F("MHZ19: ");

              // During (and only ever at) sensor boot, 'u' is reported as 15000
              // We log but don't process readings during that time
              if (u == 15000) {

                log += F("Bootup detected! ");
                if (Plugin_049_ABC_Disable) {
                  // After bootup of the sensor the ABC will be enabled.
                  // Thus only actively disable after bootup.
                  Plugin_049_ABC_MustApply = true;
                  log += F("Will disable ABC when bootup complete. ");
                }
                success = false;
              // Finally, stable readings are used for variables
              } else {
                const int filterValue = Settings.TaskDevicePluginConfig[event->TaskIndex][1];
                if (Plugin_049_Check_and_ApplyFilter(UserVar[event->BaseVarIndex], ppm, s, filterValue, log)) {
                  UserVar[event->BaseVarIndex] = (float)ppm;
                  UserVar[event->BaseVarIndex + 1] = (float)temp;
                  UserVar[event->BaseVarIndex + 2] = (float)u;
                  if (s==0 || s==64) {
                    // Reading is stable.
                    if (Plugin_049_ABC_MustApply) {
                      // Send ABC enable/disable command based on the desired state.
                      if (Plugin_049_ABC_Disable) {
                        _P049_send_mhzCmd(mhzCmdABCDisable);
                        addLog(LOG_LEVEL_INFO, F("MHZ19: Sent sensor ABC Disable!"));
                      } else {
                        _P049_send_mhzCmd(mhzCmdABCEnable);
                        addLog(LOG_LEVEL_INFO, F("MHZ19: Sent sensor ABC Enable!"));
                      }
                      Plugin_049_ABC_MustApply = false;
                    }
                  }
                  success = true;
                } else {
                  success = false;
                }
              }

              // Log values in all cases
              log += F("PPM value: ");
              log += ppm;
              log += F(" Temp/S/U values: ");
              log += temp;
              log += F("/");
              log += s;
              log += F("/");
              log += u;
              addLog(LOG_LEVEL_INFO, log);
              break;

          // Sensor responds with 0x99 whenever we send it a measurement range adjustment
          } else if (mhzResp[0] == 0xFF && mhzResp[1] == 0x99 && mhzResp[8] == checksum)  {

            addLog(LOG_LEVEL_INFO, F("MHZ19: Received measurement range acknowledgment! "));
            addLog(LOG_LEVEL_INFO, F("Expecting sensor reset..."));
            success = false;
            break;

          // log verbosely anything else that the sensor reports
          } else {

              String log = F("MHZ19: Unknown response:");
              for (int i = 0; i < 9; ++i) {
                log += F(" ");
                log += String(mhzResp[i], HEX);
              }
              addLog(LOG_LEVEL_INFO, log);
              success = false;
              break;

          }

        }
        break;
      }
  }
  return success;
}

byte _P049_calculateChecksum(byte *array)
{
  byte checksum = 0;
  for (byte i = 1; i < 8; i++)
    checksum+=array[i];
  checksum = 0xFF - checksum;
  return (checksum+1);
}

size_t _P049_send_mhzCmd(byte CommandId)
{
  // The receive buffer "mhzResp" is re-used to send a command here:
  mhzResp[0] = 0xFF; // Start byte, fixed
  mhzResp[1] = 0x01; // Sensor number, 0x01 by default
  memcpy_P(&mhzResp[2], mhzCmdData[CommandId], sizeof(mhzCmdData[0]));
  mhzResp[5] = mhzResp[6] = mhzResp[7] = 0x00;
  mhzResp[8] = _P049_calculateChecksum(mhzResp);

  return Plugin_049_SoftSerial->write(mhzResp, sizeof(mhzResp));
}
