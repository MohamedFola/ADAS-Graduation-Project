/*
 *
 * MCP2515_Private.h
 * Created on:
 * Version: 02
 * Author: Eng. Ahmed Abdelshafy
 * 
 */
#ifndef MCP2515_PRIVATE_H_
#define MCP2515_PRIVATE_H_

#define INST_RESET			(0xC0)
#define INST_READ			(0x03)
#define INST_WRITE			(0x02)
#define INST_RTS_TXB0		(0x81)
#define INST_RTS_TXB1		(0x82)
#define INST_RTS_TXB2		(0x84)
#define INST_READ_STATUS	(0xA0)
#define INST_RX_STATUS		(0xB0)
#define INST_BIT_MODIFY		(0x05)


#define CNF1				(0x2A)
#define CNF2				(0x29)
#define CNF3				(0x28)

#define CANCTRL				(0x0F)
#define CANSTAT				(0x0E)

#define TXB0CTRL			(0x30)
#define TXB1CTRL			(0x40)
#define TXB2CTRL			(0x50)


#define RXB0CTRL			(0x60)
#define RXB1CTRL			(0x70)

#define BUKT				2

#define RXM0SIDH			(0x20)
#define RXM1SIDH			(0x24)

#define RXF0SIDH			(0x00)
#define RXF1SIDH			(0x04)

#define CANINTE				(0x2B)
#define CANINTF				(0x2C)

#define RX0IE				0
#define RX1IE				1
#define RX0IF				0
#define RX1IF				1


#endif /* MCP2515_PRIVATE_H_ */
