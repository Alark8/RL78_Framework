#ifndef INTERVALTIMER_H
#define INTERVALTIMER_H

#include "intervaltimerconfig.h"


#define NO_ERROR_INTERVAL_TIMER							0x00
#define IT_CLOCK_SEL_OUT_OF_BOUND						0x01
#define IT_CLOCK_SRC_OUT_OF_BOUND						0x02
#define IT_INTERRUPT_PRIORITY_OUT_OF_BOUND				0x04

#define MSTICKS_SPILL_VALUE						   268435456

#pragma inline(IntervalTimerStop)
#pragma inline(IntervalTimerStart)
#pragma inline(IntervalTimerClockInit)
#pragma inline(IntervalTimerClockDeInit)

#pragma interrupt IntervalTimerInterruptHandler(vect=INTERVAL_TIMER_VECTOR_ADDRESS)


void IntervalTimerStop(void);
void IntervalTimerStart(void);
void IntervalTimerClockInit(void);
void IntervalTimerClockDeInit(void);
void IntervalTimerWriteClockOpt(CLK_SEL selection);
void SetIntervalTimerInterruptPriority(uint8_t priority);

uint8_t IntervalTimerInitialize(INTERVALTIMER_Config *pconfig);
uint8_t IntervalTimerParamScanError(INTERVALTIMER_Config *pconfig);

uint32_t ElapsedTimeDuration(uint32_t reference_time);

#endif
