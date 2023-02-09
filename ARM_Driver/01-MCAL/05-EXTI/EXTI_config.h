#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H


/*Choose the line of external interrupt to work on it*/
/*Options:
 *			LINEx		(0 --> 15)
 * */

#define EXTI_LINE 			LINE0

/*Choose the mode of the external interrupts*/
/*Options:
 *	RISING_EDGE
 *	FALLING_EDGE
 *	ON_CHANGE
 * */

#define EXTI_MODE			RISING_EDGE


#endif
