/*
 * RCC_reg.h
 *
 *  Created on: Dec 27, 2022
 *      Author: LapStore
 */

#ifndef MCAL_RCC_RCC_REGISTER_H_
#define MCAL_RCC_RCC_REGISTER_H_

#define RCC_BASE_ADDRESS			0x40021000

typedef struct
{
	u32 CR;
	u32 CFGR;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
	u32 APB2ENR;
	u32 APB1ENR;
	u32 BDCR;
	u32 CSR;
}RCC_MemMap_t;

#define RCC						((volatile RCC_MemMap_t*)(RCC_BASE_ADDRESS))

/*RCC_CR needed bits*/
#define RCC_CR_HSION		0
#define RCC_CR_HSEON		16
#define RCC_CR_HSEBYP		18
#define RCC_CR_CSSON		19
#define RCC_CR_PLLON		24

/*HSITRIM by default is 10000*/
//	#define RCC_CR_HSITRIM

/*RCC_CFGR needed bits*/
#define RCC_CFGR_SW0			0
#define RCC_CFGR_SW1			1


#endif /* MCAL_RCC_RCC_REG_H_ */
