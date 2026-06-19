/*
 * stm32f446xx_i2c_driver.h
 *
 *  Created on: 2026
 *      Author: anagh
 */

#ifndef INC_STM32F446XX_I2C_DRIVER_H_
#define INC_STM32F446XX_I2C_DRIVER_H_

#include <stdint.h>
#include "stm32f446xx.h"

/* ACK Control */

#define I2C_ACK_ENABLE      1
#define I2C_ACK_DISABLE     0

/* SCL Speed */

#define I2C_SCL_SPEED_SM    100000
#define I2C_SCL_SPEED_FM    400000

typedef struct
{
	uint32_t sclSpeed;
	uint8_t deviceAddress;
	uint8_t ackControl;

} i2c_config_t;

typedef struct
{
	i2c_reg_t *i2c;
	i2c_config_t config;

} i2c_handle_t;


/* APIs */

void i2c_clock_control(i2c_reg_t *i2c,uint8_t state);

void i2c_init(i2c_handle_t *handle);

void i2c_generate_start(i2c_reg_t *i2c);

void i2c_generate_stop(i2c_reg_t *i2c);

void i2c_master_send_data(i2c_handle_t *handle,uint8_t *buffer,uint32_t len,uint8_t slaveAddress);

void i2c_master_receive_data(i2c_handle_t *handle, uint8_t *buffer,uint32_t len,uint8_t slaveAddress);

#endif /* INC_STM32F446XX_I2C_DRIVER_H_ */
