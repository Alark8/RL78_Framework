#ifndef LCDSEGMENTCONFIG_H
#define LCDSEGMENTCONFIG_H

#include "rl78_d1a_head.h"

#define MAX_SEGMENTS											0x35			//Relative to project

/* LCD Volt Selection, read data sheet for more info
 * PWR_SAVE
 * INT_RESISTOR_NO_STEPDOWN
 * INT_RESISTOR_STEPDOWN */
typedef enum {PWR_SAVE, INT_RESISTOR_NO_STEPDOWN, INT_RESISTOR_STEPDOWN=3} LCD_VOLT;

/* LCD Display selection, read data sheet for more info
 * OUTPUT_GND
 * DISPLAY_OFF
 * DISPLAY_ON */
typedef enum {OUTPUT_GND, DISPLAY_OFF=2, DISPLAY_ON} LCD_DISPLAY;

/* LCD_MODE selection options
 * SLICES_4 -> 4 COM configuration
 * SLICES_3 -> 3 COM configuration
 * STATIC -> Solid configuration */
typedef enum {SLICES_4, SLICES_3, STATIC=4} LCD_MODE;

/* LCD_SRC_CLK selection options
 * SUBOSC_XT -> Sub system oscillator
 * DIVIDE_BY_2PWR5 -> Main clock/(2^5)
 * DIVIDE_BY_2PWR6 -> Main clock/(2^6)
 * DIVIDE_BY_2PWR7 -> Main clock/(2^7)
 * DIVIDE_BY_2PWR8 -> Main clock/(2^8)
 * DIVIDE_BY_2PWR9 -> Main clock/(2^9)
 * DIVIDE_BY_2PWR10 -> Main clock/(2^10)
 * DIVIDE_BY_2PWR11 -> Main clock/(2^11)
 * LOWSPEED -> 15KHz */
typedef enum {SUBOSC_XT, DIVIDE_BY_2PWR5, DIVIDE_BY_2PWR6, DIVIDE_BY_2PWR7, DIVIDE_BY_2PWR8, DIVIDE_BY_2PWR9, DIVIDE_BY_2PWR10, LOWSPEED} LCD_SRC_CLK;


/* LCD Clock selection options
 * DIV_BY_2PWR4 -> LCD_SRC_CLK/(2^4)
 * DIV_BY_2PWR5 -> LCD_SRC_CLK/(2^5)
 * DIV_BY_2PWR6 -> LCD_SRC_CLK/(2^6)
 * DIV_BY_2PWR7 -> LCD_SRC_CLK/(2^7)
 * DIV_BY_2PWR8 -> LCD_SRC_CLK/(2^8)
 * DIV_BY_2PWR9 -> LCD_SRC_CLK/(2^9) */
typedef enum {DIV_BY_2PWR4, DIV_BY_2PWR5, DIV_BY_2PWR6, DIV_BY_2PWR7, DIV_BY_2PWR8, DIV_BY_2PWR9} LCD_CLK;


/* LCD Configuration setting structure */
typedef struct {
	LCD_VOLT lcd_voltage;
	LCD_DISPLAY lcd_display_mode;
	LCD_MODE lcd_mode;
	LCD_SRC_CLK lcd_source_clock;
	LCD_CLK lcd_clock;
	uint8_t number_of_pins;
	uint8_t *lcd_pinout;
}LCD_Config;


LCD_Config DefaultLCDSetting(void);

#endif
