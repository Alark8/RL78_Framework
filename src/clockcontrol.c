/*
 * clockcontrol.c
 *
 *  Created on: 17-Mar-2021
 *      Author: alarkm
 */

#include "clock.h"


/* Takes in the clock configuration structure and based on that does the configuration */
void ClockInitialize(CLK_Config *config)
{
	uint8_t pll_status=0;

	CLK_Reg clock_config_reg = {0, 0xC0, 0};				//By default this is the setting of the MCU

	SetupOscillator(config, &clock_config_reg);																				//Set the oscillator and its frequency

	CLOCK->CMC = clock_config_reg.cmc_reg;																					//Load the CMC Register of Clock

	config->ostc_value = SetOSTSRegister(config->osts_select);																//Prepare the OSTS and get the OSTC Register value

	CLOCK->CSC = clock_config_reg.csc_reg;																					//Load the CSC Register of Clock

	if(config->main_osc_type == X1_OSC)
		while(CLOCK->OSTC != config->ostc_value);																			//Wait till the oscillation(X1 only) becomes stable

	CLOCK->CKC = clock_config_reg.ckc_reg;																					//Update the CKC Register of Clock

	if(config->main_osc_type == X1_OSC)
	{
		while(!GetMainSystemClockStatus());																					//Wait for the MCS bit of CKC to be 1
		DisableOscillator(HIGH_SPEED_INT);																					//Stop the High Speed Oscillator
	}

	pll_status |= SetupPLL(config);																							//Setup PLL if desired

	SetCLMInterruptPriority(config->clm_interrupt_priority);																//Set the CLM interrupt priority
}



/* OSTC value is computed based on OSTS */
uint8_t CalculateOSTCValue(uint8_t osts_val)
{
	uint8_t ostc_value=128;

	while(osts_val--)
		ostc_value = (ostc_value >> 1) | 0x80;

	return ostc_value;
}



/* Set OSTS Register - Used for External Oscillator */
uint8_t SetOSTSRegister(uint8_t osts_value)
{
	uint8_t ostc_value=0;

	if(osts_value < 8)
	{
		CLOCK->OSTS &= (~CLOCK_OSTS_MASK);																						//Clear the OSTS Register
		CLOCK->OSTS |= CLOCK_OSTS_VALUE(osts_value);																			//Set the OSTS Register
		ostc_value = CalculateOSTCValue(osts_value);																			//Get the OSTC Register Value
	}
	else ostc_value=0;

	return ostc_value;
}
