/*
 * interruptconfig.c
 *
 *  Created on: 05-May-2021
 *      Author: alarkm
 */


#include "interruptconfig.h"

/* Add the interrupts you want to enable here */
uint8_t interrupts_to_enable[] = {INTERVAL_TIMER_IRQn};											//Can add multiple IRQn to this array


/* Function to return the interrupt configuration setting */
INTERRUPT_Config DefaultInterruptSetting(void)
{
	INTERRUPT_Config config;

	config.interrupts = interrupts_to_enable;
	config.number_of_interrupts = sizeof(interrupts_to_enable);

	return config;
}
