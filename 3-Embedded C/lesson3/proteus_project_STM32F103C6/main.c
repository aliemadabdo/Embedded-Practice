/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

typedef volatile unsigned int vuint32_t;

#include <stdint.h>

#define RCC_BASE 	0x40021000
#define GPIOA_BASE 	0x40010800
#define RCC_APB2ENR *(volatile uint32_t*)(RCC_BASE + 0x18)  // BIT 2 =1                 //this enables the GPIO
#define GPIOA_CRH 	*(volatile uint32_t*)(GPIOA_BASE + 0x04) // 20 TO 23 BITS = 0010 (2) //this like control settings
#define GPIOA_ODR 	*(volatile uint32_t*)(GPIOA_BASE + 0x0C) // BIT 13 = 1			   //the bit value it self

#define RCC_IOPAEN 	(1<<2)
#define GPIOA13		(1UL<<13)

typedef union{
	vuint32_t 		all_fields;
	struct {
		vuint32_t 	reserved:  13;
		vuint32_t 	P_13: 	   1;

	}Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);
unsigned char g_variables[3] = {1,2,3};
unsigned char const const_variables[3] = {1,2,3};
volatile unsigned char un_init_vars[3];

void H_fault_Handler(void){
	
} //To check weak and alias effect

int main(void) {

	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000; 

	un_init_vars[0] = (char)100;
	un_init_vars[0] = (char)200;
	while(1){
		R_ODR->Pin.P_13 = 1;
		for(int i=0; i<(int)un_init_vars[0]; i++);
		R_ODR->Pin.P_13 = 0;
		for(int i=0; i<(int)un_init_vars[1]; i++);
//Other solution
//		GPIOA_ODR ^= 1<<13;
//		for(int i=0; i<5000; i++);
	}

	return 0;
}