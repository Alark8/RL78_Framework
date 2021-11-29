################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/adc.c \
../src/adcconfig.c \
../src/adccontrol.c \
../src/clock.c \
../src/clockconfig.c \
../src/clockcontrol.c \
../src/displayitems.c \
../src/eeprom.c \
../src/fuelcontrol.c \
../src/fuelmanage.c \
../src/gpio.c \
../src/interrupt.c \
../src/interruptconfig.c \
../src/intervaltimer.c \
../src/intervaltimerconfig.c \
../src/lcdsegment.c \
../src/lcdsegmentconfig.c \
../src/lcdsegmentcontrol.c \
../src/main.c \
../src/rtc.c \
../src/rtcconfig.c \
../src/rtccontrol.c \
../src/timeconfig.c \
../src/timer.c \
../src/timercontrol.c \
../src/utils.c 

COMPILER_OBJS += \
src/adc.obj \
src/adcconfig.obj \
src/adccontrol.obj \
src/clock.obj \
src/clockconfig.obj \
src/clockcontrol.obj \
src/displayitems.obj \
src/eeprom.obj \
src/fuelcontrol.obj \
src/fuelmanage.obj \
src/gpio.obj \
src/interrupt.obj \
src/interruptconfig.obj \
src/intervaltimer.obj \
src/intervaltimerconfig.obj \
src/lcdsegment.obj \
src/lcdsegmentconfig.obj \
src/lcdsegmentcontrol.obj \
src/main.obj \
src/rtc.obj \
src/rtcconfig.obj \
src/rtccontrol.obj \
src/timeconfig.obj \
src/timer.obj \
src/timercontrol.obj \
src/utils.obj 

C_DEPS += \
src/adc.d \
src/adcconfig.d \
src/adccontrol.d \
src/clock.d \
src/clockconfig.d \
src/clockcontrol.d \
src/displayitems.d \
src/eeprom.d \
src/fuelcontrol.d \
src/fuelmanage.d \
src/gpio.d \
src/interrupt.d \
src/interruptconfig.d \
src/intervaltimer.d \
src/intervaltimerconfig.d \
src/lcdsegment.d \
src/lcdsegmentconfig.d \
src/lcdsegmentcontrol.d \
src/main.d \
src/rtc.d \
src/rtcconfig.d \
src/rtccontrol.d \
src/timeconfig.d \
src/timer.d \
src/timercontrol.d \
src/utils.d 

# Each subdirectory must supply rules for building sources it contributes
src/%.obj: ../src/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\cDepSubCommand.tmp"
	ccrl -subcommand="src\cDepSubCommand.tmp" -o "$(@:%.obj=%.d)"  -MT="$(@:%.obj=%.obj)"  -MT="$(@:%.obj=%.d)" -msg_lang=english "$<"
	@echo src\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\cSubCommand.tmp"
	ccrl -subcommand="src\cSubCommand.tmp" -msg_lang=english -o "$(@:%.d=%.obj)" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

