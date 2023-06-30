/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : Port Driver                           */
/***************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"


#include "../01-PORT/PORT_config.h"
#include "../01-PORT/PORT_private.h"
#include "../01-PORT/PORT_interface.h"


/****************************************************************************
 * Name        : PORT_voidInit                                              *
 *                                                                          *
 * Return type : void                                                       *
 *                                                                          *
 * Arguments   : void                                                       *
 * 	                                                                        *
 * Type        : Synchronous & Non Reentrant                                *
 *                                                                          *
 * description : Initiate all Pins of the Microcontroller                   *
 ****************************************************************************/
void PORT_voidInit( void )
{
	/* --> set the mode for all ports */

	/* port A */
	GPIOA->CRL = PORTA_LOW_MODE;
	GPIOA->CRH = PORTA_HIGH_MODE;

	/* port B */
	GPIOB->CRL = PORTB_LOW_MODE;
	GPIOB->CRH = PORTB_HIGH_MODE;

	/* port C */
	GPIOC->CRH = PORTC_HIGH_MODE;

	/* --> set initial value for all ports */

	/* port A */
	GPIOA->ODR = PORTA_INITIAL_VALUE;

	/* port B */
	GPIOB->ODR = PORTB_INITIAL_VALUE;

	/* port C */
	GPIOC->ODR = PORTC_INITIAL_VALUE;
}
