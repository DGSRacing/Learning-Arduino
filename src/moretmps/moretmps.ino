#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

//Pin Nymbers
#define ONE_WIRE_BUS_PIN 3

//Library Stuff
OneWire oneWire(ONE_WIRE_BUS_PIN);
DallasTemperature sensors(&oneWire);

//Addresses
DeviceAddress black = { 0x28, 0xFF, 0x1A, 0xAA, 0x62, 0x15, 0x03, 0x20 }; //black
DeviceAddress red = { 0x28, 0xFF, 0xA9, 0xB4, 0x62, 0x15, 0x03, 0x0C }; //red
DeviceAddress green = { 0x28, 0xFF, 0xF5, 0xB3, 0x62, 0x15, 0x03, 0x3E }; //green


void setup()
{
  Serial.begin(9600);
  Serial.println("BLACK | RED | GREEN");
  sensors.begin();
  sensors.setResolution(black, 10);
  sensors.setResolution(red, 10);
  sensors.setResolution(green, 10);
}

void loop()
{
  delay(100);
  sensors.requestTemperatures();  
 
  printTemperature(black);
  Serial.print(", ");
  printTemperature(red);
  Serial.print(", ");
  printTemperature(green);
  Serial.println();  
}

void printTemperature(DeviceAddress deviceAddress)
{

float tempC = sensors.getTempC(deviceAddress);

   if (tempC == -127.00) 
   {
   Serial.print("Error getting temperature ");
   } 
   else
   {
   Serial.print(tempC);
   }
}
