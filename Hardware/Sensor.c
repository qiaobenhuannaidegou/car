#include "stm32f10x.h"                  // Device header

void Sensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

uint8_t Get_RSensor(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1);
}

uint8_t Get_LSensor(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);
}
