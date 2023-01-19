################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Problema\ Compañia\ de\ Aviación.cpp 

OBJS += \
./src/Problema\ Compañia\ de\ Aviación.o 

CPP_DEPS += \
./src/Problema\ Compañia\ de\ Aviación.d 


# Each subdirectory must supply rules for building sources it contributes
src/Problema\ Compañia\ de\ Aviación.o: ../src/Problema\ Compañia\ de\ Aviación.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Problema Compañia de Aviación.d" -MT"src/Problema\ Compañia\ de\ Aviación.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


