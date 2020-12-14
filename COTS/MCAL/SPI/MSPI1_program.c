

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSPI1_interface.h"
#include "MSPI1_private.h"
#include "MSPI1_config.h"

static void (*MSPI_CallBack)(u8 Data);

void MSPII1_voidInit( void ){
	
	#if    MSPI1_STATUS == MSPI1_ENABLE
	
		#if     MSPI1_CPOL == MSPI1_CLOCK_LOW
		
			CLR_BIT( MSPI1 -> CR1 , 1 );
		
		#elif   MSPI1_CPOL == MSPI1_CLOCK_HIGH
			
			SET_BIT( MSPI1 -> CR1 , 1 );
			
		#endif
		
		#if     MSPI1_CPHA == MSPI1_READ_WRITE
		
			CLR_BIT( MSPI1 -> CR1 , 0 );
		
		#elif   MSPI1_CPHA == MSPI1_WRITE_READ
			
			SET_BIT( MSPI1 -> CR1 , 0 );
			
		#endif
		
		#if     MSPI1_MODE == MSPI1_MASTER
		
			SET_BIT( MSPI1 -> CR1 , 2 );
		
		#elif   MSPI1_MODE == MSPI1_SLAVE
		
			CLR_BIT( MSPI1 -> CR1 , 2 );
		
		#endif
		
		#if     MSPI1_DATA_ORDER == MSPI1_MSB
		
			CLR_BIT( MSPI1 -> CR1 , 7 );
		
		#elif   MSPI1_DATA_ORDER == MSPI1_LSB
		
			SET_BIT( MSPI1 -> CR1 , 7 );
		
		#endif
		
		
		#if    MSPI1_NSS_MANAGE == MSPI1_SW
		
			#if     MSPI1_MODE == MSPI1_MASTER
			
				SET_BIT( MSPI1 -> CR1 , 8 );/* SET For SSI */
			
			#endif
			
			SET_BIT( MSPI1 -> CR1 , 9 );
		
		#elif  MSPI1_NSS_MANAGE == MSPI1_HW
		
			CLR_BIT( MSPI1 -> CR1 , 9 );
		
		#endif
		
		#if     MSPI1_DATA_SIZE == MSPI1_8BIT_DATA
		
			CLR_BIT( MSPI1 -> CR1 , 11 );
		
		#elif   MSPI1_DATA_SIZE == MSPI1_16BIT_DATA
		
			SET_BIT( MSPI1 -> CR1 , 11 );
		
		#endif
		
		MSPI1 -> CR1 &= 0xFFC7 ;   
		
		MSPI1 -> CR1 |= ( MSPI1_PRESCALLER << 3 ) ;
		
		SET_BIT( MSPI1 -> CR1 , 6 );
		
	
	#elif  MSPI1_STATUS == MSPI1_DISABLE
	
		CLR_BIT( MSPI1 -> CR1 , 6 );
	
	#endif
	
	
}

void MSPI1_voidSendReceiveSynch  ( u8 Copy_u8Data , u8 * Copy_ptrDataToReceive ){
	
	/* Disable All Interrupts */
	MSPI1 -> CR2 = 0 ;
	
	MGPIO_voidSetPinValue( MSPI1_SLAVE_SELECT_PIN , MGPIO_LOW  );
	
	MSPI1 -> DR = Copy_u8Data ;
	
	while( GET_BIT( MSPI1 -> SR , 7 ) == 1 );
	
	*Copy_ptrDataToReceive = MSPI1 -> DR ;
	
	MGPIO_voidSetPinValue( MSPI1_SLAVE_SELECT_PIN , MGPIO_HIGH );
	
	
}

void MSPI1_voidSendReceiveAsynch ( u8 Copy_u8Data , void (*Copy_CallBack)(u8 Data) ){
	
	MSPI1 -> DR = Copy_u8Data ;
	
	MSPI_CallBack = Copy_CallBack ;
	
	#if     MSPI1_INT_SATATUS == MSPI1_INT_TXENE
	
		SET_BIT( MSPI1 -> CR2 , 7 );
	
	#elif   MSPI1_INT_SATATUS == MSPI1_INT_RXENE
	
		SET_BIT( MSPI1 -> CR2 , 6 );
	
	#endif
	
}


void MSPI1_IRQHandler(void){
	
	MSPI_CallBack( MSPI1 -> DR );
	
}