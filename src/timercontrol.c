/*
 * timercontrol.c
 *
 *  Created on: 17-Mar-2021
 *      Author: alarkm
 */

#include "timercontrol.h"


uint8_t TimerInitialize(TIMER_Type *ptimer, TIMER_Config *pconfig)
{
	uint8_t error = TimerParamScanError(pconfig), idx=0;
	if(error) return error;

	TIMERPARAMS timer_info;

	TMRChannel_Config *channel_config_base = (TMRChannel_Config *)&pconfig->timer_channels;

	GetTimerRelatedParams(ptimer, &timer_info);

	TimerClockInit(ptimer, timer_info.clock_timer_bit);

	TimerInit(ptimer, pconfig, timer_info.noisefilter);

	for(idx=0; idx<8; ++idx)
	{
		uint8_t bit_shift = (idx & 3) << 1;
		TMRChannel_Config *current_config = (channel_config_base + idx);

		if(current_config->timer_channel_used)
		{
			SetTimerModeRegister((timer_info.tmr_address + (2 * idx)), current_config);
			TimerArrayInit(ptimer, idx, current_config, timer_info.noisefilter);

			if(idx > 3)
			{
				TimerInputPinSelect(ptimer, timer_info.tis_address+1, bit_shift, current_config->timer_ip_alternate_pin_select);
				TimerOutputPinSelect(ptimer, timer_info.tos_address+1, bit_shift, current_config->timer_out_alternate_pin_select);
			}
			else
			{
				TimerInputPinSelect(ptimer, timer_info.tis_address, bit_shift, current_config->timer_ip_alternate_pin_select);
				TimerOutputPinSelect(ptimer, timer_info.tos_address, bit_shift, current_config->timer_out_alternate_pin_select);
			}

			SetTimerInterruptPriority(ptimer, idx, current_config->timer_intp_priority);

			if(current_config->timer_start) TimerStart(ptimer, idx);
			else TimerStop(ptimer, idx);
		}
	}

	return error;
}




void GetTimerRelatedParams(TIMER_Type *ptimer, TIMERPARAMS *ptimer_info)
{
	switch((uint16_t)ptimer)
	{
	case TIMER0_REGISTER_BASE:
		ptimer_info->clock_timer_bit = PER0_TAU0EN_SHIFT;
		ptimer_info->noisefilter = NOISE_FILTER_CONFIG0;
		ptimer_info->tmr_address = TIMER_MODE_REGISTER_00_BASE;
		ptimer_info->tis_address = TIMER_INPUT_SELECT_REGISTER_00_BASE;
		ptimer_info->tos_address = TIMER_OUTPUT_SELECT_REGISTER_00_BASE;
		break;

	case TIMER1_REGISTER_BASE:
		ptimer_info->clock_timer_bit = PER0_TAU1EN_SHIFT;
		ptimer_info->noisefilter = NOISE_FILTER_CONFIG1;
		ptimer_info->tmr_address = TIMER_MODE_REGISTER_10_BASE;
		ptimer_info->tis_address = TIMER_INPUT_SELECT_REGISTER_10_BASE;
		ptimer_info->tos_address = TIMER_OUTPUT_SELECT_REGISTER_10_BASE;
		break;

	case TIMER2_REGISTER_BASE:
		ptimer_info->clock_timer_bit = PER0_TAU2EN_SHIFT;
		ptimer_info->noisefilter = NOISE_FILTER_CONFIG2;
		ptimer_info->tmr_address = TIMER_MODE_REGISTER_20_BASE;
		ptimer_info->tis_address = TIMER_INPUT_SELECT_REGISTER_20_BASE;
		ptimer_info->tos_address = TIMER_OUTPUT_SELECT_REGISTER_20_BASE;
		break;

	default: break;
	}
}




uint8_t SetTimerInterruptPriority(TIMER_Type *ptimer, uint8_t timer_channel, uint8_t priority)
{
	uint8_t error=NO_ERROR_TIMER;

	if((timer_channel > MAX_TIMER_CHANNELS_IN_TAU) || priority > (uint8_t)LVL3) error = TIMER_PRIOR_OUT_OF_BOUND;

	switch((uint16_t)ptimer)
	{
	case TIMER0_REGISTER_BASE: SetTAU0Priority(timer_channel, priority);
		break;

	case TIMER1_REGISTER_BASE: SetTAU1Priority(timer_channel, priority);
		break;

	case TIMER2_REGISTER_BASE: SetTAU2Priority(timer_channel, priority);
		break;

	default: break;
	}

	return error;
}



uint8_t TimerParamScanError(TIMER_Config *pconfig)
{
	uint8_t idx=0,error=0;

	TMRChannel_Config *channel_config_base = (TMRChannel_Config *)&pconfig->timer_channels;

	for(idx=0; idx<8; ++idx)
	{
		TMRChannel_Config *current_config = (channel_config_base + idx);

		if(current_config->clk_option > CKM3) error |= TIMER_CLOCK_OUT_OF_BOUND;
		if(current_config->trigger_option == 3 || current_config->trigger_option > INT_SIGNAL) error |= TIMER_TRG_OPT_OUT_OF_BOUND;
		if(current_config->valid_edge_TImn > BOTH_EDGE_HIGH) error |= TIMER_TIMN_IN_OUT_OF_BOUND;
		if(current_config->timer_mode > CAPTURE_ONE_COUNT) error |= TIMER_TMR_OPT_OUT_OF_BOUND;

		switch((uint8_t)current_config->timer_mode)
		{
		case 2:
		case 3:
		case 7:
		case 10:
		case 11:
			error |= TIMER_TMR_OPT_OUT_OF_BOUND;
			break;

		default: break;
		}
	}

	return error;
}


