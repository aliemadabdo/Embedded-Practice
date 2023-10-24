/*
 ============================================================================
 Name        : STM32F103c6_GPIO.c
 Author      : Ali_Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdint.h>

// Set a specific bit in a register
#define SET_BIT(reg, bit) ((reg) |= (1 << (bit)))

// Reset (clear) a specific bit in a register
#define RESET_BIT(reg, bit) ((reg) &= ~(1 << (bit)))

// Read (get) the value of a specific bit in a register
#define READ_BIT(reg, bit) (((reg) >> (bit)) & 1)

// Toggle (invert) a specific bit in a register
#define TOGGLE_BIT(reg, bit) ((reg) ^= (1 << (bit)))

#define RCC_BASE   0x40021000
#define GPIOA_Base 0x40010800
#define GPIOB_Base 0x40010C00

#define RCC_APB2ENR *(volatile uint32_t*)(RCC_BASE + 0x18)  // BIT 2 =1  //this enables the GPIO

#define GPIOA_CRL  *(volatile uint32_t*) (GPIOA_Base + 0x00)
#define GPIOA_CRH  *(volatile uint32_t*) (GPIOA_Base + 0x04)
#define GPIOA_ODR  *(volatile uint32_t*) (GPIOA_Base + 0x08)
#define GPIOA_IDR  *(volatile uint32_t*) (GPIOA_Base + 0x0C)
#define GPIOA_BSRR *(volatile uint32_t*) (GPIOA_Base + 0x10)
#define GPIOA_BRR  *(volatile uint32_t*) (GPIOA_Base + 0x14)
#define GPIOA_LCKR *(volatile uint32_t*) (GPIOA_Base + 0x18)

#define GPIOB_CRL  *(volatile uint32_t*) (GPIOB_Base + 0x00)
#define GPIOB_CRH  *(volatile uint32_t*) (GPIOB_Base + 0x04)
#define GPIOB_ODR  *(volatile uint32_t*) (GPIOB_Base + 0x08)
#define GPIOB_IDR  *(volatile uint32_t*) (GPIOB_Base + 0x0C)
#define GPIOB_BSRR *(volatile uint32_t*) (GPIOB_Base + 0x10)
#define GPIOB_BRR  *(volatile uint32_t*) (GPIOB_Base + 0x14)
#define GPIOB_LCKR *(volatile uint32_t*) (GPIOB_Base + 0x18)

#define RCC_IOPAEN 	(1<<2)
#define RCC_IOPBEN 	(1<<3)

void GPIO_Init(void){
	/*set pin 1 port A as input pin*/
	// SET_BIT(GPIOA_CRL,6); --> WRONG
	GPIOA_CRL = 0x44444444;

	/*set pin 13 port A as output pin*/
	GPIOA_CRH = 0x44444444;

	/*set pin 1 port B as output pin*/
	// SET_BIT(GPIOB_CRL,4); --> WRONG
	GPIOA_CRL = 0x44444414;

	/*set pin 13 port B as output pin*/
	GPIOA_CRH = 0x44144444;
}

void clock_init(){
	RCC_APB2ENR |= RCC_IOPAEN;
	RCC_APB2ENR |= RCC_IOPBEN;

}

void delay(int count){
	for (int i = 0; i < count; i++);
}

int main(void) {
	
	clock_init();
	GPIO_Init();
	
	RESET_BIT(GPIOA_ODR,1);
	RESET_BIT(GPIOA_ODR,13);

	while (1)
	{
		/*Rising edge*/
		if (READ_BIT(GPIOA_IDR,1))
		{
			TOGGLE_BIT(GPIOA_ODR,1);
			while(READ_BIT(GPIOA_IDR,1) == 1);
		}

		/*Multi press*/
		if (READ_BIT(GPIOA_IDR,13))
		{
			SET_BIT(GPIOA_ODR,13);
			delay(1000);
			RESET_BIT(GPIOA_ODR,13);

		}
		
	}
	
	return 0;
}
