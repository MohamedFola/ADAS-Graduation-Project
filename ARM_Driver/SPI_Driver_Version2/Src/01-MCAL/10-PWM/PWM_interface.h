/***************************************************************************/
/******************      Author : Ahmad Bassiony ,Mohab Ahmed  *************/
/***********************   			  Layer : MCAL 		  ******************/
/************************ 			 Version : 1.0   ***********************/
/************************** 		  SWC : PWM      ***********************/
/***************************************************************************/

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

void MPWM2_voidInit(void);
void MPWM3_voidInit(void);
void MPWM4_voidInit(void);

u8 MPWM2_SetDutyCycle(u8 Copy_u8ChannelNumber,u16 Copy_u16DutyCycle);
u8 MPWM3_SetDutyCycle(u8 Copy_u8ChannelNumber,u16 Copy_u16DutyCycle);
u8 MPWM4_SetDutyCycle(u8 Copy_u8ChannelNumber,u16 Copy_u16DutyCycle);

u8 MPWM2_SetPeriodAndDuty(u8 Copy_u8ChannelNumber,u16 Copy_u16Period,u16 Copy_u16DutyCycle);
u8 MPWM3_SetPeriodAndDuty(u8 Copy_u8ChannelNumber,u16 Copy_u16Period,u16 Copy_u16DutyCycle);
u8 MPWM4_SetPeriodAndDuty(u8 Copy_u8ChannelNumber,u16 Copy_u16Period,u16 Copy_u16DutyCycle);

#define CH1 1  /*for PWM2 :A0		for PWM3 :A6*/
#define CH2 2  /*for PWM2 :A1		for PWM3 :A7*/
#define CH3 3  /*for PWM2 :A2		for PWM3 :B0*/
#define CH4 4  /*for PWM2 :A3		for PWM3 :B1*/

#endif /* PWM_INTERFACE_H_ */
