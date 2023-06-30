################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/00-LIB/Software_Delay.c 

OBJS += \
./Src/00-LIB/Software_Delay.o 

C_DEPS += \
./Src/00-LIB/Software_Delay.d 


# Each subdirectory must supply rules for building sources it contributes
Src/00-LIB/%.o Src/00-LIB/%.su: ../Src/00-LIB/%.c Src/00-LIB/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-00-2d-LIB

clean-Src-2f-00-2d-LIB:
	-$(RM) ./Src/00-LIB/Software_Delay.d ./Src/00-LIB/Software_Delay.o ./Src/00-LIB/Software_Delay.su

.PHONY: clean-Src-2f-00-2d-LIB

