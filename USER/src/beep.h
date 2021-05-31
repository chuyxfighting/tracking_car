#ifndef __BEEP_H__
#define __BEEP_H__



/*
	beep_init: 蜂鸣器初始化函数
	参数：
		无。
	返回值：
		无。
*/
void beep_init(void);


/*
	beep_ctrl: 蜂鸣器控制函数
	@beep_ctrl: 开还是关蜂鸣器
			BEEP_ON 开蜂鸣器
			BEEP_OFF 关蜂鸣器
	返回值：
		无。
*/
void beep_ctrl(int beep_state);

enum BEEP_STATE{BEEP_OFF, BEEP_ON};
#endif
