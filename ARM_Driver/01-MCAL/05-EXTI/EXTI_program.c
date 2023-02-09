#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"



void MEXTI_voidInit()
{
#if EXTI_MODE == RISING_EDGE
	SET_BIT(EXTI->RTSR,EXTI_LINE);
#elif EXTI_MODE == FALLING_EDGE
	SET_BIT(EXTI->FTSR,EXTI_LINE);
#elif EXTI_MODE == ON_CHANGE
	SET_BIT(EXTI->RTSR,EXTI_LINE);
	SET_BIT(EXTI->FTSR,EXTI_LINE);
#else
#error "Wrong Configuration"

#endif

	/*Disable Interrupt*/
	CLR_BIT(EXTI->IMR,EXTI_LINE);
}


u8 MEXTI_u8EnableEXTI(u8 Copy_u8Line)
{
	u8 Local_u8ErrorState= OK;

	if(Copy_u8Line <= LINE15)
	{
		SET_BIT(EXTI->IMR,Copy_u8Line);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

u8 MEXTI_u8DisableEXTI(u8 Copy_u8Line)
{
	u8 Local_u8ErrorState= OK;

	if(Copy_u8Line <= LINE15)
	{
		CLR_BIT(EXTI->IMR,Copy_u8Line);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

u8 MEXTI_u8SwTrigger(u8 Copy_u8Line)
{
	u8 Local_u8ErrorState= OK;

	if(Copy_u8Line <= LINE15)
	{
		SET_BIT(EXTI->SWIER,Copy_u8Line);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8SetSignalLatch(u8 Copy_u8Line, u8 Copu_u8Mode)
{
	u8 Local_u8ErrorState= OK;

	switch(Copu_u8Mode)
	{
	case RISING_EDGE: 	SET_BIT(EXTI->RTSR,Copy_u8Line); break;
	case FALLING_EDGE:	SET_BIT(EXTI->FTSR,Copy_u8Line); break;
	case ON_CHANGE:
		SET_BIT(EXTI->RTSR,Copy_u8Line);
		SET_BIT(EXTI->FTSR,Copy_u8Line);
		break;
	default: Local_u8ErrorState = NOK; break;
	}

	/*Enable Interrupt*/
	SET_BIT(EXTI->IMR,Copy_u8Line);

	return Local_u8ErrorState;
}
