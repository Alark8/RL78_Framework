#ifndef CLOCK_H
#define CLOCK_H

#include "clockconfig.h"

typedef struct {
	uint8_t cmc_reg;
	uint8_t csc_reg;
	uint8_t ckc_reg;
}CLK_Reg;

#pragma inline(DisablePLL)
#pragma inline(GetPLLLockStatus)
#pragma inline(SelectPeripheralClock)
#pragma inline(SelectMainSystemClock)
#pragma inline(GetPLLClockModeStatus)
#pragma inline(GetMainSystemClockStatus)
#pragma inline(GetPeripheralClockStatus)
#pragma inline(SetHighSpeedIntOscillatorFreq)
#pragma inline(EnableLowSpeedOscClock)
#pragma inline(DisableLowSpeedOscClock)

void DisablePLL(void);
void EnableLowSpeedOscClock(void);
void DisableLowSpeedOscClock(void);
void ClockInitialize(CLK_Config *config);
void SelectPeripheralClock(CPU_CLK fclock);
void DisableOscillator(OSC_TYPE oscillator);
void SelectMainSystemClock(FMAIN oscillator);
void SetCLMInterruptPriority(uint8_t priority);
void SetHighSpeedIntOscillatorFreq(OSC_FREQ freq);
void SetupOscillator(CLK_Config *config, CLK_Reg *reg);

uint8_t GetPLLLockStatus(void);
uint8_t GetPLLClockModeStatus(void);
uint8_t SetupPLL(CLK_Config *config);
uint8_t GetMainSystemClockStatus(void);
uint8_t GetPeripheralClockStatus(void);
uint8_t SetOSTSRegister(uint8_t osts_value);
uint8_t CalculateOSTCValue(uint8_t osts_val);
uint8_t SetupSubSystemOscillatorPower(CLK_PWR oscillator_power);
uint8_t EnableOscillator(OSC_TYPE oscillator, uint8_t osts_value);

#endif
