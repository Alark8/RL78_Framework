#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include "rl78_d1a_head.h"				//Device header as per ARM

/* Various macros for driver */
#define CLOCK_FREQ_BOUNDARY																0x0A
#define PLL_ERROR_NULL																	0x00
#define PLL_INVALID_OSC_OR_FREQ_ERROR													0x01

/* M8 -> Multiplier by 8 (capped to 32 MHz)
 * M6 -> Multiplier by 6 (capped to 32 MHz)
 * These settings are to be done from Option Bytes, configuring them doesn't make any change */
typedef enum {M8, M6} PLL_MUL;

/* Fmain -> Main system clock
 * Fsub -> Sub System clock */
typedef enum {Fmain, Fsub} CPU_CLK;

/* INTERNAL -> Internal high speed OSC
 * EXTERNAL -> External OSC */
typedef enum {INTERNAL, EXTERNAL} FMAIN;


/* Various power modes of the clock */
typedef enum {LOW_PWR, NORMAL_PWR, ULTRA_LOW} CLK_PWR;


/* X1_OSC -> External Osc
 * EXT_IP -> Clock on an external pin
 * HIGH_SPEED_INT -> High Speed internal Osc
 * SUBSYSTEM -> Subsystem Osc */
typedef enum {X1_OSC, EXT_IP, HIGH_SPEED_INT, SUBSYSTEM} OSC_TYPE;

/* Just an enum for different OSC freq */
typedef enum {F4MHZ=11, F8MHZ=10, F16MHZ=9, F24MHZ=0, F32MHZ=8} OSC_FREQ;

/* Config structure for clock*/
typedef struct {
	OSC_TYPE main_osc_type;
	PLL_MUL pll_multiplier;
	CPU_CLK cpu_clk_select;
	CLK_PWR sub_clk_power_mode;
	INT_PRIORITY clm_interrupt_priority;
	OSC_FREQ oscillator_freq;
	uint16_t subsystem_osc_enabled			:1;				//True or False
	uint16_t pll_enabled					:1;				//True or False
	uint16_t osts_select					:3;				//Value from 0 to 7
	uint16_t ostc_value						:8;				//Computed automatically based on OSTS
	uint16_t lowspeed_osc_enable			:1;				//True or False
	uint16_t reserve						:2;
}CLK_Config;


CLK_Config DefaultClockSetting(void);			//Function to return the configuration structure

#endif
