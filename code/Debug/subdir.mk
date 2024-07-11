################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Function.c \
../adc.c \
../gpio.c \
../keypad.c \
../lcd.c \
../lm.c \
../main.c 

OBJS += \
./Function.o \
./adc.o \
./gpio.o \
./keypad.o \
./lcd.o \
./lm.o \
./main.o 

C_DEPS += \
./Function.d \
./adc.d \
./gpio.d \
./keypad.d \
./lcd.d \
./lm.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


