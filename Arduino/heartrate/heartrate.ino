#include <Wire.h>
#include <LiquidCrystal_I2C.h>  

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  lcd.init();  // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("HeartRate:");
  lcd.setCursor(0,1);
}

void loop()
{
      lcd.setCursor(0,1);
      lcd.print("82");
      delay(200);
 }
