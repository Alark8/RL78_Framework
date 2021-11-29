#ifndef EEPROM_H
#define EEPROM_H

#include "fdl.h"
#include "eel.h"


/* Dummy data structure */
typedef struct {
	eel_u16 tripA;
	eel_u16 tripB;
	eel_u32 odometer;
}DistanceDetails;


/* specifies the number of abstract variables the EEL should handle           */
#define   EEL_VAR_NO                    1


void EEPROMExecuteCommand(eel_request_t *command_request);
void EEPROMInitialization(fdl_descriptor_t *fdl_descriptor, fdl_status_t *fdl_init_status, eel_status_t *eel_init_status);

fdl_descriptor_t DefaultFDLSetting(void);

#endif
