#include "00-LIB/STD_TYPES.h"
#include "00-LIB/BIT_MATH.h"
#include "00-LIB/Software_Delay.h"

#include "01-MCAL/00-RCC/RCC_interface.h"
#include "01-MCAL/01-PORT/PORT_interface.h"
#include "01-MCAL/02-DIO/DIO_interface.h"
#include "01-MCAL/03-STK/STK_interface.h"
#include "01-MCAL/04-NVIC/NVIC_interface.h"
#include "01-MCAL/05-EXTI/EXTI_interface.h"
#include "01-MCAL/06-AFIO/AFIO_interface.h"
#include "01-MCAL/07-I2C/I2C_interface.h"
#include "01-MCAL/08-TIM/TIM_interface.h"
#include "01-MCAL/09-SPI/SPI_interface.h"
#include "01-MCAL/10-PWM/PWM_interface.h"
#include "01-MCAL/11-USART/USART_interface.h"

#include "02-HAL/00-ENC/ENC_interface.h"
#include "02-HAL/01-ULTRASOINC/ULTRASONIC_interface.h"
#include "02-HAL/02-MOTOR/MOTOR_interface.h"
#include "02-HAL/03-MCP/MCP2515_Interface.h"

extern u8 readBuffer[];

#define Spi_data_counter   4


int main ( void )
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock( RCC_GPIOA, RCC_APB2 );
	RCC_voidEnableClock( RCC_GPIOB, RCC_APB2 );
	RCC_voidEnableClock( RCC_GPIOC, RCC_APB2 );

	RCC_voidEnableClock( RCC_I2C1, RCC_APB1 );
	RCC_voidEnableClock( RCC_I2C2, RCC_APB1 );

	RCC_voidEnableClock( RCC_SPI1, RCC_APB2 );
	RCC_voidEnableClock( RCC_SPI2, RCC_APB1 );

	RCC_voidEnableClock( RCC_AFIO, RCC_APB2 );

	RCC_voidEnableClock( RCC_USART1, RCC_APB2 );

	PORT_voidInit();

//	setremap();

	//	u8 data[Spi_data_counter] =
	//	{
	//		0xab,
	//		0xba,
	//		0xcf,
	//		0x55
	//	};
	//
	//	u8 a[Spi_data_counter];

	u8 data = 0x54;
	u8 a;
	u8 Data1[ 8 ] = { 'M', 'o', 'h', 'a' , 'o', 'o', 'o', 'o' };
	u8 Data2[ 8 ] = { 'B', 'O', 'L', 'B' , 'O', 'L', 'L', 'L' };

	//	I2C_Init( I2C1 );


	u8 dataR;
	u8 r;

	USART_config_t uart =
	{
			.USART_BaudRate = USART_BaudRate_9600 ,
			.USART_DataLength = USART_Data8Bits ,
			.USART_Number = USART1,
			.USART_Parity = USART_EvenParity,
			.USART_ParityCheck = USART_ParityCheckDisabled,
			.USART_StopBits = USART_1StopBits
	};


	USART_voidInit( &uart );

	MCP2515_VidReceiveInit();

//	MCP2515_VidInit();

//	SPI_t spi =
//	{
//			.SPI_Mode      = SPI_Master,
//			.SPI_Number    = SPI1,
//			.SPI_Phase     = SPI_ClkPhase_LeadingEdge,
//			.SPI_Polartity = SPI_ClkPol_IdleLow,
//			.SPI_ClkRate   = SPI_ClkRateDiv4,
//			.SPI_DataOrder = SPI_MSBFirst,
//	};
//
//	SPI_Init( &spi );

	while ( 1 )
	{
//
//		MCP2515_VidSendCANmsg( 0 , 0x7E1 , Data1 , 8 );
//		MSTK_voidSetBusyWait( 10000 );
//
//		MCP2515_VidSendCANmsg( 0 , 0x771 , Data2 , 8 );
//		MSTK_voidSetBusyWait( 10000 );

//		SPI_State( SPI1 , SPI_Enable );
//		SPI_SynchTransceiveByte( SPI1 , 0x55 , &r );
//		SPI_State( SPI1 , SPI_Disable );

		//		I2C_Start( I2C1 );
		//		I2C_SendAddress( I2C1, 0x4E );
		//		I2C_SendData( I2C1, &(t), 1 );
		//		I2C_Stop( I2C1 );

		//		SPI_State( SPI1 , SPI_Enable );
		//		SPI_SynchTransceiveByte( SPI1 , data , &a );
		//		SPI_State( SPI1 , SPI_Disable );

		//		MCP2515_U8ReadRegister( 0x55 );
		//		MCP2515_VidWriteRegister( 0x10 , 0x11 );
		//		MCP2515_VidSetBitTiming(0x20, 0x21, 0x22);
		//		MCP2515_VidReset();
		//		MCP2515_VidChangeBits( 0x30, 0x31, 0x32 );
		//		MCP2515_VidSendCANmsg( 0 , 0x7E1 , Data , 8 );
		//
		MDIO_u8ReadChannel( MDIO_PORTA , MDIO_PIN11 , &r );


		if ( r == 0 )
		{
			MCP2515_VidReceiveCANmsg();

			for ( int i = 0 ; i < 8 ; i++ )
			{
				dataR = readBuffer[ 6 + i ];
				USART_voidTransmitByteSynch(dataR, USART1);
			}

			USART_voidTransmitByteSynch( '\r' , USART1 );
			USART_voidTransmitByteSynch( '\n' , USART1 );
		}
    MSTK_voidSetBusyWait( 1000000 );
		////
		//		USART_voidTransmitByteSynch( 'a'  , USART1 );
		//		USART_voidTransmitByteSynch( '\r' , USART1 );
		//		USART_voidTransmitByteSynch( '\n' , USART1 );
	}
}
