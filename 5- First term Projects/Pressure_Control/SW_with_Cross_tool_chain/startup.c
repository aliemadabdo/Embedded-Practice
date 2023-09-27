/* 
====================================================
Description : The startup code in C for Cortex-M3 stm32f103c6
Author	    : Ali Emad
Date		: 26/9/2023
Copyrights  : Learn in depth first term project
====================================================
*/



/*
As (CortexM3) can intalize the SP with the first 4 bytes, so
we can write startup by C code.

handle data types by including stdint.h [DONE]

array of pointers to function{
	stack top
	reset handler
	the rest of interrupt... 
}

Write vector handler functiones

EXTERN all linker variables

reset handler implementation{ [DONE]
	copying data section from flash to memory [DONE]
	initialize bss section in ram with 0 [DONE]
	call main() [DONE]
	
}

NMI_handler(){
	reset_handler();
}

and all other handlers

check weak, alias and __attribute__

*/

/* included for data types */
#include <stdint.h>

/* extern Linker variables */
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
extern uint32_t _stack_pointer;

/* extern main function */
extern int main();

/* Handlers */
void reset_Handler();
void Default_Handler();


void NMI_Handler()__attribute__((weak,alias("Default_Handler")));
void H_fault_Handler()__attribute__((weak, alias("Default_Handler")));

/* notes about Vectors Table */
/* We use an array of uint32_t insted of .word in assembly*/
/* We can us '&' befor symbols or not, both are the same*/
/* we don't use an array of pointers as we need the data of 
   the array directly not the pointees inside the array 
   So that also we need to cast the stored symbols to the
   data type of the array which is uint32_t*/
/* __attribute__((section(".vectors"))) attribute specifies
 that this array should be placed in a section of memory
 named ".vectors." In embedded systems, it's common to
 place the vector table in a specific memory section to
 ensure that the addresses are correctly mapped to the
 microcontroller's interrupt vector table.*/

/* Vectors Table */ 
uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &_stack_pointer, /* & as it's not a function */
	(uint32_t) reset_Handler, /* for fn & is optional */
	(uint32_t) NMI_Handler,
	(uint32_t) H_fault_Handler
};

/* Reset Handler implementation */
void reset_Handler(){
	// note: _E_data = _S_bss
	// but _E_text != _S_data 
	//as text is in the flash but data is in the sram and flash
	
	/*source and destination pointers*/
	uint8_t* srcPtr = (uint8_t*)_E_text;  
	uint8_t* dstPtr = (uint8_t*)_S_data;  
	
	/* Sections sizes */
	uint32_t data_size = (uint8_t*)_E_data - (uint8_t*)_S_data;
	uint32_t bss_size  = (uint8_t*)_E_bss  - (uint8_t*)_S_bss;

	/*copying data section from flash to memory*/
	for (uint32_t i=0; i<data_size; i++){
		*dstPtr = *srcPtr;
		dstPtr = dstPtr + (uint8_t)1;
		srcPtr = srcPtr + (uint8_t)1;
	}
	
	/*initialize bss section in ram with 0*/	
	for (uint32_t i=0; i<bss_size; i++){
		*dstPtr = (uint8_t)0;
		dstPtr = dstPtr + (uint8_t)1;
	}
	
	/* We can also use the uint32_t format and each step 
	we write 4 bytes as zeros but we should use ALIGN command in linker*/
	
	main();
}

/* the rest of Handlers Implementation */
void Default_Handler(){
	reset_Handler();
}
/* void Default_Handler(){
	reset_Handler();
}

void NMI_Handler(){
	
	Default_Handler();
}

void H_fault_Handler(){
	
	Default_Handler();
} */