#ifndef __MOTOR_H__
#define __MOTOR_H__

//ÂÖµÄ×´Ì¬
#define HIGHT_LEVEL 1
#define LOW_LEVLE   0

void car_ctrl_init(void);
void set_LA(int level);
void set_LB(int level);
void set_RA(int level);
void set_RB(int level);
void left_forward(void);
void left_back(void);
void right_forward(void);
void right_back(void);
void left_stop(void);
void right_stop(void);
void car_stop(void);
void car_pause(int time);
void car_forward(void);
void car_back(void);
void rotation_left(int time);
void rotation_right(int time);
void turn_left(void);
void turn_right(void);
void turn_right_2wheels(void);
void turn_left_2wheels(void);

#endif
