#include "main.h"
#define __AVR_ATmega16A__
uint16_t i;



void ssd1306_command(uint8_t data);

int main(void)
{

	init_ports();
	i2cInit();
	DS1307_Init(0);
	//_delay_ms(100);
	//
	//
	//InitLed();
	//ClearDisplay();
	//SetIntensity(0x0F);
	//WriteNum(ONE, TWO, THREE);
	//_delay_ms(1000);
	//WriteNum(SIX, FIVE, FOUR);
	//_delay_ms(1000);
	//WriteNum(NINE, EITHT, SEVEN);
	//_delay_ms(1000);
	//WriteNum(EMPTY, ZERO, ZERO);
	//_delay_ms(1000);
	//WriteNum(G, P, S);
	//
	//
	//_delay_ms(1000);
	//
	//SelectDisplay(2);
	//InitOLED();
	//OLED_Command(SSD1306_DISPLAYON);
	//ClearOLED();
	//
	//SetPointer(0x00);
	//SelectDisplay(0);
	//Set_OLED_Image(ansgrem_struct, ansgrem_logo);
	//_delay_ms(1000);
	//
	//SelectDisplay(1);
	//Set_OLED_Image(bsuir_struct, bsuir_logo);
	//_delay_ms(1000);
	//
	//SelectDisplay(2);
	//Set_OLED_Image(avr_struct, avr_logo);
	//_delay_ms(1000);
	//ClearOLED();
	//
	//initSymbolOLED();
	//
	//DS1307_SetTime(0x20, 0x48);
	//
	//SelectDisplay(1);
	//SetPointer(0x00);
	//Set_OLED_Image(sputnik_struct, sputnik_logo);
	//_delay_ms(1000);
	//
	//SelectDisplay(0);
	//SetPointer(0x3C);
	//Set_OLED_Image(colon_struct, colon_logo);
	
	USART_Init(MYUBRR);
	//sei();
	while(1)
	{
		//GetTime();
		//_delay_ms(200);
		if(Get_flagRX() == 1)
		{
			USARTReceiveChar();
		}
	}
	return 0;
}


void initSymbolOLED(void)
{
	OLED_Command(SSD1306_DISPLAYOFF);

	SelectDisplay(2);
	SetPointer(0x08);
	Set_OLED_Num(GetNum(0));
	//_delay_ms(1000);
	SetPointer(0x22);
	Set_OLED_Num(GetNum(1));
	//_delay_ms(1000);
	SetPointer(0x41);
	Set_OLED_Num(GetNum(2));
	//_delay_ms(1000);
	SetPointer(0x5B);
	Set_OLED_Num(GetNum(3));
	SelectDisplay(2);
	SetPointer(0x08);
	Set_OLED_Num(GetNum(4));
	//_delay_ms(1000);
	SetPointer(0x22);
	Set_OLED_Num(GetNum(5));
	//_delay_ms(1000);
	SetPointer(0x41);
	Set_OLED_Num(GetNum(6));
	//_delay_ms(1000);
	SetPointer(0x5B);
	Set_OLED_Num(GetNum(7));
	SelectDisplay(2);
	SetPointer(0x08);
	Set_OLED_Num(GetNum(8));
	//_delay_ms(1000);
	SetPointer(0x22);
	Set_OLED_Num(GetNum(9));
	
	OLED_Command(SSD1306_DISPLAYON);
	ClearOLED();
}