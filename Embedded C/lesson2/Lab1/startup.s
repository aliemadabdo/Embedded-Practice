.global reset 	/*To be seen in vector table*/
reset:
	ldr sp, =stack_top 
	/*
	In cortex M3 we do not write this instruction, 
	as by default the cpu takes the address in 
	the entry point as the starting of the stack 
	top(value of SP register).
	*/
	
	bl main
stop: b stop
