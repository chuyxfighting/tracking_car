#ifndef __BT_H__
#define __BT_H__



//蓝牙控制信号

#define FORWARD    1      //前进
#define BACK       2			//后退
#define TURN_LEFT	 3			//左转
#define TURN_RIGHT 4			//右转
#define STOP	     5			//停止

//RunMode
#define AutoCtrl   6			//自动循迹
#define BTCtrl	   7			//蓝牙控制

extern unsigned char SerialData;
extern char RunMode; 

void bt_Init(void);
void Serial_Rcv(void);
void bt_Ctrl(void);

#endif

