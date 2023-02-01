/*
 * RCC_int.h
 *
 *  Created on: Dec 27, 2022
 *      Author: LapStore
 */

#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_

//Macros to choose which bus the peripheral connected on it
#define	RCC_AHB		0
#define RCC_APB1	1
#define RCC_APB2	2

//Peripherals you choose when you enable it for APB2 bus
#define RCC_GPIOA 	2
#define RCC_GPIOB 	3
#define RCC_GPIOC 	4



void RCC_voidInitSysClock(void);

u8 RCC_voidEnableClock(u8 Copy_u8PeripheralID,u8 Copy_u8BusId);

u8 RCC_voidDisableClock(u8 Copy_u8PeripheralID,u8 Copy_u8BusId);

#endif /* MCAL_RCC_RCC_INT_H_ */
