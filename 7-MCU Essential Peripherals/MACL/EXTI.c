/*
 * EXTI.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Ali Emad
 */

#include "stm32f103c8xx.h"
#include "GPIO.h"
#include "EXTI.h"
#include "BIT_Math.h"

void (*(gp_callBackFn[16]))(void); // from EXTI line 0 to 15 = 16 interrupt = 16 call back functions

/*
 * =============================================================================
 * 								Generic Macros
 * =============================================================================
 */

//#define AFIO_GPIO_EXTI_Mapping(x) (	(x==GPIOA) ? 0 : \
//		(x==GPIOB) ? 1 : \
//				(x==GPIOC) ? 2 : \
//						(x==GPIOD) ? 3 : 0 )

void EXTI_GPIO_init(EXTI_PIN_CONFG_t* extiConfig){

	/*============Set the GPIO Configurations========*/
	//extiConfig.intrPinCnfg = EXTI13PC13; (EXTI_GPIO_Mapping_t){ GPIO_PORT_C, GPIO_PIN_13, EXTI13_IRQ}
	GPIO_PIN_CONFG_t EXTI_PinConfig;

	//	-->extiConfig->intrPinCnfg.pin = GPIO_PIN_13;
	EXTI_PinConfig.GPIO_pinNum = extiConfig->exti_GPIOCnfg.pin;
	EXTI_PinConfig.GPIO_pinConfg = GPIO_IN_floating;
	//	EXTI_PinConfig.GPIO_MaxOutSpeed = 0;

	//	-->extiConfig->intrPinCnfg.port = GPIOC;
	GPIO_init(extiConfig->exti_GPIOCnfg.port, &EXTI_PinConfig);

	/*==================Set the AFIO registers======================*/
	uint8_t EXTI_AFIO_PORT_MAP = (((uint32_t)extiConfig->exti_GPIOCnfg.port - 0x40010800) / 0x400) & 0xf;
									//port A B C D mapped to 0 1 2 3 and mask the bits after the 3rd bit
	uint8_t index = extiConfig->exti_GPIOCnfg.pin / 4;
	uint8_t shift = ((extiConfig->exti_GPIOCnfg.pin % 4) * 4);

	AFIO->EXTICR[index] &= ~(0xf << (shift));             //clear EXTIx for EXTICRy
	AFIO->EXTICR[index] |= (EXTI_AFIO_PORT_MAP << (shift));	  // set  EXTIx for EXTICRy with port A B C D mapped to 0 1 2 3

	/*===============Set EXTI registers =================*/
	//		To generate the interrupt, the interrupt line should be configured and enabled.
	//	This is done by programming the two trigger registers with the desired edge
	//	detection and by enabling the interrupt request by writing a ‘1’ to the corresponding
	//	bit in the interrupt mask register.
	////	When the selected edge occurs on the external interrupt line,
	//	an interrupt request is generated. The pending bit corresponding to the interrupt
	//	line is also set. This request is reset by writing a ‘1’ in the pending register.

	/* Trigger state*/
	//extiConfig.trigger = EXTI_Trigger_RISING;
	if (extiConfig->trigger == EXTI_Trigger_RISING){
		EXTI->RTSR |= (1 << extiConfig->exti_GPIOCnfg.pin);
	}
	else if(extiConfig->trigger == EXTI_Trigger_RISING){
		EXTI->FTSR |= (1 << extiConfig->exti_GPIOCnfg.pin);
	}
	else if (extiConfig->trigger == EXTI_Trigger_RISING_OR_FALLING){
		EXTI->RTSR |= (1 << extiConfig->exti_GPIOCnfg.pin);
		EXTI->FTSR |= (1 << extiConfig->exti_GPIOCnfg.pin);
	}

	/*Set the non-mask bit*/
	EXTI->IMR |= (1 << extiConfig->exti_GPIOCnfg.pin);

	/*==================Set the NVIC registers=====================*/
	//extiConfig->intrPinCnfg.IRQ_Num = EXTI13_IRQ;
	Enable_NVIC(extiConfig->exti_GPIOCnfg.IRQ_Num);

	/*=================== Set the Call Back function==================*/
	//extiConfig.P_callBackFn = LED_high_callBack;
	gp_callBackFn[extiConfig->exti_GPIOCnfg.pin] = extiConfig->P_callBackFn;

}
void EXTI_GPIO_disable(EXTI_PIN_CONFG_t* extiConfig){


	//	-->extiConfig->intrPinCnfg.port = GPIOC;
	GPIO_reset(extiConfig->exti_GPIOCnfg.port);

	/*clear the non-mask bit*/
	EXTI->IMR &= ~(1 << extiConfig->exti_GPIOCnfg.pin);

	/*==================Set the NVIC registers=====================*/
	//extiConfig->intrPinCnfg.IRQ_Num = EXTI13_IRQ;
	Disable_NVIC(extiConfig->exti_GPIOCnfg.IRQ_Num);

}
void EXTI_GPIO_update(EXTI_PIN_CONFG_t* extiConfig){
	EXTI_GPIO_init(extiConfig);
}

void EXTI_reset(){
	EXTI->RTSR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->IMR = 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->EMR = 0x00000000;

	//all pins are Write 1 to clear
	EXTI->PR    = 0xFFFFFFFF;

	//Disable EXTI IRQ masks from NVIC
	NVIC_IRQ6_EXTI0_DISABLE()		;
	NVIC_IRQ7_EXTI1_DISABLE()		;
	NVIC_IRQ8_EXTI2_DISABLE()       ;
	NVIC_IRQ9_EXTI3_DISABLE()       ;
	NVIC_IRQ10_EXTI4_DISABLE()      ;
	NVIC_IRQ23_EXTI5_9_DISABLE()    ;
	NVIC_IRQ40_EXTI10_15_DISABLE()	;
}


void Enable_NVIC(uint8_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_ENABLE();
		break;
	case 1:
		NVIC_IRQ7_EXTI1_ENABLE();
		break;
	case 2:
		NVIC_IRQ8_EXTI2_ENABLE();
		break;
	case 3:
		NVIC_IRQ9_EXTI3_ENABLE();
		break;
	case 4:
		NVIC_IRQ10_EXTI4_ENABLE();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_ENABLE();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_ENABLE();
		break;

	}

}

void Disable_NVIC(uint8_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_DISABLE();
		break;
	case 1:
		NVIC_IRQ7_EXTI1_DISABLE();
		break;
	case 2:
		NVIC_IRQ8_EXTI2_DISABLE();
		break;
	case 3:
		NVIC_IRQ9_EXTI3_DISABLE();
		break;
	case 4:
		NVIC_IRQ10_EXTI4_DISABLE();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_DISABLE();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_DISABLE();
		break;

	}
}



/*
 * =============================================================================
 * 								ISR Functions
 * =============================================================================
 */

void EXTI0_IRQHandler(void)
{
	//Clear IRQ bit in Pending Register (EXTI_PR)
	EXTI->PR |= (1 <<0);

	//Call the IRQ callback Function
	gp_callBackFn[0]();

}

void EXTI1_IRQHandler(void)
{
	//Clear IRQ bit in Pending Register (EXTI_PR)
	EXTI->PR |= (1 <<1);

	//Call the IRQ callback Function
	gp_callBackFn[1]();

}

void EXTI2_IRQHandler(void)
{
	//Clear IRQ bit in Pending Register (EXTI_PR)
	EXTI->PR |= (1 <<2);

	//Call the IRQ callback Function
	gp_callBackFn[2]();

}

void EXTI3_IRQHandler(void)
{
	//Clear IRQ bit in Pending Register (EXTI_PR)
	EXTI->PR |= (1 <<3);

	//Call the IRQ callback Function
	gp_callBackFn[3]();

}

void EXTI4_IRQHandler(void)
{
	//Clear IRQ bit in Pending Register (EXTI_PR)
	EXTI->PR |= (1 <<4);

	//Call the IRQ callback Function
	gp_callBackFn[4]();

}

void EXTI9_5_IRQHandler(void)
{
	if(GET_BIT(EXTI->PR, 5)) {
		SET_BIT(EXTI->PR, 5);
		gp_callBackFn[5]();
	}
	if(EXTI->PR & (1 << 6)) { EXTI->PR |= (1 << 6); gp_callBackFn[6](); }
	if(EXTI->PR & (1 << 7)) { EXTI->PR |= (1 << 7); gp_callBackFn[7](); }
	if(EXTI->PR & (1 << 8)) { EXTI->PR |= (1 << 8); gp_callBackFn[8](); }
	if(EXTI->PR & (1 << 9)) { EXTI->PR |= (1 << 9); gp_callBackFn[9](); }
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & (1 << 10)) { EXTI->PR |= (1 << 10); gp_callBackFn[10](); }
	if(EXTI->PR & (1 << 11)) { EXTI->PR |= (1 << 11); gp_callBackFn[11](); }
	if(EXTI->PR & (1 << 12)) { EXTI->PR |= (1 << 12); gp_callBackFn[12](); }
	if(EXTI->PR & (1 << 13)) { EXTI->PR |= (1 << 13); gp_callBackFn[13](); }
	if(EXTI->PR & (1 << 14)) { EXTI->PR |= (1 << 14); gp_callBackFn[14](); }
	if(EXTI->PR & (1 << 15)) { EXTI->PR |= (1 << 15); gp_callBackFn[15](); }
}
