/***************************************************************************/
/******************      Author : Ahmad Bassiony ,Mohab Ahmed  *************/
/***********************   			  Layer : MCAL 		  ******************/
/************************ 			 Version : 1.0   ***********************/
/************************** 		  SWC : PWM      ***********************/
/***************************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"

/*PWM of Timer 2 Initialization*/
void MPWM2_voidInit(void)
{
	/*choosing the PWM mode*/
#if(PWM2_CHANNEL_1==ENABLED)
	#if(PWM2_MODE==PWM_MODE_1)
		/*For Channel 1*/
		CLR_BIT(TIM2->CCMR1,TIM_CCMR1_OC1M0);
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC1M1);
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC1M2);

	#elif (PWM2_MODE==PWM_MODE_2)
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC1M0);
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC1M1);
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC1M2);
	#else
		#error("Wrong PWM Mode")
	#endif

	/*the CC1 channel is configured as output.*/
	CLR_BIT(TIM2->CCMR1,TIM_CCMR1_CC1S0);
	CLR_BIT(TIM2->CCMR1,TIM_CCMR1_CC1S1);
	

#endif


#if(PWM2_CHANNEL_2==ENABLED)
	#if(PWM2_MODE==PWM_MODE_1)
		/*For Channel 2*/
		CLR_BIT(TIM2->CCMR1,TIM_CCMR1_OC2M0);
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC2M1);
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC2M2);
	
	#elif (PWM2_MODE==PWM_MODE_2)
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC2M0);
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC2M1);
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC2M2);
	#else
		#error("Wrong PWM Mode")
	#endif
	
		/*the CC2 channel is configured as output.*/
		CLR_BIT(TIM2->CCMR1,TIM_CCMR1_CC2S0);
		CLR_BIT(TIM2->CCMR1,TIM_CCMR1_CC2S1);
	
	
#endif



#if(PWM2_CHANNEL_3==ENABLED)
	#if(PWM2_MODE==PWM_MODE_1)
		/*For Channel 1*/
		CLR_BIT(TIM2->CCMR2,TIM_CCMR2_OC3M0);
		SET_BIT(TIM2->CCMR2,TIM_CCMR2_OC3M1);
		SET_BIT(TIM2->CCMR2,TIM_CCMR2_OC3M2);
	
	#elif (PWM2_MODE==PWM_MODE_2)
		SET_BIT(TIM2->CCMR2,TIM_CCMR2_OC3M0);
		SET_BIT(TIM2->CCMR2,TIM_CCMR2_OC3M1);
		SET_BIT(TIM2->CCMR2,TIM_CCMR2_OC3M2);
	#else
		#error("Wrong PWM Mode")
	#endif

	/*the CC3 channel is configured as output.*/
	CLR_BIT(TIM2->CCMR2,TIM_CCMR2_CC3S0	);
	CLR_BIT(TIM2->CCMR2,TIM_CCMR2_CC3S1);
	/*Set the Polarity of all the channels */

#endif

#if(PWM2_CHANNEL_4==ENABLED)
	#if(PWM2_MODE==PWM_MODE_1)
		/*For Channel 1*/
		CLR_BIT(TIM2->CCMR2,TIM_CCMR2_OC4M0	);
		SET_BIT(TIM2->CCMR2,TIM_CCMR2_OC4M1	);
		SET_BIT(TIM2->CCMR2,TIM_CCMR2_OC4M2);
	
	#elif (PWM2_MODE==PWM_MODE_2)
		SET_BIT(TIM2->CCMR2,TIM_CCMR2_OC4M0);
		SET_BIT(TIM2->CCMR2,TIM_CCMR2_OC4M1);
		SET_BIT(TIM2->CCMR2,TIM_CCMR2_OC4M2);
	#else
		#error("Wrong PWM Mode")
	#endif

	/*the CC4 channel is configured as output.*/
	CLR_BIT(TIM2->CCMR2,TIM_CCMR2_CC4S0	);
	CLR_BIT(TIM2->CCMR2,TIM_CCMR2_CC4S1	);
	
#endif


/*Set the Polarity of all the channels in TIM2*/
#if(PWM2_POLARITY==ACTIVE_HIGH)
	CLR_BIT(TIM2->CCER,TIM_CCER_CC1P);


#elif(PWM2_POLARITY==ACTIVE_LOW)
	SET_BIT(TIM2->CCER,TIM_CCER_CC1P);
#else
	#error("Wrong PWM Polarity")
#endif

}


/*PWM of Timer 3 Initialization*/
void MPWM3_voidInit(void)
{
	/*choosing the PWM mode*/
#if(PWM3_CHANNEL_1==ENABLED)
	#if(PWM3_MODE==PWM_MODE_1)
		/*For Channel 1*/
		CLR_BIT(TIM3->CCMR1,TIM_CCMR1_OC1M0);
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC1M1);
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC1M2);
	
	#elif (PWM3_MODE==PWM_MODE_2)
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC1M0);
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC1M1);
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC1M2);
	#else
		#error("Wrong PWM Mode")
	#endif

	/*the CC1 channel is configured as output.*/
	CLR_BIT(TIM3->CCMR1,TIM_CCMR1_CC1S0);
	CLR_BIT(TIM3->CCMR1,TIM_CCMR1_CC1S1);
	
#endif


#if(PWM3_CHANNEL_2==ENABLED)
	#if(PWM3_MODE==PWM_MODE_1)
		/*For Channel 2*/
		CLR_BIT(TIM3->CCMR1,TIM_CCMR1_OC2M0);
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC2M1);
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC2M2);
	
	#elif (PWM3_MODE==PWM_MODE_2)
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC2M0);
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC2M1);
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC2M2);
	#else
		#error("Wrong PWM Mode")
	#endif

	/*the CC2 channel is configured as output.*/
	CLR_BIT(TIM3->CCMR1,TIM_CCMR1_CC2S0);
	CLR_BIT(TIM3->CCMR1,TIM_CCMR1_CC2S1);
	
#endif



#if(PWM3_CHANNEL_3==ENABLED)
	#if(PWM3_MODE==PWM_MODE_1)
		/*For Channel 1*/
		CLR_BIT(TIM3->CCMR2,TIM_CCMR2_OC3M0);
		SET_BIT(TIM3->CCMR2,TIM_CCMR2_OC3M1);
		SET_BIT(TIM3->CCMR2,TIM_CCMR2_OC3M2);
	
	#elif (PWM3_MODE==PWM_MODE_2)
		SET_BIT(TIM3->CCMR2,TIM_CCMR2_OC3M0);
		SET_BIT(TIM3->CCMR2,TIM_CCMR2_OC3M1);
		SET_BIT(TIM3->CCMR2,TIM_CCMR2_OC3M2);
	#else
		#error("Wrong PWM Mode")
	#endif

	/*the CC3 channel is configured as output.*/
	CLR_BIT(TIM3->CCMR2,TIM_CCMR2_CC3S0	);
	CLR_BIT(TIM3->CCMR2,TIM_CCMR2_CC3S1);
	
#endif

#if(PWM3_CHANNEL_4==ENABLED)
	#if(PWM3_MODE==PWM_MODE_1)
		/*For Channel 1*/
		CLR_BIT(TIM3->CCMR2,TIM_CCMR2_OC4M0	);
		SET_BIT(TIM3->CCMR2,TIM_CCMR2_OC4M1	);
		SET_BIT(TIM3->CCMR2,TIM_CCMR2_OC4M2);
	
	#elif (PWM3_MODE==PWM_MODE_2)
		SET_BIT(TIM3->CCMR2,TIM_CCMR2_OC4M0);
		SET_BIT(TIM3->CCMR2,TIM_CCMR2_OC4M1);
		SET_BIT(TIM3->CCMR2,TIM_CCMR2_OC4M2);
	#else
		#error("Wrong PWM Mode")
	#endif

	/*the CC4 channel is configured as output.*/
	CLR_BIT(TIM3->CCMR2,TIM_CCMR2_CC4S0	);
	CLR_BIT(TIM3->CCMR2,TIM_CCMR2_CC4S1	);
	
#endif


/*Set the Polarity of all the channels */
#if(PWM3_POLARITY==ACTIVE_HIGH)
	CLR_BIT(TIM3->CCER,TIM_CCER_CC1P);


#elif(PWM3_POLARITY==ACTIVE_LOW)
	SET_BIT(TIM3->CCER,TIM_CCER_CC1P);
#else
	#error("Wrong PWM Polarity")
#endif

}

/*PWM of Timer 4 Initialization*/
void MPWM4_voidInit(void)
{
	/*choosing the PWM mode*/
#if(PWM2_CHANNEL_1==ENABLED)
	#if(PWM2_MODE==PWM_MODE_1)
		/*For Channel 1*/
		CLR_BIT(TIM4->CCMR1,TIM_CCMR1_OC1M0);
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC1M1);
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC1M2);

	#elif (PWM2_MODE==PWM_MODE_2)
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC1M0);
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC1M1);
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC1M2);
	#else
		#error("Wrong PWM Mode")
	#endif

	/*the CC1 channel is configured as output.*/
	CLR_BIT(TIM4->CCMR1,TIM_CCMR1_CC1S0);
	CLR_BIT(TIM4->CCMR1,TIM_CCMR1_CC1S1);


#endif


#if(PWM2_CHANNEL_2==ENABLED)
	#if(PWM2_MODE==PWM_MODE_1)
		/*For Channel 2*/
		CLR_BIT(TIM4->CCMR1,TIM_CCMR1_OC2M0);
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC2M1);
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC2M2);

	#elif (PWM2_MODE==PWM_MODE_2)
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC2M0);
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC2M1);
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC2M2);
	#else
		#error("Wrong PWM Mode")
	#endif

		/*the CC2 channel is configured as output.*/
		CLR_BIT(TIM4->CCMR1,TIM_CCMR1_CC2S0);
		CLR_BIT(TIM4->CCMR1,TIM_CCMR1_CC2S1);


#endif



#if(PWM2_CHANNEL_3==ENABLED)
	#if(PWM2_MODE==PWM_MODE_1)
		/*For Channel 1*/
		CLR_BIT(TIM4->CCMR2,TIM_CCMR2_OC3M0);
		SET_BIT(TIM4->CCMR2,TIM_CCMR2_OC3M1);
		SET_BIT(TIM4->CCMR2,TIM_CCMR2_OC3M2);

	#elif (PWM2_MODE==PWM_MODE_2)
		SET_BIT(TIM4->CCMR2,TIM_CCMR2_OC3M0);
		SET_BIT(TIM4->CCMR2,TIM_CCMR2_OC3M1);
		SET_BIT(TIM4->CCMR2,TIM_CCMR2_OC3M2);
	#else
		#error("Wrong PWM Mode")
	#endif

	/*the CC3 channel is configured as output.*/
	CLR_BIT(TIM4->CCMR2,TIM_CCMR2_CC3S0	);
	CLR_BIT(TIM4->CCMR2,TIM_CCMR2_CC3S1);
	/*Set the Polarity of all the channels */

#endif

#if(PWM2_CHANNEL_4==ENABLED)
	#if(PWM2_MODE==PWM_MODE_1)
		/*For Channel 1*/
		CLR_BIT(TIM4->CCMR2,TIM_CCMR2_OC4M0	);
		SET_BIT(TIM4->CCMR2,TIM_CCMR2_OC4M1	);
		SET_BIT(TIM4->CCMR2,TIM_CCMR2_OC4M2);

	#elif (PWM2_MODE==PWM_MODE_2)
		SET_BIT(TIM4->CCMR2,TIM_CCMR2_OC4M0);
		SET_BIT(TIM4->CCMR2,TIM_CCMR2_OC4M1);
		SET_BIT(TIM4->CCMR2,TIM_CCMR2_OC4M2);
	#else
		#error("Wrong PWM Mode")
	#endif

	/*the CC4 channel is configured as output.*/
	CLR_BIT(TIM4->CCMR2,TIM_CCMR2_CC4S0	);
	CLR_BIT(TIM4->CCMR2,TIM_CCMR2_CC4S1	);

#endif


/*Set the Polarity of all the channels in TIM2*/
#if(PWM2_POLARITY==ACTIVE_HIGH)
	CLR_BIT(TIM4->CCER,TIM_CCER_CC1P);


#elif(PWM2_POLARITY==ACTIVE_LOW)
	SET_BIT(TIM4->CCER,TIM_CCER_CC1P);
#else
	#error("Wrong PWM Polarity")
#endif
}

/*Set Duty cycle of PWM of timer 2*/
u8 MPWM2_SetDutyCycle(u8 Copy_u8ChannelNumber,u16 Copy_u16DutyCycle)
{

	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16DutyCycle<=200)
	{
		switch(Copy_u8ChannelNumber)
		{
		case CH1:		/*Maps to PA0*/
			/*Output compare preload enable*/
			SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC1PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIM2->CCER,TIM_CCER_CC1E);
			/*Set the duty cycle in the CCR1 register*/
			TIM2->CCR1=PWM2_PERIOD-Copy_u16DutyCycle;
			break;
		case CH2:	/*Maps to PA1*/
			/*Output compare preload enable*/
			SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC2PE);
			/*Output compare channel 2 enable */
			SET_BIT(TIM2->CCER,TIM_CCER_CC2E);
			/*Set the duty cycle in the CCR1 register*/
			TIM2->CCR2=PWM2_PERIOD-Copy_u16DutyCycle;
			break;
		case CH3:	/*Maps to PA2*/
			/*Output compare preload enable*/
			SET_BIT(TIM2->CCMR2,TIM_CCMR1_OC3PE);
			/*Output compare channel 3 enable */
			SET_BIT(TIM2->CCER,TIM_CCER_CC3E);
			/*Set the duty cycle in the CCR1 register*/
			TIM2->CCR3=PWM2_PERIOD-Copy_u16DutyCycle;
			break;
		case CH4:	/*Maps to PA4*/
			/*Output compare preload enable*/
			SET_BIT(TIM2->CCMR2,TIM_CCMR1_OC4PE);
			/*Output compare channel 4 enable */
			SET_BIT(TIM2->CCER,TIM_CCER_CC4E);
			/*Set the duty cycle in the CCR1 register*/
			TIM2->CCR4=PWM2_PERIOD-Copy_u16DutyCycle;
			break;
		default:Local_u8ErrorStatus=NOK;
		}
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	/*Reload the Period time in the ARR*/
	TIM2->ARR=PWM2_PERIOD;
	/*initialize all the registers by setting the UG bit*/
	SET_BIT(TIM2->EGR,TIM_EGR_UG);
	/*Counter enable*/
	SET_BIT(TIM2->CR1,TIM_CR1_CEN);
	return Local_u8ErrorStatus;

}

/*Set Duty cycle of PWM of timer 3*/
u8 MPWM3_SetDutyCycle(u8 Copy_u8ChannelNumber,u16 Copy_u16DutyCycle)
{

	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16DutyCycle<=200)
	{
		switch(Copy_u8ChannelNumber)
		{
		case CH1:		/*Maps to PA0*/
			/*Output compare preload enable*/
			SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC1PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIM3->CCER,TIM_CCER_CC1E);
			/*Set the duty cycle in the CCR1 register*/
			TIM3->CCR1=PWM3_PERIOD-Copy_u16DutyCycle;
			break;
		case CH2:	/*Maps to PA1*/
			/*Output compare preload enable*/
			SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC2PE);
			/*Output compare channel 2 enable */
			SET_BIT(TIM3->CCER,TIM_CCER_CC2E);
			/*Set the duty cycle in the CCR1 register*/
			TIM3->CCR2=PWM3_PERIOD-Copy_u16DutyCycle;
			break;
		case CH3:	/*Maps to PA2*/
			/*Output compare preload enable*/
			SET_BIT(TIM3->CCMR2,TIM_CCMR1_OC3PE);
			/*Output compare channel 3 enable */
			SET_BIT(TIM3->CCER,TIM_CCER_CC3E);
			/*Set the duty cycle in the CCR1 register*/
			TIM3->CCR3=PWM3_PERIOD-Copy_u16DutyCycle;
			break;
		case CH4:	/*Maps to PA4*/
			/*Output compare preload enable*/
			SET_BIT(TIM3->CCMR2,TIM_CCMR1_OC4PE);
			/*Output compare channel 4 enable */
			SET_BIT(TIM3->CCER,TIM_CCER_CC4E);
			/*Set the duty cycle in the CCR1 register*/
			TIM3->CCR4=PWM3_PERIOD-Copy_u16DutyCycle;
			break;
		default:Local_u8ErrorStatus=NOK;
		}
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	/*Reload the Period time in the ARR*/
	TIM3->ARR=PWM3_PERIOD;
	/*initialize all the registers by setting the UG bit*/
	SET_BIT(TIM3->EGR,TIM_EGR_UG);
	/*Counter enable*/
	SET_BIT(TIM3->CR1,TIM_CR1_CEN);
	return Local_u8ErrorStatus;

}

/*Set Duty cycle of PWM of timer 4*/
u8 MPWM4_SetDutyCycle(u8 Copy_u8ChannelNumber,u16 Copy_u16DutyCycle)
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u16DutyCycle<=200)
	{
		switch(Copy_u8ChannelNumber)
		{
		case CH1:		/*Maps to PA0*/
			/*Output compare preload enable*/
			SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC1PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIM4->CCER,TIM_CCER_CC1E);
			/*Set the duty cycle in the CCR1 register*/
			TIM4->CCR1=PWM4_PERIOD-Copy_u16DutyCycle;
			break;
		case CH2:	/*Maps to PA1*/
			/*Output compare preload enable*/
			SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC2PE);
			/*Output compare channel 2 enable */
			SET_BIT(TIM4->CCER,TIM_CCER_CC2E);
			/*Set the duty cycle in the CCR1 register*/
			TIM4->CCR2=PWM4_PERIOD-Copy_u16DutyCycle;
			break;
		case CH3:	/*Maps to PA2*/
			/*Output compare preload enable*/
			SET_BIT(TIM4->CCMR2,TIM_CCMR1_OC3PE);
			/*Output compare channel 3 enable */
			SET_BIT(TIM4->CCER,TIM_CCER_CC3E);
			/*Set the duty cycle in the CCR1 register*/
			TIM4->CCR3=PWM4_PERIOD-Copy_u16DutyCycle;
			break;
		case CH4:	/*Maps to PA4*/
			/*Output compare preload enable*/
			SET_BIT(TIM4->CCMR2,TIM_CCMR1_OC4PE);
			/*Output compare channel 4 enable */
			SET_BIT(TIM4->CCER,TIM_CCER_CC4E);
			/*Set the duty cycle in the CCR1 register*/
			TIM4->CCR4=PWM4_PERIOD-Copy_u16DutyCycle;
			break;
		default:Local_u8ErrorStatus=NOK;
		}
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	/*Reload the Period time in the ARR*/
	TIM4->ARR=PWM4_PERIOD;
	/*initialize all the registers by setting the UG bit*/
	SET_BIT(TIM4->EGR,TIM_EGR_UG);
	/*Counter enable*/
	SET_BIT(TIM4->CR1,TIM_CR1_CEN);
	return Local_u8ErrorStatus;
}


/*Setting Period and on ticks of PWM of timer 2*/
u8 MPWM2_SetPeriodAndDuty(u8 Copy_u8ChannelNumber,u16 Copy_u16Period,u16 Copy_u16DutyCycle)
{
	u8 Local_u8ErrorStatus=OK;

	switch(Copy_u8ChannelNumber)
	{
	case CH1:		/*Maps to PA0*/
		/*Output compare preload enable*/
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC1PE);
		/*Output compare channel 1 enable */
		SET_BIT(TIM2->CCER,TIM_CCER_CC1E);
		/*Set the duty cycle in the CCR1 register*/
		TIM2->CCR1=Copy_u16Period - Copy_u16DutyCycle;
		break;
	case CH2:	/*Maps to PA1*/
		/*Output compare preload enable*/
		SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC2PE);
		/*Output compare channel 2 enable */
		SET_BIT(TIM2->CCER,TIM_CCER_CC2E);
		/*Set the duty cycle in the CCR1 register*/
		TIM2->CCR2=Copy_u16Period - Copy_u16DutyCycle;
		break;
	case CH3:	/*Maps to PA2*/
		/*Output compare preload enable*/
		SET_BIT(TIM2->CCMR2,TIM_CCMR1_OC3PE);
		/*Output compare channel 3 enable */
		SET_BIT(TIM2->CCER,TIM_CCER_CC3E);
		/*Set the duty cycle in the CCR1 register*/
		TIM2->CCR3=Copy_u16Period - Copy_u16DutyCycle;
		break;
	case CH4:	/*Maps to PA4*/
		/*Output compare preload enable*/
		SET_BIT(TIM2->CCMR2,TIM_CCMR1_OC4PE);
		/*Output compare channel 4 enable */
		SET_BIT(TIM2->CCER,TIM_CCER_CC4E);
		/*Set the duty cycle in the CCR1 register*/
		TIM2->CCR4=Copy_u16Period - Copy_u16DutyCycle;
		break;
	default:Local_u8ErrorStatus=NOK;
	}

	/*Reload the Period time in the ARR*/
	TIM2->ARR=Copy_u16Period;
	/*initialize all the registers by setting the UG bit*/
	SET_BIT(TIM2->EGR,TIM_EGR_UG);
	/*Counter enable*/
	SET_BIT(TIM2->CR1,TIM_CR1_CEN);
	return Local_u8ErrorStatus;
}

/*Setting Period and on ticks of PWM of timer 3*/
u8 MPWM3_SetPeriodAndDuty(u8 Copy_u8ChannelNumber,u16 Copy_u16Period,u16 Copy_u16DutyCycle)
{
	u8 Local_u8ErrorStatus=OK;

	switch(Copy_u8ChannelNumber)
	{
	case CH1:		/*Maps to PA0*/
		/*Output compare preload enable*/
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC1PE);
		/*Output compare channel 1 enable */
		SET_BIT(TIM3->CCER,TIM_CCER_CC1E);
		/*Set the duty cycle in the CCR1 register*/
		TIM3->CCR1=Copy_u16Period - Copy_u16DutyCycle;
		break;
	case CH2:	/*Maps to PA1*/
		/*Output compare preload enable*/
		SET_BIT(TIM3->CCMR1,TIM_CCMR1_OC2PE);
		/*Output compare channel 2 enable */
		SET_BIT(TIM3->CCER,TIM_CCER_CC2E);
		/*Set the duty cycle in the CCR1 register*/
		TIM3->CCR2=Copy_u16Period - Copy_u16DutyCycle;
		break;
	case CH3:	/*Maps to PA2*/
		/*Output compare preload enable*/
		SET_BIT(TIM3->CCMR2,TIM_CCMR1_OC3PE);
		/*Output compare channel 3 enable */
		SET_BIT(TIM3->CCER,TIM_CCER_CC3E);
		/*Set the duty cycle in the CCR1 register*/
		TIM3->CCR3=Copy_u16Period - Copy_u16DutyCycle;
		break;
	case CH4:	/*Maps to PA4*/
		/*Output compare preload enable*/
		SET_BIT(TIM3->CCMR2,TIM_CCMR1_OC4PE);
		/*Output compare channel 4 enable */
		SET_BIT(TIM3->CCER,TIM_CCER_CC4E);
		/*Set the duty cycle in the CCR1 register*/
		TIM3->CCR4=Copy_u16Period - Copy_u16DutyCycle;
		break;
	default:Local_u8ErrorStatus=NOK;
	}


	/*Reload the Period time in the ARR*/
	TIM3->ARR=Copy_u16Period;
	/*initialize all the registers by setting the UG bit*/
	SET_BIT(TIM3->EGR,TIM_EGR_UG);
	/*Counter enable*/
	SET_BIT(TIM3->CR1,TIM_CR1_CEN);
	return Local_u8ErrorStatus;
}

/*Setting Period and on ticks of PWM of timer 3*/
u8 MPWM4_SetPeriodAndDuty(u8 Copy_u8ChannelNumber,u16 Copy_u16Period,u16 Copy_u16DutyCycle)
{
	u8 Local_u8ErrorStatus=OK;

	switch(Copy_u8ChannelNumber)
	{
	case CH1:		/*Maps to PA0*/
		/*Output compare preload enable*/
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC1PE);
		/*Output compare channel 1 enable */
		SET_BIT(TIM4->CCER,TIM_CCER_CC1E);
		/*Set the duty cycle in the CCR1 register*/
		TIM4->CCR1=Copy_u16Period - Copy_u16DutyCycle;
		break;
	case CH2:	/*Maps to PA1*/
		/*Output compare preload enable*/
		SET_BIT(TIM4->CCMR1,TIM_CCMR1_OC2PE);
		/*Output compare channel 2 enable */
		SET_BIT(TIM4->CCER,TIM_CCER_CC2E);
		/*Set the duty cycle in the CCR1 register*/
		TIM4->CCR2=Copy_u16Period - Copy_u16DutyCycle;
		break;
	case CH3:	/*Maps to PA2*/
		/*Output compare preload enable*/
		SET_BIT(TIM4->CCMR2,TIM_CCMR1_OC3PE);
		/*Output compare channel 3 enable */
		SET_BIT(TIM4->CCER,TIM_CCER_CC3E);
		/*Set the duty cycle in the CCR1 register*/
		TIM4->CCR3=Copy_u16Period - Copy_u16DutyCycle;
		break;
	case CH4:	/*Maps to PA4*/
		/*Output compare preload enable*/
		SET_BIT(TIM4->CCMR2,TIM_CCMR1_OC4PE);
		/*Output compare channel 4 enable */
		SET_BIT(TIM4->CCER,TIM_CCER_CC4E);
		/*Set the duty cycle in the CCR1 register*/
		TIM4->CCR4=Copy_u16Period - Copy_u16DutyCycle;
		break;
	default:Local_u8ErrorStatus=NOK;
	}


	/*Reload the Period time in the ARR*/
	TIM4->ARR=Copy_u16Period;
	/*initialize all the registers by setting the UG bit*/
	SET_BIT(TIM4->EGR,TIM_EGR_UG);
	/*Counter enable*/
	SET_BIT(TIM4->CR1,TIM_CR1_CEN);
	return Local_u8ErrorStatus;
}









