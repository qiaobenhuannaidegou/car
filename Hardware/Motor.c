#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	PWM_Init();
}

void Motor_SetSpeed(uint8_t L_Speed, uint8_t R_Speed)
{
    if (L_Speed < 20) L_Speed = 20; // 防止低速失速
    if (R_Speed < 20) R_Speed = 20; // 防止低速失速

    GPIO_SetBits(GPIOB, GPIO_Pin_13);
    GPIO_ResetBits(GPIOB, GPIO_Pin_12);
    PWM_SetCompare1(L_Speed);

    GPIO_SetBits(GPIOB, GPIO_Pin_15);
    GPIO_ResetBits(GPIOB, GPIO_Pin_14);
    PWM_SetCompare2(R_Speed);
}

void Forword(void)
{
	Motor_SetSpeed(75,75);
}

void Turn_Left(void)
{
	Motor_SetSpeed(65,45);
}

void Turn_Right(void)
{
	Motor_SetSpeed(45,65);
}

void Stop(void)
{
	Motor_SetSpeed(0,0);
}
