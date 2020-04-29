#include "ds1307.h"

void DS1307_Init(uint8_t rs)
{
	rs &= 0x03;
	i2cstart(DS1307_ADDR);
	i2cwrite(0x07);
	i2cwrite(0x13);
	//i2cwrite(0x00);
	//i2cwrite(0x00);
	//i2cwrite(rs);
	i2cstop();
	i2cstart(DS1307_ADDR);
	i2cwrite(0x00);
	i2cwrite(0x00);
	i2cstop();
}

uint8_t DS1307_ReadRegister(uint8_t deviceRegister)
// Функция читает байт из внутреннего регистра slave-устройства.
{
	uint8_t data0, data1, data2,boo = 0;
	//i2cstart(DS1307_ADDR);      // отправка адреса шины I2C
	//i2cwrite(deviceRegister); // установка указателя на регистр
	//i2cstop();
	//i2cstart(DS1307_ADDR | 0x01);   // перезапуск для операции чтения
	//data = I2C_ReadNACK();     // чтение данных регистра
	//i2cstop();
	//return data;
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

