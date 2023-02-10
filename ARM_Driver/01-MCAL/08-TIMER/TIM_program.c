/***************************************************************/
/******************       Author : Ahmad Bassiony *************/
/***********************   Layer : MCAL   **********************/
/************************  Version : 1.00  *********************/
/************************** SWC : TIM  ************************/
/***************************************************************/




#include	"STD_TYPES.h"
#include	"Bit_Math.h"

#include	"TIM_interface.h"
#include	"TIM_private.h"
#include	"TIM_config.h"


volatile void (*Global_voidTIM2PtrCallbackFunc) (void);
volatile void (*Global_voidTIM3PtrCallbackFunc) (void);


void  MTIM2_voidInit(void)
{ 

	// set request source
#if TIM2_UPDATE_REQUEST_SOURCE ==	ALL_SOURCES
	CLR_BIT(TIM2->CR1,TIM_CR1_URS);
#elif TIM2_UPDATE_REQUEST_SOURCE == OVERFLOW_UNDERFLOW_ONLY
	SET_BIT(TIM2->CR1,TIM_CR1_URS);
#else
	CLR_BIT(TIM2->CR1,TIM_CR1_URS);
#endif




	//set 	Center Align mode

#if TIM2_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE0
	CLR_BIT(TIM2->CR1,TIM_CR1_CMS1);
	CLR_BIT(TIM2->CR1,TIM_CR1_CMS2);
	// WE CAN ONLY SET A DIRECTION OF COUNTING AT MODE 0 !!
	// SET DIRECTION OF COUNTING
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

	//PRESCALE
	/*F=fCK_PSC / (PSC[15:0] + 1)*/


#if (TIM2_PRESCALE_VALUE>0 && TIM2_PRESCALE_VALUE<=65536)
	TIM2->PSC=TIM2_PRESCALE_VALUE-1;
#else
#error ("wrong prescale  ")
#endif


}
void  MTIM3_voidInit(void)
{

	// set request source 
#if TIM3_UPDATE_REQUEST_SOURCE ==	ALL_SOURCES
	CLR_BIT(TIM3->CR1,TIM_CR1_URS);
#elif TIM3_UPDATE_REQUEST_SOURCE == OVERFLOW_UNDERFLOW_ONLY
	SET_BIT(TIM3->CR1,TIM_CR1_URS);
#else
	CLR_BIT(TIM3->CR1,TIM_CR1_URS);
#endif




	//set 	Center Align mode

#if TIM3_CENTER_ALIGNED_MODE ==	CENTER_ALIGN_MODE0
	CLR_BIT(TIM3->CR1,TIM_CR1_CMS1);
	CLR_BIT(TIM3->CR1,TIM_CR1_CMS2);
	// WE CAN ONLY SET A DIRECTION OF COUNTING AT MODE 0 !!
	// SET DIRECTION OF COUNTING
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

	//PRESCALE
	/*F=fCK_PSC / (PSC[15:0] + 1)*/


#if (TIM3_PRESCALE_VALUE>0 && TIM3_PRESCALE_VALUE<=65536)
	TIM3->PSC=TIM3_PRESCALE_VALUE-1;
#else
#error ("wrong prescale  ")
#endif


}


void MTIM2_voidSetBusyWait(u16 Copy_u16Ticks)
{


	TIM2->ARR=Copy_u16Ticks;
	MTIM2_voidStartCounter();

	while (GET_BIT(TIM2->SR,TIM_SR_UIF)==0)
	{
		asm("NOP");
	}
	CLR_BIT(TIM2->SR,TIM_SR_UIF);
}	
void MTIM3_voidSetBusyWait(u16 Copy_u16Ticks)
{
	TIM3->ARR=Copy_u16Ticks;

	MTIM3_voidStartCounter();

	while (GET_BIT(TIM3->SR,TIM_SR_UIF)==0)
	{
		asm("NOP");
	}
	CLR_BIT(TIM3->SR,TIM_SR_UIF);
}






void MTIM2_voidStartCounter(void)
{

	SET_BIT(TIM2->CR1,TIM_CR1_CEN);

	CLR_BIT(TIM2->SR,TIM_SR_UIF);
}

void MTIM3_voidStartCounter(void)
{
	SET_BIT(TIM3->CR1,TIM_CR1_CEN);
	CLR_BIT(TIM3->SR,TIM_SR_UIF);

}

void MTIM2_voidStopCounter(void)
{
	CLR_BIT(TIM2->CR1,TIM_CR1_CEN);
}
void MTIM3_voidStopCounter(void)
{
	CLR_BIT(TIM3->CR1,TIM_CR1_CEN);
}



u8 MTIM2_u8SetIntervalSingle(u16 Copy_u16Ticks)
{
	//clear the auto reload
	TIM2->ARR=0x00;
	// enable interupt
	SET_BIT(TIM2->DIER,TIM_DIER_UIE);
	// load arr
	TIM2->ARR=Copy_u16Ticks;
	// set to one pluse mode
	SET_BIT(TIM2->CR1,TIM_CR1_OPM);

	SET_BIT(TIM2->CR1,TIM_CR1_CEN);

	//	MTIM2_voidStartCounter();

}
u8 MTIM3_u8SetIntervalSingle(u16 Copy_u16Ticks)

{
	// enable interupt
	SET_BIT(TIM3->DIER,TIM_DIER_UIE);
	// load arr
	TIM3->ARR=Copy_u16Ticks;
	// set to one pluse mode
	SET_BIT(TIM3->CR1,TIM_CR1_OPM);
	MTIM3_voidStartCounter();
}

u8 MTIM2_u8SetIntervalPeriodic(u16 Copy_u16Ticks)
{
	TIM2->ARR=0x00;
	// enable interupt
	SET_BIT(TIM2->DIER,TIM_DIER_UIE);
	// load arr
	TIM2->ARR=Copy_u16Ticks;
	// set to one pluse mode
	CLR_BIT(TIM2->CR1,TIM_CR1_OPM);

	SET_BIT(TIM2->CR1,TIM_CR1_CEN);

	//MTIM2_voidStartCounter();

}
u8 MTIM3_u8SetIntervalPeriodic(u16 Copy_u16Ticks)
{
	// enable interupt
	SET_BIT(TIM3->DIER,TIM_DIER_UIE);
	// load arr
	TIM3->ARR=Copy_u16Ticks;
	// set to one pluse mode
	CLR_BIT(TIM3->CR1,TIM_CR1_OPM);
	MTIM3_voidStartCounter();
}
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




void TIM2_IRQHandler(void)
{
	if(Global_voidTIM2PtrCallbackFunc!=NULL)
	{
		CLR_BIT(TIM2->SR,TIM_SR_UIF);
		Global_voidTIM2PtrCallbackFunc();

	}

}
void TIM3_IRQHandler(void)
{
	if(Global_voidTIM3PtrCallbackFunc!=NULL)
	{
		CLR_BIT(TIM3->SR,TIM_SR_UIF);
		Global_voidTIM3PtrCallbackFunc();

	}

}
