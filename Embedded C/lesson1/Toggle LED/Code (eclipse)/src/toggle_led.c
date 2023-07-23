/*
 ============================================================================
 Name        : toggle_led.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "platform_type.h"

#define RCC_BASE 0x40021000
#define GPIO_BASE 0x40010800
#define RCC_APB2ENR *(vuint32*)(RCC_BASE+0x18)  // BIT 2 =1                 //this enables the GPIO
#define GPIO_PA_CRH *(vuint32*)(GPIO_BASE+0x04) // 20 TO 23 BITS = 0010 (2) //this like control settings
#define GPIO_PA_ODR *(vuint32*)(GPIO_BASE+0x0C) // BIT 13 = 1			   //the bit value it self

typedef union{
	vuint32 all_pins;
	struct {
		vuint32 reserved : 13;
		vuint32 pin13 : 1;

	}pins;
}R_ODR_t;

volatile R_ODR_t* odr_ptr = (volatile R_ODR_t*)(GPIO_BASE+0x0C);

int main(void) {

	RCC_APB2ENR |= 1<<2;
	GPIO_PA_CRH &= 0xff0fffff;
	GPIO_PA_CRH |= 0x00200000;

	while(1){
		odr_ptr->pins.pin13 = 1;
		for(int i=0; i<1000; i++);
		odr_ptr->pins.pin13 = 0;
		for(int i=0; i<1000; i++);
//Other solution
//		GPIO_PA_ODR ^= 1<<13;
//		for(int i=0; i<1000; i++);
	}

	return 0;
}
