


all:	test


.PHONY: test

test:
	arm-none-eabi-gcc -Os -g -c -mthumb -mcpu=cortex-m3 -Iinclude src/lpc1343/I2cDriver.c 
	arm-none-eabi-size I2cDriver.o

