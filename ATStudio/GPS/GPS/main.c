#include "main.h"

uint16_t i;
uint8_t a,b;


void ssd1306_command(uint8_t data);

int main(void)
{

	init_ports();
	_delay_ms(100);

	
	InitLed();
	//InitI2C();
	ClearDisplay();
	//
	WriteNum(ONE, TWO, THREE);
	_delay_ms(5000);
	WriteNum(SIX, FIVE, FOUR);
	_delay_ms(5000);
	WriteNum(NINE, EITHT, SEVEN);
	_delay_ms(5000);
	WriteNum(EMPTY, ZERO, ZERO);
	_delay_ms(5000);
	WriteNum(G, P, S);
	
	
	PORTB |= (1<<PORTB0);
	PORTB &= ~(1<<PORTB1);
	
	_delay_ms(100);
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
	SetIntensity(0);
	while(1)
	{
		
	}
	return 0;
}
