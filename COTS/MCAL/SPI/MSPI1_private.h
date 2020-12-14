#ifndef _MSPI1_PRIVATE_H
#define _MSPI1_PRIVATE_H

typedef struct{
	
	volatile u32 CR1     ;
	volatile u32 CR2     ;   
	volatile u32 SR      ;
	volatile u32 DR      ;
	volatile u32 CRCPR   ;
	volatile u32 RXCRCR  ;
	volatile u32 TXCRCR  ;
	volatile u32 I2SCFGR ;
	volatile u32 I2SPR   ;
	
}MSPI1_Type ;

#define MSPI1  ((volatile MSPI1_Type *)0x40013000)

#endif
