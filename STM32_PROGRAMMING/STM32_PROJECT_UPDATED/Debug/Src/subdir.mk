################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio_main.c \
../Src/i2c_main.c \
../Src/main.c \
../Src/spi_main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/usart_main.c 

OBJS += \
./Src/gpio_main.o \
./Src/i2c_main.o \
./Src/main.o \
./Src/spi_main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/usart_main.o 

C_DEPS += \
./Src/gpio_main.d \
./Src/i2c_main.d \
./Src/main.d \
./Src/spi_main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/usart_main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"D:/EMBEDDED_SYSTEMS/STM32_PROGRAMMING/STM32_PROJECT_UPDATED/DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/gpio_main.cyclo ./Src/gpio_main.d ./Src/gpio_main.o ./Src/gpio_main.su ./Src/i2c_main.cyclo ./Src/i2c_main.d ./Src/i2c_main.o ./Src/i2c_main.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/spi_main.cyclo ./Src/spi_main.d ./Src/spi_main.o ./Src/spi_main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/usart_main.cyclo ./Src/usart_main.d ./Src/usart_main.o ./Src/usart_main.su

.PHONY: clean-Src

