
/*********** includes ***********/

#include "00-LIB/STD_TYPES.h"
#include "00-LIB/BIT_MATH.h"

#include "01-MCAL/00-RCC/RCC_interface.h"
#include "01-MCAL/01-PORT/PORT_interface.h"
#include "01-MCAL/02-DIO/DIO_interface.h"
#include "01-MCAL/03-STK/STK_interface.h"
#include "01-MCAL/04-NVIC/NVIC_interface.h"
#include "01-MCAL/05-EXTI/EXTI_interface.h"
#include "01-MCAL/06-AFIO/AFIO_interface.h"
#include "01-MCAL/08-TIM/TIM_interface.h"
#include "01-MCAL/09-SPI/SPI_interface.h"
#include "01-MCAL/11-USART/USART_interface.h"


#include "02-HAL/03-MCP/MCP2515_Interface.h"


#include "03-APP/01-COMM_HANDLER/CommHandler_interface.h"


#define DISTANCE_MSG_ID    0x771


u32 Current_Time  = 0;
u32 Last_Time     = 0;
u32 Last_Distance = 0;
u32 Distance      = 0;


int main (void)
{
	Rx_t First_Distance;
	Rx_t Second_Distance;

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



	/* this struct is used to test the communication */
	Tx_t Transmit =
	{
			.Data        = 123456 ,
			.DataID      = 0x7E1  ,
			.DataNoBytes = 4      ,
			.DataType    = SPEED
	};



	// start the counter to get the reading of the ultra-sonic every 10 milli
	MTIM3_voidStartCounter();

	while(1)
	{
		CommHandlerInit( ECU_TRANSMIT );

		MTIM2_voidSetBusyWait(1000);

		CommHandlerInit( ECU_RECIEVE );

		//		First_Distance = CommHandlerRxIndication();
		//		MTIM2_voidSetBusyWait( 100 );
		//		Second_Distance = CommHandlerRxIndication();

		First_Distance = CommHandlerRxIndication();


		USART_voidTransmitByteSynch( 'D'   , USART1 );
		USART_voidTransmitByteSynch( ':'   , USART1 );
		USART_voidSendNumber( First_Distance.Data , USART1 );
		USART_voidTransmitByteSynch( '\r'  , USART1 );
		USART_voidTransmitByteSynch( '\n'  , USART1 );

		USART_voidTransmitByteSynch( 'T'       , USART1 );
		USART_voidTransmitByteSynch( ':'       , USART1 );
		USART_voidSendNumber( First_Distance.DataType , USART1 );
		USART_voidTransmitByteSynch( '\r'      , USART1 );
		USART_voidTransmitByteSynch( '\n'      , USART1 );

		MTIM2_voidSetBusyWait(1000);

		//		Current_Time = MTIM3_u16GetRemainingTime();
		//
		//		if ( ( Current_Time - Last_Time ) >= 1050 )
		//		{
		//			Last_Time = MTIM3_u16GetRemainingTime() ;
		//
		//			if( ( Absolute( Last_Distance - Distance ) <= 150 ) || ( Last_Distance == 0 ) )
		//			{
		//				Last_Distance = Distance;
		//			}
		//
		//
		//
		//		}
	}
}

