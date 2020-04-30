#ifndef __UART_H__
	#define __UART_H__

	#define DATA_REGISTER_EMPTY (1<<UDRE)
	#define RX_COMPLETE (1<<RXC)
	#define FRAMING_ERROR (1<<FE)
	#define PARITY_ERROR (1<<UPE)
	#define DATA_OVERRUN (1<<DOR)

	// USART Receiver buffer
	#define RX_BUFFER_SIZE 80


	//interrupt [USART_RXC] void usart_rx_isr(void);
	//#pragma vector = USART_RXC
	//__interrupt void usart_rx_isr(void)
#endif