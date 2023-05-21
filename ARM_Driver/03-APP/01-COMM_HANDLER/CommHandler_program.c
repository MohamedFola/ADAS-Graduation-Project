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

#include "CommHandler_interface.h"


extern u8 readBuffer[];

u32 CommHandlerRxIndication(void){

	u8 dataR[8]={0};
	u8 r;
	u8 DataType = 0;
	u32 Data=0;		//1023
	MDIO_u8ReadChannel( MDIO_PORTA , MDIO_PIN11 , &r );
	if ( r == 0 )
	{
		MCP2515_VidReceiveCANmsg();

		for ( int i = 0 ; i < 8 ; i++ )
		{
			dataR[i] = readBuffer[ 6 + i ];
			//					USART_voidTransmitByteSynch(dataR, USART1);
		}
		//
		//				USART_voidTransmitByteSynch( '\r' , USART1 );
		//				USART_voidTransmitByteSynch( '\n' , USART1 );
	}
	switch(dataR[0]){
	case 1: DataType = DISTANCE; break;
	case 2: DataType = SPEED; 	break;
	case 3: DataType = STEERING; break;
	}

	u32 a=dataR[2];
	u32 b=dataR[3];
	u32 c=b;
	u8 i=3;
	while(i<dataR[1]+2){
		c=b;
		if(c==0){
			a*=10;
		}
		while(b!=0)
		{
			b=b/10;
			a*=10;
		}
		a+=c;
		i++;
		b=dataR[i];
	}
	Data=a;

	return Data;
}

void CommHandlerSend(u32 Copy_u32data , u8 Copy_u8Type, u16 Copy_u8ID){
	u8 Data[8]={0};

	switch(Copy_u8Type){
	case DISTANCE: Data[0] = 1; break;
	case SPEED:    Data[0] = 2; break;
	case STEERING: Data[0] = 3; break;
	}

	u32 a=Copy_u32data;
	u32 b=Copy_u32data;
	u8 counter=5;
	while(b!=0)
	{
		if(counter ==2 && b >9)
		{
			Data[2] = b;
			break;
		}
		else
		{
			b=b/10;//3
			Data[counter]=a%10;
			counter--;
			a=b;
		}
	}
	MCP2515_VidSendCANmsg( 0 , Copy_u8ID , Data , 8 );
}
