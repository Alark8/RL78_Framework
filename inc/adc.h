#ifndef ADC_H
#define ADC_H

#include "adcconfig.h"

#pragma inline(ADCClockInit)
#pragma inline(ADCClockDeInit)
#pragma inline(SetADCScanMode)
#pragma inline(SetADCSelectMode)
#pragma inline(SetADCOneShotMode)
#pragma inline(EnableADCConversion)
#pragma inline(EnableADCSnoozeMode)
#pragma inline(SetADC8bitResolution)
#pragma inline(DisableADCSnoozeMode)
#pragma inline(DisableADCCOnversion)
#pragma inline(SetADC10bitResolution)
#pragma inline(SetADCInterruptADCRLower)
#pragma inline(SetADCInterruptADCRGreater)
#pragma inline(SetADCVssNegativeReference)
#pragma inline(SetADCVrefmNegativeReference)


uint16_t ADCReadValue(void);


void ADCClockInit(void);
void ADCClockDeInit(void);
void SetADCScanMode(void);
void SetADCSelectMode(void);
void SetADCOneShotMode(void);
void SetADCStandbyMode(void);
void StartADCConversion(void);
void ClearADCStandbyMode(void);
void EnableADCConversion(void);
void EnableADCSnoozeMode(void);
void DisableADCConversion(void);
void SetADC8bitResolution(void);
void DisableADCSnoozeMode(void);
void SetADCSequentialMode(void);
void SetADC10bitResolution(void);
void SetADCLVValue(uint8_t value);
void SetADCFRValue(uint8_t value);
void SetADCADULValue(uint8_t value);
void SetADCADLLValue(uint8_t value);
void SetADCADPCValue(uint8_t value);
void SetADCInterruptADCRLower(void);
void SetADCADPCValue(uint8_t value);
void SetADCInterruptADCRGreater(void);
void SetADCVssNegativeReference(void);
void SetADCTriggerMode(ADC_TRIG value);
void ADCSelectChannel(uint8_t channel);
void SetADCVrefmNegativeReference(void);
void SetADCHWTriggerSelect(ADC_HW_TRIG value);
void SetADCInterruptPriority(uint8_t priority);
void SetADCPositiveVoltageReference(ADC_POS_REF value);

#endif
