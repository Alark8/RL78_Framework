#ifndef INTERVALTIMERCONFIG_H
#define INTERVALTIMERCONFIG_H

#include "rl78_d1a_head.h"

/* Interval Timer Clock Source
 * EXT -> External Osc
 * INT -> Internal Osc */
typedef enum {EXT, INT} CLK_SRC;

/* Interval Timer Clock Selection
 * SUBOSC -> Sub system oscillator
 * LOWSPEED_INT -> 15KHz clock
 * CLK_SRC_RES_7 -> Clock source divided by 2^7
 * CLK_SRC_BY_122 -> Clock source divided by 122
 * CLK_SRC_RES_8 -> Clock source divided by 2^8
 * CLK_SRC_BY_244 -> Clock source divided by 244 */
typedef enum {SUBOSC=0, LOWSPEED_INT=2, CLK_SRC_RES_7=4, CLK_SRC_BY_122=5, CLK_SRC_RES_8=6, CLK_SRC_BY_244=7} CLK_SEL;


/* Interval timer configuration structure */
typedef struct {
	CLK_SRC clock_source;
	CLK_SEL clock_selection;
	INT_PRIORITY timer_interval_interrupt_prior;						//Refer config.h
	uint16_t timer_ticks								:15;			//Calculated based on the clock frequency and time interval
	uint16_t reserve									:01;
}INTERVALTIMER_Config;


INTERVALTIMER_Config DefaultIntervalTimerSetting(void);					//Function which returns the interval timer configuration settings

#endif
