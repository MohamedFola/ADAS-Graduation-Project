/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : SPI                                   */
/***************************************************************/

/********************************************************************************
                            |      |      |      |
                            ----------------------
1  :    VB                -|                      |-       3.3v            : 40
2  :    PC13              -|                      |-       GND             : 39
3  :    PC14              -|                      |-       5v              : 38
4  :    PC15              -|                      |-       PB9             : 37
5  :    PA0               -|                      |-       PB8             : 36
6  :    PA1               -|      STM32F103       |-       PB7             : 35
7  :    PA2               -|                      |-       PB6             : 34
8  :    PA3               -|     Based on ARM     |-       PB5  --> MOSI1  : 33
9  :    PA4 --> NSS1      -|                      |-       PB4  --> MISO1  : 32
10 :    PA5 --> SCK1      -|                      |-       PB3  --> SCK1   : 31
11 :    PA6 --> MISO1     -|                      |-       PA15 --> NSS1   : 30
12 :    PA7 --> MOSI1     -|                      |-       PA12            : 29
13 :    PB0               -|                      |-       PA11            : 28
14 :    PB1               -|                      |-       PA10            : 27
15 :    PB10              -|                      |-       PA9             : 26
16 :    PB11              -|                      |-       PA8             : 25
17 :    R                 -|                      |-       PB15 --> MOSI2  : 24
18 :    3.3v              -|                      |-       PB14 --> MISO2  : 23
19 :    GND               -|                      |-       PB13 --> SCK2   : 22
20 :    GND               -|                      |-       PB12 --> NSS2   : 21
                            ----------------------
********************************************************************************/

#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_

/* SPI used */
#define SPI_1                           0
#define SPI_2                           1


/* Clock Phase Options */
#define SPI_CLKPH_LEADING_EDGE          0
#define SPI_CLKPH_TRAILING_EDGE         1


/* Clock Polarity Options */
#define SPI_CLKPOL_IDLE_LOW             0
#define SPI_CLKPOL_IDLE_HIGH            1


/* Clock Rate Options */
#define	SPI_CLOCK_RATE_DIV_2            0
#define	SPI_CLOCK_RATE_DIV_4            1
#define	SPI_CLOCK_RATE_DIV_8            2
#define	SPI_CLOCK_RATE_DIV_16           3
#define	SPI_CLOCK_RATE_DIV_32           4
#define	SPI_CLOCK_RATE_DIV_64           5
#define	SPI_CLOCK_RATE_DIV_128          6
#define	SPI_CLOCK_RATE_DIV_256          7


/* Data Order Options */
#define SPI_MSB_FIRST                   0
#define SPI_LSB_FIRST                   1


/****************************************************************************
 * Name        : SPI_u8MasterInit                                           *
 *                                                                          *
 * Return type :                                                            *
 * 		u8 --> Local_u8Error: a variable that stores the error type         *
 *                                                                          *
 * Arguments   :                                                            *
 * 		Copy_u8SPI                                                          *
 * 		Copy_u8DataOrder                                                    *
 * 		Copy_u8ClockPolatrity                                               *
 * 		Copy_u8ClockPhase                                                   *
 * 		Copy_u8ClockRate                                                    *
 * 	                                                                        *
 * Type        : Synchronous                                                *
 *                                                                          *
 * Description :                                                            *
 * 		Initiate the used SPI peripheral by Enabling the RCC and set the    *
 * 		clock, data order, clock phase and polarity and Enabling the        *
 * 		used SPI peripheral                                                 *
 ****************************************************************************/
u8 SPI_u8MasterInit(
		u8 Copy_u8SPI,
		u8 Copy_u8DataOrder,
		u8 Copy_u8ClockPolatrity,
		u8 Copy_u8ClockPhase,
		u8 Copy_u8ClockRate);


/****************************************************************************
 * Name        : SPI_u8SlaveInit                                            *
 *                                                                          *
 * Return type :                                                            *
 * 		u8 --> Local_u8Error: a variable that stores the error type         *
 *                                                                          *
 * Arguments   :                                                            *
 * 		Copy_u8SPI                                                          *
 * 		Copy_u8DataOrder                                                    *
 * 		Copy_u8ClockPolatrity                                               *
 * 		Copy_u8ClockPhase                                                   *
 * 	                                                                        *
 * Type        : Synchronous                                                *
 *                                                                          *
 * Description :                                                            *
 * 		Initiate the used SPI peripheral by Enabling the RCC and set the    *
 * 		clock, data order, clock phase and polarity and Enabling the        *
 * 		used SPI peripheral                                                 *
 ****************************************************************************/
u8 SPI_u8SlaveInit(
		u8 Copy_u8SPI,
		u8 Copy_u8DataOrder,
		u8 Copy_u8ClockPolatrity,
		u8 Copy_u8ClockPhase);



/****************************************************************************
 * Name        : SPI_u8SynchTransceive                                      *
 *                                                                          *
 * Return type :                                                            *
 * 		u8 --> Received Data                                                *
 *                                                                          *
 * Arguments   :                                                            *
 * 		Copy_u8SPI                                                          *
 * 		Copy_u8Data                                                         *
 * 		                                                                    *
 * Type        : Synchronous                                                *
 *                                                                          *
 * Description :                                                            *
 * 		Sends and Receives one data Byte                                    *
 ****************************************************************************/
u8 SPI_u8SynchTransceive( u8 Copy_u8SPI, u8 Copy_u8Data );



/****************************************************************************
 * Name        : SPI_u8SynchTransceiveString                                *
 *                                                                          *
 * Return type :                                                            *
 * 		u8* --> Received String                                             *
 *                                                                          *
 * Arguments   :                                                            *
 * 		Copy_u8SPI                                                          *
 * 		Copy_pu8String                                                      *
 * 		                                                                    *
 * Type        : Synchronous                                                *
 *                                                                          *
 * Description :                                                            *
 * 		Sends and Receives whole String                                     *
 ****************************************************************************/
u8* SPI_u8SynchTransceiveString( u8 Copy_u8SPI, u8* Copy_pu8String );


#endif /* _SPI_INTERFACE_H_ */
