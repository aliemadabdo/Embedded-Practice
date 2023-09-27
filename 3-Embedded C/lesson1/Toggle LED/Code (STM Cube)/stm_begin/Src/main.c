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

//Example to check optimization in compiler levels

#include <stdio.h>
int main(void)
{
	volatile uint8_t data1;
	volatile uint8_t data2;

	data1 = 50;
	data2 = data1;
	data2 = data1;

    /* Loop forever */
	for(;;);
	//inside the loop the compiler of level 3 will delete
	// (without volatile) data1 and data2 as they are not used
}