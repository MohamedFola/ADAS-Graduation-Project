/***************************************************************/
/******************       Author : Ahmad Bassiony *************/
/***********************   Layer : MCAL   **********************/
/************************  Version : 1.00  *********************/
/************************** SWC : TIM  ************************/
/***************************************************************/


#ifndef    	TIM_CONFIG_H
#define    	TIM_CONFIG_H
			
/*  UEV event sources Selection		
UEV - > updates the value of the auto reload register 
ALL_SOURCES : 
-Counter overflow/underflow
– Setting the UG bit
– Update generation through the slave mode controller
OVERFLOW_UNDERFLOW_ONLY :
-Only counter overflow/underflow generates an update interrupt.
*/
#define		TIM2_UPDATE_REQUEST_SOURCE			ALL_SOURCES	
#define		TIM3_UPDATE_REQUEST_SOURCE			ALL_SOURCES		

/*  Direction
UP_COUNTER 	
DOWN_COUNTER
***NOTE :	WE CAN ONLY SET A DIRECTION OF COUNTING AT MODE 0 !! ****
*/


#define		TIM2_COUNTER_DIRECTION		DOWN_COUNTER	
#define		TIM3_COUNTER_DIRECTION		DOWN_COUNTER


	/*  Center-aligned mode selection
MODE0 UP ONLY OR DOWN ONLY
MODE1 UP AND DOWN WITH UNDERFLOW INTRP ONLY
MODE2 UP AND DOWN WITH OVERFLOW INTRP ONLY	
MODE3 UP AND DOWN WITH BOTH OVERFLOW AND UNDERFLOW INTRPS 	
DOWN_COUNTER
*/
#define		TIM2_CENTER_ALIGNED_MODE	 	CENTER_ALIGN_MODE0
#define		TIM3_CENTER_ALIGNED_MODE	 	CENTER_ALIGN_MODE0


/* Auto-reload preload config
ARR_NOT_BUFFERED : TIMx_ARR register is not buffered
// you will not wait for the intial reload value to trigger the interupt to reload the new value given to the ARR 
ARR_BUFFERED: 		TIMx_ARR register is buffered
// you will  wait for the intial reload value to trigger the interupt to reload the new value given to the ARR 
*/

#define 	TIM2_AUTO_RELOAD_PRELOAD 	ARR_NOT_BUFFERED
#define 	TIM3_AUTO_RELOAD_PRELOAD 	ARR_NOT_BUFFERED


/***
Capture/Compare interupt enable 
***/

#define 	TIM2_CAPTURE_COMPARE_INTRUPT_STATUS				ENABLED	
#define 	TIM3_CAPTURE_COMPARE_INTRUPT_STATUS				DISABLED



/**Write the prescale clock value any number between 1->65536**/
#define 	TIM2_PRESCALE_VALUE								800
#define 	TIM3_PRESCALE_VALUE								800



#endif
