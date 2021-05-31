#include "led.h" 
#include "bitband.h"

/**
  * @brief  LED初始化函数
	* @note		LED对应的引脚分别为 PF9,PF10,PE13,PE14。输出低电平亮,输出高电平不亮
  * @param  无
  * @retval 无
  */
void led_init(void)
{
	GPIO_InitTypeDef f, e;
	/*使能GPIOE,GPIOF的时钟*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	/*配置PF9,PF10,PE13,PE14为输出模,输出推挽类型，低速模式*/
	e.GPIO_Pin = GPIO_Pin_13 |GPIO_Pin_14;
	e.GPIO_Mode = GPIO_Mode_OUT;
	e.GPIO_OType = GPIO_OType_PP;
	e.GPIO_Speed = GPIO_Low_Speed;
	f.GPIO_Pin = GPIO_Pin_9 |GPIO_Pin_10;
	f.GPIO_Mode = GPIO_Mode_OUT;
	f.GPIO_OType = GPIO_OType_PP;
	f.GPIO_Speed = GPIO_Low_Speed;
	GPIO_Init(GPIOE, &e);
	GPIO_Init(GPIOF, &f);
	
	/*设置LED0,LED1,LED2,LED3缺省为熄灭*/
	GPIO_SetBits(GPIOE, GPIO_Pin_13 | GPIO_Pin_14);
	GPIO_SetBits(GPIOF, GPIO_Pin_9 | GPIO_Pin_10);	
}

/**
  * @brief  LED状态控制函数
  * @note		LED对应的引脚分别为 PF9,PF10,PE13,PE14;输出低电平亮,输出高电平不亮
	* @param  led_num 指定要控制哪一盏LED的状态。
			可选择为 LED_D1,LED_D2,LED_D3,LED_D4
  * @param  led_state 指定LED灯的状态。可选择为 LED_ON,LED_OFF
  * @retval 无
  */
void led_ctrl(int led_num, int led_state)
{
	switch(led_num)
	{
		case LED_D1:
			PFout(9) = led_state;
			break;
		case LED_D2:
			PFout(10) = led_state;
			break;
		case LED_D3:
			PEout(13) = led_state;
			break;
		case LED_D4:
			PEout(14) = led_state;
			break;	
	}
}




