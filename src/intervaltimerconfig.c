/*
 * intervaltimerconfig.c
 *
 *  Created on: 05-May-2021
 *      Author: alarkm
 */


#include "intervaltimerconfig.h"

/* Function to return interval timer configuration settings */
INTERVALTIMER_Config DefaultIntervalTimerSetting(void)
{
	INTERVALTIMER_Config config = {(0)};

	config.clock_source = INT;
	config.clock_selection = CLK_SRC_BY_122;
	config.timer_ticks = 33;																		//For 1ms, count is 33 . (Clock = 4MHz), Relative Clock = 4000000/122. For 1ms, counts = 33
	config.timer_interval_interrupt_prior = LVL0;

	return config;
}
