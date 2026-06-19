/*
 * stm32f446xx_usart_driver.h
 *
 *  Created on: 2026
 *      Author: anagha
 */

#ifndef INC_STM32F446XX_USART_DRIVER_H_
#define INC_STM32F446XX_USART_DRIVER_H_

#include "stm32f446xx.h"
#include <stdint.h>

typedef struct
{
	uint32_t baudRate;
	uint8_t wordLength;
	uint8_t stopBits;
	uint8_t parityControl;
	uint8_t mode;

} usart_config_t;

typedef struct
{
	usart_reg_t *usart;
	usart_config_t config;

} usart_handle_t;


/* Modes */

#define USART_MODE_TX        1
#define USART_MODE_RX        2
#define USART_MODE_TXRX      3

/* Word Length */

#define USART_WORDLEN_8BITS  0
#define USART_WORDLEN_9BITS  1

/* Parity */

#define USART_PARITY_DISABLE 0
#define USART_PARITY_EVEN    1
#define USART_PARITY_ODD     2

/* Stop Bits */

#define USART_STOPBITS_1     0
#define USART_STOPBITS_2     2

/* APIs */

void usart_clock_control(usart_reg_t *usart,uint8_t state);

void usart_init(usart_handle_t *handle);

void usart_send_data(usart_reg_t *usart,uint8_t *buffer,uint32_t len);

void usart_receive_data(usart_reg_t *usart,uint8_t *buffer,uint32_t len);


#endif /* INC_STM32F446XX_USART_DRIVER_H_ */
