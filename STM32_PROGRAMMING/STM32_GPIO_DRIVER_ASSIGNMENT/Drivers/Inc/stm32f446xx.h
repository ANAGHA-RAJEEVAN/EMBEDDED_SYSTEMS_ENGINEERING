/*
 * STM32F446xx.h
 *
 *  Created on: Jan 16, 2026
 *      Author: anagha
 */
#include <stdint.h>

#ifndef DRIVERS_INC_STM32F446XX_H_
#define DRIVERS_INC_STM32F446XX_H_

#define __vol                            volatile

/*--------------------------MEMORY BASE ADDRESS------------------------*/

#define FLASH_BASEADDR                      0x08000000U     /* Flash memory base address */
#define SRAM1_BASEADDR                      0x20000000U     /* SRAM1 base address (112KB) */
#define SRAM2_BASEADDR                      0x2001C000U     /* SRAM2 base address (16KB) */
#define ROM_BASEADDR                        0x1FFF0000U     /* System memory (ROM) base address */
#define SRAM                                SRAM1_BASEADDR

/*AHBx and APBx Bus Peripheral base addresses */

#define PERIPH_BASEADDR                     0x40000000U
#define APB1PERIPH_BASEADDR                 PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR                 0x40010000U
#define AHB1PERIPH_BASEADDR                 0x40020000U
#define AHB2PERIPH_BASEADDR                 0x50000000U
#define AHB3PERIPH_BASEADDR                 0xA0000000U

/*-------------------------------------PERIPHERALS IN AHB1 BUS------------------------------------*/

/*GPIO BASE ADDRESSES (AHB1 BUS)*/

#define GPIOA_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR                      (AHB1PERIPH_BASEADDR + 0x1C00)

/*CRC BASE ADDRESS*/
#define CRC_BASEADDR						(AHB1PERIPH_BASEADDR + 0x3000)
/*RCC BASE ADDRESS*/
#define RCC_BASEADDR						(AHB1PERIPH_BASEADDR + 0x3800)
/*DMA1 BASE ADDRESS*/
#define DMA1_BASEADDR						(AHB1PERIPH_BASEADDR + 0x6000)
/*DMA2 BASE ADDRESS*/
#define DMA2_BASEADDR						(AHB1PERIPH_BASEADDR + 0x6400)
/*FLASH INTERFACE BASE ADDRESS*/
#define FLASH_INTERFACE_BASEADDR			(AHB1PERIPH_BASEADDR + 0x3C00)
/*BKPSRAM BASE ADDRESS*/
#define BKPSRAM_BASEADDR					(AHB1PERIPH_BASEADDR + 0x4000)
/*USB OTG HS BASE ADDRESS*/
#define USB_OTG_HS_BASEADDR					(AHB1PERIPH_BASEADDR + 0x6400)

/*-------------------------------------PERIPHERALS IN AHB2 BUS------------------------------------*/

/*USB OTG FS BASE ADDRESS*/
#define USB_OTG_FS_BASEADDR                 (AHB2PERIPH_BASEADDR + 0x0000)
/*DCMI BASE ADDRESS*/
#define DCMI_BASEADDR                       (AHB2PERIPH_BASEADDR + 0x50000)

/*-------------------------------------PERIPHERALS IN AHB3 BUS------------------------------------*/

/*FMC BASE ADDRESS*/
#define FMC_BASEADDR                        (AHB3PERIPH_BASEADDR + 0x0000)
/*QUADSPI BASE ADDRESS*/
#define QUADSPI_BASEADDR                    0xA0001000U

/*-------------------------------------PERIPHERALS IN APB1 BUS------------------------------------*/


/*SPI BASE ADDRESSES (APB1/APB2 BUS)*/

#define SPI2_BASEADDR                       (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR                       (APB1PERIPH_BASEADDR + 0x3C00)
#define SPDIFRX_BASEADDR                    (APB1PERIPH_BASEADDR + 0x4000)

/*I2C BASE ADDRESSES (APB1 BUS)*/

#define I2C1_BASEADDR                       (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR                       (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR                       (APB1PERIPH_BASEADDR + 0x5C00)
#define FMPI2C1_BASEADDR                    (APB1PERIPH_BASEADDR + 0x6000)

/*USART/UART BASE ADDRESS(APB1 BUS)*/

#define USART2_BASEADDR                     (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR                     (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR                      (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR                      (APB1PERIPH_BASEADDR + 0x5000)

/*TIMER BASE ADDRESS(APB1 BUS)*/

#define TIM2_BASEADDR                       (APB1PERIPH_BASEADDR + 0x0000)
#define TIM3_BASEADDR                       (APB1PERIPH_BASEADDR + 0x0400)
#define TIM4_BASEADDR                       (APB1PERIPH_BASEADDR + 0x0800)
#define TIM5_BASEADDR                       (APB1PERIPH_BASEADDR + 0x0C00)
#define TIM6_BASEADDR                       (APB1PERIPH_BASEADDR + 0x1000)
#define TIM7_BASEADDR                       (APB1PERIPH_BASEADDR + 0x1400)
#define TIM12_BASEADDR                      (APB1PERIPH_BASEADDR + 0x1800)
#define TIM13_BASEADDR                      (APB1PERIPH_BASEADDR + 0x1C00)
#define TIM14_BASEADDR                      (APB1PERIPH_BASEADDR + 0x2000)

/*-------------------------------------PERIPHERALS IN APB2 BUS------------------------------------*/

/*SPI BASE ADDRESSES (APB1/APB2 BUS)*/

#define SPI1_BASEADDR                       (APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR                       (APB2PERIPH_BASEADDR + 0x3400)

/*ADC BASE ADDRESS (APB2 BUS)*/
#define ADC1_BASEADDR   					(APB2PERIPH_BASEADDR + 0x2000)
#define ADC2_BASEADDR   					(APB2PERIPH_BASEADDR + 0x2100)
#define ADC3_BASEADDR   					(APB2PERIPH_BASEADDR + 0x2200)
#define ADC_COMMON_BASEADDR  				(APB2PERIPH_BASEADDR + 0x2300)// Common registers

/*TIMER BASE ADDRESS(APB2 BUS)*/

#define TIM1_BASEADDR                       (APB2PERIPH_BASEADDR + 0x0000)
#define TIM8_BASEADDR                       (APB2PERIPH_BASEADDR + 0x0400)
#define TIM9_BASEADDR                       (APB2PERIPH_BASEADDR + 0x4000)
#define TIM10_BASEADDR                      (APB2PERIPH_BASEADDR + 0x4400)
#define TIM11_BASEADDR                      (APB2PERIPH_BASEADDR + 0x4800)

/*USART BASE ADDRESS(APB2 BUS)*/

#define USART1_BASEADDR                     (APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR                     (APB2PERIPH_BASEADDR + 0x1400)

/*------------------------------------REGISTER STRUCTURE-------------------------------*/

/*GPIO REGISTER STRUCTURE FOR STM32F446 series*/

typedef struct
{
    __vol uint32_t MODER;    // GPIO port mode register              (0x00)
    __vol uint32_t OTYPER;   // GPIO port output type register       (0x04)
    __vol uint32_t OSPEEDR;  // GPIO port output speed register      (0x08)
    __vol uint32_t PUPDR;    // GPIO port pull-up/pull-down register (0x0C)
    __vol uint32_t IDR;      // GPIO port input data register        (0x10)
    __vol uint32_t ODR;      // GPIO port output data register       (0x14)
    __vol uint32_t BSRR;     // GPIO port bit set/reset register     (0x18)
    __vol uint32_t LCKR;     // GPIO port configuration lock register(0x1C)
    __vol uint32_t AFR[2];   //AFR[0]: GPIO alternate function low register (0x20)
    						 //AFR[1]: GPIO alternate function high register(0x24)
} GPIO_RegDef_t;

/*RCC REGISTER STRUCTURE FOR STM32F446 series*/

typedef struct
{
	__vol uint32_t CR;            // RCC clock control register                    (0x00)
    __vol uint32_t PLLCFGR;       // RCC PLL configuration register                (0x04)
    __vol uint32_t CFGR;          // RCC clock configuration register              (0x08)
    __vol uint32_t CIR;           // RCC clock interrupt register                  (0x0C)
    __vol uint32_t AHB1RSTR;      // RCC AHB1 peripheral reset register            (0x10)
    __vol uint32_t AHB2RSTR;      // RCC AHB2 peripheral reset register            (0x14)
    __vol uint32_t AHB3RSTR;      // RCC AHB3 peripheral reset register            (0x18)
    __vol uint32_t RESERVED0;     // Reserved                                      (0x1C)
	__vol uint32_t APB1RSTR;      // RCC APB1 peripheral reset register            (0x20)
	__vol uint32_t APB2RSTR;      // RCC APB2 peripheral reset register            (0x24)
	__vol uint32_t RESERVED1[2];  // Reserved                                      (0x28-0x2C)
	__vol uint32_t AHB1ENR;       // RCC AHB1 peripheral clock enable register     (0x30)
	__vol uint32_t AHB2ENR;       // RCC AHB2 peripheral clock enable register     (0x34)
	__vol uint32_t AHB3ENR;       // RCC AHB3 peripheral clock enable register     (0x38)
	__vol uint32_t RESERVED2;     // Reserved                                      (0x3C)
	__vol uint32_t APB1ENR;       // RCC APB1 peripheral clock enable register     (0x40)
	__vol uint32_t APB2ENR;       // RCC APB2 peripheral clock enable register     (0x44)
	__vol uint32_t RESERVED3[2];  // Reserved                                      (0x48-0x4C)
	__vol uint32_t AHB1LPENR;     // RCC AHB1 peripheral clock enable in low power (0x50)
	__vol uint32_t AHB2LPENR;     // RCC AHB2 peripheral clock enable in low power (0x54)
	__vol uint32_t AHB3LPENR;     // RCC AHB3 peripheral clock enable in low power (0x58)
	__vol uint32_t RESERVED4;     // Reserved                                      (0x5C)
	__vol uint32_t APB1LPENR;     // RCC APB1 peripheral clock enable in low power (0x60)
	__vol uint32_t APB2LPENR;     // RCC APB2 peripheral clock enable in low power (0x64)
	__vol uint32_t RESERVED5[2];  // Reserved                                      (0x68-0x6C)
	__vol uint32_t BDCR;          // RCC Backup domain control register            (0x70)
	__vol uint32_t CSR;           // RCC clock control & status register           (0x74)
	__vol uint32_t RESERVED6[2];  // Reserved                                      (0x78-0x7C)
	__vol uint32_t SSCGR;         // RCC spread spectrum clock generation register (0x80)
	__vol uint32_t PLLI2SCFGR;    // RCC PLLI2S configuration register             (0x84)
	__vol uint32_t PLLSAICFGR;    // RCC PLLSAI configuration register             (0x88)
	__vol uint32_t DCKCFGR;       // RCC Dedicated Clocks configuration register   (0x8C)
	__vol uint32_t CKGATENR;      // RCC clocks gated enable register              (0x90)
	__vol uint32_t DCKCFGR2;      // RCC Dedicated Clocks configuration register 2 (0x94)
} RCC_RegDef_t;


/*SPI REGISTER STRUCTURE FOR STM32F446 series*/

typedef struct
{
    __vol uint32_t CR1;       // Control register 1     (0x00)
    __vol uint32_t CR2;       // Control register 2     (0x04)
    __vol uint32_t SR;        // Status register        (0x08)
    __vol uint32_t DR;        // Data register          (0x0C)
    __vol uint32_t CRCPR;     // CRC polynomial         (0x10)
    __vol uint32_t RXCRCR;    // RX CRC register        (0x14)
    __vol uint32_t TXCRCR;    // TX CRC register        (0x18)
    __vol uint32_t I2SCFGR;   // I2S config register    (0x1C)
    __vol uint32_t I2SPR;     // I2S prescaler          (0x20)
} SPI_RegDef_t;

/*I2C REGISTER STRUCTURE FOR STM32F446 series*/

typedef struct
{
    __vol uint32_t CR1;       // Control register 1        (0x00)
    __vol uint32_t CR2;       // Control register 2        (0x04)
    __vol uint32_t OAR1;      // Own address register 1    (0x08)
    __vol uint32_t OAR2;      // Own address register 2    (0x0C)
    __vol uint32_t DR;        // Data register             (0x10)
    __vol uint32_t SR1;       // Status register 1         (0x14)
    __vol uint32_t SR2;       // Status register 2         (0x18)
    __vol uint32_t CCR;       // Clock control register    (0x1C)
    __vol uint32_t TRISE;     // TRISE register            (0x20)
    __vol uint32_t FLTR;      // Filter register           (0x24)
} I2C_RegDef_t;

/*ADC REGISTER STRUCTURE FOR STM32F446 series*/
typedef struct
{
    __vol uint32_t SR;         // Status register                (0x00)
    __vol uint32_t CR1;        // Control register 1             (0x04)
    __vol uint32_t CR2;        // Control register 2             (0x08)
    __vol uint32_t SMPR1;      // Sample time register 1         (0x0C)
    __vol uint32_t SMPR2;      // Sample time register 2         (0x10)
    __vol uint32_t JOFR1;      // Injected offset 1              (0x14)
    __vol uint32_t JOFR2;      // Injected offset 2              (0x18)
    __vol uint32_t JOFR3;      // Injected offset 3              (0x1C)
    __vol uint32_t JOFR4;      // Injected offset 4              (0x20)
    __vol uint32_t HTR;        // Analog watchdog high threshold (0x24)
    __vol uint32_t LTR;        // Analog watchdog low threshold  (0x28)
    __vol uint32_t SQR1;       // Regular sequence register 1    (0x2C)
    __vol uint32_t SQR2;       // Regular sequence register 2    (0x30)
    __vol uint32_t SQR3;       // Regular sequence register 3    (0x34)
    __vol uint32_t JSQR;       // Injected sequence register     (0x38)
    __vol uint32_t JDR1;       // Injected data register 1       (0x3C)
    __vol uint32_t JDR2;       // Injected data register 2       (0x40)
    __vol uint32_t JDR3;       // Injected data register 3       (0x44)
    __vol uint32_t JDR4;       // Injected data register 4       (0x48)
    __vol uint32_t DR;         // Regular data register          (0x4C)
} ADC_RegDef_t;

/*ADC COMMON REGISTER STRUCTURE FOR STM32F446 series*/
typedef struct
{
    __vol uint32_t CSR;        // Common status register         (0x00)
    __vol uint32_t CCR;        // Common control register        (0x04)
    __vol uint32_t CDR;        // Common data register           (0x08)
} ADC_CommonRegDef_t;


/*--------------------------------------POINTERS------------------------------*/

/*GPIO POINTERS*/

#define GPIOA   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD   ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE   ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF   ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG   ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH   ((GPIO_RegDef_t*)GPIOH_BASEADDR)

/*RCC POINTERS*/

#define RCC   ((RCC_RegDef_t*)RCC_BASEADDR)

/*SPI POINTERS*/

#define SPI1    ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2    ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3    ((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4    ((SPI_RegDef_t*)SPI4_BASEADDR)

/*I2C POINTERS*/

#define I2C1   ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2   ((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3   ((I2C_RegDef_t*)I2C3_BASEADDR)

/*ADC POINTERS*/
#define ADC1   ((ADC_RegDef_t*)ADC1_BASEADDR)
#define ADC2   ((ADC_RegDef_t*)ADC2_BASEADDR)
#define ADC3   ((ADC_RegDef_t*)ADC3_BASEADDR)
#define ADC_COMMON   ((ADC_CommonRegDef_t*)ADC_COMMON_BASEADDR)

/**********************************Clock Enable Macros **********************************/

/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()                     (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()                     (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()                     (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()                     (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()                     (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()                     (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()                     (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()                     (RCC->AHB1ENR |= (1 << 7))

/*
 * Clock Enable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN()                      (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()                      (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()                      (RCC->APB1ENR |= (1 << 23))
#define FMPI2C1_PCLK_EN()                   (RCC->APB1ENR |= (1 << 24))


/*
 * Clock Enable Macros for SPIx peripherals
 */
#define SPI1_PCLK_EN()                      (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()                      (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()                      (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()                      (RCC->APB2ENR |= (1 << 13))


/*
 * Clock Enable Macros for USARTx peripherals
 */
#define USART1_PCLK_EN()                    (RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()                    (RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()                    (RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN()                     (RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()                     (RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN()                    (RCC->APB2ENR |= (1 << 5))

/* Aliases for backward compatibility */
#define USART1_PCCK_EN()                    USART1_PCLK_EN()
#define USART2_PCCK_EN()                    USART2_PCLK_EN()
#define USART3_PCCK_EN()                    USART3_PCLK_EN()
#define UART4_PCCK_EN()                     UART4_PCLK_EN()
#define UART5_PCCK_EN()                     UART5_PCLK_EN()
#define USART6_PCCK_EN()                    USART6_PCLK_EN()


/*
 * Clock Enable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN()                    (RCC->APB2ENR |= (1 << 14))


/*
 * Clock Enable Macros for CRC peripheral
 */
#define CRC_PCLK_EN()                       (RCC->AHB1ENR |= (1 << 12))


/*
 * Clock Enable Macros for DMA peripherals
 */
#define DMA1_PCLK_EN()                      (RCC->AHB1ENR |= (1 << 21))
#define DMA2_PCLK_EN()                      (RCC->AHB1ENR |= (1 << 22))


/* CLOCK ENABLE MACROS FOR ADC (APB2 BUS) */
#define ADC1_CLK_EN()   (RCC->APB2ENR |= (1 << 8))
#define ADC2_CLK_EN()   (RCC->APB2ENR |= (1 << 9))
#define ADC3_CLK_EN()   (RCC->APB2ENR |= (1 << 10))

/**********************************Clock Disable Macros **********************************/

/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI()                     (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()                     (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()                     (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()                     (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()                     (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()                     (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()                     (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()                     (RCC->AHB1ENR &= ~(1 << 7))


/*
 * Clock Disable Macros for SPIx peripherals
 */
#define SPI1_PCLK_DI()                      (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()                      (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()                      (RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()                      (RCC->APB2ENR &= ~(1 << 13))


/*
 * Clock Disable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_DI()                      (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()                      (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()                      (RCC->APB1ENR &= ~(1 << 23))
#define FMPI2C1_PCLK_DI()                   (RCC->APB1ENR &= ~(1 << 24))


/*
 * Clock Disable Macros for USARTx peripherals
 */
#define USART1_PCLK_DI()                    (RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()                    (RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()                    (RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DI()                     (RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI()                     (RCC->APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DI()                    (RCC->APB2ENR &= ~(1 << 5))


/*
 * Clock Disable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_DI()                    (RCC->APB2ENR &= ~(1 << 14))

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)

#endif /* DRIVERS_INC_STM32F446XX_H_ */
