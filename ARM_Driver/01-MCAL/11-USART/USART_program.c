/*****************************************************************************************************/
/************************************    Author:Mohab Ahmed    	  ************************************/
/************************************		Layer:MCAL            ************************************/
/************************************   	SWC:USART             ************************************/
/************************************		Version:1.00          ************************************/
/*****************************************************************************************************/



#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"


/* Array of Addresses which has type of Struct to addresses USART_t*/
static volatile USART_t* const USART [3] = { USART_1 , USART_2 , USART_3 };

void USART_voidInit(USART_config_t *USART_ptr)
{
	u8 Local_u8USARTNum=USART_ptr->USART_Number;


	/*Calculating the value of BRR corresponding to the BaudRate*/
	u32 Local_u32Mantissa= CLOCK_FREQ / ( 16 * (USART_ptr -> USART_BaudRate ) );
	u32 Local_u32Fraction = ((( CLOCK_FREQ * 100 ) / ( 16 * (USART_ptr->USART_BaudRate) )) % 100 ) * 16 ;

	if( Local_u32Fraction > 1500 )
	{
		Local_u32Mantissa += 1 ;
		Local_u32Fraction = 0 ;
	}
	USART [Local_u8USARTNum] -> BRR	= ( Local_u32Mantissa << 4 ) | ( Local_u32Fraction / 100 );


	/*Enabling the TX and RX*/
	SET_BIT( USART[Local_u8USARTNum] -> CR1 , USART_TE);
	SET_BIT( USART[Local_u8USARTNum] -> CR1 , USART_RE);

	/*Parity Check Enable*/
	if(USART_ptr->USART_ParityCheck == USART_ParityCheckEnabled)
	{
		SET_BIT(USART [Local_u8USARTNum] -> CR1 , USART_PCE);
	}
	else
	{
		CLR_BIT(USART [Local_u8USARTNum] -> CR1 , USART_PCE);
	}
	/*Even or Odd Parity  */
	if(USART_ptr->USART_Parity == USART_EvenParity )
	{
		CLR_BIT(USART [Local_u8USARTNum] -> CR1, USART_PS );
	}
	else if( USART_ptr -> USART_Parity == USART_OddParity )
	{
		SET_BIT(USART [Local_u8USARTNum] -> CR1, USART_PS );
	}



	/*Data length*/
	if(USART_ptr -> USART_DataLength == USART_Data8Bits)
	{
		CLR_BIT ( USART[Local_u8USARTNum] -> CR1 , USART_M );
	}
	else if(USART_ptr -> USART_DataLength == USART_Data9Bits)
	{
		SET_BIT ( USART[Local_u8USARTNum] -> CR1 , USART_M );
	}


	/*Number of Stop bits*/
	if(USART_ptr -> USART_StopBits == USART_1StopBits)
	{
		CLR_BIT ( USART[Local_u8USARTNum] -> CR2 , USART_STOP1 );
		CLR_BIT ( USART[Local_u8USARTNum] -> CR2 , USART_STOP0 );
	}
	else if(USART_ptr -> USART_StopBits == USART_2StopBits)
	{
		SET_BIT ( USART[Local_u8USARTNum] -> CR2 , USART_STOP1 );
		CLR_BIT ( USART[Local_u8USARTNum] -> CR2 , USART_STOP0 );
	}
	else if(USART_ptr -> USART_StopBits == USART_halfStopBit)
	{
		CLR_BIT ( USART[Local_u8USARTNum] -> CR2 , USART_STOP1 );
		SET_BIT ( USART[Local_u8USARTNum] -> CR2 , USART_STOP0 );
	}
	else if(USART_ptr -> USART_StopBits == USART_three_halfsStopBits)
	{
		SET_BIT ( USART[Local_u8USARTNum] -> CR2 , USART_STOP1 );
		SET_BIT ( USART[Local_u8USARTNum] -> CR2 , USART_STOP0 );
	}


		/*Enable the USART*/
		SET_BIT( USART[Local_u8USARTNum] -> CR1 , USART_UE );
		/*Clear the status register*/
		USART[Local_u8USARTNum] -> SR = 0x00;

}


void USART_voidTransmitByteSynch(u8	Local_u8Byte , USART_Num_t Copy_USARTNumber)
{
	/*Send the Byte to the Data Register*/
	USART[Copy_USARTNumber] -> DR = Local_u8Byte;

	/*Wait until the transmission complete*/
	while(GET_BIT(USART[Copy_USARTNumber]-> SR , USART_TC) == 0);

	/*Clear the transmission Complete flag*/
	CLR_BIT(USART[Copy_USARTNumber] -> SR , USART_TC);

}
u8 USART_voidReceiveByteSynch(USART_Num_t Copy_USARTNumber)
{

	u8 Local_u8Byte;

	/*Wait until the Receive not empty flag is raised*/
	while(GET_BIT( USART[Copy_USARTNumber] -> SR , USART_RXNE) == 0);

	/*Get the received data*/
	Local_u8Byte = USART[Copy_USARTNumber] -> DR ;

	/*Clear the Receive not empty flag*/
	CLR_BIT( USART[Copy_USARTNumber] -> SR , USART_RXNE);

	return Local_u8Byte;

}
void  USART_voidSendArrSynch(u8 * Copy_ptr_u8_TXArr, u8 Copy_u8ArrSize,USART_Num_t Copy_USARTNumber)
{
	u16 Local_u16Iterator = 0 ;

	while ( Local_u16Iterator < Copy_u8ArrSize )
	{
		USART_voidTransmitByteSynch(Copy_ptr_u8_TXArr[Local_u16Iterator],Copy_USARTNumber);
		Local_u16Iterator ++ ;
	}

}

void  USART_voidReceiveArrSynch(u8 * Copy_ptr_u8_RXArr,u8 Copy_u8ArrSize ,USART_Num_t Copy_USARTNumber)
{
	u16 Local_u16Iterator = 0 ;

	while ( Local_u16Iterator < Copy_u8ArrSize )
	{
		Copy_ptr_u8_RXArr[Local_u16Iterator]=USART_voidReceiveByteSynch(Copy_USARTNumber);
		Local_u16Iterator ++ ;
	}

	Copy_ptr_u8_RXArr[Local_u16Iterator] = '\0';
}
void  USART_voidSendNumber(s32 Copy_s32Number, USART_Num_t Copy_USARTNumber)
{

	u8 Local_u8Counter=0,Local_u8SentNumber;
	u32 Local_u32divisible=1;

	if(Copy_s32Number < 0)
	{
		USART_voidTransmitByteSynch('-', Copy_USARTNumber);
		Copy_s32Number  *= -1;
	}

	s32 Local_u32temp=Copy_s32Number;

	if(Copy_s32Number==0)
		USART_voidTransmitByteSynch('0',Copy_USARTNumber);

	else
	{

		/*getting the number of the digits*/
		while(Local_u32temp!=0)
		{
			Local_u8Counter++;
			Local_u32temp=Local_u32temp/10;

		}

		/*getting the divisible to get each number separately*/
		while(Local_u8Counter>1)
		{
			Local_u8Counter--;
			Local_u32divisible*=10;
		}

		/*getting each number and send it to the USART*/
		while(Local_u32divisible!=0)
		{
			Local_u8SentNumber=Copy_s32Number/Local_u32divisible;
			USART_voidTransmitByteSynch(Local_u8SentNumber+'0' ,Copy_USARTNumber);
			Copy_s32Number=Copy_s32Number-(Local_u8SentNumber*Local_u32divisible);
			Local_u32divisible=Local_u32divisible/10;
		}
	}

}



