#ifndef _MUSART1_PRIVATE_H_
#define _MUSART1_PRIVATE_H_

typedef struct {
	
	volatile u32 SR   ;
	volatile u32 DR   ;
	volatile u32 BRR  ;
	volatile u32 CR1  ;
	volatile u32 CR2  ;
	volatile u32 CR3  ;
	volatile u32 GTPR ;
	
}USART1_Type;


#define MUSART1( ( volatile USART1_Type *)0x40013800 )


#define  MUSART1_DISABLE         0
#define  MUSART1_ENABLE          1

#define MUSART1_8BIT             0
#define MUSART1_9BIT             1


#define MUSART1_PARITY_DISABLE  0
#define MUSART1_EVEN_PARITY     1
#define MUSART1_ODD_RITY        2

#define MUSART1_INT_DISABLE     0
#define MUSART1_TXE_INT         1
#define MUSART1_TCE_INT         2
#define MUSART1_RXNE_INT        3

#define  MUSART1_1_STOP_BIT     0
#define  MUSART1_5_STOP_BIT     1
#define  MUSART1_1_5_BIT        2
#define  MUSART1_2_STOP_BIT     3

#endif