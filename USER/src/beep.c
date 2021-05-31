#include "beep.h" 
#include "bitband.h"

/**
  * @brief  beep初始化函数
	* @note		beep对应的引脚为 PF8。输出高电平响,输出低电平不响
  * @param  无
  * @retval 无
  */
void beep_init(void)
{
	GPIO_InitTypeDef f;
	/*使能GPIOF的时钟*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

	/*配置PF8为输出模式,输出推挽类型,低速模式*/
	f.GPIO_Pin = GPIO_Pin_8 ;
	f.GPIO_Mode = GPIO_Mode_OUT;
	f.GPIO_OType = GPIO_OType_PP;
	f.GPIO_Speed = GPIO_Low_Speed;
	GPIO_Init(GPIOF, &f);
	
	/*设置beep缺省为不响*/
	PFout(8) = 0;
}

/**
  * @brief  beep状态控制函数
  * @note		beep对应的引脚为 PF8。输出高电平响,输出低电平不响
  * @param  beep_state 指定beep灯的状态。可选择为 BEEP_ON,BEEP_OFF
  * @retval 无
  */
void beep_ctrl(int beep_state)
{
	PFout(8) = beep_state;
}
