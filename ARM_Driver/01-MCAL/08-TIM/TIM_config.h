/***************************************************************************/
/******************      Author : Ahmad Bassiony ,Mohab Ahmed  *************/
/***********************   			  Layer : MCAL 		  ******************/
/************************ 			 Version : 1.0   ***********************/
/************************** 		  SWC : TIM      ***********************/
/***************************************************************************/


#ifndef    	TIM_CONFIG_H
#define    	TIM_CONFIG_H
			
/*  UEV event sources Selection		
UEV - > updates the value of the auto reload register
1.ALL_SOURCES :
-Counter overflow/underflow
-Setting the UG bit
-Update generation through the slave mode controller
OVERFLOW_UNDERFLOW_ONLY :
2.Only counter overflow/underflow generates an update interrupt.
*/
#define		TIM2_UPDATE_REQUEST_SOURCE			ALL_SOURCES
#define		TIM3_UPDATE_REQUEST_SOURCE			ALL_SOURCES		
#define		TIM4_UPDATE_REQUEST_SOURCE			ALL_SOURCES

/* Counting Direction
1.UP_COUNTER
2.DOWN_COUNTER
***NOTE :	WE CAN ONLY SET A DIRECTION OF COUNTING AT MODE 0 !! ***/


#define		TIM2_COUNTER_DIRECTION		UP_COUNTER
#define		TIM3_COUNTER_DIRECTION		UP_COUNTER
#define		TIM4_COUNTER_DIRECTION		UP_COUNTER

/*  Center-aligned mode selection
1.CENTER_ALIGN_MODE0 (MODE0 UP ONLY OR DOWN ONLY)
2.CENTER_ALIGN_MODE1 (MODE1 UP AND DOWN WITH UNDERFLOW INTERRUPTS ONLY)
3.CENTER_ALIGN_MODE2 (MODE2 UP AND DOWN WITH OVERFLOW INTERRUPTS  ONLY)
4.CENTER_ALIGN_MODE3 (MODE3 UP AND DOWN WITH BOTH OVERFLOW AND UNDERFLOW INTERRUPTS)
*/
#define		TIM2_CENTER_ALIGNED_MODE	 	CENTER_ALIGN_MODE0
#define		TIM3_CENTER_ALIGNED_MODE	 	CENTER_ALIGN_MODE0
#define		TIM4_CENTER_ALIGNED_MODE	 	CENTER_ALIGN_MODE0


/* Auto Reload Preload Configuration
1.ARR_NOT_BUFFERED : TIMx_ARR register is not buffered
(You will not wait for the initial reload value to trigger the interrupt to
reload the new value given to the ARR )
2.ARR_BUFFERED: 		TIMx_ARR register is buffered
(You will wait for the initial reload value to trigger the interrupt to
 reload the new value given to the ARR)
*/

#define 	TIM2_AUTO_RELOAD_PRELOAD 	ARR_NOT_BUFFERED
#define 	TIM3_AUTO_RELOAD_PRELOAD 	ARR_NOT_BUFFERED
#define 	TIM4_AUTO_RELOAD_PRELOAD 	ARR_NOT_BUFFERED


/***
Capture/Compare interrupt enable
1.ENABLED
2.DISABLED
***/

#define 	TIM2_CAPTURE_COMPARE_INTRUPT_STATUS				DISABLED
#define 	TIM3_CAPTURE_COMPARE_INTRUPT_STATUS				DISABLED
#define 	TIM4_CAPTURE_COMPARE_INTRUPT_STATUS				DISABLED


/**Write the Prescale clock value any number between 1->65536**/
#define 	TIM2_PRESCALE_VALUE								800
#define 	TIM3_PRESCALE_VALUE								800
#define 	TIM4_PRESCALE_VALUE								1


#endif
