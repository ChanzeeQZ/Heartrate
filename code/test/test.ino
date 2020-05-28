/***********************声明功能函数********************/

void InputVoltageMeasurement();                    //测量输入电压，并发送至串口
void FrequencyDutyMeasurement();                //测量输入信号的频率、占空比，并将测量值发送到串口
void OverVoltageAlarm();                        //过压报警
/*********************************************************/

/************************定义引脚************************/

#define InputVoltagePin A0
#define SquareWave 2
#define Buzzer 3

/*********************************************************/

/***********************定义变量*************************/

float InputVoltage;
volatile unsigned long CurrentTime;                //当前时间
volatile unsigned long FirstTime;                //第一次跳变的时间
volatile unsigned long SecondTime;                //第二次跳变的时间
unsigned long Frequency;
unsigned long DutyRatio;                        //占空比
volatile unsigned long Time_99;                  //计数99次跳变的时间
volatile unsigned long Time_199;                 //计数199次跳变的时间
int Shift;                                        //测量档位

/*********************************************************/

/***********************定义常量*************************/

#define InputPartialRatio (0.3429)                //定义输入分压比
#define SamplingTime_s (0.0001)                    //ADC采样一次所花费的时间

/*********************************************************/

void setup()
{
    pinMode(SquareWave,INPUT);
    Serial.begin(9600);
    Serial.println("This is a frequency meter!");
    Shift=1;                                    //默认档位是1挡
    Frequency=20;                                //默认频率是20HZ
}

void loop()
{
    InputVoltageMeasurement();
    if(InputVoltage<=7.5)
        FrequencyDutyMeasurement();
    else
        OverVoltageAlarm();
}

void InputVoltageMeasurement()                    //测量输入电压，并发送至串口
{
    int SingleCycleSamplingPoints;                //采样点数
    if(Frequency<=100)                            //保证在频率范围内都能够采到至少100个点
        SingleCycleSamplingPoints=1/(SamplingTime_s*Frequency);            //根据频率智能计算采样点数
    else
        SingleCycleSamplingPoints=100/(SamplingTime_s*Frequency);
    float Peak=(((analogRead(InputVoltagePin))/1023.0)*5.0)/InputPartialRatio;    //在众多的采样点中找到峰值
    for(int p=1;p<SingleCycleSamplingPoints;p++)
    {
        float CurrentValue=(((analogRead(InputVoltagePin))/1023.0)*5.0)/InputPartialRatio;
        if(CurrentValue>Peak)
            Peak=CurrentValue;
    }
    InputVoltage=Peak;                            //认为输入电压就是峰值电压
    Serial.println();                            //串口输出
    Serial.print("InputVoltage=");
    Serial.print(InputVoltage);
    Serial.println("V");
}

void FrequencyDutyMeasurement()                    //测量输入信号的频率、占空比，并将测量值发送到串口
{
  volatile int i=digitalRead(SquareWave);       //先看现在是高电平还是低电平
  while(1)
  {
    if(i!=digitalRead(SquareWave))                //发现第一次跳变
    {
        i=digitalRead(SquareWave);
        CurrentTime=micros();                    //记录第一次跳变的时间
        goto S1;
    }
  }
  S1:FirstTime=CurrentTime;
  int m=1;                                        //存放跳变的次数，次数越多精度越高，测量时间也就会越长
  if(Shift==1)                                     //分档处理，低频的时候点取少，高频的时候点取多
  {
    while(1)
    {
        if(i!=digitalRead(SquareWave))
        {
            m++;
            i=digitalRead(SquareWave);
            if(m==200)
            {
                CurrentTime=micros();            //记录200次跳变的时间
                goto S2;
            }
        }
    }
  S2:SecondTime=CurrentTime;
  Frequency=100000000/(SecondTime-FirstTime);    //计算频率
  }
  if(Shift==2)
  {
    while(1)
    {
        if(i!=digitalRead(SquareWave))
        {
            m++;
            i=digitalRead(SquareWave);
            if(m==1000)
            {
                CurrentTime=micros();            //记录1000次跳变的时间
                goto S3;
            }
        }
    }
  S3:SecondTime=CurrentTime;
  Frequency=500000000/(SecondTime-FirstTime);    //计算频率
  }
  Serial.println();                             //将频率值发送至串口
  Serial.print("The frequency is ");
  Serial.print(Frequency);
  Serial.println("HZ");
  if(Frequency<=1000)                            //根据测得的频率智能换挡
    Shift=1;
  else
    Shift=2;

  volatile int j=digitalRead(SquareWave);        //先看现在是高电平还是低电平
  while(1)
  {
    if(j!=digitalRead(SquareWave))              //发现第一次跳变
    {
      j=digitalRead(SquareWave);
      CurrentTime=micros();                       //记录第一次跳变的时间
      goto S4;
    }
  }
  S4:FirstTime=CurrentTime*1.0;
  int n=0;
  while(1)
  {
      if(j!=digitalRead(SquareWave))
      {
        n++;
        j=digitalRead(SquareWave);
        if(n==99)
        {
            CurrentTime=micros();
            Time_99=CurrentTime-FirstTime;            //记录99次跳变的时间
        }
        if(n==199)
        {
            CurrentTime=micros();
            Time_199=CurrentTime-FirstTime;            //记录199次跳变的时间
        goto S5;
        }
      }
  }
  S5:
  if(j)                                                //根据第一次测的电平值来计算占空比
    DutyRatio=((Time_199-2*Time_99)*Frequency)/10000.0;
  else
    DutyRatio=100-((Time_199-2*Time_99)*Frequency)/10000.0;
  Serial.print("The duty ratio is ");                 //串口输出占空比
  Serial.print(DutyRatio);
  Serial.println("%");
}

void OverVoltageAlarm()                                //过压报警
{
    tone(Buzzer,1000);                                //蜂鸣器报警
    delay(1000);                                    //延时1s
    noTone(Buzzer);                                    //蜂鸣器停止报警
    for(int k=0;k<3;k++)                            //屏幕显示三次过压警告
    {
        Serial.println("OVER VOLTAGE!!!");
    }
}
