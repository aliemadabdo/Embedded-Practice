/*
 * GPIO.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ali Emad
 */

#include "BIT_Math.h"
#include "stm32f103c8xx.h"
#include "GPIO.h"

/*Pseudo code
 *
 * MAIN:
 * GPIO_PIN_CONFG* pinConfg;
 * pinConfg->GPIO_MaxOutSpeed = MAX_OUT_Speed_50M;
 * pinConfig->GPIO_pinConfg = OUT_push_pull;
 * pinConfig->GPIO_pinNum = GPIO_PIN_3;
 * GPIO_init(GPIOA, pinConfig)
 *
 * DRIVER:
 * void GPIO_init(GPIO_TypeDef* GPIOx,GPIO_PIN_CONFG* pinConfig){
 * if (pinconfg->GPIO_pinNum > 8){
 *
 *
 * GPIOx->CRL |= (pinConfig->GPIO_pinConfg << pinconfg->GPIO_pinNum * 4 + 1)
 * if pinconfg->GPIO_pinConfg > 4
 *  * GPIOx->CRL &= ~(0b11 << pinconfg->GPIO_pinNum * 4 - 1)
 *  else
 *  * GPIOx->CRL |= (pinConfig->GPIO_MaxOutSpeed << pinconfg->GPIO_pinNum * 4 - 1)
 *
 * }else{}
 * */

/**================================================================
 * * @Fn			- GPIO_init
 * * @brief 		- Configurates the desired GPIO Pin as Input (with Pull and Pull down configuration ) or Output (With speed mode setup)
 * * @param [in] 	- GPIOx: GPIO port that include the target pin from port A to E
 * * @param [in] 	- pinConfig: The full configuration structure of the pin to be set.
 * * @retval 		- none
 * * Note			- Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 * */
void GPIO_init(GPIO_TypeDef* GPIOx,GPIO_PIN_CONFG_t* pinConfig){

	if (pinConfig->GPIO_pinNum < 0x0008 /*0b10000000*/ ){ //check if (CRL) or CRH
		 GPIOx->CRL &= ~(3 << ((pinConfig->GPIO_pinNum * 4) + 2)); // clear the configuration bits
		 GPIOx->CRL |= (pinConfig->GPIO_pinConfg << ((pinConfig->GPIO_pinNum * 4) + 2)); // set the configuration bits

		if (pinConfig-> GPIO_pinConfg > 0x00000004u){ // Check if (Input) or Output
			GPIOx->CRL &= ~(3 << pinConfig->GPIO_pinNum * 4);

			if(pinConfig-> GPIO_pinConfg == GPIO_IN_pull_up){ // check if the input pull up
				GPIOx->BSRR = 1 << pinConfig->GPIO_pinNum;
			}
			else if(pinConfig-> GPIO_pinConfg == GPIO_IN_pull_down){ //check if input pull down
				GPIOx->BRR = 1 << pinConfig->GPIO_pinNum;
			}
		}
		else{ // output
			GPIOx->CRL &= ~(3 << pinConfig->GPIO_pinNum * 4);
			GPIOx->CRL |= (pinConfig->GPIO_MaxOutSpeed << pinConfig->GPIO_pinNum * 4);
		}
	}
	else{
		 GPIOx->CRH &= ~(3 << ((pinConfig->GPIO_pinNum * 4) + 2)); // clear the configuration bits
		 GPIOx->CRH |= ( (pinConfig->GPIO_pinConfg - 4) << ((pinConfig->GPIO_pinNum * 4) + 2)); // //@ref GPIO_PIN_Configurations (x - 4)

		if (pinConfig-> GPIO_pinConfg > 0x00000004u){ // Check if (Input) or Output
			GPIOx->CRH &= ~(3 << pinConfig->GPIO_pinNum * 4);

			if(pinConfig-> GPIO_pinConfg == GPIO_IN_pull_up){ // check if the input pull up
				GPIOx->BSRR = 1 << pinConfig->GPIO_pinNum;
			}
			else if(pinConfig-> GPIO_pinConfg == GPIO_IN_pull_down){ // check if the input pull down
				GPIOx->BRR = 1 << pinConfig->GPIO_pinNum;
			}
		}
		else{ // output
			GPIOx->CRH &= ~(3 << pinConfig->GPIO_pinNum * 4);
			GPIOx->CRH |= (pinConfig->GPIO_MaxOutSpeed << pinConfig->GPIO_pinNum * 4);
		}
	}


}

/**================================================================
 * * @Fn			- GPIO_reset
 * * @brief 		- Resets the GPIO peripheral through the reset unit within the RCC
 * * @param [in] 	- GPIOx: GPIO port that include the target pin from port A to E
 * * @retval 		- none
 * * Note			- none
 * */
void GPIO_reset(GPIO_TypeDef* GPIOx){
		((( RCC_TypeDef *)0x40021000)->APB2RSTR) |= (1<< (((uint32_t)GPIOx - 0x40010000) / 0x400) );
		//This line is the same structure of RCC_GPIOA_RST() but expanded to avoid including the RCC driver
		//(((uint32_t)GPIOx - 0x40010000) / 0x400) This mapping is used to get the the bit position that resets the corresponding gpio
}

/**================================================================
 * * @Fn			- GPIO_read_pin
 * * @brief 		- reads the input voltage applied on a specified pin
 * * @param [in] 	- GPIOx: GPIO port that include the target pin from port A to E
 * * @param [in] 	- pinNum: The pin number (from 0 to 15) in the port to apply the read operation on it
 * * @retval 		- returns the pin value (0 or 1)
 * * Note			- none
 * */
uint8_t GPIO_read_pin(GPIO_TypeDef* GPIOx, uint8_t pinNum){
	return GET_BIT(GPIOx->IDR, pinNum);
}

/**================================================================
 * * @Fn			- GPIO_read_port
 * * @brief 		- reads the input voltage applied on a specified port
 * * @param [in] 	- GPIOx: GPIO port that include the target pin from port A to E
 * * @retval 		- returns the Port value (0x0000 or 0xffff)
 * * Note			- none
 * */
uint16_t GPIO_read_port(GPIO_TypeDef* GPIOx){
//	uint16_t port;
//	port =  (GET_BIT(GPIOx->IDR, 0) << 0) |
//			(GET_BIT(GPIOx->IDR, 1) << 1) |
//			(GET_BIT(GPIOx->IDR, 2) << 2) |
//			(GET_BIT(GPIOx->IDR, 3) << 3) |
//			(GET_BIT(GPIOx->IDR, 4) << 4) |
//			(GET_BIT(GPIOx->IDR, 5) << 5) |
//			(GET_BIT(GPIOx->IDR, 6) << 6) |
//			(GET_BIT(GPIOx->IDR, 7) << 7) |
//			(GET_BIT(GPIOx->IDR, 8) << 8) |
//			(GET_BIT(GPIOx->IDR, 9) << 9) |
//			(GET_BIT(GPIOx->IDR, 10) << 10) |
//			(GET_BIT(GPIOx->IDR, 11) << 11) |
//			(GET_BIT(GPIOx->IDR, 12) << 12) |
//			(GET_BIT(GPIOx->IDR, 13) << 13) |
//			(GET_BIT(GPIOx->IDR, 14) << 14) |
//			(GET_BIT(GPIOx->IDR, 15) << 15) ;
//	return port;

	return (uint16_t)(GPIOx->IDR & GPIO_PIN_MASK);
}

/**================================================================
 * * @Fn			- GPIO_write_pin
 * * @brief 		- Writes value on a specified pin
 * * @param [in] 	- GPIOx: GPIO port that include the target pin from port A to E
 * * @param [in] 	- pinNum: The pin number (from 0 to 15) in the port to apply the write operation on it
 * * @param [in] 	- value: the value to be seated (0 or 1)
 * * @retval 		- none
 * * Note			- none
 * */
void GPIO_write_pin(GPIO_TypeDef* GPIOx, uint8_t pinNum, uint8_t value){
	GPIOx->ODR |= (((uint16_t)value) << pinNum);
}

/**================================================================
 * * @Fn			- GPIO_write_port
 * * @brief 		- Writes value on a specified port
 * * @param [in] 	- GPIOx: GPIO port that include the target pin from port A to E
 * * @param [in] 	- value: the value to be seated (0x0000 or 0xffff)
 * * @retval 		- none
 * * Note			- none
 * */
void GPIO_write_port(GPIO_TypeDef* GPIOx, uint16_t value){
	GPIOx->ODR = value;
}

/**================================================================
 * * @Fn			- GPIO_toggle_pin
 * * @brief 		- flip the logic of the pin
 * * @param [in] 	- GPIOx: GPIO port that include the target pin from port A to E
 * * @param [in] 	- pinNum: The pin number (from 0 to 15) in the port to apply the toggle operation on it
 * * @retval 		- none
 * * Note			- none
 * */
void GPIO_toggle_pin(GPIO_TypeDef* GPIOx, uint8_t pinNum){
	TGL_BIT(GPIOx->ODR,pinNum);
}

/**================================================================
 * * @Fn			- GPIO_write_pin
 * * @brief 		- Writes value (0 or 1) on a specified pin
 * * @param [in] 	- GPIOx: GPIO port that include the target pin from port A to E
 * * @param [in] 	- pinNum: The pin number (from 0 to 15) in the port to apply the lock operation on it
 * * @retval 		- return the status of the lock (enabled of error)
 * * Note			- none
 * */
uint8_t GPIO_lock_pin(GPIO_TypeDef* GPIOx, uint8_t pinNum){

//	Bit 16 LCKK[16]: Lock key
//	This bit can be read anytime.
//	It can only be modified using the Lock Key Writing Sequence.
//			0: Port configuration lock key not active
//			1: Port configuration lock key active.
//	 GPIOx_LCKR register is locked until the next reset.

//	 LOCK key writing sequence:
//	 Write 1 --> store
//	 Write 0 --> store
//	 Write 1 --> store
//	 Read 0 --> fetch
//	 Read 1 --> fetch (this read is optional but confirms that the lock is active)
//	 Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
//	 Any error in the lock sequence will abort the lock.

//	 Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
//	These bits are read write but can only be written when the LCKK bit is 0.
//	 	 0: Port configuration not locked
//		 1: Port configuration locked

//	//Locked pin
//	SET_BIT(GPIOx->LCKR,pinNum);
//
//	//Lock sequence
//	SET_BIT(GPIOx->LCKR,16);
//	CLR_BIT(GPIOx->LCKR,16);
//	SET_BIT(GPIOx->LCKR,16);
//	SET_BIT(GPIOx->LCKR,16);
//	GET_BIT(GPIOx->LCKR,16); //not used warning
//	if ( GET_BIT(GPIOx->LCKR,16) == 1){
//		return GPIO_Lock_Enabled;
//	}
//	else{
//		return GPIO_Lock_Error;
//	}

	/* This way of implementation may have some problems as when we
	 * set, clear or toggle we fetch(read) the lock register and store value in it (write)
	 * which will distract the desired sequence*/

	//Set LCKK[16]
	volatile uint32_t tmp = 1<<16 ; //1000000000000000
	//Set the LCKy
	tmp |= pinNum ; //if pin is 3 --> 1000000000001000

	//	Write 1
	GPIOx->LCKR = tmp ; //same operation
	//	Write 0
	GPIOx->LCKR = pinNum ; // write 0 to pin 16
	//	Write 1
	GPIOx->LCKR = tmp ;

	//	Read 0
	tmp = GPIOx->LCKR  ;
	//	Read 1 (this read is optional but confirms that the lock is active)
	if ((GPIOx->LCKR  & (1<<16) )) //just we read lock 16
	{
		return GPIO_Lock_Enabled ;
	}else
	{
		return GPIO_Lock_Error ;

	}
}
