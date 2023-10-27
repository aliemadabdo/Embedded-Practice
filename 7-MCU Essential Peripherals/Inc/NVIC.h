/*
 * NVIC.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Mega Store
 */

#ifndef INC_NVIC_H_
#define INC_NVIC_H_

#include "stm32f103c8xx.h"

//-*-*-*-*-*-*-*-*-*-*-*-
//IVT Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40


//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ Enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_IRQ6_EXTI0_ENABLE()				(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_ENABLE()				(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_ENABLE()				(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_ENABLE()				(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_ENABLE()				(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_ENABLE()				(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_ENABLE()			(NVIC_ISER1 |= 1<<8)  //40-32 = 8


#define NVIC_IRQ6_EXTI0_DISABLE()				(NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_DISABLE()				(NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_DISABLE()				(NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_DISABLE()				(NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_DISABLE()				(NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_DISABLE()			(NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_DISABLE()			(NVIC_ICER1 |= 1<<8)  //40-32 = 8

//void Enable_NVIC(uint16_t IRQ)
//{
//	switch(IRQ)
//	{
//	case 0:
//		NVIC_IRQ6_EXTI0_ENABLE();
//		break;
//	case 1:
//		NVIC_IRQ7_EXTI1_ENABLE();
//		break;
//	case 2:
//		NVIC_IRQ8_EXTI2_ENABLE();
//		break;
//	case 3:
//		NVIC_IRQ9_EXTI3_ENABLE();
//		break;
//	case 4:
//		NVIC_IRQ10_EXTI4_ENABLE();
//		break;
//	case 5:
//	case 6:
//	case 7:
//	case 8:
//	case 9:
//		NVIC_IRQ23_EXTI5_9_ENABLE();
//		break;
//	case 10:
//	case 11:
//	case 12:
//	case 13:
//	case 14:
//	case 15:
//		NVIC_IRQ40_EXTI10_15_ENABLE();
//		break;
//
//	}
//
//}
//
//void Disable_NVIC(uint16_t IRQ)
//{
//	switch(IRQ)
//	{
//	case 0:
//		NVIC_IRQ6_EXTI0_DISABLE();
//		break;
//	case 1:
//		NVIC_IRQ7_EXTI1_DISABLE();
//		break;
//	case 2:
//		NVIC_IRQ8_EXTI2_DISABLE();
//		break;
//	case 3:
//		NVIC_IRQ9_EXTI3_DISABLE();
//		break;
//	case 4:
//		NVIC_IRQ10_EXTI4_DISABLE();
//		break;
//	case 5:
//	case 6:
//	case 7:
//	case 8:
//	case 9:
//		NVIC_IRQ23_EXTI5_9_DISABLE();
//		break;
//	case 10:
//	case 11:
//	case 12:
//	case 13:
//	case 14:
//	case 15:
//		NVIC_IRQ40_EXTI10_15_DISABLE();
//		break;
//
//	}
//}


#endif /* INC_NVIC_H_ */
