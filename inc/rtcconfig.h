#ifndef RTCCONFIG_H
#define RTCCONFIG_H

#include "rl78_d1a_head.h"
#include "intervaltimerconfig.h"

/* RTC 1Hz Output Pin Select
 * P64 -> P64 pin
 * P15 -> P15 pin
 * P94 -> P94 pin
 * NOTUSED*/
typedef enum {P64, P15, P94, NOTUSED} RTC1HZ_OUTPUT;

/* RTC Day enum */
typedef enum {SUN, MON, TUE, WED, THUR, FRI, SAT} DAY;

/* RTC 1Hz Timer Input Pin Select
 * TI06 -> Timer 0 Channel 6
 * TI07 -> Timer 0 Channel 7
 * TI16 -> Timer 1 Channel 16
 * TI17 -> Timer 1 Channel 17 */
typedef enum {TI06, TI07, TI16, TI17} RTC1HZ_TIMERINPUT;

/* RTC Month enum */
typedef enum {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} MONTH;

/* RTC Interrupt Setting
 * NO_INTR -> No Interrupt
 * INTR_HALFSEC -> Half second interrupt
 * INTR_1SEC -> 1 second interrupt
 * INTR_1MIN -> 1 minute interrupt
 * INTR_1HR -> 1 hour interrupt
 * INTR_1DAY -> 1 day interrupt
 * INTR_1MON -> 1 month interrupt */
typedef enum {NO_INTR, INTR_HALFSEC, INTR_1SEC, INTR_1MIN, INTR_1HR, INTR_1DAY, INTR_1MON} RTC_INTR;


/* RTC Time Data structure */
typedef struct {
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t week;
	uint8_t day;
	uint8_t month;
	uint8_t year;
}RTC_Data;


/* RTC Alarm Data structure */
typedef struct {
	uint8_t alarm_min;
	uint8_t alarm_hour;
	DAY *alarm_week;
	uint8_t number_of_week_days;
}RTCAlarm_Data;



/* RTC configuration structure */
typedef struct {
	CLK_SRC clock_src;
	CLK_SEL clock_select;
	RTC_INTR rtc_interrupt;
	RTC1HZ_OUTPUT rtc1hz_outpin;
	RTC1HZ_TIMERINPUT rtc1hz_timerip;
	INT_PRIORITY rtc_int_priority;
	uint8_t rtc1hz_output_enabled				:1;				//True or False
	uint8_t format_24hour_enabled				:1;				//True or False
	uint8_t start_rtc							:1;				//True or False
	uint8_t reserve								:5;
	uint8_t subcud;												//Not used in this driver
	uint16_t subcudw;											//Not used in this driver
}RTC_Config;


RTC_Data DefaultRTCTime(void);						//Function to return the default RTC time setting
RTC_Config DefaultRTCSetting(void);					//Function to return the default RTC configuration setting

#endif
