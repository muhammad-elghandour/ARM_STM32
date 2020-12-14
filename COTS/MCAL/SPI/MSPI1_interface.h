#ifndef _MSPI1_INTERFACE_H
#define _MSPI1_INTERFACE_H

#define MSPI1_ENABLE      1
#define MSPI1_DISABLE     0

#define MSPI1_CLOCK_LOW   0
#define MSPI1_CLOCK_HIGH  1

#define MSPI1_READ_WRITE  0
#define MSPI1_WRITE_READ  1

#define MSPI1_MASTER      0
#define MSPI1_SLAVE       1

#define MSPI1_FPCLK_2     0b000
#define MSPI1_FPCLK_4     0b001
#define MSPI1_FPCLK_8     0b010
#define MSPI1_FPCLK_16    0b011
#define MSPI1_FPCLK_32    0b100
#define MSPI1_FPCLK_64    0b101
#define MSPI1_FPCLK_128   0b110
#define MSPI1_FPCLK_256   0b111  

#define MSPI1_MSB         0
#define MSPI1_LSB         1

#define MSPI1_HW          0
#define MSPI1_SW          1

#define MSPI1_8BIT_DATA   0
#define MSPI1_16BIT_DATA  1

#define MSPI1_INT_DISABLE 0
#define MSPI1_INT_TXENE   1
#define MSPI1_INT_RXENE   2


void MSPII1_voidInit( void );

void MSPI1_voidSendReceiveSynch  ( u8 Copy_u8Data , u8 * Copy_ptrDataToReceive );

void MSPI1_voidSendReceiveAsynch ( u8 Copy_u8Data , void (*Copy_CallBack)(u8 Data) );

#endif
