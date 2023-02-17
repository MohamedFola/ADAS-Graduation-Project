/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : SPI                                   */
/***************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"


#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"

#include "../00-RCC/RCC_interface.h"


static volatile SPI_MemMap_t * const SPI_Array[ 2 ] = { SPI1, SPI2 };


u8 SPI_u8MasterInit(
		u8 Copy_u8SPI,
		u8 Copy_u8DataOrder,
		u8 Copy_u8ClockPolatrity,
		u8 Copy_u8ClockPhase,
		u8 Copy_u8ClockRate)
{
	u8 Local_u8Error = SPI_NoError;

	/*************************************/
	/* enable clock for peripherals used */
	/*************************************/
	if      ( Copy_u8SPI == SPI_1 )
	{
		RCC_voidEnableClock( RCC_SPI1, RCC_APB2 );  // SPI1 enable
		RCC_voidEnableClock( RCC_GPIOA, RCC_APB2 ); // GPIOA enable
	}
	else if ( Copy_u8SPI == SPI_2 )
	{
		RCC_voidEnableClock( RCC_SPI2, RCC_APB1 );  // SPI2 enable
		RCC_voidEnableClock( RCC_GPIOB, RCC_APB2 ); // GPIOB enable
	}
	else
	{
		Local_u8Error = SPI_PointerError;
		return Local_u8Error;
	}


	/*******************/
	/* set clock phase */
	/*******************/
	if( Copy_u8ClockPhase <= SPI_CLKPH_TRAILING_EDGE )
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( Copy_u8ClockPhase << SPI_CR1_CPHA );
	}
	else
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( SPI_DEFAULT << SPI_CR1_CPHA );
		Local_u8Error = SPI_ClkPhaseError;
	}


	/**********************/
	/* set clock polarity */
	/**********************/
	if( Copy_u8ClockPhase <= SPI_CLKPOL_IDLE_HIGH )
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( Copy_u8ClockPhase << SPI_CR1_CPOL );
	}
	else
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( SPI_DEFAULT << SPI_CR1_CPOL );
		Local_u8Error = SPI_ClkPolarityError;
	}


	/**************/
	/* set master */
	/**************/
	SET_BIT( SPI_Array[ Copy_u8SPI ]->CR1, SPI_CR1_MSTR );


	/***************************/
	/* set software management */
	/***************************/
#if SPI_SOFTWARE_MANAGEMENT == SPI_ENABLE_SM
	SPI_Array[ Copy_u8SPI ]->CR1 |= ( SPI_SOFTWARE_MANAGEMENT << SPI_CR1_SSI );
#endif


	/*********************/
	/* set the baud rate */
	/*********************/
	if( Copy_u8ClockRate <= SPI_CLOCK_RATE_DIV_256 )
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( Copy_u8ClockRate << SPI_CR1_BR );
	}
	else
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( SPI_DEFAULT << SPI_CR1_BR );
		Local_u8Error = SPI_ClkRateError;
	}


	/******************/
	/* set data order */
	/******************/
	if( Copy_u8DataOrder <= SPI_LSB_FIRST )
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( Copy_u8DataOrder << SPI_CR1_LSBFIRST );
	}
	else
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( SPI_DEFAULT << SPI_CR1_LSBFIRST );
		Local_u8Error = SPI_DataOrderError;
	}


	/****************************/
	/* set data frame to 8 bits */
	/****************************/
	CLR_BIT( SPI_Array[ Copy_u8SPI ]->CR1, SPI_CR1_DFF );


	/***************************/
	/* set mode to full-duplex */
	/***************************/
	CLR_BIT( SPI_Array[ Copy_u8SPI ]->CR1, SPI_CR1_RXONLY );


	/**********************/
	/* clear CR2 register */
	/**********************/
	SPI_Array[ Copy_u8SPI ]->CR2 = 0;


	/**************/
	/* enable SPI */
	/**************/
	SET_BIT( SPI_Array[ Copy_u8SPI ]->CR1, SPI_CR1_SPE );


	/**************************/
	/* return the error state */
	/**************************/
	return Local_u8Error;
}


/***********************************************************************************/


u8 SPI_u8SlaveInit(
		u8 Copy_u8SPI,
		u8 Copy_u8DataOrder,
		u8 Copy_u8ClockPolatrity,
		u8 Copy_u8ClockPhase)
{
	u8 Local_u8Error = SPI_NoError;

	/*************************************/
	/* enable clock for peripherals used */
	/*************************************/
	if      ( Copy_u8SPI == SPI_1 )
	{
		RCC_voidEnableClock( RCC_SPI1, RCC_APB2 );  // SPI1 enable
		RCC_voidEnableClock( RCC_GPIOA, RCC_APB2 ); // GPIOA enable
	}
	else if ( Copy_u8SPI == SPI_2 )
	{
		RCC_voidEnableClock( RCC_SPI2, RCC_APB1 );  // SPI2 enable
		RCC_voidEnableClock( RCC_GPIOB, RCC_APB2 ); // GPIOB enable
	}
	else
	{
		Local_u8Error = SPI_PointerError;
		return Local_u8Error;
	}


	/*******************/
	/* set clock phase */
	/*******************/
	if( Copy_u8ClockPhase <= SPI_CLKPH_TRAILING_EDGE )
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( Copy_u8ClockPhase << SPI_CR1_CPHA );
	}
	else
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( SPI_DEFAULT << SPI_CR1_CPHA );
		Local_u8Error = SPI_ClkPhaseError;
	}


	/**********************/
	/* set clock polarity */
	/**********************/
	if( Copy_u8ClockPhase <= SPI_CLKPOL_IDLE_HIGH )
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( Copy_u8ClockPhase << SPI_CR1_CPOL );
	}
	else
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( SPI_DEFAULT << SPI_CR1_CPOL );
		Local_u8Error = SPI_ClkPolarityError;
	}


	/*************/
	/* set slave */
	/*************/
	CLR_BIT( SPI_Array[ Copy_u8SPI ]->CR1, SPI_CR1_MSTR );


	/***************************/
	/* set software management */
	/***************************/
#if SPI_SOFTWARE_MANAGEMENT == SPI_ENABLE_SM
	SPI_Array[ Copy_u8SPI ]->CR1 |= ( SPI_SOFTWARE_MANAGEMENT << SPI_CR1_SSI );
#endif


	/******************/
	/* set data order */
	/******************/
	if( Copy_u8DataOrder <= SPI_LSB_FIRST )
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( Copy_u8DataOrder << SPI_CR1_LSBFIRST );
	}
	else
	{
		SPI_Array[ Copy_u8SPI ]->CR1 |= ( SPI_DEFAULT << SPI_CR1_LSBFIRST );
		Local_u8Error = SPI_DataOrderError;
	}


	/****************************/
	/* set data frame to 8 bits */
	/****************************/
	CLR_BIT( SPI_Array[ Copy_u8SPI ]->CR1, SPI_CR1_DFF );


	/***************************/
	/* set mode to full-duplex */
	/***************************/
	CLR_BIT( SPI_Array[ Copy_u8SPI ]->CR1, SPI_CR1_RXONLY );


	/**********************/
	/* clear CR2 register */
	/**********************/
	SPI_Array[ Copy_u8SPI ]->CR2 = 0;


	/**************/
	/* enable SPI */
	/**************/
	SET_BIT( SPI_Array[ Copy_u8SPI ]->CR1, SPI_CR1_SPE );


	/**************************/
	/* return the error state */
	/**************************/
	return Local_u8Error;
}


/***********************************************************************************/


u8 SPI_u8SynchTransceive( u8 Copy_u8SPI, u8 Copy_u8Data )
{
	/***************************************/
	/* put the data into the data register */
	/***************************************/
	SPI_Array[ Copy_u8SPI ]->DR = Copy_u8Data;

	/*****************************************************/
	/* wait until transmission and reception is complete */
	/*****************************************************/
	while( !GET_BIT( SPI_Array[ Copy_u8SPI ]->SR, SPI_SR_TXE ) );
	while( GET_BIT( SPI_Array[ Copy_u8SPI ]->SR, SPI_SR_BSY ) );

	/****************************/
	/* return the received data */
	/****************************/
	return ( SPI_Array[ Copy_u8SPI ]->DR );
}


/***********************************************************************************/


u8* SPI_u8SynchTransceiveString( u8 Copy_u8SPI, u8* Copy_pu8String )
{
	/**************************************************/
	/* counter to iterate through the string elements */
	/**************************************************/
	u8 Local_u8Counter = 0;


	/*************************************/
	/* array to save the received string */
	/*************************************/
	u8* Local_pu8Received;


	/***********************************/
	/* wait till the end of the String */
	/***********************************/
	while( Copy_pu8String[ Local_u8Counter ] != '\0' )
	{
		/********************************************/
		/* send and receive the string byte by byte */
		/********************************************/
		Local_pu8Received[ Local_u8Counter ] = SPI_u8SynchTransceive( Copy_u8SPI, Copy_pu8String[ Local_u8Counter ] );


		/*****************************************************************/
		/* increment the counter to go to the next element in the string */
		/*****************************************************************/
		Local_u8Counter++;
	}


	/**************************************************************/
	/* last element of the received string must be NULL character */
	/**************************************************************/
	Local_pu8Received[ Local_u8Counter ] = '\0';


	/****************************/
	/* return the received data */
	/****************************/
	return Local_pu8Received;
}
