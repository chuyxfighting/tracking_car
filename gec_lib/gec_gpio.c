
#include "gec_gpio.h"


static uint32_t get_gpio_exti_pin(uint32_t GPIO_Pin)
{
	uint32_t exti_pin = 111;

	switch(GPIO_Pin)
	{
		case GPIO_Pin_0:
			exti_pin = EXTI_PinSource0;
			break;
		case GPIO_Pin_1:
			exti_pin = EXTI_PinSource1;
			break;
		case GPIO_Pin_2:
			exti_pin = EXTI_PinSource2;
			break;
		case GPIO_Pin_3:
			exti_pin = EXTI_PinSource3;
			break;
		case GPIO_Pin_4:
			exti_pin = EXTI_PinSource4;
			break;
		case GPIO_Pin_5:
			exti_pin = EXTI_PinSource5;
			break;
		case GPIO_Pin_6:
			exti_pin = EXTI_PinSource6;
			break;
		case GPIO_Pin_7:
			exti_pin = EXTI_PinSource7;
			break;
		case GPIO_Pin_8:
			exti_pin = EXTI_PinSource8;
			break;
		case GPIO_Pin_9:
			exti_pin = EXTI_PinSource9;
			break;
		case GPIO_Pin_10:
			exti_pin = EXTI_PinSource10;
			break;
		case GPIO_Pin_11:
			exti_pin = EXTI_PinSource11;
			break;
		case GPIO_Pin_12:
			exti_pin = EXTI_PinSource12;
			break;
		case GPIO_Pin_13:
			exti_pin = EXTI_PinSource13;
			break;
		case GPIO_Pin_14:
			exti_pin = EXTI_PinSource14;
			break;
		case GPIO_Pin_15:
			exti_pin = EXTI_PinSource15;
			break;
		default:
			break;
	}

	
	return exti_pin;
}

static uint32_t get_gpio_exti_port(GPIO_TypeDef* GPIOx)
{
	uint32_t exti_port = 0;
	if (GPIOx == GPIOA)
	{
		exti_port =  EXTI_PortSourceGPIOA;
	}
	else if (GPIOx == GPIOB)
	{
		exti_port =  EXTI_PortSourceGPIOB;
	}
	else if (GPIOx == GPIOC)
	{
		exti_port =  EXTI_PortSourceGPIOC;
	}
	else if (GPIOx == GPIOD)
	{
		exti_port =  EXTI_PortSourceGPIOD;
	}
	else if (GPIOx == GPIOE)
	{
		exti_port =  EXTI_PortSourceGPIOE;
	}
	else if (GPIOx == GPIOF)
	{
		exti_port =  EXTI_PortSourceGPIOF;
	}
	else if (GPIOx == GPIOG)
	{
		exti_port =  EXTI_PortSourceGPIOG;
	}
	else if (GPIOx == GPIOH)
	{
		exti_port =  EXTI_PortSourceGPIOH;
	}
	else if (GPIOx == GPIOI)
	{
		exti_port =  EXTI_PortSourceGPIOI;
	}
	else if (GPIOx == GPIOJ)
	{
		exti_port =  EXTI_PortSourceGPIOJ;
	}
	else if (GPIOx == GPIOK)
	{
		exti_port =  EXTI_PortSourceGPIOK;
	}

	return exti_port;
}



static uint32_t get_gpio_clock_group(GPIO_TypeDef* GPIOx)
{
	uint32_t clock_group = 0;
	if (GPIOx == GPIOA)
	{
		clock_group =  RCC_AHB1Periph_GPIOA;
	}
	else if (GPIOx == GPIOB)
	{
		clock_group =  RCC_AHB1Periph_GPIOB;
	}
	else if (GPIOx == GPIOC)
	{
		clock_group =  RCC_AHB1Periph_GPIOC;
	}
	else if (GPIOx == GPIOD)
	{
		clock_group =  RCC_AHB1Periph_GPIOD;
	}
	else if (GPIOx == GPIOE)
	{
		clock_group =  RCC_AHB1Periph_GPIOE;
	}
	else if (GPIOx == GPIOF)
	{
		clock_group =  RCC_AHB1Periph_GPIOF;
	}
	else if (GPIOx == GPIOG)
	{
		clock_group =  RCC_AHB1Periph_GPIOG;
	}
	else if (GPIOx == GPIOH)
	{
		clock_group =  RCC_AHB1Periph_GPIOH;
	}
	else if (GPIOx == GPIOI)
	{
		clock_group =  RCC_AHB1Periph_GPIOI;
	}
	else if (GPIOx == GPIOJ)
	{
		clock_group =  RCC_AHB1Periph_GPIOJ;
	}
	else if (GPIOx == GPIOK)
	{
		clock_group =  RCC_AHB1Periph_GPIOK;
	}

	return clock_group;
}


static EXTITrigger_TypeDef get_exti_trigger(enum GPIO_MODE gpio_mode)
{
	EXTITrigger_TypeDef trigger_mode =(EXTITrigger_TypeDef) 0; 

	switch(gpio_mode)
	{
		case GPIO_MODE_EXTI_Both:
			trigger_mode = EXTI_Trigger_Rising_Falling;
			break;
		case GPIO_MODE_EXTI_Falling:
			trigger_mode = EXTI_Trigger_Falling;
			break;
		case GPIO_MODE_EXTI_Rising:
			trigger_mode = EXTI_Trigger_Rising;
		default:
			break;
	}

	return trigger_mode;
}

static GPIOMode_TypeDef get_stm32gpiomode(enum GPIO_MODE gpio_mode)
{
	GPIOMode_TypeDef  mode = GPIO_Mode_AF ;

	switch (gpio_mode)
	{
		case GPIO_MODE_IN_FLOATING:   // 输入悬空
		case GPIO_MODE_IN_PULLUP:  //带上拉的输入
		case GPIO_MODE_IN_PULLDOWN: //带下拉的输入

		case GPIO_MODE_EXTI_Both:
		case GPIO_MODE_EXTI_Rising:
		case GPIO_MODE_EXTI_Falling:
			mode = GPIO_Mode_IN;
			break;
		case GPIO_MODE_IN_ANALOG:  //模拟输入
			mode = GPIO_Mode_AN;
			break;
		case GPIO_MODE_OUT_OD:
		case GPIO_MODE_OUT_PP:
			mode = GPIO_Mode_OUT;
			break;
		default:
			break;
	}

	return mode;

}

static GPIOPuPd_TypeDef get_stm32gpioPuPd(enum GPIO_MODE gpio_mode)
{
	GPIOPuPd_TypeDef  mode = GPIO_PuPd_NOPULL ;

	switch (gpio_mode)
	{
		//case GPIO_MODE_IN_FLOATING:   // 输入悬空
		case GPIO_MODE_IN_PULLUP:  //带上拉的输入
			mode = GPIO_PuPd_UP;
			break;
		case GPIO_MODE_IN_PULLDOWN: //带下拉的输入
			mode = GPIO_PuPd_DOWN;
			break;
	
		default:
			break;
	}

	return mode;

}

/*
	Gec_GPIO_Init: 初始化一个GPIO引脚
	@GPIOx: 指定GPIO分组，如：GPIOA, GPIOB,...
	@GPIO_Pin: 指定GPIO引脚编号，如：GPIO_Pin_0, GPIO_Pin_1,...
	@gpio_mode: 指定GPIO的模式

	返回值:
		成功返回0
		失败返回-1

*/
void Gec_GPIO_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, enum GPIO_MODE gpio_mode)
{
//	int ret = 0;
	uint32_t clock_group = get_gpio_clock_group(GPIOx);

	//使能GPIO分组时钟
	RCC_AHB1PeriphClockCmd(clock_group, ENABLE);



	//GPIO_Init
	GPIO_InitTypeDef p;
	p.GPIO_Mode = get_stm32gpiomode(gpio_mode) ;
	p.GPIO_OType = (gpio_mode == GPIO_MODE_OUT_OD) ? GPIO_OType_OD : GPIO_OType_PP;
	p.GPIO_Pin = GPIO_Pin;
	p.GPIO_PuPd = get_stm32gpioPuPd(gpio_mode);
	p.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOx, &p);


	//配置外部中断，if EXTI
	if (IS_GEC_EXTI_MODE(gpio_mode))
	{
		// 1.2 SYSCFG控制器
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
		SYSCFG_EXTILineConfig( get_gpio_exti_port(GPIOx), get_gpio_exti_pin(GPIO_Pin)); // PA0 -> EXTI0

		// 1.3 EXTI外部中断控制器的配置
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // 0 ~3

		
		EXTI_InitTypeDef e;
		e.EXTI_Line = GPIO_Pin; //GPIO_Pin_0 <->  EXTI_Line0
		e.EXTI_LineCmd = ENABLE;
		e.EXTI_Mode = EXTI_Mode_Interrupt;
		e.EXTI_Trigger = get_exti_trigger(gpio_mode);
		EXTI_Init(&e);
	}

}


/*
	Gec_GPIO_Get_Value: 获取某个GPIO的值
	@GPIOx: 指定GPIO分组，如：GPIOA, GPIOB,...
	@GPIO_Pin: 指定GPIO引脚编号，如：GPIO_Pin_0, GPIO_Pin_1,...
	返回值:
		0  -> 低电平
		1  -> 高电平
*/
int Gec_GPIO_Get_Value(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{

	return GPIO_ReadInputDataBit(GPIOx,  GPIO_Pin);

}


/*
	Gec_GPIO_Set_Value: 设置某个GPIO的值
	@GPIOx: 指定GPIO分组，如：GPIOA, GPIOB,...
	@GPIO_Pin: 指定GPIO引脚编号，如：GPIO_Pin_0, GPIO_Pin_1,...
	@value:要设置的值
		0  -> 低电平
		1  -> 高电平
	返回值：
		无。
*/

void Gec_GPIO_Set_Value(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t value)
{
	GPIO_WriteBit(GPIOx, GPIO_Pin, (value == 0)? Bit_RESET : Bit_SET);

}


/*
	Gec_GPIO_Toggle_Value:翻转某个GPIO引脚的值
					“翻转”： 0 -> 1
							1 -> 0
	@GPIOx: 指定GPIO分组，如：GPIOA, GPIOB,...
	@GPIO_Pin: 指定GPIO引脚编号，如：GPIO_Pin_0, GPIO_Pin_1,...
	返回值:
		无。

*/
void Gec_GPIO_Toggle_Value(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	GPIO_ToggleBits(GPIOx, GPIO_Pin);
}

/*
	Gec_GPIO_Get_ITFlag:获取GPIO外部中断的标记
	@EXTI_Line:
		相应GPIO外部中断的中断编号，如:
			EXTI_Line0, EXTI_Line1, ...
	返回值:
		1 -> 相应的GPIO引脚产生了中断
		0 -> 相应的GPIO引脚没产生中断
*/
int Gec_GPIO_Get_ITFlag(uint32_t EXTI_Line)
{
	return EXTI_GetITStatus(EXTI_Line);
}

/*
	Gec_GPIO_Clear_ITFlag: 清掉GPIO外部中断的标记
	@EXTI_Line:
		相应GPIO外部中断的中断编号，如:
			EXTI_Line0, EXTI_Line1, ...
	返回值:
		无
*/
void Gec_GPIO_Clear_ITFlag(uint32_t EXTI_Line)
{
	EXTI_ClearITPendingBit(EXTI_Line);
}

