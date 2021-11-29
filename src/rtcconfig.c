/*
 * rtcconfig.c
 *
 *  Created on: 05-May-2021
 *      Author: alarkm
 */

#include "rtcconfig.h"

/* Default RTC configuration which can be retrieved by this function call */
RTC_Config DefaultRTCSetting(void)
{
	RTC_Config config = {(0)};

	config.subcud = 0;
	config.subcudw = 0;
	config.clock_src = EXT;
	config.rtc_interrupt = NO_INTR;
	config.clock_select = CLK_SRC_BY_122;
	config.rtc1hz_output_enabled = FALSE;
	config.format_24hour_enabled = FALSE;
	config.rtc_int_priority = LVL3;

	return config;
}


/* Set the default RTC time which can be retrieved by this function call */
RTC_Data DefaultRTCTime(void)
{
	RTC_Data data = {(0)};

	data.sec = 0;
	data.min = 10;
	data.hour = 3;
	data.week = (uint8_t)MON;
	data.day = 24;
	data.month = (uint8_t)APR;
	data.year = 21;

	return data;
}
