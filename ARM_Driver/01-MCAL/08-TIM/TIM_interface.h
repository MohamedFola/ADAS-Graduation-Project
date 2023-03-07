/***************************************************************************/
/******************      Author : Ahmad Bassiony ,Mohab Ahmed  *************/
/***********************   			  Layer : MCAL 		  ******************/
/************************ 			 Version : 1.0   ***********************/
/************************** 		  SWC : TIM      ***********************/
/***************************************************************************/

#ifndef    	TIM_INTERFACE_H
#define    	TIM_INTERFACE_H
			
void  MTIM2_voidInit(void);
void  MTIM3_voidInit(void);
void  MTIM4_voidInit(void);

u8 MTIM2_voidSetBusyWait(u16 Copy_u16Ticks);
u8 MTIM3_voidSetBusyWait(u16 Copy_u16Ticks);
u8 MTIM4_voidSetBusyWait(u16 Copy_u16Ticks);

u8 MTIM2_u8SetIntervalSingle(u16 Copy_u16Ticks);
u8 MTIM3_u8SetIntervalSingle(u16 Copy_u16Ticks);
u8 MTIM4_u8SetIntervalSingle(u16 Copy_u16Ticks);

u8 MTIM2_u8SetIntervalPeriodic(u16 Copy_u16Ticks);
u8 MTIM3_u8SetIntervalPeriodic(u16 Copy_u16Ticks);
u8 MTIM4_u8SetIntervalPeriodic(u16 Copy_u16Ticks);

void  MTIM2_voidResetCount(void);
void  MTIM3_voidResetCount(void);
void  MTIM4_voidResetCount(void);

void MTIM2_voidStartCounter(void);
void MTIM3_voidStartCounter(void);
void MTIM4_voidStartCounter(void);

void MTIM2_voidStopCounter(void);
void MTIM3_voidStopCounter(void);
void MTIM4_voidStopCounter(void);

u16 MTIM2_u16GetElapsedTime(void);
u16 MTIM3_u16GetElapsedTime(void);
u16 MTIM4_u16GetElapsedTime(void);

u16 MTIM2_u16GetRemainingTime(void); 
u16 MTIM3_u16GetRemainingTime(void);
u16 MTIM4_u16GetRemainingTime(void);


void MTIM2_voidConfigICU(void);
void MTIM3_voidConfigICU(void);
void MTIM4_voidConfigICU(void);

u8 MTIM2_u8ICU(u16 *Copy_u16Period,u16 *Copy_u16PulseWidth);
u8 MTIM3_u8ICU(u16 *Copy_u16Period,u16 *Copy_u16PulseWidth);
u8 MTIM4_u8ICU(u16 *Copy_u16Period,u16 *Copy_u16PulseWidth);

u8 MTIM2_u8SetCallBackFunc(void (*Copy_ptrFunc)(void));
u8 MTIM3_u8SetCallBackFunc(void (*Copy_ptrFunc)(void));
u8 MTIM4_u8SetCallBackFunc(void (*Copy_ptrFunc)(void));

#endif
