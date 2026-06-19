/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: Mar 24, 2026
 *  Author: anagha
 */

#include <stddef.h>
#include <stdint.h>
#include "stm32f446xx.h"

#ifndef DRIVERS_INC_STM32F446XX_GPIO_DRIVER_H_
#define DRIVERS_INC_STM32F446XX_GPIO_DRIVER_H_

// Configuration structure for a GPIO pin
typedef struct
{
    uint8_t pinNumber;        // Pin number
    uint8_t pinMode;          // Mode: Input/Output/AltFn/Analog
    uint8_t pinSpeed;         // Speed: Low/Medium/High
    uint8_t pinPull;          // Pull-up/Pull-down configuration
    uint8_t pinType;          // Output type: Push-Pull/Open-Drain
    uint8_t pinAltFun;        // Alternate function
} gpio_pin_config_t;

// Handle structure for a GPIO pin
typedef struct
{
    gpio_reg_t *port;              // Base address of GPIO port
    gpio_pin_config_t config;      // GPIO configuration settings
} gpio_handle_t;


// Pin numbers
#define PIN_0        0
#define PIN_1        1
#define PIN_2        2
#define PIN_3        3
#define PIN_4        4
#define PIN_5        5
#define PIN_6        6
#define PIN_7        7
#define PIN_8        8
#define PIN_9        9
#define PIN_10       10
#define PIN_11       11
#define PIN_12       12
#define PIN_13       13
#define PIN_14       14
#define PIN_15       15


// Pin modes
#define PIN_MODE_INPUT        0
#define PIN_MODE_OUTPUT       1
#define PIN_MODE_ALTFN        2
#define PIN_MODE_ANALOG       3

// Output types
#define OUTPUT_PUSH_PULL      0
#define OUTPUT_OPEN_DRAIN     1

// Output speed
#define PIN_SPEED_LOW         0
#define PIN_SPEED_MEDIUM      1
#define PIN_SPEED_FAST        2
#define PIN_SPEED_HIGH        3

// Pull configuration
#define NO_PULL               0
#define PULL_UP               1
#define PULL_DOWN             2


// Generic Macros
#define ENABLE_FLAG           1
#define DISABLE_FLAG          0

#define SET_BIT               ENABLE_FLAG
#define CLEAR_BIT             DISABLE_FLAG

#define PIN_SET               1
#define PIN_RESET             0

#define FLAG_CLEAR            CLEAR_BIT
#define FLAG_ACTIVE           SET_BIT


// Clock control
void gpio_clock_control(gpio_reg_t *port, uint8_t state);

// Initialize & De-initialize
void gpio_init(gpio_handle_t *handle);
void gpio_deinit(gpio_reg_t *port);

// Input read
uint8_t gpio_read_pin(gpio_reg_t *port, uint8_t pin);
uint16_t gpio_read_port(gpio_reg_t *port);

// Output write
void gpio_write_pin(gpio_reg_t *port, uint8_t pin, uint8_t value);
void gpio_write_port(gpio_reg_t *port, uint16_t value);

// Toggle
void gpio_toggle_pin(gpio_reg_t *port, uint8_t pin);

// Set pin
void gpio_set_pin(gpio_reg_t *port, uint8_t pin);

// Clear pin (reset)
void gpio_clear_pin(gpio_reg_t *port, uint8_t pin);

// Configure pin direction
void gpio_set_direction(gpio_reg_t *port, uint8_t pin, uint8_t mode);

// Configure pull-up / pull-down
void gpio_set_pull(gpio_reg_t *port, uint8_t pin, uint8_t pull);

// Configure output type (PP / OD)
void gpio_set_output_type(gpio_reg_t *port, uint8_t pin, uint8_t type);

// Configure speed
void gpio_set_speed(gpio_reg_t *port, uint8_t pin, uint8_t speed);

// Read entire port status
uint16_t gpio_get_port_state(gpio_reg_t *port);

// Write multiple pins using mask
void gpio_write_mask(gpio_reg_t *port, uint16_t mask, uint16_t value);


#endif /* DRIVERS_INC_STM32F446XX_GPIO_DRIVER_H_ */
