#include "main.h"
#define __AVR_ATmega16A__
uint16_t i;
uint8_t a,b;


void ssd1306_command(uint8_t data);

int main(void)
{

	init_ports();
	_delay_ms(100);
	
	
	//InitLed();
	//ClearDisplay();
	//
	//WriteNum(ONE, TWO, THREE);
	//_delay_ms(100);
	//WriteNum(SIX, FIVE, FOUR);
	//_delay_ms(100);
	//WriteNum(NINE, EITHT, SEVEN);
	//_delay_ms(100);
	//WriteNum(EMPTY, ZERO, ZERO);
	//_delay_ms(100);
	//WriteNum(G, P, S);
	//
	//
	//_delay_ms(1000);
	//SetIntensity(0);
	SelectDisplay(2);
	InitOLED();
	ClearOLED();
	
	//SelectDisplay(0);
	////_delay_ms(1000);
	//SetOLED1(ansgrem_struct, ansgrem_logo);
	//_delay_ms(1000);
	//SelectDisplay(1);
	////
	//SetOLED1(bsuir_struct, bsuir_logo);
	//_delay_ms(1000);
	//SelectDisplay(2);
	//SetOLED1(avr_struct, avr_logo);
	//_delay_ms(1000);
	//SelectDisplay(2);
	//ClearOLED();
	//_delay_ms(1000);
	SelectDisplay(0);
	SetPointer(0x08);
	Set_OLED_Num(GetNum(0));
	_delay_ms(1000);
	SetPointer(0x22);
	Set_OLED_Num(GetNum(1));
	_delay_ms(1000);
	SetPointer(0x41);
	Set_OLED_Num(GetNum(2));
	_delay_ms(1000);
	SetPointer(0x5B);
	Set_OLED_Num(GetNum(3));
	SelectDisplay(1);
	SetPointer(0x08);
	Set_OLED_Num(GetNum(4));
	_delay_ms(1000);	
	SetPointer(0x22);
	Set_OLED_Num(GetNum(5));
	_delay_ms(1000);
	SetPointer(0x41);
	Set_OLED_Num(GetNum(6));
	_delay_ms(1000);
	SetPointer(0x5B);
	Set_OLED_Num(GetNum(7));
	//SelectDisplay(0);
	//SetPointer(0x08);
	//Set_OLED_Num(GetNum(8));
	//_delay_ms(1000);
	//SetPointer(0x22);
	//Set_OLED_Num(GetNum(9));
	//_delay_ms(1000);
	while(1)
	{
		
	}
	return 0;
}
