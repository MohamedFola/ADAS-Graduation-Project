################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/02-HAL/01-ULTRASOINC/ULTRASONIC_program.c 

OBJS += \
./Src/02-HAL/01-ULTRASOINC/ULTRASONIC_program.o 

C_DEPS += \
./Src/02-HAL/01-ULTRASOINC/ULTRASONIC_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/02-HAL/01-ULTRASOINC/%.o Src/02-HAL/01-ULTRASOINC/%.su: ../Src/02-HAL/01-ULTRASOINC/%.c Src/02-HAL/01-ULTRASOINC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-02-2d-HAL-2f-01-2d-ULTRASOINC

clean-Src-2f-02-2d-HAL-2f-01-2d-ULTRASOINC:
	-$(RM) ./Src/02-HAL/01-ULTRASOINC/ULTRASONIC_program.d ./Src/02-HAL/01-ULTRASOINC/ULTRASONIC_program.o ./Src/02-HAL/01-ULTRASOINC/ULTRASONIC_program.su

.PHONY: clean-Src-2f-02-2d-HAL-2f-01-2d-ULTRASOINC
