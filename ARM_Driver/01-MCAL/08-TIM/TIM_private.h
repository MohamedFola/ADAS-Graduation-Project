/***************************************************************************/
/******************      Author : Ahmad Bassiony ,Mohab Ahmed  *************/
/***********************   			  Layer : MCAL 		  ******************/
/************************ 			 Version : 1.0   ***********************/
/************************** 		  SWC : TIM      ***********************/
/***************************************************************************/

#ifndef    	TIM_PRIVATE_H
#define    	TIM_PRIVATE_H
/*Timer 2 and Timer 3 base Adresess*/
#define    	TIM2_BASE_ADD         0x40000000
#define    	TIM3_BASE_ADD         0x40000400




typedef struct {
volatile  u32	CR1    			;
volatile  u32	CR2    			;
volatile  u32	SMCR    		;
volatile  u32	DIER			;
volatile  u32	SR				;
volatile  u32	EGR				;
volatile  u32	CCMR1			;
volatile  u32	CCMR2			;
volatile  u32	CCER			;
volatile  u32	CNT				;
volatile  u32	PSC				;
volatile  u32	ARR				;


volatile  u32	Reserved    	;


volatile  u32	CCR1    		;
volatile  u32	CCR2    		;
volatile  u32	CCR3    		;
volatile  u32	CCR4    		;
volatile  u32	Reserved1    	;

volatile  u32	DCR    			;
volatile  u32	DMAR    		;

}TIM_MemMap_t;



#define TIM2  ((volatile TIM_MemMap_t*)(TIM2_BASE_ADD))
#define TIM3  ((volatile TIM_MemMap_t*)(TIM3_BASE_ADD))


#define TIM_CR1_CEN			0
#define TIM_CR1_UDIS		1
#define TIM_CR1_URS			2
#define TIM_CR1_OPM			3
#define TIM_CR1_DIR			4
#define TIM_CR1_CMS1		5
#define TIM_CR1_CMS2		6
#define TIM_CR1_ARPE		7
#define TIM_CR1_CKD1		8
#define TIM_CR1_CKD2		9




/*Update request source*/
#define ALL_SOURCES 				0
#define OVERFLOW_UNDERFLOW_ONLY		1





#define UP_COUNTER 			0
#define DOWN_COUNTER		1
/*Center align modes*/
#define CENTER_ALIGN_MODE0				0
#define CENTER_ALIGN_MODE1				1
#define CENTER_ALIGN_MODE2				2
#define CENTER_ALIGN_MODE3				3

/* Auto Reload Buffer */
#define ARR_NOT_BUFFERED 				0
#define ARR_BUFFERED					1	



/*Interrupt enable register*/
#define TIM_DIER_UIE					0
#define TIM_DIER_CC1IE					1


#define TIM_DIER_CC2IE					2
#define TIM_DIER_CC3IE					3
#define TIM_DIER_CC4IE					4





/*Event generation register*/
/*THIS BIT RELOADS THE AUTO RELOAD REGISTER WITHOUT TRIGRING AN INTERPT*/
#define TIM_EGR_UG						0	
#define TIM_EGR_CC1G					1
#define TIM_EGR_CC2G					2


/*Status Register*/
#define TIM_SR_UIF						0



#define ENABLED							1
#define DISABLED						0
#endif