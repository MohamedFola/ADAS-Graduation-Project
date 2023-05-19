/*
 *
 * MCP2515_Program.c
 * Created on:
 * Version: 02
 * Author: Eng. Ahmed Abdelshafy
 * 
 */
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "../../01-MCAL/00-RCC/RCC_interface.h"
#include "../../01-MCAL/01-PORT/PORT_interface.h"
#include "../../01-MCAL/02-DIO/DIO_interface.h"
#include "../../01-MCAL/03-STK/STK_interface.h"
#include "../../01-MCAL/04-NVIC/NVIC_interface.h"
#include "../../01-MCAL/05-EXTI/EXTI_interface.h"
#include "../../01-MCAL/06-AFIO/AFIO_interface.h"
#include "../../01-MCAL/07-I2C/I2C_interface.h"
#include "../../01-MCAL/08-TIM/TIM_interface.h"
#include "../../01-MCAL/09-SPI/SPI_interface.h"
#include "../../01-MCAL/10-PWM/PWM_interface.h"

#include "MCP2515_Interface.h"
#include "MCP2515_Private.h"

u8 data2send;
u8 MCP2515_U8ReadRegister(u8 address)
{
	u8 Reading;

	SPI_State( SPI2 , SPI_Enable );
	SPI_SynchTransceiveByte( SPI2, INST_READ, &Reading );
	SPI_SynchTransceiveByte( SPI2, address, &Reading );
	SPI_SynchTransceiveByte( SPI2, 0, &Reading );
	SPI_State( SPI2 , SPI_Disable );

	return Reading;
}


void MCP2515_VidWriteRegister(u8 address, u8 value)
{
	u8 Reading;

	SPI_State( SPI2 , SPI_Enable );
	SPI_SynchTransceiveByte( SPI2 , INST_WRITE , &Reading);
	SPI_SynchTransceiveByte( SPI2 , address , &Reading);
	SPI_SynchTransceiveByte( SPI2 , value , &Reading);
	SPI_State( SPI2, SPI_Disable );
}


void MCP2515_VidSetBitTiming(u8 cnf1Value, u8 cnf2Value, u8 cnf3Value)
{
	MCP2515_VidWriteRegister( CNF1 , cnf1Value );
	MCP2515_VidWriteRegister( CNF2 , cnf2Value );
	MCP2515_VidWriteRegister( CNF3 , cnf3Value );
}


void MCP2515_VidReset()
{
	u8 Reading;

	SPI_State( SPI2 , SPI_Enable);
	SPI_SynchTransceiveByte( SPI2 , INST_RESET , &Reading );
	SPI_State( SPI2 , SPI_Disable );
}


void MCP2515_VidChangeBits(u8 RegAddress, u8 Mask, u8 Value)
{
	u8 Reading;

	SPI_State( SPI2 , SPI_Enable);
	SPI_SynchTransceiveByte( SPI2 , INST_BIT_MODIFY , &Reading );
	SPI_SynchTransceiveByte( SPI2 , RegAddress , &Reading );
	SPI_SynchTransceiveByte( SPI2 , Mask , &Reading);
	SPI_SynchTransceiveByte( SPI2 , Value , &Reading );
	SPI_State( SPI2 , SPI_Disable );
}


void MCP2515_VidSetMode(u8 mode)
{
	MCP2515_VidChangeBits( CANCTRL , 0xE0 , ( mode << 5 ) );
}


void MCP2515_VidInit(void)
{
	//	SPI_VidMasterInit();
	SPI_t spi =
	{
			.SPI_Mode      = SPI_Master,
			.SPI_Number    = SPI2,
			.SPI_Phase     = SPI_ClkPhase_LeadingEdge,
			.SPI_Polartity = SPI_ClkPol_IdleLow,
			.SPI_ClkRate   = SPI_ClkRateDiv4,
			.SPI_DataOrder = SPI_MSBFirst,
	};

	SPI_Init( &spi );

	MCP2515_VidReset();

	//	// enter configuration mode and enable CLKOUT with no prescaler
	MCP2515_VidWriteRegister( CANCTRL , 0x84 );
	//10000100   00000100

	// to run at 250KHz bitrate using 8MHz osc
	MCP2515_VidSetBitTiming( ( 2 << 6 ) , ( 1 << 7 ) | ( 6 << 3 ) | ( 1 ) , ( 5 ) );

	MCP2515_VidSetMode( MCP2515_MODE_NORMAL );
}


/********************************TX***************************/
void MCP2515_VidSendCANmsg(u8 bufIdx, u32 msgID, u8 * data,u8 properties)
{
	u8 Reading;

	SPI_State( SPI2 , SPI_Enable);

	/* Send header and address */
	SPI_SynchTransceiveByte( SPI2 , INST_WRITE , &Reading );
	SPI_SynchTransceiveByte( SPI2 , TXB0CTRL , &Reading );

	/* Setup message priority */
	SPI_SynchTransceiveByte( SPI2 , properties , &Reading );

	/* Setup standard or extended identifier */
	SPI_SynchTransceiveByte( SPI2 , ( u8 )( msgID >> 3 ) , &Reading );
	SPI_SynchTransceiveByte( SPI2 , ( u8 )( msgID << 5 ) , &Reading );
	SPI_SynchTransceiveByte( SPI2 , 0 , &Reading );
	SPI_SynchTransceiveByte( SPI2 , 0 , &Reading );

	/* Setup message length and RTR bit */
	SPI_SynchTransceiveByte( SPI2 , ( properties & 0x0F ) , &Reading );

	/* Store the message into the buffer */
	for( u8 i = 0 ; i < ( properties & 0x0F ) ; i++ )
	{
		SPI_SynchTransceiveByte( SPI2 , data[ i ] , &Reading );
	}

	/* Release the bus */
	SPI_State( SPI2 , SPI_Disable);

	/* Send request to send */
	SPI_State( SPI2 , SPI_Enable);
	SPI_SynchTransceiveByte( SPI2 , INST_RTS_TXB0 , &Reading );
	SPI_State( SPI2 , SPI_Disable);
}


/****************************RX*******************************/
void MCP2515_VidSetRollover(u8 value)
{
	MCP2515_VidChangeBits( RXB0CTRL , ( 1 << BUKT ) , ( value << BUKT ) );
}


void MCP2515_VidSetMask(u8 maskAddress, u32 maskValue, u8 extended)
{
	u8 Reading;

	SPI_State(SPI2, SPI_Enable);
	SPI_SynchTransceiveByte( SPI2 , INST_WRITE , &Reading );
	SPI_SynchTransceiveByte( SPI2 , maskAddress , &Reading );

	if( extended )
	{
		SPI_SynchTransceiveByte( SPI2, ( u8 ) ( maskValue >> 3 ) , &Reading );
		SPI_SynchTransceiveByte( SPI2, ( u8 ) ( maskValue << 5 ) | ( 1 << 3 ) | ( u8 ) ( maskValue >> 27 ) , &Reading );
		SPI_SynchTransceiveByte( SPI2, ( u8 ) ( maskValue >> 19 ) , &Reading );
		SPI_SynchTransceiveByte( SPI2, ( u8 ) ( maskValue >> 11 ) , &Reading );
	}
	else
	{
		// standard address
		SPI_SynchTransceiveByte( SPI2, ( u8 ) ( maskValue >> 3 ) , &Reading );
		SPI_SynchTransceiveByte( SPI2, ( u8 ) ( maskValue << 5 ) , &Reading );
	}

	SPI_State( SPI2, SPI_Disable );
}


void MCP2515_VidReceiveInit(void)
{
	SPI_t spi =
	{
			.SPI_Mode      = SPI_Master,
			.SPI_Number    = SPI2,
			.SPI_Phase     = SPI_ClkPhase_LeadingEdge,
			.SPI_Polartity = SPI_ClkPol_IdleLow,
			.SPI_ClkRate   = SPI_ClkRateDiv4,
			.SPI_DataOrder = SPI_MSBFirst,
	};

	SPI_Init( &spi );

	MCP2515_VidReset();

	//	// enter configuration mode and enable CLKOUT with no prescaler
	MCP2515_VidWriteRegister( CANCTRL, 0x84 );

	//	// to run at 250KHz bitrate using 8MHz osc
	MCP2515_VidSetBitTiming( ( 2 << 6 ) , ( 1 << 7 ) | ( 6 << 3 ) | ( 1 ) , ( 5 ) );
	// accept all messages
	MCP2515_VidSetMask( RXM0SIDH, 0x00000000 , 1 );
	MCP2515_VidSetMask( RXM1SIDH, 0x00000000 , 1 );
	MCP2515_VidSetRollover( 1 );

	MCP2515_VidWriteRegister( CANINTE, ( 1 << RX0IE ) );

	MCP2515_VidSetMode( MCP2515_MODE_NORMAL );
}


u8 readBuffer[14];

void MCP2515_VidReceiveCANmsg(void)
{
	u8 Reading;

	SPI_State(SPI2, SPI_Enable);

	SPI_SynchTransceiveByte( SPI2 , INST_READ , &Reading);
	SPI_SynchTransceiveByte( SPI2 , RXB0CTRL ,  &Reading);


	for( u8 i = 0 ; i < 14 ; i++ )
	{
		SPI_SynchTransceiveByte( SPI2 , 0 , &readBuffer[ i ] );
	}

	SPI_State( SPI2, SPI_Disable );

	MCP2515_VidWriteRegister( CANINTF , 0 );
}
