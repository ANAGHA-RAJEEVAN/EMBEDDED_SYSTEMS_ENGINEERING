/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: Jan 27, 2026
 *      Author: anagh
 */
#include <stddef.h>
#include <stdint.h>
#include "stm32f446xx.h"

#ifndef DRIVERS_INC_STM32F446XX_GPIO_DRIVER_H_
#define DRIVERS_INC_STM32F446XX_GPIO_DRIVER_H_

/*Configuration structure for a GPIO pin*/
typedef struct
{
    uint8_t GPIO_PinNumber;        // Pin number (0-15)
    uint8_t GPIO_PinMode;          // Mode: Input/Output/AltFn/Analog
    uint8_t GPIO_PinSpeed;         // Speed: Low/Medium/High/Very High
    uint8_t GPIO_PinPuPdControl;   // Pull-up/Pull-down configuration
    uint8_t GPIO_PinOPType;        // Output type: Push-Pull/Open-Drain
    uint8_t GPIO_PinAltFunMode;    // Alternate function (0-15)
} GPIO_PinConfig_t;

/*Handle structure for a GPIO pin*/
typedef struct
{
    GPIO_RegDef_t *pGPIOx;              /*!< This holds the base address of the GPIO port to which the pin belongs */
    GPIO_PinConfig_t GPIO_PinConfig;    /*!< This holds GPIO pin configuration settings */
} GPIO_Handle_t;


/*GPIO pin numbers*/
#define GPIO_PIN_NO_0                   0
#define GPIO_PIN_NO_1                   1
#define GPIO_PIN_NO_2                   2
#define GPIO_PIN_NO_3                   3
#define GPIO_PIN_NO_4                   4
#define GPIO_PIN_NO_5                   5
#define GPIO_PIN_NO_6                   6
#define GPIO_PIN_NO_7                   7
#define GPIO_PIN_NO_8                   8
#define GPIO_PIN_NO_9                   9
#define GPIO_PIN_NO_10                  10
#define GPIO_PIN_NO_11                  11
#define GPIO_PIN_NO_12                  12
#define GPIO_PIN_NO_13                  13
#define GPIO_PIN_NO_14                  14
#define GPIO_PIN_NO_15                  15


/*GPIO pin possible modes*/
#define GPIO_MODE_IN                    0   /* Input mode -> 00*/
#define GPIO_MODE_OUT                   1   /* General purpose output mode -> 01*/
#define GPIO_MODE_ALTFN                 2   /* Alternate function mode -> 10*/
#define GPIO_MODE_ANALOG                3   /* Analog mode -> 11*/

/*GPIO pin possible output types*/
#define GPIO_OP_TYPE_PP                 0   /* Push-pull output */
#define GPIO_OP_TYPE_OD                 1   /* Open-drain output */


/*GPIO pin possible output speeds*/
#define GPIO_SPEED_LOW                  0   /* Low speed -> 00*/
#define GPIO_SPEED_MEDIUM               1   /* Medium speed -> 01*/
#define GPIO_SPEED_FAST                 2   /* Fast speed -> 10*/
#define GPIO_SPEED_HIGH                 3   /* High speed -> 11*/


/*GPIO pin pull-up and pull-down configuration macros*/
#define GPIO_NO_PUPD                    0   /* No pull-up, no pull-down */
#define GPIO_PIN_PU                     1   /* Pull-up */
#define GPIO_PIN_PD                     2   /* Pull-down */


/**********************************Generic Macros **********************************/

#define ENABLE                              1
#define DISABLE                             0
#define SET                                 ENABLE
#define RESET                               DISABLE
#define GPIO_PIN_SET                        1
#define GPIO_PIN_RESET                      0
#define FLAG_RESET                          RESET
#define FLAG_SET                            SET

/*Peripheral Clock setup*/

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*Init*/

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);

/*De-init*/

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*Data read*/

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

/*Data write*/

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

/*Toggle output pin*/

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


#endif /* DRIVERS_INC_STM32F446XX_GPIO_DRIVER_H_ */
