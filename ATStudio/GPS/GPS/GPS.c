/*
 * GPS.c
 *
 * Created: 06.04.2020 15:09:55
 *  Author: Evgeni
 */ 

#include "main.h"


uint16_t i;
uint8_t a,b;

void InitLed()
{
	while(i < 4){
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
    while(i <= 4)
    {
		for(char j = 1; j <= 8; j++)
		{
			SendLed(j,0);
		}
	    i++;
	    _delay_ms(1);
    }
}
	
void InitI2C()
{
	TWBR = TWBR_VALUE;
	TWSR = 0;
}	

void SendOLED(uint8_t adr, uint8_t data)
{
	// START bit
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	
	/*выдаем на шину пакет SLA-W, ACK == 0*/
	TWDR = (0b01111010)|0;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	
	TWDR = adr;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
		TWDR = data;
		TWCR = (1<<TWINT)|(1<<TWEN);
		while(!(TWCR & (1<<TWINT)));
	
	/*Stop bit*/
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

int main(void)
{
	DDRB |= ((1<<PORTB3)|(1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //ножки SPI на выход
	
	PORTB &= ~((1<<PORTB3)|(1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //низкий уровень
	
	
	SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
	SPSR=(0<<SPI2X);
	
	//InitLed();
	//InitI2C();
	//ClearDisplay();
	//PORTB |= (1<<PORTB3);
	//SendLed(4, 1);
	//SendLed(4, 2);
	//SendLed(4, 3);
	//PORTB &= ~(1<<PORTB3);
	//SendLed(1, 1);
	//SendLed(2, 1);
	
	InitI2C();
	//SendOLED(0xA8, 0x3F);
	SendOLED(0x00, 0xAF);
	//SendOLED(0x00, 0x3F);
	//SendOLED(0xA8, 0x3F);
	//SendOLED(0xA8, 0x3F);
	//SendOLED(0xA8, 0x3F);
	//SendOLED(0xA8, 0x3F);
	//SendOLED(0xA8, 0x3F);
	//SendOLED(0xA8, 0x3F);
	//SendOLED(0xA8, 0x3F);
	//SendOLED(0xA8, 0x3F);
	//SendOLED(0xA8, 0x3F);

	while(1)
	{
		
	}
	return 0;	
}