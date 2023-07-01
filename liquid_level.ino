#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 

const int trigPin = 2;      
const int echoPin = 3;      
const float tankLength = 1.0;  
const float tankWidth = 1.0;  
const float tankHeight = 1.0;   
const float litersConversion = 1000.0; 
const float cmToMetersConversion = 0.01; 

float liquidLevel;          
float tankVolume;          
float tankCapacity;         
int percentage;            


void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop() {

  float distance = getDistance();
  float distanceMeters = distance * cmToMetersConversion;
  liquidLevel = tankHeight - distanceMeters;
  tankVolume = tankLength * tankWidth * liquidLevel;
  tankCapacity = tankLength * tankWidth * tankHeight;
  percentage = (liquidLevel / tankHeight) * 100;
  float volumeLiters = tankVolume * litersConversion;
  
  // Update LCD display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(liquidLevel);
  lcd.print("m");
  lcd.setCursor(8, 0);
  lcd.print(volumeLiters, 1);
  lcd.print("lt");
  lcd.setCursor(0, 1);
  lcd.print(percentage);
  lcd.print("%");

  delay(4000); 
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;  
  return distance;
}
