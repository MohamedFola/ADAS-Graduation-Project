/*
 * MOT_program.c
 *
 *  Created on: Mar 8, 2023
 *      Author: speedTECH
 */

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"



#include "../../01-MCAL/02-DIO/DIO_interface.h"
#include "../../01-MCAL/08-TIM/TIM_interface.h"
#include "../../01-MCAL/08-TIM/TIM_private.h"
#include "../../01-MCAL/10-PWM/PWM_interface.h"

#include "MOTOR_config.h"
#include "MOTOR_interface.h"
#include "MOTOR_private.h"
void MOTOR_voidStop ( MOTOR_t* Copy_Pins )
{
	MDIO_u8WriteChannel(Copy_Pins->MOTOR_PORT, Copy_Pins->L_PWM_PIN, MDIO_PIN_LOW);
	MDIO_u8WriteChannel(Copy_Pins->MOTOR_PORT, Copy_Pins->R_PWM_PIN, MDIO_PIN_LOW);
}


u8 MOTOR_voidMove ( MOTOR_t* Copy_Pins , u8 Copy_u8Direction , u16 Copy_u16Speed_L, u16 Copy_u16Speed_R  )
{
	u8 Local_u8ErrorStaus = OK;
	static u8 Local_PerDir;

	if ( Copy_u16Speed_L > 100 )
	{
		Copy_u16Speed_L = 100;
	}

	if ( Copy_u16Speed_R > 100 )
	{
		Copy_u16Speed_R = 100;
	}

	if ( Copy_u8Direction != Local_PerDir || Copy_u16Speed_L  )
		switch(Copy_u8Direction)
		{
		case MOTOR_FORWARD:
			MDIO_u8WriteChannel(Copy_Pins->MOTOR_PORT, Copy_Pins->L_DIR_PIN, MDIO_PIN_HIGH);
			MDIO_u8WriteChannel(Copy_Pins->MOTOR_PORT, Copy_Pins->R_DIR_PIN, MDIO_PIN_HIGH);

			break;
		case MOTOR_BACKWARD:
			MDIO_u8WriteChannel(Copy_Pins->MOTOR_PORT, Copy_Pins->L_DIR_PIN, MDIO_PIN_LOW);
			MDIO_u8WriteChannel(Copy_Pins->MOTOR_PORT, Copy_Pins->R_DIR_PIN, MDIO_PIN_LOW);

			break;
		default:
			MDIO_u8WriteChannel(Copy_Pins->MOTOR_PORT, Copy_Pins->L_PWM_PIN, MDIO_PIN_LOW);
			MDIO_u8WriteChannel(Copy_Pins->MOTOR_PORT, Copy_Pins->R_PWM_PIN, MDIO_PIN_LOW);
		}


	if ( TIM2->CCR2 != Copy_u16Speed_L || TIM2->CCR4 != Copy_u16Speed_R)
	{
		MPWM2_SetDutyCycle( CH2, Copy_u16Speed_L);
		MPWM2_SetDutyCycle( CH4, Copy_u16Speed_R);
	}


	return Local_u8ErrorStaus;
}
