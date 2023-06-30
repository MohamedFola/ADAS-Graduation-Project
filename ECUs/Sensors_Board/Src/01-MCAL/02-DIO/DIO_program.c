/*
 * DIO_program.c
 *
 *  Created on: Jan 28, 2023
 *      Author: speedTECH
 */
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "../02-DIO/DIO_private.h"
#include "../02-DIO/DIO_interface.h"

/* WriteChannel is used to set pin to High or Low */
u8 MDIO_u8WriteChannel(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u8Pin >15)
	{
		Local_u8ErrorStatus=NOK;
	}
	else
	{
		switch(Copy_u8Port)
		{
		case MDIO_PORTA:
			if(Copy_u8Value==MDIO_PIN_HIGH)
			{
				//SET_BIT(MDIOA->ODR,Copy_u8Pin);
				MDIOA->BSRR=(1<<Copy_u8Pin);
			}

			else if(Copy_u8Value==MDIO_PIN_LOW)
			{
				//CLR_BIT(MDIOA->ODR,Copy_u8Pin);
				MDIOA -> BRR=(1<<Copy_u8Pin);
			}
			break;
		case MDIO_PORTB:
			if(Copy_u8Value==MDIO_PIN_HIGH)
			{
				//SET_BIT(MDIOB_ODR,Copy_u8Pin);
				MDIOB -> BSRR=(1<<Copy_u8Pin);
			}
			else if(Copy_u8Value==MDIO_PIN_LOW)
			{
				//CLR_BIT(MDIOB_ODR,Copy_u8Pin);
				MDIOB->BRR=(1<<Copy_u8Pin);
			}
			break;
		case MDIO_PORTC:
			if(Copy_u8Value==MDIO_PIN_HIGH)
			{
				//SET_BIT(MDIOC_ODR,Copy_u8Pin);
				MDIOC->BSRR=(1<<Copy_u8Pin);
			}
			else if(Copy_u8Value==MDIO_PIN_LOW)
			{
				//CLR_BIT(MDIOC_ODR,Copy_u8Pin);
				MDIOC->BRR=(1<<Copy_u8Pin);
			}
			break;
		default: break;
		}
	}
	return Local_u8ErrorStatus;
}
/* ReadChannel is used to read the logic on the pin */
/*the Read value is changed by reference*/
u8 MDIO_u8ReadChannel(u8 Copy_u8Port, u8 Copy_u8Pin, u8 * Copy_pu8ReadValue)
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u8Pin >15)
	{
		Local_u8ErrorStatus=NOK;
	}
	else
	{
		switch(Copy_u8Port)
		{
		case MDIO_PORTA	: *Copy_pu8ReadValue=	GET_BIT(MDIOA->IDR,Copy_u8Pin);	break;
		case MDIO_PORTB	: *Copy_pu8ReadValue=	GET_BIT(MDIOB->IDR,Copy_u8Pin);	break;
		case MDIO_PORTC	: *Copy_pu8ReadValue= 	GET_BIT(MDIOC->IDR,Copy_u8Pin);	break;
		default : Local_u8ErrorStatus=NOK ;				break;
		}
	}
	return Local_u8ErrorStatus;
}
/*WritePort to write on any whole port */
u8 MDIO_u8WritePort(u8 Copy_u8Port, u16 Copy_u16Value)
{
	u8 Local_u8ErrorStatus=OK;

	switch(Copy_u8Port)
	{
	case MDIO_PORTA: MDIOA->ODR&=0x0000;
	MDIOA->ODR |=Copy_u16Value; 	break;
	case MDIO_PORTB: MDIOB->ODR&=0x0000;
	MDIOB->ODR |=Copy_u16Value; 	break;
	case MDIO_PORTC: MDIOC->ODR&=0x0000;
	MDIOC->ODR |=Copy_u16Value; 	break;
	default:Local_u8ErrorStatus=NOK;

	}
	return Local_u8ErrorStatus;
}
/*ReadPort is used to read the logic on the whole port */
/*the Read value is changed by reference*/
u8 MDIO_u8ReadPort(u8 Copy_u8Port, u16 * Copy_pu16ReadValue)
{
	u8 Local_u8ErrorStatus=OK;

	switch(Copy_u8Port)
	{
	case MDIO_PORTA: *Copy_pu16ReadValue=MDIOA->IDR; break;
	case MDIO_PORTB: *Copy_pu16ReadValue=MDIOB->IDR; break;
	case MDIO_PORTC: *Copy_pu16ReadValue=MDIOC->IDR; break;
	default:Local_u8ErrorStatus=NOK;

	}
	return Local_u8ErrorStatus;
}

u8 MDIO_voidWriteChannelGroup(u8 Copy_u8Port, u8 Copy_u8BitOffset,u8 Copy_u8BitWidth, u16 Copy_u16Value)
{
	u8 Local_u8ErrorStatus=OK;
	u16 Local_u16FinalValue;
	switch(Copy_u8Port)
		{
	/*then the complement of the BitMask is anded with ODR content */
	/*then the output is ored with the shifted required value*/
			case MDIO_PORTA	:
				Local_u16FinalValue=MDIOA->ODR;
				MDIOA->ODR=BitManipulationSetBits(Local_u16FinalValue,Copy_u8BitOffset,Copy_u8BitWidth,Copy_u16Value);break;
			case MDIO_PORTB	:
				Local_u16FinalValue=MDIOB->ODR;
				MDIOB->ODR=BitManipulationSetBits(Local_u16FinalValue,Copy_u8BitOffset,Copy_u8BitWidth,Copy_u16Value);break;
			case MDIO_PORTC	:
				Local_u16FinalValue=MDIOC->ODR;
				MDIOC->ODR=BitManipulationSetBits(Local_u16FinalValue,Copy_u8BitOffset,Copy_u8BitWidth,Copy_u16Value);break;

		}

	return Local_u8ErrorStatus;
}
u8 MDIO_voidReadChannelGroup(u8 Copy_u8Port, u8 Copy_u8BitOffset,u8 Copy_u8BitWidth, u16 * Copy_pu16Value)
{
	u8 Local_u8ErrorStatus=OK;
	u16 Local_u16InitialValue;
	switch(Copy_u8Port)
			{
		/*then the complement of the BitMask is anded with ODR content */
		/*then the output is ored with the shifted required value*/
				case MDIO_PORTA	:
					Local_u16InitialValue=MDIOA->IDR;
				*Copy_pu16Value=BitManipulationGetBits(Local_u16InitialValue,Copy_u8BitOffset,Copy_u8BitWidth);break;
				case MDIO_PORTB	:
					Local_u16InitialValue=MDIOB->IDR;
					*Copy_pu16Value=BitManipulationGetBits(Local_u16InitialValue,Copy_u8BitOffset,Copy_u8BitWidth);break;
				case MDIO_PORTC	:
					Local_u16InitialValue=MDIOC->IDR;
					*Copy_pu16Value=BitManipulationGetBits(Local_u16InitialValue,Copy_u8BitOffset,Copy_u8BitWidth);break;

			}
	return Local_u8ErrorStatus;

}

