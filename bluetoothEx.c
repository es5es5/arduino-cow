#include <SoftwareSerial.h>

SoftwareSerial BlueTooth(6, 7); // RX, TX
SoftwareSerial RFIDSerial(9, 10); // RX, TX

const int SWITCH = 2; // The input switch is connected to pin 2
boolean lastSwitch = LOW; //variable containing previous switch state
boolean currentSwitch = LOW; //variable containing current switch state

boolean state = false; // The input state toggleFALSE=LOW and TRUE=HIGH
unsigned long switchtime = 0;   // Time of latest switch change
unsigned long lastswitchtime = 0; // Time of previous switch change
unsigned long zerotime = 0; //to store time of zeroing so can be subtracted from switch time
int OnCount = 0; //counts the ON switches
int OffCount = 0;  //counts the OFF switches
char message = 0; //incoming message as a single character
String SketchVersion = "2015.1";              //version of this sketch
String Copyright = "Copyright 2015 Innervations"; //copyright
String SerialNumber = "OK00001"; //serial numer assigned to Arduino
String ArduinoModel = "ArduinoUNO"; //model of Arduino

void setup()
{
  // Set up digital pin 2 to be an input
  pinMode(SWITCH, INPUT); //make it an input

  // initialize serial communication at 9600 bits per second:
  BlueTooth.begin(9600);
  RFIDSerial.begin(9600); // This is the line of code that stops the Bluetooth connection working
  zerotime=millis();
}

void loop()
{
  currentSwitch = digitalRead(SWITCH);
  if (currentSwitch != lastSwitch) //change of switch status
   {
     switchtime=millis()-zerotime;
    if (switchtime - lastswitchtime >10) //try to ignore switch bounce
      {
        if (currentSwitch == HIGH) { OnCount ++; BlueTooth.print(SerialNumber); BlueTooth.print("_"); BlueTooth.print(OnCount); BlueTooth.print("_ON_"); BlueTooth.print(switchtime); BlueTooth.println("#"); }
        if (currentSwitch == LOW) { OffCount ++; BlueTooth.print(SerialNumber); BlueTooth.print("_"); BlueTooth.print(OffCount); BlueTooth.print("_OFF_"); BlueTooth.print(switchtime); BlueTooth.println("#"); }
      switchtime = lastswitchtime;
      lastSwitch=currentSwitch;
    }
  }
  //check for messages from the PC
  if (BlueTooth.available() > 0) {
    // read the incoming message byte from the PC:
    message = BlueTooth.read();
    ProcessMessage(message);
  }
  //check for messages from the RFID Reader
  if (RFIDSerial.available() > 0) {
    // read the incoming RFID data and immediately write this out to the PC over Bluetooth:
    BlueTooth.write(RFIDSerial.read());
  }
}

void arduinoinfo()
{
  BlueTooth.println("Model " + ArduinoModel);
  BlueTooth.println("SerialNumber " + SerialNumber);
  BlueTooth.println("Sketch Version " + SketchVersion);
  BlueTooth.println(Copyright);
}

void ProcessMessage(char msg)
{
  switch (msg) {
    case 'm':
      BlueTooth.println("Model " + ArduinoModel);
      break;
    case 's':
      BlueTooth.println("SerialNumber " + SerialNumber);
      break;
    case 'v':
      BlueTooth.println("Sketch Version " + SketchVersion);
      break;
    case 'c':
      BlueTooth.println(Copyright);
      break;
    case 'z': //reset the counts
      OnCount = 0;
      OffCount = 0;
      zerotime=millis();
      break;
  }
}
