/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : I2C Driver                            */
/***************************************************************/

/******************************************************************************
                            |      |      |      |
                            ----------------------
1  :    VB                -|                      |-       3.3v           : 40
2  :    PC13              -|                      |-       GND            : 39
3  :    PC14              -|                      |-       5v             : 38
4  :    PC15              -|                      |-       PB9 --> SDA1   : 37
5  :    PA0               -|                      |-       PB8 --> SCL1   : 36
6  :    PA1               -|      STM32F103       |-       PB7 --> SDA1   : 35
7  :    PA2               -|                      |-       PB6 --> SCL1   : 34
8  :    PA3               -|     Based on ARM     |-       PB5            : 33
9  :    PA4               -|                      |-       PB4            : 32
10 :    PA5               -|                      |-       PB3            : 31
11 :    PA6               -|                      |-       PA15           : 30
12 :    PA7               -|                      |-       PA12           : 29
13 :    PB0               -|                      |-       PA11           : 28
14 :    PB1               -|                      |-       PA10           : 27
15 :    PB10 --> SCL2     -|                      |-       PA9            : 26
16 :    PB11 --> SDA2     -|                      |-       PA8            : 25
17 :    R                 -|                      |-       PB15           : 24
18 :    3.3v              -|                      |-       PB14           : 23
19 :    GND               -|                      |-       PB13           : 22
20 :    GND               -|                      |-       PB12           : 21
                            ----------------------
******************************************************************************/



#ifndef _I2C_INTERFACE_H_
#define _I2C_INTERFACE_H_

#include "I2C_private.h"

typedef enum
{
	I2C1,
	I2C2,
	I2C3,
}I2C_t;


I2C_Errors_t I2C_Init ( I2C_t Copy_Number );

I2C_Errors_t I2C_Start ( I2C_t Copy_Number );

I2C_Errors_t I2C_Stop ( I2C_t Copy_Number );

I2C_Errors_t I2C_SendAddress (
		I2C_t Copy_Number    ,
		u8    Copy_u8Address
		);

I2C_Errors_t I2C_SendData (
		I2C_t Copy_Number      ,
		u8*   Copy_u8Data      ,
		u32   Copy_u32DataSize
		);

I2C_Errors_t I2C_Read (
		I2C_t Copy_Number   ,
		u8    Copy_u8Add    ,
		u8*   Copy_u8Buffer ,
		u32   Copy_u32Size
		);



#endif /* _I2C_INTERFACE_H_ */
