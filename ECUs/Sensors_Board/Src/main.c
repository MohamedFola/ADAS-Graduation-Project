/*
 * Sensors Board:
 *
 * 		Sensors used:
 * 		1 --> ultrasonic "timer, ultrasonic"
 * 		2 --> can controller "spi, mcp"
 * 		3 --> blue-tooth for debugging purposes
 *
 * 		Drivers included:
 * 		LIB  --> STD types & bit manipulations
 * 		MCAL --> RCC & PORT & DIO & PWM2 & TIM3 & SPI2 & USART1
 * 		HAL  --> encoder & motor & ultra-sonic & mcp2515
 * 		APP  --> PID & communication handler
 *
 * 		port configuration needed:
 * 		SPI1 --> 1) PortA 7 alternative function push-pull
 * 				 2) PortA 6 input floating
 * 				 3) PortA 5 alternative function push-pull
 * 				 4) PortA 4 alternative function push-pull
 *
 * 		USART1 --> 1) PortA 9 alternative function push-pull
 * 				   2) PortA 10 input floating
 * */


/*********** includes ***********/

#include "00-LIB/STD_TYPES.h"
#include "00-LIB/BIT_MATH.h"

#include "01-MCAL/00-RCC/RCC_interface.h"
#include "01-MCAL/01-PORT/PORT_interface.h"
#include "01-MCAL/02-DIO/DIO_interface.h"
#include "01-MCAL/03-STK/STK_interface.h"
#include "01-MCAL/08-TIM/TIM_interface.h"
#include "01-MCAL/09-SPI/SPI_interface.h"
#include "01-MCAL/10-PWM/PWM_interface.h"
#include "01-MCAL/11-USART/USART_interface.h"

#include "02-HAL/00-ENC/ENC_interface.h"
#include "02-HAL/01-ULTRASOINC/ULTRASONIC_interface.h"
#include "02-HAL/02-MOTOR/MOTOR_interface.h"
#include "02-HAL/03-MCP/MCP2515_Interface.h"


#include "03-APP/00-PID/PID.h"
#include "03-APP/01-COMM_HANDLER/CommHandler_interface.h"


#define DISTACNE_MSG_ID  0x771

u32 Current_Time  = 0;
u32 Last_Time     = 0;
u32 Last_Distance = 0;
u32 Distance      = 0;


int main (void)
{
	Tx_t Transmit;

	// Clock init
	RCC_voidInitSysClock();
	RCC_voidEnableClock( RCC_GPIOA  , RCC_APB2 );
	RCC_voidEnableClock( RCC_GPIOB  , RCC_APB2 );
	RCC_voidEnableClock( RCC_GPIOC  , RCC_APB2 );
	RCC_voidEnableClock( RCC_AFIO   , RCC_APB2 );
	RCC_voidEnableClock( RCC_TIM2   , RCC_APB1 );
	RCC_voidEnableClock( RCC_TIM3   , RCC_APB1 );
	RCC_voidEnableClock( RCC_SPI1   , RCC_APB2 );
	RCC_voidEnableClock( RCC_USART1 , RCC_APB2 );

	// port init
	PORT_voidInit();

	// timers init
	MTIM2_voidInit();
	MTIM3_voidInit();


	// usart init
	USART_config_t uart =
	{
			.USART_Number      = USART1                    ,
			.USART_BaudRate    = USART_BaudRate_9600       ,
			.USART_DataLength  = USART_Data8Bits           ,
			.USART_Parity      = USART_EvenParity          ,
			.USART_ParityCheck = USART_ParityCheckDisabled ,
			.USART_StopBits    = USART_1StopBits
	};

	USART_voidInit( &uart );


	// communication init
	//CommHandlerInit( RECIEVE );
	CommHandlerInit( TRANSMIT );


	// ultra-sonic init
	Ultrasonic_t ultra =
	{
			.TrigPort     = MDIO_PORTA ,
			.TrigPin      = MDIO_PIN1  ,
			.Echo_ICU_TIM = TIM2
	};

	HULTRASONIC_voidInit( &ultra );



	/* this struct is used to test the communication
	Tx_t Trans =
	{
			.Data        = 123456 ,
			.DataID      =  0x7E1 ,
			.DataNoBytes = 4      ,
			.DataType    = SPEED
	};*/



	// start the counter to get the reading of the ultra-sonic every 10 milli
	MTIM3_voidStartCounter();

	while(1)
	{



		Current_Time = MTIM3_u16GetRemainingTime();

		if ( ( Current_Time - Last_Time ) >= 1050 )
		{
			Last_Time = MTIM3_u16GetRemainingTime() ;

			HULTRASONIC_voidGetDistance( &ultra , &Distance );

			if( ( Absolute(Last_Distance - Distance ) <= 150 ) || ( Last_Distance == 0 ) )
			{
				Last_Distance = Distance;
			}

			Transmit.Data        = Last_Distance    ;
			Transmit.DataID      = DISTACNE_MSG_ID  ;
			Transmit.DataNoBytes = 4                ;
			Transmit.DataType    = DISTANCE         ;

			CommHandlerSend( &Transmit );

			USART_voidTransmitByteSynch( 'D' , USART1 );
			USART_voidTransmitByteSynch( ':' , USART1 );
			USART_voidSendNumber( Transmit.Data , USART1 );
			USART_voidTransmitByteSynch( '\r' , USART1 );
			USART_voidTransmitByteSynch( '\n' , USART1 );
		}

	}
}

