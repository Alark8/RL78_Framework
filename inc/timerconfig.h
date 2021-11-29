#ifndef TIMERCONFIG_H
#define TIMERCONFIG_H

#include "rl78_d1a_head.h"

typedef enum {LSB, MSB} WORD;
typedef enum {CKM0, CKM1, CKM2, CKM3} CLK_OPT;
typedef enum {FALLING_EDGE, RISING_EDGE, BOTH_EDGE_LOW, BOTH_EDGE_HIGH} TIMN_IP;
typedef enum {SW_TRIG=0, SINGLE_EDGE_TIMN=1, DUAL_EDGE_TIMN=2, INT_SIGNAL=4} TRG_OPT;
typedef enum {INTERVAL_TMR_WO_INT=0, INTERVAL_TMR_INT=1, CAPTURE_WO_INT=4, CAPTURE_INT=5, EVENT_COUNTER=6, ONE_COUNT_WO_INT=8, ONE_COUNT_INT=9, CAPTURE_ONE_COUNT=12} TMR_OPT;



typedef struct {
	CLK_OPT clk_option;
	TRG_OPT trigger_option;
	TMR_OPT timer_mode;
	TIMN_IP valid_edge_TImn;
	INT_PRIORITY timer_intp_priority;
	uint16_t clock_TImn_enabled							:1;
	uint16_t master_channel								:1;
	uint16_t timer_output_enabled						:1;
	uint16_t timer_output_active_low					:1;
	uint16_t timer_output_toggle_mode					:1;
	uint16_t noise_filter_enable						:1;
	uint16_t timer_ip_alternate_pin_select				:2;
	uint16_t timer_out_alternate_pin_select				:2;
	uint16_t timer_start								:1;
	uint16_t noise_filter_clock_select					:1;
	uint16_t timer_channel_used							:1;
	uint16_t reserve									:3;
}TMRChannel_Config;




typedef struct {
	TMRChannel_Config CH0;
	TMRChannel_Config CH1;
	TMRChannel_Config CH2;
	TMRChannel_Config CH3;
	TMRChannel_Config CH4;
	TMRChannel_Config CH5;
	TMRChannel_Config CH6;
	TMRChannel_Config CH7;
}ChannelData;




typedef struct {
	ChannelData timer_channels;
	uint16_t ckm0_fclk_divider							:4;
	uint16_t ckm1_fclk_divider							:4;
	uint16_t ckm2_fclk_divider							:4;
	uint16_t ckm3_fclk_divider							:4;
	uint16_t noise_filter_sample_clock0					:4;
	uint16_t noise_filter_sample_clock1					:4;
	uint16_t reserve									:8;
}TIMER_Config;


TIMER_Config DefaultTimerSetting(void);
TMRChannel_Config DefaultTimerChannelSetting(void);


#endif
