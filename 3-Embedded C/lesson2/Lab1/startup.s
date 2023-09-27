/* 
The advantage of writing startup in assembly is 
that you can set the (sp) register by yourself
 */

/*
In cortex M3 we do not write this instruction, 
as by default the cpu takes the address in 
the entry point as the starting of the stack 
top(value of SP register).
*/

.global reset 	/*To be seen in vector table*/
reset:
	ldr sp, =stack_top 
	bl main
stop: b stop
