################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dio.c \
../EEPROM_prog.c \
../I2C_prog.c \
../TIMER_prog.c \
../UART_prog.c \
../UARTmain.c \
../lcd.c 

OBJS += \
./Dio.o \
./EEPROM_prog.o \
./I2C_prog.o \
./TIMER_prog.o \
./UART_prog.o \
./UARTmain.o \
./lcd.o 

C_DEPS += \
./Dio.d \
./EEPROM_prog.d \
./I2C_prog.d \
./TIMER_prog.d \
./UART_prog.d \
./UARTmain.d \
./lcd.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


