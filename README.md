# DFRobot_LedDisplayModule
这是一个4位/8位的数码管显示模块，通过IIC与主机实现通信，来显示数字0~9，大写字母A、B、C、D、E、F、H、L、O、P、U以及破折号- 。<br>
4位数码管的IIC地址为0x48。<br>
8位数码管的IIC默认地址为0xE0，该地址可以通过显示模块背部A1、A0两个焊点的组合方式来更改，可更改为：0xE2、0xE4、0xE6 。<br>

## DFRobot_LedDisplayModule for Arduino
---------------------------------------------------------
Provide an Arduino library for the Led Display Module.
   
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary
这是一个Arduino IDE的库，能够帮助Arduino与4位/8位的数码管显示模块进行通信。<br>
该库使得通过IIC控制显示器变得容易。<br>

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
  int begin4();
  
  /*!
   *  @brief 8位数码管初始化
   *  @return Return 0 if initialization succeeds, otherwise return non-zero.
   */ 
  int begin8();

  /*!
   *  @brief 显示开启
   *  @param IIC显示开启指令
   */
  void displayOn();
  
  /*!
   *  @brief 显示关闭
   *  @param IIC显示关闭指令
   */  
  void displayOff();

  /*!
   *  @brief 8位数码管闪烁模式，频率为0.5HZ
   *  @param IIC闪烁指令
   */
  void flashTwos();
  
  /*!
   *  @brief 8位数码管闪烁模式，频率为1HZ
   *  @param IIC闪烁指令
   */
  void flashOnes();
  
  /*!
   *  @brief 8位数码管闪烁模式，频率为2HZ 
   *  @param IIC闪烁指令
   */
  void flashHalfs();
  
  /*!
   *  @brief 8位数码管关闭闪烁
   *  @param IIC关闭闪烁指令
   */
  void stopFlash();

  /*!
   *  @brief 4位数码管设置亮度
   *  @param 亮度值，可以为数字1~8
   */
  void setBrightness4(int brightnessValue); 
  
  /*!
   *  @brief 8位数码管设置亮度
   *  @param 亮度值，可以为数字1~16
   */
  void setBrightness8(int brightnessValue);

  /*!
   *  @brief 4位数码管设置显示区域
   *  @param 第1~4位的显示地址，可以为数字1~4
   */
  void setDisplayArea4(int areaData);
  void setDisplayArea4(int areaData1,int areaData2);
  void setDisplayArea4(int areaData1,int areaData2,int areaData3);
  void setDisplayArea4(int areaData1,int areaData2,int areaData3,int areaData4);

  /*!
   *  @brief 8位数码管设置显示区域
   *  @param 第1~8位的显示地址，可以为数字1~8
   */
  void setDisplayArea8(int areaData);
  void setDisplayArea8(int areaData1,int areaData2);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3,int areaData4);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3,int areaData4,int areaData5);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3,int areaData4,int areaData5,int areaData6);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3,int areaData4,int areaData5,int areaData6,int areaData7);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3,int areaData4,int areaData5,int areaData6,int areaData7,int areaData8);

  /*!
   *  @brief 4位数码管打印显示信息
   *  @param 可以为整数、小数
   */  
  void print4(double sensorData);
  
  /*!
   *  @brief 4位数码管打印显示信息
   *  @param 第1~4位的显示数据，可以为数字0~9，大写字母A、B、C、D、E、F、H、L、O、P、U以及破折号- 
   *  @n 也可以带小数点，如"0." "9." "A." "-."
   */
  void print4(const char buf1[]);
  void print4(const char buf1[],const char buf2[]);
  void print4(const char buf1[],const char buf2[],const char buf3[]);
  void print4(const char buf1[],const char buf2[],const char buf3[],const char buf4[]);

  /*!
   *  @brief 8位数码管打印显示信息
   *  @param 可以为整数、小数
   */
  void print8(double sensorData);
  
  /*!
   *  @brief 8位数码管打印显示信息
   *  @param 第1~4位的显示数据，可以为数字0~9，大写字母A、B、C、D、E、F、H、L、O、P、U以及破折号- 
   *  @n 也可以带小数点，如"0." "9." "A." "-."
   */
  void print8(const char buf1[]);
  void print8(const char buf1[],const char buf2[]);
  void print8(const char buf1[],const char buf2[],const char buf3[]);
  void print8(const char buf1[],const char buf2[],const char buf3[],const char buf4[]);
  void print8(const char buf1[],const char buf2[],const char buf3[],const char buf4[],const char buf5[]);
  void print8(const char buf1[],const char buf2[],const char buf3[],const char buf4[],const char buf5[],const char buf6[]);
  void print8(const char buf1[],const char buf2[],const char buf3[],const char buf4[],const char buf5[],const char buf6[],const char buf7[]);
  void print8(const char buf1[],const char buf2[],const char buf3[],const char buf4[],const char buf5[],const char buf6[],const char buf7[],const char buf8[]);
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32         |      √       |              |             | 
micro:bit        |      √       |              |             | 

## History

- Data 2019-12-10
- Version V1.0

## Credits

Written by(liang.li@dfrobot.com), 2019. (Welcome to our [website](https://www.dfrobot.com/))





