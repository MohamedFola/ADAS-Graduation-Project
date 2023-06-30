/*
 * STK_program.c
 *
 *  Created on: Feb 1, 2023
 *      Author: speedTECH
 */

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "../03-STK/STK_interface.h"
#include "../03-STK/STK_private.h"
#include "../03-STK/STK_config.h"

volatile void (*Global_voidPtrCallbackFunc) (void);
static u8 MSTK_u8ModeOfinterval;
void MSTK_voidClkSrcInit(void)
{
#if STK_CLK_SRC == AHB_DIVIDE_BY_8
	CLR_BIT(MSTK->MSTK_CTRL,MSTK_CLK_SRC); /* clk source AHB/8 */
#elif STK_CLK_SRC == AHB
	SET_BIT(MSTK->MSTK_CTRL,MSTK_CLK_SRC);
#endif
}
u8 MSTK_voidClearCount(void)
{
	u8 Local_u8CountFlag;
	Local_u8CountFlag=GET_BIT(MSTK->MSTK_CTRL,MSTK_CNT_FLAG); /*clearing counter flag by reading it when it reaches overflow*/
	return Local_u8CountFlag;
}
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/*Clear Value register */
	MSTK ->MSTK_VAL =0x00;
	/*Set Load register to number of ticks*/
	MSTK ->MSTK_LOAD =Copy_u32Ticks;
	/*Enable STK peripheral*/
	SET_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE);
	/*Busy wait until the count down flag is raised */
	while(MSTK_voidClearCount()==0);
}
void MSTK_u8SetIntervalSingle(u32 Copy_u32Ticks)
{
	/*Clear Value register */
	MSTK ->MSTK_VAL =0x00;
	/*Set Load register to number of ticks*/
	MSTK ->MSTK_LOAD =Copy_u32Ticks;
	/*Enable the STK underflow interrupt*/
	SET_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_EN);
	/*Enable STK peripheral*/
	SET_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE);
	MSTK_u8ModeOfinterval=MSTK_SINGLE_INTERVAL;

}

void MSTK_u8SetIntervalPeriodic(u32 Copy_u32Ticks)
{
	/*Clear Value register */
	MSTK ->MSTK_VAL =0x00;
	/*Set Load register to number of ticks*/
	MSTK ->MSTK_LOAD =Copy_u32Ticks;
	/*Enable the STK underflow interrupt*/
	SET_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_EN);
	/*Enable STK peripheral*/
	SET_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE);
	MSTK_u8ModeOfinterval=MSTK_PERIODIC_INTERVAL;
}

void MSTK_voidStopInterval(void)
{
	/*Disable the STK peripheral*/
	CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE);
	/*Clearing load Register*/
	MSTK->MSTK_LOAD=0x00;
	/*Clearing value Register*/
	MSTK->MSTK_VAL=0x00;
}
u32 MSTK_u32GetElapsedTime(void)
{
	return  (MSTK->MSTK_LOAD - MSTK -> MSTK_VAL);
}
u32 MSTK_u32GetRemainingTime(void)
{
	return MSTK -> MSTK_VAL ;
}

u8 MSTK_u8SetCallBackFunc(void (*Copy_ptrFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_ptrFunc ==NULL)
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	else
	{
		Global_voidPtrCallbackFunc=Copy_ptrFunc;
	}
	return Local_u8ErrorStatus;
}
void SysTick_Handler(void)
{
	if(Global_voidPtrCallbackFunc!=NULL)
	{
		if(MSTK_u8ModeOfinterval==MSTK_SINGLE_INTERVAL)
		{
			/*Clear load and value registers*/
			MSTK_voidStopInterval();
			/*Disable the interrupt*/
			CLR_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_EN);
		}
		Global_voidPtrCallbackFunc();
	}
}
