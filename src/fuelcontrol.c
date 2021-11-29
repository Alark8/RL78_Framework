#include "fuelcontrol.h"
#include "utils.h"
#include <math.h>
#include "adc.h"

void CaptureFuelADC(uint8_t adc_channel, float *fuel_adc_value)
{
	static uint8_t fuel_data_logger_status;
	static DataSequence fuel_data;
	
	if(!fuel_data_logger_status)
	{
		fuel_data = GetDataMemory(FUEL_AVERAGE_SAMPLES);
		fuel_data_logger_status = 1;
	}
		
	//fuel_data.input = ADCRead(adc_channel);
	
	GetMovingAverage(&fuel_data);
	
	*fuel_adc_value = fuel_data.output * (ADC_CONVERSION_VOLTAGE/pow(2,ADC_RESOLUTION_BITS));
}


void GetFuelDisplaySegments(float fuel_adc_value, FuelInformation *fuel_info)
{
	static uint8_t confirm_change_counter;
	
	/* Write the code for selecting fuel status & fuel 
	   sub-status based on fuel adc value */
	
	fuel_info->current_fuel_status = NORMAL;
	fuel_info->current_bar_status = (uint8_t)BAR2;
	
	
	/* Capture the time instance when fuel changed and look for confirm change */
	
	if((fuel_info->current_fuel_status != fuel_info->prev_fuel_status) ||
	   (fuel_info->current_bar_status != fuel_info->prev_bar_status))
	{	
	   	confirm_change_counter = 0;
		fuel_info->fuel_change_instance = TIME_EXAMPLE;																			//time of first instance to be taken
		fuel_info->current_bar_status = (fuel_info->current_fuel_status != NORMAL) ? 1 : fuel_info->current_bar_status;
	}
	else if((fuel_info->current_fuel_status == fuel_info->prev_fuel_status) &&
		(fuel_info->prev_bar_status == fuel_info->current_bar_status))
	{
		++confirm_change_counter;
	}
	
	
	/* If fuel status has changed then update what is being displayed */
	
	if(confirm_change_counter == FUEL_CONFIRM_CHANGE_MAX)
	{
		confirm_change_counter = 0;
		
		if((fuel_info->current_fuel_status != fuel_info->to_be_displayed_fuel_status) ||
		(fuel_info->current_fuel_status == NORMAL))
		{
			fuel_info->to_be_displayed_bar_status = fuel_info->current_bar_status;
		}
		
		fuel_info->to_be_displayed_fuel_status = fuel_info->current_fuel_status;
	}
	
	
	/* Getting ready for new capture */
	
	fuel_info->prev_fuel_status = fuel_info->current_fuel_status;
	fuel_info->prev_bar_status = fuel_info->current_bar_status;
}


void DisplaySegments(FuelInformation *fuel_info)
{
	uint8_t status=0;
	int8_t steps=0;
	
	if(!fuel_info->immediate_display_req)
	{	

		/* Fuel Status is NORMAL and Fuel Bars counts to display is also same */
		if((fuel_info->to_be_displayed_fuel_status == fuel_info->displayed_fuel_status) && (fuel_info->to_be_displayed_fuel_status == NORMAL)
		&& (fuel_info->to_be_displayed_bar_status == fuel_info->displayed_bar_status))
		{
			++status;
		}

		/* Fuel Status is NORMAL and Fuel Bars counts to display is changed now */
		else if((fuel_info->to_be_displayed_fuel_status == fuel_info->displayed_fuel_status) && (fuel_info->to_be_displayed_fuel_status == NORMAL)
		&& (fuel_info->to_be_displayed_bar_status != fuel_info->displayed_bar_status))
		{
			steps = fuel_info->to_be_displayed_bar_status - fuel_info->displayed_bar_status; 
			steps = (steps < 0) ? steps++ : steps--;
			
			//if(time < response_time) ++status;
		}

		/* Fuel Status apart from NORMAL and is same which is to be displayed and currently displaying */
		else if((fuel_info->to_be_displayed_fuel_status == fuel_info->displayed_fuel_status) /* && (time < response_time) */)
		{
			++status;
		}

		/* Fuel Status changed from some other state to NORMAL state */
		else if((fuel_info->to_be_displayed_fuel_status != fuel_info->displayed_fuel_status) && (fuel_info->to_be_displayed_fuel_status == NORMAL))
		{
			steps = fuel_info->to_be_displayed_bar_status - 1;
			//if(time < response_time) ++status;
		}

		/* Fuel Status changed from some other state than NORMAL to any other state but not NORMAL */
		else if((fuel_info->to_be_displayed_fuel_status != fuel_info->displayed_fuel_status) /* && (time < response_time) */)
		{
			++status;
		}
		
		if(status) return;
		
		/* Clear the fuel bars */
	}
	
	switch(fuel_info->to_be_displayed_fuel_status)
	{
		case NORMAL:
			switch((FUEL_NORMAL_STATE)(fuel_info->to_be_displayed_bar_status - steps))
			{
				case BAR7: /* Display 7 bars */
				
				case BAR6: /* Display 6 bars */
				
				case BAR5: /* Display 5 bars */
				
				case BAR4: /* Display 4 bars */
				
				case BAR3: /* Display 3 bars */
				
				case BAR2: /* Display 2 bars */
				
				case BAR1: /* Display 1 bar */
				
				default: break;
			}
		break;
		
		case RESERVE:
			switch((FUEL_RESERVE_STATE)fuel_info->to_be_displayed_bar_status)
			{
				case BAR_BLINKING: /* Blinking Sequence to be added here */
				break;
				
				default: break;
			}
		break;
		
		case OPENCKT:
			switch((FUEL_OPENCKT_STATE)fuel_info->to_be_displayed_bar_status)
			{
				case SCR1_OC: /* Display Screen 1 */ ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR2_OC: /* Display Screen 2 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR3_OC: /* Display Screen 3 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR4_OC: /* Display Screen 4 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR5_OC: /* Display Screen 5 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR6_OC: /* Display Screen 6 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR7_OC: /* Display Screen 7 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR8_OC: /* Display Screen 8 */  fuel_info->to_be_displayed_bar_status = 1;
				break;
				
				default: break;
			}
		break;
		
		case SHORTCKT:
			switch((FUEL_SHORTCKT_STATE)fuel_info->to_be_displayed_bar_status)
			{
				case SCR1_SC: /* Display Screen 1 */ ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR2_SC: /* Display Screen 2 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR3_SC: /* Display Screen 3 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR4_SC: /* Display Screen 4 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR5_SC: /* Display Screen 5 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR6_SC: /* Display Screen 6 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR7_SC: /* Display Screen 7 */  ++fuel_info->to_be_displayed_bar_status;
				break;
				
				case SCR8_SC: /* Display Screen 8 */  fuel_info->to_be_displayed_bar_status = 1;
				break;
				
				default: break;
			}
		break;
	}
	
	fuel_info->immediate_display_req = 0;
	fuel_info->displayed_fuel_status = fuel_info->to_be_displayed_fuel_status;
	
	if(fuel_info->displayed_fuel_status == NORMAL)
	{
		fuel_info->displayed_bar_status = fuel_info->to_be_displayed_bar_status - steps;
	}
	else fuel_info->displayed_bar_status = fuel_info->to_be_displayed_bar_status;
}
