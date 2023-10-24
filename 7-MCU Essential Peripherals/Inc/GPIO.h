/*
 * GPIO.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mega Store
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f103c8xx.h"

//===================================
/*    Configurations Structure     */
//===================================

typedef struct {
	uint16_t GPIO_pinNum;		// Specifies the GPIO pins to be configured.
	// This parameter must be set based on @ref GPIO_PINS_define

	uint8_t GPIO_pinConfg;		// Specifies the GPIO pin configuration
	// This parameter must be set based on @ref GPIO_PIN_Configurations

	uint8_t GPIO_MaxOutSpeed;	// Specifies the GPIO pin Maximum frequency
	// This parameter must be set based on @ref GPIO_PIN_Speed

}GPIO_PIN_CONFG_t;

//@ref GPIO_PINS_define
#define GPIO_PIN_0                 ((uint16_t)0x0000)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0001)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0002)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0003)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0004)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0005)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0006)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0007)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0008)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0009)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x000A)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x000B)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x000C)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x000D)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x000E)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x000F)  /* Pin 15 selected   */

//#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
//#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected  10  */
//#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected  100  */
//#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected  1000  */
//#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected  10000  */
//#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
//#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
//#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
//#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
//#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
//#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
//#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
//#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
//#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
//#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
//#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */
/*We can avoid shifting operation by setting hex values with the corresponding pin position*/
/* Also we can write a get_pos() function to allocate this pin from the CRL & CRH*/

#define GPIO_PIN_MASK              0x0000FFFFu /* PIN mask for assert test */

//@ref GPIO_PIN_Configurations
#define GPIO_OUT_push_pull					0x00000000u
#define GPIO_OUT_open_drain					0x00000001u
#define GPIO_OUT_AF_Push_pull				0x00000002u
#define GPIO_OUT_AF_open_drain				0x00000003u
#define GPIO_IN_analog						0x00000004u //x - 4
#define GPIO_IN_floating					0x00000005u //x - 4
#define GPIO_IN_pull_down					0x00000006u //x - 4
#define GPIO_IN_pull_up						0x00000007u //x - 4

//@ref GPIO_PIN_Speed

#define GPIO_MAX_OUT_Speed_10M				0x00000001u
#define GPIO_MAX_OUT_Speed_2M				0x00000002u
#define GPIO_MAX_OUT_Speed_50M				0x00000003u

//GPIO Lock return
#define GPIO_Lock_Enabled				0x00000000u
#define GPIO_Lock_Error					0x00000001u

// GPIO Values
#define GPIO_Write_Pin_LOW				0x00000000u
#define GPIO_Write_Pin_HIGH				0x00000001u
#define GPIO_Write_Poert_LOW			0x00000000u
#define GPIO_Write_Port_HIGH			0x000000ffu
//No need for configuration or gpio_init() as by default all pins are output floating

//=================
/*    APIs     */
//=================
void 	 GPIO_init(GPIO_TypeDef* GPIOx,GPIO_PIN_CONFG_t* pinConfig);
void 	 GPIO_reset(GPIO_TypeDef* GPIOx);
uint8_t  GPIO_read_pin(GPIO_TypeDef* GPIOx, uint8_t pinNum);
uint16_t GPIO_read_port(GPIO_TypeDef* GPIOx);
void 	 GPIO_write_pin(GPIO_TypeDef* GPIOx, uint8_t pinNum, uint8_t value); //@ref GPIO Values
void 	 GPIO_write_port(GPIO_TypeDef* GPIOx, uint16_t value);				  //@ref GPIO Values
void 	 GPIO_toggle_pin(GPIO_TypeDef* GPIOx, uint8_t pinNum);
uint8_t  GPIO_lock_pin(GPIO_TypeDef* GPIOx, uint8_t pinNum);			 //@ref //GPIO Lock return


#endif /* INC_GPIO_H_ */




/*Pseudo code
 *
 * MAIN:
 * GPIO_PIN_CONFG_t* pinConfg;
 * pinConfg->GPIO_MaxOutSpeed = MAX_OUT_Speed_50M;
 * pinConfig->GPIO_pinConfg = OUT_push_pull;
 * pinConfig->GPIO_pinNum = GPIO_PIN_3;
 * GPIO_init(GPIOA, pinConfig)
 *
 * DRIVER:
 * void GPIO_init(GPIO_TypeDef* GPIOx,GPIO_PIN_CONFG_t* pinConfig){
 * if (pinconfg->GPIO_pinNum > 8){
 *
 *
 * GPIOx->CRL |= (pinConfig->GPIO_pinConfg << pinconfg->GPIO_pinNum * 4 + 1)
 * if pinconfg->GPIO_pinConfg > 4
 *  * GPIOx->CRL &= ~(0b11 << pinconfg->GPIO_pinNum * 4 - 1)
 *  else
 *  * GPIOx->CRL |= (pinConfig->GPIO_MaxOutSpeed << pinconfg->GPIO_pinNum * 4 - 1)
 *
 * }else{
 *
 *
 * }
 *
 *
 * */
