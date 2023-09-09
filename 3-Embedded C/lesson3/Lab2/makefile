# @copyright: Ali Emad

#>>>SHAPE 1: one batch
# MyUART.bin: uart.c app.c startup.s
	# arm-none-eabi-gcc.exe -c -mcpu=arm926ej-s -I . -g app.c -o app.o
	# arm-none-eabi-gcc.exe -c -mcpu=arm926ej-s -I . -g uart.c -o uart.o
	# arm-none-eabi-as.exe -c -mcpu=arm926ej-s -I . -g startup.s -o startup.o
	# arm-none-eabi-ld.exe -T linker_script.ld startup.o app.o uart.o -o MyUART.elf
	# arm-none-eabi-objcopy.exe -O binary MyUART.elf MyUART.bin

# clean_all:
	# rm *.o *.elf *.bin
	
#>>>SHAPE 2: incremental build

#CC for Cross tool Chain
CC=arm-none-eabi-

#CFLAGS for const commands
CFLAGS=-mcpu=cortex-m3 -gdwarf-2

#INCS to include headers
INCS=-I .

#LIBS for libraries
LIBS=

#take all source C files together
SRC=$(wildcard *.c)
#: in "SRC:" refers to take each one
OBJ=$(SRC:.c=.o)

As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)

Project_name=cortex_m3

all : $(Project_name).bin
	@echo "build is Done"

%.o: %.s
	$(CC)as.exe -c $(INCS) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -MAP=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin
	
#SHAPE 3: Some specifications (DRY) 
# $< : Dependencies
# $@ : Target

#SHAPE 4:
#SHAPE 5: generic rules takes %
#SHAPE 6: Wildcard 