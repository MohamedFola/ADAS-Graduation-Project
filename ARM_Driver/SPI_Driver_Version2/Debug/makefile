################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/02-HAL/02-MOTOR/subdir.mk
-include Src/02-HAL/01-ULTRASOINC/subdir.mk
-include Src/02-HAL/00-ENC/subdir.mk
-include Src/01-MCAL/10-PWM/subdir.mk
-include Src/01-MCAL/09-SPI/subdir.mk
-include Src/01-MCAL/08-TIM/subdir.mk
-include Src/01-MCAL/07-I2C/subdir.mk
-include Src/01-MCAL/06-AFIO/subdir.mk
-include Src/01-MCAL/05-EXTI/subdir.mk
-include Src/01-MCAL/04-NVIC/subdir.mk
-include Src/01-MCAL/03-STK/subdir.mk
-include Src/01-MCAL/02-DIO/subdir.mk
-include Src/01-MCAL/01-PORT/subdir.mk
-include Src/01-MCAL/00-RCC/subdir.mk
-include Src/00-LIB/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SPI_Driver_Version2
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
SPI_Driver_Version2.elf \

MAP_FILES += \
SPI_Driver_Version2.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
SPI_Driver_Version2.list \


# All Target
all: main-build

# Main-build Target
main-build: SPI_Driver_Version2.elf secondary-outputs

# Tool invocations
SPI_Driver_Version2.elf SPI_Driver_Version2.map: $(OBJS) $(USER_OBJS) D:\Electrical\ Engineering\4th\ Year\Graduation\ Project\STM_Projects\SPI_Driver_Version2\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "SPI_Driver_Version2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Electrical Engineering\4th Year\Graduation Project\STM_Projects\SPI_Driver_Version2\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="SPI_Driver_Version2.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

SPI_Driver_Version2.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "SPI_Driver_Version2.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) SPI_Driver_Version2.elf SPI_Driver_Version2.list SPI_Driver_Version2.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
