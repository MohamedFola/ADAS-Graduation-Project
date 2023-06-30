/*
 * STK_interface.h
 *
 *  Created on: Feb 1, 2023
 *      Author: speedTECH
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

#define S 		*(1000000)
#define MS 		*(1000)
#define US		*1

void MSTK_voidClkSrcInit(void);
u8 MSTK_voidClearCount(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_u8SetIntervalSingle(u32 Copy_u32Ticks);
void MSTK_u8SetIntervalPeriodic(u32 Copy_u32Ticks);
void MSTK_voidStopInterval(void);
u32 MSTK_u32GetElapsedTime(void);
u32 MSTK_u32GetRemainingTime(void);
u8 MSTK_u8SetCallBackFunc(void (*Copy_ptrFunc)(void));


#endif /* STK_INTERFACE_H_ */
