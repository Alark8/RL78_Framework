/*
 * lcdsegmentcontrol.c
 *
 *  Created on: 13-Apr-2021
 *      Author: alarkm
 */

#include "lcdsegmentcontrol.h"


/* Takes in LCD configuration structure and initializes the LCD module accordingly */
uint8_t LCDInitialize(LCD_Config *pconfig)
{
	uint8_t error=LCDParamScanError(pconfig);				//Validation check of the parameters
	if(error) return error;

	LCDPortInitialize(pconfig->lcd_pinout, pconfig->number_of_pins);		//Initialize the LCD Port pin-out
	SetLCDVoltageMode(pconfig->lcd_voltage);								//Voltage mode setting
	SetLCDDisplayMode(pconfig->lcd_display_mode, pconfig->lcd_mode);		//Display mode setting
	SetLCDSourceClock(pconfig->lcd_source_clock);							//LCD source clock setting
	SetLCDClock(pconfig->lcd_clock);										//LCD clock setting

//	SetInitialLCDDisplay();													//Turns ON all the segments

	return error;
}


/* Initialize the LCD Port  */
uint8_t LCDPortInitialize(uint8_t *pin_numbers, uint8_t length)
{
	uint8_t idx=0,error=NO_ERROR_LCD;

	for(idx=0; idx<MAX_SEGMENTS; ++idx)
	{
		if(pin_numbers[idx] > MAX_LCD_PIN_NUMBER) return LCD_PIN_NUMBER_OUT_OF_BOUND;				//Validation of GPIO Number for LCD

		uint8_t pin=0;
		uint16_t base=0;

		base += ((pin_numbers[idx] >> DIVISION_BY_8) + LCD_PORT_FUNCTION_REGISTER_BASE);			//Get the port base
		pin = (pin_numbers[idx] & MODULUS_BY_8);													//Get the pin number

		*(uint8_t *)base |= (1 << pin);																//Setting the respective pin
	}
	return error;
}



/* Validation of arguments used in LCD Configuration structure */
uint8_t LCDParamScanError(LCD_Config *pconfig)
{
	uint8_t error=NO_ERROR_LCD;

	if(pconfig->lcd_voltage == 2 || pconfig->lcd_voltage > INT_RESISTOR_STEPDOWN) error |= LCD_VOLT_OUT_OF_BOUND;
	if(pconfig->lcd_display_mode == 1 || pconfig->lcd_display_mode > DISPLAY_ON) error |= LCD_DISPLAY_OUT_OF_BOUND;
	if(pconfig->lcd_mode == 2 || pconfig->lcd_mode == 3 || pconfig->lcd_mode > STATIC) error |= LCD_MODE_OUT_OF_BOUND;
	if(pconfig->lcd_source_clock > LOWSPEED) error |= LCD_SRC_CLK_OUT_OF_BOUND;
	if(pconfig->lcd_clock > DIV_BY_2PWR9) error |= LCD_CLK_OUT_OF_BOUND;

	return error;
}
