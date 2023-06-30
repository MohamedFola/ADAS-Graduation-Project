/*
 * RCC_cfg.h
 *
 *  Created on: Dec 27, 2022
 *      Author: LapStore
 */

#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_

/*Mode of the Clock Security Source*/
#define RCC_CSS_ENABLE			DISABLE

/*Choosing the HSE clock bypass (CRYSTAL / RC_CLOCK)*/
#define	RCC_HSE_BYPASS			CRYSTAL

/*Selecting the system clock switch*/
/*You can choose: (SYS_CLK_HSE_CRYSTAL / SYS_CLK_HSE_RC_CLK / SYS_CLK_HSI / SYS_CLK_PLL)*/
#define SYSTEM_CLK				SYS_CLK_HSE_CRYSTAL

/*Choosing PLL Source*/
/*You can choose: (RCC_PLL_IN_HSI_DIV_2 / RCC_PLL_IN_HSE_DIV_2 / RCC_PLL_IN_HSE)*/
/*Select if only you have selected PLL as a clock source*/
#if SYSTEM_CLK == SYS_CLK_PLL
/*Choosing the source of PLL*/
#define PLL_INPUT				RCC_PLL_IN_HSE
/*Choosing the Multiplier value of PLL*/
/*You can choose from 2 to 16 by writting (MULL_x)*/
#define PLL_MUL_VALUE			MULL_4
#endif

#endif /* MCAL_RCC_RCC_CFG_H_ */
