/*
 * clockconfig.c
 *
 *  Created on: 05-May-2021
 *      Author: alarkm
 */
#include "clockconfig.h"


/* A function to return the clock configuration structure */
CLK_Config DefaultClockSetting(void)
{
	CLK_Config clk_setting = {(0)};

	clk_setting.main_osc_type = HIGH_SPEED_INT;
	clk_setting.sub_clk_power_mode = ULTRA_LOW;
	clk_setting.cpu_clk_select = Fmain;
	clk_setting.pll_multiplier = M8;
	clk_setting.oscillator_freq = F4MHZ;
	clk_setting.subsystem_osc_enabled = FALSE;
	clk_setting.pll_enabled = TRUE;
	clk_setting.osts_select = 4;
	clk_setting.lowspeed_osc_enable = FALSE;
	clk_setting.clm_interrupt_priority = LVL3;

	return clk_setting;
}
