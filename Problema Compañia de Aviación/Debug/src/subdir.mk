################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Problema\ Compa�ia\ de\ Aviaci�n.cpp 

OBJS += \
./src/Problema\ Compa�ia\ de\ Aviaci�n.o 

CPP_DEPS += \
./src/Problema\ Compa�ia\ de\ Aviaci�n.d 


# Each subdirectory must supply rules for building sources it contributes
src/Problema\ Compa�ia\ de\ Aviaci�n.o: ../src/Problema\ Compa�ia\ de\ Aviaci�n.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Problema Compa�ia de Aviaci�n.d" -MT"src/Problema\ Compa�ia\ de\ Aviaci�n.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


