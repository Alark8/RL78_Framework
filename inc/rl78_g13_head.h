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
**     Copyright: NCVE. All Rights Reserved.
**
**     Revisions:
**     - rev. 1.0 (2013-07-30)
**         Initial version.
**     
**		This revision is a complete access layer of Renesas G13 microcontroller family.
** #######################################################################################################
*/


#ifndef RL78_G13_HEAD_H
#define RL78_G13_HEAD_H

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
	volatile uint8_t BL2;
	volatile uint8_t PU14;
}PUR_Type, *PUR_MemMapPtr;


#define PULL_UP_RESISTOR_BASE												   															(0x0030)
#define PUR															 			 							 ((PUR_Type *)PULL_UP_RESISTOR_BASE)


/* Port Input Mode Register Definition */
typedef struct {
	volatile uint8_t PIM0;
	volatile uint8_t PIM1;
	volatile uint8_t BL1[2];
	volatile uint8_t PIM4;
	volatile uint8_t PIM5;
	volatile uint8_t BL2[2];
	volatile uint8_t PIM8;
	volatile uint8_t BL3[5];
	volatile uint8_t PIM14;
}PIM_Type, *PIM_MemMapPtr;


#define PORT_INPUT_MODE_REGISTER_BASE	   					    					   												    (0x0040)
#define PIM									 							 							 ((PIM_Type *)PORT_INPUT_MODE_REGISTER_BASE)



/* Port Output Mode Register Definition */
typedef struct {
	volatile uint8_t POM0;
	volatile uint8_t POM1;
	volatile uint8_t BL1[2];
	volatile uint8_t POM4;
	volatile uint8_t POM5;
	volatile uint8_t BL2;
	volatile uint8_t POM7;
	volatile uint8_t POM8;
	volatile uint8_t POM9;
	volatile uint8_t BL3[4];
}POM_Type, *POM_MemMapPtr;


#define PORT_OUTPUT_MODE_REGISTER_BASE							                                   										(0x0050)
#define POM									       													((POM_Type *)PORT_OUTPUT_MODE_REGISTER_BASE)



/* Port Mode Control Register */
typedef struct {
	volatile uint8_t PMC0;
	volatile uint8_t BL1[2];
	volatile uint8_t PMC3;
	volatile uint8_t BL2[6];
	volatile uint8_t PMC10;
	volatile uint8_t PMC11;
	volatile uint8_t PMC12;
	volatile uint8_t BL3;
	volatile uint8_t PMC14;
}PMC_Type, *PMC_MemMapPtr;


#define PORT_MODE_CONTROL_REGISTER_BASE											   														(0x0060)
#define PMC									      					   							   ((PMC_Type *)PORT_MODE_CONTROL_REGISTER_BASE)



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
#define PORT											  						   							   ((PORT_Type *)PORT_REGISTER_BASE)


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
	volatile uint8_t BL1;
	volatile uint8_t PM14;
	volatile uint8_t PM15;
}PMR_Type, *PMR_MemMapPtr;


#define PORT_MODE_REGISTER_BASE												   															(0xFF20)
#define PMR										      						   							   ((PMR_Type *)PORT_MODE_REGISTER_BASE)

/* Peripheral Input/Output Redirection Register Address */
#define PERIPHERAL_IO_REDIR_REGISTER_BASE										   														(0x0077)
#define PERIPHERAL_IO_REDIR_REGISTER					    							*((volatile uint8_t *)PERIPHERAL_IO_REDIR_REGISTER_BASE)

/* Global Digital Input Disable Register Address */
#define GLOBAL_DIGITAL_INPUT_DISABLE_REGISTER_BASE									   													(0x007D)
#define GLOBAL_DIGITAL_INPUT_DISABLE_REGISTER			  					   *((volatile uint8_t *)GLOBAL_DIGITAL_INPUT_DISABLE_REGISTER_BASE)

/* --------------------------------------------------------------- Port Configuration Handlers ----------------------------------------------------------- */












/* ------------------------------------------------------------ Timer Configuration Handlers ------------------------------------------------------------ */

/* Timer Data Register Definition */
typedef struct {
	union {
		volatile uint8_t TDR_L;
		volatile uint8_t TDR_H;
	}ACCESS_8bit;
	
	volatile uint16_t TDR;
}TDR_Type, *TDR_MemMapPtr;


#define TIMER_DATA_REGISTER_00_BASE											   															(0xFF18)
#define TDR00										  												   ((TDR_Type *)TIMER_DATA_REGISTER_00_BASE)

#define TIMER_DATA_REGISTER_01_BASE											   															(0xFF1A)
#define TDR01										  												   ((TDR_Type *)TIMER_DATA_REGISTER_01_BASE)

#define TIMER_DATA_REGISTER_02_BASE											   															(0xFF64)
#define TDR02										  												   ((TDR_Type *)TIMER_DATA_REGISTER_02_BASE)

#define TIMER_DATA_REGISTER_03_BASE											   															(0xFF66)
#define TDR03										  												   ((TDR_Type *)TIMER_DATA_REGISTER_03_BASE)

#define TIMER_DATA_REGISTER_04_BASE											   															(0xFF68)
#define TDR04										  												   ((TDR_Type *)TIMER_DATA_REGISTER_04_BASE)

#define TIMER_DATA_REGISTER_05_BASE											   															(0xFF6A)
#define TDR05										  												   ((TDR_Type *)TIMER_DATA_REGISTER_05_BASE)

#define TIMER_DATA_REGISTER_06_BASE											   															(0xFF6C)
#define TDR06										  												   ((TDR_Type *)TIMER_DATA_REGISTER_06_BASE)

#define TIMER_DATA_REGISTER_07_BASE											   															(0xFF6E)
#define TDR07										  												   ((TDR_Type *)TIMER_DATA_REGISTER_07_BASE)

#define TIMER_DATA_REGISTER_10_BASE											   															(0xFF70)
#define TDR10										  												   ((TDR_Type *)TIMER_DATA_REGISTER_10_BASE)

#define TIMER_DATA_REGISTER_11_BASE											   															(0xFF72)
#define TDR11										  												   ((TDR_Type *)TIMER_DATA_REGISTER_11_BASE)

#define TIMER_DATA_REGISTER_12_BASE											   															(0xFF74)
#define TDR12										  												   ((TDR_Type *)TIMER_DATA_REGISTER_12_BASE)

#define TIMER_DATA_REGISTER_13_BASE											   															(0xFF76)
#define TDR13										  												   ((TDR_Type *)TIMER_DATA_REGISTER_13_BASE)

#define TIMER_DATA_REGISTER_14_BASE											   															(0xFF78)
#define TDR14										  												   ((TDR_Type *)TIMER_DATA_REGISTER_14_BASE)

#define TIMER_DATA_REGISTER_15_BASE											   															(0xFF7A)
#define TDR15										  												   ((TDR_Type *)TIMER_DATA_REGISTER_15_BASE)

#define TIMER_DATA_REGISTER_16_BASE											   															(0xFF7C)
#define TDR16										  												   ((TDR_Type *)TIMER_DATA_REGISTER_16_BASE)

#define TIMER_DATA_REGISTER_17_BASE											   															(0xFF7E)
#define TDR17										  												   ((TDR_Type *)TIMER_DATA_REGISTER_17_BASE)



/* Timer Configuration Register Definition */
typedef struct {
	volatile uint8_t NFEN0;
	volatile uint8_t NFEN1;
	volatile uint8_t NFEN2;
	volatile uint8_t ISC;
	volatile uint8_t TIS0;
}TMR_Config_Type, *TMR_Config_MemMapPtr;


#define TIMER_CONFIG_REGISTER_BASE										 	   															(0x0070)
#define TMR_CONFIG								    											 ((TMR_Config_Type *)TIMER_CONFIG_REGISTER_BASE)



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


#define TIMER0_REGISTER_BASE												   															(0x01B0)
#define TIMER0										       													((TIMER_Type *)TIMER0_REGISTER_BASE)

#define TIMER1_REGISTER_BASE												   															(0x01F0)
#define TIMER1										       													((TIMER_Type *)TIMER1_REGISTER_BASE)



/* Timer Counter Register Definition */
typedef struct {
	volatile uint16_t TCR;
}TCR_Type, *TCR_MemMapPtr;


#define TIMER_COUNTER_REGISTER_00_BASE											   														(0x0180)
#define TCR00									       												((TCR_Type *)TIMER_COUNTER_REGISTER_00_BASE)

#define TIMER_COUNTER_REGISTER_01_BASE											   														(0x0182)
#define TCR01									       												((TCR_Type *)TIMER_COUNTER_REGISTER_01_BASE)

#define TIMER_COUNTER_REGISTER_02_BASE											   														(0x0184)
#define TCR02									       												((TCR_Type *)TIMER_COUNTER_REGISTER_02_BASE)

#define TIMER_COUNTER_REGISTER_03_BASE										           													(0x0186)
#define TCR03									       												((TCR_Type *)TIMER_COUNTER_REGISTER_03_BASE)

#define TIMER_COUNTER_REGISTER_04_BASE											   														(0x0188)
#define TCR04									       												((TCR_Type *)TIMER_COUNTER_REGISTER_04_BASE)

#define TIMER_COUNTER_REGISTER_05_BASE											   														(0x018A)
#define TCR05									       												((TCR_Type *)TIMER_COUNTER_REGISTER_05_BASE)

#define TIMER_COUNTER_REGISTER_06_BASE											   														(0x018C)
#define TCR06									       												((TCR_Type *)TIMER_COUNTER_REGISTER_06_BASE)

#define TIMER_COUNTER_REGISTER_07_BASE										           													(0x018E)
#define TCR07									       												((TCR_Type *)TIMER_COUNTER_REGISTER_07_BASE)

#define TIMER_COUNTER_REGISTER_10_BASE											   														(0x01C0)
#define TCR10									       												((TCR_Type *)TIMER_COUNTER_REGISTER_10_BASE)

#define TIMER_COUNTER_REGISTER_11_BASE											   														(0x01C2)
#define TCR11									       												((TCR_Type *)TIMER_COUNTER_REGISTER_11_BASE)

#define TIMER_COUNTER_REGISTER_12_BASE											   														(0x01C4)
#define TCR12									      												((TCR_Type *)TIMER_COUNTER_REGISTER_12_BASE)

#define TIMER_COUNTER_REGISTER_13_BASE											   														(0x01C6)
#define TCR13									       												((TCR_Type *)TIMER_COUNTER_REGISTER_13_BASE)

#define TIMER_COUNTER_REGISTER_14_BASE											   														(0x01C8)
#define TCR14									       												((TCR_Type *)TIMER_COUNTER_REGISTER_14_BASE)

#define TIMER_COUNTER_REGISTER_15_BASE											   														(0x01CA)
#define TCR15									       												((TCR_Type *)TIMER_COUNTER_REGISTER_15_BASE)

#define TIMER_COUNTER_REGISTER_16_BASE											   														(0x01CC)
#define TCR16									       												((TCR_Type *)TIMER_COUNTER_REGISTER_16_BASE)

#define TIMER_COUNTER_REGISTER_17_BASE											   														(0x01CE)
#define TCR17									       												((TCR_Type *)TIMER_COUNTER_REGISTER_17_BASE)



/* Timer Mode Register Definition */
typedef struct {
	volatile uint16_t TMR;
}TMR_Type, *TMR_MemMapPtr;


#define TIMER_MODE_REGISTER_00_BASE											   															(0x0190)
#define TMR00										  												   ((TMR_Type *)TIMER_MODE_REGISTER_00_BASE)

#define TIMER_MODE_REGISTER_01_BASE											   															(0x0192)
#define TMR01										  												   ((TMR_Type *)TIMER_MODE_REGISTER_01_BASE)

#define TIMER_MODE_REGISTER_02_BASE											   															(0x0194)
#define TMR02										  												   ((TMR_Type *)TIMER_MODE_REGISTER_02_BASE)

#define TIMER_MODE_REGISTER_03_BASE											   															(0x0196)
#define TMR03										  												   ((TMR_Type *)TIMER_MODE_REGISTER_03_BASE)

#define TIMER_MODE_REGISTER_04_BASE											   															(0x0198)
#define TMR04										 												   ((TMR_Type *)TIMER_MODE_REGISTER_04_BASE)

#define TIMER_MODE_REGISTER_05_BASE											   															(0x019A)
#define TMR05										  												   ((TMR_Type *)TIMER_MODE_REGISTER_05_BASE)

#define TIMER_MODE_REGISTER_06_BASE											   															(0x019C)
#define TMR06										  												   ((TMR_Type *)TIMER_MODE_REGISTER_06_BASE)

#define TIMER_MODE_REGISTER_07_BASE											   															(0x019E)
#define TMR07										   												   ((TMR_Type *)TIMER_MODE_REGISTER_07_BASE)

#define TIMER_MODE_REGISTER_10_BASE											  	 														(0x01D0)
#define TMR10										  												   ((TMR_Type *)TIMER_MODE_REGISTER_10_BASE)

#define TIMER_MODE_REGISTER_11_BASE											   															(0x01D2)
#define TMR11										  												   ((TMR_Type *)TIMER_MODE_REGISTER_11_BASE)

#define TIMER_MODE_REGISTER_12_BASE											   															(0x01D4)
#define TMR12										  												   ((TMR_Type *)TIMER_MODE_REGISTER_12_BASE)

#define TIMER_MODE_REGISTER_13_BASE											   															(0x01D6)
#define TMR13										  												   ((TMR_Type *)TIMER_MODE_REGISTER_13_BASE)

#define TIMER_MODE_REGISTER_14_BASE											   															(0x01D8)
#define TMR14										  												   ((TMR_Type *)TIMER_MODE_REGISTER_14_BASE)

#define TIMER_MODE_REGISTER_15_BASE											   															(0x01DA)
#define TMR15										  												   ((TMR_Type *)TIMER_MODE_REGISTER_15_BASE)

#define TIMER_MODE_REGISTER_16_BASE											   															(0x01DC)
#define TMR16										  												   ((TMR_Type *)TIMER_MODE_REGISTER_16_BASE)

#define TIMER_MODE_REGISTER_17_BASE											   															(0x01DE)
#define TMR17										  												   ((TMR_Type *)TIMER_MODE_REGISTER_17_BASE)



/* Timer Status Register Definition */
typedef struct {
	union {
		volatile uint8_t TSR_L;
		volatile uint8_t TSR_H;
	}ACCESS_8bit;
	volatile uint16_t TSR;
}TSR_Type, *TSR_MemMapPtr;


#define TIMER_STATUS_REGISTER_00_BASE											   														(0x01A0)
#define TSR00																						 ((TSR_Type *)TIMER_STATUS_REGISTER_00_BASE)

#define TIMER_STATUS_REGISTER_01_BASE											   														(0x01A2)
#define TSR01																						 ((TSR_Type *)TIMER_STATUS_REGISTER_01_BASE)

#define TIMER_STATUS_REGISTER_02_BASE											   														(0x01A4)
#define TSR02																						 ((TSR_Type *)TIMER_STATUS_REGISTER_02_BASE)

#define TIMER_STATUS_REGISTER_03_BASE											   														(0x01A6)
#define TSR03																						 ((TSR_Type *)TIMER_STATUS_REGISTER_03_BASE)

#define TIMER_STATUS_REGISTER_04_BASE											   														(0x01A8)
#define TSR04																						 ((TSR_Type *)TIMER_STATUS_REGISTER_04_BASE)

#define TIMER_STATUS_REGISTER_05_BASE											   														(0x01AA)
#define TSR05																						 ((TSR_Type *)TIMER_STATUS_REGISTER_05_BASE)

#define TIMER_STATUS_REGISTER_06_BASE											   														(0x01AC)
#define TSR06																						 ((TSR_Type *)TIMER_STATUS_REGISTER_06_BASE)

#define TIMER_STATUS_REGISTER_07_BASE											   														(0x01AE)
#define TSR07																						 ((TSR_Type *)TIMER_STATUS_REGISTER_07_BASE)

#define TIMER_STATUS_REGISTER_10_BASE											   														(0x01E0)
#define TSR10																						 ((TSR_Type *)TIMER_STATUS_REGISTER_10_BASE)

#define TIMER_STATUS_REGISTER_11_BASE											   														(0x01E2)
#define TSR11																						 ((TSR_Type *)TIMER_STATUS_REGISTER_11_BASE)

#define TIMER_STATUS_REGISTER_12_BASE											   														(0x01E4)
#define TSR12																						 ((TSR_Type *)TIMER_STATUS_REGISTER_12_BASE)

#define TIMER_STATUS_REGISTER_13_BASE											   														(0x01E6)
#define TSR13																						 ((TSR_Type *)TIMER_STATUS_REGISTER_13_BASE)

#define TIMER_STATUS_REGISTER_14_BASE											   														(0x01E8)
#define TSR14																						 ((TSR_Type *)TIMER_STATUS_REGISTER_14_BASE)

#define TIMER_STATUS_REGISTER_15_BASE											   														(0x01EA)
#define TSR15																						 ((TSR_Type *)TIMER_STATUS_REGISTER_15_BASE)

#define TIMER_STATUS_REGISTER_16_BASE											   														(0x01EC)
#define TSR16																						 ((TSR_Type *)TIMER_STATUS_REGISTER_16_BASE)

#define TIMER_STATUS_REGISTER_17_BASE											   														(0x01EE)
#define TSR17																						 ((TSR_Type *)TIMER_STATUS_REGISTER_17_BASE)

/* 12 bit Timer Control Register Base Address */
#define INTERVAL_TIMER_CTRL_REGISTER_BASE					 					   														(0xFF90)
#define INTERVAL_TIMER_CTRL_REGISTER					   								*((volatile uint8_t *)INTERVAL_TIMER_CTRL_REGISTER_BASE)

/* ------------------------------------------------------------ Timer Configuration Handlers ------------------------------------------------------------ */














/* -------------------------------------------------------------- ADC Configuration Handlers ------------------------------------------------------------ */

/* ADC Config Register Definition */
typedef struct {
	volatile uint8_t ADM0;
	volatile uint8_t ADS;
	volatile uint8_t ADM1;
}ADC0_Config_Type, *ADC0_Config_MemMapPtr;


#define ADC0_CONFIGURATION_REGISTER_BASE										   														(0xFF30)
#define ADC0_CONFIG							     										  ((ADC0_Config_Type *)ADC0_CONFIGURATION_REGISTER_BASE)



/* ADC Config Register Definition */
typedef struct {
	volatile uint8_t ADM2;
	volatile uint8_t ADUL;
	volatile uint8_t ADLL;
	volatile uint8_t ADTES;
}ADC1_Config_Type, *ADC1_Config_MemMapPtr;


#define ADC1_CONFIGURATION_REGISTER_BASE										   														(0x0010)
#define ADC1_CONFIG							     										  ((ADC1_Config_Type *)ADC1_CONFIGURATION_REGISTER_BASE)

/* ADC Conversion Result Register Address */
#define ADC_CONVERSION_RESULT_BASE											   															(0xFF1E)
#define ADC_CONVERSION_RESULT							 									  *((volatile uint16_t *)ADC_CONVERSION_RESULT_BASE)

/* ADC Port Configuration Register Address */
#define ADC_PORT_CONFIG_REGISTER_BASE											   														(0x0076)
#define ADC_PORT_CONFIG_REGISTER					       									*((volatile uint8_t *)ADC_PORT_CONFIG_REGISTER_BASE)

/* -------------------------------------------------------------- ADC Configuration Handlers ------------------------------------------------------------ */












/* -------------------------------------------------------------- I2C Configuration Handlers ------------------------------------------------------------ */

/* I2C Data Register Definition */
typedef struct {
	volatile uint8_t I2CA;
	volatile uint8_t I2CS;
	volatile uint8_t I2CF;
}I2C_Type, *I2C_MemMapPtr;


#define I2C_REGISTER_0_BASE												   																(0xFF50)
#define I2C0											  													   ((I2C_Type *)I2C_REGISTER_0_BASE)

#define I2C_REGISTER_1_BASE												   																(0xFF54)
#define I2C1											  													   ((I2C_Type *)I2C_REGISTER_1_BASE)



/* I2C Configuration Register Definition */
typedef struct {
	volatile uint8_t I2CCTRL0;
	volatile uint8_t I2CCTRL1;
	volatile uint8_t I2CWL;
	volatile uint8_t I2CWH;
	volatile uint8_t SVA;
}I2C_Config_Type, *I2C_Config_MemMapPtr;


#define I2C_CONFIGURATION_REGISTER_0_BASE										   														(0x0230)
#define I2C0_CONFIG							     										  ((I2C_Config_Type *)I2C_CONFIGURATION_REGISTER_0_BASE)

#define I2C_CONFIGURATION_REGISTER_1_BASE										   														(0x0238)
#define I2C1_CONFIG							     										  ((I2C_Config_Type *)I2C_CONFIGURATION_REGISTER_1_BASE)

/* -------------------------------------------------------------- I2C Configuration Handlers ------------------------------------------------------------ */















/* ------------------------------------------------------------- RTC Configuration Handlers ------------------------------------------------------------ */

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


#define RTC_REGISTER_BASE												   																(0xFF92)
#define RTC											    														 ((RTC_Type *)RTC_REGISTER_BASE)

/* ------------------------------------------------------------- RTC Configuration Handlers ------------------------------------------------------------ */














/* ----------------------------------------------------------- DMA Configuration Handlers ------------------------------------------------------------ */

/* DMA SFR Register Definition */
typedef struct {
	volatile uint8_t DSA;
}DMA_Type, *DMA_MemMapPtr;


#define DMA_SFR_REGISTER_0_BASE												   															(0xFFB0)
#define DSA0										      												   ((DMA_Type *)DMA_SFR_REGISTER_0_BASE)

#define DMA_SFR_REGISTER_1_BASE												   															(0xFFB1)
#define DSA1										      												   ((DMA_Type *)DMA_SFR_REGISTER_1_BASE)

#define DMA_SFR_REGISTER_2_BASE												   															(0x0200)
#define DSA2										      												   ((DMA_Type *)DMA_SFR_REGISTER_2_BASE)

#define DMA_SFR_REGISTER_3_BASE												   															(0x0201)
#define DSA3										      												   ((DMA_Type *)DMA_SFR_REGISTER_3_BASE)



/* DMA RAM Register Definition */
typedef struct {
	union {
		volatile uint8_t DRA_L;
		volatile uint8_t DRA_H;
	}ACCESS_8bit;
	volatile uint16_t DRA;
}DMA_RAM_Type, *DMA_RAM_MemMapPtr;


#define DMA_RAM_REGISTER_0_BASE												   															(0xFFB2)
#define DRA0										  												   ((DMA_RAM_Type *)DMA_RAM_REGISTER_0_BASE)

#define DMA_RAM_REGISTER_1_BASE												   															(0xFFB4)
#define DRA1										  												   ((DMA_RAM_Type *)DMA_RAM_REGISTER_1_BASE)

#define DMA_RAM_REGISTER_2_BASE												   															(0x0202)
#define DRA2										  												   ((DMA_RAM_Type *)DMA_RAM_REGISTER_2_BASE)

#define DMA_RAM_REGISTER_3_BASE												   															(0x0204)
#define DRA3										  												   ((DMA_RAM_Type *)DMA_RAM_REGISTER_3_BASE)



/* DMA Byte Count Register Definition */
typedef struct {
	volatile uint8_t DBC_L;
	volatile uint8_t DBC_H;
}DMA_BC_Type, *DMA_BC_MemMapPtr;


#define DMA_BYTE_COUNT_REGISTER_0_BASE											   														(0xFFB6)
#define DBC0									    											 ((DMA_BC_Type *)DMA_BYTE_COUNT_REGISTER_0_BASE)

#define DMA_BYTE_COUNT_REGISTER_1_BASE											   														(0xFFB8)
#define DBC1									    											 ((DMA_BC_Type *)DMA_BYTE_COUNT_REGISTER_1_BASE)

#define DMA_BYTE_COUNT_REGISTER_2_BASE											   														(0x0206)
#define DBC2									    											 ((DMA_BC_Type *)DMA_BYTE_COUNT_REGISTER_2_BASE)

#define DMA_BYTE_COUNT_REGISTER_3_BASE											   														(0x0208)
#define DBC3									    											 ((DMA_BC_Type *)DMA_BYTE_COUNT_REGISTER_3_BASE)



/* DMA Mode Control Register Definition */
typedef struct {
	volatile uint8_t DMC;
}DMA_MC_Type, *DMA_MC_MemMapPtr;


#define DMA_MODE_CONTROL_REGISTER_0_BASE										   														(0xFFBA)
#define DMC0									   												(DMA_MC_Type *)DMA_MODE_CONTROL_REGISTER_0_BASE)

#define DMA_MODE_CONTROL_REGISTER_1_BASE										   														(0xFFBB)
#define DMC1									   												(DMA_MC_Type *)DMA_MODE_CONTROL_REGISTER_1_BASE)

#define DMA_MODE_CONTROL_REGISTER_2_BASE										   														(0x020A)
#define DMC2									   												(DMA_MC_Type *)DMA_MODE_CONTROL_REGISTER_2_BASE)

#define DMA_MODE_CONTROL_REGISTER_3_BASE										   														(0x020B)
#define DMC3									   												(DMA_MC_Type *)DMA_MODE_CONTROL_REGISTER_3_BASE)



/* DMA Operation Control Register Definition */
typedef struct {
	volatile uint8_t DRC;
}DMA_OC_Type, *DMA_OC_MemMapPtr;


#define DMA_OPER_CONTROL_REGISTER_0_BASE										   														(0xFFBC)
#define DRC0									   												(DMA_OC_Type *)DMA_OPER_CONTROL_REGISTER_0_BASE)

#define DMA_OPER_CONTROL_REGISTER_1_BASE										   														(0xFFBD)
#define DRC1									   												(DMA_OC_Type *)DMA_OPER_CONTROL_REGISTER_1_BASE)

#define DMA_OPER_CONTROL_REGISTER_2_BASE										   														(0x020C)
#define DRC2									   												(DMA_OC_Type *)DMA_OPER_CONTROL_REGISTER_2_BASE)

#define DMA_OPER_CONTROL_REGISTER_3_BASE										   														(0x020D)
#define DRC3									   												(DMA_OC_Type *)DMA_OPER_CONTROL_REGISTER_3_BASE)

/* ----------------------------------------------------------- DMA Configuration Handlers ------------------------------------------------------------ */













/* ---------------------------------------------------------- Interrupt Configuration Handlers ------------------------------------------------------ */

/* Interrupt Request Flag Register Definition */
typedef struct {
	union {
		volatile uint8_t IF_L;
		volatile uint8_t IF_H;
	}ACCESS_8bit;
	volatile uint16_t IF;
}IRF_Req_Type, *IRF_Req_MemMapPtr;


#define INTERRUPT_REQ_FLAG_REGISTER_0_BASE										   														(0xFFE0)
#define IF0																					 (IRF_Req_Type *)INTERRUPT_REQ_FLAG_REGISTER_0_BASE)

#define INTERRUPT_REQ_FLAG_REGISTER_1_BASE										   														(0xFFE2)
#define IF1																					 (IRF_Req_Type *)INTERRUPT_REQ_FLAG_REGISTER_1_BASE)

#define INTERRUPT_REQ_FLAG_REGISTER_2_BASE										   														(0xFFD0)
#define IF2																					 (IRF_Req_Type *)INTERRUPT_REQ_FLAG_REGISTER_2_BASE)

#define INTERRUPT_REQ_FLAG_REGISTER_3_BASE										   														(0xFFD2)
#define IF3																					 (IRF_Req_Type *)INTERRUPT_REQ_FLAG_REGISTER_3_BASE)



/* Interrupt Mask Flag Register Definition */
typedef struct {
	union {
		volatile uint8_t MK_L;
		volatile uint8_t MK_H;
	}ACCESS_8bit;
	volatile uint16_t MK;
}IRF_Mask_Type, *IRF_Mask_MemMapPtr;


#define INTERRUPT_MASK_FLAG_REGISTER_0_BASE										  														(0xFFE4)
#define MK0								       												(IRF_Req_Type *)INTERRUPT_MASK_FLAG_REGISTER_0_BASE)

#define INTERRUPT_MASK_FLAG_REGISTER_1_BASE										   														(0xFFE6)
#define MK1								       												(IRF_Req_Type *)INTERRUPT_MASK_FLAG_REGISTER_1_BASE)

#define INTERRUPT_MASK_FLAG_REGISTER_2_BASE										   														(0xFFD4)
#define MK2								       												(IRF_Req_Type *)INTERRUPT_MASK_FLAG_REGISTER_2_BASE)

#define INTERRUPT_MASK_FLAG_REGISTER_3_BASE										   														(0xFFD6)
#define MK3								       												(IRF_Req_Type *)INTERRUPT_MASK_FLAG_REGISTER_3_BASE)



/* External Interrupt Register 0 Definition */
typedef struct {
	volatile uint8_t EGP;
	volatile uint8_t EGN;
}EXT_Interrupt_Type, *EXT_Interrupt_MemMapPtr;


#define EXT_INTERRUPT_EDGE_ENABLE_REGISTER_0_BASE									   													(0xFF38)
#define EXT_INT0						  									   ((EXT_Interrupt_Type *)EXT_INTERRUPT_EDGE_ENABLE_REGISTER_0_BASE)

#define EXT_INTERRUPT_EDGE_ENABLE_REGISTER_1_BASE									   													(0xFF3A)
#define EXT_INT1						  									   ((EXT_Interrupt_Type *)EXT_INTERRUPT_EDGE_ENABLE_REGISTER_1_BASE)

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
	volatile uint8_t CKS1;
}CLK_Type, *CLK_MemMapPtr;


#define CLOCK_CONFIGURATION_REGISTER_BASE										   														(0xFFA0)
#define CLOCK									    											 ((CLK_Type *)CLOCK_CONFIGURATION_REGISTER_BASE)

/* High Speed Oscillator Trimming Register Address */
#define HIGH_SPEED_OSC_TRIM_REGISTER_BASE										   														(0x00A0)
#define HIGH_SPEED_OSC_TRIM_REGISTER					   								*((volatile uint8_t *)HIGH_SPEED_OSC_TRIM_REGISTER_BASE)

/* High Speed Oscillator Frequency Select Register Address */
#define HIGH_SPEED_OSC_FREQ_SELECT_REGISTER_BASE									   													(0x00A8)
#define HIGH_SPEED_OSC_FREQ_SELECT_REGISTER			    						 *((volatile uint8_t *)HIGH_SPEED_OSC_FREQ_SELECT_REGISTER_BASE)

/* Sub System Clock Supply Mode Control Register Address */
#define SUB_SYS_CLK_SUPPLY_MODE_CTRL_REG_BASE									           												(0x00F3)
#define SUB_SYS_CLK_SUPPLY_MODE_CTRL_REGISTER			       						*((volatile uint8_t *)SUB_SYS_CLK_SUPPLY_MODE_CTRL_REG_BASE)

/* ---------------------------------------------------------- Clock Configuration Handlers --------------------------------------------------------- */














/* ------------------------------------------------------------ Safety Function Registers ---------------------------------------------------------- */

/* CRC Input Register Base Address */
#define CRC_INPUT_REGISTER_BASE												   															(0xFFAC)
#define CRC_INPUT_REGISTER							     										  *((volatile uint8_t *)CRC_INPUT_REGISTER_BASE)

/* Invalid Memory Access Detection Control Register Address */
#define INVALID_MEM_ACCESS_DETECT_CTRL_REGISTER_BASE								  	   												(0x0078)
#define INVALID_MEM_ACCESS_DETECT_CTRL_REGISTER								 *((volatile uint8_t *)INVALID_MEM_ACCESS_DETECT_CTRL_REGISTER_BASE)

/* RAM Parity Error Control Register Address */
#define RAM_PARITY_ERROR_CTRL_REGISTER_BASE										   														(0x00F5)
#define RAM_PARITY_ERROR_CTRL_REGISTER					 							  *((volatile uint8_t *)RAM_PARITY_ERROR_CTRL_REGISTER_BASE)

/* Flash Memory CRC Control Register Address */
#define FLASH_MEM_CRC_CTRL_REGISTER_BASE										   														(0x02F0)
#define FLASH_MEM_CRC_CTRL_REGISTER					    								 *((volatile uint8_t *)FLASH_MEM_CRC_CTRL_REGISTER_BASE)

/* Flash Memory CRC Operation Result Register Address */
#define FLASH_MEM_CRC_OPER_RESULT_REGISTER_BASE										   													(0x02F2)
#define FLASH_MEM_CRC_OPER_RESULT_REGISTER			    						 *((volatile uint16_t *)FLASH_MEM_CRC_OPER_RESULT_REGISTER_BASE)

/* CRC Data Register */
#define CRC_DATA_REGISTER_BASE												   															(0x02FA)
#define CRC_DATA_REGISTER							     										  *((volatile uint16_t *)CRC_DATA_REGISTER_BASE)

/* ------------------------------------------------------------ Safety Function Registers ---------------------------------------------------------- */














/* ------------------------------------------------------------- Serial Control Registers --------------------------------------------------------- */

/* Serial Data Register Definition */
typedef struct {
	volatile uint8_t SDR_L;
	volatile uint8_t SDR_H;
} SDR_Type, *SDR_MemMapPtr;


#define SERIAL_DATA_REGISTER_00_BASE											   														(0xFF10)
#define SDR00										  												   (SDR_Type *)SERIAL_DATA_REGISTER_00_BASE)

#define SERIAL_DATA_REGISTER_01_BASE											   														(0xFF12)
#define SDR01										  												   (SDR_Type *)SERIAL_DATA_REGISTER_01_BASE)

#define SERIAL_DATA_REGISTER_02_BASE											   														(0xFF44)
#define SDR02										  												   (SDR_Type *)SERIAL_DATA_REGISTER_02_BASE)

#define SERIAL_DATA_REGISTER_03_BASE											   														(0xFF46)
#define SDR03										  												   (SDR_Type *)SERIAL_DATA_REGISTER_03_BASE)

#define SERIAL_DATA_REGISTER_10_BASE											   														(0xFF48)
#define SDR10										  												   (SDR_Type *)SERIAL_DATA_REGISTER_10_BASE)

#define SERIAL_DATA_REGISTER_11_BASE											   														(0xFF4A)
#define SDR11										  												   (SDR_Type *)SERIAL_DATA_REGISTER_11_BASE)

#define SERIAL_DATA_REGISTER_12_BASE											   														(0xFF14)
#define SDR12										  												   (SDR_Type *)SERIAL_DATA_REGISTER_12_BASE)

#define SERIAL_DATA_REGISTER_13_BASE											   														(0xFF16)
#define SDR13										  												   (SDR_Type *)SERIAL_DATA_REGISTER_13_BASE)



/* Serial Status Register Definition */
typedef struct {
	union {
		volatile uint8_t SSR_L;
		volatile uint8_t SSR_H;
	}ACCESS_8bit;
	volatile uint16_t SSR;
} SSR_Type, *SSR_MemMapPtr;


#define SERIAL_STATUS_REGISTER_00_BASE											   														(0x0100)
#define SSR00																						 (SSR_Type *)SERIAL_STATUS_REGISTER_00_BASE)

#define SERIAL_STATUS_REGISTER_01_BASE											   														(0x0102)
#define SSR01																						 (SSR_Type *)SERIAL_STATUS_REGISTER_01_BASE)

#define SERIAL_STATUS_REGISTER_02_BASE											   														(0x0104)
#define SSR02																						 (SSR_Type *)SERIAL_STATUS_REGISTER_02_BASE)

#define SERIAL_STATUS_REGISTER_03_BASE											   														(0x0106)
#define SSR03																						 (SSR_Type *)SERIAL_STATUS_REGISTER_03_BASE)

#define SERIAL_STATUS_REGISTER_10_BASE											   														(0x0140)
#define SSR10																						 (SSR_Type *)SERIAL_STATUS_REGISTER_10_BASE)

#define SERIAL_STATUS_REGISTER_11_BASE											  	 													(0x0142)
#define SSR11																						 (SSR_Type *)SERIAL_STATUS_REGISTER_11_BASE)

#define SERIAL_STATUS_REGISTER_12_BASE											  	 													(0x0144)
#define SSR12																						 (SSR_Type *)SERIAL_STATUS_REGISTER_12_BASE)

#define SERIAL_STATUS_REGISTER_13_BASE											   														(0x0146)
#define SSR13																						 (SSR_Type *)SERIAL_STATUS_REGISTER_13_BASE)



/* Serial Flag Clear Trigger Register Definition */
typedef struct {
	union {
		volatile uint8_t SIR_L;
		volatile uint8_t SIR_H;
	}ACCESS_8bit;
	volatile uint16_t SIR;
} SIR_Type, *SIR_MemMapPtr;


#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_00_BASE										   													(0x0108)
#define SIR00								       											(SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_00_BASE)

#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_01_BASE										  	 												(0x010A)
#define SIR01								       											(SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_01_BASE)

#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_02_BASE										   													(0x010C)
#define SIR02								       											(SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_02_BASE)

#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_03_BASE										   													(0x010E)
#define SIR03								       											(SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_03_BASE)

#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_10_BASE										   													(0x0148)
#define SIR10								       											(SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_10_BASE)

#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_11_BASE										   													(0x014A)
#define SIR11								       											(SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_11_BASE)

#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_12_BASE										   													(0x014C)
#define SIR12								       											(SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_12_BASE)

#define SERIAL_FLAG_CLEAR_TRIG_REGISTER_13_BASE										   													(0x014E)
#define SIR13								       											(SIR_Type *)SERIAL_FLAG_CLEAR_TRIG_REGISTER_13_BASE)



/* Serial Mode Register Definition */
typedef struct {
	volatile uint16_t SMR;
} SMR_Type, *SMR_MemMapPtr;


#define SERIAL_MODE_REGISTER_00_BASE											   														(0x0110)
#define SMR00										  												   (SMR_Type *)SERIAL_MODE_REGISTER_00_BASE)

#define SERIAL_MODE_REGISTER_01_BASE											   														(0x0112)
#define SMR01										  												   (SMR_Type *)SERIAL_MODE_REGISTER_01_BASE)

#define SERIAL_MODE_REGISTER_02_BASE											   														(0x0114)
#define SMR02										  												   (SMR_Type *)SERIAL_MODE_REGISTER_02_BASE)

#define SERIAL_MODE_REGISTER_03_BASE											   														(0x0116)
#define SMR03										  												   (SMR_Type *)SERIAL_MODE_REGISTER_03_BASE)

#define SERIAL_MODE_REGISTER_10_BASE											   														(0x0150)
#define SMR10										  												   (SMR_Type *)SERIAL_MODE_REGISTER_10_BASE)

#define SERIAL_MODE_REGISTER_11_BASE											   														(0x0152)
#define SMR11										  												   (SMR_Type *)SERIAL_MODE_REGISTER_11_BASE)

#define SERIAL_MODE_REGISTER_12_BASE											   														(0x0154)
#define SMR12										  												   (SMR_Type *)SERIAL_MODE_REGISTER_12_BASE)

#define SERIAL_MODE_REGISTER_13_BASE											   														(0x0156)
#define SMR13										  												   (SMR_Type *)SERIAL_MODE_REGISTER_13_BASE)



/* Serial Communication Operation Register Definition */
typedef struct {
	volatile uint16_t SCR;
} SCR_Type, *SCR_MemMapPtr;


#define SERIAL_COMM_OPER_REGISTER_00_BASE										   														(0x0118)
#define SCR00									     											  (SCR_Type *)SERIAL_COMM_OPER_REGISTER_00_BASE)

#define SERIAL_COMM_OPER_REGISTER_01_BASE										   														(0x011A)
#define SCR01									     											  (SCR_Type *)SERIAL_COMM_OPER_REGISTER_01_BASE)

#define SERIAL_COMM_OPER_REGISTER_02_BASE										   														(0x011C)
#define SCR02									     											  (SCR_Type *)SERIAL_COMM_OPER_REGISTER_02_BASE)

#define SERIAL_COMM_OPER_REGISTER_03_BASE										   														(0x011E)
#define SCR03									     											  (SCR_Type *)SERIAL_COMM_OPER_REGISTER_03_BASE)

#define SERIAL_COMM_OPER_REGISTER_10_BASE										   														(0x0158)
#define SCR10									     											  (SCR_Type *)SERIAL_COMM_OPER_REGISTER_10_BASE)

#define SERIAL_COMM_OPER_REGISTER_11_BASE										   														(0x015A)
#define SCR11									     											  (SCR_Type *)SERIAL_COMM_OPER_REGISTER_11_BASE)

#define SERIAL_COMM_OPER_REGISTER_12_BASE										   														(0x015C)
#define SCR12									     											  (SCR_Type *)SERIAL_COMM_OPER_REGISTER_12_BASE)

#define SERIAL_COMM_OPER_REGISTER_13_BASE										   														(0x015E)
#define SCR13									     											  (SCR_Type *)SERIAL_COMM_OPER_REGISTER_13_BASE)



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
	volatile uint16_t BL2;
	volatile uint16_t SSC;
} SER_Type, *SER_MemMapPtr;


#define SERIAL_CHANNEL_REGISTER_0_BASE											   														(0x0120)
#define SERIAL0																						 (SER_Type *)SERIAL_CHANNEL_REGISTER_0_BASE)

#define SERIAL_CHANNEL_REGISTER_1_BASE											   														(0x0160)
#define SERIAL1																						 (SER_Type *)SERIAL_CHANNEL_REGISTER_1_BASE)

/* ------------------------------------------------------------- Serial Control Registers --------------------------------------------------------- */










/* ------------------------------------------------------------- LVDS Control Registers ----------------------------------------------------------- */

/* Voltage Functions Register Definition */
typedef struct {
	volatile uint8_t LVIM;
	volatile uint8_t LVIS;
}LVDS_Type, *LVDS_MemMapPtr;


#define VOLTAGE_DETECTION_REGISTER_BASE											   														(0xFFA9)
#define LVDS									      											   (LVDS_Type *)VOLTAGE_DETECTION_REGISTER_BASE)

/* ------------------------------------------------------------- LVDS Control Registers ----------------------------------------------------------- */











/* ------------------------------------------------------- Priority Specification Registers ------------------------------------------------------ */

/* Priority Specification Flag Register Definition */
typedef struct {
	union {
		volatile uint8_t PR_L;
		volatile uint8_t PR_H;
	}ACCESS_8bit;
	volatile uint16_t PR;
}PRS_Type, *PRS_MemMapPtr;


#define PRIORITY_SPECIFICATION_FLAG_REGISTER_00_BASE									   												(0xFFE8)
#define PR00								 										  ((PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_00_BASE)

#define PRIORITY_SPECIFICATION_FLAG_REGISTER_01_BASE									   												(0xFFEA)
#define PR01								 										  ((PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_01_BASE)

#define PRIORITY_SPECIFICATION_FLAG_REGISTER_02_BASE									   												(0xFFD8)
#define PR02								 										  ((PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_02_BASE)

#define PRIORITY_SPECIFICATION_FLAG_REGISTER_03_BASE									   												(0xFFDA)
#define PR03								 										  ((PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_03_BASE)

#define PRIORITY_SPECIFICATION_FLAG_REGISTER_10_BASE									   												(0xFFEC)
#define PR10								 										  ((PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_10_BASE)

#define PRIORITY_SPECIFICATION_FLAG_REGISTER_11_BASE									   												(0xFFEE)
#define PR11								 										  ((PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_11_BASE)

#define PRIORITY_SPECIFICATION_FLAG_REGISTER_12_BASE									   												(0xFFDC)
#define PR12								 										  ((PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_12_BASE)

#define PRIORITY_SPECIFICATION_FLAG_REGISTER_13_BASE									   												(0xFFDE)
#define PR13								 										  ((PRS_Type *)PRIORITY_SPECIFICATION_FLAG_REGISTER_13_BASE)

/* ------------------------------------------------------- Priority Specification Registers ------------------------------------------------------ */















/* Key Mode Register Base Address */
#define KEY_MODE_REGISTER_BASE						 						   															(0xFF37)
#define KEY_MODE_REGISTER							      										   *((volatile uint8_t *)KEY_MODE_REGISTER_BASE)

/* Reset Control Flag Register Base Address */
#define RESET_CONTROL_FLAG_REGISTER_BASE			 							   														(0xFFA8)
#define RESET_CONTROL_FLAG_REGISTER					    								 *((volatile uint8_t *)RESET_CONTROL_FLAG_REGISTER_BASE)

/* Watchdog Timer Enable Register Base Address */
#define WATCHDOG_TIMER_ENABLE_REGISTER_BASE					 					   														(0xFFAB)
#define WATCHDOG_TIMER_ENABLE_REGISTER					 							  *((volatile uint8_t *)WATCHDOG_TIMER_ENABLE_REGISTER_BASE)

/* Data Flash Control Register Address */
#define DATA_FLASH_CTRL_REGISTER_BASE											   														(0x0090)
#define DATA_FLASH_CTRL_REGISTER					       									*((volatile uint8_t *)DATA_FLASH_CTRL_REGISTER_BASE)

/* Peripheral Enable Register Address */
#define PERIPHERAL_ENABLE_REGISTER_BASE											   														(0x00F0)
#define PERIPHERAL_ENABLE_REGISTER					     								  *((volatile uint8_t *)PERIPHERAL_ENABLE_REGISTER_BASE)

/* BCD Adjust Result Register Address */
#define BCD_ADJUST_RESULT_REGISTER_BASE											   														(0x00FE)
#define BCD_ADJUST_RESULT_REGISTER					     								  *((volatile uint8_t *)BCD_ADJUST_RESULT_REGISTER_BASE)


#endif
