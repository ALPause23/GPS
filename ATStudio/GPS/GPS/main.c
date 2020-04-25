#include "main.h"

uint16_t i;
uint8_t a,b;


void ssd1306_command(uint8_t data);

int main(void)
{

	init_ports();
	_delay_ms(100);
	
	
	InitLed();
	ClearDisplay();
	//
	//WriteNum(ONE, TWO, THREE);
	//_delay_ms(5000);
	//WriteNum(SIX, FIVE, FOUR);
	//_delay_ms(5000);
	//WriteNum(NINE, EITHT, SEVEN);
	//_delay_ms(5000);
	//WriteNum(EMPTY, ZERO, ZERO);
	//_delay_ms(5000);
	WriteNum(G, P, S);
	
	
	_delay_ms(1000);
	SelectDisplay(2);

	InitOLED();
	ClearOLED();
	SetOLED();
	SetIntensity(0);
	while(1)
	{
		
	}
	return 0;
}
