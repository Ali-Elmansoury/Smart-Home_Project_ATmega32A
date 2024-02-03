#ifndef _std_types_h_
#define _std_types_h_

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned long u32;
typedef signed long s32;

typedef float f32;
typedef double f64;

typedef enum {
	FALSE,
	TRUE
} boolean;

typedef enum {
	OK,
	NOK
} std_returnStatus;

#endif