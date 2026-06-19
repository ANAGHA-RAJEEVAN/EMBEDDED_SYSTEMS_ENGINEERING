/*
 * stm32f446xx_usart_driver.c
 *
 * Created on: 2026
 * Author: anagha
 */

#include "stm32f446xx.h"
#include "stm32f446xx_usart_driver.h"

void usart_clock_control(usart_reg_t *usart,uint8_t state)
{
	if(state == ENABLE_FLAG)
	{
		if(usart == USART1)
		{
			USART1_CLK_ENABLE();
		}
		else if(usart == USART2)
		{
			USART2_CLK_ENABLE();
		}
		else if(usart == USART3)
		{
			USART3_CLK_ENABLE();
		}
		else if(usart == USART6)
		{
			USART6_CLK_ENABLE();
		}
	}
	else
	{
		if(usart == USART1)
		{
			USART1_CLK_DISABLE();
		}
		else if(usart == USART2)
		{
			USART2_CLK_DISABLE();
		}
		else if(usart == USART3)
		{
			USART3_CLK_DISABLE();
		}
		else if(usart == USART6)
		{
			USART6_CLK_DISABLE();
		}
	}
}

void usart_init(usart_handle_t *handle)
{
	uint32_t temp = 0;

	if(handle->config.wordLength == USART_WORDLEN_9BITS)
	{
		temp |= (1 << 12);
	}

	if(handle->config.parityControl == USART_PARITY_EVEN)
	{
		temp |= (1 << 10);
	}
	else if(handle->config.parityControl == USART_PARITY_ODD)
	{
		temp |= (1 << 10);
		temp |= (1 << 9);
	}

	if(handle->config.mode == USART_MODE_TX)
	{
		temp |= (1 << 3);
	}
	else if(handle->config.mode == USART_MODE_RX)
	{
		temp |= (1 << 2);
	}
	else
	{
		temp |= (1 << 2);
		temp |= (1 << 3);
	}

	handle->usart->CR1 = temp;

	handle->usart->BRR = 0x0683;

	handle->usart->CR1 |= (1 << 13);
}

void usart_send_data(usart_reg_t *usart,uint8_t *buffer,uint32_t len)
{
	while(len)
	{
		while(!(usart->SR & (1 << 7)));

		usart->DR = *buffer;

		buffer++;
		len--;
	}
}

void usart_receive_data(usart_reg_t *usart,uint8_t *buffer,uint32_t len)
{
	while(len)
	{
		while(!(usart->SR & (1 << 5)));

		*buffer = (uint8_t)usart->DR;

		buffer++;
		len--;
	}
}
