#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

static void (*Global_pvEXTICallBackFunc[16])(void) = {NULL};

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

	if(Copy_u8Line <= MEXTI_LINE15)
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

	if(Copy_u8Line <= MEXTI_LINE15)
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

	if(Copy_u8Line <= MEXTI_LINE15)
	{
		SET_BIT(EXTI->SWIER,Copy_u8Line);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

u8 MEXTI_u8SetSignalLatch(u8 Copy_u8Line, u8 Copu_u8Mode)
{
	u8 Local_u8ErrorState= OK;

	/*Disable Interrupt*/
	CLR_BIT(EXTI->IMR,Copy_u8Line);

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


	return Local_u8ErrorState;
}

u8 MEXTI_voidSetCallBackFunc(u8 Copy_u8Line, void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;

	if(Copy_u8Line <= MEXTI_LINE15)
	{
		if(Copy_pvNotificationFunc != NULL)
		{
			/*Declaring the call back function*/
			Global_pvEXTICallBackFunc[Copy_u8Line] = Copy_pvNotificationFunc;
		}
		else
		{
			Local_u8ErrorState = NULL_POINTER;
		}

	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

void EXTI0_IRQHandler(void)
{
	if(Global_pvEXTICallBackFunc[MEXTI_LINE0] != NULL)
	{
		/*Calling the Call back function*/
		Global_pvEXTICallBackFunc[MEXTI_LINE0]();

		/*Clearing Pending bit*/
		SET_BIT(EXTI->PR,MEXTI_LINE0);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI1_IRQHandler(void)
{
	if(Global_pvEXTICallBackFunc[MEXTI_LINE1] != NULL)
	{
		/*Calling the Call back function*/
		Global_pvEXTICallBackFunc[MEXTI_LINE1]();

		/*Clearing Pending bit*/
		SET_BIT(EXTI->PR,MEXTI_LINE1);
	}
	else
	{
		/*Do Nothing*/
	}

}

void EXTI2_IRQHandler(void)
{
	if(Global_pvEXTICallBackFunc[MEXTI_LINE2] != NULL)
	{
		/*Calling the Call back function*/
		Global_pvEXTICallBackFunc[MEXTI_LINE2]();

		/*Clearing Pending bit*/
		SET_BIT(EXTI->PR,MEXTI_LINE2);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI3_IRQHandler(void)
{
	if(Global_pvEXTICallBackFunc[MEXTI_LINE3] != NULL)
	{
		/*Calling the Call back function*/
		Global_pvEXTICallBackFunc[MEXTI_LINE3]();

		/*Clearing Pending bit*/
		SET_BIT(EXTI->PR,MEXTI_LINE3);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI4_IRQHandler(void)
{
	if(Global_pvEXTICallBackFunc[MEXTI_LINE4] != NULL)
	{
		/*Calling the Call back function*/
		Global_pvEXTICallBackFunc[MEXTI_LINE4]();

		/*Clearing Pending bit*/
		SET_BIT(EXTI->PR,MEXTI_LINE4);
	}
	else
	{
		/*Do Nothing*/
	}
}


void EXTI5_IRQHandler(void)
{
	if(Global_pvEXTICallBackFunc[MEXTI_LINE5] != NULL)
	{
		/*Calling the Call back function*/
		Global_pvEXTICallBackFunc[MEXTI_LINE5]();

		/*Clearing Pending bit*/
		SET_BIT(EXTI->PR,MEXTI_LINE5);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI6_IRQHandler(void)
{
	if(Global_pvEXTICallBackFunc[MEXTI_LINE6] != NULL)
	{
		/*Calling the Call back function*/
		Global_pvEXTICallBackFunc[MEXTI_LINE6]();

		/*Clearing Pending bit*/
		SET_BIT(EXTI->PR,MEXTI_LINE6);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI7_IRQHandler(void)
{
	if(Global_pvEXTICallBackFunc[MEXTI_LINE7] != NULL)
	{
		/*Calling the Call back function*/
		Global_pvEXTICallBackFunc[MEXTI_LINE7]();

		/*Clearing Pending bit*/
		SET_BIT(EXTI->PR,MEXTI_LINE7);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI8_IRQHandler(void)
{
	if(Global_pvEXTICallBackFunc[MEXTI_LINE8] != NULL)
	{
		/*Calling the Call back function*/
		Global_pvEXTICallBackFunc[MEXTI_LINE8]();

		/*Clearing Pending bit*/
		SET_BIT(EXTI->PR,MEXTI_LINE8);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI9_IRQHandler(void)
{
	if(Global_pvEXTICallBackFunc[MEXTI_LINE9] != NULL)
	{
		/*Calling the Call back function*/
		Global_pvEXTICallBackFunc[MEXTI_LINE9]();

		/*Clearing Pending bit*/
		SET_BIT(EXTI->PR,MEXTI_LINE9);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI10_IRQHandler(void)
{
	if(Global_pvEXTICallBackFunc[MEXTI_LINE10] != NULL)
	{
		/*Calling the Call back function*/
		Global_pvEXTICallBackFunc[MEXTI_LINE10]();

		/*Clearing Pending bit*/
		SET_BIT(EXTI->PR,MEXTI_LINE10);
	}
	else
	{
		/*Do Nothing*/
	}
}

