/*********************************************************************************************************/
/************************************    Author:Mohab Ahmed    	      ************************************/
/************************************		Layer:MCAL            ************************************/
/************************************   	SWC:USART             ************************************/
/************************************		Version:1.00          ************************************/
/*********************************************************************************************************/



/********************************************************************************
                            |      |      |      |
                            ----------------------
1  :    VB                -|                      |-       3.3v            : 40
2  :    PC13              -|                      |-       GND             : 39
3  :    PC14              -|                      |-       5v              : 38
4  :    PC15              -|                      |-       PB9             : 37
5  :    PA0               -|                      |-       PB8             : 36
6  :    PA1               -|      STM32F103       |-       PB7  -->RX1     : 35
7  :    PA2   -->TX2   	  -|                      |-       PB6  -->TX1     : 34
8  :    PA3   -->RX2      -|     Based on ARM     |-       PB5  	   : 33
9  :    PA4 		  -|                      |-       PB4             : 32
10 :    PA5 	          -|                      |-       PB3             : 31
11 :    PA6 	          -|                      |-       PA15            : 30
12 :    PA7 		  -|                      |-       PA12            : 29
13 :    PB0               -|                      |-       PA11            : 28
14 :    PB1               -|                      |-       PA10 -->RX1     : 27
15 :    PB10  -->TX3      -|                      |-       PA9  -->TX1     : 26
16 :    PB11  -->RX3      -|                      |-       PA8             : 25
17 :    R                 -|                      |-       PB15 	   : 24
18 :    3.3v              -|                      |-       PB14            : 23
19 :    GND               -|                      |-       PB13            : 22
20 :    GND               -|                      |-       PB12            : 21
                            ----------------------
********************************************************************************/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_



typedef enum
{
	USART1,USART2,USART3
}USART_Num_t;

typedef enum
{
	USART_BaudRate_2400 	=2400,
	USART_BaudRate_9600 	=9600,
	USART_BaudRate_19200 	=19200,
	USART_BaudRate_57600 	=57600,
	USART_BaudRate_115200 	=115200,
	USART_BaudRate_230400 	= 230400,
	USART_BaudRate_460800 	= 460800,
	USART_BaudRate_921600 	= 921600,
	USART_BaudRate_2250000 	= 2250000,
	USART_BaudRate_4500000 	= 4500000
}USART_BaudRate_t;

typedef enum
{
	USART_EvenParity,
	USART_OddParity
}USART_Parity_t;

typedef enum
{
	USART_Data8Bits,
	USART_Data9Bits
}USART_DataLength_t;

typedef enum
{
	USART_halfStopBit,
	USART_1StopBits,
	USART_2StopBits,
	USART_three_halfsStopBits
}USART_StopBits_t;

typedef enum
{
	USART_ParityCheckEnabled,
	USART_ParityCheckDisabled
}USART_ParityCheck_t;

typedef struct
{
	USART_Num_t 	 	USART_Number;
	USART_BaudRate_t 	USART_BaudRate;
	USART_DataLength_t	USART_DataLength;
	USART_Parity_t	    USART_Parity;
	USART_StopBits_t	USART_StopBits;
	USART_ParityCheck_t USART_ParityCheck;

}USART_config_t;

/************************************************************/
void USART_voidInit(USART_config_t * USART_ptr);

void USART_voidTransmitByteSynch(u8	Local_u8Byte , USART_Num_t USART_Number );
u8 USART_voidReceiveByteSynch( USART_Num_t USART_Number);

void  USART_voidSendArrSynch(u8 * Copy_ptr_u8_TXArr, u8 Copy_u8ArrSize, USART_Num_t Copy_USARTNumber);
void  USART_voidReceiveArrSynch(u8 * Copy_ptr_u8_RXArr,u8 Copy_u8ArrSize, USART_Num_t Copy_USARTNumber);

void  USART_voidSendNumber(s32 Copy_s32Number, USART_Num_t Copy_USARTNumber);
/*************************************************************/



#endif /* USART_INTERFACE_H_ */
