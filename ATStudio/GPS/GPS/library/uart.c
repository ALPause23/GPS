#include "uart.h"
#include "OLED.h"
#include "LED_MAX7219.h"
#include "ds1307.h"

char rx_buffer[RX_BUFFER_SIZE], buf_speed[3];

char status, data;

int rx_wr_index = 0, rx_rd_index = 0;
unsigned char rx_counter = 0;
uint8_t buffer;
char flagEr = 0, flagRX = 0, flag_Set_Time = 0, flagValid = 1, flagVTG = 0;

char Get_flagRX(void)
{
	return flagRX;
}

ISR(USARTRXC_vect)
{
	//while(!(UCSRA & (1<<RXC)))
	//;
	//rx_buffer[rx_wr_index++] = UDR;
	//if(rx_buffer[0] != '$') /*&& rx_wr_index == 0*/
	//{
		//flagEr &= 0;
		//flagRX &= 0;
		//UCSRB |= (1<<RXCIE);
		//return;
	//}
	//else
	//{
		//while(1)
		//{
			//while(!(UCSRA & (1<<RXC)))
			//;
			//status = UCSRA;
			//data = UDR;
			//if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN)) == 0)
			//{
				//rx_buffer[rx_wr_index++]=data;
			//}
		//}
	//}
	
	if(flagEr == 0)
	{
		flagRX = 1;
		UCSRB &= ~(1<<RXCIE);
	}
}

void USARTReceiveChar(void)
{
	//  Устанавливается, когда регистр свободен
	char status, data;
	//int i = 0;
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
				//#if RX_BUFFER_SIZE == 255
				//// special case for receiver buffer size=256
				//if (++rx_counter == 0)
				//{
					//rx_buffer_overflow = 1;
				//}
				//#else
				//if (rx_wr_index == RX_BUFFER_SIZE)
				//{
					//rx_wr_index = 0;
				//}
				//if (++rx_counter == RX_BUFFER_SIZE)
				//{
					//rx_counter = 0;
					////rx_buffer_overflow = 1;
				//}
				//#endif
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
		if(rx_buffer[4] == 'T' && flagValid == 0x01)
		{
			
			ProcessingVTG();
		}
		if(rx_buffer[4] == 'G')
		{
			ProcessingGGA();
		}
	}
	flagEr = 0;
	flagRX &= 0;
	rx_buffer[0] = 0xA5;
	UCSRB |= (1<<RXCIE);	
}

void ProcessingRCM()
{
	
	if(rx_buffer[17] == 'A')
	{
		DS1307_SetTime(In_BCD(rx_buffer[7], rx_buffer[8], 'h'), In_BCD(rx_buffer[9], rx_buffer[10], 'm'));
		flag_Set_Time = 0x01;
		flagValid = 0x01;
		Buzzer(100);
	}
	else flagValid = 0x00;
}

void ProcessingVTG()
{
	int i = 0, j = 0;
	if(rx_buffer[7] == ',')
	{
		WriteNum(GetNumbers(12), GetNumbers(12), GetNumbers(0));
		return;
	}
	while(1)
	{
		if(rx_buffer[i++] == 'N')
		{
			i++;
			break;
		}
		//else i++;
	}
	while(1)
	{
		if(rx_buffer[i] == '.')
		{
			i--;
			break;
		}
		else
		{
			buf_speed[j++] = rx_buffer[i++];
		}
	}
	//Buzzer(50);
	if(j == 1)
	{
		WriteNum(GetNumbers(12), GetNumbers(12), GetNumbers(Out_ASCII(buf_speed[j - 1])));
	}
	else if(j == 2)
	{
		WriteNum(GetNumbers(12), GetNumbers(Out_ASCII(buf_speed[j - 2])), GetNumbers(Out_ASCII(buf_speed[j - 1])));
	}
	else if(j == 3)
	{
		WriteNum(GetNumbers((int)Out_ASCII(buf_speed[j - 3])), GetNumbers(Out_ASCII(buf_speed[j - 2])), GetNumbers((int)(int)Out_ASCII(buf_speed[j - 1])));
	}
	
}

void ProcessingGGA()
{
	int i = 0;
	if(rx_buffer[17] == ',')
	{
		SelectDisplay(1);
		SetPointer(0x5B);
		Set_OLED_Num(GetNum(0));
		return;
	}
		
	while(1)
	{
		if(rx_buffer[i++] == 'E')
		{
			break;
		}
	}
	if(rx_buffer[i + 1] == '0')
	{
		
		flagValid = 0x00;
		
	}
	else
	{
		i += 0x03;
		flagValid = 0x01;
		SelectDisplay(1);
		SetPointer(0x5B);
		Set_OLED_Num(GetNum(Out_ASCII(rx_buffer[i+1])));
		SetPointer(0x41);
		Set_OLED_Num(GetNum(Out_ASCII(rx_buffer[i])));
	}
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


