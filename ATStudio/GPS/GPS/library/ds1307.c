#include "ds1307.h"
uint8_t buffer0, buffer1, buffer2;

void DS1307_Init(uint8_t rs)
{
	buffer0 = 0xFF;
	buffer1 = 0xFF;
	buffer2 = 0xFF;
	rs &= 0x03;
	i2cstart(DS1307_ADDR);
	i2cwrite(DS1307_CONTROL_REGISTER);
	i2cwrite(0x13);
	i2cstop();
	i2cstart(DS1307_ADDR);
	i2cwrite(0x00);
	i2cwrite(0x00);
	i2cstop();
}

// Функция читает байт из внутреннего регистра slave-устройства.
uint8_t DS1307_ReadRegister(uint8_t deviceRegister)
{
	uint8_t boo = 0;
	i2cstart(DS1307_ADDR);
	i2cwrite(deviceRegister);
	i2cstop();
	i2cstart(DS1307_ADDR | 0x01);
	boo = i2cread(0x00);
	i2cstop();
	return boo;
}

void DS1307_SetTime(uint8_t hour, uint8_t minutes)
{
	i2cstart(DS1307_ADDR);
	i2cwrite(DS1307_MINUTES_REGISTER);
	i2cwrite(minutes);
	i2cwrite(hour);
	i2cstop();
}


void GetTime(void)
{
	uint8_t second, minute, hour, a, b;
	
	second = DS1307_ReadRegister(DS1307_SECONDS_REGISTER);
	
	a = (second>>4);
	b = second;
	a&= 7;
	b&= 15;
	if(b != buffer0)
	{
		SelectDisplay(0);
		if(b == 0x00 || b == 0x02|| b == 0x04 || b == 0x06||b == 0x08)
		{
			SetPointer(0x3C);
			Set_OLED_Image(Ncolon_struct, Ncolon_logo);
		}
		else
		{
			SetPointer(0x3C);
			Set_OLED_Image(colon_struct, colon_logo);
		}
		buffer0 = b;
		SelectDisplay(1);
		SetPointer(0x5B);
		Set_OLED_Num(GetNum(b));
		SetPointer(0x41);
		Set_OLED_Num(GetNum(a));
		
		minute = DS1307_ReadRegister(DS1307_MINUTES_REGISTER);
		
		a = (minute>>4);
		b = minute;
		a&= 7;
		b&= 15;
	
		if(b != buffer1)
		{
			SelectDisplay(0);
			SetPointer(0x5B);
			Set_OLED_Num(GetNum(b));
			SetPointer(0x41);
			Set_OLED_Num(GetNum(a));
			buffer1 = b;
		
			hour = DS1307_ReadRegister(DS1307_HOURS_REGISTER);
			a = (hour>>4);
			b = hour;
			a&= 7;
			b&= 15;
			if(b != buffer2)
			{
				SetPointer(0x22);
				Set_OLED_Num(GetNum(b));
				SetPointer(0x08);
				Set_OLED_Num(GetNum(a));
				buffer2 = b;
			}
		}
	}
	else
	{
		return;
	}
}

//запись в бсд
uint8_t In_BCD(uint8_t n)
{
	asm volatile(
		"ld   r26,y+"	"\n\t" 
		"clr  r30"		"\n\t" 
	"bin2bcd0:"			"\n\t" 
		"subi r26,10"	"\n\t" 
		"brmi bin2bcd1" "\n\t" 
		"subi r30,-16"	"\n\t" 
		"rjmp bin2bcd0" "\n\t" 
	"bin2bcd1:"			"\n\t" 
		"subi r26,-10"	"\n\t" 
		"add  r30,r26"	"\n\t" 
		"ret" "\n\t" 
	::);
}

//чтение из бсд
uint8_t Out_BCD(uint8_t n)
{
	asm volatile(
	"ld   r30,y"		"\n\t" 
	"swap r30"			"\n\t"
	"andi r30,0xf"		"\n\t"
	"mov  r26,r30"		"\n\t"
	"lsl  r26"			"\n\t"
	"lsl  r26"			"\n\t"
	"add  r30,r26"		"\n\t"
	"lsl  r30"			"\n\t"
	"ld   r26,y+"		"\n\t"
	"andi r26,0xf"		"\n\t"
	"add  r30,r26"		"\n\t"
	"ret" "\n\t"
	::);
}