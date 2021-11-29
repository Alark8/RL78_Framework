#ifndef MAIN_H
#define MAIN_H

#include "clock.h"
#include "intervaltimer.h"
#include "gpio.h"
#include "lcdsegmentcontrol.h"
#include "adccontrol.h"
#include "displayitems.h"
#include "interrupt.h"
#include "eeprom.h"

#define LOW_FUEL_TT									57				//P71
#define I3S_TT										56				//P70
#define SIDE_STAND_TT								52				//P64
#define LCD_ILL_OUT									48				//P60
#define BT_SWT_ON									53				//P65

#define POSITIVE_REFERENCE							16				//P20
#define NEGATIVE_REFERENCE							17				//P21
#define SIDE_STAND_IP								20				//P24
#define FUEL_RESISTANCE_IP							22				//P26
#define FUEL_MONITOR_IP								23				//P27

#define SIDE_STAND_ANALOG_CH						 4
#define FUEL_RESISTANCE_ANALOG_CH					 6
#define FUEL_MONITOR_ANALOG_CH						 7

extern volatile uint32_t msTicks;

void GPIOInitialize(void);
void ManageSystem(void);
void DummyFunction(void);


#endif
