

#ifndef COMMHANDLER_INTERFACE_H_
#define COMMHANDLER_INTERFACE_H_



#define DISTANCE 		1
#define SPEED	 		2
#define STEERING 		3
#define INVALID_TYPE	4


#define TRANSMIT		1
#define RECIEVE			2



#define ECU_STATE		TRANSMIT


typedef struct
{
	u8 DataType;
	u32 Data;
}Rx_t;

typedef struct
{
	u32 Data;
	u16 DataID;
	u8 	DataNoBytes;
	u8  DataType;


}Tx_t;

void CommHandlerInit( u8 Copy_u8Mode );

void CommHandlerSend(Tx_t* Tx);

Rx_t CommHandlerRxIndication(void);

#endif /* COMMHANDLER_INTERFACE_H_ */
