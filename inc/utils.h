#ifndef UTILS_H
#define UTILS_H

#include "config.h"


/* Standard data structure for applying filtering to */
typedef struct{
	uint8_t avg_size;
	uint8_t current_idx;
	uint8_t avg_num_bits;
	uint8_t reserve;
	uint16_t *samples;
	uint16_t input;
	uint16_t output;
	uint16_t sum;
}DataSequence;

void GetMovingAverage(DataSequence *data);
DataSequence GetDataMemory(uint8_t average_size);

#endif
