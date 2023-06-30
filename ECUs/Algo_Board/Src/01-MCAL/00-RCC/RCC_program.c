#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "../00-RCC/RCC_config.h"
#include "../00-RCC/RCC_interface.h"
#include "../00-RCC/RCC_private.h"
#include "../00-RCC/RCC_register.h"


void RCC_voidInitSysClock(void)
{
	/*Selecting the Clock switch of the bus*/
#if SYSTEM_CLK == SYS_CLK_HSI
	/*Choosing system clock switch without choosing prescaler*/
	RCC->CFGR = 0;

	/*Turn ON HSI with no trimming*/
	RCC->CR = 0x00000081;

#elif SYSTEM_CLK == SYS_CLK_HSE_CRYSTAL
	/*Selecting HSE as system clock without choosing prescaler*/
	RCC->CFGR = 1;

	/*Selecting HSE with no bypass and trimming*/
	RCC->CR = 0x00010080;

#elif SYSTEM_CLK == SYS_CLK_HSE_RC_CLK
	/*Selecting HSE as system clock without choosing prescaler*/
	RCC->CFGR = 1;

	/*Selecting HSE with bypass and no trimming*/
	RCC->CR = 0x00050080;

#elif SYSTEM_CLK == SYS_CLK_PLL
/*Selecting the source of PLL*/
#if PLL_INPUT == RCC_PLL_IN_HSE
	/*Set PLL Source with HSE with choosen Multiplier*/
	RCC->CFGR = 0x00010002 | PLL_MUL_VALUE;
	/*Enable PLL with HSE with not bypassed oscillator*/
	RCC->CR = 0x01010080;

#elif PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	/*Set PLL Source with HSE/2 with choosen Multiplier*/
	RCC->CFGR = 0x00030002 | PLL_MUL_VALUE;

	/*Enable PLL with HSE with not bypassed oscillator*/
	RCC->CR = 0x01010080;


#elif PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	/*Set PLL Source with HSI/2 with choosen Multiplier*/
	RCC->CFGR = 0x00000002 | PLL_MUL_VALUE;
	/*Enable PLL with HSI*/
	RCC->CR = 0x01000081;
#endif


#else
#error("You chose Wrong Clock Type")
#endif

	/*Selecting Clock security system*/
#if RCC_CSS_ENABLE == ENABLE
	SET_BIT(RCC->CR,RCC_CR_CSSON);
#elif RCC_CSS_ENABLE == DISABLE
	CLR_BIT(RCC->CR,RCC_CR_CSSON);
#endif

}


u8 RCC_voidEnableClock(u8 Copy_u8PeripheralID,u8 Copy_u8BusId)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8PeripheralID <= 31)
	{
		switch (Copy_u8BusId)
		{
		case RCC_AHB:  SET_BIT(RCC->AHBENR,	Copy_u8PeripheralID); break;
		case RCC_APB1: SET_BIT(RCC->APB1ENR,Copy_u8PeripheralID); break;
		case RCC_APB2: SET_BIT(RCC->APB2ENR,Copy_u8PeripheralID); break;
		default: 	   Local_u8ErrorState = NOK; break;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}


u8 RCC_voidDisableClock(u8 Copy_u8PeripheralID,u8 Copy_u8BusId)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8PeripheralID <= 31)
	{
		switch (Copy_u8BusId)
		{
		case RCC_AHB:  CLR_BIT(RCC->AHBENR,	Copy_u8PeripheralID); break;
		case RCC_APB1: CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralID); break;
		case RCC_APB2: CLR_BIT(RCC->APB2ENR,Copy_u8PeripheralID); break;
		default: 	   Local_u8ErrorState = NOK; break;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
