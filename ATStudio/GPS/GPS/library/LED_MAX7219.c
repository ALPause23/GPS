/*
 * CFile1.c
 *
 * Created: 23.04.2020 17:36:19
 *  Author: Евген
 */ 
	#include "LED_MAX7219.h"

void InitLed()
{
	
	int i = 0;
	while(i < 3){
		// инициализация дисплея
		PORTB &= ~(1<<PORTB4);
		SPDR = 0x0F;
		//SPDR = (DISPLAY_TEST >> 8);
		while(!(SPSR & (1<<SPIF)));
		//PORTB |= (1<<PORTB4); //высокий уровень
		//_delay_ms(50);

		//PORTB &= ~(1<<PORTB4); //низкий уровень
		SPDR = 0x00;
		//SPDR = (DISPLAY_TEST | 0x00);
		while(!(SPSR & (1<<SPIF)));
		PORTB |= (1<<PORTB4);


		PORTB &= ~(1<<PORTB4);
		//SPDR = 0x0C;
		
		while(!(SPSR & (1<<SPIF)));
		//PORTB |= (1<<PORTB4); //высокий уровень
		//_delay_ms(50);

		//PORTB &= ~(1<<PORTB4); //низкий уровень
		SPDR = 0x01;
		while(!(SPSR & (1<<SPIF)));
		PORTB |= (1<<PORTB4);


		PORTB &= ~(1<<PORTB4);
		SPDR = 0x0A;
		while(!(SPSR & (1<<SPIF)));
		//PORTB |= (1<<PORTB4); //высокий уровень
		//_delay_ms(50);

		//PORTB &= ~(1<<PORTB4); //низкий уровень
		SPDR = 0x0F;
		while(!(SPSR & (1<<SPIF)));
		PORTB |= (1<<PORTB4);


		PORTB &= ~(1<<PORTB4);
		SPDR = 0x0B;
		while(!(SPSR & (1<<SPIF)));
		//PORTB |= (1<<PORTB4); //высокий уровень
		//_delay_ms(50);

		//PORTB &= ~(1<<PORTB4); //низкий уровень
		SPDR = 0x07;
		while(!(SPSR & (1<<SPIF)));
		PORTB |= (1<<PORTB4);


		PORTB &= ~(1<<PORTB4);
		SPDR = 0x09;
		while(!(SPSR & (1<<SPIF)));
		//PORTB |= (1<<PORTB4); //высокий уровень
		//_delay_ms(50);

		//PORTB &= ~(1<<PORTB4); //низкий уровень
		SPDR = 0x00;
		while(!(SPSR & (1<<SPIF)));
		PORTB |= (1<<PORTB4);
		
		
		PORTB &= ~(1<<PORTB4);
		SPDR = 0x0A;
		while(!(SPSR & (1<<SPIF)));
		//PORTB |= (1<<PORTB4); //высокий уровень
		//_delay_ms(50);

		//PORTB &= ~(1<<PORTB4); //низкий уровень
		SPDR = 0x00;
		while(!(SPSR & (1<<SPIF)));
		PORTB |= (1<<PORTB4);
		
		i++;
	}
}

void SPI_WriteStartByte(char data)
{
	PORTB &= ~(1<<PORTB4);
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

void SPI_WriteEndByte(char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= (1<<PORTB4);
}

void SPI_WriteByte(char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

void SendLed(char adr, char data)
{
	SPI_WriteStartByte(adr);
	_delay_ms(10);
	SPI_WriteEndByte(data);
	_delay_ms(10);
}

void ClearDisplay()
{
	int i = 0;
	while(i <= 3)
	{
		for(char j = 1; j <= 8; j++)
		{
			SendLed(j,0);
		}
		i++;
		_delay_ms(1);
	}
}



void WriteNum(char *x, char *y, char *z)
{
	
	for(int i = 0; i < 8; i++)
	{
		PORTB &= ~(1 << PORTB4);
		
		SPI_WriteByte(i + 1);
		SPI_WriteByte(z[i]);
		
		SPI_WriteByte(i + 1);
		SPI_WriteByte(y[i]);
		
		SPI_WriteByte(i + 1);
		SPI_WriteByte(x[i]);
		
		PORTB |= (1<<PORTB4);
	}
	
}