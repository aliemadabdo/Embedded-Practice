#Sequence
# add all needed commands
# add variables [ . * wildcards CC CFLAGS SRC OBJ INCS LIBS project_name]
# set the make commands structure [all c asm elf bin cleanall clean]
# use make symbols [@ < %] 

#basic commands
# pressureController.bin: driver.c main.c startup.c
	# arm-none-eabi-gcc.exe -c -I . -g startup.c -o startup.o
	# arm-none-eabi-gcc.exe -c -I . -g driver.c -o driver.o
	# arm-none-eabi-gcc.exe -c -I . -g main.c -o main.o
	# arm-none-eabi-ld -T Linker_script.ld startup.o main.o driver.o -o pressureController.elf
	# arm-none-eabi-objcopy -O binary pressureController.elf pressureController.bin


# Notes
# CFLAGS = -Wall --> warning all / -O2 --> opmization level 2
# The % is a wildcard character that matches any string, allowing this 
# rule to match any .o and .c file pair with the same base filename.
# $< This is an automatic variable that represents the first prerequisite
# $@ is an automatic variable that represents the target of the rule
# $< : Dependencies
# $@ : Target
# generic rules takes %

#Implementation
CC=arm-none-eabi-
CFLAGS=-c -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

AS=$(wildcard *.s)
AsOBJ=$(AS:.s=.o)

project_name=pressureController

all : pressureController.bin
	@echo "Done Building"
	
%.o: %.c
	$(CC)gcc.exe $(INCS) $(CFLAGS) $< -o $@
	
$(project_name).elf : $(OBJ)
	$(CC)ld.exe -T Linker_script.ld $(LIBS) $(OBJ) -o $@ -Map mapFile.map

$(project_name).bin: $(project_name).elf
	$(CC)objcopy -O binary $< $@
	
clean_all:
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin
	
