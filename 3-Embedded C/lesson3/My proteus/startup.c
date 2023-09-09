/* Startup.c
 By: Ali Emad*/
 
 #include <stdint.h>
 
 extern int main(void);
 
 void Reset_Handler(void);
 
  void Default_Handler(){
	 Reset_Handler();
 }
 
 void NMI_Handler(void) __attribute__ ((weak,alias ("Default_Handler")));
 void H_fault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));

 
 uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) 0x2000000,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler
 };
 
 void Reset_Handler(void){
	main(); //Warnning??
 }
 

