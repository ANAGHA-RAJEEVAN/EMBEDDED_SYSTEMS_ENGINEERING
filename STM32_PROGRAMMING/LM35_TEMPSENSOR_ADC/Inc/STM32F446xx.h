/*
 *  STM32F446xx.h
 *
 *  Created on: Nov 29, 2025
*   Author: ANAGHA R
 */


#ifndef STM32F446XX_H_
#define STM32F446XX_H_

/*GPIO BASE ADDRESSES (AHB1 BUS)*/

#define GPIOA_BASEADDR  0x40020000
#define GPIOB_BASEADDR  0x40020400
#define GPIOC_BASEADDR  0x40020800
#define GPIOD_BASEADDR  0x40020C00
#define GPIOE_BASEADDR  0x40021000
#define GPIOF_BASEADDR  0x40021400
#define GPIOG_BASEADDR  0x40021800
#define GPIOH_BASEADDR  0x40021C00

/*GPIO REGISTER STRUCTURE FOR STM32F446 series*/

typedef struct
{
    volatile uint32_t MODER;    // GPIO port mode register              (0x00)
    volatile uint32_t OTYPER;   // GPIO port output type register       (0x04)
    volatile uint32_t OSPEEDR;  // GPIO port output speed register      (0x08)
    volatile uint32_t PUPDR;    // GPIO port pull-up/pull-down register (0x0C)
    volatile uint32_t IDR;      // GPIO port input data register        (0x10)
    volatile uint32_t ODR;      // GPIO port output data register       (0x14)
    volatile uint32_t BSRR;     // GPIO port bit set/reset register     (0x18)
    volatile uint32_t LCKR;     // GPIO port configuration lock register(0x1C)
    volatile uint32_t AFRL;     // GPIO alternate function low register (0x20)
    volatile uint32_t AFRH;     // GPIO alternate function high register(0x24)
} GPIO_RegDef_t;

/*GPIO POINTERS*/

#define GPIOA   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD   ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE   ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF   ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG   ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH   ((GPIO_RegDef_t*)GPIOH_BASEADDR)


/*I2C BASE ADDRESSES (APB1 BUS)*/

#define I2C1_BASEADDR   0x40005400
#define I2C2_BASEADDR   0x40005800
#define I2C3_BASEADDR   0x40005C00

/*I2C REGISTER STRUCTURE FOR STM32F446 series*/

typedef struct
{
    volatile uint32_t CR1;       // Control register 1        (0x00)
    volatile uint32_t CR2;       // Control register 2        (0x04)
    volatile uint32_t OAR1;      // Own address register 1    (0x08)
    volatile uint32_t OAR2;      // Own address register 2    (0x0C)
    volatile uint32_t DR;        // Data register             (0x10)
    volatile uint32_t SR1;       // Status register 1         (0x14)
    volatile uint32_t SR2;       // Status register 2         (0x18)
    volatile uint32_t CCR;       // Clock control register    (0x1C)
    volatile uint32_t TRISE;     // TRISE register            (0x20)
    volatile uint32_t FLTR;      // Filter register           (0x24)
} I2C_RegDef_t;

/*I2C POINTERS*/

#define I2C1   ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2   ((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3   ((I2C_RegDef_t*)I2C3_BASEADDR)


/*SPI BASE ADDRESSES (APB2 / APB1 BUS)*/

#define SPI1_BASEADDR   0x40013000   // APB2
#define SPI2_BASEADDR   0x40003800   // APB1
#define SPI3_BASEADDR   0x40003C00   // APB1
#define SPI4_BASEADDR   0x40013400   // APB2

/*SPI REGISTER STRUCTURE FOR STM32F446 series*/

typedef struct
{
    volatile uint32_t CR1;       // Control register 1     (0x00)
    volatile uint32_t CR2;       // Control register 2     (0x04)
    volatile uint32_t SR;        // Status register        (0x08)
    volatile uint32_t DR;        // Data register          (0x0C)
    volatile uint32_t CRCPR;     // CRC polynomial         (0x10)
    volatile uint32_t RXCRCR;    // RX CRC register        (0x14)
    volatile uint32_t TXCRCR;    // TX CRC register        (0x18)
    volatile uint32_t I2SCFGR;   // I2S config register    (0x1C)
    volatile uint32_t I2SPR;     // I2S prescaler          (0x20)
} SPI_RegDef_t;

/*SPI POINTERS*/

#define SPI1    ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2    ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3    ((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4    ((SPI_RegDef_t*)SPI4_BASEADDR)


/*RCC BASE ADDRESS*/

#define RCC_BASEADDR   0x40023800

/*RCC REGISTER STRUCTURE FOR STM32F446 series*/

typedef struct
{
	volatile uint32_t CR;            // RCC clock control register                    (0x00)
    volatile uint32_t PLLCFGR;       // RCC PLL configuration register                (0x04)
    volatile uint32_t CFGR;          // RCC clock configuration register              (0x08)
    volatile uint32_t CIR;           // RCC clock interrupt register                  (0x0C)
    volatile uint32_t AHB1RSTR;      // RCC AHB1 peripheral reset register            (0x10)
    volatile uint32_t AHB2RSTR;      // RCC AHB2 peripheral reset register            (0x14)
    volatile uint32_t AHB3RSTR;      // RCC AHB3 peripheral reset register            (0x18)
    volatile uint32_t RESERVED0;     // Reserved                                      (0x1C)
	volatile uint32_t APB1RSTR;      // RCC APB1 peripheral reset register            (0x20)
	volatile uint32_t APB2RSTR;      // RCC APB2 peripheral reset register            (0x24)
	volatile uint32_t RESERVED1[2];  // Reserved                                      (0x28-0x2C)
	volatile uint32_t AHB1ENR;       // RCC AHB1 peripheral clock enable register     (0x30)
	volatile uint32_t AHB2ENR;       // RCC AHB2 peripheral clock enable register     (0x34)
	volatile uint32_t AHB3ENR;       // RCC AHB3 peripheral clock enable register     (0x38)
	volatile uint32_t RESERVED2;     // Reserved                                      (0x3C)
	volatile uint32_t APB1ENR;       // RCC APB1 peripheral clock enable register     (0x40)
	volatile uint32_t APB2ENR;       // RCC APB2 peripheral clock enable register     (0x44)
	volatile uint32_t RESERVED3[2];  // Reserved                                      (0x48-0x4C)
	volatile uint32_t AHB1LPENR;     // RCC AHB1 peripheral clock enable in low power (0x50)
	volatile uint32_t AHB2LPENR;     // RCC AHB2 peripheral clock enable in low power (0x54)
	volatile uint32_t AHB3LPENR;     // RCC AHB3 peripheral clock enable in low power (0x58)
	volatile uint32_t RESERVED4;     // Reserved                                      (0x5C)
	volatile uint32_t APB1LPENR;     // RCC APB1 peripheral clock enable in low power (0x60)
	volatile uint32_t APB2LPENR;     // RCC APB2 peripheral clock enable in low power (0x64)
	volatile uint32_t RESERVED5[2];  // Reserved                                      (0x68-0x6C)
	volatile uint32_t BDCR;          // RCC Backup domain control register            (0x70)
	volatile uint32_t CSR;           // RCC clock control & status register           (0x74)
	volatile uint32_t RESERVED6[2];  // Reserved                                      (0x78-0x7C)
	volatile uint32_t SSCGR;         // RCC spread spectrum clock generation register (0x80)
	volatile uint32_t PLLI2SCFGR;    // RCC PLLI2S configuration register             (0x84)
	volatile uint32_t PLLSAICFGR;    // RCC PLLSAI configuration register             (0x88)
	volatile uint32_t DCKCFGR;       // RCC Dedicated Clocks configuration register   (0x8C)
	volatile uint32_t CKGATENR;      // RCC clocks gated enable register              (0x90)
	volatile uint32_t DCKCFGR2;      // RCC Dedicated Clocks configuration register 2 (0x94)
} RCC_RegDef_t;

/*RCC POINTERS*/

#define RCC   ((RCC_RegDef_t*)RCC_BASEADDR)

/*CLOCK ENABLE MACROS OF AHB1 BUS FOR GPIOs*/

#define GPIOA_CLK_EN()  (RCC -> AHB1ENR |= (1 << 0))
#define GPIOB_CLK_EN()  (RCC -> AHB1ENR |= (1 << 1))
#define GPIOC_CLK_EN()  (RCC -> AHB1ENR |= (1 << 2))
#define GPIOD_CLK_EN()  (RCC -> AHB1ENR |= (1 << 3))
#define GPIOE_CLK_EN()  (RCC -> AHB1ENR |= (1 << 4))
#define GPIOF_CLK_EN()  (RCC -> AHB1ENR |= (1 << 5))
#define GPIOG_CLK_EN()  (RCC -> AHB1ENR |= (1 << 6))
#define GPIOH_CLK_EN()  (RCC -> AHB1ENR |= (1 << 7))


/*ADC BASE ADDRESS (APB2 BUS)*/
#define ADC1_BASEADDR   0x40012000
#define ADC2_BASEADDR   0x40012100
#define ADC3_BASEADDR   0x40012200
#define ADC_COMMON_BASEADDR  0x40012300   // Common registers

/*ADC REGISTER STRUCTURE FOR STM32F446 series*/
typedef struct
{
    volatile uint32_t SR;         // Status register                (0x00)
    volatile uint32_t CR1;        // Control register 1             (0x04)
    volatile uint32_t CR2;        // Control register 2             (0x08)
    volatile uint32_t SMPR1;      // Sample time register 1         (0x0C)
    volatile uint32_t SMPR2;      // Sample time register 2         (0x10)
    volatile uint32_t JOFR1;      // Injected offset 1              (0x14)
    volatile uint32_t JOFR2;      // Injected offset 2              (0x18)
    volatile uint32_t JOFR3;      // Injected offset 3              (0x1C)
    volatile uint32_t JOFR4;      // Injected offset 4              (0x20)
    volatile uint32_t HTR;        // Analog watchdog high threshold (0x24)
    volatile uint32_t LTR;        // Analog watchdog low threshold  (0x28)
    volatile uint32_t SQR1;       // Regular sequence register 1    (0x2C)
    volatile uint32_t SQR2;       // Regular sequence register 2    (0x30)
    volatile uint32_t SQR3;       // Regular sequence register 3    (0x34)
    volatile uint32_t JSQR;       // Injected sequence register     (0x38)
    volatile uint32_t JDR1;       // Injected data register 1       (0x3C)
    volatile uint32_t JDR2;       // Injected data register 2       (0x40)
    volatile uint32_t JDR3;       // Injected data register 3       (0x44)
    volatile uint32_t JDR4;       // Injected data register 4       (0x48)
    volatile uint32_t DR;         // Regular data register          (0x4C)
} ADC_RegDef_t;

/*ADC COMMON REGISTER STRUCTURE FOR STM32F446 series*/
typedef struct
{
    volatile uint32_t CSR;        // Common status register         (0x00)
    volatile uint32_t CCR;        // Common control register        (0x04)
    volatile uint32_t CDR;        // Common data register           (0x08)
} ADC_CommonRegDef_t;

/*ADC POINTERS*/
#define ADC1   ((ADC_RegDef_t*)ADC1_BASEADDR)
#define ADC2   ((ADC_RegDef_t*)ADC2_BASEADDR)
#define ADC3   ((ADC_RegDef_t*)ADC3_BASEADDR)
#define ADC_COMMON   ((ADC_CommonRegDef_t*)ADC_COMMON_BASEADDR)

/* CLOCK ENABLE MACROS FOR ADC (APB2 BUS) */
#define ADC1_CLK_EN()   (RCC->APB2ENR |= (1 << 8))
#define ADC2_CLK_EN()   (RCC->APB2ENR |= (1 << 9))
#define ADC3_CLK_EN()   (RCC->APB2ENR |= (1 << 10))

#endif /* STM32F446XX_H_ */
