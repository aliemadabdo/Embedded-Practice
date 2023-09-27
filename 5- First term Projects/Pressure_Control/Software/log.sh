echo "############Startup.c symbols###########" >> symbols.txt
arm-none-eabi-nm startup.o >> symbols.txt
echo "############main.c symbols###########" >> symbols.txt
arm-none-eabi-nm main.o >> symbols.txt
echo "############Driver.c Symbols###########" >> symbols.txt
arm-none-eabi-nm driver.o >> symbols.txt
echo "############all symbols###########" >> symbols.txt
arm-none-eabi-nm pressureController.elf >> symbols.txt
echo "############Reading the .elf image (-a to execute them all)###########" >> symbols.txt
echo "############The symbols table###########" >> symbols.txt
arm-none-eabi-readelf.exe -s pressureController.elf >> symbols.txt
echo "############Sections headers###########" >> sections.txt
arm-none-eabi-readelf.exe -S pressureController.elf >> sections.txt
echo "############Sections###########" >> sections.txt
arm-none-eabi-objdump.exe -h pressureController.elf >> sections.txt
arm-none-eabi-readelf.exe -A pressureController.elf >> architecture.txt
arm-none-eabi-objdump.exe -D pressureController.elf >> Disassembly.txt

