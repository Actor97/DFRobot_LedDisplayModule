/*!
 * @file led4Print.ino
 * @brief 数码管的显示实验.
 * @n Experiment phenomenon: 数码管显示"HALO"；一秒后显示"H.A.L.O."；一秒后显示变量val的值.
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

void setup() 
{
  Serial.begin(115200);
  /*wait for the chip to be initialized completely, and then exit*/
  while(LED.begin4() != 0)
  {
    Serial.println("Initialization of the chip failed, please confirm that the chip connection is correct!");
    delay(1000);
  }
  
  /* 设置显示区域为1，2，3，4 
   * 可以显示1~4位，每个参数范围为1~4  
   * 改变显示区域后需要重新发送显示值
   */
  LED.setDisplayArea4(1,2,3,4);
}

void loop() 
{
  /* 显示 "HALO" 
   * 目前仅支持显示数字0~9，大写字母A、B、C、D、E、F、H、L、O、P、U以及破折号-；
   * 也可以带小数点，如"0." "9." "A." "-."
   */
  LED.print4("H","A","L","O");
  delay(1000);
  
  LED.print4("H.","A.","L.","O."); 
  delay(1000);
  
  /* 显示一个变量的值
   * 这个变量可以为整数、小数 
   * 这里可以兼容你的传感器返回值，如温度、湿度等
   */
  double val = 13.25;
  LED.print4(val);
  delay(1000);
}
