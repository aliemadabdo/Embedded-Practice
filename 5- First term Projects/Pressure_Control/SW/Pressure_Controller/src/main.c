/*
 ============================================================================
 Name        : main.c
 Author      : Ali Emad
 Version     : V1
 Copyright   : Your copyright notice
 Description : Pressure Controller with full system design
 ============================================================================
 */

#include <stdint.h>
#include <stdio.h>

#include "driver/driver.h"

int main (){
	GPIO_INITIALIZATION();
	Set_Alarm_actuator(0);

	while (1)
	{
		if (getPressureVal() > 20){
			Set_Alarm_actuator(1);
			Delay(6000);
			Set_Alarm_actuator(0);
		}
	}
}
