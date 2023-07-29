/*
Learn 

*/

#define SYSCL_RCG2_R *((volatile unsigned long*)0x400FE108)
#define GPIO_PORTF_DIR_R *((volatile unsigned long*)0x40025400)
#define GPIO_PORTF_DEN_R *((volatile unsigned long*)0x4002551C)
#define GPIO_PORTF_DATA_R *((volatile unsigned long*)0x400253FC)

int main()
{
	volatile unsigned long i;
	SYSCL_RCG2_R = 0x21;
	//delay to make sure that GPIOF is up and running
	
	//take care that this line without volatile will be removed by optemizer
	for(i=0; i<200; i++);
	
	GPIO_PORTF_DIR_R |= 1<<3 ; //set the direction of pin3 in port f as output 
	GPIO_PORTF_DEN_R |= 1<<3; // enable portf pin3

	while(1){
		GPIO_PORTF_DATA_R |= 1<<3;
		for(i=0; i<1000; i++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(i=0; i<1000; i++);
	}
	
	return 0;
}