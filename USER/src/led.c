

#include "gec_gpio.h"
#include "led.h"


/*
	led_init:初始化LED灯相应的GPIO引脚
*/
void led_init(void)
{
	Gec_GPIO_Init(GPIOF, GPIO_Pin_9 |GPIO_Pin_10, GPIO_MODE_OUT_PP);
	
	Gec_GPIO_Init(GPIOE, GPIO_Pin_13 |GPIO_Pin_14, GPIO_MODE_OUT_PP);
	Gec_GPIO_Set_Value(GPIOF,GPIO_Pin_9,LED_OFF);
	Gec_GPIO_Set_Value(GPIOF,GPIO_Pin_10,LED_OFF);
	Gec_GPIO_Set_Value(GPIOE,GPIO_Pin_13,LED_OFF);
	Gec_GPIO_Set_Value(GPIOE,GPIO_Pin_14,LED_OFF);
}



/*
	led_ctrl:灯控函数
	@led_id: 灯的编号，如：
		 LED_D1
		 LED_D2
		 ...
	@OnOff: 灯的控制，如	：
		 LED_ON 开灯
		 LED_OFF 关灯
	返回值：
		
*/
void led_ctrl(int led_id, int OnOff)
{
	if (led_id == LED_D1 )
	{
		if(OnOff == LED_ON )
		{
			Gec_GPIO_Set_Value(GPIOF,GPIO_Pin_9,LED_ON);
		}
		else if(OnOff == LED_OFF)
		{
			Gec_GPIO_Set_Value(GPIOF,GPIO_Pin_9,LED_OFF);
		}
	}
	if (led_id == LED_D2 )
	{
		if(OnOff == LED_ON )
		{
			Gec_GPIO_Set_Value(GPIOF,GPIO_Pin_10,LED_ON);
		}
		else if(OnOff == LED_OFF)
		{
			Gec_GPIO_Set_Value(GPIOF,GPIO_Pin_10,LED_OFF);
		}
	}
	if (led_id == LED_D3 )
	{
		if(OnOff == LED_ON )
		{
			Gec_GPIO_Set_Value(GPIOE,GPIO_Pin_13,LED_ON);
		}
		else if(OnOff == LED_OFF)
		{
			Gec_GPIO_Set_Value(GPIOE,GPIO_Pin_13,LED_OFF);
		}
	}
	if (led_id == LED_D4 )
	{
		if(OnOff == LED_ON )
		{
			Gec_GPIO_Set_Value(GPIOE,GPIO_Pin_14,LED_ON);
		}
		else if(OnOff == LED_OFF)
		{
			Gec_GPIO_Set_Value(GPIOE,GPIO_Pin_14,LED_OFF);
		}
	}

}
