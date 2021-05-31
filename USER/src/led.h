#ifndef __LED_H__
#define __LED_H__

//灯的编号的宏
#define LED_D1 1
#define LED_D2 2
#define LED_D3 3
#define LED_D4 4
#define LED_ALL 100

//灯的操作
#define LED_ON 0
#define LED_OFF 1



/*
	led_init:初始化LED灯相应的GPIO引脚
*/
void led_init(void);


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
void led_ctrl(int led_id, int OnOff);


#endif
