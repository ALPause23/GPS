#include "ds1307.h"



void DS1307_Init(uint8_t rs)
{
	rs &= 0x03;
	i2cstart(DS1307_ADDR);
	i2cwrite(0x07);
	i2cwrite(0x13);
	i2cstop();
	i2cstart(DS1307_ADDR);
	i2cwrite(0x00);
	i2cwrite(0x00);
	i2cstop();
	//i2cstart(DS1307_ADDR);
	//i2cwrite(MINUTES_REGISTER);
	//i2cwrite(0x00);
	//i2cwrite(0x02);
	i2cstop();
}

uint8_t DS1307_ReadRegister(uint8_t deviceRegister)
// Функция читает байт из внутреннего регистра slave-устройства.
{
	uint8_t data0, data1, data2,boo = 0;
	i2cstart(DS1307_ADDR);
	i2cwrite(deviceRegister);
	i2cstop();
	i2cstart(DS1307_ADDR | 0x01);
	//data0 = i2cread(0x01);
	//data1 = i2cread(0x01);
	//data2 = i2cread(0x01);
	boo = i2cread(0x00);
	i2cstop();
	return boo;
}

//запись в бсд
//unsigned char bin2bcd(unsigned char n)
//{
	//asm volatile(
		//"ld   r26,y+"
		//"clr  r30"
	//"bin2bcd0:"
		//"subi r26,10"
		//"brmi bin2bcd1"
		//"subi r30,-16"
		//"rjmp bin2bcd0"
	//"bin2bcd1:"
		//"subi r26,-10"
		//"add  r30,r26"
		//"ret"
	//::);
//}

//чтение из бсд
uint8_t bcd2bin(uint8_t n)
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