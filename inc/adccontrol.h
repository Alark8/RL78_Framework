#ifndef ADCCONTROL_H
#define ADCCONTROL_H

#include "adc.h"


#define MAX_ADC_CHANNEL_NUMBER							0x08
#define MAX_ADPC_VALUE_FOR_THIS_APP						0x0A

#define NO_ERROR_ADC									0x00
#define ADC_TRIGGER_OUT_OF_BOUND						0x01
#define ADC_HW_TRIGGER_OUT_OF_BOUND						0x02
#define ADC_POS_REF_OUT_OF_BOUND						0x04
#define ADC_INT_PRIORITY_OUT_OF_BOUND					0x08
#define ADC_CHANNEL_OUT_OF_BOUND						0x10
#define ADC_ADPC_VALUE_OUT_OF_BOUND						0x20

uint16_t GetADCValue(uint8_t channel);
uint8_t ADCInitialize(ADC_Config *pconfig);
uint8_t ADCParamScanError(ADC_Config *pconfig);

#endif
