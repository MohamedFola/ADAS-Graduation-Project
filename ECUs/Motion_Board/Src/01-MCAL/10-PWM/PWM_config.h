/***************************************************************************/
/******************      Author : Ahmad Bassiony ,Mohab Ahmed  *************/
/***********************   			  Layer : MCAL 		  ******************/
/************************ 			 Version : 1.0   ***********************/
/************************** 		  SWC : PWM      ***********************/
/***************************************************************************/
#ifndef PWM_CONFIG_H_
#define PWM_CONFIG_H_

/*
1.PWM_MODE_1
2.PWM_MODE_2
Note:PWM1 in upcounting Channel 1 is active while in downcounting channel 1 is inactive
 	 PWM2 in upcounting Channel 1 is inactive while in downcounting  channel 2 is active
 * */
#define PWM2_MODE 			PWM_MODE_2
#define PWM3_MODE 			PWM_MODE_2
#define PWM4_MODE 			PWM_MODE_2

/*
Pwm polarity :
 You can set the polarity of the Bit of the Pwm for each timer 
 Active_High
 Active_Low
*/
#define PWM_TIM2POLARITY	ACTIVE_HIGH
#define PWM_TIM3POLARITY	ACTIVE_HIGH
#define PWM_TIM4POLARITY	ACTIVE_HIGH

/*The period of the PWM is set to  20 MS
1 Sec  - > 10000 Tick

*/
#define PWM2_PERIOD		200
#define PWM3_PERIOD		200
#define PWM4_PERIOD		200


/*The enbale of each Channel and here is the 
pin out maping 
for PWM2_CHANNEL_1:A0		for PWM3_CHANNEL_1 :A6
for PWM2_CHANNEL_2:A1		for PWM3_CHANNEL_2 :A7
for PWM2_CHANNEL_3:A2		for PWM3_CHANNEL_3 :B0
for PWM2_CHANNEL_4:A3		for PWM3_CHANNEL_4 :B1
*/



#define PWM2_CHANNEL_1 ENABLED
#define PWM2_CHANNEL_2 ENABLED
#define PWM2_CHANNEL_3 ENABLED
#define PWM2_CHANNEL_4 ENABLED

#define PWM3_CHANNEL_1 ENABLED
#define PWM3_CHANNEL_2 ENABLED
#define PWM3_CHANNEL_3 ENABLED
#define PWM3_CHANNEL_4 ENABLED

#define PWM4_CHANNEL_1 ENABLED
#define PWM4_CHANNEL_2 ENABLED
#define PWM4_CHANNEL_3 ENABLED
#define PWM4_CHANNEL_4 ENABLED


#endif /* PWM_CONFIG_H_ */
