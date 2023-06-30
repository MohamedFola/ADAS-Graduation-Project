#ifndef AFIO_REGISTER_H
#define AFIO_REGISTER_H

#define AFIO_BASE_ADDRESS			0x40010000

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_MemMap_t;


#define AFIO				((volatile AFIO_MemMap_t*)(AFIO_BASE_ADDRESS))


#endif
