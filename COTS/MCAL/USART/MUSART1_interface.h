#ifndef _MUSART1_INTERFACE_H_
#define _MUSART1_INTERFACE_H_


void MUSART1_voidInit(void);
void MUSART1_voidSendCharSynch( u8 Copy_u8Char );
void MUSART1_voidSendSrtingSynch( u8 *  Copy_u8String );

u8 MUSART1_u8ReceiveCharSync( void );
u8 * MUSART1_ptrReceiveStringSync( void );
void MUSART1_voidSetCallBack( void (*Copy_CallBack)(void) );


#endif