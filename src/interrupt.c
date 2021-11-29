/*
 * interrupt.c
 *
 *  Created on: 07-Apr-2021
 *      Author: alarkm
 */

#include "interrupt.h"


/* Enable the requested interrupt */
uint8_t EnableInterrupt(uint8_t iRQn)
{
	uint8_t error = (iRQn > MAX_IRQn) ? ERROR_IRQ_OUT_OF_BOUND : NO_ERROR_INTERRUPT;		//Validation of IRQ number
	if(error) return error;

	__near IRF_Mask_Type *interrupt_mask = GetInterruptMaskRegister(iRQn);					//Get interrupt mask register

	interrupt_mask->MK &= ~(1 << (iRQn & MODULUS_16));										//Reset the interrupt mask

	return error;
}



/* Disables the requested interrupt */
uint8_t DisableInterrupt(uint8_t iRQn)
{
	uint8_t error = (iRQn > MAX_IRQn) ? ERROR_IRQ_OUT_OF_BOUND : NO_ERROR_INTERRUPT;		//Validation of IRQ number
	if(error) return error;

	__near IRF_Mask_Type *interrupt_mask = GetInterruptMaskRegister(iRQn);					//Get interrupt mask register

	interrupt_mask->MK |= (1 << (iRQn & MODULUS_16));										//Set the interrupt mask

	return error;
}



/* Function to configure multiple interrupts */
uint8_t EnableMultipleInterrupts(INTERRUPT_Config *pconfig)
{
	uint8_t error=0, idx=0;

	while(idx != pconfig->number_of_interrupts)
		error |= EnableInterrupt(pconfig->interrupts[idx++]);

	return error;
}




/* Returns the interrupt mask register as per the IRQ number */
__near IRF_Mask_Type *GetInterruptMaskRegister(uint8_t iRQn)
{
	__near IRF_Mask_Type *interrupt_mask;

	switch(iRQn >> 4)
	{
	case 0: interrupt_mask = MK0;
		break;

	case 1: interrupt_mask = MK1;
		break;

	case 2: interrupt_mask = MK2;
		break;

	case 3: interrupt_mask = MK3;
		break;

	default: break;
	}

	return interrupt_mask;
}
