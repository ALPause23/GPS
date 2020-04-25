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
	
	//WriteNum(ONE, TWO, THREE);
	//_delay_ms(1000);
	//WriteNum(SIX, FIVE, FOUR);
	//_delay_ms(1000);
	//WriteNum(NINE, EITHT, SEVEN);
	//_delay_ms(1000);
	//WriteNum(EMPTY, ZERO, ZERO);
	//_delay_ms(1000);
	WriteNum(G, P, S);
	
	
	//_delay_ms(1000);
	SetIntensity(0);
	SelectDisplay(2);
	InitOLED();
	ClearOLED();
	
	SelectDisplay(0);
	_delay_ms(1000);
	SetOLED((uint8_t)0, serp_logo);
	
	//SelectDisplay(1);
	//_delay_ms(1000);
	//SetOLED((uint8_t)0, bsuir_logo);
	_delay_ms(1000);
	SelectDisplay(2);
	while(1)
	{
		
	}
	return 0;
}
