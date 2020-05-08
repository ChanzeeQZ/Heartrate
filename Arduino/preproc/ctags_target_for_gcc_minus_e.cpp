# 1 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heart\\heart.ino"
# 2 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heart\\heart.ino" 2
# 3 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heart\\heart.ino" 2

LiquidCrystal_I2C lcd(0x27,16,2);

const byte dataPin = 2; //用2号引脚作为中断触发引脚
const byte switchPin = 3;
const byte ledPin = 0;//用0号引脚作为光源
volatile long xinLv = 0;
//double xinLv = 0;
void setup()
{
  pinMode(ledPin,0x1);
  //将中断触发引脚（2号引脚）设置为INPUT_PULLUP（输入上拉）模式
  pinMode(dataPin,0x2);
  pinMode(switchPin,0x0);
  //设置中断触发程序
  attachInterrupt(((dataPin) == 2 ? 0 : ((dataPin) == 3 ? 1 : -1)), ccount, 2);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("HeartRate:");
}

void loop()
{
  while (digitalRead(switchPin) == 1)
  {
  lcd.print("      "); //清除
  xinLv = 0;
  for (int i=0;i<=250;i++)
  {
    digitalWrite(ledPin,0x1);
    delay(10);
    digitalWrite(ledPin,0x0);
    delay(10);
  }
  xinLv = xinLv * 6;
  lcd.setCursor(0,1);
  lcd.print(xinLv);
  digitalWrite(ledPin,0x0);
  delay(200);
  }
  digitalWrite(ledPin,0x0);
 }
 void ccount() {
  xinLv++;
}
