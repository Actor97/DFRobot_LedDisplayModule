/*!
 * @file led4Power.ino
 * @brief 数码管的开关屏幕实验.
 * @n Experiment phenomenon: 数码管显示"HALO"，在显示一秒后关闭屏幕，一秒后打开屏幕.
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
 *Parameter I2C地址默认为0x48
*/
DFRobot_LedDisplayModule LED(Wire, 0x48);

//Prepare: 将数码管连接到主板的IIC接口 
void setup()
{
  Serial.begin(115200);
  /*wait for the chip to be initialized completely, and then exit*/
  while(LED.begin4() != 0)
  {
    Serial.println("Initialization of the chip failed, please confirm that the chip connection is correct!");
    delay(1000);
  }
  /* 设置显示区域 */
  LED.setDisplayArea4(1,2,3,4);
  /* 显示"HALO" 
   * 目前仅支持显示数字0~9，大写字母A、B、C、D、E、F、H、L、O、P、U以及破折号-；
   * 也可以带小数点，如"0." "9." "A." "-."
   */
  LED.print4("H","A","L","O");
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
