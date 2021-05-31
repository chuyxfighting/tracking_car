#include "bt.h"
#include "gec_uart.h"
#include "bsp.h"
#include "motor.h"
#include "led.h"
#include "track.h"


void Serial_Rcv(void)
{
	if(USART_GetITStatus(USART2,USART_IT_RXNE) == SET)/*判断一下我们的中断标志位是不是真的被设置*/
	{
		//保存数据
		SerialData = USART_ReceiveData(USART2);
		//bt_Ctrl();
		//手动的清除中断标志位
		USART_ClearITPendingBit(USART2,USART_IT_RXNE);
	}
}
  

void bt_Init()
{
	//1.串口初始化
	Gec_UART_Init(USART2,9600,USART_Parity_No,8,1);
	//2.写一个中断并注册
	BSP_IntVectSet(BSP_INT_ID_USART2,Serial_Rcv);
	//3.使能中断
	BSP_IntEn(BSP_INT_ID_USART2);
}
void bt_Ctrl()
{
	while(1)
	{
		
		if(SerialData == AutoCtrl)
		{
			//track();
			RunMode = AutoCtrl;
			break;
		}
		if(SerialData == FORWARD)
		{
			//调用前进
			car_forward();
			//led_ctrl(LED_D1,LED_ON);
		}
		if(SerialData == BACK)
		{
			//调用后退
			car_back();
			//led_ctrl(LED_D2,LED_ON);
		}
		if(SerialData == TURN_LEFT)
		{
			//调用左转
			turn_left();
			//led_ctrl(LED_D3,LED_ON);
		}
		if(SerialData == TURN_RIGHT)
		{
			//调用右转
			turn_right();
			//led_ctrl(LED_D4,LED_ON);
		}
		if(SerialData == STOP)
		{
			//调用停止
			car_stop();
			//led_ctrl(LED_D4,LED_OFF);
		}
		
	}
	
}



