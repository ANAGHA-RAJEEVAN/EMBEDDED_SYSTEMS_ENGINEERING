/*
 * stm32f446xx_spi_driver.h
 *
 *  Created on: 2026
 *      Author: anagh
 */

#ifndef INC_STM32F446XX_SPI_DRIVER_H_
#define INC_STM32F446XX_SPI_DRIVER_H_

#include <stdint.h>
#include "stm32f446xx.h"

/* SPI Device Mode */

#define SPI_DEVICE_MODE_SLAVE     0
#define SPI_DEVICE_MODE_MASTER    1

/* SPI Bus Configuration */

#define SPI_BUS_FULL_DUPLEX       1
#define SPI_BUS_HALF_DUPLEX       2
#define SPI_BUS_SIMPLEX_RXONLY    3

/* SPI Clock Speed */

#define SPI_SCLK_DIV2             0
#define SPI_SCLK_DIV4             1
#define SPI_SCLK_DIV8             2
#define SPI_SCLK_DIV16            3
#define SPI_SCLK_DIV32            4
#define SPI_SCLK_DIV64            5
#define SPI_SCLK_DIV128           6
#define SPI_SCLK_DIV256           7

/* Data Frame Format */

#define SPI_DFF_8BITS             0
#define SPI_DFF_16BITS            1

/* Clock Polarity */

#define SPI_CPOL_LOW              0
#define SPI_CPOL_HIGH             1

/* Clock Phase */

#define SPI_CPHA_LOW              0
#define SPI_CPHA_HIGH             1

/* Software Slave Management */

#define SPI_SSM_DISABLE           0
#define SPI_SSM_ENABLE            1

typedef struct
{
	uint8_t deviceMode;
	uint8_t busConfig;
	uint8_t sclkSpeed;
	uint8_t dff;
	uint8_t cpol;
	uint8_t cpha;
	uint8_t ssm;

} spi_config_t;

typedef struct
{
	spi_reg_t *spi;
	spi_config_t config;

} spi_handle_t;


/* APIs */

void spi_clock_control(spi_reg_t *spi,uint8_t state);

void spi_init(spi_handle_t *handle);

void spi_send_data(spi_reg_t *spi,uint8_t *buffer,uint32_t len);

void spi_receive_data(spi_reg_t *spi,uint8_t *buffer,uint32_t len);

void spi_peripheral_control(spi_reg_t *spi,uint8_t state);

#endif /* INC_STM32F446XX_SPI_DRIVER_H_ */
