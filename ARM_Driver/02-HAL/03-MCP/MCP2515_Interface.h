/*
 *
 * MCP2515_Interface.h
 * Created on:
 * Version: 02
 * Author: Eng. Ahmed Abdelshafy
 * 
 */
#ifndef MCP2515_INTERFACE_H_
#define MCP2515_INTERFACE_H_


u8 MCP2515_U8ReadRegister(u8 address);
void MCP2515_VidWriteRegister(u8 address, u8 value);
void MCP2515_VidSetBitTiming(u8 cnf1Value, u8 cnf2Value, u8 cnf3Value);
void MCP2515_VidReset();
void MCP2515_VidChangeBits(u8 RegAddress, u8 Mask, u8 Value);
void MCP2515_VidSetMode(u8 mode);
void MCP2515_VidInit(void);
void MCP2515_VidSendCANmsg(u8 bufIdx, u32 msgID, u8 * data,u8 properties);
void MCP2515_VidSetRollover(u8 value);
void MCP2515_VidSetMask(u8 maskAddress, u32 maskValue, u8 extended);
void MCP2515_VidReceiveInit(void);
void MCP2515_VidReceiveCANmsg(void);



#define MCP2515_MODE_NORMAL			(u8)0x0
#define MCP2515_MODE_SLEEP			(u8)0x1
#define MCP2515_MODE_LOOPBACK		(u8)0x2
#define MCP2515_MODE_LISTEN_ONLY	(u8)0x3
#define MCP2515_MODE_CONFG		    (u8)0x4


#endif /* MCP2515_INTERFACE_H_ */
