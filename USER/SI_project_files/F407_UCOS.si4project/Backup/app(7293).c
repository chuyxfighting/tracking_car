

#include "includes.h"
#include "led.h"
//#include "uart.h"
#include "os_cfg_app.h"

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

	led_init();
	while (1)
	{
		led_ctrl(LED_D1, LED_ON);
		delay_ms(2000);

		led_ctrl(LED_D1, LED_OFF);
		delay_ms(2000);
		
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

	


	OSTaskCreate(&tcb1, //保存新创建任务的TCB信息 
			"task1", //任务名字 
			task1_rountine, //"任务函数"
			NULL, //任务函数的参数 
			4, //任务优先级，数字越小，优先级越大 
			tcb1_stk, //任务栈基址 
			12, //任务栈下限值
			TASK1_STK_SIZE,//任务栈大小
			5, //任务消息队列上最大消息数 
			10,//任务时间片大小
			NULL, //任务补充的内存区 
			OS_OPT_TASK_NONE, //额外选项
			&err);
	if (err != OS_ERR_NONE)
	{}


	

	//启动UCOS-III的“任务循环/”
	OSStart(&err);

    return 0;
}