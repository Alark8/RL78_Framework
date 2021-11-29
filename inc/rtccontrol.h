#ifndef RTCCONTROL_H
#define RTCCONTROL_H

#include "rtc.h"

#define MAX_SEC_MIN_VALUE										  59
#define MAX_DAY_VALUE											  31
#define MAX_HOUR_VALUE											  32
#define MAX_YEAR_VALUE											  99


#define NO_ERROR_RTC											0x00
#define RTC_DATE_OUT_OF_BOUND									0x01
#define RTC_CLOCK_SRC_OUT_OF_BOUND								0x02
#define RTC_CLOCK_SEL_OUT_OF_BOUND								0x04
#define RTC_INTERRUPT_OUT_OF_BOUND								0x08
#define RTC_1HZ_PIN_SEL_OUT_OF_BOUND							0x10
#define RTC_PRIORITY_OUT_OF_BOUND								0x20


uint8_t RTCSetAlarm(RTCAlarm_Data *palarmdata);
uint8_t RTCParamScanError(RTC_Config *pconfig, RTC_Data *pdata);
uint8_t RTCInitialize(RTC_Config *pconfig, RTC_Data *pdata, RTCAlarm_Data *palarmdata);

#endif
