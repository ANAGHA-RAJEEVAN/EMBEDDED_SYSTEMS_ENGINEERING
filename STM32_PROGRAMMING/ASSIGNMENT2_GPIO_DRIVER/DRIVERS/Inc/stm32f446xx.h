/*
 * stm32f446xx.h
 *
 *  Created on: Jan 16, 2026
 *      Author: anagha
 */

#include <stdint.h>

#ifndef DRIVERS_INC_STM32F446XX_H_
#define DRIVERS_INC_STM32F446XX_H_

#define __vo volatile

/*--------------------------MEMORY BASE ADDRESS------------------------*/

#define FLASH_BASE_ADDR                      0x08000000U
#define SRAM1_BASE_ADDR                      0x20000000U
#define SRAM2_BASE_ADDR                      0x2001C000U
#define ROM_BASE_ADDR                        0x1FFF0000U
#define SRAM_BASE                            SRAM1_BASE_ADDR

/*---------------- BUS BASE ADDRESSES ----------------*/

#define PERIPH_BASE_ADDR                     0x40000000U
#define APB1_BASE_ADDR                       PERIPH_BASE_ADDR
#define APB2_BASE_ADDR                       0x40010000U
#define AHB1_BASE_ADDR                       0x40020000U
#define AHB2_BASE_ADDR                       0x50000000U
#define AHB3_BASE_ADDR                       0xA0000000U

/*---------------- AHB1 PERIPHERALS ----------------*/

// GPIO

#define GPIOA_BASE_ADDR                      (AHB1_BASE_ADDR + 0x0000)
#define GPIOB_BASE_ADDR                      (AHB1_BASE_ADDR + 0x0400)
#define GPIOC_BASE_ADDR                      (AHB1_BASE_ADDR + 0x0800)
#define GPIOD_BASE_ADDR                      (AHB1_BASE_ADDR + 0x0C00)
#define GPIOE_BASE_ADDR                      (AHB1_BASE_ADDR + 0x1000)
#define GPIOF_BASE_ADDR                      (AHB1_BASE_ADDR + 0x1400)
#define GPIOG_BASE_ADDR                      (AHB1_BASE_ADDR + 0x1800)
#define GPIOH_BASE_ADDR                      (AHB1_BASE_ADDR + 0x1C00)

// OTHER PERIPHERALS

#define CRC_BASE_ADDR                        (AHB1_BASE_ADDR + 0x3000)
#define RCC_BASE_ADDR                        (AHB1_BASE_ADDR + 0x3800)
#define DMA1_BASE_ADDR                       (AHB1_BASE_ADDR + 0x6000)
#define DMA2_BASE_ADDR                       (AHB1_BASE_ADDR + 0x6400)
#define FLASH_IF_BASE_ADDR                   (AHB1_BASE_ADDR + 0x3C00)
#define BKPSRAM_BASE_ADDR                    (AHB1_BASE_ADDR + 0x4000)
#define USB_OTG_HS_BASE_ADDR                 (AHB1_BASE_ADDR + 0x6400)

/*---------------- AHB2 ----------------*/

#define USB_OTG_FS_BASE_ADDR                 (AHB2_BASE_ADDR + 0x0000)
#define DCMI_BASE_ADDR                       (AHB2_BASE_ADDR + 0x50000)

/*---------------- AHB3 ----------------*/

#define FMC_BASE_ADDR                        (AHB3_BASE_ADDR + 0x0000)
#define QUADSPI_BASE_ADDR                    0xA0001000U

/*---------------- APB1 ----------------*/

#define SPI2_BASE_ADDR                       (APB1_BASE_ADDR + 0x3800)
#define SPI3_BASE_ADDR                       (APB1_BASE_ADDR + 0x3C00)

#define I2C1_BASE_ADDR                       (APB1_BASE_ADDR + 0x5400)
#define I2C2_BASE_ADDR                       (APB1_BASE_ADDR + 0x5800)
#define I2C3_BASE_ADDR                       (APB1_BASE_ADDR + 0x5C00)

#define USART2_BASE_ADDR                     (APB1_BASE_ADDR + 0x4400)
#define USART3_BASE_ADDR                     (APB1_BASE_ADDR + 0x4800)
#define UART4_BASE_ADDR                      (APB1_BASE_ADDR + 0x4C00)
#define UART5_BASE_ADDR                      (APB1_BASE_ADDR + 0x5000)

/*---------------- APB2 ----------------*/

#define SPI1_BASE_ADDR                       (APB2_BASE_ADDR + 0x3000)
#define SPI4_BASE_ADDR                       (APB2_BASE_ADDR + 0x3400)

#define ADC1_BASE_ADDR                       (APB2_BASE_ADDR + 0x2000)
#define ADC2_BASE_ADDR                       (APB2_BASE_ADDR + 0x2100)
#define ADC3_BASE_ADDR                       (APB2_BASE_ADDR + 0x2200)
#define ADC_COMMON_BASE_ADDR                 (APB2_BASE_ADDR + 0x2300)


/*------------------------------------REGISTER STRUCTURE-------------------------------*/

/*GPIO REGISTER STRUCTURE*/

typedef struct
{
    __vo uint32_t MODER;    	// GPIO mode register              (0x00)
    __vo uint32_t OTYPER;   	// Output type register       	   (0x04)
    __vo uint32_t OSPEEDR;  	// Output speed register           (0x08)
    __vo uint32_t PUPDR;    	// Pull-up / Pull-down register    (0x0C)
    __vo uint32_t IDR;      	// input data register        	   (0x10)
    __vo uint32_t ODR;      	// output data register       	   (0x14)
    __vo uint32_t BSRR;     	// bit set/reset register          (0x18)
    __vo uint32_t LCKR;     	// lock register                   (0x1C)
    __vo uint32_t AFR[2];   	//AFR[0]:  alternate function low register (0x20)
    							//AFR[1]:  alternate function high register(0x24)
} gpio_reg_t;

/*RCC REGISTER STRUCTURE*/

typedef struct
{
	__vo uint32_t CR;            // clock control register                    (0x00)
    __vo uint32_t PLLCFGR;       // PLL configuration register                (0x04)
    __vo uint32_t CFGR;          // clock configuration register              (0x08)
    __vo uint32_t CIR;           // clock interrupt register                  (0x0C)
    __vo uint32_t AHB1RSTR;      // AHB1 peripheral reset register            (0x10)
    __vo uint32_t AHB2RSTR;      // AHB2 peripheral reset register            (0x14)
    __vo uint32_t AHB3RSTR;      // AHB3 peripheral reset register            (0x18)
    __vo uint32_t RESERVED0;     // Reserved                                      (0x1C)
	__vo uint32_t APB1RSTR;      // APB1 peripheral reset register            (0x20)
	__vo uint32_t APB2RSTR;      // APB2 peripheral reset register            (0x24)
	__vo uint32_t RESERVED1[2];  // Reserved                                      (0x28-0x2C)
	__vo uint32_t AHB1ENR;       // AHB1 peripheral clock enable register     (0x30)
	__vo uint32_t AHB2ENR;       // AHB2 peripheral clock enable register     (0x34)
	__vo uint32_t AHB3ENR;       // AHB3 peripheral clock enable register     (0x38)
	__vo uint32_t RESERVED2;     // Reserved                                      (0x3C)
	__vo uint32_t APB1ENR;       // APB1 peripheral clock enable register     (0x40)
	__vo uint32_t APB2ENR;       // APB2 peripheral clock enable register     (0x44)
	__vo uint32_t RESERVED3[2];  // Reserved                                      (0x48-0x4C)
	__vo uint32_t AHB1LPENR;     // AHB1 peripheral clock enable in low power (0x50)
	__vo uint32_t AHB2LPENR;     // AHB2 peripheral clock enable in low power (0x54)
	__vo uint32_t AHB3LPENR;     // AHB3 peripheral clock enable in low power (0x58)
	__vo uint32_t RESERVED4;     // Reserved                                      (0x5C)
	__vo uint32_t APB1LPENR;     // APB1 peripheral clock enable in low power (0x60)
	__vo uint32_t APB2LPENR;     // APB2 peripheral clock enable in low power (0x64)
	__vo uint32_t RESERVED5[2];  // Reserved                                      (0x68-0x6C)
	__vo uint32_t BDCR;          // Backup domain control register            (0x70)
	__vo uint32_t CSR;           // clock control & status register           (0x74)
	__vo uint32_t RESERVED6[2];  // Reserved                                      (0x78-0x7C)
	__vo uint32_t SSCGR;         // spread spectrum clock generation register (0x80)
	__vo uint32_t PLLI2SCFGR;    // PLLI2S configuration register             (0x84)
	__vo uint32_t PLLSAICFGR;    // PLLSAI configuration register             (0x88)
	__vo uint32_t DCKCFGR;       // Dedicated Clocks configuration register   (0x8C)
	__vo uint32_t CKGATENR;      // clocks gated enable register              (0x90)
	__vo uint32_t DCKCFGR2;      // Dedicated Clocks configuration register 2 (0x94)
} rcc_reg_t;


/*SPI REGISTER STRUCTURE*/

typedef struct
{
    __vo uint32_t CR1;       // Control register 1     (0x00)
    __vo uint32_t CR2;       // Control register 2     (0x04)
    __vo uint32_t SR;        // Status register        (0x08)
    __vo uint32_t DR;        // Data register          (0x0C)
    __vo uint32_t CRCPR;     // CRC polynomial         (0x10)
    __vo uint32_t RXCRCR;    // RX CRC register        (0x14)
    __vo uint32_t TXCRCR;    // TX CRC register        (0x18)
    __vo uint32_t I2SCFGR;   // I2S config register    (0x1C)
    __vo uint32_t I2SPR;     // I2S prescaler          (0x20)
} spi_reg_t;

/*I2C REGISTER STRUCTURE*/

typedef struct
{
    __vo uint32_t CR1;       // Control register 1        (0x00)
    __vo uint32_t CR2;       // Control register 2        (0x04)
    __vo uint32_t OAR1;      // Own address register 1    (0x08)
    __vo uint32_t OAR2;      // Own address register 2    (0x0C)
    __vo uint32_t DR;        // Data register             (0x10)
    __vo uint32_t SR1;       // Status register 1         (0x14)
    __vo uint32_t SR2;       // Status register 2         (0x18)
    __vo uint32_t CCR;       // Clock control register    (0x1C)
    __vo uint32_t TRISE;     // TRISE register            (0x20)
    __vo uint32_t FLTR;      // Filter register           (0x24)
} i2c_reg_t;

/*ADC REGISTER STRUCTURE*/
typedef struct
{
    __vo uint32_t SR;         // Status register                (0x00)
    __vo uint32_t CR1;        // Control register 1             (0x04)
    __vo uint32_t CR2;        // Control register 2             (0x08)
    __vo uint32_t SMPR1;      // Sample time register 1         (0x0C)
    __vo uint32_t SMPR2;      // Sample time register 2         (0x10)
    __vo uint32_t JOFR1;      // Injected offset 1              (0x14)
    __vo uint32_t JOFR2;      // Injected offset 2              (0x18)
    __vo uint32_t JOFR3;      // Injected offset 3              (0x1C)
    __vo uint32_t JOFR4;      // Injected offset 4              (0x20)
    __vo uint32_t HTR;        // Analog watchdog high threshold (0x24)
    __vo uint32_t LTR;        // Analog watchdog low threshold  (0x28)
    __vo uint32_t SQR1;       // Regular sequence register 1    (0x2C)
    __vo uint32_t SQR2;       // Regular sequence register 2    (0x30)
    __vo uint32_t SQR3;       // Regular sequence register 3    (0x34)
    __vo uint32_t JSQR;       // Injected sequence register     (0x38)
    __vo uint32_t JDR1;       // Injected data register 1       (0x3C)
    __vo uint32_t JDR2;       // Injected data register 2       (0x40)
    __vo uint32_t JDR3;       // Injected data register 3       (0x44)
    __vo uint32_t JDR4;       // Injected data register 4       (0x48)
    __vo uint32_t DR;         // Regular data register          (0x4C)
} adc_reg_t;

/* ADC COMMON REGISTER STRUCTURE */
typedef struct
{
    __vo uint32_t CSR;        // Common status register         (0x00)
    __vo uint32_t CCR;        // Common control register        (0x04)
    __vo uint32_t CDR;        // Common data register           (0x08)
} adc_common_reg_t;
/*--------------------------------------POINTERS------------------------------*/

/*GPIO POINTERS*/

#define GPIO_PORTA   ((gpio_reg_t*)GPIOA_BASE_ADDR)
#define GPIO_PORTB   ((gpio_reg_t*)GPIOB_BASE_ADDR)
#define GPIO_PORTC   ((gpio_reg_t*)GPIOC_BASE_ADDR)
#define GPIO_PORTD   ((gpio_reg_t*)GPIOD_BASE_ADDR)
#define GPIO_PORTE   ((gpio_reg_t*)GPIOE_BASE_ADDR)
#define GPIO_PORTF   ((gpio_reg_t*)GPIOF_BASE_ADDR)
#define GPIO_PORTG   ((gpio_reg_t*)GPIOG_BASE_ADDR)
#define GPIO_PORTH   ((gpio_reg_t*)GPIOH_BASE_ADDR)

/*RCC POINTERS*/

#define RCC_CTRL   ((rcc_reg_t*)RCC_BASE_ADDR)

/*SPI POINTERS*/

#define SPI1    ((spi_reg_t*)SPI1_BASE_ADDR)
#define SPI2    ((spi_reg_t*)SPI2_BASE_ADDR)
#define SPI3    ((spi_reg_t*)SPI3_BASE_ADDR)
#define SPI4    ((spi_reg_t*)SPI4_BASE_ADDR)

/*I2C POINTERS*/

#define I2C1   ((i2c_reg_t*)I2C1_BASE_ADDR)
#define I2C2   ((i2c_reg_t*)I2C2_BASE_ADDR)
#define I2C3   ((i2c_reg_t*)I2C3_BASE_ADDR)

/*ADC POINTERS*/
#define ADC1   		 ((adc_reg_t*)ADC1_BASE_ADDR)
#define ADC2   		 ((adc_reg_t*)ADC2_BASE_ADDR)
#define ADC3   		 ((adc_reg_t*)ADC3_BASE_ADDR)
#define ADC_COMMON   ((adc_common_reg_t*)ADC_COMMON_BASE_ADDR)

/**********************************Clock Enable Macros **********************************/

// Clock Enable Macros for GPIOx peripherals
#define GPIOA_CLK_ENABLE()                     (RCC_CTRL->AHB1ENR |= (1 << 0))
#define GPIOB_CLK_ENABLE()                     (RCC_CTRL->AHB1ENR |= (1 << 1))
#define GPIOC_CLK_ENABLE()                     (RCC_CTRL->AHB1ENR |= (1 << 2))
#define GPIOD_CLK_ENABLE()                     (RCC_CTRL->AHB1ENR |= (1 << 3))
#define GPIOE_CLK_ENABLE()                     (RCC_CTRL->AHB1ENR |= (1 << 4))
#define GPIOF_CLK_ENABLE()                     (RCC_CTRL->AHB1ENR |= (1 << 5))
#define GPIOG_CLK_ENABLE()                     (RCC_CTRL->AHB1ENR |= (1 << 6))
#define GPIOH_CLK_ENABLE()                     (RCC_CTRL->AHB1ENR |= (1 << 7))

// Clock Enable Macros for I2Cx peripherals
#define I2C1_CLK_ENABLE()                      (RCC_CTRL->APB1ENR |= (1 << 21))
#define I2C2_CLK_ENABLE()                      (RCC_CTRL->APB1ENR |= (1 << 22))
#define I2C3_CLK_ENABLE()                      (RCC_CTRL->APB1ENR |= (1 << 23))
#define FMPI2C1_CLK_ENABLE()                   (RCC_CTRL->APB1ENR |= (1 << 24))

// Clock Enable Macros for SPIx peripherals
#define SPI1_CLK_ENABLE()                      (RCC_CTRL->APB2ENR |= (1 << 12))
#define SPI2_CLK_ENABLE()                      (RCC_CTRL->APB1ENR |= (1 << 14))
#define SPI3_CLK_ENABLE()                      (RCC_CTRL->APB1ENR |= (1 << 15))
#define SPI4_CLK_ENABLE()                      (RCC_CTRL->APB2ENR |= (1 << 13))

// Clock Enable Macros for USARTx peripherals
#define USART1_CLK_ENABLE()                    (RCC_CTRL->APB2ENR |= (1 << 4))
#define USART2_CLK_ENABLE()                    (RCC_CTRL->APB1ENR |= (1 << 17))
#define USART3_CLK_ENABLE()                    (RCC_CTRL->APB1ENR |= (1 << 18))
#define UART4_CLK_ENABLE()                     (RCC_CTRL->APB1ENR |= (1 << 19))
#define UART5_CLK_ENABLE()                     (RCC_CTRL->APB1ENR |= (1 << 20))
#define USART6_CLK_ENABLE()                    (RCC_CTRL->APB2ENR |= (1 << 5))

// Clock Enable Macros for SYSCFG peripheral
#define SYSCFG_CLK_ENABLE()                   (RCC_CTRL->APB2ENR |= (1 << 14))

// Clock Enable Macros for CRC peripheral
#define CRC_CLK_ENABLE()                      (RCC_CTRL->AHB1ENR |= (1 << 12))

// Clock Enable Macros for DMA peripherals
#define DMA1_CLK_ENABLE()                     (RCC_CTRL->AHB1ENR |= (1 << 21))
#define DMA2_CLK_ENABLE()                     (RCC_CTRL->AHB1ENR |= (1 << 22))

// Clock Enable Macros for ADC (APB2 BUS)
#define ADC1_CLK_ENABLE()                     (RCC_CTRL->APB2ENR |= (1 << 8))
#define ADC2_CLK_ENABLE()                     (RCC_CTRL->APB2ENR |= (1 << 9))
#define ADC3_CLK_ENABLE()                     (RCC_CTRL->APB2ENR |= (1 << 10))

/**********************************Clock Disable Macros **********************************/

// Clock Disable Macros for GPIOx peripherals
#define GPIOA_CLK_DISABLE()                   (RCC_CTRL->AHB1ENR &= ~(1 << 0))
#define GPIOB_CLK_DISABLE()                   (RCC_CTRL->AHB1ENR &= ~(1 << 1))
#define GPIOC_CLK_DISABLE()                   (RCC_CTRL->AHB1ENR &= ~(1 << 2))
#define GPIOD_CLK_DISABLE()                   (RCC_CTRL->AHB1ENR &= ~(1 << 3))
#define GPIOE_CLK_DISABLE()                   (RCC_CTRL->AHB1ENR &= ~(1 << 4))
#define GPIOF_CLK_DISABLE()                   (RCC_CTRL->AHB1ENR &= ~(1 << 5))
#define GPIOG_CLK_DISABLE()                   (RCC_CTRL->AHB1ENR &= ~(1 << 6))
#define GPIOH_CLK_DISABLE()                   (RCC_CTRL->AHB1ENR &= ~(1 << 7))

// Clock Disable Macros for SPIx peripherals
#define SPI1_CLK_DISABLE()                    (RCC_CTRL->APB2ENR &= ~(1 << 12))
#define SPI2_CLK_DISABLE()                    (RCC_CTRL->APB1ENR &= ~(1 << 14))
#define SPI3_CLK_DISABLE()                    (RCC_CTRL->APB1ENR &= ~(1 << 15))
#define SPI4_CLK_DISABLE()                    (RCC_CTRL->APB2ENR &= ~(1 << 13))

// Clock Disable Macros for I2Cx peripherals
#define I2C1_CLK_DISABLE()                    (RCC_CTRL->APB1ENR &= ~(1 << 21))
#define I2C2_CLK_DISABLE()                    (RCC_CTRL->APB1ENR &= ~(1 << 22))
#define I2C3_CLK_DISABLE()                    (RCC_CTRL->APB1ENR &= ~(1 << 23))
#define FMPI2C1_CLK_DISABLE()                 (RCC_CTRL->APB1ENR &= ~(1 << 24))

// Clock Disable Macros for USARTx peripherals
#define USART1_CLK_DISABLE()                  (RCC_CTRL->APB2ENR &= ~(1 << 4))
#define USART2_CLK_DISABLE()                  (RCC_CTRL->APB1ENR &= ~(1 << 17))
#define USART3_CLK_DISABLE()                  (RCC_CTRL->APB1ENR &= ~(1 << 18))
#define UART4_CLK_DISABLE()                   (RCC_CTRL->APB1ENR &= ~(1 << 19))
#define UART5_CLK_DISABLE()                   (RCC_CTRL->APB1ENR &= ~(1 << 20))
#define USART6_CLK_DISABLE()                  (RCC_CTRL->APB2ENR &= ~(1 << 5))

// Clock Disable Macros for SYSCFG peripheral
#define SYSCFG_CLK_DISABLE()                  (RCC_CTRL->APB2ENR &= ~(1 << 14))

// Macros to reset GPIOx peripherals
#define GPIOA_RESET()   do{ (RCC_CTRL->AHB1RSTR |= (1 << 0)); (RCC_CTRL->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_RESET()   do{ (RCC_CTRL->AHB1RSTR |= (1 << 1)); (RCC_CTRL->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_RESET()   do{ (RCC_CTRL->AHB1RSTR |= (1 << 2)); (RCC_CTRL->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_RESET()   do{ (RCC_CTRL->AHB1RSTR |= (1 << 3)); (RCC_CTRL->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_RESET()   do{ (RCC_CTRL->AHB1RSTR |= (1 << 4)); (RCC_CTRL->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_RESET()   do{ (RCC_CTRL->AHB1RSTR |= (1 << 5)); (RCC_CTRL->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_RESET()   do{ (RCC_CTRL->AHB1RSTR |= (1 << 6)); (RCC_CTRL->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_RESET()   do{ (RCC_CTRL->AHB1RSTR |= (1 << 7)); (RCC_CTRL->AHB1RSTR &= ~(1 << 7)); }while(0)

#endif /* DRIVERS_INC_STM32F446XX_H_ */
