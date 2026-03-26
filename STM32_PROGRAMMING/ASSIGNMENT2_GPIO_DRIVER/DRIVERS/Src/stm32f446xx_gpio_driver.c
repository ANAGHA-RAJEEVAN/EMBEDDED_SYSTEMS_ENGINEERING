/*
 * stm32f446xx_gpio_header.c
 *
 *  Created on: Jan 27, 2026
 *      Author: anagh
 */
#include <stdint.h>
#include <stdio.h>
#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"


/*Peripheral Clock setup*/

/*
 * ********************************************************************
 * @fn                - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @param[in]         - EnorDi: ENABLE or DISABLE macros
 *
 * @return            - none
 *
 * @Note              - none
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi){

	if (EnorDi == ENABLE)
	    {
	        if (pGPIOx == GPIOA)
	        	{
	        	GPIOA_PCLK_EN();
	        	}
	        else if (pGPIOx == GPIOB)
	        	{
	        	GPIOB_PCLK_EN();
	        	}
	        else if (pGPIOx == GPIOC)
	        	{
	        	GPIOC_PCLK_EN();
	        	}
	        else if (pGPIOx == GPIOD)
	        	{
	        	GPIOD_PCLK_EN();
	        	}
	        else if (pGPIOx == GPIOE)
	        	{
	        	GPIOE_PCLK_EN();
	        	}
	        else if (pGPIOx == GPIOF)
	        	{
	        	GPIOF_PCLK_EN();
	        	}
	        else if (pGPIOx == GPIOG)
	        	{
	        	GPIOG_PCLK_EN();
	        	}
	        else if (pGPIOx == GPIOH)
	        	{
	        	GPIOH_PCLK_EN();
	        	}
	    }

	    else
	        {
	            if (pGPIOx == GPIOA)
	            	{
	            	GPIOA_PCLK_DI();
	            	}
	            else if (pGPIOx == GPIOB)
	            	{
	            	GPIOB_PCLK_DI();
	            	}
	            else if (pGPIOx == GPIOC)
	            	{
	            	GPIOC_PCLK_DI();
	            	}
	            else if (pGPIOx == GPIOD)
	            	{
	            	GPIOD_PCLK_DI();
	            	}
	            else if (pGPIOx == GPIOE)
	            	{
	            	GPIOE_PCLK_DI();
	            	}
	            else if (pGPIOx == GPIOF)
	            	{
	            	GPIOF_PCLK_DI();
	            	}
	            else if (pGPIOx == GPIOG)
	            	{
	            	GPIOG_PCLK_DI();
	            	}
	            else if (pGPIOx == GPIOH)
	            	{
	            	GPIOH_PCLK_DI();
	            	}
	        }
}

/*Init*/
/*********************************************************************
 * @fn                - GPIO_Init
 *
 * @brief             - This function initializes the given GPIO port pin
 *
 * @param[in]         - pGPIOHandle: pointer to GPIO handle structure
 *
 * @return            - none
 *
 * @Note              - none
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    uint32_t temp = 0;

    /* Configure mode */
    temp = pGPIOHandle->pGPIOx->MODER;
    temp &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    temp |=  (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->MODER = temp;
    temp = 0;

    /* Configure speed */
    temp = pGPIOHandle->pGPIOx->OSPEEDR;
    temp &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    temp |=  (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR = temp;
    temp = 0;

    /* Configure pull-up/pull-down */
    temp = pGPIOHandle->pGPIOx->PUPDR;
    temp &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    temp |=  (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR = temp;
    temp = 0;

    /*Configure output type */
    temp = pGPIOHandle->pGPIOx->OTYPER;
    temp &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    temp |=  (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER = temp;
    temp = 0;

    /* Configure alternate function */
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
    			{
    				uint8_t temp1, temp2;

    				temp1 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)/8;
    				temp2 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)%8;
    				pGPIOHandle->pGPIOx->AFR[temp1] &= ~((0xF) << (4 * temp2));
    				pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4* temp2));

    			}
    }

/*De-init*/
/*********************************************************************
 * @fn                - GPIO_DeInit
 *
 * @brief             - This function is used to de-initialize or reset a gpio peripheral
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 *
 * @return            - none
 *
 * @Note              - none
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
    if  (pGPIOx == GPIOA)
    	{
    	GPIOA_REG_RESET();
    	}
    else if (pGPIOx == GPIOB)
    	{
    	GPIOA_REG_RESET();
    	}
    else if (pGPIOx == GPIOC)
    	{
    	GPIOA_REG_RESET();
    	}
    else if (pGPIOx == GPIOD)
    	{
    	GPIOA_REG_RESET();
    	}
    else if (pGPIOx == GPIOE)
    	{
    	GPIOA_REG_RESET();
    	}
    else if (pGPIOx == GPIOF)
    	{
    	GPIOA_REG_RESET();
    	}
    else if (pGPIOx == GPIOG)
    	{
    	GPIOA_REG_RESET();
    	}
    else if (pGPIOx == GPIOH)
    	{
    	GPIOA_REG_RESET();
    	}
}

/*GPIO_ReadFromInputPin*/

/*********************************************************************
 * @fn                - GPIO_Read from input pin
 *
 * @brief             - This function is used to read the value from a GPIO pin
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @param[in]         - PinNumber: PinNumber of which the value is to be read
 *
 * @return            - uint8_t(value inside the pin)
 *
 * @Note              - none
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001); //Reading value from the input pin.
	return value;

}

/*GPIO_ReadFromInputPort*/

/*********************************************************************
 * @fn                - GPIO_Read from input port
 *
 * @brief             - This function is used to read the value from a GPIO port
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 *
 * @return            - uint16_t(value inside the port.even if its a 32 bit register,16 bits from 32 are used and rest 16 are reserved)
 *
 * @Note              - none
 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){

	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR); //Reading value from the input port.
	return value;
}

/*GPIO_WriteToOutputPin*/

/*********************************************************************
 * @fn                - GPIO_Write To Output Pin
 *
 * @brief             - This function is used to write the value to a GPIO pin
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @param[in]         - PinNumber: PinNumber to which the value is to be written
 * @param[in]         - value: value to be written
 *
 * @return            - none
 *
 * @Note              - none
 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){

	if(Value == GPIO_PIN_SET )
	{
		(pGPIOx->ODR) |= (1 << PinNumber);
	}
	else if(Value == GPIO_PIN_RESET )
	{
		(pGPIOx->ODR) &= ~(1 << PinNumber);
	}

}

/*GPIO_WriteToOutputPort*/

/*********************************************************************
 * @fn                - GPIO_Write To Output Port
 *
 * @brief             - This function is used to write the value to a GPIO port
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @param[in]         - value: value to be written
 *
 * @return            - none
 *
 * @Note              - none
 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value){

	(pGPIOx->ODR) = Value;

}

/*GPIO_ToggleOutputPin*/

/*********************************************************************
 * @fn                - GPIO_Toggle Output Pin
 *
 * @brief             - This function is used to toggle the value of a GPIO pin
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @param[in]         - PinNumber: PinNumber to which the value is to be toggled
 *
 * @return            - none
 *
 * @Note              - none
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

	(pGPIOx->ODR) ^= (1 << PinNumber);
}
