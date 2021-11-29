#include "adc.h"


/* Read the ADC Value */
uint16_t ADCReadValue(void)
{
	return (ADCR >> 6);
}


/* Select the ADC channel */
void ADCSelectChannel(uint8_t channel)
{
	ADC0_CONFIG->ADS = 0x00;
	ADC0_CONFIG->ADS |= channel;
}


/* Init the ADC Clock */
void ADCClockInit(void)
{
	PER1 |= PER1_ADCEN_MASK;
}



/* De-Init the ADC Clock */
void ADCClockDeInit(void)
{
	PER1 &= ~PER1_ADCEN_MASK;
}



/* Set the LV Value of ADC  */
void SetADCLVValue(uint8_t value)
{
	ADC0_CONFIG->ADM0 &= ~ADC_ADM0_DV_MASK;
	ADC0_CONFIG->ADM0 |= ADC_ADM0_DV_VALUE(value);
}


/* Set the FR value of ADC */
void SetADCFRValue(uint8_t value)
{
	ADC0_CONFIG->ADM0 &= ~ADC_ADM0_FR_MASK;
	ADC0_CONFIG->ADM0 |= ADC_ADM0_FR_VALUE(value);
}



/* Set the ADC select mode */
void SetADCSelectMode(void)
{
	ADC0_CONFIG->ADM0 &= ~ADC_ADM0_ADMD_MASK;
}


/* Set the scan mode in ADC */
void SetADCScanMode(void)
{
	ADC0_CONFIG->ADM0 |= ADC_ADM0_ADMD_MASK;
}



/* Set the trigger mode of ADC */
void SetADCTriggerMode(ADC_TRIG value)
{
	ADC0_CONFIG->ADM1 &= ~ADC_ADM1_ADTMD_MASK;
	ADC0_CONFIG->ADM1 |= ADC_ADM1_ADTMD_VALUE(value);
}


/* Set ADC One Shot mode */
void SetADCOneShotMode(void)
{
	ADC0_CONFIG->ADM1 |= ADC_ADM1_ADSCM_MASK;
}



/* Set ADC sequential mode */
void SetADCSequentialMode(void)
{
	ADC0_CONFIG->ADM1 &= ~ADC_ADM1_ADSCM_MASK;
}


/* Set ADC HW Trigger select */
void SetADCHWTriggerSelect(ADC_HW_TRIG value)
{
	ADC0_CONFIG->ADM1 &= ~ADC_ADM1_ADTRS_MASK;
	ADC0_CONFIG->ADM1 |= ADC_ADM1_ADTRS_VALUE(value);
}


/* Set the ADC positive voltage reference */
void SetADCPositiveVoltageReference(ADC_POS_REF value)
{
	ADC0_CONFIG->ADM0 &= ~ADC_ADM0_ADCE_MASK;											//Disable the ADCE

	ADC1_CONFIG->ADM2 &= ~ADC_ADM2_ADREFP_MASK;
	ADC1_CONFIG->ADM2 |= ADC_ADM2_ADREFP_VALUE(value);
}


/* Set the ADC negative voltage (Vss) reference */
void SetADCVssNegativeReference(void)
{
	ADC1_CONFIG->ADM2 &= ~ADC_ADM2_ADREFM_MASK;
}


/* Set the ADC negative voltage (Vref) reference */
void SetADCVrefmNegativeReference(void)
{
	ADC1_CONFIG->ADM2 |= ADC_ADM2_ADREFM_MASK;
}


/* Set 10bit resolution */
void SetADC10bitResolution(void)
{
	ADC1_CONFIG->ADM2 &= ~ADC_ADM2_ADTYP_MASK;
}


/* Set 8bit resolution */
void SetADC8bitResolution(void)
{
	ADC1_CONFIG->ADM2 |= ADC_ADM2_ADTYP_MASK;
}


/* Set ADC interrupt Greater ADCR Setting */
void SetADCInterruptADCRGreater(void)
{
	ADC1_CONFIG->ADM2 &= ~ADC_ADM2_ADRCK_MASK;
}



/* Set ADC interrupt Lower ADCR Setting */
void SetADCInterruptADCRLower(void)
{
	ADC1_CONFIG->ADM2 |= ADC_ADM2_ADRCK_MASK;
}



/* ADC Snooze Mode Enable */
void EnableADCSnoozeMode(void)
{
	ADC1_CONFIG->ADM2 |= ADC_ADM2_AWC_MASK;
}



/* ADC Snooze Mode Disabled */
void DisableADCSnoozeMode(void)
{
	ADC1_CONFIG->ADM2 &= ~ADC_ADM2_AWC_MASK;
}



/* Setting up ADUL value */
void SetADCADULValue(uint8_t value)
{
	ADC1_CONFIG->ADUL = value;
}



/* Setting up ADLL value */
void SetADCADLLValue(uint8_t value)
{
	ADC1_CONFIG->ADLL = value;
}



/* Set ADC Standby mode */
void SetADCStandbyMode(void)
{
	ADC0_CONFIG->ADM0 |= ADC_ADM0_ADCE_MASK;
}



/* Clear ADC Standby Mode */
void ClearADCStandbyMode(void)
{
	ADC0_CONFIG->ADM0 &= ~ADC_ADM0_ADCE_MASK;
}



/* Set the ADPC value */
void SetADCADPCValue(uint8_t value)
{
	ADPC &= ~ADC_ADPC_MASK;
	ADPC |= value;
}



/* Enable ADC Conversion */
void EnableADCConversion(void)
{
	ADC0_CONFIG->ADM0 |= ADC_ADM0_ADCS_MASK;
}


/* Disable ADC Conversion */
void DisableADCConversion(void)
{
	ADC0_CONFIG->ADM0 &= ~ADC_ADM0_ADCS_MASK;
}



/* Start ADC conversion */
void StartADCConversion(void)
{
	ADC0_CONFIG->ADM0 |= ADC_ADM0_ADCS_MASK;															//Enable the ADC Conversion
	IF1->IF &= ~INT_IF1_ADIF_MASK;																		//Clear the ADIF interrupt request flag
}



/* Set ADC interrupt priority */
void SetADCInterruptPriority(uint8_t priority)
{
	PR01->PR &= ~INT_PR01_ADPR0_MASK;
	PR11->PR &= ~INT_PR11_ADPR1_MASK;
	PR01->PR |= (priority & 0x01) ? INT_PR01_ADPR0_MASK : 0;											//Set the priority bit 0
	PR11->PR |= (priority & 0x02) ? INT_PR11_ADPR1_MASK : 0;											//Set the priority bit 1
	//MK1->MK &= ~INT_MK1_ADMK_MASK;																		//Enable the interrupt
}



