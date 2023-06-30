/*
 * DIO_private.h
 *
 *  Created on: Jan 28, 2023
 *      Author: speedTECH
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define MDIOA_BASE_ADRESS 0x40010800
#define MDIOB_BASE_ADRESS 0x40010C00
#define MDIOC_BASE_ADRESS 0x40011000

typedef struct {
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;

} MDIO_MemMap_t ;

#define MDIOA ((volatile MDIO_MemMap_t *) (MDIOA_BASE_ADRESS))
#define MDIOB ((volatile MDIO_MemMap_t *) (MDIOB_BASE_ADRESS))
#define MDIOC ((volatile MDIO_MemMap_t *) (MDIOC_BASE_ADRESS))


#endif /* DIO_PRIVATE_H_ */
