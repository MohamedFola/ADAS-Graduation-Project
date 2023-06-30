
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

#include "SPI_private.h"


typedef enum
{
	SPI_Enable,
	SPI_Disable,
}SPI_State_t;

/* SPI used */
typedef enum
{
	SPI1,
	SPI2,
}SPI_Number_t;


typedef enum
{
	SPI_Slave  ,
	SPI_Master ,
}SPI_Mode_t;


/* Clock Phase Options */
typedef enum
{
	SPI_ClkPhase_LeadingEdge  ,
	SPI_ClkPhase_TrailingEdge ,
}SPI_Phase_t;


/* Clock Polarity Options */
typedef enum
{
	SPI_ClkPol_IdleLow  ,
	SPI_ClkPol_IdleHigh ,
}SPI_Polarity_t;


/* Clock Rate Options */
typedef enum
{
	SPI_ClkRateDiv2   ,
	SPI_ClkRateDiv4   ,
	SPI_ClkRateDiv8   ,
	SPI_ClkRateDiv16  ,
	SPI_ClkRateDiv32  ,
	SPI_ClkRateDiv64  ,
	SPI_ClkRateDiv128 ,
	SPI_ClkRateDiv256 ,
}SPI_CLkRate_t;


/* Data Order Options */
typedef enum
{
	SPI_MSBFirst,
	SPI_LSBFirst,
}SPI_DataOrder_t;




typedef struct
{
	SPI_Number_t    SPI_Number    ;
	SPI_Mode_t      SPI_Mode      ;
	SPI_Phase_t     SPI_Phase     ;
	SPI_Polarity_t  SPI_Polartity ;
	SPI_CLkRate_t   SPI_ClkRate   ;
	SPI_DataOrder_t SPI_DataOrder ;
}SPI_t;



SPI_Errors_t SPI_Init ( SPI_t* Ptr_SPI );

SPI_Errors_t SPI_SynchTransceive(
		SPI_Number_t Copy_SPI,
		u8* Ptr_u8DataSend,
		u8* Ptr_u8DataReceived,
		u32 Copy_u32Size
		);

SPI_Errors_t SPI_SynchTransceiveByte(
		SPI_Number_t Copy_SPI,
		u8 Copy_u8DataSend,
		u8* Ptr_u8DataReceived
		);

SPI_Errors_t SPI_State (
		SPI_Number_t Copy_SPI,
		SPI_State_t Copy_u8Status
		);





#endif /* _SPI_INTERFACE_H_ */
