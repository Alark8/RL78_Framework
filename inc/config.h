#ifndef CONFIG_H
#define CONFIG_H

#define uint8_t 										unsigned char
#define int8_t											  signed char
#define uint16_t									   unsigned short
#define int16_t											 signed short
#define uint32_t										unsigned long
#define int32_t 										  signed long

#define TRUE														1
#define FALSE														0


/* Sample configuration for different features */
#define FUEL_AVERAGE_SAMPLES		  								8
#define RTMI_AVERAGE_SAMPLES		 							   16
#define BATT_AVERAGE_SAMPLES		 							   16

/* Channel and various configuration for different features */
#define FUEL_ADC_CHANNEL		 								   10
#define ADC_RESOLUTION_BITS		 								   10
#define ADC_CONVERSION_VOLTAGE									  3.3


/*Configuration for setting the priority of various interrupts
 * LV0 -> Highest priority
 * LV3 -> Lowest priority */
typedef enum {LVL0, LVL1, LVL2, LVL3} INT_PRIORITY;


#endif
