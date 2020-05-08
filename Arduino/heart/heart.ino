#include <Wire.h>
#include <LiquidCrystal_I2C.h>  

LiquidCrystal_I2C lcd(0x27,16,2);

int datapin = 0;
int ledgreen = 1;

void setup()
{
  pinMode(ledgreen,OUTPUT);
  lcd.init();  
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("HeartRate:");
  lcd.setCursor(0,1);
}

void loop()
{
      digitalWrite(ledgreen,HIGH);
      float sensorV = analogRead(datapin);
      delay(1500);
      digitalWrite(ledgreen,LOW);
      lcd.setCursor(0,1);
      lcd.print(sensorV);
      delay(200);
 }
