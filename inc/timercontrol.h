#ifndef TIMERCONTROL_H
#define TIMERCONTROL_H

#include "timer.h"

#define MAX_TIMER_CHANNELS_IN_TAU											0x07


#define NO_ERROR_TIMER														0x00
#define TIMER_CLOCK_OUT_OF_BOUND											0x01
#define TIMER_TIMN_IN_OUT_OF_BOUND											0x02
#define TIMER_TRG_OPT_OUT_OF_BOUND											0x04
#define TIMER_TMR_OPT_OUT_OF_BOUND											0x08
#define TIMER_PRIOR_OUT_OF_BOUND											0x10


typedef struct {
	uint8_t clock_timer_bit;
	uint16_t tmr_address;
	uint16_t tis_address;
	uint16_t tos_address;
	NoiseFilter_Config_Type *noisefilter;
}TIMERPARAMS;


void GetTimerRelatedParams(TIMER_Type *ptimer, TIMERPARAMS *ptimer_info);

uint8_t TimerParamScanError(TIMER_Config *pconfig);
uint8_t TimerInitialize(TIMER_Type *ptimer, TIMER_Config *pconfig);
uint8_t SetTimerInterruptPriority(TIMER_Type *ptimer, uint8_t timer_channel, uint8_t priority);

#endif
