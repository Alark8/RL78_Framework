#include "utils.h"
#include <stdlib.h>

/* Moving Average Filtering Mechanism */
void GetMovingAverage(DataSequence *data)
{
	data->current_idx %= data->avg_size;					//Get the current index of the data

	data->sum -= data->samples[data->current_idx];			//Remove the current index data from the sum
	data->samples[data->current_idx] = data->input;			//Current index data = recent input data
	data->sum += data->input;								//Sum = Sum + recent input data
	data->output = data->sum >> data->avg_num_bits;			//Output = sum/(number of bits based on avg size) i.e. (if avg_size = 8 then avg_num_bits = 3)
	
	++data->current_idx;
}

DataSequence GetDataMemory(uint8_t average_size)
{
	uint8_t bits=0;
	DataSequence data = {(0)};
	uint16_t *mem_address = (uint16_t *)calloc(average_size, sizeof(uint16_t));			//Get memory allocated for the data structure
	
	if(mem_address)							//Not NULL
	{
		data.avg_size = average_size;		//Load average size
		data.samples = mem_address;			//Load mem_address
		
		while(average_size >>= 1)
			++bits;
		
		data.avg_num_bits = bits;			//Load average num bits
	}
	
	return data;
}
