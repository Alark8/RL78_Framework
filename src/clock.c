#include "clock.h"


/* Sets up the oscillator based on what is passed in the configuration structure */
void SetupOscillator(CLK_Config *config, CLK_Reg *reg)
{
	switch(config->main_osc_type)
	{
	case X1_OSC:				//For external oscillator
		reg->cmc_reg |= (1 << CLOCK_CMC_OSCSEL_SHIFT);						//Set the CMC register

		if((uint8_t)config->oscillator_freq < CLOCK_FREQ_BOUNDARY)			//If the OSC frequency is under limit, then set the CMC register
			reg->cmc_reg |= (1 << CLOCK_CMC_AMPH_SHIFT);

		reg->csc_reg &= ~(1 << CLOCK_CSC_MSTOP_SHIFT);						//Update the CSC register

		reg->ckc_reg |= (1 << CLOCK_CKC_MCM0_SHIFT);						//Update the CKC register
		break;

	case EXT_IP:				//For external clock on MCU PIN
		reg->cmc_reg |= (1 << CLOCK_CMC_EXCLK_SHIFT);						//Set the CMC register
		reg->cmc_reg |= (1 << CLOCK_CMC_OSCSEL_SHIFT);						//Set the CMC register

		reg->csc_reg &= ~(1 << CLOCK_CSC_MSTOP_SHIFT);						//Update the CSC register
		break;

	case HIGH_SPEED_INT:
		SetHighSpeedIntOscillatorFreq(config->oscillator_freq);				//Do not have any effect, setting in Option Byte

		reg->csc_reg &= ~(1 << CLOCK_CSC_HIOSTOP_SHIFT);					//Update the CSC register

		reg->ckc_reg &= ~(1 << CLOCK_CKC_MCM0_SHIFT);						//Update the CKC register
		break;

	default: break;
	}


	if(config->subsystem_osc_enabled)									//If sub system oscillator is enabled
	{
		reg->cmc_reg |= (1 << CLOCK_CMC_OSCSELS_SHIFT);																//Enable the sub system clock
		reg->cmc_reg |= CLOCK_CMC_AMPHS_VALUE((uint8_t)config->sub_clk_power_mode);									//Set the power mode for sub system clock

		if((uint8_t)config->cpu_clk_select)
			reg->ckc_reg |= (1 << CLOCK_CKC_CSS_SHIFT);																//Set Subsystem clock as the CPU clock
		else
			reg->ckc_reg &= ~(1 << CLOCK_CKC_CSS_SHIFT);															//Set the Main clock as the CPU clock

		reg->csc_reg &= ~(1 << CLOCK_CSC_XTSTOP_SHIFT);																//Start Sub System Oscillator
	}

	if(config->lowspeed_osc_enable) EnableLowSpeedOscClock();
}



/* This function is responsible for setting up the PLL Clock */
uint8_t SetupPLL(CLK_Config *config)
{
	uint8_t pll_status=PLL_ERROR_NULL;

	if(config->pll_enabled)			//If PLL has to be enabled
	{
		/* PLL can only be enabled if oscillator is high speed internal or external oscillator and also for 4MHz and 8MHz */
		if((config->main_osc_type == X1_OSC || config->main_osc_type == HIGH_SPEED_INT) && config->oscillator_freq >= CLOCK_FREQ_BOUNDARY)
		{
			switch(config->oscillator_freq)
			{
			case F4MHZ: PLL->PLLCTL &= (~PLL_PLLCTL_LCKSEL_MASK);
						PLL->PLLCTL |= PLL_PLLCTL_LCKSEL_VALUE(1);													//Set the LCKSEL value as 1 for 4MHz
						PLL->PLLCTL &= ~(1 << PLL_PLLCTL_PLLDIV0_SHIFT);											//Set the PLLDIV0 value as 0 for 4MHz
				break;

			case F8MHZ: PLL->PLLCTL &= (~PLL_PLLCTL_LCKSEL_MASK);
						PLL->PLLCTL |= PLL_PLLCTL_LCKSEL_VALUE(2);													//Set the LCKSEL value as 2 for 8MHz
						PLL->PLLCTL |= (1 << PLL_PLLCTL_PLLDIV0_SHIFT);												//Set the PLLDIV0 value as 1 for 8MHz
				break;

			default: break;
			}
		}
		else pll_status = PLL_INVALID_OSC_OR_FREQ_ERROR;

		if(config->pll_multiplier) OPT3 |= (1 << OPT3_OPTPLL_SHIFT);												//PLL Multiplier by 6 or 3
		else OPT3 &= ~(1 << OPT3_OPTPLL_SHIFT);																		//PLL Multiplier by 8 or 4

		PLL->PLLCTL |= (1 << PLL_PLLCTL_PLLON_SHIFT);																//Turn on the PLL

		while(!GetPLLLockStatus());																					//Wait till PLL to get stable

		PLL->PLLCTL |= (1 << PLL_PLLCTL_SELPLL_SHIFT);																//Make PLL Clock as the main clock
	}

	return pll_status;
}




/* Peripheral Clock Selection based on CPU_CLK selection */
void SelectPeripheralClock(CPU_CLK fclock)
{
	switch(fclock)
	{
	case Fmain: CLOCK->CKC &= ~(1 << CLOCK_CKC_CSS_SHIFT);			//Fmain select
		break;

	case Fsub: CLOCK->CKC |= (1 << CLOCK_CKC_CSS_SHIFT);			//Fsub select
		break;

	default: break;
	}
}



/* Main Clock Selection based on FMAIN selection */
void SelectMainSystemClock(FMAIN oscillator)
{
	switch(oscillator)
	{
	case INTERNAL: CLOCK->CKC &= ~(1 << CLOCK_CKC_MCM0_SHIFT);		//Internal oscillator select
		break;

	case EXTERNAL: CLOCK->CKC |= (1 << CLOCK_CKC_MCM0_SHIFT);		//External oscillator select
		break;
	}
}




/* Enable the oscillator */
uint8_t EnableOscillator(OSC_TYPE oscillator, uint8_t osts_value)
{
	uint8_t ostc_value=0;

	switch(oscillator)
	{
	case X1_OSC: ostc_value = SetOSTSRegister(osts_value);				//Set the OSTS register
		CLOCK->CSC &= ~(1 << CLOCK_CSC_MSTOP_SHIFT);					//Update the CSC register
		while(CLOCK->OSTC != ostc_value);								//While oscillation has reached a stable point
		break;

	case EXT_IP: CLOCK->CSC &= ~(1 << CLOCK_CSC_MSTOP_SHIFT);			//Update the CSC register
		break;

	case HIGH_SPEED_INT: ostc_value = SetOSTSRegister(osts_value);		//Set the OSTS register
		CLOCK->CSC &= ~(1 << CLOCK_CSC_HIOSTOP_SHIFT);					//Update the CSC register
		while(CLOCK->OSTC != ostc_value);								//While oscillation has reached a stable point
		break;

	case SUBSYSTEM: CLOCK->CSC &= ~(1 << CLOCK_CSC_XTSTOP_SHIFT);		//Update the CSC register
		break;

	default: break;
	}
	return 0;
}




/* Disable the oscillator */
void DisableOscillator(OSC_TYPE oscillator)
{
	switch(oscillator)
	{
	case X1_OSC: case EXT_IP: CLOCK->CSC |= (1 << CLOCK_CSC_MSTOP_SHIFT);
		break;

	case HIGH_SPEED_INT: CLOCK->CSC |= (1 << CLOCK_CSC_HIOSTOP_SHIFT);
		break;

	case SUBSYSTEM: CLOCK->CSC |= (1 << CLOCK_CSC_XTSTOP_SHIFT);
		break;

	default: break;
	}
}



/* Setting up CLM Interrupt Priority */
void SetCLMInterruptPriority(uint8_t priority)
{
	PR00->PR &= (~INT_PR00_CLMPR0_MASK);
	PR10->PR &= (~INT_PR10_CLMPR1_MASK);
	PR00->PR |= (priority & 0x01) ? INT_PR00_CLMPR0_MASK : 0;
	PR10->PR |= (priority & 0x02) ? INT_PR10_CLMPR1_MASK : 0;
	//MK0->MK &= (~INT_MK0_CLMMK_MASK);
}




/* Get the peripheral clock status */
uint8_t GetPeripheralClockStatus(void)
{
	return (CLOCK->CKC & CLOCK_CKC_CLS_SHIFT);
}



/* Get the main system clock status */
uint8_t GetMainSystemClockStatus(void)
{
	return (CLOCK->CKC & CLOCK_CKC_MCS_MASK);
}



/* Get the PLL clock status */
uint8_t GetPLLLockStatus(void)
{
	return (PLL->PLLSTS & PLL_PLLSTS_LOCK_MASK);
}



/* Get the PLL Clock mode status */
uint8_t GetPLLClockModeStatus(void)
{
	return (PLL->PLLSTS & PLL_PLLSTS_SELPLLS_MASK);
}



/* this function don't make any change */
void SetHighSpeedIntOscillatorFreq(OSC_FREQ freq)
{
	OPT3 &= (~OPT3_FRQSEL_MASK);
	OPT3 |= OPT3_FRQSEL_VALUE((uint8_t)freq);
}



/* Enable low speed OSC Clock */
void EnableLowSpeedOscClock(void)
{
	OSMC |= (1 << CLOCK_OSMC_WUTMMCK0_SHIFT);
}



/* Disable the low speed OSC clock */
void DisableLowSpeedOscClock(void)
{
	OSMC &= ~(1 << CLOCK_OSMC_WUTMMCK0_SHIFT);
}



/* Disable PLL */
void DisablePLL(void)
{
	PLL->PLLCTL &= (~PLL_PLLCTL_PLLON_MASK);
	PLL->PLLCTL &= (~PLL_PLLCTL_SELPLL_MASK);
}
