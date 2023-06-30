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


//u8 MOTOR_voidMove ( MOTOR_t* Copy_Pins , u8 Copy_u8Direction , u16 Copy_u16Speed_Left, u16 Copy_u16Speed_Right  )
u8 MOTOR_voidMove ( MOTOR_t* Copy_Pins , u8 Copy_u8Direction , u16 Copy_u16Speed_L, u16 Copy_u16Speed_R  )

{

//	u16 Copy_u16Speed_L ,Copy_u16Speed_R;
//	Copy_u16Speed_L = MOTOR_u16Map(Copy_u16Speed_Left, 0, 600, 0, 200);
//	Copy_u16Speed_R = MOTOR_u16Map(Copy_u16Speed_Right, 0, 600, 0, 200);

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
u16 MOTOR_u16Map(u16 InputVal,u16 Min1,u16 Max1,u16 Min2,u16 Max2)
{
	u16 Local_s32Range2Diff,Local_s32Range1Diff,Local_s32Output;
	Local_s32Range2Diff=Max2-Min2;  // 200
	Local_s32Range1Diff=Max1-Min1;	//600
	Local_s32Output=(((InputVal-Min1)*Local_s32Range2Diff)/Local_s32Range1Diff)+Min2;
	return Local_s32Output;

}
