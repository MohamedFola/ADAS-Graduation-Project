/*
 * STK_private.h
 *
 *  Created on: Feb 1, 2023
 *      Author: speedTECH
 */


#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

#define STK_BASE_ADRESS 0xE000E010

typedef struct
{
	volatile u32 MSTK_CTRL;
	volatile u32 MSTK_LOAD;
	volatile u32 MSTK_VAL;
	volatile u32 MSTK_CALIB;

}MSTK_t;

#define MSTK   ((volatile MSTK_t*)STK_BASE_ADRESS)
#define MSTK_ENABLE			0
#define MSTK_TICKINT_EN		1
#define MSTK_CLK_SRC		2
#define MSTK_CNT_FLAG		16

#define AHB					1
#define AHB_DIVIDE_BY_8     2

#define MSTK_SINGLE_INTERVAL   1
#define MSTK_PERIODIC_INTERVAL 2
#endif /* STK_PRIVATE_H_ */
