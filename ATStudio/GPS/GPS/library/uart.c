#include "uart.h"
#include "OLED.h"
#include "LED_MAX7219.h"
#include "ds1307.h"

char rx_buffer[RX_BUFFER_SIZE];


int rx_wr_index = 0, rx_rd_index = 0;
unsigned char rx_counter = 0;
uint8_t buffer;
char flagEr = 0, flagRX = 0, flag_Set_Time = 0, flagValid = 1;

char Get_flagRX(void)
{
	return flagRX;
}

void USARTReceiveChar(void)
{
	//  Устанавливается, когда регистр свободен
	char status, data;
	int i = 0;
	rx_wr_index = 0;
	while(!(UCSRA & (1<<RXC)))
		;
	rx_buffer[rx_wr_index++] = UDR;
	if(rx_buffer[0] != '$') /*&& rx_wr_index == 0*/
	{
		flagEr &= 0;
		flagRX &= 0;
		UCSRB |= (1<<RXCIE);
		return;
	}
	else
	{
		while(1)
		{
			while(!(UCSRA & (1<<RXC)))
				;
			status = UCSRA;
			data = UDR;
			if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN)) == 0)
			{
				rx_buffer[rx_wr_index++]=data;
				#if RX_BUFFER_SIZE == 255
				// special case for receiver buffer size=256
				if (++rx_counter == 0)
				{
					rx_buffer_overflow = 1;
				}
				#else
				if (rx_wr_index == RX_BUFFER_SIZE)
				{
					rx_wr_index = 0;
				}
				if (++rx_counter == RX_BUFFER_SIZE)
				{
					rx_counter = 0;
					//rx_buffer_overflow = 1;
				}
				#endif
			}
			if (data == '*')
			{
				break;
			}
		}
		if(rx_buffer[4] == 'M' && flag_Set_Time == 0)
		{
			ProcessingRCM();
		}
		if(rx_buffer[4] == 'T' && flagValid)
		{
			ProcessingVTG();
		}
		
	}	//(rx_buffer[4] == 'S') || 
			/*rx_buffer[2] == 'G' /*|| rx_buffer[2] == 'L' ||*/ 
	
				//status = UCSRA;
			//data = UDR;
			//if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
			//{
				//rx_buffer[rx_wr_index++] = data;
			//}
		
			//if(data == 0x43)
			//{
				//flagEr = 255;	
				//break;
			//}
				
			//return UDR;
		
	


	
	flagEr = 0;
	flagRX &= 0;
	UCSRB |= (1<<RXCIE);	
}

void ProcessingRCM()
{
	if(rx_buffer[17] == 'A')
	{
		if((Out_ASCII(rx_buffer[7])*10 + Out_ASCII(rx_buffer[8]) + 3) < 24)
		{
			DS1307_SetTime(rx_buffer[7], rx_buffer[8]),
			In_BCD(rx_buffer[9], rx_buffer[10]));
		}
		DS1307_SetTime(rx_buffer[7], rx_buffer[8]),
		In_BCD(rx_buffer[9], rx_buffer[10])
		((Out_ASCII(rx_buffer[7])*10 + Out_ASCII(rx_buffer[8]) + 3) >= 24) ? (In_BCD(rx_buffer[7], rx_buffer[8]))
		
		In_BCD(rx_buffer[7], rx_buffer[8]), 
				In_BCD(rx_buffer[9], rx_buffer[10]));
		flag_Set_Time = 1;
		Buzzer(100);
	}
	else flagValid = 0x00;
}

void ProcessingVTG()
{
	if(rx_buffer[7] == ',')
	{
		WriteNum(EMPTY, ZERO, ZERO);
	}
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


