/*
 * lcdsegment.c
 *
 *  Created on: 13-Apr-2021
 *      Author: alarkm
 */
#include "lcdsegment.h"


/* Setting up LCD Voltage Mode */
void SetLCDVoltageMode(LCD_VOLT lcd_voltage)
{
	LCD_CONFIG0->LCDMD &= (~LCD_LCDMD_MDSET_MASK);
	LCD_CONFIG0->LCDMD |= LCD_LCDMD_MDSET_VALUE(lcd_voltage);
}


/* Setting up LCD Display Mode */
void SetLCDDisplayMode(LCD_DISPLAY lcd_display_mode, LCD_MODE lcd_mode)
{
	LCD_CONFIG0->LCDM &= (~LCD_LCDM_LCDON_MASK);
	LCD_CONFIG0->LCDM &= (~LCD_LCDM_SCOC_MASK);
	LCD_CONFIG0->LCDM &= (~LCD_LCDM_MASK);

	LCD_CONFIG0->LCDM |= (lcd_display_mode & 0x02) ? LCD_LCDM_SCOC_MASK : 0;
	LCD_CONFIG0->LCDM |= (lcd_display_mode & 0x01) ? LCD_LCDM_LCDON_MASK : 0;
	LCD_CONFIG0->LCDM |= LCD_LCDM_VALUE(lcd_mode);
}


/* Setting up LCD clock source */
void SetLCDSourceClock(LCD_SRC_CLK lcd_source_clock)
{
	LCD_CONFIG0->LCDC0 &= (~LCD_LCDC0_MASK);
	LCD_CONFIG0->LCDC0 |= LCD_LCDC0_VALUE(lcd_source_clock);
}



/* Setting up LCD clock */
void SetLCDClock(LCD_CLK lcd_clock)
{
	LCD_CONFIG0->LCDC0 &= (~LCD_LCDC4_MASK);
	LCD_CONFIG0->LCDC0 |= LCD_LCDC4_VALUE(lcd_clock);
}


/* Initial LCD Display is all data */
void SetInitialLCDDisplay(void)
{
	uint8_t idx=0;
	for(idx=0; idx<MAX_SEGMENTS; ++idx)
	{
		uint8_t *data = (uint8_t *)(LCD_DATA_REGISTER_BASE + idx);
		*data = 0x0F;
	}
}
