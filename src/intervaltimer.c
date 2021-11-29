/*
 * intervaltimer.c
 *
 *  Created on: 25-Mar-2021
 *      Author: alarkm
 */


#include "intervaltimer.h"

volatile uint32_t msTicks=0;


/* API takes in interval timer configuration structure and initializes the interval timer accordingly */
uint8_t IntervalTimerInitialize(INTERVALTIMER_Config *pconfig)
{
	uint8_t error=IntervalTimerParamScanError(pconfig);				//Param scan for errors
	if(error) return error;

	IntervalTimerClockInit();				//Initialize the clock for Interval timer

	if(pconfig->clock_source) RTCCL |= (1 << RTC_RTCCL_RTCCL7_SHIFT);				//Internal Osc
	else RTCCL &= ~(1 << RTC_RTCCL_RTCCL7_SHIFT);				//External Osc

	IntervalTimerWriteClockOpt(pconfig->clock_selection);			//Clock selection write

	ITMC &= (~TIMER_ITMC_ITMCMP_MASK);								//Reset the count register
	ITMC |= TIMER_ITMC_ITMCMP_VALUE(pconfig->timer_ticks);			//Set the count register with desired number of ticks

	SetIntervalTimerInterruptPriority(pconfig->timer_interval_interrupt_prior);		//Set the priority of interval timer interrupt

	IntervalTimerStart();			//Start the interval timer

	return error;
}



/* Start the interval timer */
void IntervalTimerStart(void)
{
	ITMC |= TIMER_ITMC_RINTE_MASK;
}


/* Stop the interval timer */
void IntervalTimerStop(void)
{
	ITMC &= ~(1 << TIMER_ITMC_RINTE_SHIFT);
}


/* Initialize the interval timer clock */
void IntervalTimerClockInit(void)
{
	PER0 |= (1 << PER0_RTCEN_SHIFT);
}


/* De-init the interval timer clock */
void IntervalTimerClockDeInit(void)
{
	PER0 &= ~(1 << PER0_RTCEN_SHIFT);
}


/* Setting up the clock selection for interval timer */
void IntervalTimerWriteClockOpt(CLK_SEL selection)
{
	if(selection & 0x01) RTCCL |= (1 << RTC_RTCCL_RTCCL6_SHIFT);
	else RTCCL &= ~(1 << RTC_RTCCL_RTCCL6_SHIFT);

	RTCCL &= (~RTC_RTCCL_RTCCKS_MASK);
	RTCCL |= RTC_RTCCL_RTCCKS_VALUE(selection>>1);
}



/* Setting up interval timer interrupt priority */
void SetIntervalTimerInterruptPriority(uint8_t priority)
{
	PR00->PR &= (~INT_PR00_ITPR0_MASK);
	PR10->PR &= (~INT_PR10_ITPR1_MASK);
	PR00->PR |= (priority & 0x01) ? INT_PR00_ITPR0_MASK : 0;										//Set the priority bit 0
	PR10->PR |= (priority & 0x02) ? INT_PR10_ITPR1_MASK : 0;										//Set the priority bit 1
	MK0->MK &= (~INT_MK0_ITMK_MASK);																//Enable the interrupt
}



/* Validation of arguments passed to interval timer configuration structure */
uint8_t IntervalTimerParamScanError(INTERVALTIMER_Config *pconfig)
{
	uint8_t error=0;

	if(pconfig->clock_source > INT) error |= IT_CLOCK_SRC_OUT_OF_BOUND;
	if(pconfig->timer_interval_interrupt_prior > LVL3) error |= IT_INTERRUPT_PRIORITY_OUT_OF_BOUND;
	if(pconfig->clock_selection > CLK_SRC_BY_244) error |= IT_CLOCK_SEL_OUT_OF_BOUND;

	switch((uint8_t)pconfig->clock_selection)
	{
	case 1:
	case 3:
		error |= IT_CLOCK_SEL_OUT_OF_BOUND;
		break;

	default: break;
	}
	return error;
}



/* Time Tick API - To read how much time has elapsed from a certain reference point */
uint32_t ElapsedTimeDuration(uint32_t reference_time)
{
	return (msTicks >= reference_time) ? (msTicks - reference_time) : (MSTICKS_SPILL_VALUE + msTicks - reference_time);
}




/* Interval Timer Interrupt Handler */
void IntervalTimerInterruptHandler(void)
{
	msTicks = (msTicks >= MSTICKS_SPILL_VALUE) ? 0 : msTicks+1;				//Just to avoid overrun, it is reset to 0 once it reaches this value
}
