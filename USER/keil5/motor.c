#include "gec_gpio.h"
#include "motor.h"
#include "delay.h"
void car_ctrl_init(void)
{
	Gec_GPIO_Init(GPIOC, GPIO_Pin_6 |GPIO_Pin_7, GPIO_MODE_OUT_PP);
	Gec_GPIO_Init(GPIOC, GPIO_Pin_8 |GPIO_Pin_9, GPIO_MODE_OUT_PP);
	Gec_GPIO_Set_Value(GPIOC,GPIO_Pin_6,LOW_LEVLE);
	Gec_GPIO_Set_Value(GPIOC,GPIO_Pin_7,LOW_LEVLE);
	Gec_GPIO_Set_Value(GPIOC,GPIO_Pin_8,LOW_LEVLE);
	Gec_GPIO_Set_Value(GPIOC,GPIO_Pin_9,LOW_LEVLE);
}


//控制左轮正极
void set_LA(int level)
{
	Gec_GPIO_Set_Value(GPIOC,GPIO_Pin_6,level);
}
//控制左轮负极
void set_LB(int level)
{
	Gec_GPIO_Set_Value(GPIOC,GPIO_Pin_7,level);
}
//控制右轮正极
void set_RA(int level)
{
	Gec_GPIO_Set_Value(GPIOC,GPIO_Pin_8,level);
}

//控制右轮负极
void set_RB(int level)
{
	Gec_GPIO_Set_Value(GPIOC,GPIO_Pin_9,level);
}

//控制左轮前进
void left_forward(void)
{
		set_LA(1);
		set_LB(0);
}
//控制左轮后退
void left_back(void)
{
		set_LA(0);
		set_LB(1);
}
//控制右轮前进
void right_forward(void)
{
		set_RA(1);
		set_RB(0);
}
//控制右轮后退
void right_back(void)
{
		set_RA(0);
		set_RB(1);
}

//左轮停止
void left_stop(void)
{
		set_LA(0);
		set_LB(0);
}
//右轮停止
void right_stop(void)
{
		set_RA(0);
		set_RB(0);
}


//左慢转
void turn_left_2wheels(void)
{
	int i;
	for(i=0;i<20;i++)
	{
		left_stop();
		right_forward();
		delay_ms(60);
		left_forward();
		delay_ms(40);
	}
	
}
//右慢转
void turn_right_2wheels(void)
{
	int i;
	for(i=0;i<20;i++)
	{
		right_stop();
		left_forward();
		delay_ms(60);
		right_forward();
		delay_ms(40);
	}
	
}
//车前进
void car_forward(void)
{
		left_forward();
		right_forward();
		//delay_ms(80);
		//left_stop();
		//right_stop();
		//delay_ms(20);
	
}
//车后退
void car_back()
{
		left_back();
		right_back();
}
//车停止
void car_stop(void)
{
		left_stop();
		right_stop();
		//delay_ms(time);
}

void car_pause(int time)
{
		left_stop();
		right_stop();
		delay_ms(time);
}


//绕左轮直转
void turn_left(void)
{
	left_stop();
	right_forward();
	//delay_ms(time);
	
}
//绕右轮直转
void turn_right(void)
{
	right_stop();
	left_forward();
	//delay_ms(time);
}
//小车向左中心旋转
void rotation_left(int time)
{
	left_back();
	right_forward();
	delay_ms(time);
}
//小车向右中心旋转
void rotation_right(int time)
{
	left_forward();
	right_back();
	delay_ms(time);
}
