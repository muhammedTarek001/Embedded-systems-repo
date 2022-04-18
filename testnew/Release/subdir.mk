################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Button.c \
../Clock.c \
../GPIO.c \
../LCD.c \
../Led.c \
../PasswordDoorlock.c \
../SEVERAL_TASKS.c \
../Sebaha.c \
../Seg.c \
../Servo.c \
../Timer.c \
../main.c 

OBJS += \
./Button.o \
./Clock.o \
./GPIO.o \
./LCD.o \
./Led.o \
./PasswordDoorlock.o \
./SEVERAL_TASKS.o \
./Sebaha.o \
./Seg.o \
./Servo.o \
./Timer.o \
./main.o 

C_DEPS += \
./Button.d \
./Clock.d \
./GPIO.d \
./LCD.d \
./Led.d \
./PasswordDoorlock.d \
./SEVERAL_TASKS.d \
./Sebaha.d \
./Seg.d \
./Servo.d \
./Timer.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


