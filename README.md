# HeartRate
> 调研报告：基于光电传感器技术的心率/脉率检测方法研究 <br />

常见的可穿戴光电容积法传感器有两种模式——透射模式和反射模式。如图所示。因为本次实无硬件电路实现来进行信号的测量，所以在发光二极管以及后续的信号调理电路中的放大倍数均要进行考虑计算。对于透射已经有非常完善的定律（朗伯-比尔定律），其在超声、X射线等临床领域已经是非常完善的理论基础之一了。所以采用了透视模式来计算。<br>
![Transmission & Reflection mode](img/Transmission&reflection_mode.png) <br />
在LED的光源的波长选择方面，由于目前只有光电心率传感器MAX30102的发光的二极管，其集成了两个发光二极管，一个是红光LED(660nm)，另一个是红外光LED(880nm)，在仅仅测量心率的时候仅红光LED工作，这样我就可以对660nm的红光进行实验。所以我将要选择的发光二极管波长为660nm。<br />
|元件清单|具体型号|
|:-----:|:-----:|
|激光二极管：|GH06510F4A|
|光电二极管：|SFH203P|
|传感器接口电路：|ADA4622-4|
|滤波放大电路：|ADA4622-4|
|微处理器：|Arduino UNO|
|显示：|LCD1602|
|IIC：|PCF8574|
# 系统结构设计
通过光电二极管采集信号，再放大、滤波消除噪声。信号进入处理器进行数据的处理并计算，最后在显示屏上显示。<br>
将电路主要分为三个部分：1)信号调理电路；2)处理器与显示电路；3)电源电路。<br>
## 系统结构框图
![系统结构框图](img/系统结构框图.svg)
## 模块设计
### 信号调理电路
> 负责信号的采集、放大、滤波<br>
#### 信号采集与电流电压转换
1. 选择增益电阻。<br>
$$R_1 = \frac{V_{oMAX}-V_{oMIN}}{I_{iMAX}} = \frac{0.5V-0V}{0.5\mu A} = 1M\Omega $$
2. 选择满足电路带宽要求的反馈电容。<br>
$$C_1 ≤ \frac{1}{2\pi R_1 f_p} = \frac{1}{2\pi\times 1M\Omega \times 10KHz} ≤ 15.92pF\approx 16pF$$
3. 计算使电路保持稳定所必需的运算放大器增益带宽(GBW)<br>

#### 带通滤波器
0.1Hz~10Hz
#### 二级放大
### 处理器与显示电路
> 负责信号的处理、计算、显示<br>
### 电源电路
> 负责整体电路的稳定供电<br>
### 其它电路
#### 发光电路
由于需要稳定的光源，所以发光二极管需要稳压。<br>
## 软件设计

# 参考
1. [Pulse sersor][sersor]<br>
2. [TINKERCAD][tinkercad]<br>
3. [proteus仿真arduino中使用PCF8574以I2C方式操作LCD1602][xiHe]<br>
4. [手指检测心跳设计——传感器制作篇][shouZhi]<br>
5. [基于uFUN开发板的心率计（一）DMA方式获取传感器数据][wangchao1]<br>

# F.1 测量仪器设计拓展
## F.1.1 一般结构
* **传感器：** 实现生理信号从非电量到电量的变换；<br>
* **传感器接口电路：** 将传感器输出信号转换成低输出电阻的电压信号；<br>
* **放大滤波器：** 获得纯净可识别信号；<br>
* **ADC：** 模拟/数字变换，得到数字信号；<br>
* **微处理器/微控制器：** 实现信号输出显示、存储、控制，以及改变电路参数。<br>

## F.1.2 设计原则
确定目标，总体框架，功能模块，具体技术，具体型号，参数选择。<br>
先从整体考虑，逐步精细化，直至达成目标。(自上而下)<br>
1. 被测量的量是什么？信号的大小与频率是多少？（心率，毫伏级水平，60~100次/min）；<br>
2. 输出是什么？如何与使用者传达信息？（通过显示屏输出）；<br>
3. 仪器的测量的精度、性能；<br>
4. 仪器的使用条件；<br>
5. 仪器的功能（测量心率）；<br>
6. ~~成本、工艺条件；~~<br>




[photodiode]:"https://zh.wikipedia.org/wiki/%E5%85%89%E7%94%B5%E4%BA%8C%E6%9E%81%E7%AE%A1 "光电二极管"
[PPG]:https://www.cdstm.cn/gallery/media/mkjx/wxd/201605/t20160525_321684.html "光电容积法"
[sersor]:https://pulsesensor.com/ "光电传感器模块"
[tinkercad]:https://www.tinkercad.com/ "Arduino仿真"
[xiHe]:https://blog.csdn.net/haigear/article/details/88935697 "proteus仿真arduino中使用PCF8574以I2C方式操作LCD1602"
[shouZhi]:https://blog.csdn.net/qq_34445388/article/details/79781181/ "手指检测心跳设计——传感器制作篇"
[wangchao1]:http://www.wangchaochao.top/2019/03/23/uFun-3/ "基于uFUN开发板的心率计（一）DMA方式获取传感器数据"
[wangchao2]:http://www.wangchaochao.top/2019/03/31/uFun-5/ "基于uFUN开发板的心率计（二）动态阈值算法获取心率值"
[wangchao3]:http://www.wangchaochao.top/2019/04/05/uFun-6/ "基于uFUN开发板的心率计（三）Qt上位机的实现"
[attachinterrupt]:https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/ "attachinterrupt"