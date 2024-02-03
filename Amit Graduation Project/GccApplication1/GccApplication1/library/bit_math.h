#ifndef _bit_math_h_
#define _bit_math_h

#define SET_BIT(reg, bit_num) (reg|=(1<<bit_num))
#define CLEAR_BIT(reg, bit_num) (reg&=~(1<<bit_num))
#define CHECK_BIT(reg, bit_num) ((reg>>bit_num)&1)
#define FLIP_BIT(reg, bit_num) (reg^=(1<<bit_num))

#endif