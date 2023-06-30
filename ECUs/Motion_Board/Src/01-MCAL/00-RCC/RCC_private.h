/*
 * RCC_prv.h
 *
 *  Created on: Dec 27, 2022
 *      Author: LapStore
 */

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_


/*Configurations*/
#define ENABLE					0
#define DISABLE					1

/*Clock Type*/
#define CRYSTAL					0
#define RC_CLOCK				1

/*System Clock Types*/
#define SYS_CLK_HSI				0
#define SYS_CLK_HSE_CRYSTAL		1
#define SYS_CLK_HSE_RC_CLK		2
#define SYS_CLK_PLL				3

/*PLL Options*/
#define RCC_PLL_IN_HSI_DIV_2	0
#define RCC_PLL_IN_HSE_DIV_2	1
#define RCC_PLL_IN_HSE			2

/*PLL Multiplier*/
#define MULL_2					0x00000000
#define MULL_3					0x00040000
#define MULL_4					0x00080000
#define MULL_5					0x000C0000
#define MULL_6					0x00100000
#define MULL_7					0x00140000
#define MULL_8                  0x00180000
#define MULL_9                  0x001C0000
#define MULL_10                 0x00200000
#define MULL_11                 0x00240000
#define MULL_12                 0x00280000
#define MULL_13                 0x002C0000
#define MULL_14                 0x00300000
#define MULL_15                 0x00340000
#define MULL_16                 0x00380000

#endif /* MCAL_RCC_RCC_PRV_H_ */
