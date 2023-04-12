/* this file is used to initialize all the used peripherals and drivers */

#include "init.h"
#include "init.config.h"

void init_hardware ( void )
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock( RCC_GPIOA, RCC_APB2 );
	RCC_voidEnableClock( RCC_GPIOB, RCC_APB2 );
	RCC_voidEnableClock( RCC_GPIOC, RCC_APB2 );

	PORT_voidInit();

#if STK_ENABLE == MOD_ENA
	MSTK_voidClkSrcInit();
#endif

#if TIM2_ENABLE == MOD_ENA
	RCC_voidEnableClock(RCC_TIM2, RCC_APB1);
	MTIM2_voidInit();
#endif

#if TIM3_ENABLE == MOD_ENA
	RCC_voidEnableClock(RCC_TIM3, RCC_APB1);
	MTIM3_voidInit();
#endif

#if TIM4_ENABLE == MOD_ENA
	RCC_voidEnableClock(RCC_TIM4, RCC_APB1);
	MTIM4_voidInit();
#endif


#if PWM2_ENABLE == MOD_ENA
	MPWM2_voidInit();
#endif

#if PWM3_ENABLE == MOD_ENA
	MPWM3_voidInit();
#endif

#if PWM4_ENABLE == MOD_ENA
	MPWM4_voidInit();
#endif


#if ENC_ENABLE == MOD_ENA
	HENC_voidInit();
#endif

}


