#ifndef INTERRUPTCONFIG_H
#define INTERRUPTCONFIG_H

#include "rl78_d1a_head.h"


#define WATCHDOG_IRQn																	0x00
#define VOLTAGE_DETECT_IRQn																0x01
#define EXT_INTERRUPT0_IRQn																0x02
#define EXT_INTERRUPT1_IRQn																0x03
#define EXT_INTERRUPT2_IRQn																0x04
#define EXT_INTERRUPT3_IRQn																0x05
#define EXT_INTERRUPT4_IRQn																0x06
#define EXT_INTERRUPT5_IRQn																0x07
#define CLOCK_INTERRUPT_IRQn															0x08
#define UART0_TX_IRQn																	0x09
#define UART0_RX_IRQn																	0x0A
#define DMA0_TX_IRQn																	0x0B
#define DMA1_TX_IRQn																	0x0C
#define RTC_ALARM_IRQn																	0x0D
#define INTERVAL_TIMER_IRQn																0x0E
#define LIN_UART0_TX_IRQn																0x0F
#define LIN_UART0_RX_IRQn																0x10
#define LIN_UART0_RX_STATUS_IRQn														0x11
#define LIN_UART0_RX_PIN_IP_IRQn														0x12
#define SG_ALD_IRQn																		0x13
#define TAU0_CHANNEL0_IRQn																0x14
#define TAU0_CHANNEL1_IRQn																0x15
#define TAU0_CHANNEL2_IRQn																0x16
#define TAU0_CHANNEL3_IRQn																0x17
#define ADC_CONVERSION_IRQn																0x18
#define LIN_UART1_TX_IRQn																0x19
#define LIN_UART1_RX_IRQn																0x1A
#define LIN_UART1_RX_STATUS_IRQn														0x1B
#define LIN_UART1_RX_PIN_IP_IRQn														0x1C
#define CSI10_COMM_IRQn																	0x1D
#define IIC11_COMM_IRQn																	0x1E
#define TAU0_CHANNEL4_IRQn																0x1F
#define TAU0_CHANNEL5_IRQn																0x20
#define TAU0_CHANNEL6_IRQn																0x21
#define TAU0_CHANNEL7_IRQn																0x22
#define CAN1_ERROR_IRQn																	0x23
#define CAN1_WAKEUP_IRQn																0x24
#define CAN0_ERROR_IRQn																	0x25
#define CAN0_WAKEUP_IRQn																0x26
#define CAN0_RX_IRQn																	0x27
#define CAN0_TX_IRQn																	0x28
#define TAU1_CHANNEL0_IRQn																0x29
#define TAU1_CHANNEL1_IRQn																0x2A
#define TAU1_CHANNEL2_IRQn																0x2B
#define TAU1_CHANNEL3_IRQn																0x2C
#define END_OF_DIV_IRQn																	0x2D
#define CAN1_RX_IRQn																	0x2E
#define END_OF_SEQ_IRQn																	0x2F
#define CAN1_TX_IRQn																	0x30
#define TAU1_CHANNEL4_IRQn																0x31
#define TAU1_CHANNEL5_IRQn																0x32
#define TAU1_CHANNEL6_IRQn																0x33
#define TAU1_CHANNEL7_IRQn																0x34
#define TAU2_CHANNEL0_IRQn																0x35
#define TAU2_CHANNEL1_IRQn																0x36
#define TAU2_CHANNEL2_IRQn																0x37
#define TAU2_CHANNEL3_IRQn																0x38
#define TAU2_CHANNEL4_IRQn																0x39
#define TAU2_CHANNEL6_IRQn																0x3A
#define DMA2_TX_IRQn																	0x3B
#define DMA3_TX_IRQn																	0x3C


#define MAX_IRQn																DMA3_TX_IRQn


/* Interrupt configuration structure, add the interrupts you want to enable into interrupts array */
typedef struct{
	uint8_t *interrupts;
	uint8_t number_of_interrupts;
}INTERRUPT_Config;


INTERRUPT_Config DefaultInterruptSetting(void);			//Function to get the interrupt configuration settings

#endif
