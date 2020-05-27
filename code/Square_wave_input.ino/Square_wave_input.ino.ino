#include <Wire.h>
#include <LiquidCrystal_I2C.h>  
//等待6s然后才能读到波形
LiquidCrystal_I2C lcd(0x27,16,2);

const byte dataPin = 2; //用2号引脚作为中断触发引脚
volatile long xinLv = 0;
//double xinLv = 0;

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
  delay(200);
}

void loop()
{ 
    lcd.print("      "); //清除
    xinLv = 0;
    delay(6000);//延时6s
    xinLv = xinLv * 5; 
    //不理解为什么下降沿计数还是会变成原来的两倍
    //CHANGE也是两倍的关系。。。。
    lcd.setCursor(0,1);
    lcd.print(xinLv);
 }
void ccount() {
  xinLv++;
}
