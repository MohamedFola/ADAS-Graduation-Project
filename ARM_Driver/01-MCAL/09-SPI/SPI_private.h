/***************************************************************/
/*             Author  : Mohamed Hassan Hassan                 */
/*             Layer   : MCAL                                  */
/*             Version : 1                                     */
/*             SWC     : SPI                                   */
/***************************************************************/

#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_


typedef struct
{
	volatile u32 CR1     ;
	volatile u32 CR2     ;
	volatile u32 SR      ;
	volatile u32 DR      ;
	volatile u32 CRCPR   ;
	volatile u32 RXCRCR  ;
	volatile u32 TXCRCR  ;
	volatile u32 I2SCFGR ;
	volatile u32 I2SPR   ;
}SPI_MemMap_t;

#define SPI_COUNT           2

#define SPI1_BASE_ADDRESS   ( ( volatile SPI_MemMap_t * ) ( 0x40013000 ) )
#define SPI2_BASE_ADDRESS   ( ( volatile SPI_MemMap_t * ) ( 0x40003800 ) )


typedef enum
{
	SPI_CR1_CPHA             , /* start of CR1 */
	SPI_CR1_CPOL             ,
	SPI_CR1_MSTR             ,
	SPI_CR1_BR               ,
	SPI_CR1_SPE         = 6  ,
	SPI_CR1_LSBFIRST         ,
	SPI_CR1_SSI              ,
	SPI_CR1_SSM              ,
	SPI_CR1_RXONLY           ,
	SPI_CR1_DFF              ,
	SPI_CR1_CRCNEXT          ,
	SPI_CR1_CRCEN            ,
	SPI_CR1_BIDIOE           ,
	SPI_CR1_BIDIMODE         , /* end of CR1 */
	SPI_CR2_RXDMAEN     = 0  , /* start of CR2 */
	SPI_CR2_TXDMAEN          ,
	SPI_CR2_SSOE             ,
	SPI_CR2_ERRIE       = 5  ,
	SPI_CR2_RXNEIE           ,
	SPI_CR2_TXEIE            , /* end of CR2 */
	SPI_SR_RXNE         = 0  , /* start of SR */
	SPI_SR_TXE               ,
	SPI_SR_CHSIDE            ,
	SPI_SR_UDR               ,
	SPI_SR_CRCPRR            ,
	SPI_SR_MODF              ,
	SPI_SR_OVR               ,
	SPI_SR_BSY               , /* end of SR */
	SPI_I2SCFGR_CHLIEN  = 0  , /* start of I2SCFGR */
	SPI_I2SCFGR_DATLEN       ,
	SPI_I2SCFGR_CKPOL   = 3  ,
	SPI_I2SCFGR_I2SSTD       ,
	SPI_I2SCFGR_PCMSYNC = 7  ,
	SPI_I2SCFGR_I2SCFG       ,
	SPI_I2SCFGR_I2SE    = 10 ,
	SPI_I2SCFGR_I2SMOD       , /* end of I2SCFGR */
	SPI_I2SPR_I2SDIV    = 0  , /* start of I2SPR */
	SPI_I2SPR_ODD       = 8  ,
	SPI_I2SPR_MCKOE          , /* end of I2SPR */
}SPI_Pins_t;


typedef enum
{
	SPI_NoError          ,
	SPI_PointerError     ,
	SPI_ClkPhaseError    ,
	SPI_ClkPolarityError ,
	SPI_ClkRateError     ,
	SPI_DataOrderError   ,
	SPI_ModeError        ,
}SPI_Errors_t;


#define SPI_SW_SLAVE_SELECT  3


#endif /* _SPI_PRIVATE_H_ */
