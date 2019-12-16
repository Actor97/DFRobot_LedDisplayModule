/*!
 * @file DFRobot_LedDisplayModule.h
 * @brief Define the basic structure of class DFRobot_LedDisplayModule
 * @n 这是一个使用IIC控制的4位/8位数码管显示设备，其中8位数码管可以通过硬件更改IIC地址
 * @n 该数码管的主要功能如下:
 * @n 显示4位/8位数字、小数点；
 * @n 目前仅支持显示数字0~9，大写字母A、B、C、D、E、F、H、L、O、P、U以及破折号-；
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Actor](liang.li@dfrobot.com)
 * @version  V1.0
 * @date  2019-12-10
 * @https://github.com/DFRobot/DFRobot_LedDisplayModule
 */
#ifndef __DFRobot_LedDisplayModule_H__
#define __DFRobot_LedDisplayModule_H__

#include "Arduino.h"
#include <Wire.h>

//Define DBG, change 0 to 1 open the DBG, 1 to 0 to close.  
#if 0
#define DBG(...) {Serial.print("["); Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

#if 0
#define DBGI(...) {Serial.print("["); Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBGI(...)
#endif

#define CMD_HT16K33_OSCOFF      0x20  /**< 关闭时钟 */
#define CMD_HT16K33_OSCON       0x21  /**< 打开时钟 */
#define CMD_HT16K33_DISPLAYOFF  0x80  /**< 关闭显示 */
#define CMD_HT16K33_DISPLAYON   0x81  /**< 打开显示 */
#define CMD_HT16K33_FLASHTWOS   0x87  /**< 设置为闪烁模式，频率为0.5Hz */
#define CMD_HT16K33_FLASHONES   0x85  /**< 设置为闪烁模式，频率为1Hz */
#define CMD_HT16K33_FLASHHALFS  0x83  /**< 设置为闪烁模式，频率为2Hz */
#define CMD_HT16K33_STOPFLASH   0x81  /**< 关闭闪烁 */

class DFRobot_LedDisplayModule
{
public:  
  #define ERR_OK             0      //ok
  #define ERR_ADDR          -1      //error in I2C address 
    
public:
 /**
   * @brief Constructor
   * @param pWire I2C bus pointer object. When calling the function, you may transfer a parameter into it. Defaule as Wire
   * @param addr 8 bits I2C address, 其中4位数码管的地址为0x48;8位数码管可以通过A1、A0的组合方式来改变地址
   * @n 8位数码管的默认地址为0xE0
   * 1  1  1  0  | 0  A1 A0 0
     1  1  1  0  | 0  0  0  0    0xE0
     1  1  1  0  | 0  0  1  0    0xE2
     1  1  1  0  | 0  1  0  0    0xE4
     0  0  1  0  | 0  1  1  0    0xE6
   */ 
  DFRobot_LedDisplayModule(TwoWire &wire, uint8_t ledAddress);

  /*!
   *  @brief 4位数码管初始化
   *  @return Return 0 if initialization succeeds, otherwise return non-zero.
   */
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
   *  @n The default value is 82, because TAB2[82-48] happens to be the value for turning off
   */
  void setDisplayArea4(int areaData1 = 82,int areaData2 = 82,int areaData3 = 82,int areaData4 = 82);

  /*!
   *  @brief 8位数码管设置显示区域
   *  @param 第1~8位的显示地址，可以为数字1~8
   *  @n The default value is 82, because TAB2[82-48] happens to be the value for turning off
   */
  void setDisplayArea8(int areaData1 = 82,int areaData2 = 82,int areaData3 = 82,int areaData4 = 82,int areaData5 = 82,int areaData6 = 82,int areaData7 = 82,int areaData8 = 82);

  /*!
   *  @brief 4位数码管打印显示信息
   *  @param 可以为整数、小数
   */  
  void print4(double sensorData);
  
  /*!
   *  @brief 4位数码管打印显示信息
   *  @param 第1~4位的显示数据，可以为数字0~9，大写字母A、B、C、D、E、F、H、L、O、P、U以及破折号- 
   *  @n 也可以带小数点，如"0." "9." "A." "-."
   *  @n The default value is 82, because TAB2[82-48] happens to be the value for turning off
   */
  void print4(const char buf1[] = "82",const char buf2[] = "82",const char buf3[] = "82",const char buf4[] = "82");

  /*!
   *  @brief 8位数码管打印显示信息
   *  @param 可以为整数、小数
   */
  void print8(double sensorData);
  
  /*!
   *  @brief 8位数码管打印显示信息
   *  @param 第1~8位的显示数据，可以为数字0~9，大写字母A、B、C、D、E、F、H、L、O、P、U以及破折号- 
   *  @n 也可以带小数点，如"0." "9." "A." "-."
   *  @n The default value is 82, because TAB2[82-48] happens to be the value for turning off
   */
  void print8(const char buf1[] = "82",const char buf2[] = "82",const char buf3[] = "82",const char buf4[] = "82",const char buf5[] = "82",const char buf6[] = "82",const char buf7[] = "82",const char buf8[] = "82");

private:
  TwoWire *_pWire;
  uint8_t _ledAddress;  /**< iic地址 */
  int displayAreaFlag;  /**< 显示区域标志 */
  int data1,data2,data3,data4,data5,data6,data7,data8;  /**< 显示数据缓存 */
  unsigned char ledData1,ledData11,ledData2,ledData22,ledData3,ledData33,ledData4,ledData44,ledData5,ledData55,ledData6,ledData66,ledData7,ledData77,ledData8,ledData88;  /**< 输入数据缓存 */
  
  int d11;
  int d21,d22;
  int d31,d32,d33;
  int d41,d42,d43,d44;  
  int d51,d52,d53,d54,d55;
  int d61,d62,d63,d64,d65,d66;
  int d71,d72,d73,d74,d75,d76,d77;
  int d81,d82,d83,d84,d85,d86,d87,d88;   /**< 显示区域数据缓存 */

  int d1,d2,d3,d4,d5,d6,d7;
  int a1,a2,a3,a4,a5,a6,a7;  /**< 显示地址数据缓存 */

  const unsigned char TAB2[38]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  /**< 0~9 */
                                0x77,0x7C,0x39,0x5E,0x79,0x71,  /**< A~F */
                                0x00,
                                0x76,                /**< H */
                                0x00,0x00,0x00,
                                0x38,                /**< L */
                                0x00,0x00,0x5C,      /**< O */
                                0x73,                /**< P */
                                0x00,0x00,0x00,0x40, /**< - */
                                0x3E};               /**< U */                                                                   /**< 显示数据 */
                 
  const unsigned char TAB_Point2[38]={0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
                                      0xF7,0xFC,0xB9,0xDE,0xF9,0xF1, 
                                      0x00,
                                      0xF6,
                                      0x00,0x00,0x00,
                                      0xB8,
                                      0x00,0x00,0xDC,
                                      0xF3,
                                      0x00,0x00,0x00,0xC0,
                                      0xBE};                                                                                     /**< 显示数据，点亮小数点 */
  
  /*!
   *  @brief 发送IIC控制指令
   *  @param IIC指令
   */
  void i2cWriteCmd(uint8_t cmd);
  
  /*!
   *  @brief 8位数码管发送IIC数据
   *  @param 寄存器地址
   *  @param IIC数据
   */
  void i2cWriteData(uint8_t reg,uint8_t data);
  
  /*!
   *  @brief 4位数码管发送IIC数据
   *  @param 寄存器地址
   *  @param IIC数据
   */
  void i2cWriteData4(uint8_t reg,uint8_t data);

 /*!
  *  @brief 重置打印缓存区 
  */
  void printCacheReset();
  
  /*!
   *  @brief 从用户输入处获取第1~8位的显示数据
   */
  void  getDisplayData();

  /*!
   *  @brief 4位数码管获取显示地址
   */
  void getDisplayAddress4_1();
  void getDisplayAddress4_2();
  void getDisplayAddress4_3(); 
  
  /*!
   *  @brief 8位数码管获取显示地址
   */
  void getDisplayAddress8_1();
  void getDisplayAddress8_2();
  void getDisplayAddress8_3();
  void getDisplayAddress8_4();
  void getDisplayAddress8_5();
  void getDisplayAddress8_6();
  void getDisplayAddress8_7();

  /*!
   *  @brief 4位数码管获取显示地址(传感器数据模式)
   */
  void sensorGetDisplayAddress4();
   
  /*!
   *  @brief 8位数码管获取显示地址(传感器数据模式)
   */
  void sensorGetDisplayAddress8();
  
  /**
   * @brief I2C address detection
   * @param addr I2C address
   * @return Return o if IIC address is set correctly, otherwise return non-zero. 
   */
  int i2cdetect(uint8_t _ledAddress);
};

#endif