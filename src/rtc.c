/*
 * rtc.c
 *
 *  Created on: 24-Mar-2021
 *      Author: alarkm
 */

#include "rtc.h"


/* Initialize the RTC as per the configuration passed */
void RTCInit(RTC_Config *pconfig)
{
	RTCClockInit();			//Initialize the RTC Clock

	if(pconfig->clock_src) RTCCL |= (1 << RTC_RTCCL_RTCCL7_SHIFT);				//Selecting the clock source (INT or EXT) for RTC, same as Interval Timer
	else RTCCL &= ~(1 << RTC_RTCCL_RTCCL7_SHIFT);

	RTCWriteClockOpt(pconfig->clock_select);								//Selecting the clock speed for RTC

	RTC->SUBCUD = pconfig->subcud;						//Load the subcud register

	if(pconfig->rtc1hz_output_enabled)										//If 1Hz output is enabled
	{
		RTCSEL |= RTCSEL_RTCOSEL_VALUE(pconfig->rtc1hz_outpin);				//Selecting the output pin
		SetRTC1HZTimerInputChannel(pconfig->rtc1hz_timerip);				//Selecting the timer input channel
		RTC1HZOutputEnable();									//Output enable
	}
	else RTC1HZOutputDisable();				//Output disable

	if(pconfig->format_24hour_enabled) RTC->RTCC0 |= (1 << RTC_RTCC0_AMPM_SHIFT);			//24 hour format
	RTC->RTCC0 &= ~(1 << RTC_RTCC0_AMPM_SHIFT);			//12 hour format

	RTC->RTCC0 |= RTC_RTCC0_CT_VALUE(pconfig->rtc_interrupt);					//RTC Interrupt setting

	SUBCUDW = pconfig->subcudw;					//Load subcudw register
}



/* Selecting the clock for RTC Operation */
void RTCWriteClockOpt(CLK_SEL selection)
{
	if(selection & 0x01) RTCCL |= (1 << RTC_RTCCL_RTCCL6_SHIFT);
	else RTCCL &= ~(1 << RTC_RTCCL_RTCCL6_SHIFT);

	RTCCL &= (~RTC_RTCCL_RTCCKS_MASK);
	RTCCL |= RTC_RTCCL_RTCCKS_VALUE(selection>>1);
}



/* Write the Date Time into RTC Module */
void RTCWriteDateTime(RTC_Data *pdata)
{
	RTC->RTCC1 |= (1 << RTC_RTCC1_RWAIT_SHIFT);
	while(!GetRTCWaitStatus());

	RTC->SEC = DEC_TO_BCD(pdata->sec);
	RTC->MIN = DEC_TO_BCD(pdata->min);
	RTC->HOUR = DEC_TO_BCD(pdata->hour);
	RTC->WEEK = DEC_TO_BCD(pdata->week);
	RTC->DAY = DEC_TO_BCD(pdata->day);
	RTC->MONTH = DEC_TO_BCD(pdata->month);
	RTC->YEAR = DEC_TO_BCD(pdata->year);

	RTC->RTCC1 &= ~(1 << RTC_RTCC1_RWAIT_SHIFT);
	while(GetRTCWaitStatus());
}



/* Read the date time from RTC module */
void RTCReadDateTime(RTC_Data *pdata)
{
	RTC->RTCC1 |= (1 << RTC_RTCC1_RWAIT_SHIFT);
	while(!GetRTCWaitStatus());

	pdata->sec = BCD_TO_DEC(RTC->SEC);
	pdata->min = BCD_TO_DEC(RTC->MIN);
	pdata->hour = BCD_TO_DEC(RTC->HOUR);
	pdata->week = BCD_TO_DEC(RTC->WEEK);
	pdata->day = BCD_TO_DEC(RTC->DAY);
	pdata->month = BCD_TO_DEC(RTC->MONTH);
	pdata->year = BCD_TO_DEC(RTC->YEAR);

	RTC->RTCC1 &= ~(1 << RTC_RTCC1_RWAIT_SHIFT);
	while(GetRTCWaitStatus());
}



/* Set RTC interrupt priority */
void SetRTCInterruptPriority(uint8_t priority)
{
	PR00->PR &= (~INT_PR00_RTCPR0_MASK);
	PR10->PR &= (~INT_PR10_RTCPR1_MASK);
	PR00->PR |= (priority & 0x01) ? INT_PR00_RTCPR0_MASK : 0;											//Set the priority bit 0
	PR10->PR |= (priority & 0x02) ? INT_PR10_RTCPR1_MASK : 0;											//Set the priority bit 1
	//MK0->MK &= (~INT_MK0_RTCMK_MASK);																	//Enable the interrupt
}



/* Setting the RTC Alarm Minute Register */
void SetRTCAlarmMinute(uint8_t value)
{
	RTC->ALARMWM = DEC_TO_BCD(value);
}



/* Setting the RTC Alarm Hour Register */
void SetRTCAlarmHour(uint8_t value)
{
	RTC->ALARMWH = DEC_TO_BCD(value);
}



/* Setting the RTC Alarm Week Register */
void SetRTCAlarmWeek(uint8_t value)
{
	RTC->ALARMWW = value;
}




/* Enable the RTC Alarm Detection status flag */
uint8_t GetRTCAlarmDetectionStatus(void)
{
	return (RTC->RTCC1 & RTC_RTCC1_WAFG_MASK);
}



/* Disable the RTC Alarm Detection status flag */
void ClearRTCAlarmDetectionFlag(void)
{
	RTC->RTCC1 &= ~(1 << RTC_RTCC1_WAFG_SHIFT);
}



/* Get the RTC Constant Period Interrupt status flag */
uint8_t GetRTCConstantPeriodInterruptStatus(void)
{
	return (RTC->RTCC1 & RTC_RTCC1_RIFG_MASK);
}



/* Clear the RTC Constant Period Interrupt status flag */
void ClearRTCConstantPeriodInterruptStatus(void)
{
	RTC->RTCC1 &= ~(1 << RTC_RTCC1_RIFG_MASK);
}



/* Get RTC Wait Status */
uint8_t GetRTCWaitStatus(void)
{
	return (RTC->RTCC1 & RTC_RTCC1_RWST_MASK);
}



/* Enable RTC Alarm Match Operation */
void SetRTCAlarmMatchOperation(void)
{
	RTC->RTCC1 |= (1 << RTC_RTCC1_WALE_SHIFT);
}



/* Disable RTC Alarm Match Operation */
void ClearRTCAlarmMatchOperation(void)
{
	RTC->RTCC1 &= ~(1 << RTC_RTCC1_WALE_SHIFT);
}



/* Enable RTC 1Hz Output */
void RTC1HZOutputEnable(void)
{
	RTC->RTCC0 |= (1 << RTC_RTCC0_RCLOE1_SHIFT);
}


/* Disable RTC 1Hz Output */
void RTC1HZOutputDisable(void)
{
	RTC->RTCC0 &= ~(1 << RTC_RTCC0_RCLOE1_SHIFT);
}



/* Set RTC 1Hz Timer Input Channel */
void SetRTC1HZTimerInputChannel(RTC1HZ_TIMERINPUT selection)
{
	RTCSEL |= (selection < 4) ? (1 << selection) : 0;
}


/* Set RTC Alarm Interrupt */
void SetRTCAlarmInterrupt(void)
{
	RTC->RTCC1 |= (1 << RTC_RTCC1_WALIE_SHIFT);
}



/* Clear RTC Alarm Interrupt */
void ClearRTCAlarmInterrupt(void)
{
	RTC->RTCC1 &= ~(1 << RTC_RTCC1_WALIE_SHIFT);
}



/* Start the RTC */
void RTCStart(void)
{
	RTC->RTCC0 |= (1 << RTC_RTCC0_RTCE_SHIFT);
}



/* Stop the RTC */
void RTCStop(void)
{
	RTC->RTCC0 &= ~(1 << RTC_RTCC0_RTCE_SHIFT);
}


/* RTC Clock Initialization */
void RTCClockInit(void)
{
	PER0 |= (1 << PER0_RTCEN_SHIFT);
}


/* RTC Clock De-Initialization */
void RTCClockDeInit(void)
{
	PER0 &= ~(1 << PER0_RTCEN_SHIFT);
}
