#include "LED_MAX7219.h"

void SPI_WriteStartByte(char data);
void SPI_WriteEndByte(char data);
void SPI_WriteByte(char data);
void SPI_WriteByte(char data);
void SendLed(char adr, char data);

void InitLed()
{
	SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
	SPSR=(0<<SPI2X);
	
	// инициализация дисплея
	SendLed((DISPLAY_TEST >> 8), (DISPLAY_TEST | 0x00));
	SendLed((INTENSITY >> 8), (INTENSITY | 0x0f));
	SendLed((SCAN_LIMIT >> 8), (SCAN_LIMIT | 0x07));
	SendLed((NO_DECODE_MODE >> 8), (NO_DECODE_MODE | 0x00));
	SendLed((SHUTDOWN >> 8), (SHUTDOWN | 0x00));
}

void SPI_WriteStartByte(char data)
{
	PORTB &= ~(CS);
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

void SPI_WriteEndByte(char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= (CS);
}

void SPI_WriteByte(char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

void SendLed(char adr, char data)
{
	int i = 0;
	while(i < 3)
	{
		SPI_WriteStartByte(adr);
		SPI_WriteEndByte(data);
		i++;
	}
}

void ClearDisplay()
{
	for(char j = 1; j <= 8; j++)
	{
		SendLed(j,0);
	}
	SendLed((SHUTDOWN >> 8), (SHUTDOWN | 0x01));
}

void WriteNum(char *z, char *y, char *x)
{
	for(int i = 0; i < 8; i++)
	{
		PORTB &= ~(CS);
		
		SPI_WriteByte(i + 1);
		SPI_WriteByte(pgm_read_byte(&(z[i])));
		
		SPI_WriteByte(i + 1);
		SPI_WriteByte(pgm_read_byte(&(y[i])));
		
		SPI_WriteByte(i + 1);
		SPI_WriteByte(pgm_read_byte(&(x[i])));
		
		PORTB |= CS;
	}
}

void SetIntensity(uint8_t a)  // 0 down to 15
{
	SendLed((INTENSITY >> 8), (SHUTDOWN | a));
}