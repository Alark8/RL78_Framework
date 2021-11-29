#include "fuelmanage.h"
#include "fuelcontrol.h"

static FuelInformation fuel_info;

void InitFuel(void)
{	
	/* Write the logic of collecting initial fuel level */
	
	fuel_info.to_be_displayed_fuel_status = NORMAL;
	fuel_info.to_be_displayed_bar_status = (uint8_t)BAR2;
	
	fuel_info.prev_fuel_status = fuel_info.to_be_displayed_fuel_status;
	fuel_info.prev_bar_status = fuel_info.to_be_displayed_bar_status;
	
	fuel_info.immediate_display_req = 1;
	
	DisplaySegments(&fuel_info);
}


void DisplayFuel(void)
{
	static uint8_t fuel_display_enable_counter=0;
	static uint32_t fuel_read_elapsed_time;
	
	float fuel_adc_value=0.0;
	/* Time Duration calculation with respect to system timer needs to be added */
	
	if(fuel_read_elapsed_time > FUEL_READ_INTERVAL)
	{
		++fuel_display_enable_counter;
		
		CaptureFuelADC(FUEL_ADC_CHANNEL, &fuel_adc_value);
		GetFuelDisplaySegments(fuel_adc_value, &fuel_info);
	}
	
	if(fuel_display_enable_counter >= FUEL_AVERAGE_SAMPLES)
	{
		DisplaySegments(&fuel_info);
		fuel_display_enable_counter = FUEL_AVERAGE_SAMPLES;
	}
}
