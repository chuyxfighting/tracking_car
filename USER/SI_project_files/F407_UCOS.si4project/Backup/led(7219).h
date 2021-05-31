#ifndef __LED_H__
#define __LED_H__

//F407上，灯的编号 
#define LED_D1  1
#define LED_D2  2
#define LED_D3  3
#define LED_D4  4


//灯控制操作的宏
#define LED_ON 0
#define LED_OFF 1





/*
	led_init:LED初始化函数
	参数：
		无
	返回值：
		无。
*/
void led_init(void);


/*
	led_ctrl:灯控函数
	@led_num: 要控制哪个灯，如：
				LED_D1
				LED_D2
				LED_D3
				LED_D4
	@led_state: 要开灯还是关灯，
				LED_ON  开灯
				LED_OFF 关灯
	返回值：
		无。
*/
void led_ctrl(int led_num, int led_state);




#endif
