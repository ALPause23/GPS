#ifndef __UART_H__
	#define __UART_H__

	#include "ports.h"
	
	#define BAUD 9600
	#define MYUBRR 51//F_CPU/16/(BAUD-1)
	
	#define DATA_REGISTER_EMPTY (1<<UDRE)
	#define RX_COMPLETE (1<<RXC)
	#define FRAMING_ERROR (1<<FE)
	#define PARITY_ERROR (1<<UPE)
	#define DATA_OVERRUN (1<<DOR)

	// USART Receiver buffer
	#define RX_BUFFER_SIZE 400
	extern char flagRX;
	
	void ProcessingBufferRx(void);
	char Get_flagRX(void);

	//interrupt [USART_RXC] void usart_rx_isr(void);
	//#pragma vector = USART_RXC
	//__interrupt void usart_rx_isr(void)
	

	
	////////////////////////////////////////////////////////////////////////////////////////////
	
	void USART_Init(unsigned int speed);//Инициализация модуля USART

	
	
	
	
	
#endif