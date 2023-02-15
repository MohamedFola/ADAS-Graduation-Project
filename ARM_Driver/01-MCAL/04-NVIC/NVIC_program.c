#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_register.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = OK;

	if(Copy_u8IntNumber <=31)
	{
		NVIC_ISER0 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <=63)
	{
		Copy_u8IntNumber -= 32; 	/*To deal with the interrupt number from the first bit*/
		NVIC_ISER1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = OK;

	if(Copy_u8IntNumber <=31)
	{
		NVIC_ICER0 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <=63)
	{
		Copy_u8IntNumber -= 32;		/*To deal with the interrupt number from the first bit*/
		NVIC_ICER1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

u8 MNVIC_u8SetPendingFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = OK;

	if(Copy_u8IntNumber <=31)
	{
		NVIC_ISPR0 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <=63)
	{
		Copy_u8IntNumber -= 32;		/*To deal with the interrupt number from the first bit*/
		NVIC_ISPR1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

u8 MNVIC_u8ClrPendingFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = OK;

	if(Copy_u8IntNumber <=31)
	{
		NVIC_ICPR0 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <=63)
	{
		Copy_u8IntNumber -= 32;		/*To deal with the interrupt number from the first bit*/
		NVIC_ICPR1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber, u8* Copy_u8ActiveFlagReading)
{
	u8 Local_u8ErrorState = OK;

	if(Copy_u8IntNumber <=31)
	{
		*Copy_u8ActiveFlagReading = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <=63)
	{
		Copy_u8IntNumber -= 32;		/*To deal with the interrupt number from the first bit*/
		*Copy_u8ActiveFlagReading = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

u8 MNVIC_u8SetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubGroupPriority)
{
	u8 Local_u8ErrorState = OK;

	/*Calculate the priority to put in IPR register in the allowed 4 bits*/
	u8 Local_u8Priority = (Copy_u8SubGroupPriority | (Copy_u8GroupPriority<<((MNVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300)/256)));

	#define SCB_AIRCR  *((u32*)0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;

	if(Copy_s8IntID < 60)
	{
		NVIC_IPR[Copy_s8IntID] = (Local_u8Priority << 4);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
