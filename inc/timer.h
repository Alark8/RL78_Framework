#ifndef TIMER_H
#define TIMER_H

#include "timerconfig.h"

#pragma inline(TimerStop)
#pragma inline(TimerStart)
#pragma inline(TimerClockInit)
#pragma inline(TimerClockDeInit)
#pragma inline(GetTimerEnableStatus)

void TimerStop(TIMER_Type *ptimer, uint8_t channel);
void TimerStart(TIMER_Type *ptimer, uint8_t channel);
void SetTAU0Priority(uint8_t channel, uint8_t priority);
void SetTAU1Priority(uint8_t channel, uint8_t priority);
void SetTAU2Priority(uint8_t channel, uint8_t priority);
void TimerClockInit(TIMER_Type *ptimer, uint8_t clock_timer_bit);
void TimerClockDeInit(TIMER_Type *ptimer, uint8_t clock_timer_bit);
void SetTimerArrayClock(TIMER_Type *ptimer, CLK_OPT clock_opt, uint8_t value);
void SetTimerModeRegister(uint16_t tmr_address, TMRChannel_Config *tmrconfig);
void TimerInit(TIMER_Type *ptimer, TIMER_Config *pconfig, NoiseFilter_Config_Type *noisefilter);
void SetTimerNoiseFilterClock(NoiseFilter_Config_Type *pnoiseconfig, uint8_t nible, uint8_t value);
void TimerInputPinSelect(TIMER_Type *ptimer, uint16_t tis_address, uint8_t bit_shift, uint8_t selection);
void TimerOutputPinSelect(TIMER_Type *ptimer, uint16_t tos_address, uint8_t bit_shift, uint8_t selection);
void TimerArrayInit(TIMER_Type *ptimer, uint8_t channel, TMRChannel_Config *pconfig, NoiseFilter_Config_Type *noisefilter);

uint8_t GetTimerEnableStatus(TIMER_Type *ptimer, uint8_t channel);

#endif
