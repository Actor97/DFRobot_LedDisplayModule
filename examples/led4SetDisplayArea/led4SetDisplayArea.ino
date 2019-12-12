/*!
 * @file led4SetDisplayArea.ino
 * @brief 数码管的设置显示区域实验.
 * @n Experiment phenomenon: 数码管13区域显示显示"HL"，一秒后24区域显示显示"AO"，一秒后1234区域显示显示"HALO".
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
}

void loop() 
{
  /* 设置显示区域为1，3 
   * 可以显示1~4位，每个参数范围为1~4  
   * 改变显示区域后需要重新发送显示值
   */
  LED.setDisplayArea4(1,3);
  /* 显示 "HL" 
   * 目前仅支持显示数字0~9，大写字母A、B、C、D、E、F、H、L、O、P、U以及破折号-；
   * 也可以带小数点，如"0." "9." "A." "-."
   */
  LED.print4("H","L"); 
  delay(1000);
 
  LED.setDisplayArea4(2,4);
  LED.print4("A","O");
  delay(1000);
  
  LED.setDisplayArea4(1,2,3,4);
  LED.print4("H","A","L","O");
  //LED.print4("H.","A.","L.","O.");
  delay(1000);
}
