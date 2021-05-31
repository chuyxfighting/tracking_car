#include "includes.h"
#include "led.h"
#include "os_cfg_app.h"
#include "delay.h"
#include "motor.h"
#include "track.h"
#include "bt.h"



unsigned char SerialData;											//蓝牙控制信号
char RunMode = AutoCtrl;												//状态机：自动运行模式

OS_TCB  tcb1 ;
#define TASK1_STK_SIZE  100
CPU_STK tcb1_stk[TASK1_STK_SIZE]; //任务1的栈空间
					  //有能存放100个栈元素，每个栈元素的类型是CPU_STK
					  //任务1的栈空间字节大小为: 100 * sizeof(CPU_STK)
					  //任务1的栈空间大小为: 100

//"任务函数"
void task1_rountine(void * data)
{
	
	OS_ERR err;
	car_ctrl_init();//车轮控制GPIO初始化
	track_init();//循迹信号GPIO初始化
	bt_Init();
	//led_init();
	while (1)
	{
		if(RunMode == AutoCtrl)
		{
			track();
		}
		if(RunMode == BTCtrl)
		{
			bt_Ctrl();
		}
		

	}

}
/**
  * @brief  SysTick系统时钟设置函数
  * @param  无
  * @retval 无
  */
void SysTick_init(void)
{
	SysTick->CTRL|=SysTick_CTRL_TICKINT_Msk;//使能SysTick中断
	SysTick->LOAD=SystemCoreClock/8/OSCfg_TickRate_Hz;//设置定时周期	
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;//开启定时器
}
int main()
{
	int a;

	OS_ERR err;


	
	// 底层硬件的初始化
   	BSP_IntDisAll();                                            /* Disable all interrupts.                              */
    
    CPU_Init();                                                 /* Initialize the uC/CPU Services                       */
    Mem_Init();                                                 /* Initialize Memory Management Module                  */
    Math_Init();                                                /* Initialize Mathematical Module                       */

	
	BSP_Init(); // BSP初始化	

	BSP_Tick_Init(); //初始化SysTick时钟
		//操作系统(UCOS)的初始化
	OSInit(&err);

	OSSchedRoundRobinCfg(DEF_ENABLED,5,&err);

	OSTaskCreate( &tcb1,  //用来保存“任务控制块，TCB”
				"task1", //任务的名字
				task1_rountine,  //"任务函数"
				NULL, //“任务函数的参数” 

				3,				//任务优先级， [2, OS_CFG_PRIO_MAX]

				tcb1_stk, //指向任务的栈空间的基址 
				TASK1_STK_SIZE/10, //设置栈中剩余多少空间时，“报警” 
				TASK1_STK_SIZE, //指定任务栈最多能存放的元素个数
				
				10, //指定任务消息队列上的最大消息数 

				10, //指定任务的“时间片的长度”，10个tick  
							
	
				NULL,//指向用户补充的存储区  
				OS_OPT_TASK_NONE , //指定任务额外的选项 
				&err //用来保存出错信息
				);
					//启动UCOS-III的“任务循环/”
	OSStart(&err);

    return 0;
}

