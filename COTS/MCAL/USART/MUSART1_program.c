#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MUSART1_interface.h"
#include "MUSART1_private.h"
#include "MUSART1_config.h"

static void (*MUSART1_CallBack)(void);

void MUSART1_voidInit(void){
	
	u32 LOC_u32Mantissa =  ( F_CPU ) / ( 16 * MUSART1_BAUD_RATE ) ;
	u32 LOC_u32Fraction = ( ( ( F_CPU * 100 ) / ( 16 * MUSART1_BAUD_RATE ) ) % 100 ) * 16 ;
	
	if( LOC_u32Fraction >= 1550 ){ LOC_u32Mantissa += 1 ; LOC_u32Fraction = 0; }
	
	#if    MUSART1_STATUS == MUSART1_ENABLE
	
	
		MUSART -> SR = 0;
		
		#if   MUSART1_WORD_LENGTH == MUSART1_8BIT 
		
		`	CLR_BIT( MUSART1 -> CR1 , 12 );
		
		#elif MUSART1_WORD_LENGTH == MUSART1_9BIT 
		
			SET_BIT( MUSART1 -> CR1 , 12 );
		
		#endif
		
		
		#if   MUSART_PARITY == MUSART1_PARITY_DISABLE
		
			CLR_BIT( MUSART1 -> CR1 , 10 );
		
		#elif MUSART_PARITY == MUSART1_EVEN_PARITY
		
			SET_BIT( MUSART1 -> CR1 , 10 );
			CLR_BIT( MUSART1 -> CR1 , 9  );
		
		#elif MUSART_PARITY == MUSART1_ODD_PARITY
		
			SET_BIT( MUSART1 -> CR1 , 10 );
			SET_BIT( MUSART1 -> CR1 , 9  );
		
		#endif
		
		#if   MUSART1_INTERRUPT == MUSART1_INT_DISABLE
		
			CLR_BIT( MUSART -> CR1 , 5 );
			CLR_BIT( MUSART -> CR1 , 6 );
			CLR_BIT( MUSART -> CR1 , 7 );
		
		#elif MUSART1_INTERRUPT == MUSART1_TXE_INT
		
			SET_BIT( MUSART -> CR1 , 7 );
		
		#elif MUSART1_INTERRUPT == MUSART1_TCE_INT
		
			SET_BIT( MUSART -> CR1 , 6 );
		
		#elif MUSART1_INTERRUPT == MUSART1_RXNE_INT
		
			SET_BIT( MUSART -> CR1 , 5 );
			
		#endif
			
		#if   MUSART1_TRANSMITTER == MUSART1_ENABLE
		
			SET_BIT( MUSART1 -> CR1 , 3 );
		
		#elif MUSART1_TRANSMITTER == MUSART1_DISABLE
		
			CLR_BIT( MUSART1 -> CR1 , 3 );
		
		#endif
		
		#if   MUSART1_RECEIVE == MUSART1_ENABLE
		
			SET_BIT( MUSART1 -> CR1 , 2 );
		
		#elif MUSART1_RECEIVER == MUSART1_DISABLE
		
			CLR_BIT( MUSART1 -> CR1 , 2 );
			
		#endif	
		
		#if    MUSART1_STOP_BITS == MUSART1_1_STOP_BIT
		
			CLR_BIT( MUSART1 -> CR2 , 12 ); CLR_BIT( MUSART1 -> CR2 , 13 );
		
		#elif  MUSART1_STOP_BITS == MUSART1_5_STOP_BIT
		
			SET_BIT( MUSART1 -> CR2 , 12 ); CLR_BIT( MUSART1 -> CR2 , 13 );
		
		#elif  MUSART1_STOP_BITS == MUSART1_1_5_STOP_BIT
		
			SET_BIT( MUSART1 -> CR2 , 12 ); SET_BIT( MUSART1 -> CR2 , 13 );
		
		#elif  MUSART1_STOP_BITS == MUSART1_2_STOP_BIT
		
			CLR_BIT( MUSART1 -> CR2 , 12 ); SET_BIT( MUSART1 -> CR2 , 13 );
		

		#endif 
	
		MUSART1 -> BRR = ( LOC_u32Mantissa << 4 ) | ( LOC_u32Fraction / 100 );
		SET_BIT( MUSART1 -> CR1 , 13 );
	
	#elif  MUSART1_STATUS == MUSART1_DISABLE
	
	#endif
	
}
void MUSART1_voidSendCharSynch( u8 Copy_u8Char ){
	
	MUSART1 -> DR = Copy_u8Char ;
	
	while( GET_BIT( MUSART1 -> SR , 6 ) == 0 );
	
	CLR_BIT( MUSART1 -> SR , 6 );
	
}



void MUSART1_voidSendSrtingSynch( u8 *  Copy_u8String );




u8 MUSART1_u8ReceiveCharSync( void ){
	
	u8 LOC_u8Result = 0;
	
	while( GET_BIT( MUSART1 -> SR , 5 ) == 0 );
	
	LOC_u8Result = MUSART1 -> DR ;
	
	return LOC_u8Result ;
	
	
}



u8 * MUSART1_ptrReceiveStringSync( void );




void MUSART1_voidSetCallBack( void (*Copy_CallBack)(void) ){
	
	MUSART1_CallBack = Copy_CallBack ;
	
}

void USART1_IRQHanlder (void){
	
	MUSART1 -> SR = 0 ;
	MUSART1_CallBack();
	
}
