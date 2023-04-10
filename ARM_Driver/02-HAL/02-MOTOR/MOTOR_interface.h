/*
 * MOT_interface.h
 *
 *  Created on: Mar 8, 2023
 *      Author: speedTECH
 */

#ifndef _MOTOR_INTERFACE_H_
#define _MOTOR_INTERFACE_H_


typedef struct
{
	u8 R_DIR_PIN  :  4;
	u8 L_DIR_PIN  :  4;
	u8 R_PWM_PIN  :  4;
	u8 L_PWM_PIN  :  4;
	u8 MOTOR_PORT: 2;
}MOTOR_t;


#define MOTOR1           1
#define MOTOR2			 2

#define MOTOR_BACKWARD   1
#define MOTOR_FORWARD    2





void MOTOR_voidStop ( MOTOR_t* Copy_Pins );

u8 MOTOR_voidMove ( MOTOR_t* Copy_Pins , u8 Copy_u8Direction , u16 Copy_u16Speed_L, u16 Copy_u16Speed_R  );


#endif /* _MOTOR_INTERFACE_H_ */
