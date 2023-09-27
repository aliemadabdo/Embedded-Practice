/* Startup.c
 By: Ali Emad*/
 
 #include <stdint.h>
 
 extern int main(void);
 
 extern uint32_t _stack_top ;
 
 void Reset_Handler(void);
 
  void Default_Handler(){
	 Reset_Handler();
 }
 
 void NMI_Handler(void) __attribute__ ((weak,alias ("Default_Handler")));
 void H_fault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));

__attribute__( weak ) ,__attribute__( (weak,alias(Default_Handler)) ) ,
__attribute__(section(".vectors"))
 uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler
 };
 
 extern unsigned int _E_text;
 extern unsigned int _S_DATA;
 extern unsigned int _E_DATA;
 extern unsigned int _E_bss;
 extern unsigned int _S_bss; 
 
 
 void Reset_Handler(void){
	 
	 //copy data section from flash to memory
	 unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA; 
	 
	 
	 unsigned char* P_src = (unsigned char*) _E_text;  
	 unsigned char* P_dst = (unsigned char*) _S_DATA;
	 
	 for(int i=0;i<DATA_size; i++){
		 *((unsigned char*)P_dst++) = *((unsigned char*)P_src++); 
		 /*
		 *P_dst = *P_src;
		 P_src = P_src + (unsigned char*)1 ;
		 P_dst = P_dst + (unsigned char*)1 ;
		 */
	 }
	 // Is both formats the same ??
	 
	 //init .bss section in SRAM =0
	 unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	 
	 	 for(int i=0;i<bss_size; i++){
		 *((unsigned char*)P_dst++) = (unsigned char)0 ; 
		 }		 
	//jump to main
	main(); //Warnning?? --> EXTERN it from the main.c to avoid implicit declaration warninig
 }
 

