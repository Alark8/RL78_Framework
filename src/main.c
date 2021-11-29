/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c                                                */
/*  DATE        :                                                      */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
#include "main.h"

static eel_request_t command_request;											//command request structure for EEPROM operation

void main(void)
{
	uint8_t error=0;
	static DistanceDetails distance = {12, 20, 1000};		//Dummy data
	fdl_status_t fdl_init_status = FDL_ERR_PARAMETER;		//status init of FDL
	eel_status_t eel_init_status = EEL_ERR_PARAMETER;		//status init of EEL

	__EI();					//Enable global interrupts

	GPIOInitialize();		//Initialize GPIOs used


	/* You need to get the settings of the peripheral/system and then initialize it, you can modify these settings in config file of each system/peripheral */
	CLK_Config clock_config = DefaultClockSetting();				//Get default clock settings
	INTERVALTIMER_Config systick_config = DefaultIntervalTimerSetting();			//Get default interval timer settings
	ADC_Config adc_config = DefaultADCSetting();			//Get default ADC settings
	LCD_Config lcd_config = DefaultLCDSetting();			//Get default LCD settings
	INTERRUPT_Config interrupt_config = DefaultInterruptSetting();			//Get default interrupt settings
	fdl_descriptor_t fdl_config = DefaultFDLSetting();			//Get default FDL settings

	/* Initialize the peripheral
	 * 1. Clock
	 * 2. Interval Timer
	 * 3. LCD
	 * 4. ADC
	 * 5. Interrupts*/
	ClockInitialize(&clock_config);		//Clock
	error = IntervalTimerInitialize(&systick_config);		//Interval Timer
	error |= LCDInitialize(&lcd_config);		//LCD
	error |= ADCInitialize(&adc_config);		//ADC
	error |= EnableMultipleInterrupts(&interrupt_config);		//Interrupts

	EEPROMInitialization(&fdl_config, &fdl_init_status, &eel_init_status);			//EEPROM Initialization
	if(fdl_init_status != FDL_OK || eel_init_status != EEL_OK) DummyFunction();		//If error in initialising the FDL and EDL then go to dummy function
	DFLCTL |= DFLCTL_DFLEN_MASK;					//Enable DFLCTL

	DisplayAlwaysOnSegments();			//Display always on segment (respective to project)
	DisplaySpeed(0);					//Display speed as 0
	DisplayBTCalling(ON);				//Display BT Calling segment
	DisplayBTMissedMessage(ON);			//Display BT Missed message segment
	DisplayBTMissedCall(ON);			//Display BT Missed call segment
	DisplayBTConnected(ON);				//Display BT Connection segment
	DisplayFuelLevel(ON, SEG1);			//Display Fuel Level segment
	DisplayBTBatteryStatus(ON, PERCENT75);			//Display smartphone battery segment
	DisplayOdo(0);						//Display Odo as 0
	DisplayOdoString(ON);				//Display Odo string
	DisplayDefaultRTMi();				//Display default "--.-" RTMi display

	/* Populate the command request for EEPROM emulation operation */
	command_request.address_pu08 = (eel_u08 *)&distance;		//data
	command_request.command_enu = EEL_CMD_WRITE;				//command
	command_request.identifier_u08 = 1;							//identifier
	command_request.status_enu = EEL_ERR_PARAMETER;				//initial status

	EEPROMExecuteCommand(&command_request);				//Execute EEPROM command

	while(1)
	{
		ManageSystem();				//Manage system actions in a superloop
	}
}


/* Initialize all the GPIOs that are going be to be used by the system */
void GPIOInitialize(void)
{
	uint8_t error=0;

	/* gpio_config_data should contain gpio_number, direction */
	uint8_t gpio_config_data[][2] = {{LOW_FUEL_TT, OUTPUT},
								     {SIDE_STAND_TT, OUTPUT},
								     {LCD_ILL_OUT, OUTPUT},
								     {POSITIVE_REFERENCE, INPUT},
								     {NEGATIVE_REFERENCE, INPUT},
								     {SIDE_STAND_IP, INPUT},
								     {FUEL_MONITOR_IP, INPUT},
								     {FUEL_RESISTANCE_IP, INPUT}};

	/* gpio_set_data should contain gpio_number, logic_level */
	uint8_t gpio_set_data[][2] = {{LOW_FUEL_TT, HIGH},
								  {SIDE_STAND_TT, HIGH},
								  {LCD_ILL_OUT, HIGH}};

	/* Config Multiple GPIOs by passing the gpio_config_data and the size of it */
	error |= GpioConfigMultiple(gpio_config_data, (sizeof(gpio_config_data)/sizeof(gpio_config_data[0])));

	/* Set Multiple GPIOs by passing the gpio_set_data and the size of it */
	error |= GpioSetMultiple(gpio_set_data, (sizeof(gpio_set_data)/sizeof(gpio_set_data[0])));
}



/* Just a dummy function where you can actually manage all system tasks as per the timing requirement */
void ManageSystem(void)
{
	static uint32_t reference_time, eeprom_ref_time;			//Variable storing time information
	static uint16_t fuel_val=0;
	static DistanceDetails readDistance = {0, 0, 0};			//Read variable from EEPROM

	if(ElapsedTimeDuration(reference_time) > 500)				//At every 500ms
	{
		reference_time = msTicks;			//Refresh the time

		fuel_val = GetADCValue(FUEL_RESISTANCE_ANALOG_CH);		//Get the Fuel ADC Value
		fuel_val = (fuel_val) ? fuel_val+1 : fuel_val;

		if(command_request.status_enu == EEL_OK)			//Check for the command status of EEPROM
		{
			command_request.address_pu08 = (eel_u08 *)&readDistance;		//Load the read variable
			command_request.command_enu = EEL_CMD_READ;						//Read command
			command_request.identifier_u08 = 1;								//Identifier
			command_request.status_enu = EEL_ERR_PARAMETER;					//Initial status

			EEPROMExecuteCommand(&command_request);			//Execute EEPROM command
		}

		GpioToggle(LOW_FUEL_TT);			//Toggle the GPIO
		GpioToggle(SIDE_STAND_TT);			//Toggle the GPIO
	}

	if(ElapsedTimeDuration(eeprom_ref_time) > 10)				//At every 10ms
	{
		if(command_request.status_enu == EEL_BUSY)
		{
			EEL_Handler();			//Call the EEPROM handler for resume operations
		}
	}
}



/* Just a dummy function */
void DummyFunction(void)
{
	GpioToggle(SIDE_STAND_TT);
}






