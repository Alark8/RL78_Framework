/*
 * timeconfig.c
 *
 *  Created on: 05-May-2021
 *      Author: alarkm
 */


#include "timerconfig.h"


TIMER_Config DefaultTimerSetting(void)
{
	TIMER_Config config = {(0)};

	config.ckm0_fclk_divider = 0;
	config.ckm1_fclk_divider = 1;
	config.ckm2_fclk_divider = 2;
	config.ckm3_fclk_divider = 3;
	config.noise_filter_sample_clock0 = 1;
	config.noise_filter_sample_clock1 = 1;

	config.timer_channels.CH0 = DefaultTimerChannelSetting();
	config.timer_channels.CH1 = DefaultTimerChannelSetting();
	config.timer_channels.CH2 = DefaultTimerChannelSetting();
	config.timer_channels.CH3 = DefaultTimerChannelSetting();
	config.timer_channels.CH4 = DefaultTimerChannelSetting();
	config.timer_channels.CH5 = DefaultTimerChannelSetting();
	config.timer_channels.CH6 = DefaultTimerChannelSetting();
	config.timer_channels.CH7 = DefaultTimerChannelSetting();

	return config;
}




TMRChannel_Config DefaultTimerChannelSetting(void)
{
	TMRChannel_Config config = {(0)};

	config.clk_option = CKM0;
	config.master_channel = FALSE;
	config.trigger_option = SW_TRIG;
	config.clock_TImn_enabled = FALSE;
	config.timer_mode = INTERVAL_TMR_INT;
	config.timer_output_enabled = FALSE;
	config.timer_output_active_low = FALSE;
	config.timer_output_toggle_mode = TRUE;
	config.noise_filter_enable = FALSE;
	config.timer_start = TRUE;
	config.noise_filter_clock_select = 0;
	config.timer_intp_priority = LVL3;
	config.timer_channel_used = FALSE;

	return config;
}
