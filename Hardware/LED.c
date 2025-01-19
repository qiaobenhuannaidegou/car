#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //推挽
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);
}

void LED3_ON(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_3);
}

void LED3_OFF(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_3);
}

void LED4_ON(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_4);
}

void LED4_OFF(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_4);
}

void LED5_ON(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
}

void LED5_OFF(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
}
