#include "uart.h"
#include "init_perif.h"

char rx_buffer[RX_BUFFER_SIZE];


unsigned char rx_wr_index = 0, rx_rd_index = 0;
unsigned char rx_counter = 0;
uint8_t rx_buffer_overflow;
char flagEr, flagRX = 0;

char Get_flagRX(void)
{
	return flagRX;
}

void USARTReceiveChar(void) {
	//  Устанавливается, когда регистр свободен
	char status,data;
	int i = 0;
	while(1)
	{
		while(!(UCSRA & (1<<RXC)));
		status = UCSRA;
		data = UDR;
		//if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
		//{
			rx_buffer[rx_wr_index++] = data;
		//}
		
		if(i == 5)
		{
			//flagEr = 255;	
			break;
		}
		i++;		
		//return UDR;
	}
	flagRX &= 0;
	UCSRB |= (1<<RXCIE);
	_delay_ms(100);
	
}

ISR(USARTRXC_vect)
{
	if(flagEr == 0)
	{
		flagRX = 1;
		UCSRB &= ~(1<<RXCIE);
	}
	//char b = USARTReceiveChar();
	//rx_buffer[i] = b;
	//i++;
	
	//char status,data;
	//status = UCSRA;
	//data = UDR;
	//if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
	//{
		//rx_buffer[rx_wr_index++] = data;
		//#if RX_BUFFER_SIZE == 256
		//// special case for receiver buffer size=256
		//if (++rx_counter == 0) rx_buffer_overflow=1;
		//#else
		//if (rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
		//if (++rx_counter == RX_BUFFER_SIZE)
		//{
			//rx_counter = 0;
			//rx_buffer_overflow = 1;
		//}
		//#endif
	//}
	
}

void USART_Init(unsigned int speed)//Инициализация модуля USART
{
	UBRRH = (unsigned char)(speed>>8);
	UBRRL = (unsigned char)speed;
	
	UCSRB = (1<<RXEN) | (1<<RXCIE); //Включаем прием и передачу по USART
	//UCSRB |= (1<<RXCIE); //Разрешаем прерывание при передаче
	UCSRA = 0;
	//UCSRA |= (1<<U2X); // Для 8 мгц
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);// Обращаемся именно к регистру UCSRC (URSEL=1),
	sei();
}

//unsigned char rx_counter = 0;
//
//bit rx_buffer_overflow;
//
//// USART Receiver interrupt service routine
//interrupt [USART_RXC] void usart_rx_isr(void)
//{
////rx_buffer[i++] = USARTReceiveChar(); 
//unsigned char rx_wr_index = 0, rx_rd_index = 0;
//char status,data;
//status = UCSRA;
//data = UDR;
//if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
	//{
	//rx_buffer[rx_wr_index++] = data;
//#if RX_BUFFER_SIZE == 256
	//// special case for receiver buffer size=256
	//if (++rx_counter == 0) rx_buffer_overflow=1;
//#else
	//if (rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
	//if (++rx_counter == RX_BUFFER_SIZE)
		//{
		//rx_counter = 0;
		//rx_buffer_overflow = 1;
		//}
//#endif
	//}
//}
//#pragma vector = USART_RXC
//__interrupt void usart_rx_isr(void)
//{
//  rx_buffer[i++] = USARTReceiveChar();
//}


