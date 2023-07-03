################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"C:\Users\Anwar\Desktop\SBME 2024\COURSES\Cortex Mx Programming\Task Schedualer\Code\Tasks_Schedular\Gpio" -I"C:\Users\Anwar\Desktop\SBME 2024\COURSES\Cortex Mx Programming\Task Schedualer\Code\Tasks_Schedular\LCD" -I"C:\Users\Anwar\Desktop\SBME 2024\COURSES\Cortex Mx Programming\Task Schedualer\Code\Tasks_Schedular\Delay" -I"C:\Users\Anwar\Desktop\SBME 2024\COURSES\Cortex Mx Programming\Task Schedualer\Code\Tasks_Schedular\Led" -I"C:\Users\Anwar\Desktop\SBME 2024\COURSES\Cortex Mx Programming\Task Schedualer\Code\Tasks_Schedular\Lib" -I"C:\Users\Anwar\Desktop\SBME 2024\COURSES\Cortex Mx Programming\Task Schedualer\Code\Tasks_Schedular\Rcc" -I"../include" -I"../system/include" -I"../system/include/cmsis" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


