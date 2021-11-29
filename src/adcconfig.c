/*
 * adcconfig.c
 *
 *  Created on: 05-May-2021
 *      Author: alarkm
 */

#include "adcconfig.h"

/* Function to return the ADC configuration settings */
ADC_Config DefaultADCSetting(void)
{
	ADC_Config config = {(0)};

	config.adc_8bit_resolution = FALSE;
	config.adc_neg_ref_voltage_vrefm1 = TRUE;
	config.adc_positive_ref_voltage = VREFP;
	config.adc_scan_mode = FALSE;
	config.adc_fr_value = 1;
	config.adc_lv_value = 0;
	config.adc_trigger_mode = SFW_TRIG;
	config.adc_one_shot_conv = TRUE;
	config.adc_snooze_enabled = FALSE;
	config.adc_adpc_value = 0;
	config.adc_interrupt_priority = LVL3;

	return config;
}
