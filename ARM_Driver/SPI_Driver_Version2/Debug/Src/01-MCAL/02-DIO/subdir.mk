################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/01-MCAL/02-DIO/DIO_program.c 

OBJS += \
./Src/01-MCAL/02-DIO/DIO_program.o 

C_DEPS += \
./Src/01-MCAL/02-DIO/DIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/01-MCAL/02-DIO/%.o Src/01-MCAL/02-DIO/%.su: ../Src/01-MCAL/02-DIO/%.c Src/01-MCAL/02-DIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-01-2d-MCAL-2f-02-2d-DIO

clean-Src-2f-01-2d-MCAL-2f-02-2d-DIO:
	-$(RM) ./Src/01-MCAL/02-DIO/DIO_program.d ./Src/01-MCAL/02-DIO/DIO_program.o ./Src/01-MCAL/02-DIO/DIO_program.su

.PHONY: clean-Src-2f-01-2d-MCAL-2f-02-2d-DIO

