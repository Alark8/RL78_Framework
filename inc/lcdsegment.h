#ifndef LCDSEGMENT_H
#define LCDSEGMENT_H


#include "lcdsegmentconfig.h"


void SetInitialLCDDisplay(void);
void SetLCDClock(LCD_CLK lcd_clock);
void SetLCDVoltageMode(LCD_VOLT lcd_voltage);
void SetLCDSourceClock(LCD_SRC_CLK lcd_source_clock);
void SetLCDDisplayMode(LCD_DISPLAY lcd_display_mode, LCD_MODE lcd_mode);


#endif
