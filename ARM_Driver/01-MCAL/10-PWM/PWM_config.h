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
#define PWM_MODE PWM_MODE_2

#define PWM_POLARITY	ACTIVE_HIGH

#define PWM_PERIOD		200

#define PWM2_CHANNEL_1 ENABLED
#define PWM2_CHANNEL_2 ENABLED
#define PWM2_CHANNEL_3 ENABLED
#define PWM2_CHANNEL_4 ENABLED

#define PWM3_CHANNEL_1 ENABLED
#define PWM3_CHANNEL_2 ENABLED
#define PWM3_CHANNEL_3 ENABLED
#define PWM3_CHANNEL_4 ENABLED




#endif /* PWM_CONFIG_H_ */
