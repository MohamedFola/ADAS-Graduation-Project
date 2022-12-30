/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : LIB                                   */
/*             Version : 1                                     */
/*             SWC     : Bit Manipulations                     */                                                                                
/***************************************************************/

/***************************************************************

                    |      |      |      |
                    ----------------------
1  :              -|                      |-              : 40
2  :    PC13      -|                      |-              : 39
3  :    PC14      -|                      |-              : 38
4  :    PC15      -|                      |-       PB9    : 37
5  :              -|                      |-       PB8    : 36
6  :    PA0       -|      STM32F103       |-       PB7    : 35
7  :    PA1       -|                      |-       PB6    : 34
8  :    PA2       -|     Based on ARM     |-       PB5    : 33
9  :    PA3       -|                      |-       PB4    : 32
10 :    PA4       -|                      |-       PB3    : 31
11 :    PA5       -|                      |-       PA15   : 30
12 :    PA6       -|                      |-       PA12   : 29
13 :    PA7       -|                      |-       PA11   : 28
14 :    PB0       -|                      |-       PA10   : 27
15 :    PB1       -|                      |-       PA9    : 26
16 :    PB2       -|                      |-       PA8    : 25
17 :    PB10      -|                      |-       PB15   : 24
18 :              -|                      |-       PB14   : 23
19 :              -|                      |-       PB13   : 22
20 :              -|                      |-       PB12   : 21
                    ----------------------

******************************************************************/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define MASK(Bit)                                        ((1U)<<(Bit))

#define DIGITAL_SET_MODE                                  1
#define DIGITAL_CLR_MODE                                  0


#define SET_BIT(Register, Bit)                           ((Register) |= MASK(Bit))
#define CLR_BIT(Register, Bit)                           ((Register) &= ~MASK(Bit))
#define TOGGLE_BIT(Register, Bit)                        ((Register) ^= MASK(Bit))
#define GET_BIT(Register, Bit)                           (((Register)>>(Bit)) & 0x01)

#define DIGITAL_SET_OR_CLEAR(Register, Bit, Function)    (Register) = ((Register) | MASK(Bit)) & ~(((Function) == 0)<<(Bit))							    

#define IS_HIGH(Register, Bit)                           (((Register)>>(Bit)) & 0x01)
#define IS_LOW(Register, Bit)                           ~(((Register)>>(Bit)) & 0x01)

#define BitManipulationGetBits(Variable, Bits_Offest, Bits_Width) \
((Variable) >> (Bits_Offest)) & (((1U << (Bits_Width)) - 1U))

#define BitManipulationSetBits(Variable, Bits_Offest, Bits_Width, Value) \
(((Variable) & ~(((1U << (Bits_Width)) - 1U) << (Bits_Offest))) | (((Value) & ((1U << (Bits_Width)) - 1U)) << (Bits_Offest)))


#endif /* _BIT_MATH_H_ */
