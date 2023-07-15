/*
 ============================================================================
 Name        : check_uniqu_number.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int map1 = 0, map2 = 0, arr[7] = {4,2,5,2,5,7,4};

	for(int i=0; i<7; i++){

		if ((map2 & (1 << arr[i])) == 0){
			if ((map1 & (1 << arr[i])) == 0)
				map1 = map1 | (1 << arr[i]);
			else
				map2 = map2 | (1 << arr[i]);
		}
	}

	int map3 = map1 ^ map2;

	int unique;
	switch(map3){ //search for the corresponding number of the sited bit
	case(1): unique = 0; break;
	case(2): unique = 1; break;
	case(4): unique = 2; break;
	case(8): unique = 3; break;
	case(16): unique = 4; break;
	case(32): unique = 5; break;
	case(64): unique = 6; break;
	case(128): unique = 7; break;
	case(256): unique = 8; break;
	case(512): unique = 9; break;
	}

	printf("%d", unique);

	return 0;
}
