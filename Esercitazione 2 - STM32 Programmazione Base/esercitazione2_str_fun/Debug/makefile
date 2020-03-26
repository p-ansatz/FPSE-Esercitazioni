################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
esercitazione2_str_fun.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
esercitazione2_str_fun.list \

OBJCOPY_BIN += \
esercitazione2_str_fun.bin \


# All Target
all: esercitazione2_str_fun.elf secondary-outputs

# Tool invocations
esercitazione2_str_fun.elf: $(OBJS) $(USER_OBJS) C:\Users\Paolo\develop\STM32CubeWS\esercitazione2_str_fun\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "esercitazione2_str_fun.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Paolo\develop\STM32CubeWS\esercitazione2_str_fun\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="esercitazione2_str_fun.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

esercitazione2_str_fun.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "esercitazione2_str_fun.list"
	@echo 'Finished building: $@'
	@echo ' '

esercitazione2_str_fun.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "esercitazione2_str_fun.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
