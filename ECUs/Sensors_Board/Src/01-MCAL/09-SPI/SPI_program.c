/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : SPI                                   */
/***************************************************************/


#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "../../01-MCAL/02-DIO/DIO_interface.h"

#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"



static volatile SPI_MemMap_t* const SPI[ SPI_COUNT ] =
{
		SPI1_BASE_ADDRESS,
		SPI2_BASE_ADDRESS
};


SPI_Errors_t SPI_Init ( SPI_t* Ptr_SPI )
{
	SPI_Errors_t Local_Error = SPI_NoError;

	SPI_Number_t Local_SPINumber = Ptr_SPI->SPI_Number;


	/**********************/
	/* clear CR2 register */
	/**********************/
	SPI[ Local_SPINumber ]->CR2 = 0;


	if ( Local_SPINumber < SPI_COUNT )
	{
		/*******************/
		/* set clock phase */
		/*******************/
		if ( Ptr_SPI->SPI_Phase <= SPI_ClkPhase_TrailingEdge )
		{
			SPI[ Local_SPINumber ]->CR1 |= ( Ptr_SPI->SPI_Phase << SPI_CR1_CPHA );
		}
		else
		{
			Local_Error = SPI_ClkPhaseError;
		}


		/**********************/
		/* set clock polarity */
		/**********************/
		if ( Ptr_SPI->SPI_Polartity <= SPI_ClkPol_IdleHigh )
		{
			SPI[ Local_SPINumber ]->CR1 |= ( Ptr_SPI->SPI_Polartity << SPI_CR1_CPOL );
		}
		else
		{
			Local_Error = SPI_ClkPolarityError;
		}


		/************/
		/* set mode */
		/************/
		if ( Ptr_SPI->SPI_Mode == SPI_Master )
		{
			SET_BIT( SPI[ Local_SPINumber ]->CR1, SPI_CR1_MSTR );
		}
		else if ( Ptr_SPI->SPI_Mode == SPI_Slave )
		{
			CLR_BIT( SPI[ Local_SPINumber ]->CR1, SPI_CR1_MSTR );
		}
		else
		{
			Local_Error = SPI_ModeError;
		}


		/***************************/
		/* set hardware management */
		/***************************/
		SPI[ Local_SPINumber ]->CR1 |= ( SPI_SW_SLAVE_SELECT << SPI_CR1_SSI );


		/*********************/
		/* set the baud rate */
		/*********************/
		if ( Ptr_SPI->SPI_Mode == SPI_Master )
		{
			if ( Ptr_SPI->SPI_ClkRate <= SPI_ClkRateDiv256 )
			{
				SPI[ Local_SPINumber ]->CR1 &= ~( SPI_CLK_MASK << SPI_CR1_BR );
				SPI[ Local_SPINumber ]->CR1 |= ( Ptr_SPI->SPI_ClkRate << SPI_CR1_BR );

				/*********************/
				/* enable NSS output */
				/*********************/
				SET_BIT( SPI[ Local_SPINumber ]->CR2, SPI_CR2_SSOE );
			}
			else
			{
				Local_Error = SPI_ClkRateError;
			}
		}
		else
		{
			/* no setting for baud rate for slaves */
		}


		/******************/
		/* set data order */
		/******************/
		if ( Ptr_SPI->SPI_DataOrder <= SPI_LSBFirst )
		{
			SPI[ Local_SPINumber ]->CR1 |= ( Ptr_SPI->SPI_DataOrder << SPI_CR1_LSBFIRST );
		}
		else
		{
			Local_Error = SPI_DataOrderError;
		}


		/****************************/
		/* set data frame to 8 bits */
		/****************************/
		CLR_BIT( SPI[ Local_SPINumber ]->CR1, SPI_CR1_DFF );


		/***************************/
		/* set mode to full-duplex */
		/***************************/
		CLR_BIT( SPI[ Local_SPINumber ]->CR1, SPI_CR1_RXONLY );
	}
	else
	{
		Local_Error = SPI_PointerError;
	}


	/**************************/
	/* return the error state */
	/**************************/
	return Local_Error;
}




SPI_Errors_t SPI_SynchTransceive( SPI_Number_t Copy_SPI, u8* Ptr_u8DataSend, u8* Ptr_u8DataReceived, u32 Copy_u32Size )
{
	u32 Local_u32Iterator = 0;

	SPI_Errors_t Local_Error = SPI_NoError;

	if ( Copy_SPI < SPI_COUNT )
	{
		while ( ( Copy_u32Size-- ) != 0 )
		{
			/***************************************/
			/* put the data into the data register */
			/***************************************/
			SPI[ Copy_SPI ]->DR = Ptr_u8DataSend[ Local_u32Iterator ];


			/*****************************************************/
			/* wait until transmission and reception is complete */
			/*****************************************************/
			while ( !GET_BIT( SPI[ Copy_SPI ]->SR, SPI_SR_TXE ) );
			while (  GET_BIT( SPI[ Copy_SPI ]->SR, SPI_SR_BSY ) );


			/*****************************************/
			/* put the received data to the variable */
			/*****************************************/
			Ptr_u8DataReceived[ Local_u32Iterator ] = SPI[ Copy_SPI ]->DR;


			/**************************/
			/* increment the iterator */
			/**************************/
			Local_u32Iterator++;
		}
	}
	else
	{
		Local_Error = SPI_PointerError;
	}


	/**************************/
	/* return the local error */
	/**************************/
	return Local_Error;
}


SPI_Errors_t SPI_SynchTransceiveByte( SPI_Number_t Copy_SPI, u8 Copy_u8DataSend, u8* Ptr_u8DataReceived )
{
	SPI_Errors_t Local_Error = SPI_NoError;

	if ( Copy_SPI < SPI_COUNT )
	{

		/***************************************/
		/* put the data into the data register */
		/***************************************/
		SPI[ Copy_SPI ]->DR = Copy_u8DataSend;


		/*****************************************************/
		/* wait until transmission and reception is complete */
		/*****************************************************/
		while ( !GET_BIT( SPI[ Copy_SPI ]->SR, SPI_SR_TXE ) );
		while (  GET_BIT( SPI[ Copy_SPI ]->SR, SPI_SR_BSY ) );


		/*****************************************/
		/* put the received data to the variable */
		/*****************************************/
		( *Ptr_u8DataReceived ) = SPI[ Copy_SPI ]->DR;
	}
	else
	{
		Local_Error = SPI_PointerError;
	}


	/**************************/
	/* return the local error */
	/**************************/
	return Local_Error;
}


SPI_Errors_t SPI_State ( SPI_Number_t Copy_SPI, SPI_State_t Copy_u8Status )
{
	SPI_Errors_t Local_Error = SPI_NoError;

	if ( Copy_SPI < SPI_COUNT )
	{
		if ( Copy_u8Status == SPI_Enable )
		{
			/*************************/
			/* enable SPI peripheral */
			/*************************/
			SET_BIT( SPI[ Copy_SPI ]->CR1, SPI_CR1_SPE );
		}
		else if ( Copy_u8Status == SPI_Disable )
		{
			/**************************/
			/* disable SPI peripheral */
			/**************************/
			CLR_BIT( SPI[ Copy_SPI ]->CR1, SPI_CR1_SPE );
		}
		else
		{
			Local_Error = SPI_StateError;
		}

	}
	else
	{
		Local_Error = SPI_PointerError;
	}


	/**************************/
	/* return the local error */
	/**************************/
	return Local_Error;
}


