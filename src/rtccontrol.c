/*
 * rtc_control.c
 *
 *  Created on: 24-Mar-2021
 *      Author: alarkm
 */

#include "rtccontrol.h"


/* Takes up the RTC configuration structure and initializes it accordingly, also writes the time and alarm data into respective registers */
uint8_t RTCInitialize(RTC_Config *pconfig, RTC_Data *pdata, RTCAlarm_Data *palarmdata)
{
	uint8_t error=RTCParamScanError(pconfig, pdata);				//Validation of arguments passed in the configuration structure
	if(error) return error;

	RTCInit(pconfig);						//Initialize the RTC

	RTCWriteDateTime(pdata);				//Write the Date Time into RTC module

	RTCSetAlarm(palarmdata);				//Write the Alarm data into RTC module

	SetRTCInterruptPriority(pconfig->rtc_int_priority);			//Set the RTC interrupt priority

	RTCStart();				//Start the RTC

	return error;
}



/* Validate various parameters passed for RTC Initialization */
uint8_t RTCParamScanError(RTC_Config *pconfig, RTC_Data *pdata)
{
	uint8_t error=NO_ERROR_RTC;

	if(pdata->sec > MAX_SEC_MIN_VALUE || pdata->min > MAX_SEC_MIN_VALUE || pdata->hour > MAX_HOUR_VALUE || pdata->week > (uint8_t)SAT
			|| pdata->day > MAX_DAY_VALUE || pdata->month > (uint8_t)DEC || pdata->year > MAX_YEAR_VALUE)
			return RTC_DATE_OUT_OF_BOUND;																//Validating the time passed


	/* Validating various params */
	if(pconfig->clock_src > INT) error |= RTC_CLOCK_SRC_OUT_OF_BOUND;
	if(pconfig->rtc_interrupt > INTR_1MON) error |= RTC_INTERRUPT_OUT_OF_BOUND;
	if(pconfig->rtc1hz_timerip > TI17) error |= RTC_1HZ_PIN_SEL_OUT_OF_BOUND;
	if(pconfig->rtc1hz_outpin > NOTUSED) error |= RTC_1HZ_PIN_SEL_OUT_OF_BOUND;
	if(pconfig->rtc_int_priority > LVL3) error |= RTC_PRIORITY_OUT_OF_BOUND;
	if(pconfig->clock_select > CLK_SRC_BY_244) error |= RTC_CLOCK_SEL_OUT_OF_BOUND;

	switch((uint8_t)pconfig->clock_select)
	{
	case 1:
	case 3:
		error |= RTC_CLOCK_SEL_OUT_OF_BOUND;
		break;

	default: break;
	}

	return error;
}


/* Write the Alarm Data into the RTC module using this API */
uint8_t RTCSetAlarm(RTCAlarm_Data *palarmdata)
{
	uint8_t week_value=0, error=0, idx=0;

	if(palarmdata->alarm_min > MAX_SEC_MIN_VALUE || palarmdata->alarm_hour > MAX_HOUR_VALUE) error |= RTC_DATE_OUT_OF_BOUND;			//Validating the values of alarm data

	for(idx=0; idx < palarmdata->number_of_week_days; ++idx)
	{
		if(palarmdata->alarm_week[idx] > SAT) error |= RTC_DATE_OUT_OF_BOUND;
		week_value |= (1 << (uint8_t)palarmdata->alarm_week[idx]);							//Getting the week data for setting up alarm
	}

	if(error) return error;

	ClearRTCAlarmMatchOperation();							//Clear the RTC Match Operation flag
	SetRTCAlarmInterrupt();									//Enable the RTC Alarm Interrupt
	SetRTCAlarmMinute(palarmdata->alarm_min);				//Set the Alarm Minute data
	SetRTCAlarmHour(palarmdata->alarm_hour);				//Set the Alarm Hour data
	SetRTCAlarmWeek(week_value);							//Set the Alarm week data
	SetRTCAlarmMatchOperation();							//Enable the Alarm Match operation

	return error;
}


