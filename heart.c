#include <stdio.h>
#include <math.h>

int main(void)
{
	int i;
	LED_Init();
    delay_init();	    	 //延时函数初始化
    UART1_Config(115200);	 	//串口初始化为9600
    ADC1_Init();
    
    while(1)
    {
        preReadData = readData;	        // 保存前一次值
//        readData = GetPulseSensorValue();		// 读取AD转换值
        readData = 4095 - ADC_ConvertedValue;		// 读取AD转换值

        if((readData - preReadData) < filter)     // 滤除突变噪声信号干扰
            data[idx++] = readData;	// 填充缓存数组

        if(idx >= DATA_SIZE)
        {
            idx = 0;	// 数组填满，从头再填

            // 通过缓存数组获取脉冲信号的波峰、波谷值，并计算中间值作为判定参考阈值
            max = Get_Array_Max(data, DATA_SIZE);
            min = Get_Array_Min(data, DATA_SIZE);
            mid = (max + min) / 2;
            filter = (max - min) / 2;
        }

        PRE_PULSE = PULSE;	// 保存当前脉冲状态
        PULSE = (readData > mid) ? TRUE : FALSE;  // 采样值大于中间值为有效脉冲

        if(PRE_PULSE == FALSE && PULSE == TRUE)   // 寻找到“信号上升到振幅中间位置”的特征点，检测到一次有效脉搏
        {
            pulseCount++;
            pulseCount %= 2;

            if(pulseCount == 1) // 两次脉搏的第一次
            {
                firstTimeCount = timeCount;   // 记录第一次脉搏时间
            }
            if(pulseCount == 0)  // 两次脉搏的第二次
            {
                secondTimeCount = timeCount;  // 记录第二次脉搏时间
                timeCount = 0;

                if((secondTimeCount > firstTimeCount))
                {
                    IBI = (secondTimeCount - firstTimeCount) * SAMPLE_PERIOD;	// 计算相邻两次脉搏的时间，得到 IBI
                    BPM = 60000 / IBI;  // 通过 IBI 得到心率值 BPM
                    if(BPM > 200)     //限制BPM最高显示值
                        BPM = 200;
                    if(BPM < 30)     //限制BPM最低显示值
                        BPM = 30;
                }
            }
//			printf("B%d\r\n", BPM);
			printf("SIG = %d IBI = %d, BMP = %d\r\n\r\n", readData, IBI, BPM);
        }
        SIG = readData;
//        printf("S%d\r\n", SIG);  // 上位机S数据发送
        timeCount++;  // 时间计数累加
        delay_ms(SAMPLE_PERIOD);  // 延时再进行下一周期采样
		if(i++ >= 50)
		{
			LED = !LED;
			i = 0;
		}
	}
}