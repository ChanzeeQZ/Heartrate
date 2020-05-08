# 1 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heart\\heart.ino"
# 2 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heart\\heart.ino" 2
# 3 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heart\\heart.ino" 2

LiquidCrystal_I2C lcd(0x27,16,2);

int datapin = 0;
int ledgreen = 1;

void setup()
{
  pinMode(ledgreen,0x1);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("HeartRate:");
  lcd.setCursor(0,1);
}

void loop()
{
      digitalWrite(ledgreen,0x1);
      float sensorV = analogRead(datapin);
      delay(1500);
      digitalWrite(ledgreen,0x0);
      lcd.setCursor(0,1);
      lcd.print(sensorV);
      delay(200);
 }
