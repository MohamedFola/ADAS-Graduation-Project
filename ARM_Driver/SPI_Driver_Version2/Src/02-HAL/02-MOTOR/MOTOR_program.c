/*
 * MOT_program.c
 *
 *  Created on: Mar 8, 2023
 *      Author: speedTECH
 */

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "MOTOR_config.h"
#include "MOTOR_interface.h"
#include "MOTOR_private.h"

#include "../../01-MCAL/02-DIO/DIO_interface.h"
#include "../../01-MCAL/10-PWM/PWM_interface.h"


void MOTOR_voidEnable (  MOTOR_t* Copy_Pins )
{
	// enable the two drivers
	MDIO_u8WriteChannel( Copy_Pins->L_EN_PORT, Copy_Pins->L_EN_PIN, MDIO_PIN_HIGH );
	MDIO_u8WriteChannel( Copy_Pins->R_EN_PORT, Copy_Pins->R_EN_PIN, MDIO_PIN_HIGH );
}


void MOTOR_voidStop ( MOTOR_t* Copy_Pins )
{
	// disable the two drivers
	MDIO_u8WriteChannel( Copy_Pins->L_EN_PORT, Copy_Pins->L_EN_PIN, MDIO_PIN_LOW );
	MDIO_u8WriteChannel( Copy_Pins->R_EN_PORT, Copy_Pins->R_EN_PIN, MDIO_PIN_LOW );
}


u8 MOTOR_voidMove ( u8 Copy_u8MotorNumber, u8 Copy_u8Dir, u16 Copy_u16Speed )
{
	u8 Local_u8ErrorStaus=OK;

	switch( Copy_u8MotorNumber )
	{
	case MOTOR1:
		if      ( Copy_u8Dir == MOTOR_FORWARD  ) { MDIO_u8WriteChannel(MDIO_PORTA, MDIO_PIN1, MDIO_PIN_HIGH); MDIO_u8WriteChannel(MDIO_PORTA, MDIO_PIN1, MDIO_PIN_LOW); }
		else if ( Copy_u8Dir == MOTOR_BACKWARD ) { MDIO_u8WriteChannel(MDIO_PORTA, MDIO_PIN1, MDIO_PIN_HIGH); MDIO_u8WriteChannel(MDIO_PORTA, MDIO_PIN0, MDIO_PIN_LOW); }
		break;

	case MOTOR2:
		if      ( Copy_u8Dir == MOTOR_FORWARD  ) MPWM2_SetDutyCycle( CH3, Copy_u16Speed);
		else if ( Copy_u8Dir == MOTOR_BACKWARD ) MPWM2_SetDutyCycle( CH4, Copy_u16Speed);
		break;

	default: Local_u8ErrorStaus = NOK; break;
	}


	return Local_u8ErrorStaus;
}
