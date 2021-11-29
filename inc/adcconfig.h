#ifndef ADCCONFIG_H
#define ADCCONFIG_H

#include "rl78_d1a_head.h"				//Device header

/* ADC Trigger Selection
 * SFW_TRIG -> Software Trigger
 * HW_TRIG_NO_WAIT -> Hardware Trigger with no Wait
 * HW_TRIG_WAIT -> Hardware Trigger with Wait */
typedef enum {SFW_TRIG=0, HW_TRIG_NO_WAIT=2, HW_TRIG_WAIT=3} ADC_TRIG;


/* ADC Hardware Trigger Selection
 * TAU_02 -> Timer array unit 2
 * TAU_04 -> Timer array unit 4
 * HW_TRIG_NO_NOISE_FLTR -> Hardware trigger with no Noise Filter
 * HW_TRIG_NOISE_FLTR -> Hardware trigger with Noise Filter */
typedef enum {TAU_02, TAU_04, HW_TRIG_NO_NOISE_FLTR, HW_TRIG_NOISE_FLTR} ADC_HW_TRIG;


/* ADC Positive Reference selection
 * VDD -> Vdd
 * VREFP -> Vrefp
 * INT_VOL_1_45 -> Internal voltage 1.45 */
typedef enum {VDD, VREFP, INT_VOL_1_45} ADC_POS_REF;


typedef struct{
	ADC_TRIG adc_trigger_mode;
	ADC_HW_TRIG adc_hw_trigger_select;
	ADC_POS_REF adc_positive_ref_voltage;
	INT_PRIORITY adc_interrupt_priority;
	uint16_t adc_scan_mode						:1;				//True or False
	uint16_t adc_fr_value						:3;				//Value from 0 to 7
	uint16_t adc_lv_value						:2;				//Value from 0 to 3
	uint16_t adc_one_shot_conv					:1;				//True or False
	uint16_t adc_neg_ref_voltage_vrefm1			:1;				//True or False
	uint16_t adc_interrupt_setting				:1;				//True or False
	uint16_t adc_snooze_enabled					:1;				//True or False
	uint16_t adc_8bit_resolution				:1;				//True or False
	uint16_t adc_adpc_value						:5;
}ADC_Config;


ADC_Config DefaultADCSetting(void);					//API for getting the ADC configuration setting


#endif
