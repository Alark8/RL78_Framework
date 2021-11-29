#ifndef FUELCONTROL_H
#define FUELCONTROL_H

#include "config.h"

#define TIME_EXAMPLE						0xFF
#define FUEL_SEGMENT_RESPONSE_TIME			0x0F
#define FUEL_RESERVE_RESPONSE_TIME			0x0F
#define FUEL_OPENCKT_RESPONSE_TIME			0x05
#define FUEL_SHRTCKT_RESPONSE_TIME			0x05
#define FUEL_CONFIRM_CHANGE_MAX				0x14

typedef enum {NORMAL=1, RESERVE, OPENCKT, SHORTCKT} FUEL_STATE;

typedef enum {BAR_BLINKING=1} FUEL_RESERVE_STATE;

typedef enum {BAR1=1, BAR2, BAR3, BAR4, BAR5, BAR6, BAR7} FUEL_NORMAL_STATE;

typedef enum {SCR1_OC=1, SCR2_OC, SCR3_OC, SCR4_OC, SCR5_OC, SCR6_OC, SCR7_OC, SCR8_OC} FUEL_OPENCKT_STATE;

typedef enum {SCR1_SC=1, SCR2_SC, SCR3_SC, SCR4_SC, SCR5_SC, SCR6_SC, SCR7_SC, SCR8_SC} FUEL_SHORTCKT_STATE;


typedef struct{
	FUEL_STATE displayed_fuel_status;
	FUEL_STATE current_fuel_status;
	FUEL_STATE prev_fuel_status;
	FUEL_STATE to_be_displayed_fuel_status;
	uint32_t fuel_change_instance;
	uint32_t fuel_update_instance;
	uint8_t displayed_bar_status;
	uint8_t current_bar_status;
	uint8_t prev_bar_status;
	uint8_t to_be_displayed_bar_status;
	uint8_t immediate_display_req;
}FuelInformation;


void DisplaySegments(FuelInformation *fuel_info);
void CaptureFuelADC(uint8_t adc_channel, float *fuel_adc_value);
void GetFuelDisplaySegments(float fuel_adc_value, FuelInformation *fuel_info);

#endif
