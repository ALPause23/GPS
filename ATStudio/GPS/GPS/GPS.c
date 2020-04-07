/*
 * GPS.c
 *
 * Created: 06.04.2020 15:09:55
 *  Author: Evgeni
 */ 

#include "main.h"

#define MOSI 5								/* Define SPI bus pins */
#define MISO 6
#define SCK 7
#define SPI_SS     4

/*uint16_t i[16] = {
	0b000100000001,
	0b000100000010,
	0b000100000011,
	0b000100000100,
	0b100000000101,
	0b100000000110,
	0b100000000111,
	0b100000001000,
	0b000100000001,
	0b000100000010,
	0b000100000011,
	0b000100000100,
	0b000100000101,
	0b100100000110,
	0b100100000111,
	0b100100001000, 
	};*/
uint16_t i;
uint8_t a,b;

void InitLed()
{
	for(int i = 0; i < 4; i++)
	{
		// инициализация дисплея
		PORTB &= ~(1<<PORTB4);
		SPDR = 0x0F;
		while(!(SPSR & (1<<SPIF)));
		//PORTB |= (1<<PORTB4); //высокий уровень
		//_delay_ms(50);
		
		//PORTB &= ~(1<<PORTB4); //низкий уровень
		SPDR = 0x00;
		while(!(SPSR & (1<<SPIF)));
		PORTB |= (1<<PORTB4);
		
		
		PORTB &= ~(1<<PORTB4);
		SPDR = 0x0C;
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
	}
}

int main(void)
{
	int j = 0;
	DDRB |= ((1<<PORTB0)|(1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //ножки SPI на выход
	
	PORTB &= ~((1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //низкий уровень
	PORTB |= (1<<PORTB0);
	
	SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
	SPSR=(0<<SPI2X);
	
	InitLed();
	
	
	
	i = 0x13c;	
		a = (i >> 8);
		b = i;
		
		
		PORTB &= ~(1<<PORTB4);
		SPDR = a;
		while(!(SPSR & (1<<SPIF)));
		//PORTB |= (1<<PORTB4); //высокий уровень
		//_delay_ms(50);
		
		//PORTB &= ~(1<<PORTB4); //низкий уровень
		SPDR = b;
		while(!(SPSR & (1<<SPIF)));
		PORTB |= (1<<PORTB4);
		
		_delay_ms(1000);
		
		i = 0x242;
		PORTB &= ~(1<<PORTB4);
		SPDR = a;
		while(!(SPSR & (1<<SPIF)));
		//PORTB |= (1<<PORTB4); //высокий уровень
		//_delay_ms(50);
		
		//PORTB &= ~(1<<PORTB4); //низкий уровень
		SPDR = b;
		while(!(SPSR & (1<<SPIF)));
		PORTB |= (1<<PORTB4);
		
	
}