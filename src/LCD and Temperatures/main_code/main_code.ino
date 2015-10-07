#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;

//Pin Nymbers
#define ONE_WIRE_BUS_PIN 6


//Library Stuff
OneWire oneWire(ONE_WIRE_BUS_PIN);
DallasTemperature sensors(&oneWire);

//Addresses
DeviceAddress black = { 0x28, 0xFF, 0x1A, 0xAA, 0x62, 0x15, 0x03, 0x20 }; //black
DeviceAddress red = { 0x28, 0xFF, 0xA9, 0xB4, 0x62, 0x15, 0x03, 0x0C }; //red
DeviceAddress green = { 0x28, 0xFF, 0xF5, 0xB3, 0x62, 0x15, 0x03, 0x3E }; //green


void setup()
{
  sensors.begin();
  sensors.setResolution(black, 10);
  sensors.setResolution(red, 10);
  sensors.setResolution(green, 10);
  pinMode(switchPin, INPUT);
}

void loop()
{
  //delay(delay_time);
  sensors.requestTemperatures();  
  
  delay(2000);
  lcd.begin(16, 2);
  lcd.print("DGS Racing");
  lcd.setCursor(0, 1);
  lcd.print("Black = ");
  printTemperature(black);
 
  delay(2000);
  lcd.clear();
  lcd.print("DGS Racing");
  lcd.setCursor(0, 1);
  lcd.print("Red   = ");
  printTemperature(red);
  
  delay(2000);
  lcd.clear();
  lcd.print("DGS Racing");
  lcd.setCursor(0, 1);
  lcd.print("Green = ");
  printTemperature(green);
  
  //lcd.print(getTemperature(red));
}

void printTemperature(DeviceAddress deviceAddress)
{

float tempC = sensors.getTempC(deviceAddress);

   if (tempC == -127.00) 
   {
    lcd.print("Failed");
   } 
   else
   {
    lcd.print(tempC);
   }
}
