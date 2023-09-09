################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
stm_begin.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
stm_begin.list \

OBJCOPY_BIN += \
stm_begin.bin \


# All Target
all: stm_begin.elf secondary-outputs

# Tool invocations
stm_begin.elf: $(OBJS) $(USER_OBJS) C:\Users\ALI\Documents\GitHub\Embedded-Practice\Embedded\ C\lesson1\STM\ Cube\ test\stm_begin\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "stm_begin.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\ALI\Documents\GitHub\Embedded-Practice\Embedded C\lesson1\STM Cube test\stm_begin\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="stm_begin.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

stm_begin.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "stm_begin.list"
	@echo 'Finished building: $@'
	@echo ' '

stm_begin.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "stm_begin.bin"
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
