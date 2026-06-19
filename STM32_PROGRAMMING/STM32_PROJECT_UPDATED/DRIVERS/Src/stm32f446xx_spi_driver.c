/*
 * stm32f446xx_spi_driver.c
 *
 * Created on: 2026
 * Author: anagha
 */

#include "stm32f446xx.h"
#include "stm32f446xx_spi_driver.h"


void spi_clock_control(spi_reg_t *spi,uint8_t state)
{
	if(state == ENABLE_FLAG)
	{
		if(spi == SPI1)
		{
			SPI1_CLK_ENABLE();
		}
		else if(spi == SPI2)
		{
			SPI2_CLK_ENABLE();
		}
		else if(spi == SPI3)
		{
			SPI3_CLK_ENABLE();
		}
		else if(spi == SPI4)
		{
			SPI4_CLK_ENABLE();
		}
	}
	else
	{
		if(spi == SPI1)
		{
			SPI1_CLK_DISABLE();
		}
		else if(spi == SPI2)
		{
			SPI2_CLK_DISABLE();
		}
		else if(spi == SPI3)
		{
			SPI3_CLK_DISABLE();
		}
		else if(spi == SPI4)
		{
			SPI4_CLK_DISABLE();
		}
	}
}


void spi_init(spi_handle_t *handle)
{
	uint32_t temp = 0;

	/* Device Mode */

	temp |= (handle->config.deviceMode << 2);

	/* Bus Configuration */

	if(handle->config.busConfig == SPI_BUS_FULL_DUPLEX)
	{
		temp &= ~(1 << 15);
	}
	else if(handle->config.busConfig == SPI_BUS_HALF_DUPLEX)
	{
		temp |= (1 << 15);
	}
	else if(handle->config.busConfig == SPI_BUS_SIMPLEX_RXONLY)
	{
		temp &= ~(1 << 15);
		temp |= (1 << 10);
	}

	/* Clock Speed */

	temp |= (handle->config.sclkSpeed << 3);

	/* DFF */

	temp |= (handle->config.dff << 11);

	/* CPOL */

	temp |= (handle->config.cpol << 1);

	/* CPHA */

	temp |= (handle->config.cpha << 0);

	/* SSM */

	temp |= (handle->config.ssm << 9);

	handle->spi->CR1 = temp;
}


void spi_peripheral_control(spi_reg_t *spi,uint8_t state)
{
	if(state == ENABLE_FLAG)
	{
		spi->CR1 |= (1 << 6);
	}
	else
	{
		spi->CR1 &= ~(1 << 6);
	}
}


void spi_send_data(spi_reg_t *spi,uint8_t *buffer,uint32_t len)
{
	while(len > 0)
	{
		while(!(spi->SR & (1 << 1)));

		if(spi->CR1 & (1 << 11))
		{
			spi->DR = *((uint16_t*)buffer);

			len -= 2;

			buffer += 2;
		}
		else
		{
			spi->DR = *buffer;

			buffer++;

			len--;
		}
	}
}


void spi_receive_data(spi_reg_t *spi,uint8_t *buffer,uint32_t len)
{
	while(len > 0)
	{
		while(!(spi->SR & (1 << 0)));

		if(spi->CR1 & (1 << 11))
		{
			*((uint16_t*)buffer) = spi->DR;

			len -= 2;

			buffer += 2;
		}
		else
		{
			*buffer = spi->DR;

			buffer++;

			len--;
		}
	}
}
