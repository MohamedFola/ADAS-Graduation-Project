/***************************************************************************/
/******************      Author : Ahmad Bassiony ,Mohab Ahmed  *************/
/***********************   			  Layer : MCAL 		  ******************/
/************************ 			 Version : 1.0   ***********************/
/************************** 		  SWC : TIM      ***********************/
/***************************************************************************/


#include    "../../00-LIB/STD_TYPES.h"
#include    "../../00-LIB/BIT_MATH.h"

#include	"TIM_interface.h"
#include	"TIM_private.h"
#include	"TIM_config.h"


volatile void (*Global_voidTIM2PtrCallbackFunc) (void);
volatile void (*Global_voidTIM3PtrCallbackFunc) (void);

u8 Global_u8FlagTIM2=DISABLED;
u8 Global_u8FlagTIM3=DISABLED;

/*Timer 2 Initialization */
void  MTIM2_voidInit(void)
{ 

	/* Set the Request Event Source*/
#if TIM2_UPDATE_REQUEST_SOURCE ==	ALL_SOURCES
	CLR_BIT(TIM2->CR1,TIM_CR1_URS);
#elif TIM2_UPDATE_REQUEST_SOURCE == OVERFLOW_UNDERFLOW_ONLY
	SET_BIT(TIM2->CR1,TIM_CR1_URS);
#else
	CLR_BIT(TIM2->CR1,TIM_CR1_URS);
#endif

	/* Set Center Align Mode */
#if TIM2_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE0
	CLR_BIT(TIM2->CR1,TIM_CR1_CMS1);
	CLR_BIT(TIM2->CR1,TIM_CR1_CMS2);
	/*WE CAN ONLY SET A DIRECTION OF COUNTING AT MODE 0 !!*/
	/* SET DIRECTION OF COUNTING */
#if	TIM2_COUNTER_DIRECTION==UP_COUNTER
	CLR_BIT(TIM2->CR1,TIM_CR1_DIR);
#else
	SET_BIT(TIM2->CR1,TIM_CR1_DIR);

#endif

#elif TIM2_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE1
	SET_BIT(TIM2->CR1,TIM_CR1_CMS1);
	CLR_BIT(TIM2->CR1,TIM_CR1_CMS2);


#elif TIM2_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE2
	CLR_BIT(TIM2->CR1,TIM_CR1_CMS1);
	SET_BIT(TIM2->CR1,TIM_CR1_CMS2);


#elif TIM2_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE3
	SET_BIT(TIM2->CR1,TIM_CR1_CMS1);
	SET_BIT(TIM2->CR1,TIM_CR1_CMS2);

#else
#error ("wrong algin mode ")

#endif


#if TIM2_AUTO_RELOAD_PRELOAD == ARR_BUFFERED
	SET_BIT(TIM2->CR1,TIM_CR1_ARPE);
#else
	CLR_BIT(TIM2->CR1,TIM_CR1_ARPE);
#endif

#if TIM2_CAPTURE_COMPARE_INTRUPT_STATUS ==ENABLED
	SET_BIT(TIM2->DIER,TIM_DIER_CC1IE);
#else
	CLR_BIT(TIM2->DIER,TIM_DIER_CC1IE);
#endif

	/*Set the required Prescaler value*/
	/*the eqn:F=fCK_PSC / (PSC[15:0] + 1)*/
#if (TIM2_PRESCALE_VALUE>0 && TIM2_PRESCALE_VALUE<=65536)
	TIM2->PSC=TIM2_PRESCALE_VALUE-1;
#else
#error ("wrong prescale  ")
#endif

}

/*Timer 3 Initialization */
void  MTIM3_voidInit(void)
{

	/* Set the Request Event Source*/
#if TIM3_UPDATE_REQUEST_SOURCE ==	ALL_SOURCES
	CLR_BIT(TIM3->CR1,TIM_CR1_URS);
#elif TIM3_UPDATE_REQUEST_SOURCE == OVERFLOW_UNDERFLOW_ONLY
	SET_BIT(TIM3->CR1,TIM_CR1_URS);
#else
	CLR_BIT(TIM3->CR1,TIM_CR1_URS);
#endif

	/* Set Center Align Mode */
#if TIM3_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE0
	CLR_BIT(TIM3->CR1,TIM_CR1_CMS1);
	CLR_BIT(TIM3->CR1,TIM_CR1_CMS2);
	/*WE CAN ONLY SET A DIRECTION OF COUNTING AT MODE 0 !!*/
	/* SET DIRECTION OF COUNTING */
#if	TIM3_COUNTER_DIRECTION==UP_COUNTER
	CLR_BIT(TIM3->CR1,TIM_CR1_DIR);
#else
	SET_BIT(TIM3->CR1,TIM_CR1_DIR);

#endif

#elif TIM3_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE1
	SET_BIT(TIM3->CR1,TIM_CR1_CMS1);
	CLR_BIT(TIM3->CR1,TIM_CR1_CMS2);


#elif TIM3_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE2
	CLR_BIT(TIM3->CR1,TIM_CR1_CMS1);
	SET_BIT(TIM3->CR1,TIM_CR1_CMS2);


#elif TIM3_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE3
	SET_BIT(TIM3->CR1,TIM_CR1_CMS1);
	SET_BIT(TIM3->CR1,TIM_CR1_CMS2);

#else
#error ("wrong algin mode ")

#endif


#if TIM3_AUTO_RELOAD_PRELOAD == ARR_BUFFERED
	SET_BIT(TIM3->CR1,TIM_CR1_ARPE);
#else
	CLR_BIT(TIM3->CR1,TIM_CR1_ARPE);
#endif


#if TIM3_CAPTURE_COMPARE_INTRUPT_STATUS ==ENABLED
	SET_BIT(TIM3->DIER,TIM_DIER_CC1IE);
#else
	CLR_BIT(TIM3->DIER,TIM_DIER_CC1IE);
#endif

	/*Set the required Prescaler value*/
	/*the eqn:F=fCK_PSC / (PSC[15:0] + 1)*/
#if (TIM3_PRESCALE_VALUE>0 && TIM3_PRESCALE_VALUE<=65536)
	TIM3->PSC=TIM3_PRESCALE_VALUE-1;
#else
#error ("wrong prescale  ")
#endif

}


u8 MTIM2_voidSetBusyWait(u16 Copy_u16Ticks)
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16Ticks<=65536)
	{
		/*Reload the auto reload register with the required ticks*/
		TIM2->ARR=Copy_u16Ticks;
		/*Enable the counter*/
		MTIM2_voidStartCounter();
		/*Busy wait until the UIF flag is raised*/
		while (GET_BIT(TIM2->SR,TIM_SR_UIF)==0)
		{
			asm("NOP");
		}
		/*Clearing the UIF flag by software to be able to be raised again*/
		CLR_BIT(TIM2->SR,TIM_SR_UIF);
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	return Local_u8ErrorStatus;
}	
u8 MTIM3_voidSetBusyWait(u16 Copy_u16Ticks)
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16Ticks<=65536)
	{
		/*Reload the auto reload register with the required ticks*/
		TIM3->ARR=Copy_u16Ticks;
		/*Enable the counter*/
		MTIM3_voidStartCounter();
		/*Busy wait until the UIF flag is raised*/
		while (GET_BIT(TIM3->SR,TIM_SR_UIF)==0)
		{
			asm("NOP");
		}
		/*Clearing the UIF flag by software to be able to be raised again*/
		CLR_BIT(TIM3->SR,TIM_SR_UIF);
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	return Local_u8ErrorStatus;

}
/*Enable the counter to Timer 2 and down the flag to be able for another interrupt to enter the ISR*/
void MTIM2_voidStartCounter(void)
{
	Global_u8FlagTIM2=DISABLED;
	SET_BIT(TIM2->CR1,TIM_CR1_CEN);
}
/*Enable the counter to Timer 3 and down the flag to be able for another interrupt to enter the ISR*/
void MTIM3_voidStartCounter(void)
{
	Global_u8FlagTIM3=DISABLED;
	SET_BIT(TIM3->CR1,TIM_CR1_CEN);
}
/*Disable the counter of Timer 2 and down the flag to be able for another interrupt to enter the ISR*/
void MTIM2_voidStopCounter(void)
{
	CLR_BIT(TIM2->CR1,TIM_CR1_CEN);
	Global_u8FlagTIM2=DISABLED;
}
/*Disable the counter of Timer 3 and down the flag to be able for another interrupt to enter the ISR*/
void MTIM3_voidStopCounter(void)
{
	CLR_BIT(TIM3->CR1,TIM_CR1_CEN);
	Global_u8FlagTIM3=DISABLED;
}
/*Calculating The Elapsed Time for Timer 2*/
u16 MTIM2_u16GetElapsedTime(void)
{
	return (TIM2->ARR-TIM2->CNT);
}
/*Calculating The Elapsed Time for Timer 3*/
u16 MTIM3_u16GetElapsedTime(void)
{
	return (TIM3->ARR-TIM3->CNT);
}
/*Calculating The Remaining Time for Timer 2*/
u16 MTIM2_u16GetRemainingTime(void)
{
	return (TIM2->CNT);
}
/*Calculating The Remaining Time for Timer 3*/
u16 MTIM3_u16GetRemainingTime(void)
{
	return (TIM3->CNT);
}

/*Timer 2 Asynchronous single Interval*/
u8 MTIM2_u8SetIntervalSingle(u16 Copy_u16Ticks)
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16Ticks<=65536)
	{
		/*Update Interrupt Enable*/
		SET_BIT(TIM2->DIER,TIM_DIER_UIE);
		/*Reload the auto reload register with the required ticks*/
		TIM2->ARR=Copy_u16Ticks;
		/*Enable the counter*/
		MTIM2_voidStartCounter();
		/*Enable One Pulse mode*/
		SET_BIT(TIM2->CR1,TIM_CR1_OPM);
		/* To differentiate between the OPM trigger and the CEN enable trigger
		 * and the overflow and underflow */
		Global_u8FlagTIM2=ENABLED;
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	return Local_u8ErrorStatus;

}
/*Timer 3 Asynchronous single Interval*/
u8 MTIM3_u8SetIntervalSingle(u16 Copy_u16Ticks)

{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16Ticks<=65536)
	{
		/*Update Interrupt Enable*/
		SET_BIT(TIM3->DIER,TIM_DIER_UIE);
		/*Reload the auto reload register with the required ticks*/
		TIM3->ARR=Copy_u16Ticks;
		/*Enable the counter*/
		MTIM3_voidStartCounter();
		/*Enable One Pulse mode*/
		SET_BIT(TIM3->CR1,TIM_CR1_OPM);
		/* To differentiate between the OPM trigger and the CEN enable trigger
		 * and the overflow and underflow */
		Global_u8FlagTIM3=ENABLED;
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	return Local_u8ErrorStatus;
}

/*Timer 2 Asynchronous Periodic Interval*/
u8 MTIM2_u8SetIntervalPeriodic(u16 Copy_u16Ticks)
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16Ticks<=65536)
	{
		/*Update Interrupt Enable*/
		SET_BIT(TIM2->DIER,TIM_DIER_UIE);
		/*Reload the auto reload register with the required ticks*/
		TIM2->ARR=Copy_u16Ticks;
		/*Enable the counter*/
		MTIM2_voidStartCounter();
		/* To differentiate between the OPM trigger and the CEN enable trigger
		 * and the overflow and underflow */
		Global_u8FlagTIM2=ENABLED;
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	return Local_u8ErrorStatus;
}
/*Timer 3 Asynchronous Periodic Interval*/
u8 MTIM3_u8SetIntervalPeriodic(u16 Copy_u16Ticks)


{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16Ticks<=65536)
	{
		/*Update Interrupt Enable*/
		SET_BIT(TIM3->DIER,TIM_DIER_UIE);
		/*Reload the auto reload register with the required ticks*/
		TIM3->ARR=Copy_u16Ticks;
		/*Enable the counter*/
		MTIM3_voidStartCounter();
		/* To differentiate between the OPM trigger and the CEN enable trigger
		 * and the overflow and underflow */
		Global_u8FlagTIM3=ENABLED;
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	return Local_u8ErrorStatus;
}

/*Callback function to Timer 2*/
u8 MTIM2_u8SetCallBackFunc(void (*Copy_ptrFunc)(void)) 
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_ptrFunc ==NULL)
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	else
	{
		Global_voidTIM2PtrCallbackFunc=Copy_ptrFunc;
	}
	return Local_u8ErrorStatus;
}
/*Callback function to Timer 3*/
u8 MTIM3_u8SetCallBackFunc(void (*Copy_ptrFunc)(void)) 
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_ptrFunc ==NULL)
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	else
	{
		Global_voidTIM3PtrCallbackFunc=Copy_ptrFunc;
	}
	return Local_u8ErrorStatus;
}
/*Timer 2 ISR Handler*/
void TIM2_IRQHandler(void)
{
	if(Global_voidTIM2PtrCallbackFunc!=NULL)
	{
		/*Check if the coming interrupt from the underflow or overflow or not*/
		if(Global_u8FlagTIM2==ENABLED)
		{
			Global_voidTIM2PtrCallbackFunc();
		}
		/*Clear the update interrupt flag to be raised in the next interrupt*/
		CLR_BIT(TIM2->SR,TIM_SR_UIF);

	}

}
/*Timer 3 ISR Handler*/
void TIM3_IRQHandler(void)
{
	if(Global_voidTIM3PtrCallbackFunc!=NULL)
	{
		/*Check if the coming interrupt from the underflow or overflow or not*/
		if(Global_u8FlagTIM3==ENABLED)
		{
			Global_voidTIM3PtrCallbackFunc();
		}
		/*Clear the update interrupt flag to be raised in the next interrupt*/
		CLR_BIT(TIM3->SR,TIM_SR_UIF);
	}

}
