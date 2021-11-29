#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "interruptconfig.h"

#define MODULUS_16																		0x0F

#define NO_ERROR_INTERRUPT																0x00
#define ERROR_IRQ_OUT_OF_BOUND															0x01


uint8_t EnableInterrupt(uint8_t iRQn);
uint8_t DisableInterrupt(uint8_t iRQn);
uint8_t EnableMultipleInterrupts(INTERRUPT_Config *pconfig);

__near IRF_Mask_Type *GetInterruptMaskRegister(uint8_t iRQn);

#endif
