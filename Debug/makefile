################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include app/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/DIO_driver/subdir.mk
-include HAL/LCD_driver/subdir.mk
-include HAL/Keypad_driver/subdir.mk
-include HAL/EXT_EEPROM/subdir.mk
-include HAL/Buzzer_driver/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
locker.lss \

FLASH_IMAGE += \
locker.hex \

EEPROM_IMAGE += \
locker.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: locker.elf secondary-outputs

# Tool invocations
locker.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,locker.map -mmcu=atmega32 -o "locker.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

locker.lss: locker.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S locker.elf  >"locker.lss"
	@echo 'Finished building: $@'
	@echo ' '

locker.hex: locker.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex locker.elf  "locker.hex"
	@echo 'Finished building: $@'
	@echo ' '

locker.eep: locker.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex locker.elf  "locker.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: locker.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 locker.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) locker.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
