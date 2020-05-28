#include <Wire.h>
#include <LiquidCrystal_I2C.h>  
//矩形波输入
LiquidCrystal_I2C lcd(0x27,16,2);

const byte dataPin = 2; //用2号引脚作为中断触发引脚
volatile long value = 0;
volatile unsigned long Time0;//当前时间
volatile unsigned long Time1;//第一次跳变的时间
volatile unsigned long Time2;//第二次跳变的时间
int m = 0;

void setup()
{
  pinMode(dataPin,INPUT_PULLUP);
  //将中断触发引脚（2号引脚）设置为INPUT_PULLUP（输入上拉）模式
  attachInterrupt(digitalPinToInterrupt(dataPin), ccount, FALLING);
  //设置中断触发程序
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
    if (m>0 & m%2 == 0){
    value = 60*1000000/(Time2-Time1);
    Serial.print("Heart Rate = ");
    Serial.print(value);
    Serial.println(" BPM.");
    lcd.setCursor(0,1);
    lcd.print(value);
    delay(200);
    lcd.print("      "); //清除
    }
 }
void ccount() { //中断执行程序
  Time0 = micros();
  if (m%2 == 0){
  Time1 = Time0;
  }else if (m>0 & m%2 == 1){
  Time2 = Time0;
  }
  m++;
}
