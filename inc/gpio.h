#ifndef GPIO_H
#define GPIO_H

/* Following is the number map for GPIO, it supports till 128pin devices, request you to kindly configure carefully
 *
 * 00	: PM00				24	  : PM30				48	  : PM60				72	  : PM90				96	  : PM120			   120	  : PM150
 * 01	: PM01				25	  : PM31				49	  : PM61				73	  : PM91				97	  : PM121			   121	  : PM151
 * 02	: PM02				26	  : PM32				50	  : PM62				74	  : PM92				98	  : PM122			   122	  : PM152
 * 03	: PM03				27	  : PM33				51	  : PM63				75	  : PM93				99	  : PM123			   123	  : PM153
 * 04	: PM04				28	  : PM34				52	  : PM64				76	  : PM94			   100	  : PM124			   124	  : PM154
 * 05	: PM05				29	  : PM35				53	  : PM65				77	  : PM95			   101	  : PM125			   125	  : PM155
 * 06	: PM06				30	  : PM36				54	  : PM66				78	  : PM96			   102	  : PM126			   126	  : PM156
 * 07	: PM07				31	  : PM37				55	  : PM67				79	  : PM97			   103	  : PM127			   127	  : PM157
 *
 * 08	: PM10				32	  : PM40				56	  : PM70				80	  : PM100			   104	  : PM130
 * 09	: PM11				33	  : PM41				57	  : PM71				81	  : PM101			   105	  : PM131
 * 10	: PM12				34	  : PM42				58	  : PM72				82	  : PM102			   106	  : PM132
 * 11	: PM13				35	  : PM43				59	  : PM73				83	  : PM103			   107	  : PM133
 * 12	: PM14				36	  : PM44				60	  : PM74				84	  : PM104			   108	  : PM134
 * 13	: PM15				37	  : PM45				61	  : PM75				85	  : PM105			   109	  : PM135
 * 14	: PM16				38	  : PM46				62	  : PM76				86	  : PM106			   110	  : PM136
 * 15	: PM17				39	  : PM47				63	  : PM77				87	  : PM107			   111	  : PM137
 *
 * 16	: PM20				40	  : PM50				64	  : PM80				88	  : PM110			   112	  : PM140
 * 17	: PM21				41	  : PM51				65	  : PM81				89	  : PM111			   113	  : PM141
 * 18	: PM22				42	  : PM52				66	  : PM82				90	  : PM112			   114	  : PM142
 * 19	: PM23				43	  : PM53				67	  : PM83				91	  : PM113			   115	  : PM143
 * 20	: PM24				44	  : PM54				68	  : PM84				92	  : PM114			   116	  : PM144
 * 21	: PM25				45	  : PM55				69	  : PM85				93	  : PM115			   117	  : PM145
 * 22	: PM26				46	  : PM56				70	  : PM86				94	  : PM116			   118	  : PM146
 * 23	: PM27 				47	  : PM57				71	  : PM87				95	  : PM117			   119	  : PM147
 *
*/

#include "rl78_d1a_head.h"


typedef enum {LOW, HIGH} GPIO_LEVEL;
typedef enum {OUTPUT, INPUT} GPIO_STATE;
typedef enum {DISABLE, ENABLE} GPIO_PULLUP;


#define GPIO_NO_ERROR																		0x00
#define GPIO_OUT_OF_LIMIT_ERROR																0x01
#define GPIO_STATE_INVALID_ERROR															0x02
#define GPIO_LEVEL_INVALID_ERROR															0x04
#define GPIO_PULLUP_INVALID_ERROR															0x10


#define DIVIDE_BY_8																			0x03
#define MODULO_BY_8																			0x07
#define MAX_GPIO_COUNT																		0x7F
#define MAX_GPIO_COUNT_PULLUP																0x70


uint8_t GpioToggle(uint8_t gpio_number);
uint8_t GpioSet(uint8_t gpio_number, uint8_t gpio_level);
uint8_t GpioConfig(uint8_t gpio_number, uint8_t gpio_state);
uint8_t GpioSetMultiple(uint8_t (*gpio_data)[2], uint8_t length);
uint8_t GpioPullUpConfig(uint8_t gpio_number, uint8_t gpio_state);
uint8_t GpioConfigMultiple(uint8_t (*gpio_data)[2], uint8_t length);
uint8_t GpioPullUpConfigMultiple(uint8_t (*gpio_data)[2], uint8_t length);

#endif
