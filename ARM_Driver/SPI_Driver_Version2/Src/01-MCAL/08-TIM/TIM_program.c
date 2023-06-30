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

/*Call Back Functions*/
volatile void (*Global_voidTIM2PtrCallbackFunc) (void);
volatile void (*Global_voidTIM3PtrCallbackFunc) (void);
volatile void (*Global_voidTIM4PtrCallbackFunc) (void);

/*Software Flags*/
u8 Global_u8FlagTIM2=DISABLED;
u8 Global_u8FlagTIM3=DISABLED;
u8 Global_u8FlagTIM4=DISABLED;


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


/*Timer 4 Initialization */
void  MTIM4_voidInit(void)
{

	/* Set the Request Event Source*/
#if TIM4_UPDATE_REQUEST_SOURCE ==	ALL_SOURCES
	CLR_BIT(TIM4->CR1,TIM_CR1_URS);
#elif TIM4_UPDATE_REQUEST_SOURCE == OVERFLOW_UNDERFLOW_ONLY
	SET_BIT(TIM4->CR1,TIM_CR1_URS);
#else
	CLR_BIT(TIM4->CR1,TIM_CR1_URS);
#endif

	/* Set Center Align Mode */
#if TIM4_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE0
	CLR_BIT(TIM4->CR1,TIM_CR1_CMS1);
	CLR_BIT(TIM4->CR1,TIM_CR1_CMS2);
	/*WE CAN ONLY SET A DIRECTION OF COUNTING AT MODE 0 !!*/
	/* SET DIRECTION OF COUNTING */
#if	TIM4_COUNTER_DIRECTION==UP_COUNTER
	CLR_BIT(TIM4->CR1,TIM_CR1_DIR);
#else
	SET_BIT(TIM4->CR1,TIM_CR1_DIR);

#endif

#elif TIM4_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE1
	SET_BIT(TIM4->CR1,TIM_CR1_CMS1);
	CLR_BIT(TIM4->CR1,TIM_CR1_CMS2);


#elif TIM4_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE2
	CLR_BIT(TIM4->CR1,TIM_CR1_CMS1);
	SET_BIT(TIM4->CR1,TIM_CR1_CMS2);


#elif TIM4_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE3
	SET_BIT(TIM4->CR1,TIM_CR1_CMS1);
	SET_BIT(TIM4->CR1,TIM_CR1_CMS2);

#else
#error ("wrong algin mode ")

#endif


#if TIM4_AUTO_RELOAD_PRELOAD == ARR_BUFFERED
	SET_BIT(TIM4->CR1,TIM_CR1_ARPE);
#else
	CLR_BIT(TIM4->CR1,TIM_CR1_ARPE);
#endif


#if TIM4_CAPTURE_COMPARE_INTRUPT_STATUS ==ENABLED
	SET_BIT(TIM4->DIER,TIM_DIER_CC1IE);
#else
	CLR_BIT(TIM4->DIER,TIM_DIER_CC1IE);
#endif

	/*Set the required Prescaler value*/
	/*the eqn:F=fCK_PSC / (PSC[15:0] + 1)*/
#if (TIM4_PRESCALE_VALUE>0 && TIM4_PRESCALE_VALUE<=65536)
	TIM4->PSC=TIM4_PRESCALE_VALUE-1;
#else
#error ("wrong prescaler")
#endif
}

/*Timer 2 Synchronous mode*/
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

/*Timer 3 Synchronous mode*/
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


/*Timer 4 Synchronous mode*/
u8 MTIM4_voidSetBusyWait(u16 Copy_u16Ticks)
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16Ticks<=65536)
	{
		/*Reload the auto reload register with the required ticks*/
		TIM4->ARR=Copy_u16Ticks;
		/*Enable the counter*/
		MTIM4_voidStartCounter();
		/*Busy wait until the UIF flag is raised*/
		while (GET_BIT(TIM4->SR,TIM_SR_UIF)==0)
		{
			asm("NOP");
		}
		/*Clearing the UIF flag by software to be able to be raised again*/
		CLR_BIT(TIM4->SR,TIM_SR_UIF);
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

/*Enable the counter to Timer 4 and down the flag to be able for another interrupt to enter the ISR*/
void MTIM4_voidStartCounter(void)
{
	Global_u8FlagTIM4=DISABLED;
	SET_BIT(TIM4->CR1,TIM_CR1_CEN);
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

/*Disable the counter of Timer 4 and down the flag to be able for another interrupt to enter the ISR*/
void MTIM4_voidStopCounter(void)
{
	CLR_BIT(TIM4->CR1,TIM_CR1_CEN);
	Global_u8FlagTIM4=DISABLED;
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

/*Calculating The Elapsed Time for Timer 4*/
u16 MTIM4_u16GetElapsedTime(void)
{
	return (TIM4->ARR-TIM4->CNT);
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

/*Calculating The Remaining Time for Timer 4*/
u16 MTIM4_u16GetRemainingTime(void)
{
	return (TIM4->CNT);
}

void  MTIM2_voidResetCount(void)
{
	TIM2->CNT=0x00;
}
void  MTIM3_voidResetCount(void)
{
	TIM3->CNT=0x00;
}
void  MTIM4_voidResetCount(void)
{
	TIM4->CNT=0x00;
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

/*Timer 4 Asynchronous single Interval*/
u8 MTIM4_u8SetIntervalSingle(u16 Copy_u16Ticks)

{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16Ticks<=65536)
	{
		/*Update Interrupt Enable*/
		SET_BIT(TIM4->DIER,TIM_DIER_UIE);
		/*Reload the auto reload register with the required ticks*/
		TIM4->ARR=Copy_u16Ticks;
		/*Enable the counter*/
		MTIM4_voidStartCounter();
		/*Enable One Pulse mode*/
		SET_BIT(TIM4->CR1,TIM_CR1_OPM);
		/* To differentiate between the OPM trigger and the CEN enable trigger
		 * and the overflow and underflow */
		Global_u8FlagTIM4=ENABLED;
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

/*Timer 4 Asynchronous Periodic Interval*/
u8 MTIM4_u8SetIntervalPeriodic(u16 Copy_u16Ticks)


{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16Ticks<=65536)
	{
		/*Update Interrupt Enable*/
		SET_BIT(TIM4->DIER,TIM_DIER_UIE);
		/*Reload the auto reload register with the required ticks*/
		TIM4->ARR=Copy_u16Ticks;
		/*Enable the counter*/
		MTIM4_voidStartCounter();
		/* To differentiate between the OPM trigger and the CEN enable trigger
		 * and the overflow and underflow */
		Global_u8FlagTIM4=ENABLED;
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	return Local_u8ErrorStatus;
}


/* TIMER 2 ICU */
void MTIM2_voidConfigICU(void)
{
	/* SLECET CHANNEL 1 TI1*/
	CLR_BIT(TIM2->CR2,TIM_CR2_TI1S);

	/* USE CHANNEL 1 AS INPUT*/
	SET_BIT(TIM2->CCMR1,TIM_CCMR1_CC1S0);
	CLR_BIT(TIM2->CCMR1,TIM_CCMR1_CC1S1);
	/* SELECT RISING EDGE AS ACTIVE POLARITY*/
	CLR_BIT(TIM2->CCER,TIM_CCER_CC1P);

	/* SELECT CHANNEL 2 INPUT*/
	CLR_BIT(TIM2->CCMR1,TIM_CCMR1_CC2S0);
	SET_BIT(TIM2->CCMR1,TIM_CCMR1_CC2S1);

	/* SELECT FALLING EDGE AS ACTIVE POLARITY*/
	SET_BIT(TIM2->CCER,TIM_CCER_CC2P);

	/* FILTER TIMER INPUT 1*/
	SET_BIT(TIM2->SMCR,TIM_SMCR_TS0);
	CLR_BIT(TIM2->SMCR,TIM_SMCR_TS1);
	SET_BIT(TIM2->SMCR,TIM_SMCR_TS2);

	/* CONFIGURE SLAVE MODE IN RESET MODE*/
	CLR_BIT(TIM2->SMCR,TIM_SMCR_SMS0);
	CLR_BIT(TIM2->SMCR,TIM_SMCR_SMS1);
	SET_BIT(TIM2->SMCR,TIM_SMCR_SMS2);


	/* ENABLE CAPTURES OR 2 CHANNELS*/
	SET_BIT(TIM2->CCER,TIM_CCER_CC1E);
	SET_BIT(TIM2->CCER,TIM_CCER_CC2E);

	MTIM2_voidStartCounter();
}


/* TIMER 3 ICU */
void MTIM3_voidConfigICU(void)
{
	/* SLECET CHANNEL 1 TI1*/
	CLR_BIT(TIM3->CR2,TIM_CR2_TI1S);

	/* USE CHANNEL 1 AS INPUT*/
	SET_BIT(TIM3->CCMR1,TIM_CCMR1_CC1S0);
	CLR_BIT(TIM3->CCMR1,TIM_CCMR1_CC1S1);
	/* SELECT RISING EDGE AS ACTIVE POLARITY*/
	CLR_BIT(TIM3->CCER,TIM_CCER_CC1P);

	/* SELECT CHANNEL 2 INPUT*/
	CLR_BIT(TIM3->CCMR1,TIM_CCMR1_CC2S0);
	SET_BIT(TIM3->CCMR1,TIM_CCMR1_CC2S1);

	/* SELECT FALLING EDGE AS ACTIVE POLARITY*/
	SET_BIT(TIM3->CCER,TIM_CCER_CC2P);

	/* FILTER TIMER INPUT 1*/
	SET_BIT(TIM3->SMCR,TIM_SMCR_TS0);
	CLR_BIT(TIM3->SMCR,TIM_SMCR_TS1);
	SET_BIT(TIM3->SMCR,TIM_SMCR_TS2);

	/* CONFIGURE SLAVE MODE IN RESET MODE*/
	CLR_BIT(TIM3->SMCR,TIM_SMCR_SMS0);
	CLR_BIT(TIM3->SMCR,TIM_SMCR_SMS1);
	SET_BIT(TIM3->SMCR,TIM_SMCR_SMS2);


	/* ENABLE CAPTURES OR 2 CHANNELS*/
	SET_BIT(TIM3->CCER,TIM_CCER_CC1E);
	SET_BIT(TIM3->CCER,TIM_CCER_CC2E);

	MTIM3_voidStartCounter();
}

/* TIMER 4 ICU */
void MTIM4_voidConfigICU(void)
{
	/* SLECET CHANNEL 1 TI1*/
	CLR_BIT(TIM4->CR2,TIM_CR2_TI1S);

	/* USE CHANNEL 1 AS INPUT*/
	SET_BIT(TIM4->CCMR1,TIM_CCMR1_CC1S0);
	CLR_BIT(TIM4->CCMR1,TIM_CCMR1_CC1S1);
	/* SELECT RISING EDGE AS ACTIVE POLARITY*/
	CLR_BIT(TIM4->CCER,TIM_CCER_CC1P);

	/* SELECT CHANNEL 2 INPUT*/
	CLR_BIT(TIM4->CCMR1,TIM_CCMR1_CC2S0);
	SET_BIT(TIM4->CCMR1,TIM_CCMR1_CC2S1);

	/* SELECT FALLING EDGE AS ACTIVE POLARITY*/
	SET_BIT(TIM4->CCER,TIM_CCER_CC2P);

	/* FILTER TIMER INPUT 1*/
	SET_BIT(TIM4->SMCR,TIM_SMCR_TS0);
	CLR_BIT(TIM4->SMCR,TIM_SMCR_TS1);
	SET_BIT(TIM4->SMCR,TIM_SMCR_TS2);

	/* CONFIGURE SLAVE MODE IN RESET MODE*/
	CLR_BIT(TIM4->SMCR,TIM_SMCR_SMS0);
	CLR_BIT(TIM4->SMCR,TIM_SMCR_SMS1);
	SET_BIT(TIM4->SMCR,TIM_SMCR_SMS2);


	/* ENABLE CAPTURES OR 2 CHANNELS*/
	SET_BIT(TIM4->CCER,TIM_CCER_CC1E);
	SET_BIT(TIM4->CCER,TIM_CCER_CC2E);

	MTIM4_voidStartCounter();
}


/*Start ICU of timer 2 mode*/
u8 MTIM2_u8ICU(u16 *Copy_u16Period,u16 *Copy_u16PulseWidth)
{
	u8 Local_u8ErrorState=OK;

	/*Polling on rising edge on channel 1*/
	while(GET_BIT(TIM2->SR,TIM_SR_CC1IF) == 0);

	/*Polling on falling edge on channel 2*/
	while(GET_BIT(TIM2->SR,TIM_SR_CC2IF) == 0);
	*Copy_u16PulseWidth = TIM2->CCR2;

	/*Polling on Rising edge on channel 1*/
	while(GET_BIT(TIM2->SR,TIM_SR_CC1IF) == 0);
	*Copy_u16Period = TIM2->CCR1;

	return Local_u8ErrorState;
}

/*Start ICU of timer 3 mode*/
u8 MTIM3_u8ICU(u16 *Copy_u16Period,u16 *Copy_u16PulseWidth)
{
	u8 Local_u8ErrorState=OK;

	/*Polling on rising edge on channel 1*/
	while(GET_BIT(TIM3->SR,TIM_SR_CC1IF) == 0);

	/*Polling on falling edge on channel 2*/
	while(GET_BIT(TIM3->SR,TIM_SR_CC2IF) == 0);
	*Copy_u16PulseWidth = TIM3->CCR2;

	/*Polling on Rising edge on channel 1*/
	while(GET_BIT(TIM3->SR,TIM_SR_CC1IF) == 0);
	*Copy_u16Period = TIM3->CCR1;

	return Local_u8ErrorState;
}

/*Start ICU of timer 4 mode*/
u8 MTIM4_u8ICU(u16 *Copy_u16Period,u16 *Copy_u16PulseWidth)
{
	u8 Local_u8ErrorState=OK;

	/*Polling on rising edge on channel 1*/
	while(GET_BIT(TIM4->SR,TIM_SR_CC1IF) == 0);

	/*Polling on falling edge on channel 2*/
	while(GET_BIT(TIM4->SR,TIM_SR_CC2IF) == 0);
	*Copy_u16PulseWidth = TIM4->CCR2;

	/*Polling on Rising edge on channel 1*/
	while(GET_BIT(TIM4->SR,TIM_SR_CC1IF) == 0);
	*Copy_u16Period = TIM4->CCR1;

	return Local_u8ErrorState;
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

/*Callback function to Timer 4*/
u8 MTIM4_u8SetCallBackFunc(void (*Copy_ptrFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_ptrFunc ==NULL)
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	else
	{
		Global_voidTIM4PtrCallbackFunc=Copy_ptrFunc;
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

/*Timer 4 ISR Handler*/
void TIM4_IRQHandler(void)
{
	if(Global_voidTIM4PtrCallbackFunc!=NULL)
	{
		/*Check if the coming interrupt from the underflow or overflow or not*/
		if(Global_u8FlagTIM4==ENABLED)
		{
			Global_voidTIM4PtrCallbackFunc();
		}
		/*Clear the update interrupt flag to be raised in the next interrupt*/
		CLR_BIT(TIM4->SR,TIM_SR_UIF);
	}

}
