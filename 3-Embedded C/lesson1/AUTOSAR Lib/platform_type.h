/*
 * AUTOSAR platform types
 * */

#ifndef PLATFORM_TYPR_
#define PLATFORM_TYPR_

#include <stdbool.h>
//#include <stdint.h>

/* Supporting _Bool in C++ is a GCC extension.  */
#ifndef _Bool
#define _Bool unsigned char
#endif

#define CPU_TYPE CPU_TYPE_32
#define CPU_BIT_ORDER MSB_FIRST
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST

#ifndef FALSE
#define FALSE (boolean)FALSE
#endif

#ifndef TRUE
#define TRUE (boolean)FALSE
#endif

typedef _Bool 						boolean;

typedef signed char 				sint8;
typedef unsigned char 				uint8;
typedef char 						char_t;
typedef short 	        			sint16;
typedef unsigned short  			uint16;
typedef int 						sint32;
typedef unsigned int 				uint32;
typedef long long 					sint64;
typedef unsigned long long 			uint64;

typedef volatile unsigned char 	    vuint8;
typedef volatile signed char 	    vsint8;

typedef volatile unsigned short     vuint16;
typedef volatile short  	   		vsint16;

typedef volatile unsigned int 	    vuint32;
typedef volatile int 	   			vsint32;

typedef volatile unsigned long long vuint64;
typedef volatile long long   		vsint64;

#endif
