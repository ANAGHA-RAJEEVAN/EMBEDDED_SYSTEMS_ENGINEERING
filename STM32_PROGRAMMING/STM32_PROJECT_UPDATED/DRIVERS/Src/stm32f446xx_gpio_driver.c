/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: Mar 24, 2026
 *  Author: anagha
 */

#include <stdint.h>
#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"


/*
 Function: gpio_clock_control
 Purpose : Enable or disable clock for given GPIO port
 Input   : port  -> GPIO port base address
           state -> ENABLE_FLAG or DISABLE_FLAG
 Output  : none
*/
void gpio_clock_control(gpio_reg_t *port, uint8_t state)
{
    if(state == ENABLE_FLAG)
    {
        if(port == GPIO_PORTA)
        	{
        	GPIOA_CLK_ENABLE();
        	}
        else if(port == GPIO_PORTB)
        	{
        	GPIOB_CLK_ENABLE();
        	}
        else if(port == GPIO_PORTC)
        	{
        	GPIOC_CLK_ENABLE();
        	}
        else if(port == GPIO_PORTD)
        	{
        	GPIOD_CLK_ENABLE();
        	}
        else if(port == GPIO_PORTE)
        	{
        	GPIOE_CLK_ENABLE();
        	}
        else if(port == GPIO_PORTF)
        	{
        	GPIOF_CLK_ENABLE();
        	}
        else if(port == GPIO_PORTG)
        	{
        	GPIOG_CLK_ENABLE();
        	}
        else if(port == GPIO_PORTH)
        	{
        	GPIOH_CLK_ENABLE();
        	}
    }
    else
    {
        if(port == GPIO_PORTA)
        	{
        	GPIOA_CLK_DISABLE();
        	}
        else if(port == GPIO_PORTB)
        	{
        	GPIOB_CLK_DISABLE();
        	}
        else if(port == GPIO_PORTC)
        	{
        	GPIOC_CLK_DISABLE();
        	}
        else if(port == GPIO_PORTD)
        	{
        	GPIOD_CLK_DISABLE();
        	}
        else if(port == GPIO_PORTE)
        	{
        	GPIOE_CLK_DISABLE();
        	}
        else if(port == GPIO_PORTF)
        	{
        	GPIOF_CLK_DISABLE();
        	}
        else if(port == GPIO_PORTG)
        	{
        	GPIOG_CLK_DISABLE();
        	}
        else if(port == GPIO_PORTH)
        	{
        	GPIOH_CLK_DISABLE();
        	}
    }
}


/*
 Function: gpio_init
 Purpose : Initialize GPIO pin configuration
 Input   : handle -> pointer to GPIO handle structure
 Output  : none
*/
void gpio_init(gpio_handle_t *handle)
{
    uint32_t temp = 0;

    // Configure mode
    temp = handle->port->MODER;
    temp &= ~(0x3 << (2 * handle->config.pinNumber));
    temp |= (handle->config.pinMode << (2 * handle->config.pinNumber));
    handle->port->MODER = temp;

    // Configure speed
    temp = handle->port->OSPEEDR;
    temp &= ~(0x3 << (2 * handle->config.pinNumber));
    temp |= (handle->config.pinSpeed << (2 * handle->config.pinNumber));
    handle->port->OSPEEDR = temp;

    // Configure pull-up/pull-down
    temp = handle->port->PUPDR;
    temp &= ~(0x3 << (2 * handle->config.pinNumber));
    temp |= (handle->config.pinPull << (2 * handle->config.pinNumber));
    handle->port->PUPDR = temp;

    // Configure output type
    temp = handle->port->OTYPER;
    temp &= ~(0x1 << handle->config.pinNumber);
    temp |= (handle->config.pinType << handle->config.pinNumber);
    handle->port->OTYPER = temp;

    // Configure alternate function
    if(handle->config.pinMode == PIN_MODE_ALTFN)
    {
        uint8_t reg = handle->config.pinNumber / 8;
        uint8_t pos = handle->config.pinNumber % 8;

        handle->port->AFR[reg] &= ~(0xF << (4 * pos));
        handle->port->AFR[reg] |= (handle->config.pinAltFun << (4 * pos));
    }
}


/*
 Function: gpio_deinit
 Purpose : Reset given GPIO port to default state
 Input   : port -> GPIO port base address
 Output  : none
*/
void gpio_deinit(gpio_reg_t *port)
{
    if(port == GPIO_PORTA)
    	{
    	GPIOA_RESET();
    	}
    else if(port == GPIO_PORTB)
    	{
    	GPIOB_RESET();
    	}
    else if(port == GPIO_PORTC)
    	{
    	GPIOC_RESET();
    	}
    else if(port == GPIO_PORTD)
    	{
    	GPIOD_RESET();
    	}
    else if(port == GPIO_PORTE)
    	{
    	GPIOE_RESET();
    	}
    else if(port == GPIO_PORTF)
    	{
    	GPIOF_RESET();
    	}
    else if(port == GPIO_PORTG)
    	{
    	GPIOG_RESET();
    	}
    else if(port == GPIO_PORTH)
    	{
    	GPIOH_RESET();
    	}
}

/*
 Function: gpio_read_pin
 Purpose : Read value from a specific GPIO pin
 Input   : port -> GPIO port base address
           pin  -> pin number
 Output  : returns pin value (0 or 1)
*/
uint8_t gpio_read_pin(gpio_reg_t *port, uint8_t pin)
{
    return (uint8_t)((port->IDR >> pin) & 0x1);
}

/*
 Function: gpio_read_port
 Purpose : Read entire GPIO port value
 Input   : port -> GPIO port base address
 Output  : returns 16-bit port value
*/
uint16_t gpio_read_port(gpio_reg_t *port)
{
    return (uint16_t)(port->IDR);
}

/*
 Function: gpio_write_pin
 Purpose : Write value to a specific GPIO pin
 Input   : port  -> GPIO port base address
           pin   -> pin number
           value -> PIN_SET or PIN_RESET
 Output  : none
*/
void gpio_write_pin(gpio_reg_t *port, uint8_t pin, uint8_t value)
{
    if(value == PIN_SET)
        port->ODR |= (1 << pin);
    else
        port->ODR &= ~(1 << pin);
}

/*
 Function: gpio_write_port
 Purpose : Write value to entire GPIO port
 Input   : port  -> GPIO port base address
           value -> 16-bit value
 Output  : none
*/
void gpio_write_port(gpio_reg_t *port, uint16_t value)
{
    port->ODR = value;
}

/*
 Function: gpio_toggle_pin
 Purpose : Toggle output state of a GPIO pin
 Input   : port -> GPIO port base address
           pin  -> pin number
 Output  : none
*/
void gpio_toggle_pin(gpio_reg_t *port, uint8_t pin)
{
    port->ODR ^= (1 << pin);
}

/*
 Function: gpio_set_pin
 Purpose : Set GPIO pin (logic HIGH)
 Input   : port -> GPIO port base address
           pin  -> pin number
 Output  : none
*/
void gpio_set_pin(gpio_reg_t *port, uint8_t pin)
{
    port->BSRR = (1 << pin);
}

/*
 Function: gpio_clear_pin
 Purpose : Clear GPIO pin (logic LOW)
 Input   : port -> GPIO port base address
           pin  -> pin number
 Output  : none
*/
void gpio_clear_pin(gpio_reg_t *port, uint8_t pin)
{
    port->BSRR = (1 << (pin + 16));
}

/*
 Function: gpio_set_direction
 Purpose : Configure pin direction
 Input   : port -> GPIO port base address
           pin  -> pin number
           mode -> PIN_MODE_INPUT / OUTPUT / etc
 Output  : none
*/
void gpio_set_direction(gpio_reg_t *port, uint8_t pin, uint8_t mode)
{
    port->MODER &= ~(0x3 << (2 * pin));
    port->MODER |= (mode << (2 * pin));
}

/*
 Function: gpio_set_pull
 Purpose : Configure pull-up or pull-down for pin
 Input   : port -> GPIO port base address
           pin  -> pin number
           pull -> NO_PULL / PULL_UP / PULL_DOWN
 Output  : none
*/
void gpio_set_pull(gpio_reg_t *port, uint8_t pin, uint8_t pull)
{
    port->PUPDR &= ~(0x3 << (2 * pin));
    port->PUPDR |= (pull << (2 * pin));
}


/*
 Function: gpio_set_output_type
 Purpose : Configure output type of pin
 Input   : port -> GPIO port base address
           pin  -> pin number
           type -> OUTPUT_PUSH_PULL / OPEN_DRAIN
 Output  : none
*/
void gpio_set_output_type(gpio_reg_t *port, uint8_t pin, uint8_t type)
{
    port->OTYPER &= ~(1 << pin);
    port->OTYPER |= (type << pin);
}


/*
 Function: gpio_set_speed
 Purpose : Configure speed of GPIO pin
 Input   : port  -> GPIO port base address
           pin   -> pin number
           speed -> PIN_SPEED_LOW / MEDIUM / HIGH
 Output  : none
*/
void gpio_set_speed(gpio_reg_t *port, uint8_t pin, uint8_t speed)
{
    port->OSPEEDR &= ~(0x3 << (2 * pin));
    port->OSPEEDR |= (speed << (2 * pin));
}

