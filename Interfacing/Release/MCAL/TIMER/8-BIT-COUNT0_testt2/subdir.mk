################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER/8-BIT-COUNT0_testt2/8BIT_prg.c 

OBJS += \
./MCAL/TIMER/8-BIT-COUNT0_testt2/8BIT_prg.o 

C_DEPS += \
./MCAL/TIMER/8-BIT-COUNT0_testt2/8BIT_prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER/8-BIT-COUNT0_testt2/%.o: ../MCAL/TIMER/8-BIT-COUNT0_testt2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


