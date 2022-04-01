################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad_driver/keypad_program.c 

OBJS += \
./HAL/Keypad_driver/keypad_program.o 

C_DEPS += \
./HAL/Keypad_driver/keypad_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad_driver/%.o: ../HAL/Keypad_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


