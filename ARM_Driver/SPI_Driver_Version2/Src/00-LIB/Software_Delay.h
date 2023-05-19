/*  
--> this header file contains the delay function implementation
*/


#ifndef _SOFTWARE_DELAY_H_
#define _SOFTWARE_DELAY_H_

/****************************************************************************************/
/* Name        : _delay_ms                                                              */
/* Type        : Synchronous                                                            */
/* Inputs      : Copy_u32Time -> time in millis                                         */
/* Output      : void                                                                   */
/* Description :                                                                        */
/* 		stops CPU form executing usefull instructions for a certain time in millis      */
/****************************************************************************************/
void _delay_ms(u32 Copy_u32Time);

#endif /* _SOFTWARE_DELAY_H_ */
