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

#define I2C_1      0
#define I2C_2      1

/* these number are calculated for 36MHz clock on APB bus */
#define I2C_SM     0xB4   /* standard mode */
#define I2C_FM     0x2D   /* fast mode */

#define I2C_WRITE_OPERATION   0
#define I2C_READ_OPERATION    1


/****************************************************************************
 * Name        : I2C_u8Init                                                 *
 *                                                                          *
 * Return type :                                                            *
 * 		u8 --> Local_u8Error: a variable that stores the error type         *
 *                                                                          *
 * Arguments   :                                                            *
 * 		Copy_u8I2C      --> The used I2C peripheral                         *
 * 		Copy_u8I2CSpeed --> Clock speed of I2C                              *
 * 	                                                                        *
 * Type        : Synchronous                                                *
 *                                                                          *
 * description :                                                            *
 * 		Initiate the used I2C peripheral by Enabling the RCC and set the    *
 * 		clock and Enabling the used I2C peripheral                          *
 ****************************************************************************/
u8 I2C_u8Init(u8 Copy_u8I2C, u8 Copy_u8I2CSpeed);


/****************************************************************************
 * Name        : I2C_voidStart                                              *
 *                                                                          *
 * Return type : void                                                       *
 *                                                                          *
 * Arguments   :                                                            *
 * 		Copy_u8I2C --> the used I2C peripheral                              *
 * 	                                                                        *
 * Type        : Synchronous                                                *
 *                                                                          *
 * description : Send start condition to start data transfer                *
 ****************************************************************************/
void I2C_voidStart( u8 Copy_u8I2C );


/****************************************************************************
 * Name        : I2C_voidWriteAddress                                       *
 *                                                                          *
 * Return type : void                                                       *
 *                                                                          *
 * Arguments   :                                                            *
 * 		Copy_u8I2C       --> The used I2C peripheral                        *
 * 		Copy_u8Add       --> Address of the slave                           *
 * 		Copy_u8Operation --> Read or Write operation                        *
 * 	                                                                        *
 * Type        : Synchronous                                                *
 *                                                                          *
 * description :                                                            *
 * 		Send address on the bus to start communication with this slave      *
 ****************************************************************************/
void I2C_voidWriteAddress( u8 Copy_u8I2C, u8 Copy_u8Add, u8 Copy_u8Operation );


/****************************************************************************
 * Name        : I2C_voidWriteByte                                          *
 *                                                                          *
 * Return type : void                                                       *
 *                                                                          *
 * Arguments   :                                                            *
 * 		Copy_u8I2C  --> The used I2C peripheral                             *
 * 		Copy_u8Data --> Data to be transfered to the slave                  *
 * 	                                                                        *
 * Type        : Synchronous                                                *
 *                                                                          *
 * description : Send data to the slave                                     *
 ****************************************************************************/
void I2C_voidWriteByte( u8 Copy_u8I2C, u8 Copy_u8Data );


/****************************************************************************
 * Name        : I2C_voidWriteMultiBytes                                    *
 *                                                                          *
 * Return type : void                                                       *
 *                                                                          *
 * Arguments   :                                                            *
 * 		Copy_u8I2C  --> The used I2C peripheral                             *
 * 		Copy_u8Data --> Data to be transfered to the slave                  *
 * 		Copy_u8Size --> Size of the data to be transfered to the slave      *
 * 	                                                                        *
 * Type        : Synchronous                                                *
 *                                                                          *
 * description : Send multiple bytes to the slave                           *
 ****************************************************************************/
void I2C_voidWriteMultiBytes( u8 Copy_u8I2C, u8* Copy_u8Data, u8 Copy_u8Size );


/****************************************************************************
 * Name        : I2C_voidStop                                               *
 *                                                                          *
 * Return type : void                                                       *
 *                                                                          *
 * Arguments   :                                                            *
 * 		Copy_u8I2C --> the used I2C peripheral                              *
 * 	                                                                        *
 * Type        : Synchronous                                                *
 *                                                                          *
 * description : Send stop condition to stop communication with the slave   *
 ****************************************************************************/
void I2C_voidStop( u8 Copy_u8I2C );


/****************************************************************************
 * Name        : I2C_voidRead                                               *
 *                                                                          *
 * Return type : void                                                       *
 *                                                                          *
 * Arguments   :                                                            *
 * 		Copy_u8I2C    --> the used I2C peripheral                           *
 * 		Copy_u8Add    --> Address of the slave                              *
 * 		Copy_u8Buffer --> Buffer to receive data at it                      *
 * 		Copy_u8Size   --> Size of the data to be received from the slave    *
 * 	                                                                        *
 * Type        : Synchronous                                                *
 *                                                                          *
 * description : Read one or multiple bytes from the slave                  *
 ****************************************************************************/
void I2C_voidRead( u8 Copy_u8I2C, u8 Copy_u8Add, u8* Copy_u8Buffer, u8 Copy_u8Size );


#endif /* _I2C_INTERFACE_H_ */
