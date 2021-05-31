#include "stm32f4xx.h"
#include "stdio.h"
unsigned char data;
void uart1_init(uint32_t baudrate)
{
	/*1GPIO???*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructA;
	GPIO_InitStructA.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructA.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructA.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructA.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructA.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_InitStructA);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

	/*2USART??*/
	USART_InitTypeDef USART1_InitStruct;
	USART1_InitStruct.USART_BaudRate = baudrate;
	USART1_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART1_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART1_InitStruct.USART_Parity = USART_Parity_No;
	USART1_InitStruct.USART_StopBits = USART_StopBits_1;
	USART1_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART1_InitStruct);

	/*3????*/
	USART_ITConfig  (USART1,USART_IT_RXNE,ENABLE);
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;
	NVIC_Init(&NVIC_InitStruct);
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2 ); 	

	/*4????*/
	USART_Cmd(USART1, ENABLE);
}

void USART1_IRQHandler()
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE) != RESET)//?????????
	{
		//??????
		data = USART_ReceiveData(USART1);//????????
		
		USART_SendData(USART1,data);
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);//??????
		
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
}

void USART1_SendData(unsigned char *data,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		USART_SendData(USART1,data[i]);
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);//??????
	}
}
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout; 
int fputc(int ch,FILE *f)
{
	USART_SendData(USART1,ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	return ch;
}
