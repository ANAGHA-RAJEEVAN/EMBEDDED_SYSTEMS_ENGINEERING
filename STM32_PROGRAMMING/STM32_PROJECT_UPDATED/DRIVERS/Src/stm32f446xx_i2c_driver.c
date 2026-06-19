/*
 * stm32f446xx_i2c_driver.c
 *
 * Created on: 2026
 * Author: anagha
 */

#include "stm32f446xx.h"
#include "stm32f446xx_i2c_driver.h"


void i2c_clock_control(i2c_reg_t *i2c,uint8_t state)
{
	if(state == ENABLE_FLAG)
	{
		if(i2c == I2C1)
		{
			I2C1_CLK_ENABLE();
		}
		else if(i2c == I2C2)
		{
			I2C2_CLK_ENABLE();
		}
		else if(i2c == I2C3)
		{
			I2C3_CLK_ENABLE();
		}
	}
	else
	{
		if(i2c == I2C1)
		{
			I2C1_CLK_DISABLE();
		}
		else if(i2c == I2C2)
		{
			I2C2_CLK_DISABLE();
		}
		else if(i2c == I2C3)
		{
			I2C3_CLK_DISABLE();
		}
	}
}


void i2c_init(i2c_handle_t *handle)
{
	handle->i2c->CR1 = 0;

	handle->i2c->CR2 = 16;

	handle->i2c->CCR = 80;

	handle->i2c->TRISE = 17;

	handle->i2c->OAR1 =(handle->config.deviceAddress << 1);

	if(handle->config.ackControl == I2C_ACK_ENABLE)
	{
		handle->i2c->CR1 |= (1 << 10);
	}

	handle->i2c->CR1 |= (1 << 0);
}


void i2c_generate_start(i2c_reg_t *i2c)
{
	i2c->CR1 |= (1 << 8);

	while(!(i2c->SR1 & (1 << 0)));
}


void i2c_generate_stop(i2c_reg_t *i2c)
{
	i2c->CR1 |= (1 << 9);
}


void i2c_master_send_data(i2c_handle_t *handle,uint8_t *buffer,uint32_t len,uint8_t slaveAddress)
{
	i2c_generate_start(handle->i2c);

	handle->i2c->DR = (slaveAddress << 1);

	while(!(handle->i2c->SR1 & (1 << 1)));

	(void)handle->i2c->SR1;
	(void)handle->i2c->SR2;

	while(len)
	{
		while(!(handle->i2c->SR1 & (1 << 7)));

		handle->i2c->DR = *buffer;

		buffer++;
		len--;
	}

	while(!(handle->i2c->SR1 & (1 << 2)));

	i2c_generate_stop(handle->i2c);
}


void i2c_master_receive_data(i2c_handle_t *handle,uint8_t *buffer,uint32_t len,uint8_t slaveAddress)
{
	i2c_generate_start(handle->i2c);

	handle->i2c->DR =(slaveAddress << 1) | 1;

	while(!(handle->i2c->SR1 & (1 << 1)));

	(void)handle->i2c->SR1;
	(void)handle->i2c->SR2;

	while(len)
	{
		while(!(handle->i2c->SR1 & (1 << 6)));

		*buffer = handle->i2c->DR;

		buffer++;
		len--;
	}

	i2c_generate_stop(handle->i2c);
}


