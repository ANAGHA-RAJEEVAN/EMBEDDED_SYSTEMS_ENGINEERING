# STM32F446RE Peripheral Driver Development

## Overview

This project implements a custom bare-metal peripheral driver library for the STM32F446RE microcontroller without using the STM32 HAL library. The objective is to understand low-level peripheral programming by directly accessing hardware registers and building reusable driver APIs for common communication and I/O peripherals.

The project includes driver development, application examples, and testing for the following peripherals:

* GPIO (General Purpose Input Output)
* USART (Universal Synchronous/Asynchronous Receiver Transmitter)
* SPI (Serial Peripheral Interface)
* I2C (Inter-Integrated Circuit)

The drivers are designed using a modular architecture with configuration structures, handle structures, register-level programming, and reusable APIs.

---

## Project Structure

```text
STM32_PROJECT_UPDATED/
│
├── DRIVERS/
│   ├── Inc/
│   │   ├── stm32f446xx.h
│   │   ├── stm32f446xx_gpio_driver.h
│   │   ├── stm32f446xx_usart_driver.h
│   │   ├── stm32f446xx_spi_driver.h
│   │   └── stm32f446xx_i2c_driver.h
│   │
│   └── Src/
│       ├── stm32f446xx_gpio_driver.c
│       ├── stm32f446xx_usart_driver.c
│       ├── stm32f446xx_spi_driver.c
│       └── stm32f446xx_i2c_driver.c
│
├── Src/
│   ├── gpio_main.c
│   ├── usart_main.c
│   ├── spi_main.c
│   └── i2c_main.c
│
└── Documentation/
    ├── GPIO_Driver_Analysis.pdf
    ├── USART_Driver_Analysis.pdf
    ├── SPI_Driver_Analysis.pdf
    └── I2C_Driver_Analysis.pdf
```

---

## GPIO Driver

The GPIO driver provides APIs for configuring and controlling GPIO pins.

### Features

* GPIO clock enable/disable
* Input mode configuration
* Output mode configuration
* Alternate function configuration
* Pull-up/Pull-down support
* Pin read and write operations
* Pin toggle functionality

### Example Application

* Push button connected to PC13
* LED connected to PA5
* LED toggles when button is pressed
* Alternate LED blinking using PA6 and PA7

---

## USART Driver

The USART driver provides serial communication capabilities between the STM32F446RE and external devices.

### Features

* Peripheral initialization
* Baud rate configuration
* Data transmission
* Data reception
* Clock control

### Example Application

* UART Echo Program
* Characters received from the terminal are transmitted back to the sender

---

## SPI Driver

The SPI driver provides synchronous communication support for external devices such as sensors and displays.

### Features

* Master mode configuration
* Clock polarity and phase configuration
* Data transmission
* Data reception
* Peripheral enable/disable control

### Example Application

* SPI1 configured as Master
* Transmission of the string:

```text
HELLO STM32
```

---

## I2C Driver

The I2C driver provides communication with external peripherals using the I2C protocol.

### Features

* Clock configuration
* START and STOP generation
* Master transmit
* Master receive
* Address handling

### Example Application

* LM75 Temperature Sensor Interface
* Temperature data acquisition through I2C1

---

## Learning Outcomes

Through this project, the following concepts were explored:

* Register-level peripheral programming
* Peripheral clock management
* GPIO configuration and control
* Serial communication using USART
* Synchronous communication using SPI
* Sensor interfacing using I2C
* Driver abstraction and modular software design
* Embedded system debugging and testing

---

## Development Environment

* STM32F446RE
* STM32CubeIDE
* ARM GCC Toolchain
* Bare-Metal Embedded C
* Git & GitHub

---

## Author

**Anagha**

Embedded Software Project – STM32 Peripheral Driver Development
