################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/01-MCAL/01-PORT/PORT_program.c 

OBJS += \
./Src/01-MCAL/01-PORT/PORT_program.o 

C_DEPS += \
./Src/01-MCAL/01-PORT/PORT_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/01-MCAL/01-PORT/%.o Src/01-MCAL/01-PORT/%.su: ../Src/01-MCAL/01-PORT/%.c Src/01-MCAL/01-PORT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-01-2d-MCAL-2f-01-2d-PORT

clean-Src-2f-01-2d-MCAL-2f-01-2d-PORT:
	-$(RM) ./Src/01-MCAL/01-PORT/PORT_program.d ./Src/01-MCAL/01-PORT/PORT_program.o ./Src/01-MCAL/01-PORT/PORT_program.su

.PHONY: clean-Src-2f-01-2d-MCAL-2f-01-2d-PORT

