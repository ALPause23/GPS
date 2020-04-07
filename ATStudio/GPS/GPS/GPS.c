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

uint16_t i = 0x8ff;
uint8_t a,b;

int main(void)

{
	DDRB |= ((1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //ножки SPI на выход
	PORTB &= ~((1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //низкий уровень
	
	SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
	SPSR=(0<<SPI2X);
	_delay_ms(2000);	
	{
		a = (i >> 8);
		b = i;
		
		
		SPDR = a;
		while(!(SPSR & (1<<SPIF)));//подождем пока данные передадутся
		//сгенерируем отрицательный фронт для записи в STORAGE REGISTER
		PORTB |= (1<<PORTB4); //высокий уровень
		PORTB &= ~(1<<PORTB4); //низкий уровень
		
		//PORTB &= ~(1<<PORTB4);
		_delay_ms(50);
		
		SPDR = b;
		while(!(SPSR & (1<<SPIF)));//подождем пока данные передадутся
		//сгенерируем отрицательный фронт для записи в STORAGE REGISTER
		PORTB |= (1<<PORTB4); //высокий уровень
		PORTB &= ~(1<<PORTB4); //низкий уровень
		
		//PORTB &= ~(1<<PORTB4);
		_delay_ms(50g);	
	}
}