#include <Wire.h>
#include <LiquidCrystal_I2C.h>  

LiquidCrystal_I2C lcd(0x27,16,2);

const byte dataPin = 2; //用2号引脚作为中断触发引脚
const byte switchPin = 3;
const byte ledPin = 0;//用0号引脚作为光源
volatile long xinLv = 0;
//double xinLv = 0;
void setup()
{
  pinMode(ledPin,OUTPUT);
  //将中断触发引脚（2号引脚）设置为INPUT_PULLUP（输入上拉）模式
  pinMode(dataPin,INPUT_PULLUP);
  pinMode(switchPin,INPUT);
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
  while (digitalRead(switchPin) == 1)//按下开关开始测量
  {
    lcd.print("      "); //清除
    xinLv = 0;
    for (int i=0;i<=250;i++)
    {
      digitalWrite(ledPin,HIGH);
      delay(10);
      digitalWrite(ledPin,LOW);
      delay(10);
    }
    xinLv = xinLv * 6; 
    //不理解为什么下降沿计数还是会变成原来的两倍
    //CHANGE也是两倍的关系。。。。
    lcd.setCursor(0,1);
    lcd.print(xinLv);
    digitalWrite(ledPin,LOW);
    delay(200);
  }
 }
void ccount() {
  xinLv++;
}
