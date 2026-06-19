#include <stdint.h>
#include <stdio.h>

#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_i2c_driver.h"
#include "main.h"

#define LM75_ADDRESS    0x48

/*void delay_ms(uint32_t delay)
{
	for(uint32_t i = 0 ; i < delay * 5000 ; i++);
}*/

#if I2C_APP
int main(void)
{
	uint8_t temp_data[2];

	/*---------------- GPIO CONFIGURATION ----------------*/

	gpio_handle_t i2c_gpio;

	i2c_gpio.port = GPIO_PORTB;
	i2c_gpio.config.pinMode = PIN_MODE_ALTFN;
	i2c_gpio.config.pinAltFun = 4;
	i2c_gpio.config.pinSpeed = PIN_SPEED_FAST;
	i2c_gpio.config.pinType = OUTPUT_OPEN_DRAIN;
	i2c_gpio.config.pinPull = PULL_UP;

	gpio_clock_control(GPIO_PORTB,ENABLE_FLAG);

	/* PB8 -> SCL */

	i2c_gpio.config.pinNumber = PIN_8;
	gpio_init(&i2c_gpio);

	/* PB9 -> SDA */

	i2c_gpio.config.pinNumber = PIN_9;
	gpio_init(&i2c_gpio);

	/*---------------- I2C CONFIGURATION ----------------*/

	i2c_handle_t i2c1_handle;

	i2c1_handle.i2c = I2C1;

	i2c1_handle.config.sclSpeed = I2C_SCL_SPEED_SM;

	i2c1_handle.config.deviceAddress = 0x61;

	i2c1_handle.config.ackControl = I2C_ACK_ENABLE;

	i2c_clock_control(I2C1,ENABLE_FLAG);

	i2c_init(&i2c1_handle);

	while(1)
	{
		i2c_master_receive_data(&i2c1_handle,temp_data,2,LM75_ADDRESS);

		delay_ms(1000);
	}
}
#endif

