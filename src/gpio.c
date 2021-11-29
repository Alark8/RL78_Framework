#include "gpio.h"


/* API for configuring the GPIO */
uint8_t GpioConfig(uint8_t gpio_number, uint8_t gpio_state)
{
	uint8_t error=0, pin=0;
	uint16_t base=0;

	error = (gpio_number > MAX_GPIO_COUNT) ? GPIO_OUT_OF_LIMIT_ERROR : GPIO_NO_ERROR;			//Validation for gpio number
	error = (gpio_state > INPUT) ? GPIO_STATE_INVALID_ERROR : GPIO_NO_ERROR;					//Validation for gpio state

	if(error) return error;

	base += ((gpio_number >> DIVIDE_BY_8) + PORT_MODE_REGISTER_BASE);				//Get the port base
	pin = (gpio_number & MODULO_BY_8);												//Get the pin number

	if(gpio_state)									//Input
		*(uint8_t *)base |= (1 << pin);
	else
		*(uint8_t *)base &= ~(1 << pin);			//Output

	return error;
}



/* To configure multiple GPIOs */
uint8_t GpioConfigMultiple(uint8_t (*gpio_data)[2], uint8_t length)
{
	uint8_t idx=0, error=0;

	while(idx != length)
		error |= GpioConfig(gpio_data[idx][0], gpio_data[idx++][1]);				//Call to GpioConfig

	return error;
}



/* API for setting the GPIO High or Low */
uint8_t GpioSet(uint8_t gpio_number, uint8_t gpio_level)
{
	uint8_t error=0, pin=0;
	uint16_t base=0;

	error = (gpio_number > MAX_GPIO_COUNT) ? GPIO_OUT_OF_LIMIT_ERROR : GPIO_NO_ERROR;				//Validation for GPIO number
	error = (gpio_level > HIGH) ? GPIO_LEVEL_INVALID_ERROR : GPIO_NO_ERROR;							//Validation for GPIO level

	if(error) return error;

	base += ((gpio_number >> DIVIDE_BY_8) + PORT_REGISTER_BASE);						//Get the port base
	pin = (gpio_number & MODULO_BY_8);													//Get the pin number

	if(gpio_level)
		*(uint8_t *)base |= (1 << pin);						//High logic level
	else
		*(uint8_t *)base &= ~(1 << pin);					//Low logic level

	return error;
}



/* To set multiple GPIOs */
uint8_t GpioSetMultiple(uint8_t (*gpio_data)[2], uint8_t length)
{
	uint8_t idx=0, error=0;

	while(idx != length)
		error |= GpioSet(gpio_data[idx][0], gpio_data[idx++][1]);				//Call to GpioSet

	return error;
}



/* API for Toggling the GPIO */
uint8_t GpioToggle(uint8_t gpio_number)
{
	uint8_t pin=0, error = (gpio_number > MAX_GPIO_COUNT) ? GPIO_OUT_OF_LIMIT_ERROR : GPIO_NO_ERROR;
	uint16_t base=0;

	if(error) return error;

	base += ((gpio_number >> DIVIDE_BY_8) + PORT_REGISTER_BASE);				//Get the port base
	pin = (gpio_number & MODULO_BY_8);											//Get the pin number

	*(uint8_t *)base ^= (1 << pin);					//Toggle the GPIO

	return error;
}



/* API for Pull up configuration of GPIO */
uint8_t GpioPullUpConfig(uint8_t gpio_number, uint8_t gpio_state)
{
	uint8_t error=0, pin=0;
	uint16_t base=0;

	error = (gpio_number > MAX_GPIO_COUNT) ? GPIO_OUT_OF_LIMIT_ERROR : GPIO_NO_ERROR;			//Validation of GPIO number
	error = (gpio_state > ENABLE) ? GPIO_PULLUP_INVALID_ERROR : GPIO_NO_ERROR;					//Validation of GPIO state

	if(error) return error;

	base += ((gpio_number >> DIVIDE_BY_8) + PULL_UP_RESISTOR_BASE);						//Get the port base
	pin = (gpio_number & MODULO_BY_8);													//Get the pin number

	if(gpio_state)
		*(uint8_t *)base |= (1 << pin);				//Enable the pull up
	else
		*(uint8_t *)base &= ~(1 << pin);			//Disable the pull up

	return error;
}



/* To configure the pull up of multiple GPIOs */
uint8_t GpioPullUpConfigMultiple(uint8_t (*gpio_data)[2], uint8_t length)
{
	uint8_t idx=0, error=0;

	while(idx != length)
		error |= GpioPullUpConfig(gpio_data[idx][0], gpio_data[idx++][1]);

	return error;
}




