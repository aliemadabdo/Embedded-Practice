.global reset 	/*To be seen in vector table*/
reset:
	ldr sp, =stack_top
	bl main
stop: b stop
