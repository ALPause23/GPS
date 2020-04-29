#include "main.h"
#define __AVR_ATmega16A__
uint16_t i;
uint8_t d;
int a,b;


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
	//SetIntensity(0x00);
	//WriteNum(ONE, TWO, THREE);
	//_delay_ms(5000);
	//WriteNum(SIX, FIVE, FOUR);
	//_delay_ms(5000);
	//WriteNum(NINE, EITHT, SEVEN);
	//_delay_ms(5000);
	//WriteNum(EMPTY, ZERO, ZERO);
	//_delay_ms(5000);
	//WriteNum(G, P, S);
	//
	//
	//_delay_ms(1000);
	
	SelectDisplay(2);
	InitOLED();
	OLED_Command(SSD1306_DISPLAYON);
	ClearOLED();
	//
	SelectDisplay(0);
	//_delay_ms(1000);
	Set_OLED_Image(ansgrem_struct, ansgrem_logo);
	_delay_ms(1000);
	SelectDisplay(1);
	//
	Set_OLED_Image(bsuir_struct, bsuir_logo);
	_delay_ms(1000);
	SelectDisplay(2);
	Set_OLED_Image(avr_struct, avr_logo);
	_delay_ms(1000);
	SelectDisplay(2);
	ClearOLED();
	OLED_Command(SSD1306_DISPLAYOFF);
	i2cstop();
	//_delay_ms(1000);
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
	//_delay_ms(1000);
	
	OLED_Command(SSD1306_DISPLAYON);
	ClearOLED();
	
	while(1)
	{
		SelectDisplay(0);
		d = DS1307_ReadRegister(HOURS_REGISTER);
		a = (int)(d>>4);
		b = (int)d;
		a&= 7;
		b&= 15;
		SetPointer(0x08);
		Set_OLED_Num(GetNum(a));
		SetPointer(0x22);
		Set_OLED_Num(GetNum(b));
		d = DS1307_ReadRegister(MINUTES_REGISTER);
		a = (int)(d>>4);
		b = (int)d;
		a&= 7;
		b&= 15;
		SetPointer(0x41);
		Set_OLED_Num(GetNum(a));
		SetPointer(0x5B);
		Set_OLED_Num(GetNum(b));
		SelectDisplay(1);
		d = DS1307_ReadRegister(SECONDS_REGISTER);
		a = (int)(d>>4);
		b = (int)d;
		a&= 7;
		b&= 15;
		SetPointer(0x08);
		Set_OLED_Num(GetNum(a));
		SetPointer(0x22);
		Set_OLED_Num(GetNum(b));
		//_delay_ms(1000);
		
	}
	return 0;
}
