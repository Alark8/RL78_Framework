#ifndef LCDSEGMENTCONTROL_H
#define LCDSEGMENTCONTROL_H

#include "lcdsegment.h"

#define DIVISION_BY_8								0x03
#define MODULUS_BY_8								0x07
#define MAX_LCD_PIN_NUMBER							0x6E						//Max is P136 which is 110 (0x6E) according to gpio.h


#define NO_ERROR_LCD								0x00
#define LCD_VOLT_OUT_OF_BOUND						0x01
#define LCD_DISPLAY_OUT_OF_BOUND					0x02
#define LCD_MODE_OUT_OF_BOUND						0x04
#define LCD_SRC_CLK_OUT_OF_BOUND					0x08
#define LCD_CLK_OUT_OF_BOUND						0x10
#define LCD_PIN_NUMBER_OUT_OF_BOUND					0x20

uint8_t LCDInitialize(LCD_Config *pconfig);
uint8_t LCDParamScanError(LCD_Config *pconfig);
uint8_t LCDPortInitialize(uint8_t *pin_numbers, uint8_t length);

#endif
