#include "main.h"


uint16_t i;
uint8_t a,b;
;

void ssd1306_command(uint8_t data);








int main(void)
{
	DDRB |= ((1<<PORTB0)|(1<<PORTB1)|(1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //ножки SPI на выход

	PORTB &= ~((1<<PORTB0)|(1<<PORTB1)|(1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //низкий уровень
	
	_delay_ms(100);
	SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
	SPSR=(0<<SPI2X);
	
	InitLed();
	//InitI2C();
	ClearDisplay();
	
	WriteNum(THREE, TWO,ONE );
	_delay_ms(1000);
	WriteNum(SIX, FIVE, FOUR);
	_delay_ms(1000);
	WriteNum(NINE, EITHT, SEVEN);
	_delay_ms(1000);
	WriteNum(Z, Y, X);
	
	PORTB |= (1<<PORTB0);
	PORTB &= ~(1<<PORTB1);
	
	_delay_ms(10);
	InitOLED();
	PORTB |= (1<<PORTB1);
	PORTB &= ~(1<<PORTB0);
	InitOLED();
	PORTB |= (1<<PORTB0);
	PORTB &= ~(1<<PORTB1);
	ClearOLED();
	PORTB |= (1<<PORTB1);
	PORTB &= ~(1<<PORTB0);
	ClearOLED();
	PORTB |= (1<<PORTB0);
	PORTB &= ~(1<<PORTB1);
	SetOLED();
	PORTB |= (1<<PORTB1);
	PORTB &= ~(1<<PORTB0);
	SetOLED();
	PORTB |= (1<<PORTB3);
	_delay_ms(100);
	PORTB &= ~(1<<PORTB3);

	while(1)
	{
		
	}
	return 0;
}
