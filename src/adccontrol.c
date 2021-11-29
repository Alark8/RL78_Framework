/*
 * adccontrol.c
 *
 *  Created on: 26-Apr-2021
 *      Author: alarkm
 */

#include "adccontrol.h"

/* The function takes in ADC_Config structure and initializes the peripheral as desired */
uint8_t ADCInitialize(ADC_Config *pconfig)
{
	uint8_t error=ADCParamScanError(pconfig);			//Check for error in ADC parameters
	if(error) return error;

	ADCClockInit();				//Init ADC Clock

	//ADPC Setting//
	SetADCADPCValue(pconfig->adc_adpc_value);

	//ADM0
	if(pconfig->adc_scan_mode) SetADCScanMode();				//Scan Mode selection
	else SetADCSelectMode();									//Select Mode selection

	SetADCFRValue(pconfig->adc_fr_value);			//Set the FR Value
	SetADCLVValue(pconfig->adc_lv_value);			//Set the LV Value

	//ADM1
	if(pconfig->adc_one_shot_conv) SetADCOneShotMode();			//One Shot mode selection
	else SetADCSequentialMode();								//Sequential mode selection

	SetADCTriggerMode(pconfig->adc_trigger_mode);				//Trigger mode selection
	SetADCHWTriggerSelect(pconfig->adc_hw_trigger_select);		//ADC HW Trigger selection

	//ADM2
	if(pconfig->adc_neg_ref_voltage_vrefm1) SetADCVrefmNegativeReference();				//ADC Vref negative ref selection
	else SetADCVssNegativeReference();						//ADC Vss Negative ref selection

	if(pconfig->adc_snooze_enabled) EnableADCSnoozeMode();				//Snooze Mode selection
	else DisableADCSnoozeMode();							//Disable the snooze mode

	if(pconfig->adc_interrupt_setting) SetADCInterruptADCRLower();				//ADC interrupt ADCR lower setting
	else SetADCInterruptADCRGreater();				//ADC interrupt ADCR greater setting

	if(pconfig->adc_8bit_resolution) SetADC8bitResolution();			//8 bit resolution
	else SetADC10bitResolution();				//10 bit resolution

	SetADCPositiveVoltageReference(pconfig->adc_positive_ref_voltage);			//Positive reference voltage selection

	SetADCInterruptPriority(pconfig->adc_interrupt_priority);				//ADC interrupt priority

	SetADCStandbyMode();

	return error;
}



/* Function that checks or scans the parameters passed in the configuration register */
uint8_t ADCParamScanError(ADC_Config *pconfig)
{
	uint8_t error=NO_ERROR_ADC;

	if(pconfig->adc_trigger_mode == 1 || pconfig->adc_trigger_mode > HW_TRIG_WAIT) error |= ADC_TRIGGER_OUT_OF_BOUND;
	if(pconfig->adc_hw_trigger_select > HW_TRIG_NO_NOISE_FLTR) error |= ADC_HW_TRIGGER_OUT_OF_BOUND;
	if(pconfig->adc_positive_ref_voltage > INT_VOL_1_45) error |= ADC_POS_REF_OUT_OF_BOUND;
	if(pconfig->adc_interrupt_priority > LVL3) error |= ADC_INT_PRIORITY_OUT_OF_BOUND;
	if(pconfig->adc_adpc_value > MAX_ADPC_VALUE_FOR_THIS_APP) error |= ADC_ADPC_VALUE_OUT_OF_BOUND;

	return error;
}



/* Get the ADC Value of the channel passed */
uint16_t GetADCValue(uint8_t channel)
{
	uint16_t data=0;

	ADCSelectChannel(channel);				//Select the channel

	StartADCConversion();				//Start conversion

	while(!(IF1->IF & INT_IF1_ADIF_MASK));			//While ADIF is low

	IF1->IF &= ~INT_IF1_ADIF_MASK;			//Clear the IDIF

	data = ADCReadValue();			//Read the ADC register

	DisableADCConversion();			//Disable the conversion

	return data;
}


