/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : I2C Driver                            */
/***************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "I2C_private.h"
#include "I2C_interface.h"
#include "I2C_config.h"


static volatile I2C_MemMap_t* const I2C[ I2C_COUNT ] =
{
		I2C1_BASE_ADDRESS,
		I2C2_BASE_ADDRESS
};


/***********************************************************************
 * Steps to follow                                                     *
 * 1) Enable I2C and GPIO clock --> RCC Driver                         *
 * 2) Pin Configurations --> PORT Driver                               *
 * 		a) Select Alternate Function in MODER                          *
 * 		b) Select Output Open Drain                                    *
 * 		c) Select the speed --> High Speed as example                  *
 * 		d) Select Pull-Up for both pins                                *
 * 		e) Configure Alternate Function in AFR                         *
 *																	   *
 * 3) Reset the I2C                                                    *
 * 4) Program the peripheral input clock in I2C_CR2 Register           *
 * 	  in order to generate correct timings                             *
 * 5) Configure the clock control registers                            *
 * 6) Configure the rise time register                                 *
 * 7) Program the I2C_CR1 register to enable the peripheral            *
 ***********************************************************************/
I2C_Errors_t I2C_Init ( I2C_t Copy_Number )
{
	I2C_Errors_t Local_Error = I2C_No_Error;

	if ( Copy_Number < I2C_COUNT )
	{
		/* reset the peripheral for re-initialize */
		SET_BIT( I2C[ Copy_Number ]->CR1, I2C_CR1_SWRST );
		CLR_BIT( I2C[ Copy_Number ]->CR1, I2C_CR1_SWRST );

		/* set the clock */
		I2C[ Copy_Number ]->CR2   |= I2C_APB_CLOCK << I2C_CR2_FREQ ;
		I2C[ Copy_Number ]->CCR    = I2C_SM_CRR                    ;
		I2C[ Copy_Number ]->TRISE |= I2C_APB_CLOCK + 1             ;

		/* enable the peripheral */
		SET_BIT( I2C[ Copy_Number ]->CR1, I2C_CR1_PE );
	}
	else
	{
		Local_Error = I2C_Number_Error;
	}

	return Local_Error;
}



/***********************************************************************
 * Steps to follow                                                     *
 * 1) Enable ACK                                                       *
 * 2) Send the Start Bit                                               *
 * 3) Wait for SB bit to be 1 which means that the start is generated  *
 ***********************************************************************/
I2C_Errors_t I2C_Start ( I2C_t Copy_Number )
{
	I2C_Errors_t Local_Error = I2C_No_Error;

	if ( Copy_Number < I2C_COUNT )
	{
		/* enable ACK */
		SET_BIT( I2C[ Copy_Number ]->CR1, I2C_CR1_ACK );

		/* send start bit */
		SET_BIT( I2C[ Copy_Number ]->CR1, I2C_CR1_START );

		/* wait for start generation */
		while( !GET_BIT( I2C[ Copy_Number ]->SR1, I2C_SR1_SB ) );
	}
	else
	{
		Local_Error = I2C_Number_Error;
	}

	return Local_Error;
}


I2C_Errors_t I2C_Stop ( I2C_t Copy_Number )
{
	I2C_Errors_t Local_Error = I2C_No_Error;

	if ( Copy_Number < I2C_COUNT )
	{
		/* send stop bit */
		SET_BIT( I2C[ Copy_Number ]->CR1, I2C_CR1_STOP );
	}
	else
	{
		Local_Error = I2C_Number_Error;
	}

	return Local_Error;
}



/****************************************************
 * Steps to follow                                  *
 * 1) Send the Slave Address                        *
 * 2) Wait until the transmission is over           *
 * 3) Clear ADDR by reading both SR1 and SR2        *
 ****************************************************/
I2C_Errors_t I2C_SendAddress ( I2C_t Copy_Number, u8 Copy_u8Address )
{
	u8 Local_u8Temp;  // for reading SR1 and SR2 to clear flag

	I2C_Errors_t Local_Error = I2C_No_Error;

	if ( Copy_Number < I2C_COUNT )
	{
		/* send the slave address */
		I2C[ Copy_Number ]->DR = Copy_u8Address;

		/* wait until transmission of address is over */
		while( !GET_BIT( I2C[ Copy_Number ]->SR1, I2C_SR1_ADDR ) );

		/* clearing the ADDR flag */
		Local_u8Temp = I2C[ Copy_Number ]->SR1 | I2C[ Copy_Number ]->SR2;

		/* check for the Acknowledge */
		if ( GET_BIT( I2C[ Copy_Number ]->SR1, I2C_SR1_AF ) )
		{
			Local_Error = I2C_NACK;
		}
	}
	else
	{
		Local_Error = I2C_Number_Error;
	}

	return Local_Error;
}



/******************************************************************************
 * Steps to follow                                                            *
 * 1) Waits for TxE to be 1, which indicates that the DR register is Empty    *
 * 2) Send the Byte                                                           *
 * 3) Wait for BTF bit to be 1 which means that the Byte is Transmitted       *
 ******************************************************************************/
I2C_Errors_t I2C_SendData ( I2C_t Copy_Number, u8* Copy_u8Data, u32 Copy_u32DataSize )
{
	u32 Local_u32Iterator = 0 ;   // for iterating through the data

	I2C_Errors_t Local_Error = I2C_No_Error;

	if ( Copy_Number < I2C_COUNT )
	{
		while ( ( Copy_u32DataSize-- ) != 0 )
		{
			/* wait for TxE */
			while( !GET_BIT( I2C[ Copy_Number ]->SR1, I2C_SR1_TxE ) );

			/* send the data */
			I2C[ Copy_Number ]->DR = Copy_u8Data[ Local_u32Iterator++ ];

			/* wait for BTF */
			while( I2C[ Copy_Number ]->SR1, I2C_SR1_BTF );
		}
	}
	else
	{
		Local_Error = I2C_Number_Error;
	}

	return Local_Error;
}



/*********************************************************************************************
* --> If only 1 BYTE needs to be Read                                                         *
*	a) Write the slave Address, and wait for the ADDR bit (bit 1 in SR1) to be set           *
*	b) the Acknowledge disable is made during EV6 (before ADDR flag is cleared)              *
*	   and the STOP condition generation is made after EV6                                   *
*	c) Wait for the RXNE (Receive Buffer not Empty) bit to set                               *
*	d) Read the data from the DR                                                             *
*                                                                                            *
* --> If Multiple BYTES needs to be read                                                      *
* a) Write the slave Address, and wait for the ADDR bit (bit 1 in SR1) to be set             *
* b) Clear the ADDR bit by reading the SR1 and SR2 Registers                                 *
* c) Wait for the RXNE (Receive buffer not empty) bit to set                                 *
* d) Read the data from the DR                                                               *
* e) Generate the Acknowledgment by setting the ACK (bit 10 in SR1)                           *
* f) To generate the non acknowledge pulse after the last received data byte,                 *
*    the ACK bit must be cleared just after reading the second last data byte                *
*    (after second last RxNE event)                                                          *
* g) In order to generate the Stop/Restart condition, software must set the STOP/START bit   *
*	 after reading the second last data byte (after the second last RxNE event)              *
 *********************************************************************************************/

I2C_Errors_t I2C_Read ( I2C_t Copy_Number, u8 Copy_u8Add, u8* Copy_u8Buffer, u32 Copy_u32Size )
{
	u8  Local_u8Temp                     ;  // for reading SR1 and SR2 to clear flag
	u32 Local_u32Iterator = Copy_u32Size ;  // for data buffer

	I2C_Errors_t Local_Error = I2C_No_Error;

	if ( Copy_Number < I2C_COUNT )
	{
		if ( Copy_u32Size == 1 )
		{
			/* send the slave address */
			I2C[ Copy_Number ]->DR = Copy_u8Add;

			/* wait until transmission of address is over */
			while( !GET_BIT( I2C[ Copy_Number ]->SR1, I2C_SR1_ADDR ) );

			/* send NACK before clearing ADDR */
			CLR_BIT( I2C[ Copy_Number ]->CR1, I2C_CR1_ACK );

			/* clearing the ADDR flag */
			Local_u8Temp = I2C[ Copy_Number ]->SR1 | I2C[ Copy_Number ]->SR2;

			/* send the stop after clearing ADDR flag */
			SET_BIT( I2C[ Copy_Number ]->CR1, I2C_CR1_STOP );

			/* wait for receiving to be over */
			while( !GET_BIT( I2C[ Copy_Number ]->SR1, I2C_SR1_RxNE ) );

			/* put the data into the buffer */
			Copy_u8Buffer[ Copy_u32Size - Local_u32Iterator ] = I2C[ Copy_Number ]->DR;
		}
		else
		{
			/* send the slave address */
			I2C[ Copy_Number ]->DR = Copy_u8Add;

			/* wait until transmission of address is over */
			while( !GET_BIT( I2C[ Copy_Number ]->SR1, I2C_SR1_ADDR ) );

			/* clearing the ADDR flag */
			Local_u8Temp = I2C[ Copy_Number ]->SR1 | I2C[ Copy_Number ]->SR2;

			while ( Local_u32Iterator > 2 )
			{
				/* wait for receiving to be over */
				while( !GET_BIT( I2C[ Copy_Number ]->SR1, I2C_SR1_RxNE ) );

				/* put the data into the buffer */
				Copy_u8Buffer[ Copy_u32Size - ( Local_u32Iterator-- ) ] = I2C[ Copy_Number ]->DR;

				/* send ACK */
				SET_BIT( I2C[ Copy_Number ]->CR1, I2C_CR1_ACK );
			}


			/* --> read the second last byte */

			/* wait for receiving to be over */
			while( !GET_BIT( I2C[ Copy_Number ]->SR1, I2C_SR1_RxNE ) );

			/* put the data into the buffer */
			Copy_u8Buffer[ Copy_u32Size - ( Local_u32Iterator-- ) ] = I2C[ Copy_Number ]->DR;

			/* send NACK */
			CLR_BIT( I2C[ Copy_Number ]->CR1, I2C_CR1_ACK );

			/* send stop */
			SET_BIT( I2C[ Copy_Number ]->CR1, I2C_CR1_STOP );


			/* --> read the last byte */

			/* wait for receiving to be over */
			while( !GET_BIT( I2C[ Copy_Number ]->SR1, I2C_SR1_RxNE ) );

			/* put the data into the buffer */
			Copy_u8Buffer[ Copy_u32Size - Local_u32Iterator ] = I2C[ Copy_Number ]->DR;
		}
	}
	else
	{
		Local_Error = I2C_Number_Error;
	}

	return Local_Error;
}
