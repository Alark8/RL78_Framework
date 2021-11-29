/*
 * timer.c
 *
 *  Created on: 18-Mar-2021
 *      Author: alarkm
 */

#include "timer.h"


void TimerInit(TIMER_Type *ptimer, TIMER_Config *pconfig, NoiseFilter_Config_Type *noisefilter)
{
	ptimer->TPS |= TIMER_TPS_M00_VALUE(pconfig->ckm0_fclk_divider);
	ptimer->TPS |= TIMER_TPS_M10_VALUE(pconfig->ckm1_fclk_divider);
	ptimer->TPS |= TIMER_TPS_M20_VALUE(pconfig->ckm2_fclk_divider);
	ptimer->TPS |= TIMER_TPS_M30_VALUE(pconfig->ckm3_fclk_divider);

	noisefilter->TNFSMP |= TIMER_TNFSMP_TNFSMP00_VALUE(pconfig->noise_filter_sample_clock0);
	noisefilter->TNFSMP |= TIMER_TNFSMP_TNFSMP10_VALUE(pconfig->noise_filter_sample_clock1);
}




void SetTimerArrayClock(TIMER_Type *ptimer, CLK_OPT clock_opt, uint8_t value)
{
	switch(clock_opt)
	{
	case CKM0: ptimer->TPS &= (~TIMER_TPS_M00_MASK);
			   ptimer->TPS |= TIMER_TPS_M00_VALUE(value);
		break;

	case CKM1: ptimer->TPS &= (~TIMER_TPS_M10_MASK);
			   ptimer->TPS |= TIMER_TPS_M10_VALUE(value);
			break;

	case CKM2: ptimer->TPS &= (~TIMER_TPS_M20_MASK);
			   ptimer->TPS |= TIMER_TPS_M20_VALUE(value);
			break;

	case CKM3: ptimer->TPS &= (~TIMER_TPS_M30_MASK);
			   ptimer->TPS |= TIMER_TPS_M30_VALUE(value);
			break;

	default: break;
	}
}




void SetTimerNoiseFilterClock(NoiseFilter_Config_Type *pnoiseconfig, uint8_t nible, uint8_t value)
{
	switch(nible)
	{
	case LSB:
		pnoiseconfig->TNFSMP &= (~TIMER_TNFSMP_TNFSMP00_MASK);
		pnoiseconfig->TNFSMP |= TIMER_TNFSMP_TNFSMP00_VALUE(value);
		break;

	case MSB:
		pnoiseconfig->TNFSMP &= (~TIMER_TNFSMP_TNFSMP10_MASK);
		pnoiseconfig->TNFSMP |= TIMER_TNFSMP_TNFSMP10_VALUE(value);
		break;

	default: break;
	}
}




void SetTimerModeRegister(uint16_t tmr_address, TMRChannel_Config *tmrconfig)
{
	__near uint16_t tmr = *((__near volatile uint16_t *)tmr_address);

	tmr &= (~TIMER_TMR_CKS_MASK);
	tmr |= TIMER_TMR_CKS_VALUE((uint8_t)tmrconfig->clk_option);

	if(tmrconfig->clock_TImn_enabled)
		tmr |= (1 << TIMER_TMR_CCS_SHIFT);
	else tmr &= ~(1 << TIMER_TMR_CCS_SHIFT);

	if(tmrconfig->master_channel)
		tmr |= (1 << TIMER_TMR_MASTER_SHIFT);
	else tmr &= ~(1 << TIMER_TMR_MASTER_SHIFT);

	tmr &= (~TIMER_TMR_STS_MASK);
	tmr |= TIMER_TMR_STS_VALUE((uint8_t)tmrconfig->trigger_option);

	tmr &= (~TIMER_TMR_CIS_MASK);
	tmr |= TIMER_TMR_CIS_VALUE((uint8_t)tmrconfig->valid_edge_TImn);

	tmr &= (~TIMER_TMR_MD_MASK);
	tmr |= TIMER_TMR_MD_VALUE((uint8_t)tmrconfig->timer_mode);
}




void TimerArrayInit(TIMER_Type *ptimer, uint8_t channel, TMRChannel_Config *pconfig, NoiseFilter_Config_Type *noisefilter)
{
	if(pconfig->timer_output_enabled) ptimer->TOE |= (1 << channel);
	else ptimer->TOE &= ~(1 << channel);

	if(pconfig->timer_output_active_low) ptimer->TOL |= (1 << channel);
	else ptimer->TOL &= ~(1 << channel);

	if(pconfig->timer_output_toggle_mode) ptimer->TOM &= ~(1 << channel);
	ptimer->TOM |= (1 << channel);

	if(pconfig->noise_filter_enable) noisefilter->TNFEN |= (1 << channel);
	else noisefilter->TNFEN &= ~(1 << channel);

	if(pconfig->noise_filter_clock_select) noisefilter->TNFCS |= (1 << channel);
	noisefilter->TNFCS &= ~(1 << channel);
}



void SetTAU0Priority(uint8_t channel, uint8_t priority)
{
	switch(channel)
	{
	case 0:
		PR01->PR &= (~INT_PR01_TMPR000_MASK);
		PR11->PR &= (~INT_PR11_TMPR100_MASK);
		PR01->PR |= (priority & 0x01) ? INT_PR01_TMPR000_MASK : 0;
		PR11->PR |= (priority & 0x02) ? INT_PR11_TMPR100_MASK : 0;
		//MK1->MK &= (~INT_MK1_TMMK00_MASK);																		//Enable the interrupt
		break;

	case 1:
		PR01->PR &= (~INT_PR01_TMPR001_MASK);
		PR11->PR &= (~INT_PR11_TMPR101_MASK);
		PR01->PR |= (priority & 0x01) ? INT_PR01_TMPR001_MASK : 0;
		PR11->PR |= (priority & 0x02) ? INT_PR11_TMPR101_MASK : 0;
		//MK1->MK &= (~INT_MK1_TMMK01_MASK);
		break;

	case 2:
		PR01->PR &= (~INT_PR01_TMPR002_MASK);
		PR11->PR &= (~INT_PR11_TMPR102_MASK);
		PR01->PR |= (priority & 0x01) ? INT_PR01_TMPR002_MASK : 0;
		PR11->PR |= (priority & 0x02) ? INT_PR11_TMPR102_MASK : 0;
		//MK1->MK &= (~INT_MK1_TMMK02_MASK);
		break;

	case 3:
		PR01->PR &= (~INT_PR01_TMPR003_MASK);
		PR11->PR &= (~INT_PR11_TMPR103_MASK);
		PR01->PR |= (priority & 0x01) ? INT_PR01_TMPR003_MASK : 0;
		PR11->PR |= (priority & 0x02) ? INT_PR11_TMPR103_MASK : 0;
		//MK1->MK &= (~INT_MK1_TMMK03_MASK);
		break;

	case 4:
		PR01->PR &= (~INT_PR01_TMPR004_MASK);
		PR11->PR &= (~INT_PR11_TMPR104_MASK);
		PR01->PR |= (priority & 0x01) ? INT_PR01_TMPR004_MASK : 0;
		PR11->PR |= (priority & 0x02) ? INT_PR11_TMPR104_MASK : 0;
		//MK1->MK &= (~INT_MK1_TMMK04_MASK);
		break;

	case 5:
		PR02->PR &= (~INT_PR02_TMPR005_MASK);
		PR12->PR &= (~INT_PR12_TMPR105_MASK);
		PR02->PR |= (priority & 0x01) ? INT_PR02_TMPR005_MASK : 0;
		PR12->PR |= (priority & 0x02) ? INT_PR12_TMPR105_MASK : 0;
		//MK2->MK &= (~INT_MK2_TMMK05_MASK);
		break;

	case 6:
		PR02->PR &= (~INT_PR02_TMPR006_MASK);
		PR12->PR &= (~INT_PR12_TMPR106_MASK);
		PR02->PR |= (priority & 0x01) ? INT_PR02_TMPR006_MASK : 0;
		PR12->PR |= (priority & 0x02) ? INT_PR12_TMPR106_MASK : 0;
		//MK2->MK &= (~INT_MK2_TMMK06_MASK);
		break;

	case 7:
		PR02->PR &= (~INT_PR02_TMPR007_MASK);
		PR12->PR &= (~INT_PR12_TMPR107_MASK);
		PR02->PR |= (priority & 0x01) ? INT_PR02_TMPR007_MASK : 0;
		PR12->PR |= (priority & 0x02) ? INT_PR12_TMPR107_MASK : 0;
		//MK2->MK &= (~INT_MK2_TMMK07_MASK);
		break;

	default: break;
	}
}



void SetTAU1Priority(uint8_t channel, uint8_t priority)
{
	switch(channel)
	{
	case 0:
		PR02->PR &= (~INT_PR02_TMPR010_MASK);
		PR12->PR &= (~INT_PR12_TMPR110_MASK);
		PR02->PR |= (priority & 0x01) ? INT_PR02_TMPR010_MASK : 0;
		PR12->PR |= (priority & 0x02) ? INT_PR12_TMPR110_MASK : 0;
		//MK2->MK &= (~INT_MK2_TMMK10_MASK);
		break;

	case 1:
		PR02->PR &= (~INT_PR02_TMPR011_MASK);
		PR12->PR &= (~INT_PR12_TMPR111_MASK);
		PR02->PR |= (priority & 0x01) ? INT_PR02_TMPR011_MASK : 0;
		PR12->PR |= (priority & 0x02) ? INT_PR12_TMPR111_MASK : 0;
		//MK2->MK &= (~INT_MK2_TMMK11_MASK);
		break;

	case 2:
		PR02->PR &= (~INT_PR02_TMPR012_MASK);
		PR12->PR &= (~INT_PR12_TMPR112_MASK);
		PR02->PR |= (priority & 0x01) ? INT_PR02_TMPR012_MASK : 0;
		PR12->PR |= (priority & 0x02) ? INT_PR12_TMPR112_MASK : 0;
		//MK2->MK &= (~INT_MK2_TMMK12_MASK);
		break;

	case 3:
		PR02->PR &= (~INT_PR02_TMPR013_MASK);
		PR12->PR &= (~INT_PR12_TMPR113_MASK);
		PR02->PR |= (priority & 0x01) ? INT_PR02_TMPR013_MASK : 0;
		PR12->PR |= (priority & 0x02) ? INT_PR12_TMPR113_MASK : 0;
		//MK2->MK &= (~INT_MK2_TMMK13_MASK);
		break;

	case 4:
		PR03->PR &= (~INT_PR03_TMPR014_MASK);
		PR13->PR &= (~INT_PR13_TMPR114_MASK);
		PR03->PR |= (priority & 0x01) ? INT_PR03_TMPR014_MASK : 0;
		PR13->PR |= (priority & 0x02) ? INT_PR13_TMPR114_MASK : 0;
		//MK3->MK &= (~INT_MK3_TMMK14_MASK);
		break;

	case 5:
		PR03->PR &= (~INT_PR03_TMPR015_MASK);
		PR13->PR &= (~INT_PR13_TMPR115_MASK);
		PR03->PR |= (priority & 0x01) ? INT_PR03_TMPR015_MASK : 0;
		PR13->PR |= (priority & 0x02) ? INT_PR13_TMPR115_MASK : 0;
		//MK3->MK &= (~INT_MK3_TMMK15_MASK);
		break;

	case 6:
		PR03->PR &= (~INT_PR03_TMPR016_MASK);
		PR13->PR &= (~INT_PR13_TMPR116_MASK);
		PR03->PR |= (priority & 0x01) ? INT_PR03_TMPR016_MASK : 0;
		PR13->PR |= (priority & 0x02) ? INT_PR13_TMPR116_MASK : 0;
		//MK3->MK &= (~INT_MK3_TMMK16_MASK);
		break;

	case 7:
		PR03->PR &= (~INT_PR03_TMPR017_MASK);
		PR13->PR &= (~INT_PR13_TMPR117_MASK);
		PR03->PR |= (priority & 0x01) ? INT_PR03_TMPR017_MASK : 0;
		PR13->PR |= (priority & 0x02) ? INT_PR13_TMPR117_MASK : 0;
		//MK3->MK &= (~INT_MK3_TMMK17_MASK);
		break;

	default: break;
	}
}



void SetTAU2Priority(uint8_t channel, uint8_t priority)
{
	switch(channel)
	{
	case 0:
		PR03->PR &= (~INT_PR03_TMPR020_MASK);
		PR13->PR &= (~INT_PR13_TMPR120_MASK);
		PR03->PR |= (priority & 0x01) ? INT_PR03_TMPR020_MASK : 0;
		PR13->PR |= (priority & 0x02) ? INT_PR13_TMPR121_MASK : 0;
		//MK3->MK &= (~INT_MK3_TMMK20_MASK);
		break;

	case 1:
		PR03->PR &= (~INT_PR03_TMPR021_MASK);
		PR13->PR &= (~INT_PR13_TMPR121_MASK);
		PR03->PR |= (priority & 0x01) ? INT_PR03_TMPR021_MASK : 0;
		PR13->PR |= (priority & 0x02) ? INT_PR13_TMPR121_MASK : 0;
		//MK3->MK &= (~INT_MK3_TMMK21_MASK);
		break;

	case 2:
		PR03->PR &= (~INT_PR03_TMPR022_MASK);
		PR13->PR &= (~INT_PR13_TMPR122_MASK);
		PR03->PR |= (priority & 0x01) ? INT_PR03_TMPR022_MASK : 0;
		PR13->PR |= (priority & 0x02) ? INT_PR13_TMPR122_MASK : 0;
		//MK3->MK &= (~INT_MK3_TMMK22_MASK);
		break;

	case 3:
		PR03->PR &= (~INT_PR03_TMPR023_MASK);
		PR13->PR &= (~INT_PR13_TMPR123_MASK);
		PR03->PR |= (priority & 0x01) ? INT_PR03_TMPR023_MASK : 0;
		PR13->PR |= (priority & 0x02) ? INT_PR13_TMPR123_MASK : 0;
		//MK3->MK &= (~INT_MK3_TMMK23_MASK);
		break;

	case 4:
		PR03->PR &= (~INT_PR03_TMPR024_MASK);
		PR13->PR &= (~INT_PR13_TMPR124_MASK);
		PR03->PR |= (priority & 0x01) ? INT_PR03_TMPR024_MASK : 0;
		PR13->PR |= (priority & 0x02) ? INT_PR13_TMPR124_MASK : 0;
		//MK3->MK &= (~INT_MK3_TMMK24_MASK);
		break;

	case 6:
		PR03->PR &= (~INT_PR03_TMPR026_MASK);
		PR13->PR &= (~INT_PR13_TMPR126_MASK);
		PR03->PR |= (priority & 0x01) ? INT_PR03_TMPR026_MASK : 0;
		PR13->PR |= (priority & 0x02) ? INT_PR13_TMPR126_MASK : 0;
		//MK3->MK &= (~INT_MK3_TMMK26_MASK);
		break;

	default: break;
	}
}




void TimerInputPinSelect(TIMER_Type *ptimer, uint16_t tis_address, uint8_t bit_shift, uint8_t selection)
{
	uint8_t mask = (0x03 << bit_shift);
	__near volatile uint16_t tis = *((__near volatile uint16_t *)tis_address);

	tis &= (~mask);
	tis |= (selection << bit_shift) & mask;
}




void TimerOutputPinSelect(TIMER_Type *ptimer, uint16_t tos_address, uint8_t bit_shift, uint8_t selection)
{
	uint8_t mask = (0x03 << bit_shift);
	__near volatile uint16_t tos = *((__near volatile uint16_t *)tos_address);

	tos &= (~mask);
	tos |= (selection << bit_shift) & mask;
}



uint8_t GetTimerEnableStatus(TIMER_Type *ptimer, uint8_t channel)
{
	return (ptimer->TE & (1 << channel));
}




void TimerStart(TIMER_Type *ptimer, uint8_t channel)
{
	ptimer->TS |= (1 << channel);
}



void TimerStop(TIMER_Type *ptimer, uint8_t channel)
{
	ptimer->TS &= ~(1 << channel);
}




void TimerClockInit(TIMER_Type *ptimer, uint8_t clock_timer_bit)
{
	PER0 |= (1 << clock_timer_bit);
}




void TimerClockDeInit(TIMER_Type *ptimer, uint8_t clock_timer_bit)
{
	PER0 &= ~(1 << clock_timer_bit);
}




