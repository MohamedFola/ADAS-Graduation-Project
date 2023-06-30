################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/03-APP/01-COMM_HANDLER/CommHandler_program.c 

OBJS += \
./Src/03-APP/01-COMM_HANDLER/CommHandler_program.o 

C_DEPS += \
./Src/03-APP/01-COMM_HANDLER/CommHandler_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/03-APP/01-COMM_HANDLER/%.o Src/03-APP/01-COMM_HANDLER/%.su: ../Src/03-APP/01-COMM_HANDLER/%.c Src/03-APP/01-COMM_HANDLER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-03-2d-APP-2f-01-2d-COMM_HANDLER

clean-Src-2f-03-2d-APP-2f-01-2d-COMM_HANDLER:
	-$(RM) ./Src/03-APP/01-COMM_HANDLER/CommHandler_program.d ./Src/03-APP/01-COMM_HANDLER/CommHandler_program.o ./Src/03-APP/01-COMM_HANDLER/CommHandler_program.su

.PHONY: clean-Src-2f-03-2d-APP-2f-01-2d-COMM_HANDLER

