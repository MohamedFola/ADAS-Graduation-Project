/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : LIB                                   */
/*             Version : 1                                     */
/*             SWC     : Bit Manipulations                     */                                                                                
/***************************************************************/

/***************************************************************

                    |      |      |      |
                    ----------------------
1  :    VB        -|                      |-       3.3v   : 40
2  :    PC13      -|                      |-       GND    : 39
3  :    PC14      -|                      |-       5v     : 38
4  :    PC15      -|                      |-       PB9    : 37
5  :    PA0       -|                      |-       PB8    : 36
6  :    PA1       -|      STM32F103       |-       PB7    : 35
7  :    PA2       -|                      |-       PB6    : 34
8  :    PA3       -|     Based on ARM     |-       PB5    : 33
9  :    PA4       -|                      |-       PB4    : 32
10 :    PA5       -|                      |-       PB3    : 31
11 :    PA6       -|                      |-       PA15   : 30
12 :    PA7       -|                      |-       PA12   : 29
13 :    PB0       -|                      |-       PA11   : 28
14 :    PB1       -|                      |-       PA10   : 27
15 :    PB10      -|                      |-       PA9    : 26
16 :    PB11      -|                      |-       PA8    : 25
17 :    R         -|                      |-       PB15   : 24
18 :    3.3v      -|                      |-       PB14   : 23
19 :    GND       -|                      |-       PB13   : 22
20 :    GND       -|                      |-       PB12   : 21
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
