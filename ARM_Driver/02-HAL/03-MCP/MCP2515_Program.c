/*
 *
 * MCP2515_Program.c
 * Created on:
 * Version: 02
 * Author: Eng. Ahmed Abdelshafy
 * 
 */
#include "../../01-MCAL/09-SPI/SPI_Interface.h"
#include "../../../Src/00-LIB/BIT_MATH.h"
#include "../../../Src/00-LIB/STD_TYPES.h"
#include "../../../Src/01-MCAL/09-SPI/SPI_interface.h"
#include "../../../Src/02-HAL/03-MCP/MCP2515_Interface.h"
#include "../../../Src/02-HAL/03-MCP/MCP2515_Private.h"

u8 data2send;
u8 MCP2515_U8ReadRegister(u8 address)
{
	u8 readValue;
	SPI_voidChipSelect(1);
	//	SPI_U8MasterTransmit(INST_READ);
	//	SPI_U8MasterTransmit(address);
	//	readValue = SPI_U8MasterTransmit(0);
	/**********************/
//	data2send=INST_READ;
//	SPI_u8SynchTransceive(SPI1, &data2send,0, 1);
//	data2send=address;
//	SPI_u8SynchTransceive(SPI1,&data2send,0, 1);
	/***********************/
	SPI_u8SynchTransceiveByte(SPI1, INST_READ);
	SPI_u8SynchTransceiveByte(SPI1, address);
	readValue=SPI_u8SynchTransceiveByte(SPI1, 0);
	SPI_voidChipSelect(0);

	return readValue;
}

void MCP2515_VidWriteRegister(u8 address, u8 value)
{
	SPI_voidChipSelect(1);
	//	SPI_U8MasterTransmit(INST_WRITE);
	//	SPI_U8MasterTransmit(address);
	//	SPI_U8MasterTransmit(value);

	SPI_u8SynchTransceiveByte(SPI1, INST_WRITE);
	SPI_u8SynchTransceiveByte(SPI1, address);
	SPI_u8SynchTransceiveByte(SPI1, value);
	SPI_voidChipSelect(0);
}

void MCP2515_VidSetBitTiming(u8 cnf1Value, u8 cnf2Value, u8 cnf3Value)
{
	MCP2515_VidWriteRegister(CNF1, cnf1Value);
	MCP2515_VidWriteRegister(CNF2, cnf2Value);
	MCP2515_VidWriteRegister(CNF3, cnf3Value);
}

void MCP2515_VidReset()
{
	SPI_voidChipSelect(1);
	//	SPI_U8MasterTransmit(INST_RESET);
	SPI_u8SynchTransceiveByte(SPI1, INST_RESET);
	SPI_voidChipSelect(0);
}

void MCP2515_VidChangeBits(u8 RegAddress, u8 Mask, u8 Value)
{
	SPI_voidChipSelect(1);
	//	SPI_U8MasterTransmit(INST_BIT_MODIFY);
	//	SPI_U8MasterTransmit(RegAddress);
	//	SPI_U8MasterTransmit(Mask);
	//	SPI_U8MasterTransmit(Value);
	SPI_u8SynchTransceiveByte(SPI1, INST_BIT_MODIFY);
	SPI_u8SynchTransceiveByte(SPI1, RegAddress);
	SPI_u8SynchTransceiveByte(SPI1, Mask);
	SPI_u8SynchTransceiveByte(SPI1, Value);
	SPI_voidChipSelect(0);
}

void MCP2515_VidSetMode(u8 mode)
{

	MCP2515_VidChangeBits(CANCTRL, 0xE0, mode << 5);
	while((MCP2515_U8ReadRegister(CANSTAT)>>5) != mode );
}


void MCP2515_VidInit(void)
{
	//	SPI_VidMasterInit();
	SPI_t spi ={.SPI_Number=SPI1,.SPI_Mode=SPI_Master,.SPI_Polartity=SPI_ClkPol_IdleHigh,
			.SPI_ClkRate=SPI_ClkRateDiv256,.SPI_DataOrder=SPI_MSBFirst,.SPI_Phase=SPI_ClkPhase_LeadingEdge};
	SPI_Init(&spi);
	MCP2515_VidReset();

	//	// enter configuration mode and enable CLKOUT with no prescaler
	MCP2515_VidWriteRegister(CANCTRL, 0x84);
	while((MCP2515_U8ReadRegister(CANSTAT)>>5) != MCP2515_MODE_CONFG);
	//	// to run at 250KHz bitrate using 8MHz osc
	MCP2515_VidSetBitTiming((2<<6), (1<<7)|(6<<3)|(1), (5));

	MCP2515_VidSetMode(MCP2515_MODE_NORMAL);
}

/********************************TX***************************/
void MCP2515_VidSendCANmsg(u8 bufIdx, u32 msgID, u8 * data,u8 properties)
{
	SPI_voidChipSelect(1);
	/* Send header and address */
	//	SPI_U8MasterTransmit(INST_WRITE);
	//	SPI_U8MasterTransmit(TXB0CTRL);
	SPI_u8SynchTransceiveByte(SPI1, INST_WRITE);
	SPI_u8SynchTransceiveByte(SPI1, TXB0CTRL);

	/* Setup message priority */
	//SPI_U8MasterTransmit(properties >> 6);
	SPI_u8SynchTransceiveByte(SPI1, properties >> 6);
	/* Setup standard or extended identifier */
	//		SPI_U8MasterTransmit((u8)(msgID>>3));
	//		SPI_U8MasterTransmit((u8)(msgID<<5));
	//		SPI_U8MasterTransmit(0);
	//		SPI_U8MasterTransmit(0);
	SPI_u8SynchTransceiveByte(SPI1,(u8)(msgID>>3));
	SPI_u8SynchTransceiveByte(SPI1,(u8)(msgID<<5));
	SPI_u8SynchTransceiveByte(SPI1, 0);
	SPI_u8SynchTransceiveByte(SPI1, 0);


	/* Setup message length and RTR bit */
	//	SPI_U8MasterTransmit((properties & 0x0F);
/************************************/
	//	data2send=(properties & 0x0F);
//	SPI_u8SynchTransceive(SPI1,&data2send,0,8);
/******************************************/
	SPI_u8SynchTransceiveByte(SPI1, properties & 0x0F);

	/* Store the message into the buffer */
	//	for(u8 i = 0; i < (properties & 0x0F); i++)
	//		SPI_U8MasterTransmit(data[i]);
	SPI_u8SynchTransceive(SPI1,data,0,8);


	/* Release the bus */
	SPI_voidChipSelect(0);

	/* Send request to send */
	SPI_voidChipSelect(1);
	//	SPI_U8MasterTransmit(INST_RTS_TXB0);
	SPI_u8SynchTransceiveByte(SPI1, INST_RTS_TXB0);
	SPI_voidChipSelect(0);
}


/****************************RX*******************************/
void MCP2515_VidSetRollover(u8 value)
{
	MCP2515_VidChangeBits(RXB0CTRL, 1<<BUKT, value<<BUKT);
}

void MCP2515_VidSetMask(u8 maskAddress, u32 maskValue, u8 extended)
{
	SPI_voidChipSelect(1);
	//	SPI_U8MasterTransmit(INST_WRITE);
	//	SPI_U8MasterTransmit(maskAddress);
	SPI_u8SynchTransceiveByte(SPI1, INST_WRITE);
	SPI_u8SynchTransceiveByte(SPI1, maskAddress);

	if(extended)
	{
		// extended address
		//		SPI_U8MasterTransmit((u8) (maskValue >> 3));
		//		SPI_U8MasterTransmit((u8) (maskValue << 5) | (1<<3) | (u8) (maskValue >> 27));
		//		SPI_U8MasterTransmit((u8) (maskValue >> 19));
		//		SPI_U8MasterTransmit((u8) (maskValue >> 11));
		SPI_u8SynchTransceiveByte(SPI1, (u8) (maskValue >> 3));
		SPI_u8SynchTransceiveByte(SPI1, (u8) (maskValue << 5) | (1<<3) | (u8) (maskValue >> 27));
		SPI_u8SynchTransceiveByte(SPI1, (u8) (maskValue >> 19));
		SPI_u8SynchTransceiveByte(SPI1, (u8) (maskValue >> 11));
		/***************************************/
//		data2send=(u8) (maskValue >> 3);
//		SPI_u8SynchTransceive(SPI1, &data2send, 0, 1);
//		data2send=((u8) (maskValue << 5) | (1<<3) | (u8) (maskValue >> 27));
//		SPI_u8SynchTransceive(SPI1, &data2send, 0, 1);
//		data2send=(maskValue >> 19);
//		SPI_u8SynchTransceive(SPI1, &data2send ,0, 1);
//		data2send=(maskValue >> 11);
//		SPI_u8SynchTransceive(SPI1, &data2send, 0, 1);
		/*****************************************/
	}
	else
	{
		// standard address
		//		SPI_U8MasterTransmit((u8) (maskValue >> 3));
		//		SPI_U8MasterTransmit((u8) (maskValue << 5));
		SPI_u8SynchTransceiveByte(SPI1, (u8) (maskValue >> 3));
		SPI_u8SynchTransceiveByte(SPI1, (u8) (maskValue << 5));
	}
	SPI_voidChipSelect(0);
}
void MCP2515_VidReceiveInit(void)
{
	SPI_t spi ={.SPI_Number=SPI1,.SPI_Mode=SPI_Master,.SPI_Polartity=SPI_ClkPol_IdleHigh,
			.SPI_ClkRate=SPI_ClkRateDiv256,.SPI_DataOrder=SPI_MSBFirst,.SPI_Phase=SPI_ClkPhase_LeadingEdge};
	SPI_Init(&spi);
	MCP2515_VidReset();

	//	// enter configuration mode and enable CLKOUT with no prescaler
	MCP2515_VidWriteRegister(CANCTRL, 0x84);
	while((MCP2515_U8ReadRegister(CANSTAT)>>5) != MCP2515_MODE_CONFG);
	//	// to run at 250KHz bitrate using 8MHz osc
	MCP2515_VidSetBitTiming((2<<6), (1<<7)|(6<<3)|(1), (5));
	//	MCP2515_VidSetBitTiming(0, 0xAC, 0x03);
	// accept all messages
	MCP2515_VidSetMask(RXM0SIDH, 0x00000000, 1);
	MCP2515_VidSetMask(RXM1SIDH, 0x00000000, 1);
	MCP2515_VidSetRollover(1);

	MCP2515_VidWriteRegister(CANINTE, 1<<RX0IE);

	MCP2515_VidSetMode(MCP2515_MODE_NORMAL);
}

u8 readBuffer[14];
void MCP2515_VidReceiveCANmsg(void)
{
	SPI_voidChipSelect(1);

	//	SPI_U8MasterTransmit(INST_READ);
	//	SPI_U8MasterTransmit(RXB0CTRL);
	SPI_u8SynchTransceiveByte(SPI1, INST_READ);
	SPI_u8SynchTransceiveByte(SPI1, RXB0CTRL);


//	for(u8 i=0; i<14; i++)
		//		readBuffer[i] = SPI_U8MasterTransmit(0);
		SPI_u8SynchTransceive(SPI1, 0,readBuffer, 14);



	SPI_voidChipSelect(0);

	MCP2515_VidWriteRegister(CANINTF, 0);
}
