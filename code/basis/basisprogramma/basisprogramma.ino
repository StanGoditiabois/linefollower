#include "SerialCommand.h"
#include "EEPROMAnything.h"
#include "BluetoothSerial.h"
#include <EEPROM.h>

#define SerialPort SerialBT
BluetoothSerial SerialPort;
SerialCommand sCmd(SerialPort);

unsigned long previous, calculationTime;
volatile bool run = false;

struct param_t
{
  unsigned long cycleTime;
} params;

#define EEPROM_SIZE sizeof(param_t)

void setup()
{
  SerialPort.begin("ESP32_stanG");

  sCmd.addCommand("set", onSet);
  sCmd.addCommand("debug", onDebug);
  sCmd.addCommand("run", onRun);
  sCmd.setDefaultHandler(onUnknownCommand);

  pinMode(23,INPUT);
  attachInterrupt(23,aan,RISING);
  pinMode(22,INPUT);
  attachInterrupt(22,uit,RISING);

  EEPROM.begin(EEPROM_SIZE);
  EEPROM.get(0, params);
  EEPROM.end();
  SerialPort.println("ready");
}

void loop()
{
  sCmd.readSerial();
  unsigned long current = micros();
  if(current - previous >= params.cycleTime)
  {
    if (run)
    {
      previous = current;
    
    }
  }

  unsigned long difference = micros() - current;
  if (difference > calculationTime) calculationTime = difference;
}

void onUnknownCommand(char *command)
{
  SerialPort.print("unknown command: \"");
  SerialPort.print(command);
  SerialPort.println("\"");
}

void onSet()
{
  char* param = sCmd.next();
  char* value = sCmd.next();

  if (strcmp(param, "cycle") == 0) params.cycleTime = atol(value);

  EEPROM.begin(EEPROM_SIZE);
  EEPROM.put(0, params);
  EEPROM.commit();
  EEPROM.end();
}

void onDebug()
{
  SerialPort.print("cycle time: ");
  SerialPort.println(params.cycleTime);
  
  /* parameters weergeven met behulp van het debug commando doe je hier ... */
  
  SerialPort.print("calculation time: ");
  SerialPort.println(calculationTime);
  calculationTime = 0;
}

void onRun()
{
  char* param = sCmd.next();

  if (strcmp(param, "aan") == 0) 
  {
    run = true;
  }
  else if (strcmp(param, "uit") == 0) run = false; 
}

void aan()
{
  run = true;
}

void uit()
{
  run = false;
}