#include "uart_spi.h"
//#include "init_perif.h"

char rx_buffer[RX_BUFFER_SIZE];

unsigned char rx_wr_index = 0, rx_rd_index = 0;

unsigned char rx_counter = 0;

bit rx_buffer_overflow;
int i = 0;

// USART Receiver interrupt service routine
interrupt [USART_RXC] void usart_rx_isr(void)
{
    //rx_buffer[i++] = USARTReceiveChar();
    char status,data;
    status = UCSRA;
    data = UDR;
    if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
       {
       rx_buffer[rx_wr_index++] = data;
    #if RX_BUFFER_SIZE == 256
       // special case for receiver buffer size=256
       if (++rx_counter == 0) rx_buffer_overflow=1;
    #else
       if (rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
       if (++rx_counter == RX_BUFFER_SIZE)
          {
          rx_counter = 0;
          rx_buffer_overflow = 1;
          }
    #endif
       }
}
//#pragma vector = USART_RXC
//__interrupt void usart_rx_isr(void)
//{
//  rx_buffer[i++] = USARTReceiveChar();
//}

#ifndef _DEBUG_TERMINAL_IO_
// Get a character from the USART Receiver buffer
#define _ALTERNATE_GETCHAR_
#pragma used+
char getchar(void)
{
    char data;
    while (rx_counter == 0);
    data = rx_buffer[rx_rd_index++];
    #if RX_BUFFER_SIZE != 256
    if (rx_rd_index == RX_BUFFER_SIZE) rx_rd_index = 0;
    #endif
    #asm("cli")
    --rx_counter;
    #asm("sei")
    return data;
}
#pragma used-
#endif

char USARTReceiveChar(void) {
  //  Устанавливается, когда регистр свободен
  while(!(UCSRA & (1<<RXC)));
  return UDR;
}

