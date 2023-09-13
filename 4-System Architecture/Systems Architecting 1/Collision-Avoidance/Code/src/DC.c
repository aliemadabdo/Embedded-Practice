
#include "state.h"
#include "DC.h"

int speed;

void DC_init(){
	printf("Initializing DC motor...");
	DC_gpf_nextState = STATE(DC_IDLE);

}

STATE_DEFINE(DC_IDLE){
	DC_state = DC_IDLE;
	DC_set_speed(speed);
	DC_gpf_nextState = STATE(DC_BUSY);
	printf("DC motor Idle State\n");
}

STATE_DEFINE(DC_BUSY){
	DC_state = DC_BUSY;
	DC_gpf_nextState = STATE(DC_IDLE);
	printf("DC motor Busy State\n");

}

void DC_set_speed(int s){
	speed = s;
	DC_gpf_nextState = STATE(DC_BUSY);
	printf("CA-------Set speed = %d------>DC\n", speed);

}
