/* 
====================================================
Description : The Linker Script for Cortex-M3 stm32f103c6 
Author	    : Ali Emad
Date		: 26/9/2023
Copyrights  : Learn in depth first term project
====================================================
*/

/*
Mission: collect for me all .text section in one big .text section 
and all .data sections in one big .data section and etc...
then locate them in flash or sram

1- memory layout
2- sections
	- text
	- bss
	- data
	- rodata
3- memory of each sections
4- get sections boundaries
5- save linker locator to stack pointer
6-check and ALIGN memory odd none word spaces

NOTES:
	(.vectors*): This is the pattern being matched. 
It consists of two parts:
	.vectors: This is a literal section name. 
It means that the pattern is looking for sections with names
 that start with ".vectors."
	*: This is another asterisk acting as a wildcard, 
and it indicates that the pattern should match any 
characters that come after ".vectors" in the section name.

*/

MEMORY
{
flash(RX): ORIGIN = 0x08000000, LENGTH = 128K
sram(RWX): ORIGIN = 0x02000000, LENGTH = 20K
}

SECTIONS
{
	.text : { /* _S_text = flash start so no need to store it*/
		*(.vectors*) /* The Startup vector table*/
		*(.text)
		*(.rodata)
		_E_text = . ;
	}> flash
	
	.data : {
		_S_data = . ;
		*(.data)
		_E_data = . ;
	}> sram AT>flash
	
	.bss : {
		_S_bss = . ;
		*(.bss)
		_E_bss = . ;
	}> sram
	
	. = . + 0x1000;
	_stack_pointer = . ;
}