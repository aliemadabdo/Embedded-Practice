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

#include "driver.h"

int threshold = 20;
int pressure = 0;

enum alarm_state{
	OFF, ON
};

int main (){
	GPIO_INITIALIZATION();
	Set_Alarm_actuator(OFF);

	while (1)
	{	pressure = getPressureVal();
		if (pressure > threshold){
			Set_Alarm_actuator(ON);
			Delay(6000);
			Set_Alarm_actuator(OFF);
		}
	}
}
