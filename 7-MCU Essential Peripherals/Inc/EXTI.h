/*
 * EXTI.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Mega Store
 */

/*
 * TODO:
 * 1- Testing
 * 2- Check warnings
 * 3- A separate NVIC Driver
 * */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include "stm32f103c8xx.h"
#include "NVIC.h"


typedef struct{
	GPIO_TypeDef* port;
	uint16_t pin;
	uint8_t IRQ_Num;
}EXTI_GPIO_Mapping_t;

typedef struct{
	EXTI_GPIO_Mapping_t exti_GPIOCnfg;

	uint8_t trigger;

	void (*P_callBackFn)(void);


}EXTI_PIN_CONFG_t;


//@ref EXTI_Trigger_define
#define EXTI_Trigger_RISING					0
#define EXTI_Trigger_FALLING				1
#define EXTI_Trigger_RISING_OR_FALLING		2


////@ref EXTI_IRQ_define
//#define EXTI_IRQ_ENABLE				1
//#define EXTI_IRQ_DISABLE			0


//@ref EXTI_define

/*the type casting step is used to create an "instance" of the
 * EXTI_GPIO_Mapping_t structure and initialize its fields in a single line.
 *
 * Also the type casting step is used to be able to send the desired data type type not just a random struct <<<<<<<<< حلوه*/

//EXTI0 Configuration
#define EXTI0PA0 (EXTI_GPIO_Mapping_t){ GPIOA, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PB0 (EXTI_GPIO_Mapping_t){ GPIOB, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PC0 (EXTI_GPIO_Mapping_t){ GPIOC, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PD0 (EXTI_GPIO_Mapping_t){ GPIOD, GPIO_PIN_0, EXTI0_IRQ}

//EXTI1 Configuration
#define EXTI1PA1 (EXTI_GPIO_Mapping_t){ GPIOA, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1PB1 (EXTI_GPIO_Mapping_t){ GPIOB, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1PC1 (EXTI_GPIO_Mapping_t){ GPIOC, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1PD1 (EXTI_GPIO_Mapping_t){ GPIOD, GPIO_PIN_1, EXTI1_IRQ}

//EXTI2 Configuration
#define EXTI2PA2 (EXTI_GPIO_Mapping_t){ GPIOA, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2PB2 (EXTI_GPIO_Mapping_t){ GPIOB, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2PC2 (EXTI_GPIO_Mapping_t){ GPIOC, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2PD2 (EXTI_GPIO_Mapping_t){ GPIOD, GPIO_PIN_2, EXTI2_IRQ}

//EXTI3 Configuration
#define EXTI3PA3 (EXTI_GPIO_Mapping_t){  GPIOA, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3PB3 (EXTI_GPIO_Mapping_t){  GPIOB, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3PC3 (EXTI_GPIO_Mapping_t){  GPIOC, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3PD3 (EXTI_GPIO_Mapping_t){  GPIOD, GPIO_PIN_3, EXTI3_IRQ}

//EXTI4 Configuration
#define EXTI4PA4 (EXTI_GPIO_Mapping_t){  GPIOA, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4PB4 (EXTI_GPIO_Mapping_t){  GPIOB, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4PC4 (EXTI_GPIO_Mapping_t){  GPIOC, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4PD4 (EXTI_GPIO_Mapping_t){  GPIOD, GPIO_PIN_4, EXTI4_IRQ}

//EXTI5 Configuration
#define EXTI5PA5 (EXTI_GPIO_Mapping_t){  GPIOA, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5PB5 (EXTI_GPIO_Mapping_t){  GPIOB, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5PC5 (EXTI_GPIO_Mapping_t){  GPIOC, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5PD5 (EXTI_GPIO_Mapping_t){  GPIOD, GPIO_PIN_5, EXTI5_IRQ}

//EXTI6 Configuration
#define EXTI6PA6 (EXTI_GPIO_Mapping_t){  GPIOA, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6PB6 (EXTI_GPIO_Mapping_t){  GPIOB, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6PC6 (EXTI_GPIO_Mapping_t){  GPIOC, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6PD6 (EXTI_GPIO_Mapping_t){  GPIOD, GPIO_PIN_6, EXTI6_IRQ}

//EXTI7 Configuration
#define EXTI7PA7 (EXTI_GPIO_Mapping_t){  GPIOA, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7PB7 (EXTI_GPIO_Mapping_t){  GPIOB, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7PC7 (EXTI_GPIO_Mapping_t){  GPIOC, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7PD7 (EXTI_GPIO_Mapping_t){  GPIOD, GPIO_PIN_7, EXTI7_IRQ}

//EXTI8 Configuration
#define EXTI8PA8 (EXTI_GPIO_Mapping_t){  GPIOA, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8PB8 (EXTI_GPIO_Mapping_t){  GPIOB, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8PC8 (EXTI_GPIO_Mapping_t){  GPIOC, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8PD8 (EXTI_GPIO_Mapping_t){  GPIOD, GPIO_PIN_8, EXTI8_IRQ}

//EXTI9 Configuration
#define EXTI9PA9 (EXTI_GPIO_Mapping_t){  GPIOA, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9PB9 (EXTI_GPIO_Mapping_t){  GPIOB, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9PC9 (EXTI_GPIO_Mapping_t){  GPIOC, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9PD9 (EXTI_GPIO_Mapping_t){  GPIOD, GPIO_PIN_9, EXTI9_IRQ}

//EXTI10 Configuration
#define EXTI10PA10 (EXTI_GPIO_Mapping_t){ GPIOA, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10PB10 (EXTI_GPIO_Mapping_t){ GPIOB, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10PC10 (EXTI_GPIO_Mapping_t){ GPIOC, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10PD10 (EXTI_GPIO_Mapping_t){ GPIOD, GPIO_PIN_10, EXTI10_IRQ}

//EXTI11 Configuration
#define EXTI11PA11 (EXTI_GPIO_Mapping_t){ GPIOA, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11PB11 (EXTI_GPIO_Mapping_t){ GPIOB, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11PC11 (EXTI_GPIO_Mapping_t){ GPIOC, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11PD11 (EXTI_GPIO_Mapping_t){ GPIOD, GPIO_PIN_11, EXTI11_IRQ}

//EXTI12 Configuration
#define EXTI12PA12 (EXTI_GPIO_Mapping_t){ GPIOA, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12PB12 (EXTI_GPIO_Mapping_t){ GPIOB, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12PC12 (EXTI_GPIO_Mapping_t){ GPIOC, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12PD12 (EXTI_GPIO_Mapping_t){ GPIOD, GPIO_PIN_12, EXTI12_IRQ}

//EXTI13 Configuration
#define EXTI13PA13 (EXTI_GPIO_Mapping_t){ GPIOA, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13PB13 (EXTI_GPIO_Mapping_t){ GPIOB, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13PC13 (EXTI_GPIO_Mapping_t){ GPIOC, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13PD13 (EXTI_GPIO_Mapping_t){ GPIOD, GPIO_PIN_13, EXTI13_IRQ}

//EXTI14 Configuration
#define EXTI14PA14 (EXTI_GPIO_Mapping_t){ GPIOA, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14PB14 (EXTI_GPIO_Mapping_t){ GPIOB, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14PC14 (EXTI_GPIO_Mapping_t){ GPIOC, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14PD14 (EXTI_GPIO_Mapping_t){ GPIOD, GPIO_PIN_14, EXTI14_IRQ}

//EXTI15 Configuration
#define EXTI15PA15 (EXTI_GPIO_Mapping_t){ GPIOA, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15PB15 (EXTI_GPIO_Mapping_t){ GPIOB, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15PC15 (EXTI_GPIO_Mapping_t){ GPIOC, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15PD15 (EXTI_GPIO_Mapping_t){ GPIOD, GPIO_PIN_15, EXTI15_IRQ}

/*================================================APIs=======================================*/
void EXTI_GPIO_init(EXTI_PIN_CONFG_t* extiConfig);
void EXTI_GPIO_disable(EXTI_PIN_CONFG_t* extiConfig);
void EXTI_GPIO_update(EXTI_PIN_CONFG_t* extiConfig);
void EXTI_reset();


#endif /* INC_EXTI_H_ */
