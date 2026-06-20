################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DRIVERS/Src/stm32f446xx_gpio_driver.c \
../DRIVERS/Src/stm32f446xx_i2c_driver.c \
../DRIVERS/Src/stm32f446xx_spi_driver.c \
../DRIVERS/Src/stm32f446xx_usart_driver.c 

OBJS += \
./DRIVERS/Src/stm32f446xx_gpio_driver.o \
./DRIVERS/Src/stm32f446xx_i2c_driver.o \
./DRIVERS/Src/stm32f446xx_spi_driver.o \
./DRIVERS/Src/stm32f446xx_usart_driver.o 

C_DEPS += \
./DRIVERS/Src/stm32f446xx_gpio_driver.d \
./DRIVERS/Src/stm32f446xx_i2c_driver.d \
./DRIVERS/Src/stm32f446xx_spi_driver.d \
./DRIVERS/Src/stm32f446xx_usart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
DRIVERS/Src/%.o DRIVERS/Src/%.su DRIVERS/Src/%.cyclo: ../DRIVERS/Src/%.c DRIVERS/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"D:/EMBEDDED_SYSTEMS/STM32_PROGRAMMING/STM32_PROJECT_UPDATED/DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DRIVERS-2f-Src

clean-DRIVERS-2f-Src:
	-$(RM) ./DRIVERS/Src/stm32f446xx_gpio_driver.cyclo ./DRIVERS/Src/stm32f446xx_gpio_driver.d ./DRIVERS/Src/stm32f446xx_gpio_driver.o ./DRIVERS/Src/stm32f446xx_gpio_driver.su ./DRIVERS/Src/stm32f446xx_i2c_driver.cyclo ./DRIVERS/Src/stm32f446xx_i2c_driver.d ./DRIVERS/Src/stm32f446xx_i2c_driver.o ./DRIVERS/Src/stm32f446xx_i2c_driver.su ./DRIVERS/Src/stm32f446xx_spi_driver.cyclo ./DRIVERS/Src/stm32f446xx_spi_driver.d ./DRIVERS/Src/stm32f446xx_spi_driver.o ./DRIVERS/Src/stm32f446xx_spi_driver.su ./DRIVERS/Src/stm32f446xx_usart_driver.cyclo ./DRIVERS/Src/stm32f446xx_usart_driver.d ./DRIVERS/Src/stm32f446xx_usart_driver.o ./DRIVERS/Src/stm32f446xx_usart_driver.su

.PHONY: clean-DRIVERS-2f-Src

