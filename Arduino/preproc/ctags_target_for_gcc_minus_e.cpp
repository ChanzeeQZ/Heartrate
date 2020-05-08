# 1 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heartrate\\heartrate.ino"
# 2 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heartrate\\heartrate.ino" 2
# 3 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heartrate\\heartrate.ino" 2

LiquidCrystal_I2C lcd(0x27,16,2);

//int l2_x=0;
//int dir=1;

void setup()
{
  lcd.init(); // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("HeartRate:");
  lcd.setCursor(0,1);
  //lcd.print("LOADING...");
  //delay(100);
}

void loop()
{
  //if(l2_x >=0 && l2_x <=9)
   // {
   //   lcd.setCursor(0,1);
   //   lcd.print("                ");
   //   lcd.setCursor(l2_x,1);
      lcd.setCursor(0,1);
      lcd.print("82");
      delay(200);
  //  }
 /* l2_x=l2_x+dir;

  if(l2_x > 9)

    dir=-1;

  if(l2_x < 0)

    dir=1;*/
# 37 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heartrate\\heartrate.ino"
 }
