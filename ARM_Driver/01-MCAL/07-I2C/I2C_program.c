/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : I2C Driver                            */
/***************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "../07-I2C/I2C_config.h"
#include "../07-I2C/I2C_private.h"
#include "../07-I2C/I2C_interface.h"

#include "../00-RCC/RCC_interface.h"


static volatile I2C_MemMap_t * const I2C_Array[ 2 ] = { I2C1, I2C2 };

/***********************************************************************************/
u8 I2C_u8Init(u8 Copy_u8I2C, u8 Copy_u8I2CSpeed)
{
	u8 Local_u8Error = I2C_NO_ERROR;

	/* enable RCC for AFIO */
	RCC_voidEnableClock( RCC_AFIO, RCC_APB2 );

	/* enable RCC for used I2C for return error if the input parameter was wrong */
	if( Copy_u8I2C == I2C_1 )
	{
		/* initiate RCC */
		RCC_voidEnableClock( RCC_I2C1, RCC_APB1 );
	}

	else if( Copy_u8I2C == I2C_2 )
	{
		/* initiate RCC */
		RCC_voidEnableClock( RCC_I2C2, RCC_APB1 );
	}
	else
	{
		Local_u8Error = I2C_Pointer_Error;
		return Local_u8Error;
	}

	/* reset peripheral for re-initializing */
	SET_BIT( I2C_Array[ Copy_u8I2C ]->CR1, I2C_CR1_SWRST );
	CLR_BIT( I2C_Array[ Copy_u8I2C ]->CR1, I2C_CR1_SWRST );

	/* set the clock of the I2C */
	I2C_Array[ Copy_u8I2C ]->CR2  |= I2C_APB_CLOCK;

	I2C_Array[ Copy_u8I2C ]->CCR   = Copy_u8I2CSpeed;

	I2C_Array[ Copy_u8I2C ]->TRISE = I2C_APB_CLOCK + 1;

	/* enable peripheral */
	SET_BIT( I2C_Array[ Copy_u8I2C ]->CR1, I2C_CR1_PE );


	return Local_u8Error;
}


/***********************************************************************************/
void I2C_voidStart( u8 Copy_u8I2C )
{
	/* enable ACK bit */
	SET_BIT( I2C_Array[ Copy_u8I2C ]->CR1, I2C_CR1_ACK );

	/* set start bit */
	SET_BIT( I2C_Array[ Copy_u8I2C ]->CR1, I2C_CR1_START );

	/* wait for the flag that means that the start bit is send */
	while( !GET_BIT( I2C_Array[ Copy_u8I2C ]->SR1, I2C_SR1_SB ) );
}


/***********************************************************************************/
void I2C_voidWriteAddress( u8 Copy_u8I2C, u8 Copy_u8Add, u8 Copy_u8Operation )
{
	/* set or clear RW bit for read or write operation */
	u8 Local_u8Temp = 0;

	/* put address in DR register to be sent */
	I2C_Array[ Copy_u8I2C ]->DR = Copy_u8Add;

	/* wait until transmission of address is over */
	while( !GET_BIT( I2C_Array[ Copy_u8Add ]->SR1, I2C_SR1_ADDR ) );

	/* clear ADDR by reading both SR1 and SR2 */
	Local_u8Temp |= I2C_Array[ Copy_u8Add ]->SR1 | I2C_Array[ Copy_u8Add ]->SR2;
}


/***********************************************************************************/
void I2C_voidWriteByte( u8 Copy_u8I2C, u8 Copy_u8Data )
{
	/* wait until data register is empty */
	while( !GET_BIT( I2C_Array[ Copy_u8Data ]->SR1, I2C_SR1_ADD10 ) );

	/* send data */
	I2C_Array[ Copy_u8I2C ]->DR = Copy_u8Data;

	/* wait until byte transfer is succeeded */
	while( !GET_BIT( I2C_Array[ Copy_u8I2C ]->SR1, I2C_SR1_BTF ) );
}


/***********************************************************************************/
void I2C_voidStop( u8 Copy_u8I2C )
{
	/* set STOP bit */
	SET_BIT( I2C_Array[ Copy_u8I2C ]->CR1, I2C_CR1_STOP );
}


/***********************************************************************************/
void I2C_voidWriteMultiBytes( u8 Copy_u8I2C, u8* Copy_u8Data, u8 Copy_u8Size )
{
	u8 Local_u8Counter = 0;

	/* loop until data is over */
	while( Local_u8Counter < Copy_u8Size )
	{
		/* if data is not null character send it */
		I2C_voidWriteByte( Copy_u8I2C, Copy_u8Data[ Local_u8Counter++ ] );
	}
}


/***********************************************************************************/
void I2C_voidRead( u8 Copy_u8I2C, u8 Copy_u8Add, u8* Copy_u8Buffer, u8 Copy_u8Size )
{
	u8 Local_u8Counter = Copy_u8Size;

	/*
	 --> if the size of the data is just one byte
		1) Write the slave Address, and wait for the ADDR bit to be set
		2) the Acknowledge disable and the STOP condition generation are made after EV6 ( just after ADDR is cleared )
		3) Wait for the RXNE bit to set
		4) Read the data from the DR

	--> if the size of the data is greater than one byte
		1) Write the slave Address, and wait for the ADDR bit to be set
		2) Wait for the RXNE (Receive buffer not empty) bit to set
		3) Read the data from the DR
		4) Generate the Ack by setting the ACK
		5) To generate the NACK pulse after the last received data byte, the ACK bit must be cleared just after reading the
		   second last data byte
		6) In order to generate the Stop/Restart condition, software must set the STOP/START bit
	   	   after reading the second last data byte
	*/
	if( Copy_u8Size == 1 )
	{
		/* send address with read operation */
		I2C_voidWriteAddress( Copy_u8I2C, Copy_u8Add, I2C_READ_OPERATION );

		/* clear acknowledge bit */
		CLR_BIT( I2C_Array[ Copy_u8Add ]->CR1, I2C_CR1_ACK);

		/* send stop condition */
		SET_BIT( I2C_Array[ Copy_u8I2C ]->CR1, I2C_CR1_STOP );

		/* wait for the data buffer to be not empty */
		while( !GET_BIT( I2C_Array[ Copy_u8I2C ]->SR1, I2C_SR1_RxNE ) );

		/* read DR register and put it to the buffer */
		Copy_u8Buffer[ Copy_u8Size - Local_u8Counter ] = I2C_Array[ Copy_u8I2C ]->DR;
	}

	else
	{
		/* send address with read operation */
		I2C_voidWriteAddress( Copy_u8I2C, Copy_u8Add, I2C_READ_OPERATION );

		/* if data size in greater than 2 then do normal reading operation */
		while( Local_u8Counter > 2 )
		{
			/* wait for the data buffer to be not empty */
			while( !GET_BIT( I2C_Array[ Copy_u8I2C ]->SR1, I2C_SR1_RxNE ) );

			/* read DR register and put it to the buffer */
			Copy_u8Buffer[ Copy_u8Size - Local_u8Counter ] = I2C_Array[ Copy_u8I2C ]->DR;

			/* set acknowledge bit */
			SET_BIT( I2C_Array[ Copy_u8I2C ]->CR1, I2C_CR1_ACK );

			/* decrement counter to read the next byte */
			Local_u8Counter--;
		}

		/* when the size of the data is 2 read --> read the second last byte and then clear the ack bit and set the stop bit */
		/* wait for the data buffer to be not empty */
		while( !GET_BIT( I2C_Array[ Copy_u8I2C ]->SR1, I2C_SR1_RxNE ) );

		/* read DR register and put it to the buffer */
		Copy_u8Buffer[ Copy_u8Size - Local_u8Counter ] = I2C_Array[ Copy_u8I2C ]->DR;

		/* clear acknowledge bit */
		CLR_BIT( I2C_Array[ Copy_u8Add ]->CR1, I2C_CR1_ACK);

		/* send stop condition */
		SET_BIT( I2C_Array[ Copy_u8I2C ]->CR1, I2C_CR1_STOP );

		/* decrement counter to read the next byte */
		Local_u8Counter--;

		/* read the last bit */
		/* wait for the data buffer to be not empty */
		while( !GET_BIT( I2C_Array[ Copy_u8I2C ]->SR1, I2C_SR1_RxNE ) );

		/* read DR register and put it to the buffer */
		Copy_u8Buffer[ Copy_u8Size - Local_u8Counter ] = I2C_Array[ Copy_u8I2C ]->DR;
	}
}
