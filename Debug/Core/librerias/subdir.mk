################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/librerias/LCD.c 

OBJS += \
./Core/librerias/LCD.o 

C_DEPS += \
./Core/librerias/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
Core/librerias/%.o Core/librerias/%.su Core/librerias/%.cyclo: ../Core/librerias/%.c Core/librerias/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"/home/javier-serna/STM32CubeIDE/workspace_1.19.0/Controlador de pwm/Core/librerias" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-librerias

clean-Core-2f-librerias:
	-$(RM) ./Core/librerias/LCD.cyclo ./Core/librerias/LCD.d ./Core/librerias/LCD.o ./Core/librerias/LCD.su

.PHONY: clean-Core-2f-librerias

