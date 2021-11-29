/*
 * eeprom.c
 *
 *  Created on: 14-May-2021
 *      Author: alarkm
 */

#include "eeprom.h"



/*********************************************************************************************************/
/*******                                                                                           *******/
/*******      B E G I N    O F    C U S T O M I Z A B L E    D E C L A R A T I O N    A R E A      *******/
/*******                                                                                           *******/
/*********************************************************************************************************/


__far const eel_u08 eel_descriptor[EEL_VAR_NO+2] =
{
  (eel_u08)(EEL_VAR_NO),      						/* variable count   */  \
  (eel_u08)(sizeof(DistanceDetails)),  				/* id=1             */  \
  (eel_u08)(0x00),            						/* zero terminator  */  \
};

/*********************************************************************************************************/
/*******                                                                                           *******/
/*******      E N D    O F    C U S T O M I Z A B L E    D E C L A R A T I O N    A R E A          *******/
/*******                                                                                           *******/
/*********************************************************************************************************/




/*********************************************************************************************************/
/*******                                                                                           *******/
/*******      B E G I N    O F    U N T O U C H A B L E     D E C L A R A T I O N    A R E A       *******/
/*******                                                                                           *******/
/*********************************************************************************************************/
__far const eel_u08   eel_internal_cfg_cau08[]     = {0x40};
/*********************************************************************************************************/
/*******                                                                                           *******/
/*******      E N D    O F    U N T O U C H A B L E     D E C L A R A T I O N    A R E A           *******/
/*******                                                                                           *******/
/*********************************************************************************************************/



/* Initialize the EEPROM as per the fdl_descriptor_t */
void EEPROMInitialization(fdl_descriptor_t *fdl_descriptor, fdl_status_t *fdl_init_status, eel_status_t *eel_init_status)
{
	eel_request_t eel_startup_request = {0, 0, EEL_CMD_STARTUP, EEL_ERR_PARAMETER};			//Load the EEL Startup command

	*fdl_init_status = FDL_Init(fdl_descriptor);				//FDL Initialization
	if(*fdl_init_status != FDL_OK) return;

	FDL_Open();					//Open the FDL

	*eel_init_status = EEL_Init();			//EEL Initialization
	if(*eel_init_status != EEL_OK) return;

	EEL_Open();					//Open the EEL

	EEL_Execute(&eel_startup_request);				//Execute the EEL Startup command

	while (eel_startup_request.status_enu == EEL_BUSY) EEL_Handler();				//Wait until the command is executed

	if(eel_startup_request.status_enu == EEL_ERR_POOL_INCONSISTENT)				//At startup, this error is received, so we have to format the EEL pool
	{
		eel_startup_request.command_enu = EEL_CMD_FORMAT;		//Format command
		EEL_Execute(&eel_startup_request);						//Execute the command

		while (eel_startup_request.status_enu == EEL_BUSY) EEL_Handler();			//Wait till format command is executed
	}

	*eel_init_status = eel_startup_request.status_enu;				//Update the initialize status
}



/* A Generic API for executing various commands related to EEPROM Emulation */
void EEPROMExecuteCommand(eel_request_t *command_request)
{
	if(command_request->command_enu > EEL_CMD_STARTUP)					//If command is other than startup or greater than that
	{
		if(command_request->command_enu == EEL_CMD_WRITE)				//If Write Command is there
		{
			eel_u16 space_left=0;
			eel_status_t eel_get_space_status = EEL_ERR_PARAMETER;

			eel_get_space_status = EEL_GetSpace(&space_left);			//Get the space left and look for error

			if((eel_get_space_status != EEL_OK) || (space_left < sizeof(DistanceDetails) + 2)) 		//If error is there or space is less compared to dummy data structure
			{
				command_request->status_enu = EEL_ERR_POOL_FULL;			//status = POOL_FULL error
				return;
			}
			else				//Else proceed to write data into EEPROM
			{
				command_request->status_enu = EEL_ERR_PARAMETER;			//Status = ERROR so that we can scan for error = ERR_OK
				EEL_Execute(command_request);
			}
		}
		else				//Else proceed to execute other commands
		{
			command_request->status_enu = EEL_ERR_PARAMETER;			//status = ERROR
			EEL_Execute(command_request);			//Execute the command
		}
	}
}


/* Can read fdl_descriptor_t for better understanding, configure it accordingly */
fdl_descriptor_t DefaultFDLSetting(void)
{
	fdl_descriptor_t fdl_config;

	fdl_config.eel_pool_blocks_u08 = 5;							//5 blocks each of 1kb capacity
	fdl_config.fdl_pool_blocks_u08 = 3;							//3 blocks each of 1kb capacity
	fdl_config.eel_pool_bytes_u16 = 5120;						//5 x 1024 bytes
	fdl_config.fdl_pool_bytes_u16 = 3072;						//3 x 1024 bytes
	fdl_config.fdl_delay_u16 = 0;								//Unable to get detail about this
	fdl_config.fx_MHz_u08 = 4;									//4MHz frequency of our system
	fdl_config.wide_voltage_mode_u08 = 0;						//Full Voltage Mode (as per datasheet)

	return fdl_config;
}
