/*
** #######################################################################################################
**     Compilers:           ARM Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          GNU C Compiler - CodeSourcery Sourcery G++
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    RL78UserGuide_Hardware.pdf
**     Version:             rev. 3.20, 01-07-2014
**
**     Abstract:
**         Renesas Peripheral Access Layer for G13 Family
**     
**	   Author: Alark Mishra
**
**     Copyright: NCVE. All Rights Reserved.
**
**     Revisions:
**     - rev. 1.0 (2013-07-30)
**         Initial version.
**     
**		This revision is a complete access layer of Renesas G13 microcontroller family.
** #######################################################################################################
*/


#ifndef RL78_D1A_HEAD_H
#define RL78_D1A_HEAD_H

#include "config.h"


/* --------------------------------------------------------------- Port Configuration Handlers ----------------------------------------------------------- */

/* Pull-up Resistor Option Register Definition */
typedef struct {
	volatile uint8_t PU0;
	volatile uint8_t PU1;
	volatile uint8_t BL1;
	volatile uint8_t PU3;
	volatile uint8_t PU4;
	volatile uint8_t PU5;
	volatile uint8_t PU6;
	volatile uint8_t PU7;
	volatile uint8_t PU8;
	volatile uint8_t PU9;
	volatile uint8_t PU10;
	volatile uint8_t PU11;
	volatile uint8_t PU12;
	volatile uint8_t PU13;
	volatile uint8_t PU14;
}PUR_Type, *PUR_MemMapPtr;


#define PULL_UP_RESISTOR_BASE												   															(0x0030)
#define PUR															 			 					  ((__near PUR_Type *)PULL_UP_RESISTOR_BASE)


/* Port Input Mode Register Definition */
typedef struct {
	volatile uint8_t PIM0;
	volatile uint8_t PIM1;
	volatile uint8_t BL1;
	volatile uint8_t PIM3;
	volatile uint8_t BL2;
	volatile uint8_t PIM5;
	volatile uint8_t PIM6;
	volatile uint8_t PIM7;
	volatile uint8_t BL3[3];
	volatile uint8_t PIM11;
	volatile uint8_t BL4;
	volatile uint8_t PIM13;
}PIM_Type, *PIM_MemMapPtr;


#define PORT_INPUT_MODE_REGISTER_BASE	   					    					   												    (0x0040)
#define PIM									 							 					  ((__near PIM_Type *)PORT_INPUT_MODE_REGISTER_BASE)



/* LCD Port Function Register Definition */
typedef struct {
	volatile uint8_t LCDPF0;
	volatile uint8_t LCDPF1;
	volatile uint8_t BL1;
	volatile uint8_t LCDPF3;
	volatile uint8_t LCDPF4;
	volatile uint8_t LCDPF5;
	volatile uint8_t BL2;
	volatile uint8_t LCDPF7;
	volatile uint8_t LCDPF8;
	volatile uint8_t LCDPF9;
	volatile uint8_t LCDPF10;
	volatile uint8_t LCDPF11;
	volatile uint8_t LCDPF12;
	volatile uint8_t LCDPF13;
}LCDPF_Type, *POM_MemMapPtr;


#define LCD_PORT_FUNCTION_REGISTER_BASE							                                   										(0x0050)
#define LCDPF									       									  ((__near LCDPF_Type *)LCD_PORT_FUNCTION_REGISTER_BASE)



/* Port Register Definition */
typedef struct {
	volatile uint8_t P0;
	volatile uint8_t P1;
	volatile uint8_t P2;
	volatile uint8_t P3;
	volatile uint8_t P4;
	volatile uint8_t P5;
	volatile uint8_t P6;
	volatile uint8_t P7;
	volatile uint8_t P8;
	volatile uint8_t P9;
	volatile uint8_t P10;
	volatile uint8_t P11;
	volatile uint8_t P12;
	volatile uint8_t P13;
	volatile uint8_t P14;
	volatile uint8_t P15;
} PORT_Type, *PORT_MemMapPtr;


#define PORT_REGISTER_BASE												   																(0xFF00)
#define PORT											  						   						((__near PORT_Type *)PORT_REGISTER_BASE)


/* Port Mode Register Definition */
typedef struct {
	volatile uint8_t PM0;
	volatile uint8_t PM1;
	volatile uint8_t PM2;
	volatile uint8_t PM3;
	volatile uint8_t PM4;
	volatile uint8_t PM5;
	volatile uint8_t PM6;
	volatile uint8_t PM7;
	volatile uint8_t PM8;
	volatile uint8_t PM9;
	volatile uint8_t PM10;
	volatile uint8_t PM11;
	volatile uint8_t PM12;
	volatile uint8_t PM13;
	volatile uint8_t PM14;
	volatile uint8_t PM15;
}PMR_Type, *PMR_MemMapPtr;


#define PORT_MODE_REGISTER_BASE												   															(0xFF20)
#define PMR										      						   						((__near PMR_Type *)PORT_MODE_REGISTER_BASE)



#define PERIPHERAL_ENABLE_REGISTER_0_BASE																								(0x00F0)
#define PER0																	 *((__near volatile uint8_t *)PERIPHERAL_ENABLE_REGISTER_0_BASE)

/* PER0 Bit Fields */
#define PER0_TAU0EN_SHIFT																													   0
#define PER0_TAU0EN_MASK																													0x01
#define PER0_TAU1EN_SHIFT																													   1
#define PER0_TAU1EN_MASK																													0x02
#define PER0_TAU2EN_SHIFT																													   2
#define PER0_TAU2EN_MASK																													0x04
#define PER0_SAU0EN_SHIFT																													   3
#define PER0_SAU0EN_MASK																													0x08
#define PER0_SAU1EN_SHIFT																													   4
#define PER0_SAU1EN_MASK																													0x10
#define PER0_LIN0EN_SHIFT																													   5
#define PER0_LIN0EN_MASK																													0x20
#define PER0_LIN1EN_SHIFT																													   6
#define PER0_LIN1EN_MASK																													0x40
#define PER0_RTCEN_SHIFT																													   7
#define PER0_RTCEN_MASK																														0x80




#define PERIPHERAL_ENABLE_REGISTER_1_BASE																								(0x00F1)
#define PER1																	 *((__near volatile uint8_t *)PERIPHERAL_ENABLE_REGISTER_1_BASE)

/* PER1 Bit Fields */
#define PER1_LBEN_SHIFT																														   3
#define PER1_LBEN_MASK																														0x08
#define PER1_SGEN_SHIFT																														   4
#define PER1_SGEN_MASK																														0x10
#define PER1_MTRCEN_SHIFT																													   5
#define PER1_MTRCEN_MASK																													0x20
#define PER1_ADCEN_SHIFT																													   7
#define PER1_ADCEN_MASK																														0x80




#define PORT_OUTPUT_MODE_REGISTER_BASE																									(0x006F)
#define POM																			*((__near volatile uint8_t *)PORT_OUTPUT_MODE_REGISTER_BASE)

#define GLOBAL_DIGITAL_INPUT_DISABLE_REGISTER_BASE									   													(0x007D)
#define GLOBAL_DIGITAL_INPUT_DISABLE_REGISTER			  				*((__near volatile uint8_t *)GLOBAL_DIGITAL_INPUT_DISABLE_REGISTER_BASE)

/* --------------------------------------------------------------- Port Configuration Handlers ----------------------------------------------------------- */












/* ------------------------------------------------------------ Timer Configuration Handlers ------------------------------------------------------------ */

#define TIMER_DATA_REGISTER_00_BASE											   														   	(0xFF18)
#define TDR00										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_00_BASE)

#define TIMER_DATA_REGISTER_01_BASE											   														   	(0xFF1A)
#define TDR01										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_01_BASE)

#define TIMER_DATA_REGISTER_02_BASE											   														  	(0xFF64)
#define TDR02										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_02_BASE)

#define TIMER_DATA_REGISTER_03_BASE											   														   	(0xFF66)
#define TDR03										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_03_BASE)

#define TIMER_DATA_REGISTER_04_BASE											   														   	(0xFF68)
#define TDR04										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_04_BASE)

#define TIMER_DATA_REGISTER_05_BASE											   														   	(0xFF6A)
#define TDR05										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_05_BASE)

#define TIMER_DATA_REGISTER_06_BASE											   														   	(0xFF6C)
#define TDR06										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_06_BASE)

#define TIMER_DATA_REGISTER_07_BASE											   														   	(0xFF6E)
#define TDR07										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_07_BASE)

#define TIMER_DATA_REGISTER_10_BASE											   														   	(0xFF70)
#define TDR10										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_10_BASE)

#define TIMER_DATA_REGISTER_11_BASE											   														   	(0xFF72)
#define TDR11										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_11_BASE)

#define TIMER_DATA_REGISTER_12_BASE											   														   	(0xFF74)
#define TDR12										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_12_BASE)

#define TIMER_DATA_REGISTER_13_BASE											   														   	(0xFF76)
#define TDR13										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_13_BASE)

#define TIMER_DATA_REGISTER_14_BASE											   														   	(0xFF78)
#define TDR14										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_14_BASE)

#define TIMER_DATA_REGISTER_15_BASE											   														   	(0xFF7A)
#define TDR15										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_15_BASE)

#define TIMER_DATA_REGISTER_16_BASE											   														   	(0xFF7C)
#define TDR16										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_16_BASE)

#define TIMER_DATA_REGISTER_17_BASE											   														   	(0xFF7E)
#define TDR17										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_17_BASE)

#define TIMER_DATA_REGISTER_20_BASE											   														   	(0xFF90)
#define TDR20										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_20_BASE)

#define TIMER_DATA_REGISTER_21_BASE											   														   	(0xFF92)
#define TDR21										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_21_BASE)

#define TIMER_DATA_REGISTER_22_BASE											   														   	(0xFF94)
#define TDR22										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_22_BASE)

#define TIMER_DATA_REGISTER_23_BASE											   														   	(0xFF96)
#define TDR23										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_23_BASE)

#define TIMER_DATA_REGISTER_24_BASE											   														   	(0xFF98)
#define TDR24										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_24_BASE)

#define TIMER_DATA_REGISTER_25_BASE											   														   	(0xFF9A)
#define TDR25										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_25_BASE)

#define TIMER_DATA_REGISTER_26_BASE											   														   	(0xFF9C)
#define TDR26										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_26_BASE)

#define TIMER_DATA_REGISTER_27_BASE											   														   	(0xFF9E)
#define TDR27										  								  *((__near volatile uint16_t *)TIMER_DATA_REGISTER_27_BASE)



/* Timer Configuration Register Definition */
typedef struct {
	volatile uint8_t TNFEN;
	volatile uint8_t TNFSMP;
	volatile uint8_t TNFCS;
}NoiseFilter_Config_Type, *NoiseFilter_Config_MemMapPtr;


#define TIMER_CONFIG_0_REGISTER_BASE										 	   														(0x0060)
#define NOISE_FILTER_CONFIG0								    				((__near NoiseFilter_Config_Type *)TIMER_CONFIG_0_REGISTER_BASE)

#define TIMER_CONFIG_1_REGISTER_BASE										 	   													   	(0x0064)
#define NOISE_FILTER_CONFIG1								    				((__near NoiseFilter_Config_Type *)TIMER_CONFIG_1_REGISTER_BASE)

#define TIMER_CONFIG_2_REGISTER_BASE										 	   													   	(0x0068)
#define NOISE_FILTER_CONFIG2								    				((__near NoiseFilter_Config_Type *)TIMER_CONFIG_2_REGISTER_BASE)



/* TNFEN Bit Fields */
#define TIMER_TNFEN_TNFEN0_SHIFT																											   0
#define TIMER_TNFEN_TNFEN0_MASK																												0x01
#define TIMER_TNFEN_TNFEN1_SHIFT																											   1
#define TIMER_TNFEN_TNFEN1_MASK																												0x02
#define TIMER_TNFEN_TNFEN2_SHIFT																											   2
#define TIMER_TNFEN_TNFEN2_MASK																												0x04
#define TIMER_TNFEN_TNFEN3_SHIFT																											   3
#define TIMER_TNFEN_TNFEN3_MASK																												0x08
#define TIMER_TNFEN_TNFEN4_SHIFT																											   4
#define TIMER_TNFEN_TNFEN4_MASK																												0x10
#define TIMER_TNFEN_TNFEN5_SHIFT																											   5
#define TIMER_TNFEN_TNFEN5_MASK																												0x20
#define TIMER_TNFEN_TNFEN6_SHIFT																											   6
#define TIMER_TNFEN_TNFEN6_MASK																												0x40
#define TIMER_TNFEN_TNFEN7_SHIFT																											   7
#define TIMER_TNFEN_TNFEN7_MASK																												0x80



/* TNFSMP Bit Fields */
#define TIMER_TNFSMP_TNFSMP00_SHIFT																											   0
#define TIMER_TNFSMP_TNFSMP00_MASK																											0x0F
#define TIMER_TNFSMP_TNFSMP00_VALUE(x)					   (((uint8_t)(((uint8_t)(x))<<TIMER_TNFSMP_TNFSMP00_SHIFT))&TIMER_TNFSMP_TNFSMP00_MASK)
#define TIMER_TNFSMP_TNFSMP10_SHIFT																											   4
#define TIMER_TNFSMP_TNFSMP10_MASK																											0xF0
#define TIMER_TNFSMP_TNFSMP10_VALUE(x)					   (((uint8_t)(((uint8_t)(x))<<TIMER_TNFSMP_TNFSMP10_SHIFT))&TIMER_TNFSMP_TNFSMP10_MASK)



/* TNFCS Bit Fields */
#define TIMER_TNFCS_TNFCS0_SHIFT																											   0
#define TIMER_TNFCS_TNFCS0_MASK																												0x01
#define TIMER_TNFCS_TNFCS1_SHIFT																											   1
#define TIMER_TNFCS_TNFCS1_MASK																												0x02
#define TIMER_TNFCS_TNFCS2_SHIFT																											   2
#define TIMER_TNFCS_TNFCS2_MASK																												0x04
#define TIMER_TNFCS_TNFCS3_SHIFT																											   3
#define TIMER_TNFCS_TNFCS3_MASK																												0x08
#define TIMER_TNFCS_TNFCS4_SHIFT																											   4
#define TIMER_TNFCS_TNFCS4_MASK																												0x10
#define TIMER_TNFCS_TNFCS5_SHIFT																											   5
#define TIMER_TNFCS_TNFCS5_MASK																												0x20
#define TIMER_TNFCS_TNFCS6_SHIFT																											   6
#define TIMER_TNFCS_TNFCS6_MASK																												0x40
#define TIMER_TNFCS_TNFCS7_SHIFT																											   7
#define TIMER_TNFCS_TNFCS7_MASK																												0x80





/* Timer Information Register Definition */
typedef struct {
	volatile uint16_t TE;
	volatile uint16_t TS;
	volatile uint16_t TT;
	volatile uint16_t TPS;
	volatile uint16_t TO;
	volatile uint16_t TOE;
	volatile uint16_t TOL;
	volatile uint16_t TOM;
}TIMER_Type, *TIMER_MemMapPtr;


#define TIMER0_REGISTER_BASE												   														   	(0x01B0)
#define TIMER0										       											 ((__near TIMER_Type *)TIMER0_REGISTER_BASE)

#define TIMER1_REGISTER_BASE												   														   	(0x01F0)
#define TIMER1										       											 ((__near TIMER_Type *)TIMER1_REGISTER_BASE)

#define TIMER2_REGISTER_BASE												   														   	(0x0230)
#define TIMER2										       											 ((__near TIMER_Type *)TIMER2_REGISTER_BASE)


/* TE Bit Fields */
#define TIMER_TE_TE0_SHIFT																													   0
#define TIMER_TE_TE0_MASK																												  0x0001
#define TIMER_TE_TE1_SHIFT																													   1
#define TIMER_TE_TE1_MASK																												  0x0002
#define TIMER_TE_TE2_SHIFT																													   2
#define TIMER_TE_TE2_MASK																												  0x0004
#define TIMER_TE_TE3_SHIFT																													   3
#define TIMER_TE_TE3_MASK																												  0x0008
#define TIMER_TE_TE4_SHIFT																													   4
#define TIMER_TE_TE4_MASK																												  0x0010
#define TIMER_TE_TE5_SHIFT																													   5
#define TIMER_TE_TE5_MASK																												  0x0020
#define TIMER_TE_TE6_SHIFT																													   6
#define TIMER_TE_TE6_MASK																												  0x0040
#define TIMER_TE_TE7_SHIFT																													   7
#define TIMER_TE_TE7_MASK																												  0x0080


/* TS Bit Fields */
#define TIMER_TS_TS0_SHIFT																													   0
#define TIMER_TS_TS0_MASK																												  0x0001
#define TIMER_TS_TS1_SHIFT																													   1
#define TIMER_TS_TS1_MASK																												  0x0002
#define TIMER_TS_TS2_SHIFT																													   2
#define TIMER_TS_TS2_MASK																												  0x0004
#define TIMER_TS_TS3_SHIFT																													   3
#define TIMER_TS_TS3_MASK																												  0x0008
#define TIMER_TS_TS4_SHIFT																													   4
#define TIMER_TS_TS4_MASK																												  0x0010
#define TIMER_TS_TS5_SHIFT																													   5
#define TIMER_TS_TS5_MASK																												  0x0020
#define TIMER_TS_TS6_SHIFT																													   6
#define TIMER_TS_TS6_MASK																												  0x0040
#define TIMER_TS_TS7_SHIFT																													   7
#define TIMER_TS_TS7_MASK																												  0x0080


/* TT Bit Fields */
#define TIMER_TT_TT0_SHIFT																													   0
#define TIMER_TT_TT0_MASK																												  0x0001
#define TIMER_TT_TT1_SHIFT																													   1
#define TIMER_TT_TT1_MASK																												  0x0002
#define TIMER_TT_TT2_SHIFT																													   2
#define TIMER_TT_TT2_MASK																												  0x0004
#define TIMER_TT_TT3_SHIFT																													   3
#define TIMER_TT_TT3_MASK																												  0x0008
#define TIMER_TT_TT4_SHIFT																													   4
#define TIMER_TT_TT4_MASK																												  0x0010
#define TIMER_TT_TT5_SHIFT																													   5
#define TIMER_TT_TT5_MASK																												  0x0020
#define TIMER_TT_TT6_SHIFT																													   6
#define TIMER_TT_TT6_MASK																												  0x0040
#define TIMER_TT_TT7_SHIFT																													   7
#define TIMER_TT_TT7_MASK																												  0x0080


/* TPS Bit Fields */
#define TIMER_TPS_M00_SHIFT																													   0
#define TIMER_TPS_M00_MASK																												  0x000F
#define TIMER_TPS_M00_VALUE(x)											 (((uint16_t)(((uint16_t)(x))<<TIMER_TPS_M00_SHIFT))&TIMER_TPS_M00_MASK)
#define TIMER_TPS_M10_SHIFT																													   4
#define TIMER_TPS_M10_MASK																												  0x00F0
#define TIMER_TPS_M10_VALUE(x)											 (((uint16_t)(((uint16_t)(x))<<TIMER_TPS_M10_SHIFT))&TIMER_TPS_M10_MASK)
#define TIMER_TPS_M20_SHIFT																													   8
#define TIMER_TPS_M20_MASK																												  0x0F00
#define TIMER_TPS_M20_VALUE(x)											 (((uint16_t)(((uint16_t)(x))<<TIMER_TPS_M20_SHIFT))&TIMER_TPS_M20_MASK)
#define TIMER_TPS_M30_SHIFT																													  12
#define TIMER_TPS_M30_MASK																												  0xF000
#define TIMER_TPS_M30_VALUE(x)											 (((uint16_t)(((uint16_t)(x))<<TIMER_TPS_M30_SHIFT))&TIMER_TPS_M30_MASK)


/* TO Bit Fields */
#define TIMER_TO_TO0_SHIFT																													   0
#define TIMER_TO_TO0_MASK																												  0x0001
#define TIMER_TO_TO1_SHIFT																													   1
#define TIMER_TO_TO1_MASK																												  0x0002
#define TIMER_TO_TO2_SHIFT																													   2
#define TIMER_TO_TO2_MASK																												  0x0004
#define TIMER_TO_TO3_SHIFT																													   3
#define TIMER_TO_TO3_MASK																												  0x0008
#define TIMER_TO_TO4_SHIFT																													   4
#define TIMER_TO_TO4_MASK																												  0x0010
#define TIMER_TO_TO5_SHIFT																													   5
#define TIMER_TO_TO5_MASK																												  0x0020
#define TIMER_TO_TO6_SHIFT																													   6
#define TIMER_TO_TO6_MASK																												  0x0040
#define TIMER_TO_TO7_SHIFT																													   7
#define TIMER_TO_TO7_MASK																												  0x0080


/* TOE Bit Fields */
#define TIMER_TOE_TOE0_SHIFT																												   0
#define TIMER_TOE_TOE0_MASK																												  0x0001
#define TIMER_TOE_TOE1_SHIFT																												   1
#define TIMER_TOE_TOE1_MASK																												  0x0002
#define TIMER_TOE_TOE2_SHIFT																												   2
#define TIMER_TOE_TOE2_MASK																												  0x0004
#define TIMER_TOE_TOE3_SHIFT																												   3
#define TIMER_TOE_TOE3_MASK																												  0x0008
#define TIMER_TOE_TOE4_SHIFT																												   4
#define TIMER_TOE_TOE4_MASK																												  0x0010
#define TIMER_TOE_TOE5_SHIFT																												   5
#define TIMER_TOE_TOE5_MASK																												  0x0020
#define TIMER_TOE_TOE6_SHIFT																												   6
#define TIMER_TOE_TOE6_MASK																												  0x0040
#define TIMER_TOE_TOE7_SHIFT																												   7
#define TIMER_TOE_TOE7_MASK																												  0x0080


/* TOL Bit Fields */
#define TIMER_TOL_TOL0_SHIFT																												   0
#define TIMER_TOL_TOL0_MASK																												  0x0001
#define TIMER_TOL_TOL1_SHIFT																												   1
#define TIMER_TOL_TOL1_MASK																												  0x0002
#define TIMER_TOL_TOL2_SHIFT																												   2
#define TIMER_TOL_TOL2_MASK																												  0x0004
#define TIMER_TOL_TOL3_SHIFT																												   3
#define TIMER_TOL_TOL3_MASK																												  0x0008
#define TIMER_TOL_TOL4_SHIFT																												   4
#define TIMER_TOL_TOL4_MASK																												  0x0010
#define TIMER_TOL_TOL5_SHIFT																												   5
#define TIMER_TOL_TOL5_MASK																												  0x0020
#define TIMER_TOL_TOL6_SHIFT																												   6
#define TIMER_TOL_TOL6_MASK																												  0x0040
#define TIMER_TOL_TOL7_SHIFT																												   7
#define TIMER_TOL_TOL7_MASK																												  0x0080


/* TOM Bit Fields */
#define TIMER_TOM_TOM0_SHIFT																												   0
#define TIMER_TOM_TOM0_MASK																												  0x0001
#define TIMER_TOM_TOM1_SHIFT																												   1
#define TIMER_TOM_TOM1_MASK																												  0x0002
#define TIMER_TOM_TOM2_SHIFT																												   2
#define TIMER_TOM_TOM2_MASK																												  0x0004
#define TIMER_TOM_TOM3_SHIFT																												   3
#define TIMER_TOM_TOM3_MASK																												  0x0008
#define TIMER_TOM_TOM4_SHIFT																												   4
#define TIMER_TOM_TOM4_MASK																												  0x0010
#define TIMER_TOM_TOM5_SHIFT																												   5
#define TIMER_TOM_TOM5_MASK																												  0x0020
#define TIMER_TOM_TOM6_SHIFT																												   6
#define TIMER_TOM_TOM6_MASK																												  0x0040
#define TIMER_TOM_TOM7_SHIFT																												   7
#define TIMER_TOM_TOM7_MASK																												  0x0080




#define TIMER_COUNTER_REGISTER_00_BASE											   													   	(0x0180)
#define TCR00									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_00_BASE)

#define TIMER_COUNTER_REGISTER_01_BASE											   													   	(0x0182)
#define TCR01									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_01_BASE)

#define TIMER_COUNTER_REGISTER_02_BASE											   													   	(0x0184)
#define TCR02									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_02_BASE)

#define TIMER_COUNTER_REGISTER_03_BASE										           												   	(0x0186)
#define TCR03									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_03_BASE)

#define TIMER_COUNTER_REGISTER_04_BASE											   													   	(0x0188)
#define TCR04									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_04_BASE)

#define TIMER_COUNTER_REGISTER_05_BASE											   													   	(0x018A)
#define TCR05									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_05_BASE)

#define TIMER_COUNTER_REGISTER_06_BASE											   													   	(0x018C)
#define TCR06									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_06_BASE)

#define TIMER_COUNTER_REGISTER_07_BASE										           												   	(0x018E)
#define TCR07									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_07_BASE)

#define TIMER_COUNTER_REGISTER_10_BASE											   													   	(0x01C0)
#define TCR10									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_10_BASE)

#define TIMER_COUNTER_REGISTER_11_BASE											   													   	(0x01C2)
#define TCR11									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_11_BASE)

#define TIMER_COUNTER_REGISTER_12_BASE											   													   	(0x01C4)
#define TCR12									      							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_12_BASE)

#define TIMER_COUNTER_REGISTER_13_BASE											   													   	(0x01C6)
#define TCR13									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_13_BASE)

#define TIMER_COUNTER_REGISTER_14_BASE											   													   	(0x01C8)
#define TCR14									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_14_BASE)

#define TIMER_COUNTER_REGISTER_15_BASE											   													   	(0x01CA)
#define TCR15									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_15_BASE)

#define TIMER_COUNTER_REGISTER_16_BASE											   													   	(0x01CC)
#define TCR16									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_16_BASE)

#define TIMER_COUNTER_REGISTER_17_BASE											   													   	(0x01CE)
#define TCR17									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_17_BASE)

#define TIMER_COUNTER_REGISTER_20_BASE											   													   	(0x0200)
#define TCR20									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_20_BASE)

#define TIMER_COUNTER_REGISTER_21_BASE											   													   	(0x0202)
#define TCR21									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_21_BASE)

#define TIMER_COUNTER_REGISTER_22_BASE											   													   	(0x0204)
#define TCR22									      							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_22_BASE)

#define TIMER_COUNTER_REGISTER_23_BASE											   													   	(0x0206)
#define TCR23									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_23_BASE)

#define TIMER_COUNTER_REGISTER_24_BASE											   													   	(0x0208)
#define TCR24									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_24_BASE)

#define TIMER_COUNTER_REGISTER_25_BASE											   													   	(0x020A)
#define TCR25									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_25_BASE)

#define TIMER_COUNTER_REGISTER_26_BASE											   													   	(0x020C)
#define TCR26									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_26_BASE)

#define TIMER_COUNTER_REGISTER_27_BASE											   													   	(0x020E)
#define TCR27									       							   *((__near volatile uint16_t *)TIMER_COUNTER_REGISTER_27_BASE)





#define TIMER_MODE_REGISTER_00_BASE											   														    (0x0190)
#define TMR00										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_00_BASE)

#define TIMER_MODE_REGISTER_01_BASE											   														    (0x0192)
#define TMR01										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_01_BASE)

#define TIMER_MODE_REGISTER_02_BASE											   														    (0x0194)
#define TMR02										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_02_BASE)

#define TIMER_MODE_REGISTER_03_BASE											   														    (0x0196)
#define TMR03										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_03_BASE)

#define TIMER_MODE_REGISTER_04_BASE											   														    (0x0198)
#define TMR04										 								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_04_BASE)

#define TIMER_MODE_REGISTER_05_BASE											   														    (0x019A)
#define TMR05										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_05_BASE)

#define TIMER_MODE_REGISTER_06_BASE											   														    (0x019C)
#define TMR06										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_06_BASE)

#define TIMER_MODE_REGISTER_07_BASE											   														    (0x019E)
#define TMR07										   								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_07_BASE)

#define TIMER_MODE_REGISTER_10_BASE											  	 													    (0x01D0)
#define TMR10										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_10_BASE)

#define TIMER_MODE_REGISTER_11_BASE											   														    (0x01D2)
#define TMR11										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_11_BASE)

#define TIMER_MODE_REGISTER_12_BASE											   														    (0x01D4)
#define TMR12										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_12_BASE)

#define TIMER_MODE_REGISTER_13_BASE											   														    (0x01D6)
#define TMR13										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_13_BASE)

#define TIMER_MODE_REGISTER_14_BASE											   														    (0x01D8)
#define TMR14										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_14_BASE)

#define TIMER_MODE_REGISTER_15_BASE											   														    (0x01DA)
#define TMR15										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_15_BASE)

#define TIMER_MODE_REGISTER_16_BASE											   														    (0x01DC)
#define TMR16										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_16_BASE)

#define TIMER_MODE_REGISTER_17_BASE											   														    (0x01DE)
#define TMR17										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_17_BASE)

#define TIMER_MODE_REGISTER_20_BASE											  	 													    (0x0210)
#define TMR20										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_20_BASE)

#define TIMER_MODE_REGISTER_21_BASE											   														    (0x0212)
#define TMR21										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_21_BASE)

#define TIMER_MODE_REGISTER_22_BASE											   														    (0x0214)
#define TMR22										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_22_BASE)

#define TIMER_MODE_REGISTER_23_BASE											   														    (0x0216)
#define TMR23										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_23_BASE)

#define TIMER_MODE_REGISTER_24_BASE											   														    (0x0218)
#define TMR24										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_24_BASE)

#define TIMER_MODE_REGISTER_25_BASE											   														    (0x021A)
#define TMR25										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_25_BASE)

#define TIMER_MODE_REGISTER_26_BASE											   														    (0x021C)
#define TMR26										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_26_BASE)

#define TIMER_MODE_REGISTER_27_BASE											   														    (0x021E)
#define TMR27										  								  *((__near volatile uint16_t *)TIMER_MODE_REGISTER_27_BASE)


/* TMR Bit Fields */
#define TIMER_TMR_MD_SHIFT																													   0
#define TIMER_TMR_MD_MASK																												  0x0001
#define TIMER_TMR_MD_VALUE(x)											   (((uint16_t)(((uint16_t)(x))<<TIMER_TMR_MD_SHIFT))&TIMER_TMR_MD_MASK)
#define TIMER_TMR_CIS_SHIFT																													   6
#define TIMER_TMR_CIS_MASK																												  0x00C0
#define TIMER_TMR_CIS_VALUE(x)											 (((uint16_t)(((uint16_t)(x))<<TIMER_TMR_CIS_SHIFT))&TIMER_TMR_CIS_MASK)
#define TIMER_TMR_STS_SHIFT																													   8
#define TIMER_TMR_STS_MASK																												  0x0700
#define TIMER_TMR_STS_VALUE(x)											 (((uint16_t)(((uint16_t)(x))<<TIMER_TMR_STS_SHIFT))&TIMER_TMR_STS_MASK)
#define TIMER_TMR_MASTER_SHIFT																												  11
#define TIMER_TMR_MASTER_MASK																											  0x0800
#define TIMER_TMR_CCS_SHIFT																													  12
#define TIMER_TMR_CCS_MASK																												  0x1000
#define TIMER_TMR_CKS_SHIFT																													  14
#define TIMER_TMR_CKS_MASK																												  0xC000
#define TIMER_TMR_CKS_VALUE(x)											 (((uint16_t)(((uint16_t)(x))<<TIMER_TMR_CKS_SHIFT))&TIMER_TMR_CKS_MASK)




#define TIMER_STATUS_REGISTER_00_BASE											   													   	(0x01A0)
#define TSR00																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_00_BASE)

#define TIMER_STATUS_REGISTER_01_BASE											   													   	(0x01A2)
#define TSR01																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_01_BASE)

#define TIMER_STATUS_REGISTER_02_BASE											   													   	(0x01A4)
#define TSR02																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_02_BASE)

#define TIMER_STATUS_REGISTER_03_BASE											   													   	(0x01A6)
#define TSR03																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_03_BASE)

#define TIMER_STATUS_REGISTER_04_BASE											   													   	(0x01A8)
#define TSR04																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_04_BASE)

#define TIMER_STATUS_REGISTER_05_BASE											   													   	(0x01AA)
#define TSR05																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_05_BASE)

#define TIMER_STATUS_REGISTER_06_BASE											   													   	(0x01AC)
#define TSR06																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_06_BASE)

#define TIMER_STATUS_REGISTER_07_BASE											   													   	(0x01AE)
#define TSR07																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_07_BASE)

#define TIMER_STATUS_REGISTER_10_BASE											   													   	(0x01E0)
#define TSR10																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_10_BASE)

#define TIMER_STATUS_REGISTER_11_BASE											   													   	(0x01E2)
#define TSR11																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_11_BASE)

#define TIMER_STATUS_REGISTER_12_BASE											   													   	(0x01E4)
#define TSR12																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_12_BASE)

#define TIMER_STATUS_REGISTER_13_BASE											   													   	(0x01E6)
#define TSR13																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_13_BASE)

#define TIMER_STATUS_REGISTER_14_BASE											   													   	(0x01E8)
#define TSR14																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_14_BASE)

#define TIMER_STATUS_REGISTER_15_BASE											   													   	(0x01EA)
#define TSR15																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_15_BASE)

#define TIMER_STATUS_REGISTER_16_BASE											   													   	(0x01EC)
#define TSR16																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_16_BASE)

#define TIMER_STATUS_REGISTER_17_BASE											   													   	(0x01EE)
#define TSR17																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_17_BASE)

#define TIMER_STATUS_REGISTER_20_BASE											   													   	(0x0220)
#define TSR20																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_20_BASE)

#define TIMER_STATUS_REGISTER_21_BASE											   													   	(0x0222)
#define TSR21																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_21_BASE)

#define TIMER_STATUS_REGISTER_22_BASE											   													   	(0x0224)
#define TSR22																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_22_BASE)

#define TIMER_STATUS_REGISTER_23_BASE											   													   	(0x0226)
#define TSR23																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_23_BASE)

#define TIMER_STATUS_REGISTER_24_BASE											   													   	(0x0228)
#define TSR24																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_24_BASE)

#define TIMER_STATUS_REGISTER_25_BASE											   													   	(0x022A)
#define TSR25																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_25_BASE)

#define TIMER_STATUS_REGISTER_26_BASE											   													   	(0x022C)
#define TSR26																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_26_BASE)

#define TIMER_STATUS_REGISTER_27_BASE											   													   	(0x022E)
#define TSR27																		*((__near volatile uint16_t *)TIMER_STATUS_REGISTER_27_BASE)


/* TSR Bit Fields */
#define TIMER_TSR_OVF_SHIFT																													   0
#define TIMER_TSR_OVF_MASK																												  0x0001






#define TIMER_INPUT_SELECT_REGISTER_00_BASE																							   	(0x0070)
#define TIS00																   *((__near volatile uint8_t *)TIMER_INPUT_SELECT_REGISTER_00_BASE)

#define TIMER_INPUT_SELECT_REGISTER_01_BASE																							   	(0x0071)
#define TIS01																   *((__near volatile uint8_t *)TIMER_INPUT_SELECT_REGISTER_01_BASE)

#define TIMER_INPUT_SELECT_REGISTER_10_BASE																							   	(0x0072)
#define TIS10																   *((__near volatile uint8_t *)TIMER_INPUT_SELECT_REGISTER_10_BASE)

#define TIMER_INPUT_SELECT_REGISTER_11_BASE																							   	(0x0073)
#define TIS11																   *((__near volatile uint8_t *)TIMER_INPUT_SELECT_REGISTER_11_BASE)

#define TIMER_INPUT_SELECT_REGISTER_20_BASE																							   	(0x0074)
#define TIS20																   *((__near volatile uint8_t *)TIMER_INPUT_SELECT_REGISTER_20_BASE)

#define TIMER_INPUT_SELECT_REGISTER_21_BASE																							   	(0x0075)
#define TIS21																   *((__near volatile uint8_t *)TIMER_INPUT_SELECT_REGISTER_21_BASE)


/* TIS Bit Fields */
#define TIMER_TIS_TISm00_SHIFT																												   0
#define TIMER_TIS_TISm00_MASK																												0x03
#define TIMER_TIS_TISm00_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TIS_TISm00_SHIFT))&TIMER_TIS_TISm00_MASK)
#define TIMER_TIS_TISm10_SHIFT																												   2
#define TIMER_TIS_TISm10_MASK																												0x0C
#define TIMER_TIS_TISm10_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TIS_TISm10_SHIFT))&TIMER_TIS_TISm10_MASK)
#define TIMER_TIS_TISm20_SHIFT																												   4
#define TIMER_TIS_TISm20_MASK																												0x30
#define TIMER_TIS_TISm20_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TIS_TISm20_SHIFT))&TIMER_TIS_TISm20_MASK)
#define TIMER_TIS_TISm30_SHIFT																												   6
#define TIMER_TIS_TISm30_MASK																												0xC0
#define TIMER_TIS_TISm30_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TIS_TISm30_SHIFT))&TIMER_TIS_TISm30_MASK)
#define TIMER_TIS_TISm40_SHIFT																												   0
#define TIMER_TIS_TISm40_MASK																												0x03
#define TIMER_TIS_TISm40_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TIS_TISm40_SHIFT))&TIMER_TIS_TISm40_MASK)
#define TIMER_TIS_TISm50_SHIFT																												   2
#define TIMER_TIS_TISm50_MASK																												0x0C
#define TIMER_TIS_TISm50_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TIS_TISm50_SHIFT))&TIMER_TIS_TISm50_MASK)
#define TIMER_TIS_TISm60_SHIFT																												   4
#define TIMER_TIS_TISm60_MASK																												0x30
#define TIMER_TIS_TISm60_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TIS_TISm60_SHIFT))&TIMER_TIS_TISm60_MASK)
#define TIMER_TIS_TISm70_SHIFT																												   6
#define TIMER_TIS_TISm70_MASK																												0xC0
#define TIMER_TIS_TISm70_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TIS_TISm70_SHIFT))&TIMER_TIS_TISm70_MASK)





#define TIMER_OUTPUT_SELECT_REGISTER_00_BASE																						   	(0x0076)
#define TOS00																  *((__near volatile uint8_t *)TIMER_OUTPUT_SELECT_REGISTER_00_BASE)

#define TIMER_OUTPUT_SELECT_REGISTER_01_BASE																						   	(0x0077)
#define TOS01																  *((__near volatile uint8_t *)TIMER_OUTPUT_SELECT_REGISTER_01_BASE)

#define TIMER_OUTPUT_SELECT_REGISTER_10_BASE																						   	(0x0079)
#define TOS10																  *((__near volatile uint8_t *)TIMER_OUTPUT_SELECT_REGISTER_10_BASE)

#define TIMER_OUTPUT_SELECT_REGISTER_11_BASE																						   	(0x007A)
#define TOS11																  *((__near volatile uint8_t *)TIMER_OUTPUT_SELECT_REGISTER_11_BASE)

#define TIMER_OUTPUT_SELECT_REGISTER_20_BASE																						   	(0x007B)
#define TOS20																  *((__near volatile uint8_t *)TIMER_OUTPUT_SELECT_REGISTER_20_BASE)

#define TIMER_OUTPUT_SELECT_REGISTER_21_BASE																						   	(0x007C)
#define TOS21																  *((__near volatile uint8_t *)TIMER_OUTPUT_SELECT_REGISTER_21_BASE)


/* TOS Bit Fields */
#define TIMER_TOS_TOSm00_SHIFT																												   0
#define TIMER_TOS_TOSm00_MASK																												0x03
#define TIMER_TOS_TOSm00_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TOS_TOSm00_SHIFT))&TIMER_TOS_TOSm00_MASK)
#define TIMER_TOS_TOSm10_SHIFT																												   2
#define TIMER_TOS_TOSm10_MASK																												0x0C
#define TIMER_TOS_TOSm10_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TOS_TOSm10_SHIFT))&TIMER_TOS_TOSm10_MASK)
#define TIMER_TOS_TOSm20_SHIFT																												   4
#define TIMER_TOS_TOSm20_MASK																												0x30
#define TIMER_TOS_TOSm20_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TOS_TOSm20_SHIFT))&TIMER_TOS_TOSm20_MASK)
#define TIMER_TOS_TOSm30_SHIFT																												   6
#define TIMER_TOS_TOSm30_MASK																												0xC0
#define TIMER_TOS_TOSm30_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TOS_TOSm30_SHIFT))&TIMER_TOS_TOSm30_MASK)
#define TIMER_TOS_TOSm40_SHIFT																												   0
#define TIMER_TOS_TOSm40_MASK																												0x03
#define TIMER_TOS_TOSm40_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TOS_TOSm40_SHIFT))&TIMER_TOS_TOSm40_MASK)
#define TIMER_TOS_TOSm50_SHIFT																												   2
#define TIMER_TOS_TOSm50_MASK																												0x0C
#define TIMER_TOS_TOSm50_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TOS_TOSm50_SHIFT))&TIMER_TOS_TOSm50_MASK)
#define TIMER_TOS_TOSm60_SHIFT																												   4
#define TIMER_TOS_TOSm60_MASK																												0x30
#define TIMER_TOS_TOSm60_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TOS_TOSm60_SHIFT))&TIMER_TOS_TOSm60_MASK)
#define TIMER_TOS_TOSm70_SHIFT																												   6
#define TIMER_TOS_TOSm70_MASK																												0xC0
#define TIMER_TOS_TOSm70_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<TIMER_TOS_TOSm70_SHIFT))&TIMER_TOS_TOSm70_MASK)



#define INTERVAL_TIMER_CTRL_REGISTER_BASE					 					   													   	(0xFF50)
#define ITMC											   						*((__near volatile uint16_t *)INTERVAL_TIMER_CTRL_REGISTER_BASE)

/* ITMC Bit Fields */
#define TIMER_ITMC_ITMCMP_SHIFT																												   0
#define TIMER_ITMC_ITMCMP_MASK																											  0x7FFF
#define TIMER_ITMC_ITMCMP_VALUE(x)								 (((uint16_t)(((uint16_t)(x))<<TIMER_ITMC_ITMCMP_SHIFT))&TIMER_ITMC_ITMCMP_MASK)
#define TIMER_ITMC_RINTE_SHIFT																												  15
#define TIMER_ITMC_RINTE_MASK																											  0x8000

/* ------------------------------------------------------------ Timer Configuration Handlers ------------------------------------------------------------ */














/* -------------------------------------------------------------- ADC Configuration Handlers ------------------------------------------------------------ */


typedef struct
{
    unsigned char no0:1;
    unsigned char no1:1;
    unsigned char no2:1;
    unsigned char no3:1;
    unsigned char no4:1;
    unsigned char no5:1;
    unsigned char no6:1;
    unsigned char no7:1;
} __bitf_T;


/* ADC Config Register Definition */
typedef struct {
	volatile uint8_t ADM0;
	volatile uint8_t ADS;
	volatile uint8_t ADM1;
}ADC0_Config_Type, *ADC0_Config_MemMapPtr;


#define ADC0_CONFIGURATION_REGISTER_BASE										   													   	(0xFF30)
#define ADC0_CONFIG							     								   ((__near ADC0_Config_Type *)ADC0_CONFIGURATION_REGISTER_BASE)


/* ADM0 Bit Fields */
#define ADC_ADM0_ADCE_SHIFT																													   0
#define ADC_ADM0_ADCE_MASK																													0x01
#define ADC_ADM0_DV_SHIFT																													   1
#define ADC_ADM0_DV_MASK																													0x06
#define ADC_ADM0_DV_VALUE(x)												   (((uint8_t)(((uint8_t)(x))<<ADC_ADM0_DV_SHIFT))&ADC_ADM0_DV_MASK)
#define ADC_ADM0_FR_SHIFT																													   3
#define ADC_ADM0_FR_MASK																													0x38
#define ADC_ADM0_FR_VALUE(x)												   (((uint8_t)(((uint8_t)(x))<<ADC_ADM0_FR_SHIFT))&ADC_ADM0_FR_MASK)
#define ADC_ADM0_ADMD_SHIFT																													   6
#define ADC_ADM0_ADMD_MASK																													0x40
#define ADC_ADM0_ADCS_SHIFT																													   7
#define ADC_ADM0_ADCS_MASK																													0x80


/* ADS Bit Fields */
#define ADC_ADS_SHIFT																														   0
#define ADC_ADS_MASK																														0x0F
#define ADC_ADS_VALUE(x)															   (((uint8_t)(((uint8_t)(x))<<ADC_ADS_SHIFT))&ADC_ADS_MASK)


/* ADM1 Bit Fields */
#define ADC_ADM1_ADTRS_SHIFT																												   0
#define ADC_ADM1_ADTRS_MASK																													0x03
#define ADC_ADM1_ADTRS_VALUE(x)											 (((uint8_t)(((uint8_t)(x))<<ADC_ADM1_ADTRS_SHIFT))&ADC_ADM1_ADTRS_MASK)
#define ADC_ADM1_ADSCM_SHIFT																												   5
#define ADC_ADM1_ADSCM_MASK																													0x20
#define ADC_ADM1_ADTMD_SHIFT																												   6
#define ADC_ADM1_ADTMD_MASK																													0xC0
#define ADC_ADM1_ADTMD_VALUE(x)											 (((uint8_t)(((uint8_t)(x))<<ADC_ADM1_ADTMD_SHIFT))&ADC_ADM1_ADTMD_MASK)



#define ADCS         																				 (((volatile __near __bitf_T *)0xFF30)->no7)





/* ADC Config Register Definition */
typedef struct {
	volatile uint8_t ADM2;
	volatile uint8_t ADUL;
	volatile uint8_t ADLL;
	volatile uint8_t ADTES;
}ADC1_Config_Type, *ADC1_Config_MemMapPtr;


#define ADC1_CONFIGURATION_REGISTER_BASE										   													   	(0x0010)
#define ADC1_CONFIG							     								   ((__near ADC1_Config_Type *)ADC1_CONFIGURATION_REGISTER_BASE)


/* ADM2 Bit Fields */
#define ADC_ADM2_ADTYP_SHIFT																												   0
#define ADC_ADM2_ADTYP_MASK																													0x01
#define ADC_ADM2_AWC_SHIFT																													   2
#define ADC_ADM2_AWC_MASK																													0x04
#define ADC_ADM2_ADRCK_SHIFT																												   3
#define ADC_ADM2_ADRCK_MASK																													0x08
#define ADC_ADM2_ADREFM_SHIFT																												   5
#define ADC_ADM2_ADREFM_MASK																												0x20
#define ADC_ADM2_ADREFP_SHIFT																												   6
#define ADC_ADM2_ADREFP_MASK																												0xC0
#define ADC_ADM2_ADREFP_VALUE(x)									   (((uint8_t)(((uint8_t)(x))<<ADC_ADM2_ADREFP_SHIFT))&ADC_ADM2_ADREFP_MASK)


/* ADTES Bit Fields */
#define ADC_ADTES_SHIFT																														   0
#define ADC_ADTES_MASK																														0x07
#define ADC_ADTES_VALUE(x)														   (((uint8_t)(((uint8_t)(x))<<ADC_ADTES_SHIFT))&ADC_ADTES_MASK)




#define ADC_CONVERSION_RESULT_BASE											   														   	(0xFF1E)
#define ADCR							 									  		   *((__near volatile uint16_t *)ADC_CONVERSION_RESULT_BASE)

#define ADC_PORT_CONFIG_REGISTER_BASE											   													   	(0x006E)
#define ADPC										       							 *((__near volatile uint8_t *)ADC_PORT_CONFIG_REGISTER_BASE)


/* ADPC Bit Fields */
#define ADC_ADPC_MASK																														0x0F
#define ADC_ADPC_SHIFT																														   0
#define ADC_ADPC_VALUE(x)												   			 (((uint8_t)(((uint8_t)(x))<<ADC_ADPC_SHIFT))&ADC_ADPC_MASK)

/* -------------------------------------------------------------- ADC Configuration Handlers ------------------------------------------------------------ */








/* ------------------------------------------------------------- RTC Configuration Handlers ------------------------------------------------------------- */

/* RTC Register Definition */
typedef struct {
	volatile uint8_t SEC;
	volatile uint8_t MIN;
	volatile uint8_t HOUR;
	volatile uint8_t WEEK;
	volatile uint8_t DAY;
	volatile uint8_t MONTH;
	volatile uint8_t YEAR;
	volatile uint8_t SUBCUD;
	volatile uint8_t ALARMWM;
	volatile uint8_t ALARMWH;
	volatile uint8_t ALARMWW;
	volatile uint8_t RTCC0;
	volatile uint8_t RTCC1;
}RTC_Type, *RTC_MemMapPtr;


#define RTC_REGISTER_BASE												   															   	(0xFF52)
#define RTC											    												  ((__near RTC_Type *)RTC_REGISTER_BASE)


/* SUBCUD Bit Fields */
#define RTC_SUBCUD_F_SHIFT																													   0
#define RTC_SUBCUD_F_MASK																													0x7F
#define RTC_SUBCUD_F_VALUE(x)												 (((uint8_t)(((uint8_t)(x))<<RTC_SUBCUD_F_SHIFT))&RTC_SUBCUD_F_MASK)
#define RTC_SUBCUD_DEV_SHIFT																												   7
#define RTC_SUBCUD_DEV_MASK																													0x80


/* RTCC0 Bit Fields */
#define RTC_RTCC0_CT_SHIFT																													   0
#define RTC_RTCC0_CT_MASK																													0x07
#define RTC_RTCC0_CT_VALUE(x)												 (((uint8_t)(((uint8_t)(x))<<RTC_RTCC0_CT_SHIFT))&RTC_RTCC0_CT_MASK)
#define RTC_RTCC0_AMPM_SHIFT																												   3
#define RTC_RTCC0_AMPM_MASK																													0x08
#define RTC_RTCC0_RCLOE1_SHIFT																												   5
#define RTC_RTCC0_RCLOE1_MASK																												0x20
#define RTC_RTCC0_RTCE_SHIFT																												   7
#define RTC_RTCC0_RTCE_MASK																													0x80


/* RTCC1 Bit Fields */
#define RTC_RTCC1_RWAIT_SHIFT																												   0
#define RTC_RTCC1_RWAIT_MASK																												0x01
#define RTC_RTCC1_RWST_SHIFT																												   1
#define RTC_RTCC1_RWST_MASK																													0x02
#define RTC_RTCC1_RIFG_SHIFT																												   3
#define RTC_RTCC1_RIFG_MASK																													0x08
#define RTC_RTCC1_WAFG_SHIFT																												   4
#define RTC_RTCC1_WAFG_MASK																													0x10
#define RTC_RTCC1_WALIE_SHIFT																												   6
#define RTC_RTCC1_WALIE_MASK																												0x40
#define RTC_RTCC1_WALE_SHIFT																												   7
#define RTC_RTCC1_WALE_MASK																													0x80




#define RTC_CLOCK_SELECTION_REGISTER_BASE																							   	(0x00F9)
#define RTCCL																	 *((__near volatile uint8_t *)RTC_CLOCK_SELECTION_REGISTER_BASE)

/* RTCCL Bit Fields */
#define RTC_RTCCL_RTCCKS_SHIFT																												   0
#define RTC_RTCCL_RTCCKS_MASK																												0x03
#define RTC_RTCCL_RTCCKS_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<RTC_RTCCL_RTCCKS_SHIFT))&RTC_RTCCL_RTCCKS_MASK)
#define RTC_RTCCL_RTCCL6_SHIFT																												   6
#define RTC_RTCCL_RTCCL6_MASK																												0x40
#define RTC_RTCCL_RTCCL7_SHIFT																												   7
#define RTC_RTCCL_RTCCL7_MASK																												0x80





#define RTC_1HZ_PIN_SEL_REGISTER_BASE																								   	(0xFF36)
#define RTCSEL																		 *((__near volatile uint8_t *)RTC_1HZ_PIN_SEL_REGISTER_BASE)

/*RTCSEL Bit Fields */
#define RTCSEL_RTCTIS00_SHIFT																												   0
#define RTCSEL_RTCTIS00_MASK																												0x01
#define RTCSEL_RTCTIS01_SHIFT																												   1
#define RTCSEL_RTCTIS01_MASK																												0x02
#define RTCSEL_RTCTIS10_SHIFT																												   2
#define RTCSEL_RTCTIS10_MASK																												0x04
#define RTCSEL_RTCTIS11_SHIFT																												   3
#define RTCSEL_RTCTIS11_MASK																												0x08
#define RTCSEL_RTCOSEL_SHIFT																												   6
#define RTCSEL_RTCOSEL_MASK																													0xC0
#define RTCSEL_RTCOSEL_VALUE(x)											 (((uint8_t)(((uint8_t)(x))<<RTCSEL_RTCOSEL_SHIFT))&RTCSEL_RTCOSEL_MASK)




#define WATCH_ERROR_CORRECTION_REGISTER_BASE																						   	(0xFF34)
#define SUBCUDW																 *((__near volatile uint16_t *)WATCH_ERROR_CORRECTION_REGISTER_BASE)

/* SUBCUDW Bit Fields */
#define RTC_SUBCUDW_F_SHIFT																													   0
#define RTC_SUBCUDW_F_MASK																												  0x1FFF
#define RTC_SUBCUDW_F_VALUE(x)											   (((uint8_t)(((uint8_t)(x))<<RTC_SUBCUDW_F_SHIFT))&RTC_SUBCUDW_F_MASK)

/* ------------------------------------------------------------- RTC Configuration Handlers ------------------------------------------------------------- */














/* ----------------------------------------------------------- DMA Configuration Handlers ------------------------------------------------------------ */

#define DMA_SFR_REGISTER_0_BASE												   														   	(0xFFB0)
#define DSA0										      								   *((__near volatile uint8_t *)DMA_SFR_REGISTER_0_BASE)

#define DMA_SFR_REGISTER_1_BASE												   														   	(0xFFB1)
#define DSA1										      								   *((__near volatile uint8_t *)DMA_SFR_REGISTER_1_BASE)

#define DMA_SFR_REGISTER_2_BASE												   														   	(0x0170)
#define DSA2										      								   *((__near volatile uint8_t *)DMA_SFR_REGISTER_2_BASE)

#define DMA_SFR_REGISTER_3_BASE												   														   	(0x0171)
#define DSA3										      								   *((__near volatile uint8_t *)DMA_SFR_REGISTER_3_BASE)



/* DMA RAM Register Definition */
typedef struct {
	union {
		volatile uint8_t DRA_L;
		volatile uint8_t DRA_H;
	}ACCESS_8bit;
	volatile uint16_t DRA;
}DMA_RAM_Type, *DMA_RAM_MemMapPtr;


#define DMA_RAM_REGISTER_0_BASE												   														   	(0xFFB2)
#define DRA0										  											((__near DMA_RAM_Type *)DMA_RAM_REGISTER_0_BASE)

#define DMA_RAM_REGISTER_1_BASE												   														   	(0xFFB4)
#define DRA1										  											((__near DMA_RAM_Type *)DMA_RAM_REGISTER_1_BASE)

#define DMA_RAM_REGISTER_2_BASE												   														  	(0x0172)
#define DRA2										  											((__near DMA_RAM_Type *)DMA_RAM_REGISTER_2_BASE)

#define DMA_RAM_REGISTER_3_BASE												   														  	(0x0174)
#define DRA3										  											((__near DMA_RAM_Type *)DMA_RAM_REGISTER_3_BASE)






#define DMA_BYTE_COUNT_REGISTER_0_BASE											   													   	(0xFFB6)
#define DBC0									    							   *((__near volatile uint16_t *)DMA_BYTE_COUNT_REGISTER_0_BASE)

#define DMA_BYTE_COUNT_REGISTER_1_BASE											   													   	(0xFFB8)
#define DBC1									    							   *((__near volatile uint16_t *)DMA_BYTE_COUNT_REGISTER_1_BASE)

#define DMA_BYTE_COUNT_REGISTER_2_BASE											   													   	(0x0176)
#define DBC2									    							   *((__near volatile uint16_t *)DMA_BYTE_COUNT_REGISTER_2_BASE)

#define DMA_BYTE_COUNT_REGISTER_3_BASE											   													   	(0x0178)
#define DBC3									    							   *((__near volatile uint16_t *)DMA_BYTE_COUNT_REGISTER_3_BASE)


/* DBC Bit Fields */
#define DMA_DBC_SHIFT																														   0
#define DMA_DBC_MASK																													  0x03FF
#define DMA_DBC_VALUE(x)															 (((uint16_t)(((uint16_t)(x))<<DMA_DBC_SHIFT))&DMA_DBC_MASK)





#define DMA_MODE_CONTROL_REGISTER_0_BASE										   													   	(0xFFBA)
#define DMC0									   								  *((__near volatile uint8_t *)DMA_MODE_CONTROL_REGISTER_0_BASE)

#define DMA_MODE_CONTROL_REGISTER_1_BASE										   													   	(0xFFBB)
#define DMC1									   								  *((__near volatile uint8_t *)DMA_MODE_CONTROL_REGISTER_1_BASE)

#define DMA_MODE_CONTROL_REGISTER_2_BASE										   													   	(0x017A)
#define DMC2									   								  *((__near volatile uint8_t *)DMA_MODE_CONTROL_REGISTER_2_BASE)

#define DMA_MODE_CONTROL_REGISTER_3_BASE										   													   	(0x017B)
#define DMC3									   								  *((__near volatile uint8_t *)DMA_MODE_CONTROL_REGISTER_3_BASE)


/* DMC Bit Fields */
#define DMA_DMC_IFC_SHIFT																													   0
#define DMA_DMC_IFC_MASK																													0x0F
#define DMA_DMC_IFC_VALUE(x)
#define DMA_DMC_DWAIT_SHIFT																													   4
#define DMA_DMC_DWAIT_MASK																													0x10
#define DMA_DMC_DS_SHIFT																													   5
#define DMA_DMC_DS_MASK																														0x20
#define DMA_DMC_DRS_SHIFT																													   6
#define DMA_DMC_DRS_MASK																													0x40
#define DMA_DMC_STG_SHIFT																													   7
#define DMA_DMC_STG_MASK																													0x80






#define DMA_OPER_CONTROL_REGISTER_0_BASE										   													   	(0xFFBC)
#define DRC0									   								  *((__near volatile uint8_t *)DMA_OPER_CONTROL_REGISTER_0_BASE)

#define DMA_OPER_CONTROL_REGISTER_1_BASE										   													   	(0xFFBD)
#define DRC1									   								  *((__near volatile uint8_t *)DMA_OPER_CONTROL_REGISTER_1_BASE)

#define DMA_OPER_CONTROL_REGISTER_2_BASE										   													   	(0x017C)
#define DRC2									   								  *((__near volatile uint8_t *)DMA_OPER_CONTROL_REGISTER_2_BASE)

#define DMA_OPER_CONTROL_REGISTER_3_BASE										   													   	(0x017D)
#define DRC3									   								  *((__near volatile uint8_t *)DMA_OPER_CONTROL_REGISTER_3_BASE)


/* DRC Bit Fields */
#define DMA_DRC_DST_SHIFT																													   0
#define DMA_DRC_DST_MASK																													0x01
#define DMA_DRC_DEN_SHIFT																													   7
#define DMA_DRC_DEN_MASK																													0x80





#define DMA_TRIGGER_SELECTION_REGISTER_BASE																							   	(0x001F)
#define DMATSEL																   *((__near volatile uint8_t *)DMA_TRIGGER_SELECTION_REGISTER_BASE)


/* DMATSEL Bit Fields */
#define DMA_DMATSEL_DMATSL01_SHIFT																											   0
#define DMA_DMATSEL_DMATSL01_MASK																											0x01
#define DMA_DMATSEL_DMATSL23_SHIFT																											   1
#define DMA_DMATSEL_DMATSL23_MASK																											0x02




#define DMA_ALL_CHANNEL_FORCE_WAIT_REGISTER_BASE																					   	(0x017F)
#define DWAITALL														  *((__near volatile uint8_t *)DMA_ALL_CHANNEL_FORCE_WAIT_REGISTER_BASE)


/* DWAITALL Bit Fields */
#define DMA_DWAITALL_SHIFT																													   0
#define DMA_DWAITALL_MASK																													0x01
#define DMA_DWAITALL_PRVARI_SHIFT																											   7
#define DMA_DWAITALL_PRVARI_MASK																											0x80

/* ----------------------------------------------------------- DMA Configuration Handlers ------------------------------------------------------------ */













/* ---------------------------------------------------------- Interrupt Configuration Handlers ------------------------------------------------------ */

/* Interrupt Request Flag Register Definition */
typedef union {
	union {
		volatile uint8_t IF_L;
		volatile uint8_t IF_H;
	}ACCESS_8bit;
	volatile uint16_t IF;
}IRF_Req_Type, *IRF_Req_MemMapPtr;


#define INTERRUPT_REQ_FLAG_REGISTER_0_BASE										   													   	(0xFFE0)
#define IF0																			 ((__near IRF_Req_Type *)INTERRUPT_REQ_FLAG_REGISTER_0_BASE)


/* IF0 Bit Fields */
#define INT_IF0_WDTIIF_SHIFT																												   0
#define INT_IF0_WDTIIF_MASK																												  0x0001
#define INT_IF0_LVIIF_SHIFT																													   1
#define INT_IF0_LVIIF_MASK																												  0x0002
#define INT_IF0_PIF0_SHIFT																													   2
#define INT_IF0_PIF0_MASK																												  0x0004
#define INT_IF0_PIF1_SHIFT																													   3
#define INT_IF0_PIF1_MASK																												  0x0008
#define INT_IF0_PIF2_SHIFT																													   4
#define INT_IF0_PIF2_MASK																												  0x0010
#define INT_IF0_PIF3_SHIFT																													   5
#define INT_IF0_PIF3_MASK																												  0x0020
#define INT_IF0_PIF4_SHIFT																													   6
#define INT_IF0_PIF4_MASK																												  0x0040
#define INT_IF0_PIF5_SHIFT																													   7
#define INT_IF0_PIF5_MASK																												  0x0080
#define INT_IF0_CLMIF_SHIFT																													   8
#define INT_IF0_CLMIF_MASK																												  0x0100
#define INT_IF0_CSIIF0_SHIFT																												   9
#define INT_IF0_CSIIF0_MASK																												  0x0200
#define INT_IF0_CSIIF1_SHIFT																												  10
#define INT_IF0_CSIIF1_MASK																												  0x0400
#define INT_IF0_DMAIF0_SHIFT																												  11
#define INT_IF0_DMAIF0_MASK																												  0x0800
#define INT_IF0_DMAIF1_SHIFT																												  12
#define INT_IF0_DMAIF1_MASK																												  0x1000
#define INT_IF0_RTCIF_SHIFT																													  13
#define INT_IF0_RTCIF_MASK																												  0x2000
#define INT_IF0_ITIF_SHIFT																													  14
#define INT_IF0_ITIF_MASK																												  0x4000
#define INT_IF0_LTIF0_SHIFT																													  15
#define INT_IF0_LTIF0_MASK																												  0x8000





#define INTERRUPT_REQ_FLAG_REGISTER_1_BASE										   													   	(0xFFE2)
#define IF1																			 ((__near IRF_Req_Type *)INTERRUPT_REQ_FLAG_REGISTER_1_BASE)


/* IF1 Bit Fields */
#define INT_IF1_LRIF0_SHIFT																													   0
#define INT_IF1_LRIF0_MASK																												  0x0001
#define INT_IF1_LSIF0_SHIFT																													   1
#define INT_IF1_LSIF0_MASK																												  0x0002
#define INT_IF1_PIFLR0_SHIFT																												   2
#define INT_IF1_PIFLR0_MASK																												  0x0004
#define INT_IF1_SGIF_SHIFT																													   3
#define INT_IF1_SGIF_MASK																												  0x0008
#define INT_IF1_TMIF00_SHIFT																												   4
#define INT_IF1_TMIF00_MASK																												  0x0010
#define INT_IF1_TMIF01_SHIFT																												   5
#define INT_IF1_TMIF01_MASK																												  0x0020
#define INT_IF1_TMIF02_SHIFT																												   6
#define INT_IF1_TMIF02_MASK																												  0x0040
#define INT_IF1_TMIF03_SHIFT																												   7
#define INT_IF1_TMIF03_MASK																												  0x0080
#define INT_IF1_ADIF_SHIFT																												   	   8
#define INT_IF1_ADIF_MASK																												  0x0100
#define INT_IF1_LTIF1_SHIFT																												 	   9
#define INT_IF1_LTIF1_MASK																												  0x0200
#define INT_IF1_LRIF1_SHIFT																													  10
#define INT_IF1_LRIF1_MASK																												  0x0400
#define INT_IF1_LSIF1_SHIFT																													  11
#define INT_IF1_LSIF1_MASK																												  0x0800
#define INT_IF1_PIFLR1_SHIFT																												  12
#define INT_IF1_PIFLR1_MASK																												  0x1000
#define INT_IF1_CSIIF10_SHIFT																												  13
#define INT_IF1_CSIIF10_MASK																											  0x2000
#define INT_IF1_IICIF11_SHIFT																												  14
#define INT_IF1_IICIF11_MASK																											  0x4000
#define INT_IF1_TMIF04_SHIFT																												  15
#define INT_IF1_TMIF04_MASK																												  0x8000





#define INTERRUPT_REQ_FLAG_REGISTER_2_BASE										   													   	(0xFFD0)
#define IF2																			 ((__near IRF_Req_Type *)INTERRUPT_REQ_FLAG_REGISTER_2_BASE)


/* IF2 Bit Fields */
#define INT_IF2_TMIF05_SHIFT																												   0
#define INT_IF2_TMIF05_MASK																												  0x0001
#define INT_IF2_TMIF06_SHIFT																												   1
#define INT_IF2_TMIF06_MASK																												  0x0002
#define INT_IF2_TMIF07_SHIFT																												   2
#define INT_IF2_TMIF07_MASK																												  0x0004
#define INT_IF2_C1ERRIF_SHIFT																												   3
#define INT_IF2_C1ERRIF_MASK																											  0x0008
#define INT_IF2_C1WUPIF_SHIFT																												   4
#define INT_IF2_C1WUPIF_MASK																											  0x0010
#define INT_IF2_C0ERRIF_SHIFT																												   5
#define INT_IF2_C0ERRIF_MASK																											  0x0020
#define INT_IF2_C0WUPIF_SHIFT																												   6
#define INT_IF2_C0WUPIF_MASK																											  0x0040
#define INT_IF2_C0RECIF_SHIFT																												   7
#define INT_IF2_C0RECIF_MASK																											  0x0080
#define INT_IF2_C0TRXIF_SHIFT																												   8
#define INT_IF2_C0TRXIF_MASK																											  0x0100
#define INT_IF2_TMIF10_SHIFT																												   9
#define INT_IF2_TMIF10_MASK																											  	  0x0200
#define INT_IF2_TMIF11_SHIFT																												  10
#define INT_IF2_TMIF11_MASK																											  	  0x0400
#define INT_IF2_TMIF12_SHIFT																												  11
#define INT_IF2_TMIF12_MASK																											  	  0x0800
#define INT_IF2_TMIF13_SHIFT																												  12
#define INT_IF2_TMIF13_MASK																											  	  0x1000
#define INT_IF2_MDIF_SHIFT																												      13
#define INT_IF2_MDIF_MASK																											  	  0x2000
#define INT_IF2_C1RECIF_SHIFT																												  14
#define INT_IF2_C1RECIF_MASK																											  0x4000
#define INT_IF2_FLIF_SHIFT																													  15
#define INT_IF2_FLIF_MASK																											  	  0x8000





#define INTERRUPT_REQ_FLAG_REGISTER_3_BASE										   													   	(0xFFD2)
#define IF3																			 ((__near IRF_Req_Type *)INTERRUPT_REQ_FLAG_REGISTER_3_BASE)


/* IF3 Bit Fields */
#define INT_IF3_C1TRXIF_SHIFT																												   0
#define INT_IF3_C1TRXIF_MASK																											  0x0001
#define INT_IF3_TMIF14_SHIFT																												   1
#define INT_IF3_TMIF14_MASK																												  0x0002
#define INT_IF3_TMIF15_SHIFT																												   2
#define INT_IF3_TMIF15_MASK																												  0x0004
#define INT_IF3_TMIF16_SHIFT																												   3
#define INT_IF3_TMIF16_MASK																												  0x0008
#define INT_IF3_TMIF17_SHIFT																												   4
#define INT_IF3_TMIF17_MASK																												  0x0010
#define INT_IF3_TMIF20_SHIFT																												   5
#define INT_IF3_TMIF20_MASK																												  0x0020
#define INT_IF3_TMIF21_SHIFT																												   6
#define INT_IF3_TMIF21_MASK																												  0x0040
#define INT_IF3_TMIF22_SHIFT																												   7
#define INT_IF3_TMIF22_MASK																												  0x0080
#define INT_IF3_TMIF23_SHIFT																												   8
#define INT_IF3_TMIF23_MASK																												  0x0100
#define INT_IF3_TMIF24_SHIFT																												   9
#define INT_IF3_TMIF24_MASK																												  0x0200
#define INT_IF3_TMIF26_SHIFT																												  10
#define INT_IF3_TMIF26_MASK																												  0x0400
#define INT_IF3_DMAIF2_SHIFT																												  11
#define INT_IF3_DMAIF2_MASK																												  0x0800
#define INT_IF3_DMAIF3_SHIFT																												  12
#define INT_IF3_DMAIF3_MASK																												  0x1000







/* Interrupt Mask Flag Register Definition */
typedef union {
	union {
		volatile uint8_t MK_L;
		volatile uint8_t MK_H;
	}ACCESS_8bit;
	volatile uint16_t MK;
}IRF_Mask_Type, *IRF_Mask_MemMapPtr;


#define INTERRUPT_MASK_FLAG_REGISTER_0_BASE										  													   	(0xFFE4)
#define MK0								       									   ((__near IRF_Mask_Type *)INTERRUPT_MASK_FLAG_REGISTER_0_BASE)


/* MK0 Bit Fields */
#define INT_MK0_WDTIMK_SHIFT																												   0
#define INT_MK0_WDTIMK_MASK																												  0x0001
#define INT_MK0_LVIMK_SHIFT																													   1
#define INT_MK0_LVIMK_MASK																												  0x0002
#define INT_MK0_PMK0_SHIFT																													   2
#define INT_MK0_PMK0_MASK																												  0x0004
#define INT_MK0_PMK1_SHIFT																													   3
#define INT_MK0_PMK1_MASK																												  0x0008
#define INT_MK0_PMK2_SHIFT																													   4
#define INT_MK0_PMK2_MASK																												  0x0010
#define INT_MK0_PMK3_SHIFT																													   5
#define INT_MK0_PMK3_MASK																												  0x0020
#define INT_MK0_PMK4_SHIFT																													   6
#define INT_MK0_PMK4_MASK																												  0x0040
#define INT_MK0_PMK5_SHIFT																													   7
#define INT_MK0_PMK5_MASK																												  0x0080
#define INT_MK0_CLMMK_SHIFT																													   8
#define INT_MK0_CLMMK_MASK																												  0x0100
#define INT_MK0_CSIMK0_SHIFT																												   9
#define INT_MK0_CSIMK0_MASK																												  0x0200
#define INT_MK0_CSIMK1_SHIFT																												  10
#define INT_MK0_CSIMK1_MASK																												  0x0400
#define INT_MK0_DMAMK0_SHIFT																												  11
#define INT_MK0_DMAMK0_MASK																												  0x0800
#define INT_MK0_DMAMK1_SHIFT																												  12
#define INT_MK0_DMAMK1_MASK																												  0x1000
#define INT_MK0_RTCMK_SHIFT																													  13
#define INT_MK0_RTCMK_MASK																												  0x2000
#define INT_MK0_ITMK_SHIFT																													  14
#define INT_MK0_ITMK_MASK																												  0x4000
#define INT_MK0_LTMK0_SHIFT																													  15
#define INT_MK0_LTMK0_MASK																												  0x8000




#define INTERRUPT_MASK_FLAG_REGISTER_1_BASE										   													   	(0xFFE6)
#define MK1								       									   ((__near IRF_Mask_Type *)INTERRUPT_MASK_FLAG_REGISTER_1_BASE)


/* MK1 Bit Fields */
#define INT_MK1_LRMK0_SHIFT																													   0
#define INT_MK1_LRMK0_MASK																												  0x0001
#define INT_MK1_LSMK0_SHIFT																													   1
#define INT_MK1_LSMK0_MASK																												  0x0002
#define INT_MK1_PMKLR0_SHIFT																												   2
#define INT_MK1_PMKLR0_MASK																												  0x0004
#define INT_MK1_SGMK_SHIFT																													   3
#define INT_MK1_SGMK_MASK																												  0x0008
#define INT_MK1_TMMK00_SHIFT																												   4
#define INT_MK1_TMMK00_MASK																												  0x0010
#define INT_MK1_TMMK01_SHIFT																												   5
#define INT_MK1_TMMK01_MASK																												  0x0020
#define INT_MK1_TMMK02_SHIFT																												   6
#define INT_MK1_TMMK02_MASK																												  0x0040
#define INT_MK1_TMMK03_SHIFT																												   7
#define INT_MK1_TMMK03_MASK																												  0x0080
#define INT_MK1_ADMK_SHIFT																												   	   8
#define INT_MK1_ADMK_MASK																												  0x0100
#define INT_MK1_LTMK1_SHIFT																												 	   9
#define INT_MK1_LTMK1_MASK																												  0x0200
#define INT_MK1_LRMK1_SHIFT																													  10
#define INT_MK1_LRMK1_MASK																												  0x0400
#define INT_MK1_LSMK1_SHIFT																													  11
#define INT_MK1_LSMK1_MASK																												  0x0800
#define INT_MK1_PMKLR1_SHIFT																												  12
#define INT_MK1_PMKLR1_MASK																												  0x1000
#define INT_MK1_CSIMK10_SHIFT																												  13
#define INT_MK1_CSIMK10_MASK																											  0x2000
#define INT_MK1_IICMK11_SHIFT																												  14
#define INT_MK1_IICMK11_MASK																											  0x4000
#define INT_MK1_TMMK04_SHIFT																												  15
#define INT_MK1_TMMK04_MASK																												  0x8000






#define INTERRUPT_MASK_FLAG_REGISTER_2_BASE										   													   	(0xFFD4)
#define MK2								       									   ((__near IRF_Mask_Type *)INTERRUPT_MASK_FLAG_REGISTER_2_BASE)


/* MK2 Bit Fields */
#define INT_MK2_TMMK05_SHIFT																												   0
#define INT_MK2_TMMK05_MASK																												  0x0001
#define INT_MK2_TMMK06_SHIFT																												   1
#define INT_MK2_TMMK06_MASK																												  0x0002
#define INT_MK2_TMMK07_SHIFT																												   2
#define INT_MK2_TMMK07_MASK																												  0x0004
#define INT_MK2_C1ERRMK_SHIFT																												   3
#define INT_MK2_C1ERRMK_MASK																											  0x0008
#define INT_MK2_C1WUPMK_SHIFT																												   4
#define INT_MK2_C1WUPMK_MASK																											  0x0010
#define INT_MK2_C0ERRMK_SHIFT																												   5
#define INT_MK2_C0ERRMK_MASK																											  0x0020
#define INT_MK2_C0WUPMK_SHIFT																												   6
#define INT_MK2_C0WUPMK_MASK																											  0x0040
#define INT_MK2_C0RECMK_SHIFT																												   7
#define INT_MK2_C0RECMK_MASK																											  0x0080
#define INT_MK2_C0TRXMK_SHIFT																												   8
#define INT_MK2_C0TRXMK_MASK																											  0x0100
#define INT_MK2_TMMK10_SHIFT																												   9
#define INT_MK2_TMMK10_MASK																											  	  0x0200
#define INT_MK2_TMMK11_SHIFT																												  10
#define INT_MK2_TMMK11_MASK																											  	  0x0400
#define INT_MK2_TMMK12_SHIFT																												  11
#define INT_MK2_TMMK12_MASK																											  	  0x0800
#define INT_MK2_TMMK13_SHIFT																												  12
#define INT_MK2_TMMK13_MASK																											  	  0x1000
#define INT_MK2_MDMK_SHIFT																												      13
#define INT_MK2_MDMK_MASK																											  	  0x2000
#define INT_MK2_C1RECMK_SHIFT																												  14
#define INT_MK2_C1RECMK_MASK																											  0x4000
#define INT_MK2_FLMK_SHIFT																													  15
#define INT_MK2_FLMK_MASK																											  	  0x8000






#define INTERRUPT_MASK_FLAG_REGISTER_3_BASE										   													   	(0xFFD6)
#define MK3								       									   ((__near IRF_Mask_Type *)INTERRUPT_MASK_FLAG_REGISTER_3_BASE)


/* MK3 Bit Fields */
#define INT_MK3_C1TRXMK_SHIFT																												   0
#define INT_MK3_C1TRXMK_MASK																											  0x0001
#define INT_MK3_TMMK14_SHIFT																												   1
#define INT_MK3_TMMK14_MASK																												  0x0002
#define INT_MK3_TMMK15_SHIFT																												   2
#define INT_MK3_TMMK15_MASK																												  0x0004
#define INT_MK3_TMMK16_SHIFT																												   3
#define INT_MK3_TMMK16_MASK																												  0x0008
#define INT_MK3_TMMK17_SHIFT																												   4
#define INT_MK3_TMMK17_MASK																												  0x0010
#define INT_MK3_TMMK20_SHIFT																												   5
#define INT_MK3_TMMK20_MASK																												  0x0020
#define INT_MK3_TMMK21_SHIFT																												   6
#define INT_MK3_TMMK21_MASK																												  0x0040
#define INT_MK3_TMMK22_SHIFT																												   7
#define INT_MK3_TMMK22_MASK																												  0x0080
#define INT_MK3_TMMK23_SHIFT																												   8
#define INT_MK3_TMMK23_MASK																												  0x0100
#define INT_MK3_TMMK24_SHIFT																												   9
#define INT_MK3_TMMK24_MASK																												  0x0200
#define INT_MK3_TMMK26_SHIFT																												  10
#define INT_MK3_TMMK26_MASK																												  0x0400
#define INT_MK3_DMAMK2_SHIFT																												  11
#define INT_MK3_DMAMK2_MASK																												  0x0800
#define INT_MK3_DMAMK3_SHIFT																												  12
#define INT_MK3_DMAMK3_MASK																												  0x1000







/* External Interrupt Register 0 Definition */
typedef struct {
	volatile uint8_t EGP;
	volatile uint8_t EGN;
}EXT_Interrupt_Type, *EXT_Interrupt_MemMapPtr;


#define EXT_INTERRUPT_EDGE_ENABLE_REGISTER_0_BASE									   												   	(0xFF38)
#define EXT_INT0						  								((__near EXT_Interrupt_Type *)EXT_INTERRUPT_EDGE_ENABLE_REGISTER_0_BASE)

/* ---------------------------------------------------------- Interrupt Configuration Handlers ------------------------------------------------------ */













/* ---------------------------------------------------------- Clock Configuration Handlers --------------------------------------------------------- */

/* Clock Registers Definition */
typedef struct{
	volatile uint8_t CMC;
	volatile uint8_t CSC;
	volatile uint8_t OSTC;
	volatile uint8_t OSTS;
	volatile uint8_t CKC;
	volatile uint8_t CKS0;
}CLK_Type, *CLK_MemMapPtr;


#define CLOCK_CONFIGURATION_REGISTER_BASE										   														(0xFFA0)
#define CLOCK									    									  ((__near CLK_Type *)CLOCK_CONFIGURATION_REGISTER_BASE)


/* CMC Bit Fields */
#define CLOCK_CMC_AMPH_SHIFT																												   0
#define CLOCK_CMC_AMPH_MASK																													0x01
#define CLOCK_CMC_AMPHS_SHIFT																												   1
#define CLOCK_CMC_AMPHS_MASK																												0x06
#define CLOCK_CMC_AMPHS_VALUE(x)									   (((uint8_t)(((uint8_t)(x))<<CLOCK_CMC_AMPHS_SHIFT))&CLOCK_CMC_AMPHS_MASK)
#define CLOCK_CMC_OSCSELS_SHIFT																												   4
#define CLOCK_CMC_OSCSELS_MASK																												0x10
#define CLOCK_CMC_OSCSEL_SHIFT																												   6
#define CLOCK_CMC_OSCSEL_MASK																												0x40
#define CLOCK_CMC_EXCLK_SHIFT																												   7
#define CLOCK_CMC_EXCLK_MASK																												0x80


/* CSC Bit Fields */
#define CLOCK_CSC_HIOSTOP_SHIFT																												   0
#define CLOCK_CSC_HIOSTOP_MASK																												0x01
#define CLOCK_CSC_XTSTOP_SHIFT																												   6
#define CLOCK_CSC_XTSTOP_MASK																												0x40
#define CLOCK_CSC_MSTOP_SHIFT																												   7
#define CLOCK_CSC_MSTOP_MASK																												0x80


/* OSTS Bit Fields */
#define CLOCK_OSTS_SHIFT																													   0
#define CLOCK_OSTS_MASK																														0x07
#define CLOCK_OSTS_VALUE(x)														 (((uint8_t)(((uint8_t)(x))<<CLOCK_OSTS_SHIFT))&CLOCK_OSTS_MASK)



/* CKC Bit Fields */
#define CLOCK_CKC_MCM0_SHIFT																												   4
#define CLOCK_CKC_MCM0_MASK																													0x10
#define CLOCK_CKC_MCS_SHIFT																													   5
#define CLOCK_CKC_MCS_MASK																													0x20
#define CLOCK_CKC_CSS_SHIFT																													   6
#define CLOCK_CKC_CSS_MASK																													0x40
#define CLOCK_CKC_CLS_SHIFT																													   7
#define CLOCK_CKC_CLS_MASK																													0x80


/* CKS0 Bit Fields */
#define CLOCK_CKS0_CCS_SHIFT																												   0
#define CLOCK_CKS0_CCS_MASK																													0x07
#define CLOCK_CKS0_CCS_VALUE(x)											 (((uint8_t)(((uint8_t)(x))<<CLOCK_CKS0_CCS_SHIFT))&CLOCK_CKS0_CCS_MASK)
#define CLOCK_CKS0_CSEL_SHIFT																												   3
#define CLOCK_CKS0_CSEL_MASK																												0x08
#define CLOCK_CKS0_PCLOE_SHIFT																												   7
#define CLOCK_CKS0_PCLOE_MASK																												0x80




#define HIGH_SPEED_OSC_TRIM_REGISTER_BASE										   													   	(0x00A0)
#define HIOTRM											   						 *((__near volatile uint8_t *)HIGH_SPEED_OSC_TRIM_REGISTER_BASE)


/* HIOTRM Bit Fields */
#define CLOCK_HIOTRM_SHIFT																													   0
#define CLOCK_HIOTRM_MASK																													0x3F
#define CLOCK_HIOTRM_VALUE(x)												 (((uint8_t)(((uint8_t)(x))<<CLOCK_HIOTRM_SHIFT))&CLOCK_HIOTRM_MASK)




#define OPERATION_SPEED_MODE_CTRL_REGISTER_BASE									           											   	(0x00F3)
#define OSMC				       										   *((__near volatile uint8_t *)OPERATION_SPEED_MODE_CTRL_REGISTER_BASE)

/* OSMC Bit Fields */
#define CLOCK_OSMC_WUTMMCK0_SHIFT																											   4
#define CLOCK_OSMC_WUTMMCK0_MASK																											0x10
#define CLOCK_OSMC_RTCLPC_SHIFT																												   7
#define CLOCK_OSMC_RTCLPC_MASK																												0x80





#define PERIPHERAL_CLOCK_SELECT_REGISTER_BASE																						   	(0x00F2)
#define PCKSEL																 *((__near volatile uint8_t *)PERIPHERAL_CLOCK_SELECT_REGISTER_BASE)

/* PCKSEL Bit Fields */
#define CLOCK_PCKSEL_SGCLKSEL_SHIFT																											   0
#define CLOCK_PCKSEL_SGCLKSEL_MASK																											0x01
#define CLOCK_PCKSEL_CANMCK0_SHIFT																											   3
#define CLOCK_PCKSEL_CANMCK0_MASK																											0x08
#define CLOCK_PCKSEL_CANMCKE0_SHIFT																											   4
#define CLOCK_PCKSEL_CANMCKE0_MASK																											0x10
#define CLOCK_PCKSEL_CANMCK1_SHIFT																											   5
#define CLOCK_PCKSEL_CANMCK1_MASK																											0x20
#define CLOCK_PCKSEL_CANMCKE1_SHIFT																											   6
#define CLOCK_PCKSEL_CANMCKE1_MASK																											0x40

/* ---------------------------------------------------------- Clock Configuration Handlers --------------------------------------------------------- */











/* ------------------------------------------------------------- Serial Control Registers --------------------------------------------------------- */

/* Serial Information Register Definition */
typedef struct {
	volatile uint16_t SE;
	volatile uint16_t SS;
	volatile uint16_t ST;
	volatile uint16_t SPS;
	volatile uint16_t SO;
	volatile uint16_t SOE;
	volatile uint16_t BL1[4];
	volatile uint16_t SOL;
} SER_Type, *SER_MemMapPtr;


#define SERIAL_CHANNEL_REGISTER_0_BASE											   													   	(0x0110)
#define SERIAL0																				 ((__near SER_Type *)SERIAL_CHANNEL_REGISTER_0_BASE)

#define SERIAL_CHANNEL_REGISTER_1_BASE											   													   	(0x0140)
#define SERIAL1																				 ((__near SER_Type *)SERIAL_CHANNEL_REGISTER_1_BASE)



/* SE Bit Fields */
#define SERIAL_SE_SHIFT																														   0
#define SERIAL_SE_MASK																													  0x0003
#define SERIAL_SE_VALUE(x)														 (((uint16_t)(((uint16_t)(x))<<SERIAL_SE_SHIFT))&SERIAL_SE_MASK)


/* SS Bit Fields */
#define SERIAL_SS_SHIFT																														   0
#define SERIAL_SS_MASK																													  0x0003
#define SERIAL_SS_VALUE(x)														 (((uint16_t)(((uint16_t)(x))<<SERIAL_SS_SHIFT))&SERIAL_SS_MASK)


/* ST Bit Fields */
#define SERIAL_ST_SHIFT																														   0
#define SERIAL_ST_MASK																													  0x0003
#define SERIAL_ST_VALUE(x)														 (((uint16_t)(((uint16_t)(x))<<SERIAL_ST_SHIFT))&SERIAL_ST_MASK)


/* SPS Bit Fields */
#define SERIAL_SPS_PRSm0_SHIFT																												   0
#define SERIAL_SPS_PRSm0_MASK																											  0x000F
#define SERIAL_SPS_PRSm0_VALUE(x)								   (((uint16_t)(((uint16_t)(x))<<SERIAL_SPS_PRSm0_SHIFT))&SERIAL_SPS_PRSm0_MASK)
#define SERIAL_SPS_PRSm1_SHIFT																												   4
#define SERIAL_SPS_PRSm1_MASK																											  0x00F0
#define SERIAL_SPS_PRSm1_VALUE(x)								   (((uint16_t)(((uint16_t)(x))<<SERIAL_SPS_PRSm1_SHIFT))&SERIAL_SPS_PRSm1_MASK)


/* SO Bit Fields */
#define SERIAL_SO_SHIFT																														   0
#define SERIAL_SO_MASK																													  0x0003
#define SERIAL_SO_VALUE(x)														 (((uint16_t)(((uint16_t)(x))<<SERIAL_SO_SHIFT))&SERIAL_SO_MASK)
#define SERIAL_CKO_SHIFT																													   8
#define SERIAL_CKO_MASK																													  0x0300
#define SERIAL_CKO_VALUE(x)													   (((uint16_t)(((uint16_t)(x))<<SERIAL_CKO_SHIFT))&SERIAL_CKO_MASK)


/* SOE Bit Fields */
#define SERIAL_SOE_SHIFT																													   0
#define SERIAL_SOE_MASK																													  0x0003
#define SERIAL_SOE_VALUE(x)													   (((uint16_t)(((uint16_t)(x))<<SERIAL_SOE_SHIFT))&SERIAL_SOE_MASK)


/* SOL Bit Fields */
#define SERIAL_SOL_SHIFT																													   0
#define SERIAL_SOL_MASK																													  0x0001




/* Serial Data Register Definition */
typedef struct {
	volatile uint8_t SDR_L;
	volatile uint8_t SDR_H;
} SDR_Type, *SDR_MemMapPtr;


#define SERIAL_DATA_REGISTER_00_BASE											   													   	(0xFF10)
#define SDR00										  										   ((__near SDR_Type *)SERIAL_DATA_REGISTER_00_BASE)

#define SERIAL_DATA_REGISTER_01_BASE											   													   	(0xFF12)
#define SDR01										  										   ((__near SDR_Type *)SERIAL_DATA_REGISTER_01_BASE)

#define SERIAL_DATA_REGISTER_10_BASE											   													   	(0xFF14)
#define SDR10										  										   ((__near SDR_Type *)SERIAL_DATA_REGISTER_10_BASE)

#define SERIAL_DATA_REGISTER_11_BASE											   													   	(0xFF16)
#define SDR11										  										   ((__near SDR_Type *)SERIAL_DATA_REGISTER_11_BASE)





/* Serial Status Register Definition */
typedef struct {
	union {
		volatile uint8_t SSR_L;
		volatile uint8_t SSR_H;
	}ACCESS_8bit;
	volatile uint16_t SSR;
} SSR_Type, *SSR_MemMapPtr;


#define SERIAL_STATUS_REGISTER_00_BASE											   													   	(0x0100)
#define SSR00																				 ((__near SSR_Type *)SERIAL_STATUS_REGISTER_00_BASE)

#define SERIAL_STATUS_REGISTER_01_BASE											   													   	(0x0102)
#define SSR01																				 ((__near SSR_Type *)SERIAL_STATUS_REGISTER_01_BASE)

#define SERIAL_STATUS_REGISTER_10_BASE											   													   	(0x0130)
#define SSR10																				 ((__near SSR_Type *)SERIAL_STATUS_REGISTER_10_BASE)

#define SERIAL_STATUS_REGISTER_11_BASE											  	 												   	(0x0132)
#define SSR11																				 ((__near SSR_Type *)SERIAL_STATUS_REGISTER_11_BASE)


/* SSR Bit Fields */
#define SERIAL_SSR_OVF_SHIFT																												   0
#define SERIAL_SSR_OVF_MASK																												  0x0001
#define SERIAL_SSR_PEF_SHIFT																												   1
#define SERIAL_SSR_PEF_MASK																												  0x0002
#define SERIAL_SSR_FEF_SHIFT																												   2
#define SERIAL_SSR_FEF_MASK																												  0x0004
#define SERIAL_SSR_BFF_SHIFT																												   5
#define SERIAL_SSR_BFF_MASK																												  0x0020
#define SERIAL_SSR_TSF_SHIFT																												   6
#define SERIAL_SSR_TSF_MASK																												  0x0040




/* Serial Flag Clear Trigger Register Definition */
typedef struct {
	union {
		volatile uint8_t SIR_L;
		volatile uint8_t SIR_H;
	}ACCESS_8bit;
	volatile uint16_t SIR;
} SIR_Type, *SIR_MemMapPtr;


#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_00_BASE										   												    (0x0104)
#define SIR00								       									((__near SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_00_BASE)

#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_01_BASE										  	 											   	(0x0106)
#define SIR01								       									((__near SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_01_BASE)

#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_10_BASE										   												   	(0x0134)
#define SIR10								       									((__near SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_10_BASE)

#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_11_BASE										   												   	(0x0136)
#define SIR11								       									((__near SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_11_BASE)


/* SIR Bit Fields */
#define SERIAL_SIR_OVC_SHIFT																												   0
#define SERIAL_SIR_OVC_MASK																												  0x0001
#define SERIAL_SIR_PEC_SHIFT																												   1
#define SERIAL_SIR_PEC_MASK																												  0x0002
#define SERIAL_SIR_FEC_SHIFT																												   2
#define SERIAL_SIR_FEC_MASK																												  0x0004




#define SERIAL_MODE_REGISTER_00_BASE											   													   	(0x0108)
#define SMR00										  								 *((__near volatile uint16_t *)SERIAL_MODE_REGISTER_00_BASE)

#define SERIAL_MODE_REGISTER_01_BASE											   													   	(0x010A)
#define SMR01										  								 *((__near volatile uint16_t *)SERIAL_MODE_REGISTER_01_BASE)

#define SERIAL_MODE_REGISTER_10_BASE											   													   	(0x0138)
#define SMR10										  								 *((__near volatile uint16_t *)SERIAL_MODE_REGISTER_10_BASE)

#define SERIAL_MODE_REGISTER_11_BASE											   													   	(0x013A)
#define SMR11										  								 *((__near volatile uint16_t *)SERIAL_MODE_REGISTER_11_BASE)


/* SMR Bit Fields */
#define SERIAL_SMR_MD0_SHIFT																												   0
#define SERIAL_SMR_MD0_MASK																												  0x0007
#define SERIAL_SMR_MD0_VALUE(x)										   (((uint16_t)(((uint16_t)(x))<<SERIAL_SMR_MD0_SHIFT))&SERIAL_SMR_MD0_MASK)
#define SERIAL_SMR_SIS_SHIFT																												   6
#define SERIAL_SMR_SIS_MASK																												  0x0040
#define SERIAL_SMR_STS_SHIFT																												   8
#define SERIAL_SMR_STS_MASK																												  0x0100
#define SERIAL_SMR_CCS_SHIFT																												  14
#define SERIAL_SMR_CCS_MASK																												  0x4000
#define SERIAL_SMR_CKS_SHIFT																												  15
#define SERIAL_SMR_CKS_MASK																												  0x8000




#define SERIAL_COMM_OPER_REGISTER_00_BASE										   													   	(0x010C)
#define SCR00									     							*((__near volatile uint16_t *)SERIAL_COMM_OPER_REGISTER_00_BASE)

#define SERIAL_COMM_OPER_REGISTER_01_BASE										   													   	(0x010E)
#define SCR01									     							*((__near volatile uint16_t *)SERIAL_COMM_OPER_REGISTER_01_BASE)

#define SERIAL_COMM_OPER_REGISTER_10_BASE										   													   	(0x013C)
#define SCR10									     							*((__near volatile uint16_t *)SERIAL_COMM_OPER_REGISTER_10_BASE)

#define SERIAL_COMM_OPER_REGISTER_11_BASE										   													   	(0x013E)
#define SCR11									     							*((__near volatile uint16_t *)SERIAL_COMM_OPER_REGISTER_11_BASE)


/*SCR Bit Fields */
#define SERIAL_SCR_DLS_SHIFT																												   0
#define SERIAL_SCR_DLS_MASK																												  0x000F
#define SERIAL_SCR_DLS_VALUE(x)										   (((uint16_t)(((uint16_t)(x))<<SERIAL_SCR_DLS_SHIFT))&SERIAL_SCR_DLS_MASK)
#define SERIAL_SCR_SLC_SHIFT																												   4
#define SERIAL_SCR_SLC_MASK																												  0x0030
#define SERIAL_SCR_SLC_VALUE(x)										   (((uint16_t)(((uint16_t)(x))<<SERIAL_SCR_SLC_SHIFT))&SERIAL_SCR_SLC_MASK)
#define SERIAL_SCR_DIR_SHIFT																												   7
#define SERIAL_SCR_DIR_MASK																												  0x0080
#define SERIAL_SCR_PTC_SHIFT																												   8
#define SERIAL_SCR_PTC_MASK																												  0x0300
#define SERIAL_SCR_PTC_VALUE(x)										   (((uint16_t)(((uint16_t)(x))<<SERIAL_SCR_PTC_SHIFT))&SERIAL_SCR_PTC_MASK)
#define SERIAL_SCR_DAPCKP_SHIFT																												  12
#define SERIAL_SCR_DAPCKP_MASK																											  0x3000
#define SERIAL_SCR_DAPCKP_VALUE(x)								 (((uint16_t)(((uint16_t)(x))<<SERIAL_SCR_DAPCKP_SHIFT))&SERIAL_SCR_DAPCKP_MASK)
#define SERIAL_SCR_RXTX_SHIFT																												  14
#define SERIAL_SCR_RXTX_MASK																											  0xC000
#define SERIAL_SCR_RXTX_VALUE(x)									 (((uint16_t)(((uint16_t)(x))<<SERIAL_SCR_RXTX_SHIFT))&SERIAL_SCR_RXTX_MASK)



/* ------------------------------------------------------------- Serial Control Registers --------------------------------------------------------- */










/* ------------------------------------------------------------- LVDS Control Registers ----------------------------------------------------------- */

/* Voltage Functions Register Definition */
typedef struct {
	volatile uint8_t LVIM;
	volatile uint8_t LVIS;
}LVDS_Type, *LVDS_MemMapPtr;


#define VOLTAGE_DETECTION_REGISTER_BASE											   													   	(0xFFA9)
#define LVDS									      									   ((__near LVDS_Type *)VOLTAGE_DETECTION_REGISTER_BASE)



/* LVIM Bit Fields */
#define LVDS_LVIM_LVIF_SHIFT																												   0
#define LVDS_LVIM_LVIF_MASK																													0x01
#define LVDS_LVIM_LVIOMSK_SHIFT																												   1
#define LVDS_LVIM_LVIOMSK_MASK																												0x02
#define LVDS_LVIM_LVISEN_SHIFT																												   7
#define LVDS_LVIM_LVISEN_MASK																												0x80


/* LVIS Bit Fields */
#define LVDS_LVIS_LVILV_SHIFT																												   0
#define LVDS_LVIS_LVILV_MASK																												0x01
#define LVDS_LVIS_LVIMD_SHIFT																												   7
#define LVDS_LVIS_LVIMD_MASK																												0x80

/* ------------------------------------------------------------- LVDS Control Registers ----------------------------------------------------------- */











/* ------------------------------------------------------- Priority Specification Registers ------------------------------------------------------ */

/* Priority Specification Flag Register Definition */
typedef union {
	union {
		volatile uint8_t PR_L;
		volatile uint8_t PR_H;
	}ACCESS_8bit;
	volatile uint16_t PR;
}PRS_Type, *PRS_MemMapPtr;


#define PRIORITY_SPECIFICATION_FLAG_REGISTER_00_BASE									   											   	(0xFFE8)
#define PR00								 								   ((__near PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_00_BASE)


/* PR00 Bit Fields */
#define INT_PR00_WDTIPR0_SHIFT																												   0
#define INT_PR00_WDTIPR0_MASK																											  0x0001
#define INT_PR00_LVIPR0_SHIFT																												   1
#define INT_PR00_LVIPR0_MASK																											  0x0002
#define INT_PR00_PPR00_SHIFT																												   2
#define INT_PR00_PPR00_MASK																												  0x0004
#define INT_PR00_PPR01_SHIFT																												   3
#define INT_PR00_PPR01_MASK																												  0x0008
#define INT_PR00_PPR02_SHIFT																												   4
#define INT_PR00_PPR02_MASK																												  0x0010
#define INT_PR00_PPR03_SHIFT																												   5
#define INT_PR00_PPR03_MASK																												  0x0020
#define INT_PR00_PPR04_SHIFT																												   6
#define INT_PR00_PPR04_MASK																												  0x0040
#define INT_PR00_PPR05_SHIFT																												   7
#define INT_PR00_PPR05_MASK																												  0x0080
#define INT_PR00_CLMPR0_SHIFT																												   8
#define INT_PR00_CLMPR0_MASK																											  0x0100
#define INT_PR00_CSIPR00_SHIFT																												   9
#define INT_PR00_CSIPR00_MASK																											  0x0200
#define INT_PR00_CSIPR01_SHIFT																												  10
#define INT_PR00_CSIPR01_MASK																											  0x0400
#define INT_PR00_DMAPR00_SHIFT																												  11
#define INT_PR00_DMAPR00_MASK																											  0x0800
#define INT_PR00_DMAPR01_SHIFT																												  12
#define INT_PR00_DMAPR01_MASK																											  0x1000
#define INT_PR00_RTCPR0_SHIFT																												  13
#define INT_PR00_RTCPR0_MASK																											  0x2000
#define INT_PR00_ITPR0_SHIFT																												  14
#define INT_PR00_ITPR0_MASK																												  0x4000
#define INT_PR00_LTPR00_SHIFT																												  15
#define INT_PR00_LTPR00_MASK																											  0x8000






#define PRIORITY_SPECIFICATION_FLAG_REGISTER_01_BASE									   											   	(0xFFEA)
#define PR01								 								   ((__near PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_01_BASE)


/* PR01 Bit Fields */
#define INT_PR01_LRPR00_SHIFT																												   0
#define INT_PR01_LRPR00_MASK																											  0x0001
#define INT_PR01_LSPR00_SHIFT																												   1
#define INT_PR01_LSPR00_MASK																											  0x0002
#define INT_PR01_PPR0LR0_SHIFT																												   2
#define INT_PR01_PPR0LR0_MASK																											  0x0004
#define INT_PR01_SGPR0_SHIFT																												   3
#define INT_PR01_SGPR0_MASK																												  0x0008
#define INT_PR01_TMPR000_SHIFT																												   4
#define INT_PR01_TMPR000_MASK																											  0x0010
#define INT_PR01_TMPR001_SHIFT																												   5
#define INT_PR01_TMPR001_MASK																											  0x0020
#define INT_PR01_TMPR002_SHIFT																												   6
#define INT_PR01_TMPR002_MASK																											  0x0040
#define INT_PR01_TMPR003_SHIFT																												   7
#define INT_PR01_TMPR003_MASK																											  0x0080
#define INT_PR01_ADPR0_SHIFT																											   	   8
#define INT_PR01_ADPR0_MASK																												  0x0100
#define INT_PR01_LTPR01_SHIFT																											 	   9
#define INT_PR01_LTPR01_MASK																											  0x0200
#define INT_PR01_LRPR01_SHIFT																												  10
#define INT_PR01_LRPR01_MASK																											  0x0400
#define INT_PR01_LSPR01_SHIFT																												  11
#define INT_PR01_LSPR01_MASK																											  0x0800
#define INT_PR01_PPR0LR1_SHIFT																												  12
#define INT_PR01_PPR0LR1_MASK																											  0x1000
#define INT_PR01_CSIPR010_SHIFT																												  13
#define INT_PR01_CSIPR010_MASK																											  0x2000
#define INT_PR01_IICPR011_SHIFT																												  14
#define INT_PR01_IICPR011_MASK																											  0x4000
#define INT_PR01_TMPR004_SHIFT																												  15
#define INT_PR01_TMPR004_MASK																											  0x8000







#define PRIORITY_SPECIFICATION_FLAG_REGISTER_02_BASE									   											   	(0xFFD8)
#define PR02								 								   ((__near PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_02_BASE)


/* PR02 Bit Fields */
#define INT_PR02_TMPR005_SHIFT																												   0
#define INT_PR02_TMPR005_MASK																											  0x0001
#define INT_PR02_TMPR006_SHIFT																												   1
#define INT_PR02_TMPR006_MASK																											  0x0002
#define INT_PR02_TMPR007_SHIFT																												   2
#define INT_PR02_TMPR007_MASK																											  0x0004
#define INT_PR02_C1ERRPR0_SHIFT																												   3
#define INT_PR02_C1ERRPR0_MASK																											  0x0008
#define INT_PR02_C1WUPPR0_SHIFT																												   4
#define INT_PR02_C1WUPPR0_MASK																											  0x0010
#define INT_PR02_C0ERRPR0_SHIFT																												   5
#define INT_PR02_C0ERRPR0_MASK																											  0x0020
#define INT_PR02_C0WUPPR0_SHIFT																												   6
#define INT_PR02_C0WUPPR0_MASK																											  0x0040
#define INT_PR02_C0RECPR0_SHIFT																												   7
#define INT_PR02_C0RECPR0_MASK																											  0x0080
#define INT_PR02_C0TRXPR0_SHIFT																												   8
#define INT_PR02_C0TRXPR0_MASK																											  0x0100
#define INT_PR02_TMPR010_SHIFT																												   9
#define INT_PR02_TMPR010_MASK																										  	  0x0200
#define INT_PR02_TMPR011_SHIFT																												  10
#define INT_PR02_TMPR011_MASK																										  	  0x0400
#define INT_PR02_TMPR012_SHIFT																												  11
#define INT_PR02_TMPR012_MASK																										  	  0x0800
#define INT_PR02_TMPR013_SHIFT																												  12
#define INT_PR02_TMPR013_MASK																										  	  0x1000
#define INT_PR02_MDPR0_SHIFT																											      13
#define INT_PR02_MDPR0_MASK																											  	  0x2000
#define INT_PR02_C1RECPR0_SHIFT																												  14
#define INT_PR02_C1RECPR0_MASK																											  0x4000
#define INT_PR02_FLPR0_SHIFT																												  15
#define INT_PR02_FLPR0_MASK																											  	  0x8000







#define PRIORITY_SPECIFICATION_FLAG_REGISTER_03_BASE									   											   	(0xFFDA)
#define PR03								 								   ((__near PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_03_BASE)


/* PR03 Bit Fields */
#define INT_PR03_C1TRXPR0_SHIFT																												   0
#define INT_PR03_C1TRXPR0_MASK																											  0x0001
#define INT_PR03_TMPR014_SHIFT																												   1
#define INT_PR03_TMPR014_MASK																											  0x0002
#define INT_PR03_TMPR015_SHIFT																												   2
#define INT_PR03_TMPR015_MASK																											  0x0004
#define INT_PR03_TMPR016_SHIFT																												   3
#define INT_PR03_TMPR016_MASK																											  0x0008
#define INT_PR03_TMPR017_SHIFT																												   4
#define INT_PR03_TMPR017_MASK																											  0x0010
#define INT_PR03_TMPR020_SHIFT																												   5
#define INT_PR03_TMPR020_MASK																											  0x0020
#define INT_PR03_TMPR021_SHIFT																												   6
#define INT_PR03_TMPR021_MASK																											  0x0040
#define INT_PR03_TMPR022_SHIFT																												   7
#define INT_PR03_TMPR022_MASK																											  0x0080
#define INT_PR03_TMPR023_SHIFT																												   8
#define INT_PR03_TMPR023_MASK																											  0x0100
#define INT_PR03_TMPR024_SHIFT																												   9
#define INT_PR03_TMPR024_MASK																											  0x0200
#define INT_PR03_TMPR026_SHIFT																												  10
#define INT_PR03_TMPR026_MASK																											  0x0400
#define INT_PR03_DMAPR02_SHIFT																												  11
#define INT_PR03_DMAPR02_MASK																											  0x0800
#define INT_PR03_DMAPR03_SHIFT																												  12
#define INT_PR03_DMAPR03_MASK																											  0x1000




#define PRIORITY_SPECIFICATION_FLAG_REGISTER_10_BASE									   											   	(0xFFEC)
#define PR10								 								   ((__near PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_10_BASE)


/* PR10 Bit Fields */
#define INT_PR10_WDTIPR1_SHIFT																												   0
#define INT_PR10_WDTIPR1_MASK																											  0x0001
#define INT_PR10_LVIPR1_SHIFT																												   1
#define INT_PR10_LVIPR1_MASK																											  0x0002
#define INT_PR10_PPR10_SHIFT																												   2
#define INT_PR10_PPR10_MASK																												  0x0004
#define INT_PR10_PPR11_SHIFT																												   3
#define INT_PR10_PPR11_MASK																												  0x0008
#define INT_PR10_PPR12_SHIFT																												   4
#define INT_PR10_PPR12_MASK																												  0x0010
#define INT_PR10_PPR13_SHIFT																												   5
#define INT_PR10_PPR13_MASK																												  0x0020
#define INT_PR10_PPR14_SHIFT																												   6
#define INT_PR10_PPR14_MASK																												  0x0040
#define INT_PR10_PPR15_SHIFT																												   7
#define INT_PR10_PPR15_MASK																												  0x0080
#define INT_PR10_CLMPR1_SHIFT																												   8
#define INT_PR10_CLMPR1_MASK																											  0x0100
#define INT_PR10_CSIPR10_SHIFT																												   9
#define INT_PR10_CSIPR10_MASK																											  0x0200
#define INT_PR10_CSIPR11_SHIFT																												  10
#define INT_PR10_CSIPR11_MASK																											  0x0400
#define INT_PR10_DMAPR10_SHIFT																												  11
#define INT_PR10_DMAPR10_MASK																											  0x0800
#define INT_PR10_DMAPR11_SHIFT																												  12
#define INT_PR10_DMAPR11_MASK																											  0x1000
#define INT_PR10_RTCPR1_SHIFT																												  13
#define INT_PR10_RTCPR1_MASK																											  0x2000
#define INT_PR10_ITPR1_SHIFT																												  14
#define INT_PR10_ITPR1_MASK																												  0x4000
#define INT_PR10_LTPR10_SHIFT																												  15
#define INT_PR10_LTPR10_MASK																											  0x8000





#define PRIORITY_SPECIFICATION_FLAG_REGISTER_11_BASE									   											   	(0xFFEE)
#define PR11								 								   ((__near PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_11_BASE)


/* PR11 Bit Fields */
#define INT_PR11_LRPR10_SHIFT																												   0
#define INT_PR11_LRPR10_MASK																											  0x0001
#define INT_PR11_LSPR10_SHIFT																												   1
#define INT_PR11_LSPR10_MASK																											  0x0002
#define INT_PR11_PPR1LR0_SHIFT																												   2
#define INT_PR11_PPR1LR0_MASK																											  0x0004
#define INT_PR11_SGPR1_SHIFT																												   3
#define INT_PR11_SGPR1_MASK																												  0x0008
#define INT_PR11_TMPR100_SHIFT																												   4
#define INT_PR11_TMPR100_MASK																											  0x0010
#define INT_PR11_TMPR101_SHIFT																												   5
#define INT_PR11_TMPR101_MASK																											  0x0020
#define INT_PR11_TMPR102_SHIFT																												   6
#define INT_PR11_TMPR102_MASK																											  0x0040
#define INT_PR11_TMPR103_SHIFT																												   7
#define INT_PR11_TMPR103_MASK																											  0x0080
#define INT_PR11_ADPR1_SHIFT																											   	   8
#define INT_PR11_ADPR1_MASK																												  0x0100
#define INT_PR11_LTPR11_SHIFT																											 	   9
#define INT_PR11_LTPR11_MASK																											  0x0200
#define INT_PR11_LRPR11_SHIFT																												  10
#define INT_PR11_LRPR11_MASK																											  0x0400
#define INT_PR11_LSPR11_SHIFT																												  11
#define INT_PR11_LSPR11_MASK																											  0x0800
#define INT_PR11_PPR1LR1_SHIFT																												  12
#define INT_PR11_PPR1LR1_MASK																											  0x1000
#define INT_PR11_CSIPR110_SHIFT																												  13
#define INT_PR11_CSIPR110_MASK																											  0x2000
#define INT_PR11_IICPR111_SHIFT																												  14
#define INT_PR11_IICPR111_MASK																											  0x4000
#define INT_PR11_TMPR104_SHIFT																												  15
#define INT_PR11_TMPR104_MASK																											  0x8000







#define PRIORITY_SPECIFICATION_FLAG_REGISTER_12_BASE									   											   	(0xFFDC)
#define PR12								 								   ((__near PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_12_BASE)


/* PR12 Bit Fields */
#define INT_PR12_TMPR105_SHIFT																												   0
#define INT_PR12_TMPR105_MASK																											  0x0001
#define INT_PR12_TMPR106_SHIFT																												   1
#define INT_PR12_TMPR106_MASK																											  0x0002
#define INT_PR12_TMPR107_SHIFT																												   2
#define INT_PR12_TMPR107_MASK																											  0x0004
#define INT_PR12_C1ERRPR1_SHIFT																												   3
#define INT_PR12_C1ERRPR1_MASK																											  0x0008
#define INT_PR12_C1WUPPR1_SHIFT																												   4
#define INT_PR12_C1WUPPR1_MASK																											  0x0010
#define INT_PR12_C0ERRPR1_SHIFT																												   5
#define INT_PR12_C0ERRPR1_MASK																											  0x0020
#define INT_PR12_C0WUPPR1_SHIFT																												   6
#define INT_PR12_C0WUPPR1_MASK																											  0x0040
#define INT_PR12_C0RECPR1_SHIFT																												   7
#define INT_PR12_C0RECPR1_MASK																											  0x0080
#define INT_PR12_C0TRXPR1_SHIFT																												   8
#define INT_PR12_C0TRXPR1_MASK																											  0x0100
#define INT_PR12_TMPR110_SHIFT																												   9
#define INT_PR12_TMPR110_MASK																										  	  0x0200
#define INT_PR12_TMPR111_SHIFT																												  10
#define INT_PR12_TMPR111_MASK																										  	  0x0400
#define INT_PR12_TMPR112_SHIFT																												  11
#define INT_PR12_TMPR112_MASK																										  	  0x0800
#define INT_PR12_TMPR113_SHIFT																												  12
#define INT_PR12_TMPR113_MASK																										  	  0x1000
#define INT_PR12_MDPR1_SHIFT																											      13
#define INT_PR12_MDPR1_MASK																											  	  0x2000
#define INT_PR12_C1RECPR1_SHIFT																												  14
#define INT_PR12_C1RECPR1_MASK																											  0x4000
#define INT_PR12_FLPR1_SHIFT																												  15
#define INT_PR12_FLPR1_MASK																											  	  0x8000



#define PRIORITY_SPECIFICATION_FLAG_REGISTER_13_BASE									   											   	(0xFFDE)
#define PR13								 								   ((__near PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_13_BASE)


/* PR13 Bit Fields */
#define INT_PR13_C1TRXPR1_SHIFT																												   0
#define INT_PR13_C1TRXPR1_MASK																											  0x0001
#define INT_PR13_TMPR114_SHIFT																												   1
#define INT_PR13_TMPR114_MASK																											  0x0002
#define INT_PR13_TMPR115_SHIFT																												   2
#define INT_PR13_TMPR115_MASK																											  0x0004
#define INT_PR13_TMPR116_SHIFT																												   3
#define INT_PR13_TMPR116_MASK																											  0x0008
#define INT_PR13_TMPR117_SHIFT																												   4
#define INT_PR13_TMPR117_MASK																											  0x0010
#define INT_PR13_TMPR120_SHIFT																												   5
#define INT_PR13_TMPR120_MASK																											  0x0020
#define INT_PR13_TMPR121_SHIFT																												   6
#define INT_PR13_TMPR121_MASK																											  0x0040
#define INT_PR13_TMPR122_SHIFT																												   7
#define INT_PR13_TMPR122_MASK																											  0x0080
#define INT_PR13_TMPR123_SHIFT																												   8
#define INT_PR13_TMPR123_MASK																											  0x0100
#define INT_PR13_TMPR124_SHIFT																												   9
#define INT_PR13_TMPR124_MASK																											  0x0200
#define INT_PR13_TMPR126_SHIFT																												  10
#define INT_PR13_TMPR126_MASK																											  0x0400
#define INT_PR13_DMAPR12_SHIFT																												  11
#define INT_PR13_DMAPR12_MASK																											  0x0800
#define INT_PR13_DMAPR13_SHIFT																												  12
#define INT_PR13_DMAPR13_MASK																											  0x1000



/* ------------------------------------------------------- Priority Specification Registers ------------------------------------------------------ */










/* ----------------------------------------------------------- LCD Configuration Handlers ------------------------------------------------------------ */

typedef struct {
	volatile uint8_t LCDMD;
	volatile uint8_t LCDM;
	volatile uint8_t LCDC0;
	volatile uint8_t BL;
	union {
		union {
			volatile uint8_t LBDATA;
			volatile uint8_t LBDATAL;
		}ACCESS_8bit;
		volatile uint16_t LBDAT;
	}DREG;
	union {
		union {
			volatile uint8_t LBDATAR;
			volatile uint8_t LBDATARL;
		}ACCESS_8bit;
		volatile uint16_t LBDATR;
	}RDREG;
}LCD_Config0_Type, *LCD_Config0_MemMapPtr;


#define LCD_CONFIG_0_REGISTER_BASE																									   	(0xFF40)
#define LCD_CONFIG0																		 ((__near LCD_Config0_Type *)LCD_CONFIG_0_REGISTER_BASE)


/* LCDMD Bit Fields */
#define LCD_LCDMD_MDSET_SHIFT																												   4
#define LCD_LCDMD_MDSET_MASK																												0x30
#define LCD_LCDMD_MDSET_VALUE(x)									   (((uint8_t)(((uint8_t)(x))<<LCD_LCDMD_MDSET_SHIFT))&LCD_LCDMD_MDSET_MASK)


/* LCDM Bit Fields */
#define LCD_LCDM_SHIFT																														   0
#define LCD_LCDM_MASK																														0x05
#define LCD_LCDM_VALUE(x)															 (((uint8_t)(((uint8_t)(x))<<LCD_LCDM_SHIFT))&LCD_LCDM_MASK)
#define LCD_LCDM_SCOC_SHIFT																													   6
#define LCD_LCDM_SCOC_MASK																													0x40
#define LCD_LCDM_LCDON_SHIFT																												   7
#define LCD_LCDM_LCDON_MASK																													0x80


/* LCDC0 Bit Fields */
#define LCD_LCDC0_SHIFT																														   0
#define LCD_LCDC0_MASK																														0x07
#define LCD_LCDC0_VALUE(x)														   (((uint8_t)(((uint8_t)(x))<<LCD_LCDC0_SHIFT))&LCD_LCDC0_MASK)
#define LCD_LCDC4_SHIFT																														   4
#define LCD_LCDC4_MASK																														0x70
#define LCD_LCDC4_VALUE(x)														   (((uint8_t)(((uint8_t)(x))<<LCD_LCDC4_SHIFT))&LCD_LCDC4_MASK)








typedef struct {
	volatile uint8_t SEG0;
	volatile uint8_t SEG1;
	volatile uint8_t SEG2;
	volatile uint8_t SEG3;
	volatile uint8_t SEG4;
	volatile uint8_t SEG5;
	volatile uint8_t SEG6;
	volatile uint8_t SEG7;
	volatile uint8_t SEG8;
	volatile uint8_t SEG9;
	volatile uint8_t SEG10;
	volatile uint8_t SEG11;
	volatile uint8_t SEG12;
	volatile uint8_t SEG13;
	volatile uint8_t SEG14;
	volatile uint8_t SEG15;
	volatile uint8_t SEG16;
	volatile uint8_t SEG17;
	volatile uint8_t SEG18;
	volatile uint8_t SEG19;
	volatile uint8_t SEG20;
	volatile uint8_t SEG21;
	volatile uint8_t SEG22;
	volatile uint8_t SEG23;
	volatile uint8_t SEG24;
	volatile uint8_t SEG25;
	volatile uint8_t SEG26;
	volatile uint8_t SEG27;
	volatile uint8_t SEG28;
	volatile uint8_t SEG29;
	volatile uint8_t SEG30;
	volatile uint8_t SEG31;
	volatile uint8_t SEG32;
	volatile uint8_t SEG33;
	volatile uint8_t SEG34;
	volatile uint8_t SEG35;
	volatile uint8_t SEG36;
	volatile uint8_t SEG37;
	volatile uint8_t SEG38;
	volatile uint8_t SEG39;
	volatile uint8_t SEG40;
	volatile uint8_t SEG41;
	volatile uint8_t SEG42;
	volatile uint8_t SEG43;
	volatile uint8_t SEG44;
	volatile uint8_t SEG45;
	volatile uint8_t SEG46;
	volatile uint8_t SEG47;
	volatile uint8_t SEG48;
	volatile uint8_t SEG49;
	volatile uint8_t SEG50;
	volatile uint8_t SEG51;
	volatile uint8_t SEG52;
	volatile uint8_t SEG53;
}LCD_DATA_Type, *LCD_DATA_MemMapPtr;


#define LCD_DATA_REGISTER_BASE																										   	(0x0300)
#define LCD_DATA																				((__near LCD_DATA_Type *)LCD_DATA_REGISTER_BASE)





typedef struct {
	volatile uint8_t LBCTL;
	volatile uint8_t LBCYC;
	volatile uint8_t LBWST;
}LCD_Config1_Type, *LCD_Config1_MemMapPtr;


#define LCD_CONFIG_1_REGISTER_BASE																									   	(0x0018)
#define LCD_CONFIG1																		 ((__near LCD_Config1_Type *)LCD_CONFIG_1_REGISTER_BASE)


/* LBCTL Bit Fields */
#define LCD_LBCTL_BYF_SHIFT																													   0
#define LCD_LBCTL_BYF_MASK																													0x01
#define LCD_LBCTL_TPF_SHIFT																													   1
#define LCD_LBCTL_TPF_MASK																													0x02
#define LCD_LBCTL_TCIS_SHIFT																												   3
#define LCD_LBCTL_TCIS_MASK																													0x08
#define LCD_LBCTL_LBC_SHIFT																													   4
#define LCD_LBCTL_LBC_MASK																													0x30
#define LCD_LBCTL_LBC_VALUE(x)											   (((uint8_t)(((uint8_t)(x))<<LCD_LBCTL_LBC_SHIFT))&LCD_LBCTL_LBC_MASK)
#define LCD_LBCTL_IMD_SHIFT																													   6
#define LCD_LBCTL_IMD_MASK																													0x40
#define LCD_LBCTL_EL_SHIFT																													   7
#define LCD_LBCTL_EL_MASK																													0x80


/* LBCYC Bit Fields */
#define LCD_LBCYC_CYC_SHIFT																													   0
#define LCD_LBCYC_CYC_MASK																													0x3F
#define LCD_LBCYC_CYC_VALUE(x)											   (((uint8_t)(((uint8_t)(x))<<LCD_LBCYC_CYC_SHIFT))&LCD_LBCYC_CYC_MASK)


/* LBWST Bit Fields */
#define LCD_LBWST_WST_SHIFT																													   0
#define LCD_LBWST_WST_MASK																													0x1F
#define LCD_LBWST_WST_VALUE(x)											   (((uint8_t)(((uint8_t)(x))<<LCD_LBWST_WST_SHIFT))&LCD_LBWST_WST_MASK)






/* ----------------------------------------------------------- LCD Configuration Handlers ------------------------------------------------------------ */













/* ---------------------------------------------------------- UART Configuration Handlers ------------------------------------------------------------ */

typedef struct {
	volatile uint16_t UFTX;
	volatile uint16_t UFRX;
}LIN_UART_DR_Type, *LIN_UART_DR_MemMapPtr;


#define LIN_UART0_DATA_REGISTER_ADDRESS																								   	(0xFF48)
#define LIN_UART_DR0																((__near LIN_UART_DR_Type *)LIN_UART0_DATA_REGISTER_ADDRESS)

#define LIN_UART1_DATA_REGISTER_ADDRESS																								   	(0xFF4C)
#define LIN_UART_DR1																((__near LIN_UART_DR_Type *)LIN_UART1_DATA_REGISTER_ADDRESS)





typedef struct {
	volatile uint8_t UFCTL0;
	volatile uint8_t UFOPT0;
	volatile uint16_t UFCTL1;
	volatile uint8_t UFOPT1;
	volatile uint8_t UFOPT2;
	volatile uint16_t UFSTR;
	volatile uint16_t UFSTC;
	volatile uint16_t UFWTX;
	volatile uint8_t UFID;
	struct {
		volatile uint8_t UFBUF0;
		volatile uint8_t UFBUF1;
		volatile uint8_t UFBUF2;
		volatile uint8_t UFBUF3;
		volatile uint8_t UFBUF4;
		volatile uint8_t UFBUF5;
		volatile uint8_t UFBUF6;
		volatile uint8_t UFBUF7;
		volatile uint8_t UFBUF8;
	}DATA;
	volatile uint16_t UFBUCTL;
}LIN_UART_Type, *LIN_UART_MemMapPtr;


#define LIN_UART0_REGISTER_BASE																										   	(0x0240)
#define LIN_UART0																			   ((__near LIN_UART_Type *)LIN_UART0_REGISTER_BASE)

#define LIN_UART1_REGISTER_BASE																										   	(0x0260)
#define LIN_UART1																			   ((__near LIN_UART_Type *)LIN_UART1_REGISTER_BASE)



/* UFCTL0 Bit Fields */
#define UARTF_UFCTL0_UFSL_SHIFT																												   0
#define UARTF_UFCTL0_UFSL_MASK																												0x01
#define UARTF_UFCTL0_UFCL_SHIFT																												   1
#define UARTF_UFCTL0_UFCL_MASK																												0x02
#define UARTF_UFCTL0_UFPS_SHIFT																												   2
#define UARTF_UFCTL0_UFPS_MASK																												0x0C
#define UARTF_UFCTL0_UFPS_VALUE(x)								   (((uint8_t)(((uint8_t)(x))<<UARTF_UFCTL0_UFPS_SHIFT))&UARTF_UFCTL0_UFPS_MASK)
#define UARTF_UFCTL0_UFDIR_SHIFT																											   4
#define UARTF_UFCTL0_UFDIR_MASK																												0x10
#define UARTF_UFCTL0_UFRX_SHIFT																												   5
#define UARTF_UFCTL0_UFRX_MASK																												0x20
#define UARTF_UFCTLO_UFTX_SHIFT																												   6
#define UARTF_UFCTLO_UFTX_MASK																												0x40


/* UFOPT0 Bit Fields */
#define UARTF_UFOPT0_UFRDL_SHIFT																											   0
#define UARTF_UFOPT0_UFRDL_MASK																												0x01
#define UARTF_UFOPT0_UFTDL_SHIFT																											   1
#define UARTF_UFOPT0_UFTDL_MASK																												0x02
#define UARTF_UFOPT0_UFBLS_SHIFT																											   2
#define UARTF_UFOPT0_UFBLS_MASK																												0x1C
#define UARTF_UFOPT0_UFBLS_VALUE(x)								 (((uint8_t)(((uint8_t)(x))<<UARTF_UFOPT0_UFBLS_SHIFT))&UARTF_UFOPT0_UFBLS_MASK)
#define UARTF_UFOPT0_UFBTT_SHIFT																											   5
#define UARTF_UFOPT0_UFBTT_MASK																												0x20
#define UARTF_UFOPT0_UFBRT_SHIFT																											   6
#define UARTF_UFOPT0_UFBRT_MASK																												0x40
#define UARTF_UFOPT0_UFBRF_SHIFT																											   7
#define UARTF_UFOPT0_UFBRF_MASK																												0x80


/* UFCTL1 Bit Fields */
#define UARTF_UFCTL1_UFBRS_SHIFT																											   0
#define UARTF_UFCTL1_UFBRS_MASK																											  0x0FFF
#define UARTF_UFCTL1_UFBRS_VALUE(x)							   (((uint16_t)(((uint16_t)(x))<<UARTF_UFCTL1_UFBRS_SHIFT))&UARTF_UFCTL1_UFBRS_MASK)
#define UARTF_UFCTL1_UFPRS_SHIFT																											  13
#define UARTF_UFCTL1_UFPRS_MASK																											  0xE000
#define UARTF_UFCTL1_UFPRS_VALUE(x)							   (((uint16_t)(((uint16_t)(x))<<UARTF_UFCTL1_UFPRS_SHIFT))&UARTF_UFCTL1_UFPRS_MASK)


/* UFOPT1 Bit Fields */
#define UARTF_UFOPT1_UFDCS_SHIFT																											   0
#define UARTF_UFOPT1_UFDCS_MASK																												0x01
#define UARTF_UFOPT1_UFMD0_SHIFT																											   1
#define UARTF_UFOPT1_UFMD0_MASK																												0x06
#define UARTF_UFOPT1_UFMDO_VALUE(x)								 (((uint8_t)(((uint8_t)(x))<<UARTF_UFOPT1_UFMD0_SHIFT))&UARTF_UFOPT1_UFMD0_MASK)
#define UARTF_UFOPT1_UFACE_SHIFT																											   3
#define UARTF_UFOPT1_UFACE_MASK																												0x08
#define UARTF_UFOPT1_UFIPCS_SHIFT																											   4
#define UARTF_UFOPT1_UFIPCS_MASK																											0x10
#define UARTF_UFOPT1_UFEBC_SHIFT																											   5
#define UARTF_UFOPT1_UFEBC_MASK																												0x20
#define UARTF_UFOPT1_UFEBL_SHIFT																											   6
#define UARTF_UFOPT1_UFEBL_MASK																												0x40
#define UARTF_UFOPT1_UFEBE_SHIFT																											   7
#define UARTF_UFOPT1_UFEBE_MASK																												0x80


/* UFOPT2 Bit Fields */
#define UARTF_UFOPT2_UFITS_SHIFT																											   0
#define UARTF_UFOPT2_UFITS_MASK																												0x01
#define UARTF_UFOPT2_UFRXFL_SHIFT																											   1
#define UARTF_UFOPT2_UFRXFL_MASK																											0x02


/* UFSTR Bit Fields */
#define UARTF_UFSTR_UFOVE_SHIFT																												   0
#define UARTF_UFSTR_UFOVE_MASK																											  0x0001
#define UARTF_UFSTR_UFFE_SHIFT																												   1
#define UARTF_UFSTR_UFFE_MASK																											  0x0002
#define UARTF_UFSTR_UFPE_SHIFT																												   2
#define UARTF_UFSTR_UFPE_MASK																											  0x0004
#define UARTF_UFSTR_UFDCE_SHIFT																												   3
#define UARTF_UFSTR_UFDCE_MASK																											  0x0008
#define UARTF_UFSTR_UFBSF_SHIFT																												   4
#define UARTF_UFSTR_UFBSF_MASK																											  0x0010
#define UARTF_UFSTR_UFRSF_SHIFT																												   6
#define UARTF_UFSTR_UFRSF_MASK																											  0x0040
#define UARTF_UFSTR_UFTSF_SHIFT																												   7
#define UARTF_UFSTR_UFTSF_MASK																											  0x0080
#define UARTF_UFSTR_UFEBD_SHIFT																												   8
#define UARTF_UFSTR_UFEBD_MASK																											  0x0100
#define UARTF_UFSTR_UFIDM_SHIFT																												   9
#define UARTF_UFSTR_UFIDM_MASK																											  0x0200
#define UARTF_UFSTR_UFBUC_SHIFT																												  10
#define UARTF_UFSTR_UFBUC_MASK																											  0x0400
#define UARTF_UFSTR_UFHDC_SHIFT																												  11
#define UARTF_UFSTR_UFHDC_MASK																											  0x0800
#define UARTF_UFSTR_UFRPE_SHIFT																												  12
#define UARTF_UFSTR_UFRPE_MASK																											  0x1000
#define UARTF_UFSTR_UFCSE_SHIFT																												  13
#define UARTF_UFSTR_UFCSE_MASK																											  0x2000
#define UARTF_UFSTR_UFIPE_SHIFT																												  14
#define UARTF_UFSTR_UFIPE_MASK																											  0x4000


/* UFSTC Bit Fields */
#define UARTF_UFSTC_UFCLOVE_SHIFT																											   0
#define UARTF_UFSTC_UFCLOVE_MASK																										  0x0001
#define UARTF_UFSTC_UFCLFE_SHIFT																											   1
#define UARTF_UFSTC_UFCLFE_MASK																											  0x0002
#define UARTF_UFSTC_UFCLPE_SHIFT																											   2
#define UARTF_UFSTC_UFCLPE_MASK																											  0x0004
#define UARTF_UFSTC_UFCLDCE_SHIFT																											   3
#define UARTF_UFSTC_UFCLDCE_MASK																										  0x0008
#define UARTF_UFSTC_UFCLBSF_SHIFT																											   4
#define UARTF_UFSTC_UFCLBSF_MASK																										  0x0010
#define UARTF_UFSTC_UFCLEBD_SHIFT																											   8
#define UARTF_UFSTC_UFCLEBD_MASK																										  0x0100
#define UARTF_UFSTC_UFCLIDM_SHIFT																											   9
#define UARTF_UFSTC_UFCLIDM_MASK																										  0x0200
#define UARTF_UFSTC_UFCLBUC_SHIFT																											  10
#define UARTF_UFSTC_UFCLBUC_MASK																										  0x0400
#define UARTF_UFSTC_UFCLHDC_SHIFT																											  11
#define UARTF_UFSTC_UFCLHDC_MASK																										  0x0800
#define UARTF_UFSTC_UFCLRPE_SHIFT																											  12
#define UARTF_UFSTC_UFCLRPE_MASK																										  0x1000
#define UARTF_UFSTC_UFCLCSE_SHIFT																											  13
#define UARTF_UFSTC_UFCLCSE_MASK																										  0x2000
#define UARTF_UFSTC_UFCLIPE_SHIFT																											  14
#define UARTF_UFSTC_UFCLIPE_MASK																										  0x4000


/* UFBUCTL Bit Fields */
#define UARTF_UFBUCTL_UFBUL_SHIFT																											   0
#define UARTF_UFBUCTL_UFBUL_MASK																										  0x000F
#define UARTF_UFBUCTL_UFBUL_VALUE(x)						 (((uint16_t)(((uint16_t)(x))<<UARTF_UFBUCTL_UFBUL_SHIFT))&UARTF_UFBUCTL_UFBUL_MASK)
#define UARTF_UFBUCTL_UFTRQ_SHIFT																											   4
#define UARTF_UFBUCTL_UFTRQ_MASK																										  0x0010
#define UARTF_UFBUCTL_UFRRQ_SHIFT																											   5
#define UARTF_UFBUCTL_UFRRQ_MASK																										  0x0020
#define UARTF_UFBUCTL_UFNO_SHIFT																											   6
#define UARTF_UFBUCTL_UFNO_MASK																											  0x0040
#define UARTF_UFBUCTL_UFECS_SHIFT																											   7
#define UARTF_UFBUCTL_UFECS_MASK																										  0x0080
#define UARTF_UFBUCTL_UFCON_SHIFT																											   8
#define UARTF_UFBUCTL_UFCON_MASK																										  0x0100
#define UARTF_UFBUCTL_UFTW_SHIFT																											   9
#define UARTF_UFBUCTL_UFTW_MASK																											  0x0200



/* ---------------------------------------------------------- UART Configuration Handlers ------------------------------------------------------------ */











/* --------------------------------------------------------- PINSEL Configuration Handlers ----------------------------------------------------------- */

typedef struct {
	volatile uint8_t STSEL0;
	volatile uint8_t STSEL1;
	volatile uint8_t TISELSE;
	volatile uint8_t SGSEL;
}PINSEL_Type, *PINSEL_MemMapPtr;


#define PIN_SELECT_00_REGISTER_BASE																									   	(0xFF3C)
#define PINSEL0																				 ((__near PINSEL_Type *)PIN_SELECT_00_REGISTER_BASE)



/* STSEL0 Bit Fields */
#define PINSEL_STSEL0_SUARTF0_SHIFT																											   0
#define PINSEL_STSEL0_SUARTF0_MASK																											0x01
#define PINSEL_STSEL0_SUARTF1_SHIFT																											   1
#define PINSEL_STSEL0_SUARTF1_MASK																											0x02
#define PINSEL_STSEL0_SCSI000_SHIFT																											   2
#define PINSEL_STSEL0_SCSI000_MASK																											0x0C
#define PINSEL_STSEL0_SCSI000_VALUE(x)					   (((uint8_t)(((uint8_t)(x))<<PINSEL_STSEL0_SCSI000_SHIFT))&PINSEL_STSEL0_SCSI000_MASK)
#define PINSEL_STSEL0_SCSI010_SHIFT																											   4
#define PINSEL_STSEL0_SCSI010_MASK																											0x10
#define PINSEL_STSEL0_SCSI100_SHIFT																											   6
#define PINSEL_STSEL0_SCSI100_MASK																											0x40


/* STSEL1 Bit Fields */
#define PINSEL_STSEL1_TMCAN_SHIFT																											   0
#define PINSEL_STSEL1_TMCAN_MASK																											0x03
#define PINSEL_STSEL1_TMCAN_VALUE(x)						   (((uint8_t)(((uint8_t)(x))<<PINSEL_STSEL1_TMCAN_SHIFT))&PINSEL_STSEL1_TMCAN_MASK)
#define PINSEL_STSEL1_SCAN_SHIFT																											   2
#define PINSEL_STSEL1_SCAN_MASK																												0x0C
#define PINSEL_STSEL1_SCAN_VALUE(x)								 (((uint8_t)(((uint8_t)(x))<<PINSEL_STSEL1_SCAN_SHIFT))&PINSEL_STSEL1_SCAN_MASK)
#define PINSEL_STSEL1_SIIC_SHIFT																											   6
#define PINSEL_STSEL1_SIIC_MASK																												0xC0
#define PINSEL_STSEL1_SIIC_VALUE(x)								 (((uint8_t)(((uint8_t)(x))<<PINSEL_STSEL1_SIIC_SHIFT))&PINSEL_STSEL1_SIIC_MASK)


/* TISELSE Bit Fields */
#define PINSEL_TISELSE_TI05SEL_SHIFT																										   0
#define PINSEL_TISELSE_TI05SEL_MASK																											0x03
#define PINSEL_TISELSE_TI05SEL_VALUE(x)					 (((uint8_t)(((uint8_t)(x))<<PINSEL_TISELSE_TI05SEL_SHIFT))&PINSEL_TISELSE_TI05SEL_MASK)
#define PINSEL_TISELSE_TOTICON_SHIFT																										   6
#define PINSEL_TISELSE_TOTICON_MASK																											0xC0
#define PINSEL_TISELSE_TOTICON_VALUE(x)					 (((uint8_t)(((uint8_t)(x))<<PINSEL_TISELSE_TOTICON_SHIFT))&PINSEL_TISELSE_TOTICON_MASK)


/* SGSEL Bit Fields */
#define PINSEL_SGSEL_SHIFT																													   0
#define PINSEL_SGSEL_MASK																													0x07
#define PINSEL_SGSEL_VALUE(x)												 (((uint8_t)(((uint8_t)(x))<<PINSEL_SGSEL_SHIFT))&PINSEL_SGSEL_MASK)
#define PINSEL_SGSEL_PCLSEL_SHIFT																											   3
#define PINSEL_SGSEL_PCLSEL_MASK																											0x08

/* --------------------------------------------------------- PINSEL Configuration Handlers ----------------------------------------------------------- */












/* ----------------------------------------------------------- PLL Configuration Handlers ------------------------------------------------------------ */

typedef struct {
	volatile uint8_t PLLSTS;
	volatile uint8_t PLLCTL;
}PLL_Type, *PLL_MemMapPtr;


#define PLL_CONFIG_REGISTER_BASE																									   	(0x0128)
#define PLL																						   ((__near PLL_Type *)PLL_CONFIG_REGISTER_BASE)


/* PLLSTS Bit Fields */
#define PLL_PLLSTS_SELPLLS_SHIFT																											   3
#define PLL_PLLSTS_SELPLLS_MASK																												0x08
#define PLL_PLLSTS_LOCK_SHIFT																												   7
#define PLL_PLLSTS_LOCK_MASK																												0x80


/* PLLCTL Bit Fields */
#define PLL_PLLCTL_PLLON_SHIFT																												   0
#define PLL_PLLCTL_PLLON_MASK																												0x01
#define PLL_PLLCTL_SELPLL_SHIFT																												   2
#define PLL_PLLCTL_SELPLL_MASK																												0x04
#define PLL_PLLCTL_PLLDIV0_SHIFT																											   4
#define PLL_PLLCTL_PLLDIV0_MASK																												0x10
#define PLL_PLLCTL_LCKSEL_SHIFT																												   6
#define PLL_PLLCTL_LCKSEL_MASK																												0xC0
#define PLL_PLLCTL_LCKSEL_VALUE(x)								   (((uint8_t)(((uint8_t)(x))<<PLL_PLLCTL_LCKSEL_SHIFT))&PLL_PLLCTL_LCKSEL_MASK)


/* ----------------------------------------------------------- PLL Configuration Handlers ------------------------------------------------------------ */












/* ---------------------------------------------------- Sound Generator Configuration Handlers ------------------------------------------------------- */

typedef struct {
	volatile uint16_t SGFL;
	volatile uint16_t SGFH;
	volatile uint16_t SGPWM;
	volatile uint8_t SGSDF;
	volatile uint8_t SGCTL;
	volatile uint16_t SGITH;
}SG_Type, *SG_MemMapPtr;


#define SOUND_GENERATOR_CONFIG_REGISTER_BASE																						   	(0x0280)
#define SG																				((__near SG_Type *)SOUND_GENERATOR_CONFIG_REGISTER_BASE)


/* SGFL Bit Fields */
#define SG_SGFL_SHIFT																														   0
#define SG_SGFL_MASK																													  0x01FF
#define SG_SGFL_VALUE(x)															 (((uint16_t)(((uint16_t)(x))<<SG_SGFL_SHIFT))&SG_SGFL_MASK)


/* SGFH Bit Fields */
#define SG_SGFH_SHIFT																														   0
#define SG_SGFH_MASK																													  0x01FF
#define SG_SGFH_VALUE(x)															 (((uint16_t)(((uint16_t)(x))<<SG_SGFH_SHIFT))&SG_SGFH_MASK)


/* SGPWM Bit Fields */
#define SG_SGPWM_SHIFT																														   0
#define SG_SGPWM_MASK																													  0x01FF
#define SG_SGPWM_VALUE(x)														   (((uint16_t)(((uint16_t)(x))<<SG_SGPWM_SHIFT))&SG_SGPWM_MASK)


/* SGCTL Bit Fields */
#define SG_SGCTL_SGALDS_SHIFT																												   0
#define SG_SGCTL_SGALDS_MASK																												0x01
#define SG_SGCTL_SGOS_SHIFT																													   1
#define SG_SGCTL_SGOS_MASK																													0x02
#define SG_SGCTL_SGPWR_SHIFT																												   4
#define SG_SGCTL_SGPWR_MASK																													0x10


/* SGITH Bit Fields */
#define SG_SGITH_SHIFT																														   0
#define SG_SGITH_MASK																													  0x01FF
#define SG_SGITH_VALUE(x)														   (((uint16_t)(((uint16_t)(x))<<SG_SGITH_SHIFT))&SG_SGITH_MASK)

/* ---------------------------------------------------- Sound Generator Configuration Handlers ------------------------------------------------------- */











/* ----------------------------------------------------------- ZPD Configuration Handlers ------------------------------------------------------------ */

typedef struct {
	volatile uint8_t ZPDS0;
	volatile uint8_t ZPDS1;
	volatile uint8_t CMPCTL;
	volatile uint8_t ZPDEN;
}ZPD_Type, *ZPD_MemMapPtr;


#define ZPD_CONTROL_REGISTER_BASE																									   	(0x015C)
#define ZPD																						  ((__near ZPD_Type *)ZPD_CONTROL_REGISTER_BASE)


/* ZPDS0 Bit Fields */
#define ZPD_ZPDS0_ZPD1S_SHIFT																												   0
#define ZPD_ZPDS0_ZPD1S_MASK																												0x07
#define ZPD_ZPDS0_ZPD1S_VALUE(x)									   (((uint8_t)(((uint8_t)(x))<<ZPD_ZPDS0_ZPD1S_SHIFT))&ZPD_ZPDS0_ZPD1S_MASK)
#define ZPD_ZPDS0_ZPD1PC_SHIFT																												   3
#define ZPD_ZPDS0_ZPD1PC_MASK																												0x08
#define ZPD_ZPDS0_ZPD2S_SHIFT																												   4
#define ZPD_ZPDS0_ZPD2S_MASK																												0x70
#define ZPD_ZPDS0_ZPD2S_VALUE(x)									   (((uint8_t)(((uint8_t)(x))<<ZPD_ZPDS0_ZPD2S_SHIFT))&ZPD_ZPDS0_ZPD2S_MASK)
#define ZPD_ZPDS0_ZPD2PC_SHIFT																												   7
#define ZPD_ZPDS0_ZPD2PC_MASK																												0x80


/* ZPDS1 Bit Fields */
#define ZPD_ZPDS1_ZPD3S_SHIFT																												   0
#define ZPD_ZPDS1_ZPD3S_MASK																												0x07
#define ZPD_ZPDS1_ZPD3S_VALUE(x)									   (((uint8_t)(((uint8_t)(x))<<ZPD_ZPDS1_ZPD3S_SHIFT))&ZPD_ZPDS1_ZPD3S_MASK)
#define ZPD_ZPDS1_ZPD3PC_SHIFT																												   3
#define ZPD_ZPDS1_ZPD3PC_MASK																												0x08
#define ZPD_ZPDS1_ZPD4S_SHIFT																												   4
#define ZPD_ZPDS1_ZPD4S_MASK																												0x70
#define ZPD_ZPDS1_ZPD4S_VALUE(x)									   (((uint8_t)(((uint8_t)(x))<<ZPD_ZPDS1_ZPD4S_SHIFT))&ZPD_ZPDS1_ZPD4S_MASK)
#define ZPD_ZPDS1_ZPD4PC_SHIFT																												   7
#define ZPD_ZPDS1_ZPD4PC_MASK																												0x80


/* CMPCTL Bit Fields */
#define ZPD_CMPCTL_DBCL_SHIFT																												   0
#define ZPD_CMPCTL_DBCL_MASK																												0x0F
#define ZPD_CMPCTL_DBCL_VALUE(x)									   (((uint8_t)(((uint8_t)(x))<<ZPD_CMPCTL_DBCL_SHIFT))&ZPD_CMPCTL_DBCL_MASK)


/* ZPDEN Bit Fields */
#define ZPD_ZPDEN_SHIFT																														   0
#define ZPD_ZPDEN_MASK																														0x0F
#define ZPD_ZPDEN_VALUE(x)														   (((uint8_t)(((uint8_t)(x))<<ZPD_ZPDEN_SHIFT))&ZPD_ZPDEN_MASK)

/* ----------------------------------------------------------- ZPD Configuration Handlers ------------------------------------------------------------ */












/* ----------------------------------------------------------- CMP Configuration Handlers ------------------------------------------------------------ */

typedef struct {
	union{
		volatile uint8_t MCMP_L;
		volatile uint8_t MCMP_H;
	}ACCESS_8bit;
	volatile uint16_t MCMP;
}CMP_Type, *CMP_MemMapPtr;


#define COMPARE_REGISTER_10_BASE																									   	(0x0162)
#define CMP10																					   ((__near CMP_Type *)COMPARE_REGISTER_10_BASE)

#define COMPARE_REGISTER_20_BASE																									   	(0x0164)
#define CMP20																					   ((__near CMP_Type *)COMPARE_REGISTER_20_BASE)

#define COMPARE_REGISTER_30_BASE																									   	(0x0166)
#define CMP30																					   ((__near CMP_Type *)COMPARE_REGISTER_30_BASE)

#define COMPARE_REGISTER_40_BASE																									   	(0x0168)
#define CMP40																					   ((__near CMP_Type *)COMPARE_REGISTER_40_BASE)





#define TIMER_MODE_CONTROL_REGISTER_BASE																							   	(0x0160)
#define MCNTC0																	  *((__near volatile uint8_t *)TIMER_MODE_CONTROL_REGISTER_BASE)


/* MCNTC0 Bit Fields */
#define TIMER_MCNTC0_SMCL_SHIFT																												   0
#define TIMER_MCNTC0_SMCL_MASK																												0x07
#define TIMER_MCNTC0_SMCL_VALUE(x)							 	   (((uint8_t)(((uint8_t)(x))<<TIMER_MCNTC0_SMCL_SHIFT))&TIMER_MCNTC0_SMCL_MASK)
#define TIMER_MCNTC0_PCS_SHIFT																												   3
#define TIMER_MCNTC0_PCS_MASK																												0x08
#define TIMER_MCNTC0_PCE_SHIFT																												   4
#define TIMER_MCNTC0_PCE_MASK																												0x10
#define TIMER_MCNTC0_FULL_SHIFT																												   5
#define TIMER_MCNTC0_FULL_MASK																												0x20
#define TIMER_MCNTC0_CAE_SHIFT																												   7
#define TIMER_MCNTC0_CAE_MASK																												0x80





#define COMPARE_CONTROL_REGISTER_1_BASE																								   	(0x016A)
#define MCMPC1																	   *((__near volatile uint8_t *)COMPARE_CONTROL_REGISTER_1_BASE)

#define COMPARE_CONTROL_REGISTER_2_BASE																								   	(0x016C)
#define MCMPC2																	   *((__near volatile uint8_t *)COMPARE_CONTROL_REGISTER_2_BASE)

#define COMPARE_CONTROL_REGISTER_3_BASE																								   	(0x016E)
#define MCMPC3																	   *((__near volatile uint8_t *)COMPARE_CONTROL_REGISTER_3_BASE)

#define COMPARE_CONTROL_REGISTER_4_BASE																								   	(0x0158)
#define MCMPC4																	   *((__near volatile uint8_t *)COMPARE_CONTROL_REGISTER_4_BASE)


/* MCMPC Bit Fields */
#define CMP_MCMPC_DIR_SHIFT																													   0
#define CMP_MCMPC_DIR_MASK																													0x03
#define CMP_MCMPC_DIR_VALUE(x)											   (((uint8_t)(((uint8_t)(x))<<CMP_MCMPC_DIR_SHIFT))&CMP_MCMPC_DIR_MASK)
#define CMP_MCMPC_ADB_SHIFT																													   2
#define CMP_MCMPC_ADB_MASK																													0x0C
#define CMP_MCMPC_ADB_VALUE(x)											   (((uint8_t)(((uint8_t)(x))<<CMP_MCMPC_ADB_SHIFT))&CMP_MCMPC_ADB_MASK)
#define CMP_MCMPC_TEN_SHIFT																													   4
#define CMP_MCMPC_TEN_MASK																													0x10
#define CMP_MCMPC_ZPD_SHIFT																													   5
#define CMP_MCMPC_ZPD_MASK																													0x20
#define CMP_MCMPC_TWIN_SHIFT																												   6
#define CMP_MCMPC_TWIN_MASK																													0x40
#define CMP_MCMPC_AOUT_SHIFT																												   7
#define CMP_MCMPC_AOUT_MASK																													0x80


/* ----------------------------------------------------------- CMP Configuration Handlers ------------------------------------------------------------ */










/* ----------------------------------------------------------- CAN Configuration Handlers ------------------------------------------------------------ */

typedef struct {
	volatile uint16_t CGMCTRL;
	volatile uint8_t CGMCS;
	volatile uint8_t BL[3];
	volatile uint16_t CGMABT;
	volatile uint8_t CGMABTD;
}CAN_GLBL_CTRL_Type, *CAN_GLBL_CTRL_MemMapPtr;


#define CAN0_GLOBAL_CTRL_REGISTER_BASE																								   	(0x05C0)
#define CAN0_GLBL_CTRL															   ((__near CAN_GLBL_CTRL_Type *)CAN0_GLOBAL_CTRL_REGISTER_BASE)

#define CAN1_GLOBAL_CTRL_REGISTER_BASE																								   	(0x0340)
#define CAN1_GLBL_CTRL															   ((__near CAN_GLBL_CTRL_Type *)CAN1_GLOBAL_CTRL_REGISTER_BASE)


/* CGMCTRL Bit Fields */
#define CAN_CGMCTRL_READ_GOM_SHIFT																											   0
#define CAN_CGMCTRL_READ_GOM_MASK																										  0x0001
#define CAN_CGMCTRL_READ_EFSD_SHIFT																											   1
#define CAN_CGMCTRL_READ_EFSD_MASK																										  0x0002
#define CAN_CGMCTRL_SET_GOM_SHIFT																											   8
#define CAN_CGMCTRL_SET_GOM_MASK																										  0x0100
#define CAN_CGMCTRL_SET_EFSD_SHIFT																											   9
#define CAN_CGMCTRL_SET_EFSD_MASK																										  0x0200
#define CAN_CGMCTRL_READ_MBON_SHIFT																											  15
#define CAN_CGMCTRL_READ_MBON_MASK																										  0x8000


/* CGMCS Bit Fields */
#define CAN_CGMCS_CCP_SHIFT																													   0
#define CAN_CGMCS_CCP_MASK																													0x0F
#define CAN_CGMCS_CCP_VALUE(x)											   (((uint8_t)(((uint8_t)(x))<<CAN_CGMCS_CCP_SHIFT))&CAN_CGMCS_CCP_MASK)


/* CGMABT Bit Fields */
#define CAN_CGMABT_READ_ABTTRG_SHIFT																										   0
#define CAN_CGMABT_READ_ABTTRG_MASK																										  0x0001
#define CAN_CGMABT_READ_ABTCLR_SHIFT																										   1
#define CAN_CGMABT_READ_ABTCLR_MASK																										  0x0002
#define CAN_CGMABT_SET_ABTTRG_SHIFT																											   8
#define CAN_CGMABT_SET_ABTTRG_MASK																										  0x0100
#define CAN_CGMABT_SET_ABTCLR_SHIFT																											   9
#define CAN_CGMABT_SET_ABTCLR_MASK																										  0x0200


/* CGMABTD Bit Fields */
#define CAN_CGMABTD_ABTD_SHIFT																												   0
#define CAN_CGMABTD_ABTD_MASK																												0x0F
#define CAN_CGMABTD_ABTD_VALUE(x)									 (((uint8_t)(((uint8_t)(x))<<CAN_CGMABTD_ABTD_SHIFT))&CAN_CGMABTD_ABTD_MASK)





typedef struct {
	volatile uint16_t CMASK1L;
	volatile uint16_t CMASK1H;
	volatile uint16_t CMASK2L;
	volatile uint16_t CMASK2H;
	volatile uint16_t CMASK3L;
	volatile uint16_t CMASK3H;
	volatile uint16_t CMASK4L;
	volatile uint16_t CMASK4H;
}CAN_MASK_Type, *CAN_MASK_MemMapPtr;


#define CAN0_MASK_REGISTER_BASE																										   	(0x05D0)
#define CAN0_MASK																			   ((__near CAN_MASK_Type *)CAN0_MASK_REGISTER_BASE)

#define CAN1_MASK_REGISTER_BASE																										   	(0x0380)
#define CAN1_MASK																			   ((__near CAN_MASK_Type *)CAN1_MASK_REGISTER_BASE)





typedef struct {
	volatile uint16_t CCTRL;
	volatile uint8_t CLEC;
	volatile uint8_t CINFO;
	volatile uint16_t CERC;
	volatile uint16_t CIE;
	volatile uint16_t CINTS;
	volatile uint16_t CBRP;
	volatile uint16_t CBTR;
	volatile uint16_t CLIPT;
	volatile uint16_t CRGPT;
	volatile uint16_t CLOPT;
	volatile uint16_t CTGPT;
	volatile uint16_t CTS;
}CAN_INFO_Type, *CAN_INFO_MemMapPtr;


#define CAN0_INFO_REGISTER_BASE																										   	(0x05E0)
#define CAN0_INFO																			   ((__near CAN_INFO_Type *)CAN1_INFO_REGISTER_BASE)

#define CAN1_INFO_REGISTER_BASE																										   	(0x0390)
#define CAN1_INFO																			   ((__near CAN_INFO_Type *)CAN1_INFO_REGISTER_BASE)


/* CCTRL Bit Fields */
#define CAN_CCTRL_READ_OPMODE_SHIFT																											   0
#define CAN_CCTRL_READ_OPMODE_MASK																										  0x0007
#define CAN_CCTRL_READ_OPMODE_VALUE(x)					 (((uint16_t)(((uint16_t)(x))<<CAN_CCTRL_READ_OPMODE_SHIFT))&CAN_CCTRL_READ_OPMODE_MASK)
#define CAN_CCTRL_READ_PSMODE_SHIFT																											   3
#define CAN_CCTRL_READ_PSMODE_MASK																										  0x0018
#define CAN_CCTRL_READ_PSMODE_VALUE(x)					 (((uint16_t)(((uint16_t)(x))<<CAN_CCTRL_READ_PSMODE_SHIFT))&CAN_CCTRL_READ_PSMODE_MASK)
#define CAN_CCTRL_READ_VALID_SHIFT																											   5
#define CAN_CCTRL_READ_VALID_MASK																										  0x0020
#define CAN_CCTRL_READ_AL_SHIFT																												   6
#define CAN_CCTRL_READ_AL_MASK																											  0x0040
#define CAN_CCTRL_READ_CCERC_SHIFT																											   7
#define CAN_CCTRL_READ_CCERC_MASK																										  0x0080
#define CAN_CCTRL_READ_TSTAT_SHIFT																											   8
#define CAN_CCTRL_READ_TSTAT_MASK																										  0x0100
#define CAN_CCTRL_READ_RSTAT_SHIFT																											   9
#define CAN_CCTRL_READ_RSTAT_MASK																										  0x0200
#define CAN_CCTRL_SET_OPMODE_SHIFT																											   8
#define CAN_CCTRL_SET_OPMODE_MASK																										  0x0700
#define CAN_CCTRL_SET_OPMODE_VALUE(x)					   (((uint16_t)(((uint16_t)(x))<<CAN_CCTRL_SET_OPMODE_SHIFT))&CAN_CCTRL_SET_OPMODE_MASK)
#define CAN_CCTRL_SET_PSMODE_SHIFT																											  11
#define CAN_CCTRL_SET_PSMODE_MASK																										  0x1800
#define CAN_CCTRL_SET_PSMODE_VALUE(x)					   (((uint16_t)(((uint16_t)(x))<<CAN_CCTRL_SET_PSMODE_SHIFT))&CAN_CCTRL_SET_PSMODE_MASK)
#define CAN_CCTRL_SET_AL_SHIFT																												  14
#define CAN_CCTRL_SET_AL_MASK																											  0x4000
#define CAN_CCTRL_SET_CCERC_SHIFT																											  15
#define CAN_CCTRL_SET_CCERC_MASK																										  0x8000


/* CLEC Bit Fields */
#define CAN_CLEC_READ_LEC_SHIFT																												   0
#define CAN_CLEC_READ_LEC_MASK																												0x07
#define CAN_CLEC_READ_LEC_VALUE(x)								   (((uint8_t)(((uint8_t)(x))<<CAN_CLEC_READ_LEC_SHIFT))&CAN_CLEC_READ_LEC_MASK)


/* CINFO Bit Fields */
#define CAN_CINFO_RECS_SHIFT																												   0
#define CAN_CINFO_RECS_MASK																													0x03
#define CAN_CINFO_RECS_VALUE(x)											 (((uint8_t)(((uint8_t)(x))<<CAN_CINFO_RECS_SHIFT))&CAN_CINFO_RECS_MASK)
#define CAN_CINFO_TECS_SHIFT																												   2
#define CAN_CINFO_TECS_MASK																													0x0C
#define CAN_CINFO_TECS_VALUE(x)											 (((uint8_t)(((uint8_t)(x))<<CAN_CINFO_TECS_SHIFT))&CAN_CINFO_TECS_MASK)
#define CAN_CINFO_BOFF_SHIFT																												   4
#define CAN_CINFO_BOFF_MASK																													0x10


/* CERC Bit Fields */
#define CAN_CERC_TEC_SHIFT																													   0
#define CAN_CERC_TEC_MASK																												  0x00FF
#define CAN_CERC_TEC_VALUE(x)											   (((uint16_t)(((uint16_t)(x))<<CAN_CERC_TEC_SHIFT))&CAN_CERC_TEC_MASK)
#define CAN_CERC_REC_SHIFT																													   8
#define CAN_CERC_REC_MASK																												  0x7F00
#define CAN_CERC_REC_VALUE(x)											   (((uint16_t)(((uint16_t)(x))<<CAN_CERC_REC_SHIFT))&CAN_CERC_REC_MASK)
#define CAN_CERC_REPS_SHIFT																													  15
#define CAN_CERC_REPS_MASK																												  0x8000


/* CIE Bit Fields */
#define CAN_CIE_READ_CIE_SHIFT																												   0
#define CAN_CIE_READ_CIE_MASK																											  0x003F
#define CAN_CIE_READ_CIE_VALUE(x)								   (((uint16_t)(((uint16_t)(x))<<CAN_CIE_READ_CIE_SHIFT))&CAN_CIE_READ_CIE_MASK)
#define CAN_CIE_SET_CIE_SHIFT																												   8
#define CAN_CIE_SET_CIE_MASK																											  0x3F00
#define CAN_CIE_SET_CIE_VALUE(x)									 (((uint16_t)(((uint16_t)(x))<<CAN_CIE_SET_CIE_SHIFT))&CAN_CIE_SET_CIE_MASK)


/* CINTS Bit Fields */
#define CAN_CINTS_READ_CINTS_SHIFT																											   0
#define CAN_CINTS_READ_CINTS_MASK																										  0x003F
#define CAN_CINTS_READ_CINTS_VALUE(x)					   (((uint16_t)(((uint16_t)(x))<<CAN_CINTS_READ_CINTS_SHIFT))&CAN_CINTS_READ_CINTS_MASK)


/* CBRP Bit Fields */
#define CAN_CBRP_TQPRS_SHIFT																												   0
#define CAN_CBRP_TQPRS_MASK																												  0x00FF
#define CAN_CBRP_TQPRS_VALUE(x)										   (((uint16_t)(((uint16_t)(x))<<CAN_CBRP_TQPRS_SHIFT))&CAN_CBRP_TQPRS_MASK)


/* CBTR Bit Fields */
#define CAN_CBTR_TSEG1_SHIFT																												   0
#define CAN_CBTR_TSEG1_MASK																												  0x000F
#define CAN_CBTR_TSEG1_VALUE(x)										   (((uint16_t)(((uint16_t)(x))<<CAN_CBTR_TSEG1_SHIFT))&CAN_CBTR_TSEG1_MASK)
#define CAN_CBTR_TSEG2_SHIFT																												   8
#define CAN_CBTR_TSEG2_MASK																												  0x0700
#define CAN_CBTR_TSEG2_VALUE(x)										   (((uint16_t)(((uint16_t)(x))<<CAN_CBTR_TSEG2_SHIFT))&CAN_CBTR_TSEG2_MASK)
#define CAN_CBTR_SJW_SHIFT																													  12
#define CAN_CBTR_SJW_MASK																												  0x3000
#define CAN_CBTR_SJW_VALUE(x)											   (((uint16_t)(((uint16_t)(x))<<CAN_CBTR_SJW_SHIFT))&CAN_CBTR_SJW_MASK)


/* CLIPT Bit Fields */
#define CAN_CLIPT_LIPT_SHIFT																												   0
#define CAN_CLIPT_LIPT_MASK																												  0x00FF
#define CAN_CLIPT_LIPT_VALUE(x)										   (((uint16_t)(((uint16_t)(x))<<CAN_CLIPT_LIPT_SHIFT))&CAN_CLIPT_LIPT_MASK)


/* CRGPT Bit Fields */
#define CAN_CRGPT_READ_ROVF_SHIFT																											   0
#define CAN_CRGPT_READ_ROVF_MASK																										  0x0001
#define CAN_CRGPT_READ_RHPM_SHIFT																											   1
#define CAN_CRGPT_READ_RHPM_MASK																										  0x0002
#define CAN_CRGPT_READ_RGPT_SHIFT																											   8
#define CAN_CRGPT_READ_RGPT_MASK																										  0xFF00
#define CAN_CRGPT_READ_RGPT_VALUE(x)						 (((uint16_t)(((uint16_t)(x))<<CAN_CRGPT_READ_RGPT_SHIFT))&CAN_CRGPT_READ_RGPT_MASK)


/* CLOPT Bit Fields */
#define CAN_CLOPT_LOPT_SHIFT																												   0
#define CAN_CLOPT_LOPT_MASK																												  0x00FF
#define CAN_CLOPT_LOPT_VALUE(x)										   (((uint16_t)(((uint16_t)(x))<<CAN_CLOPT_LOPT_SHIFT))&CAN_CLOPT_LOPT_MASK)


/* CTGPT Bit Fields */
#define CAN_CTGPT_READ_TOVF_SHIFT																											   0
#define CAN_CTGPT_READ_TOVF_MASK																										  0x0001
#define CAN_CTGPT_READ_THPM_SHIFT																											   1
#define CAN_CTGPT_READ_THPM_MASK																										  0x0002
#define CAN_CTGPT_READ_TGPT_SHIFT																											   8
#define CAN_CTGPT_READ_TGPT_MASK																										  0xFF00
#define CAN_CTGPT_READ_TGPT_VALUE(x)						 (((uint16_t)(((uint16_t)(x))<<CAN_CTGPT_READ_TGPT_SHIFT))&CAN_CTGPT_READ_TGPT_MASK)


/* CTS Bit Fields */
#define CAN_CTS_READ_TSEN_SHIFT																												   0
#define CAN_CTS_READ_TSEN_MASK																											  0x0001
#define CAN_CTS_READ_TSSEL_SHIFT																											   1
#define CAN_CTS_READ_TSSEL_MASK																											  0x0002
#define CAN_CTS_READ_TSLOCK_SHIFT																											   2
#define CAN_CTS_READ_TSLOCK_MASK																										  0x0004
#define CAN_CTS_SET_TSEN_SHIFT																												   8
#define CAN_CTS_SET_TSEN_MASK																											  0x0100
#define CAN_CTS_SET_TSSEL_SHIFT																												   9
#define CAN_CTS_SET_TSSEL_MASK																											  0x0200
#define CAN_CTS_SET_TSLOCK_SHIFT																											  10
#define CAN_CTS_SET_TSLOCK_MASK																											  0x0400







typedef struct {
	volatile uint8_t CMDB0;
	volatile uint8_t CMDB1;
	volatile uint8_t CMDB2;
	volatile uint8_t CMDB3;
	volatile uint8_t CMDB4;
	volatile uint8_t CMDB5;
	volatile uint8_t CMDB6;
	volatile uint8_t CMDB7;
	volatile uint8_t CMDLC;
	volatile uint8_t CMCONF;
	volatile uint16_t CMIDL;
	volatile uint16_t CMIDH;
	volatile uint16_t CMCTRL;
}CAN_MSG_Type, *CAN_MSG_MemMapPtr;


#define CAN0_MESSAGE_DB_REGISTER_00_BASE																							    (0x0600)
#define CAN0_MSG_00																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_00_BASE)

#define CAN0_MESSAGE_DB_REGISTER_01_BASE																							    (0x0610)
#define CAN0_MSG_01																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_01_BASE)

#define CAN0_MESSAGE_DB_REGISTER_02_BASE																							    (0x0620)
#define CAN0_MSG_02																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_02_BASE)

#define CAN0_MESSAGE_DB_REGISTER_03_BASE																							    (0x0630)
#define CAN0_MSG_03																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_03_BASE)

#define CAN0_MESSAGE_DB_REGISTER_04_BASE																							    (0x0640)
#define CAN0_MSG_04																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_04_BASE)

#define CAN0_MESSAGE_DB_REGISTER_05_BASE																							    (0x0650)
#define CAN0_MSG_05																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_05_BASE)

#define CAN0_MESSAGE_DB_REGISTER_06_BASE																							    (0x0660)
#define CAN0_MSG_06																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_06_BASE)

#define CAN0_MESSAGE_DB_REGISTER_07_BASE																							    (0x0670)
#define CAN0_MSG_07																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_07_BASE)

#define CAN0_MESSAGE_DB_REGISTER_08_BASE																							    (0x0680)
#define CAN0_MSG_08																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_08_BASE)

#define CAN0_MESSAGE_DB_REGISTER_09_BASE																							    (0x0690)
#define CAN0_MSG_09																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_09_BASE)

#define CAN0_MESSAGE_DB_REGISTER_10_BASE																							    (0x06A0)
#define CAN0_MSG_10																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_10_BASE)

#define CAN0_MESSAGE_DB_REGISTER_11_BASE																							    (0x06B0)
#define CAN0_MSG_11																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_11_BASE)

#define CAN0_MESSAGE_DB_REGISTER_12_BASE																							    (0x06C0)
#define CAN0_MSG_12																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_12_BASE)

#define CAN0_MESSAGE_DB_REGISTER_13_BASE																							    (0x06D0)
#define CAN0_MSG_13																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_13_BASE)

#define CAN0_MESSAGE_DB_REGISTER_14_BASE																							    (0x06E0)
#define CAN0_MSG_14																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_14_BASE)

#define CAN0_MESSAGE_DB_REGISTER_15_BASE																							    (0x06F0)
#define CAN0_MSG_15																	   ((__near CAN_MSG_Type *)CAN0_MESSAGE_DB_REGISTER_15_BASE)

#define CAN1_MESSAGE_DB_REGISTER_00_BASE																							    (0x0400)
#define CAN1_MSG_00																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_00_BASE)

#define CAN1_MESSAGE_DB_REGISTER_01_BASE																							    (0x0410)
#define CAN1_MSG_01																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_01_BASE)

#define CAN1_MESSAGE_DB_REGISTER_02_BASE																							    (0x0420)
#define CAN1_MSG_02																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_02_BASE)

#define CAN1_MESSAGE_DB_REGISTER_03_BASE																							    (0x0430)
#define CAN1_MSG_03																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_03_BASE)

#define CAN1_MESSAGE_DB_REGISTER_04_BASE																							    (0x0440)
#define CAN1_MSG_04																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_04_BASE)

#define CAN1_MESSAGE_DB_REGISTER_05_BASE																							    (0x0450)
#define CAN1_MSG_05																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_05_BASE)

#define CAN1_MESSAGE_DB_REGISTER_06_BASE																							    (0x0460)
#define CAN1_MSG_06																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_06_BASE)

#define CAN1_MESSAGE_DB_REGISTER_07_BASE																							    (0x0470)
#define CAN1_MSG_07																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_07_BASE)

#define CAN1_MESSAGE_DB_REGISTER_08_BASE																							    (0x0480)
#define CAN1_MSG_08																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_08_BASE)

#define CAN1_MESSAGE_DB_REGISTER_09_BASE																							    (0x0490)
#define CAN1_MSG_09																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_09_BASE)

#define CAN1_MESSAGE_DB_REGISTER_10_BASE																							    (0x04A0)
#define CAN1_MSG_10																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_10_BASE)

#define CAN1_MESSAGE_DB_REGISTER_11_BASE																							    (0x04B0)
#define CAN1_MSG_11																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_11_BASE)

#define CAN1_MESSAGE_DB_REGISTER_12_BASE																							    (0x04C0)
#define CAN1_MSG_12																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_12_BASE)

#define CAN1_MESSAGE_DB_REGISTER_13_BASE																							    (0x04D0)
#define CAN1_MSG_13																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_13_BASE)

#define CAN1_MESSAGE_DB_REGISTER_14_BASE																							    (0x04E0)
#define CAN1_MSG_14																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_14_BASE)

#define CAN1_MESSAGE_DB_REGISTER_15_BASE																							    (0x04F0)
#define CAN1_MSG_15																	   ((__near CAN_MSG_Type *)CAN1_MESSAGE_DB_REGISTER_15_BASE)



/* CMCONF Bit Fields */
#define CAN_CMCONF_MA_SHIFT																													   0
#define CAN_CMCONF_MA_MASK																													0x01
#define CAN_CMCONF_MT_SHIFT																													   3
#define CAN_CMCONF_MT_MASK																													0x38
#define CAN_CMCONF_MT_VALUE(x)											   (((uint8_t)(((uint8_t)(x))<<CAN_CMCONF_MT_SHIFT))&CAN_CMCONF_MT_MASK)
#define CAN_CMCONF_RTR_SHIFT																												   6
#define CAN_CMCONF_RTR_MASK																													0x40
#define CAN_CMCONF_OWS_SHIFT																												   7
#define CAN_CMCONF_OWS_MASK																													0x80


/* CMCTRL Bit Fields */
#define CAN_CMCTRL_READ_RDY_SHIFT																											   0
#define CAN_CMCTRL_READ_RDY_MASK																										  0x0001
#define CAN_CMCTRL_READ_TRQ_SHIFT																											   1
#define CAN_CMCTRL_READ_TRQ_MASK																										  0x0002
#define CAN_CMCTRL_READ_DN_SHIFT																											   2
#define CAN_CMCTRL_READ_DN_MASK																											  0x0004
#define CAN_CMCTRL_READ_IE_SHIFT																											   3
#define CAN_CMCTRL_READ_IE_MASK																											  0x0008
#define CAN_CMCTRL_READ_MOW_SHIFT																											   4
#define CAN_CMCTRL_READ_MOW_MASK																										  0x0010
#define CAN_CMCTRL_SET_RDY_SHIFT																											   8
#define CAN_CMCTRL_SET_RDY_MASK																											  0x0100
#define CAN_CMCTRL_SET_TRQ_SHIFT																											   9
#define CAN_CMCTRL_SET_TRQ_MASK																											  0x0200
#define CAN_CMCTRL_SET_IE_SHIFT																												  11
#define CAN_CMCTRL_SET_IE_MASK																											  0x0800
#define CAN_CMCTRL_READ_MUC_SHIFT																											  13
#define CAN_CMCTRL_READ_MUC_MASK																										  0x2000


/* ----------------------------------------------------------- CAN Configuration Handlers ------------------------------------------------------------ */














/* ------------------------------------------------------------ Safety Function Registers ---------------------------------------------------------- */

#define CRC_INPUT_REGISTER_BASE												   														   	(0xFFAC)
#define CRCIN										     								   *((__near volatile uint8_t *)CRC_INPUT_REGISTER_BASE)

#define INVALID_MEM_ACCESS_DETECT_CTRL_REGISTER_BASE								  	   											   	(0x0078)
#define IAWCTL														  *((__near volatile uint8_t *)INVALID_MEM_ACCESS_DETECT_CTRL_REGISTER_BASE)

/* IAWCTL Bit Fields */
#define IAWCTL_GCSC_SHIFT																													   0
#define IAWCTL_GCSC_MASK																													0x01
#define IAWCTL_GINT_SHIFT																													   1
#define IAWCTL_GINT_MASK																													0x02
#define IAWCTL_GPORT_SHIFT																													   2
#define IAWCTL_GPORT_MASK																													0x04
#define IAWCTL_GRAM_SHIFT																													   4
#define IAWCTL_GRAM_MASK																													0x30
#define IAWCTL_GRAM_VALUE(x)												   (((uint8_t)(((uint8_t)(x))<<IAWCTL_GRAM_SHIFT))&IAWCTL_GRAM_MASK)
#define IAWCTL_IAWEN_SHIFT																													   7
#define IAWCTL_IAWEN_MASK																													0x80





#define RAM_PARITY_ERROR_CTRL_REGISTER_BASE										   													   	(0x00F5)
#define RPECTL											 					   *((__near volatile uint8_t *)RAM_PARITY_ERROR_CTRL_REGISTER_BASE)

/* RPECTL Bit Fields */
#define RPECTL_RPEF_SHIFT																													   0
#define RPECTL_RPEF_MASK																													0x01
#define RPECTL_RPERDIS_SHIFT																												   7
#define RPECTL_RPERDIS_MASK																													0x80




#define FMP_CLOCK_DIVISION_SEL_REGISTER_BASE																						   	(0x00F8)
#define MDIV																  *((__near volatile uint8_t *)FMP_CLOCK_DIVISION_SEL_REGISTER_BASE)

/* MDIV Bit Fields */
#define CLOCK_MDIV_SHIFT																													   0
#define CLOCK_MDIV_MASK																														0x07
#define CLOCK_MDIV_VALUE(x)														 (((uint8_t)(((uint8_t)(x))<<CLOCK_MDIV_SHIFT))&CLOCK_MDIV_MASK)





#define FLASH_MEM_CRC_CTRL_REGISTER_BASE										   													   	(0x02F0)
#define CRC0CTL										    						  *((__near volatile uint8_t *)FLASH_MEM_CRC_CTRL_REGISTER_BASE)

/* CRC0CTL Bit Fields */
#define CRC0CTL_FEA_SHIFT																													   0
#define CRC0CTL_FEA_MASK																													0x3F
#define CRC0CTL_FEA_VALUE(x)												   (((uint8_t)(((uint8_t)(x))<<CRC0CTL_FEA_SHIFT))&CRC0CTL_FEA_MASK)
#define CRC0CTL_CRC0EN_SHIFT																												   7
#define CRC0CTL_CRC0EN_MASK																													0x80






#define FLASH_MEM_CRC_OPER_RESULT_REGISTER_BASE										   												   	(0x02F2)
#define PGCRCL										    				  *((__near volatile uint16_t *)FLASH_MEM_CRC_OPER_RESULT_REGISTER_BASE)

#define CRC_DATA_REGISTER_BASE												   														   	(0x02FA)
#define CRCD										     								   *((__near volatile uint16_t *)CRC_DATA_REGISTER_BASE)






#define STEPPER_MOTOR_PORT_MODE_CTRL_REGISTER_BASE						 						   									   	(0xFF37)
#define SMPC							      							*((__near volatile uint8_t *)STEPPER_MOTOR_PORT_MODE_CTRL_REGISTER_BASE)

/* SMPC Bit Fields */
#define SMPC_EN_MASK																														0x0F
#define SMPC_EN_SHIFT																														   0
#define SMPC_EN_VALUE(x)															   (((uint8_t)(((uint8_t)(x))<<SMPC_EN_SHIFT))&SMPC_EN_MASK)
#define SMPC_MOD_MASK																														0xF0
#define SMPC_MOD_SHIFT																														   4
#define SMPC_MOD_VALUE(x)															 (((uint8_t)(((uint8_t)(x))<<SMPC_MOD_SHIFT))&SMPC_MOD_MASK)




#define RESET_CTRL_FLAG_REGISTER_BASE			 							   														   	(0xFFA8)
#define RESF										    							 *((__near volatile uint8_t *)RESET_CTRL_FLAG_REGISTER_BASE)

/* RESF Bit Fields */
#define RESF_LVIRF_SHIFT																													   0
#define RESF_LVIRF_MASK																														0x01
#define RESF_IAWRF_SHIFT																													   1
#define RESF_IAWRF_MASK																														0x02
#define RESF_RPERF_SHIFT																													   2
#define RESF_RPERF_MASK																														0x04
#define RESF_WDTRF_SHIFT																													   4
#define RESF_WDTRF_MASK																														0x10
#define RESF_TRAP_SHIFT																														   7
#define RESF_TRAP_MASK																														0x80



#define WATCHDOG_TIMER_ENABLE_REGISTER_BASE					 					   													   	(0xFFAB)
#define WDTE											 					   *((__near volatile uint8_t *)WATCHDOG_TIMER_ENABLE_REGISTER_BASE)

/* WDTE Bit Fields */
#define WDTE_WDSTBYON_SHIFT																													   0
#define WDTE_WDSTBYON_MASK																													0x01
#define WDTE_WDCS_SHIFT																														   1
#define WDTE_WDCS_MASK																														0x0E
#define WDTE_WDCS_VALUE(x)														   (((uint8_t)(((uint8_t)(x))<<WDTE_WDCS_SHIFT))&WDTE_WDCS_MASK)
#define WDTE_WDTON_SHIFT																													   4
#define WDTE_WDTON_MASK																														0x10
#define WDTE_WINDOW_SHIFT																													   5
#define WDTE_WINDOW_MASK																													0x60
#define WDTE_WINDOW_VALUE(x)												   (((uint8_t)(((uint8_t)(x))<<WDTE_WINDOW_SHIFT))&WDTE_WINDOW_MASK)
#define WDTE_WDTINT_SHIFT																													   7
#define WDTE_WDTINT_MASK																													0x80



#define PROCESSOR_MODE_CTRL_REGISTER_BASE																							   	(0xFFFE)
#define PMC																		 *((__near volatile uint8_t *)PROCESSOR_MODE_CTRL_REGISTER_BASE)

#define RESET_OUTPUT_CTRL_REGISTER_BASE																								   	(0x0014)
#define RESOC																	   *((__near volatile uint8_t *)RESET_OUTPUT_CTRL_REGISTER_BASE)




#define STOP_STATUS_OUTPUT_CTRL_REGISTER_BASE																						   	(0x0016)
#define STPSTC																 *((__near volatile uint8_t *)STOP_STATUS_OUTPUT_CTRL_REGISTER_BASE)

/* STPSTC Bit Fields */
#define STPSTC_STPLV_SHIFT																													   4
#define STPSTC_STPLV_MASK																													0x10
#define STPSTC_STPOEN_SHIFT																													   7
#define STPSTC_STPOEN_MASK																													0x80





#define DATA_FLASH_CTRL_REGISTER_BASE																								   	(0x0090)
#define DFLCTL																		 *((__near volatile uint8_t *)DATA_FLASH_CTRL_REGISTER_BASE)

/* DFLCTL Bit Fields */
#define DFLCTL_DFLEN_SHIFT																													   0
#define DFLCTL_DFLEN_MASK																													0x01






#define CLM_RESET_CTRL_FLAG_REGISTER_BASE																							   	(0x00FA)
#define RESFCLM																	 *((__near volatile uint8_t *)CLM_RESET_CTRL_FLAG_REGISTER_BASE)

/* REFCLM Bit Fields */
#define REFCLM_CLKRF_SHIFT																													   0
#define REFCLM_CLKRF_MASK																													0x01





#define POC_RESET_CONFIRM_REGISTER_BASE													  											   	(0x00FB)
#define POCRES																	   *((__near volatile uint8_t *)POC_RESET_CONFIRM_REGISTER_BASE)

/* POCRES Bit Fields */
#define POCRES_POCRES0_SHIFT																												   0
#define POCRES_POCRES0_MASK																													0x01




#define GUARD_REGISTER_BASE																											   	(0x00FC)
#define GUARD																				   *((__near volatile uint8_t *)GUARD_REGISTER_BASE)

/* GUARD Bit Fields */
#define GUARD_GDPLL_SHIFT																													   0
#define GUARD_GDPLL_MASK																													0x01
#define GUARD_GDRTC_SHIFT																													   1
#define GUARD_GDRTC_MASK																													0x02



#define OPTION_REGISTER_1_BASE																										   (0x000C0)
#define OPT1																					   *((volatile uint8_t *)OPTION_REGISTER_1_BASE)

/* OPT1 Bit Fields */
#define OPT1_WDSTBYON_SHIFT																													   0
#define OPT1_WDSTBYON_MASK																													0x01
#define OPT1_WDCS_SHIFT																														   1
#define OPT1_WDCS_MASK																														0x0E
#define OPT1_WDCS_VALUE(x)														   (((uint8_t)(((uint8_t)(x))<<OPT1_WDCS_SHIFT))&OPT1_WDCS_MASK)
#define OPT1_WDTON_SHIFT																													   4
#define OPT1_WDTON_MASK																														0x10
#define OPT1_WINDOW_SHIFT																													   5
#define OPT1_WINDOW_MASK																													0x60
#define OPT1_WINDOW_VALUE(x)												   (((uint8_t)(((uint8_t)(x))<<OPT1_WINDOW_SHIFT))&OPT1_WINDOW_MASK)
#define OPT1_WDTINT_SHIFT																													   7
#define OPT1_WDTINT_MASK																													0x80




#define OPTION_REGISTER_2_BASE																										   (0x000C1)
#define OPT2																					   *((volatile uint8_t *)OPTION_REGISTER_2_BASE)

/* OPT2 Bit Fields */
#define OPT2_LVIMDS_SHIFT																													   0
#define OPT2_LVIMDS_MASK																													0x03
#define OPT2_LVIMDS_VALUE(x)												   (((uint8_t)(((uint8_t)(x))<<OPT2_LVIMDS_SHIFT))&OPT2_LVIMDS_MASK)
#define OPT2_LVIS_SHIFT																														   2
#define OPT2_LVIS_MASK																														0x0C
#define OPT2_LVIS_VALUE(x)														   (((uint8_t)(((uint8_t)(x))<<OPT2_LVIS_SHIFT))&OPT2_LVIS_MASK)
#define OPT2_CLKMB_SHIFT																													   4
#define OPT2_CLKMB_MASK																														0x10
#define OPT2_VPOC_SHIFT																														   5
#define OPT2_VPOC_MASK																														0xE0
#define OPT2_VPOC_VALUE(x)														   (((uint8_t)(((uint8_t)(x))<<OPT2_VPOC_SHIFT))&OPT2_VPOC_MASK)




#define OPTION_REGISTER_3_BASE																										   (0x000C2)
#define OPT3																					   *((volatile uint8_t *)OPTION_REGISTER_3_BASE)

/* OPT3 Bit Fields */
#define OPT3_FRQSEL_SHIFT																													   0
#define OPT3_FRQSEL_MASK																													0x0F
#define OPT3_FRQSEL_VALUE(x)												   (((uint8_t)(((uint8_t)(x))<<OPT3_FRQSEL_SHIFT))&OPT3_FRQSEL_MASK)
#define OPT3_OPTPLL_SHIFT																													   5
#define OPT3_OPTPLL_MASK																													0x20
#define OPT3_CMODE_SHIFT																													   6
#define OPT3_CMODE_MASK																														0xC0
#define OPT3_CMODE_VALUE(x)														 (((uint8_t)(((uint8_t)(x))<<OPT3_CMODE_SHIFT))&OPT3_CMODE_MASK)




#define OPTION_REGISTER_4_BASE																										   (0x000C3)
#define OPT4																					   *((volatile uint8_t *)OPTION_REGISTER_4_BASE)

/* OPT4 Bit Fields */
#define OPT4_OCDERSD_SHIFT																													   0
#define OPT4_OCDERSD_MASK																													0x01
#define OPT4_OCDENSET_SHIFT																													   7
#define OPT4_OCDENSET_MASK																													0x80


/* ------------------------------------------------------------ Safety Function Registers ---------------------------------------------------------- */




#define WATCHDOG_VECTOR_ADDRESS                         							  0x0004
#define VOLTAGE_DETECT_VECTOR_ADDRESS      											  0x0006
#define EXT_INTERRUPT0_VECTOR_ADDRESS  												  0x0008
#define EXT_INTERRUPT1_VECTOR_ADDRESS   											  0x000A
#define EXT_INTERRUPT2_VECTOR_ADDRESS   											  0x000C
#define EXT_INTERRUPT3_VECTOR_ADDRESS   											  0x000E
#define EXT_INTERRUPT4_VECTOR_ADDRESS   											  0x0010
#define EXT_INTERRUPT5_VECTOR_ADDRESS   											  0x0012
#define CLOCK_INTERRUPT_VECTOR_ADDRESS   											  0x0014
#define UART0_TX_VECTOR_ADDRESS			   											  0x0016
#define UART0_RX_VECTOR_ADDRESS			   											  0x0018
#define DMA0_TX_VECTOR_ADDRESS			   											  0x001A
#define DMA1_TX_VECTOR_ADDRESS			   											  0x001C
#define RTC_ALARM_VECTOR_ADDRESS		   											  0x001E
#define INTERVAL_TIMER_VECTOR_ADDRESS   											  0x0020
#define LIN_UART0_TX_VECTOR_ADDRESS		   											  0x0022
#define LIN_UART0_RX_VECTOR_ADDRESS	    											  0x0024
#define LIN_UART0_RX_STATUS_VECTOR_ADDRESS 											  0x0026
#define LIN_UART0_RX_PIN_IP_VECTOR_ADDRESS	  										  0x0028
#define SG_ALD_VECTOR_ADDRESS			   											  0x002A
#define TAU0_CHANNEL0_VECTOR_ADDRESS    											  0x002C
#define TAU0_CHANNEL1_VECTOR_ADDRESS    											  0x002E
#define TAU0_CHANNEL2_VECTOR_ADDRESS    											  0x0030
#define TAU0_CHANNEL3_VECTOR_ADDRESS    											  0x0032
#define ADC_CONVERSION_VECTOR_ADDRESS												  0x0034
#define LIN_UART1_TX_VECTOR_ADDRESS     											  0x0036
#define LIN_UART1_RX_VECTOR_ADDRESS     											  0x0038
#define LIN_UART1_RX_STATUS_VECTOR_ADDRESS											  0x003A
#define LIN_UART1_RX_PIN_IP_VECTOR_ADDRESS											  0x003C
#define CSI10_COMM_VECTOR_ADDRESS		   											  0x003E
#define IIC11_COMM_VECTOR_ADDRESS       											  0x0040
#define TAU0_CHANNEL4_VECTOR_ADDRESS    											  0x0042
#define TAU0_CHANNEL5_VECTOR_ADDRESS    											  0x0044
#define TAU0_CHANNEL6_VECTOR_ADDRESS    											  0x0046
#define TAU0_CHANNEL7_VECTOR_ADDRESS    											  0x0048
#define CAN1_ERROR_VECTOR_ADDRESS	    											  0x004A
#define CAN1_WAKEUP_VECTOR_ADDRESS       											  0x004C
#define CAN0_ERROR_VECTOR_ADDRESS                        							  0x004E
#define CAN0_WAKEUP_VECTOR_ADDRESS      											  0x0050
#define CAN0_RX_VECTOR_ADDRESS      												  0x0052
#define CAN0_TX_VECTOR_ADDRESS          											  0x0054
#define TAU1_CHANNEL0_VECTOR_ADDRESS     											  0x0056
#define TAU1_CHANNEL1_VECTOR_ADDRESS    											  0x0058
#define TAU1_CHANNEL2_VECTOR_ADDRESS    											  0x005A
#define TAU1_CHANNEL3_VECTOR_ADDRESS    											  0x005C
#define END_OF_DIV_VECTOR_ADDRESS     												  0x005E
#define CAN1_RX_VECTOR_ADDRESS          											  0x0060
#define END_OF_SEQ_VECTOR_ADDRESS       											  0x0062
#define CAN1_TX_VECTOR_ADDRESS          											  0x0064
#define TAU1_CHANNEL4_VECTOR_ADDRESS    											  0x0066
#define TAU1_CHANNEL5_VECTOR_ADDRESS    											  0x0068
#define TAU1_CHANNEL6_VECTOR_ADDRESS    											  0x006A
#define TAU1_CHANNEL7_VECTOR_ADDRESS    											  0x006C
#define TAU2_CHANNEL0_VECTOR_ADDRESS    											  0x006E
#define TAU2_CHANNEL1_VECTOR_ADDRESS    											  0x0070
#define TAU2_CHANNEL2_VECTOR_ADDRESS    											  0x0072
#define TAU2_CHANNEL3_VECTOR_ADDRESS    											  0x0074
#define TAU2_CHANNEL4_VECTOR_ADDRESS    											  0x0076
#define TAU2_CHANNEL6_VECTOR_ADDRESS    											  0x0078
#define DMA2_TX_VECTOR_ADDRESS                         								  0x007A
#define DMA3_TX_VECTOR_ADDRESS          											  0x007C


#endif
