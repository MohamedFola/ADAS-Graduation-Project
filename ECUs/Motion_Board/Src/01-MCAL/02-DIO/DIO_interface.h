/*************************** Layer:MCAL  ************************************/
/**************************  Driver:DIO   ***********************************/
/*************************  Version: 1.0  ***********************************/
/****************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*Ports names */
#define MDIO_PORTA 1
#define MDIO_PORTB 2
#define MDIO_PORTC 3
/*Pin numbers define*/
#define MDIO_PIN0  0
#define MDIO_PIN1  1
#define MDIO_PIN2  2
#define MDIO_PIN3  3
#define MDIO_PIN4  4
#define MDIO_PIN5  5
#define MDIO_PIN6  6
#define MDIO_PIN7  7
#define MDIO_PIN8  8
#define MDIO_PIN9  9
#define MDIO_PIN10 10
#define MDIO_PIN11 11
#define MDIO_PIN12 12
#define MDIO_PIN13 13
#define MDIO_PIN14 14
#define MDIO_PIN15 15
/*********************************/
/*Pin Values*/
#define MDIO_PIN_HIGH 			1
#define MDIO_PIN_LOW     		0
/*Port Values*/
#define MDIO_PORT_HIGH			0xffff
#define MDIO_PORT_LOW			0
/*DIO APIs*/
u8 MDIO_u8WriteChannel(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 MDIO_u8ReadChannel(u8 Copy_u8Port, u8 Copy_u8Pin, u8 * Copy_pu8ReadValue);
u8 MDIO_u8WritePort(u8 Copy_u8Port, u16 Copy_u16Value);
u8 MDIO_u8ReadPort(u8 Copy_u8Port, u16 * Copy_pu16ReadValue);
u8 MDIO_voidWriteChannelGroup(u8 Copy_u8Port, u8 Copy_u8BitOffset,u8 Copy_u8BitWidth, u16 Copy_u16Value);
u8 MDIO_voidReadChannelGroup(u8 Copy_u8Port, u8 Copy_u8BitOffset,u8 Copy_u8BitWidth, u16 * Copy_pu16Value);

#endif /* DIO_INTERFACE_H_ */
