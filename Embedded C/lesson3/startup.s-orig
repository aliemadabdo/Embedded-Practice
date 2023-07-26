/* startup coretex-M3 
By: Ali Emad 

stack pointer by default in this arm family is 
   taken from the entry pointer
   the entry point is at 0x8000000
SRAM top at 0x2000000
*/

/*.word sets 32 bit (4 bytes) with the value after it*/
.section .vectors 	  /* this is not assembly it is acommand for assembler*/
.word 0x20001000	  /* Stack top address */
.word _reset		  /* 1 Reset */
.word Vector_handler  /* 2 NMI */
.word Vector_handler  /* 2 Hard Fault */
/* ...up to 84 ISR */

.section .text
_reset:
	bl main
	bl .

.thumb_func /* To let the compiler handles 16 or 32 bit instruction*/	

Vector_handler:
	b _reset /* Dumy implementation for interuptes (just reset the program)*/
	