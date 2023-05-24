#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/Software_Delay.h"

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
#include "../../01-MCAL/11-USART/USART_interface.h"

#include "../../02-HAL/00-ENC/ENC_interface.h"
#include "../../02-HAL/01-ULTRASOINC/ULTRASONIC_interface.h"
#include "../../02-HAL/02-MOTOR/MOTOR_interface.h"
#include "../../02-HAL/03-MCP/MCP2515_Interface.h"

#include "CommHandler_interface.h"


extern u8 readBuffer[];


void CommHandlerInit(void)
{

#if ECU_STATE == TRANSMIT
	MCP2515_VidInit();
#elif	ECU_STATE == RECIEVE
	MCP2515_VidReceiveInit();
#else
#error ("Wrong ECU State")
#endif
}

Rx_t CommHandlerRxIndication(void){

	Rx_t DataRx ;

	u8 dataR[8]={0};
	u8 r;
	u8 DataType = 0;
	u32 Data=0;		//1023
	/******************************************************************************************/
	/* 		Data Receiving from the CAN	controller	  */
	MDIO_u8ReadChannel( MDIO_PORTA , MDIO_PIN11 , &r );
	if ( r == 0 )
	{
		MCP2515_VidReceiveCANmsg();

				for ( int i = 0 ; i < 8 ; i++ )
				{
					dataR[i] = readBuffer[ 6 + i ];
				}


						USART_voidTransmitByteSynch( '\r' , USART1 );
						USART_voidTransmitByteSynch( '\n' , USART1 );
	}
	/********************************************/
	/* 		Data ID  check		*/
	switch(dataR[0]){

	case 1: DataType = DISTANCE; break;
	case 2: DataType = SPEED; 	break;
	case 3: DataType = STEERING; break;
	default:DataType = INVALID_TYPE;

	}
	/********************************************/
	/*  	Data Parsing	 */
	u8 DataLength 	  =  dataR[1] ;
	u32 SummedNumber  =  dataR[2];
	u32 Temp 		  =  dataR[3];
	u32 TargetNumber  =  Temp;

	u8 i=3;
	while( i < DataLength + 2)
	{
		TargetNumber=Temp;

		if(TargetNumber==0)
		{
			SummedNumber*=10;
		}

		while(Temp!=0)
		{
			Temp = Temp / 10;
			SummedNumber *= 10;
		}

		SummedNumber += TargetNumber;
		i++;
		Temp=dataR[i];
	}
	Data = SummedNumber;
	/**********************************************/
	DataRx.Data 	= Data;
	DataRx.DataType = DataType;

//	USART_voidSendNumber(Data, USART1);
//	USART_voidTransmitByteSynch('\r', USART1);
//	USART_voidTransmitByteSynch('\n', USART1);
//	USART_voidTransmitByteSynch('D', USART1);
//	USART_voidSendNumber(DataType, USART1);
//	USART_voidTransmitByteSynch('\r', USART1);
//	USART_voidTransmitByteSynch('\n', USART1);

	return DataRx;
}

void CommHandlerSend(Tx_t* Tx)

{
	u8 Data[8]={0};

	/*				Entering the ID in the first Array element				*/
	switch(Tx -> DataType)
	{
	case DISTANCE: Data[0] = 1; break;
	case SPEED:    Data[0] = 2; break;
	case STEERING: Data[0] = 3; break;
	}
	Data[1]= Tx -> DataNoBytes ;


if(Tx -> DataNoBytes > 4)
{
	Tx -> DataNoBytes = 4;
}

	u32 Element2Send = Tx -> Data;
	u32 Temp=Element2Send;
	u8 counter= Tx -> DataNoBytes + 1 ;


	/*				Entering the Data Elements in the Array				*/
	while(Temp!=0)
	{
		if(counter == 2 && Temp > 9 )
		{
			Data[2] = Temp;
			break;
		}
		else
		{
			Temp = Temp / 10;
			Data[counter] = Element2Send % 10;
			counter-- ;
			Element2Send = Temp;
		}
	}

	MCP2515_VidSendCANmsg( 0 , Tx -> DataID , Data , 8 );
}
