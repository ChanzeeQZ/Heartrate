#include <Arduino.h>
#line 1 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heart\\heart.ino"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>  

LiquidCrystal_I2C lcd(0x27,16,2);

const byte dataPin = 2; //用2号引脚作为中断触发引脚
const byte ledgreen = 13;
volatile long xinLv = 0;
//double xinLv = 0;
#line 10 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heart\\heart.ino"
void setup();
#line 24 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heart\\heart.ino"
void loop();
#line 41 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heart\\heart.ino"
void ccount();
#line 10 "C:\\zhangQianZhe\\Git_Chanzee\\Heartrate\\Arduino\\heart\\heart.ino"
void setup()
{
  pinMode(ledgreen,OUTPUT);
  //将中断触发引脚（2号引脚）设置为INPUT_PULLUP（输入上拉）模式
  pinMode(dataPin,INPUT_PULLUP);
  //设置中断触发程序
  attachInterrupt(digitalPinToInterrupt(dataPin), ccount, FALLING);
  Serial.begin(9600);
  lcd.init();  
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("HeartRate:");
}

void loop()
{
  xinLv = 0;
  for (int i=0;i<=250;i++)
  {
    digitalWrite(ledgreen,HIGH);
    delay(10);
    digitalWrite(ledgreen,LOW);
    delay(10);
  }
  xinLv = xinLv * 6;
  lcd.setCursor(0,1);
  lcd.print(xinLv);
  digitalWrite(ledgreen,LOW);
  delay(200);
  
 }
 void ccount() {
  xinLv++;
}

