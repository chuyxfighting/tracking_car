#include "gec_gpio.h"
#include "motor.h"
#include "track.h"
#include "delay.h"
#include "bt.h"
void track_init(void)
{
		Gec_GPIO_Init(GPIOC, GPIO_Pin_11 , GPIO_MODE_IN_FLOATING);
		Gec_GPIO_Init(GPIOB, GPIO_Pin_6 , GPIO_MODE_IN_FLOATING);
		Gec_GPIO_Init(GPIOE, GPIO_Pin_5 , GPIO_MODE_IN_FLOATING);
	
}

int get_left_state(void)
{
	uint8_t i;
	i = Gec_GPIO_Get_Value(GPIOC,GPIO_Pin_11);
	return i;
}
int get_right_state(void)
{
	uint8_t i;
	i = Gec_GPIO_Get_Value(GPIOB,GPIO_Pin_6);
	return i;
}
int get_front_state(void)
{
	uint8_t i;
	i = Gec_GPIO_Get_Value(GPIOE,GPIO_Pin_5);
	return i;
}



void track(void)
{
	uint8_t left,right,front;
	left = get_left_state();
	right = get_right_state();
	front = get_front_state();
	if(front == WHITE ||(left == BLACK && right == BLACK ) )
	{
		car_stop();
		RunMode = BTCtrl;
		//SerialData = BTCtrl;
	}
	if( left == WHITE && right == WHITE && front == BLACK )
	{
		car_forward();	
	}
	if(left == BLACK && right == WHITE && front == BLACK )//左直转
	{
		turn_left();
	}
	if(left == WHITE && right == BLACK && front == BLACK)//左直转
	{
		turn_right();
	}
	

	
}




