/*
 * lcdsegmentconfig.c
 *
 *  Created on: 05-May-2021
 *      Author: alarkm
 */

#include "lcdsegmentconfig.h"

/* To understand this numbering please read gpio.h and these are the GPIOs that are used for LCD Segments */
uint8_t lcd_pinout[] = {2,3,4,5,6,7,9,11,14,24,25,26,27,28,29,30,31,40,41,42,43,44,45,46,
						47,58,59,60,61,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,110};							//Numbers correspond to pin number from gpio.h


/* Function that return the LCD configuration setting structure */
LCD_Config DefaultLCDSetting(void)
{
	LCD_Config config;

	config.lcd_voltage = INT_RESISTOR_NO_STEPDOWN;
	config.lcd_display_mode = DISPLAY_ON;
	config.lcd_mode = SLICES_4;
	config.lcd_source_clock = DIVIDE_BY_2PWR10;
	config.lcd_clock = DIV_BY_2PWR9;
	config.number_of_pins = sizeof(lcd_pinout);
	config.lcd_pinout = lcd_pinout;

	return config;
}
