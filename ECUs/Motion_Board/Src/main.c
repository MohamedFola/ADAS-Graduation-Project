/*
 * Motion Board:
 *
 * 		Sensors used:
 * 		1 --> can controller --> SPI2
 * 		2 --> encoders --> TIM2
 *
 * */


/*********** includes ***********/

#include "00-LIB/STD_TYPES.h"
#include "00-LIB/BIT_MATH.h"

#include "01-MCAL/00-RCC/RCC_interface.h"
#include "01-MCAL/01-PORT/PORT_interface.h"
#include "01-MCAL/02-DIO/DIO_interface.h"
#include "01-MCAL/03-STK/STK_interface.h"
#include "01-MCAL/04-NVIC/NVIC_interface.h"
#include "01-MCAL/05-EXTI/EXTI_interface.h"
#include "01-MCAL/08-TIM/TIM_interface.h"
#include "01-MCAL/09-SPI/SPI_interface.h"
#include "01-MCAL/10-PWM/PWM_interface.h"
#include "01-MCAL/11-USART/USART_interface.h"

#include "02-HAL/00-ENC/ENC_interface.h"
#include "02-HAL/02-MOTOR/MOTOR_interface.h"
#include "02-HAL/03-MCP/MCP2515_Interface.h"

#include "03-APP/00-PID/PID.h"
#include "03-APP/01-COMM_HANDLER/CommHandler_interface.h"


#define MOTOR_STOP 0

#define ERRORSIZE 5
u8 ErrorMsg[ ERRORSIZE ] = "Error";



int main (void)
{
	/******************************************/
	/**** variable used to store the speed ****/
	/******************************************/
	u8 Speed = 50;
	u8 softSpeed = 50;


	/*****************************************************************/
	/**** variable to receive the message from the can controller ****/
	/*****************************************************************/
	Rx_t Receive;


	/***************************/
	/**** motor init struct ****/
	/***************************/
	MOTOR_t Motor =
	{
			.MOTOR_PORT = MDIO_PORTA ,
			.L_DIR_PIN  = MDIO_PIN0  ,
			.R_DIR_PIN  = MDIO_PIN2  ,
			.L_PWM_PIN  = MDIO_PIN1  ,
			.R_PWM_PIN  = MDIO_PIN3
	};


	/********************/
	/**** Clock init ****/
	/********************/
	RCC_voidInitSysClock();
	RCC_voidEnableClock( RCC_GPIOA  , RCC_APB2 );
	RCC_voidEnableClock( RCC_GPIOB  , RCC_APB2 );
	RCC_voidEnableClock( RCC_GPIOC  , RCC_APB2 );
	RCC_voidEnableClock( RCC_TIM2   , RCC_APB1 );
	RCC_voidEnableClock( RCC_TIM3   , RCC_APB1 );
	RCC_voidEnableClock( RCC_SPI2   , RCC_APB1 );
	RCC_voidEnableClock( RCC_USART1 , RCC_APB2 );

	/*******************/
	/**** port init ****/
	/*******************/
	PORT_voidInit();

	/*********************/
	/**** timers init ****/
	/*********************/
	MTIM2_voidInit();
	MTIM3_voidInit();
	MPWM2_voidInit();

	/***************************/
	/**** usart init struct ****/
	/***************************/
	USART_config_t uart =
	{
			.USART_Number      = USART1                    ,
			.USART_BaudRate    = USART_BaudRate_9600       ,
			.USART_DataLength  = USART_Data8Bits           ,
			.USART_Parity      = USART_EvenParity          ,
			.USART_ParityCheck = USART_ParityCheckDisabled ,
			.USART_StopBits    = USART_1StopBits
	};

	/********************/
	/**** usart init ****/
	/********************/
	USART_voidInit( &uart );


	/****************************/
	/**** communication init ****/
	/****************************/
	CommHandlerInit();


	while(1)
	{
		Receive = CommHandlerRxIndication();


//		if( Receive.Data <= 250 )
//		{
//			// normal stop
//			//			MOTOR_voidMove( &Motor , MOTOR_FORWARD , ( MOTOR_STOP ) , ( MOTOR_STOP ) );
//
//			// soft stop
//			if ( softSpeed >= 0 )
//			{
//				softSpeed = ( softSpeed * 0.8 ) - ( 5 * 0.2 );
//				MOTOR_voidMove( &Motor , MOTOR_FORWARD , ( softSpeed ) , ( softSpeed ) );
//			}
//			else
//			{
//				softSpeed = 0;
//				MOTOR_voidMove( &Motor , MOTOR_FORWARD , ( softSpeed ) , ( softSpeed ) );
//			}
//
//
//			USART_voidTransmitByteSynch( 'D'   , USART1 );
//			USART_voidTransmitByteSynch( ':'   , USART1 );
//			USART_voidSendNumber( Receive.Data , USART1 );
//			USART_voidTransmitByteSynch( '\r'  , USART1 );
//			USART_voidTransmitByteSynch( '\n'  , USART1 );
//
//			USART_voidTransmitByteSynch( 'T'       , USART1 );
//			USART_voidTransmitByteSynch( ':'       , USART1 );
//			USART_voidSendNumber( Receive.DataType , USART1 );
//			USART_voidTransmitByteSynch( '\r'      , USART1 );
//			USART_voidTransmitByteSynch( '\n'      , USART1 );
//		}
//		else
//		{
//			//			softSpeed = 50;
//			USART_voidSendArrSynch( ErrorMsg , ERRORSIZE , USART1 );
//			MOTOR_voidMove( &Motor , MOTOR_FORWARD , ( Speed ) , ( Speed ) );
//		}


		USART_voidTransmitByteSynch( 'D'   , USART1 );
		USART_voidTransmitByteSynch( ':'   , USART1 );
		USART_voidSendNumber( Receive.Data , USART1 );
		USART_voidTransmitByteSynch( '\r'  , USART1 );
		USART_voidTransmitByteSynch( '\n'  , USART1 );

		USART_voidTransmitByteSynch( 'T'       , USART1 );
		USART_voidTransmitByteSynch( ':'       , USART1 );
		USART_voidSendNumber( Receive.DataType , USART1 );
		USART_voidTransmitByteSynch( '\r'      , USART1 );
		USART_voidTransmitByteSynch( '\n'      , USART1 );

		MTIM3_voidSetBusyWait( 2000 );
	}
}

