#ifndef RTC_H
#define RTC_H

#include "rtcconfig.h"
#include "intervaltimer.h"

#define BCD_TO_DEC(x)						((x/16 * 10) + (x % 16))
#define DEC_TO_BCD(x)						((x/10 * 16) + (x % 10))

#pragma inline(RTCStop)
#pragma inline(RTCStart)
#pragma inline(RTCClockInit)
#pragma inline(RTCClockDeInit)
#pragma inline(GetRTCWaitStatus)
#pragma inline(RTC1HZOutputEnable)
#pragma inline(RTC1HZOutputDisable)
#pragma inline(SetRTCAlarmInterrupt)
#pragma inline(ClearRTCAlarmInterrupt)
#pragma inline(SetRTCAlarmMatchOperation)
#pragma inline(GetRTCAlarmDetectionStatus)
#pragma inline(ClearRTCAlarmDetectionFlag)
#pragma inline(SetRTC1HZTimerInputChannel)
#pragma inline(ClearRTCAlarmMatchOperation)
#pragma inline(GetRTCConstantPeriodInterruptStatus)
#pragma inline(ClearRTCConstantPeriodInterruptStatus)


void RTCStop(void);
void RTCStart(void);
void RTCClockInit(void);
void RTCClockDeInit(void);
void RTC1HZOutputEnable(void);
void RTC1HZOutputDisable(void);
void SetRTCAlarmInterrupt(void);
void RTCInit(RTC_Config *pconfig);
void ClearRTCAlarmInterrupt(void);
void SetRTCAlarmHour(uint8_t value);
void SetRTCAlarmWeek(uint8_t value);
void SetRTCAlarmMatchOperation(void);
void SetRTCAlarmMinute(uint8_t value);
void ClearRTCAlarmDetectionFlag(void);
void ClearRTCAlarmMatchOperation(void);
void RTCWriteDateTime(RTC_Data *pdata);
void RTCWriteClockOpt(CLK_SEL selection);
void SetRTCInterruptPriority(uint8_t priority);
void ClearRTCConstantPeriodInterruptStatus(void);
void SetRTC1HZTimerInputChannel(RTC1HZ_TIMERINPUT selection);


uint8_t GetRTCWaitStatus(void);
uint8_t GetRTCAlarmDetectionStatus(void);
uint8_t GetRTCConstantPeriodInterruptStatus(void);

#endif
