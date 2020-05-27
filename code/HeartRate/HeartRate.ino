#include <Wire.h>
#include <LiquidCrystal_I2C.h>  
LiquidCrystal_I2C lcd(0x27,16,2);

int sensorPin = A0; //模拟输入口
volatile long value = 0;

void setup()
{
  Serial.begin(9600);
  //设置波特率
  lcd.init();  
  lcd.setCursor(0,0);//光标位置
  lcd.print("HeartRate:");//LCD输出
  lcd.backlight();
  //背景光
}

void loop()
{ 
    value =analogRead(sensorPin);
    lcd.setCursor(0,1);
    lcd.print(value);
    delay(200);
    lcd.print("      "); //清除
 }
