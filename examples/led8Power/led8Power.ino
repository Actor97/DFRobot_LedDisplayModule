/*!
 * @file led8Power.ino
 * @brief 数码管的开关屏幕实验.
 * @n Experiment phenomenon: 数码管显示"HALO.LED8"，在显示一秒后关闭屏幕，一秒后打开屏幕.
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Actor](liang.li@dfrobot.com)
 * @version  V1.0
 * @eGPAte  2019-12-10
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/DFRobot_LedDisplayModule
 */

# include "DFRobot_LedDisplayModule.h"
/*DFRobot_LedDisplayModule Constructor
 *Parameter &wire  Wire
 *8位数码管的默认地址为0xE0
 *8位数码管可以通过A1、A0的组合方式来改变地址
 * 1  1  1  0  | 0  A1 A0 0
   1  1  1  0  | 0  0  0  0    0xE0
   1  1  1  0  | 0  0  1  0    0xE2
   1  1  1  0  | 0  1  0  0    0xE4
   0  0  1  0  | 0  1  1  0    0xE6
*/ 
DFRobot_LedDisplayModule LED(Wire, 0xE0);

//Prepare: 将数码管连接到主板的IIC接口 
void setup()
{
  Serial.begin(115200);
  /*wait for the chip to be initialized completely, and then exit*/
  while(LED.begin8() != 0)
  {
    Serial.println("Initialization of the chip failed, please confirm that the chip connection is correct!");
    delay(1000);
  }
  /* 设置显示区域 */
  LED.setDisplayArea8(1,2,3,4,5,6,7,8);
  
  /* 显示"HALO.LED8" 
   * 目前仅支持显示数字0~9，大写字母A、B、C、D、E、F、H、L、O、P、U以及破折号-；
   * 也可以带小数点，如"0." "9." "A." "-."
   */
  LED.print8("H","A","L","O.","L","E","D","8");
  delay(1000);
}

void loop()
{ 
  /* 关闭显示器 */
  LED.displayOff();
  delay(1000);
  
  /* 打开显示器 */
  LED.displayOn();
  delay(1000);
}
