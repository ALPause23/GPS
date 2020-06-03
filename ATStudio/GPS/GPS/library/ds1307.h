#ifndef __DS1307_H__
	#define __DS1307_H__
	#include "OLED.h"
	#include "ports.h"
	
	#define READ 1
	
	#define DS1307_ADDR					0xD0
	#define DS1307_SECONDS_REGISTER		0x00
	#define DS1307_MINUTES_REGISTER		0x01
	#define DS1307_HOURS_REGISTER	    0x02
	#define DS1307_DAYOFWK_REGISTER		0x03
	#define DS1307_DAYS_REGISTER		0x04
	#define DS1307_MONTHS_REGISTER		0x05
	#define DS1307_YEARS_REGISTER		0x06
	#define DS1307_CONTROL_REGISTER		0x07
	#define DS1307_RAM_BEGIN			0x08
	#define DS1307_RAM_END				0x3F
	
	
	
	void DS1307_Init(unsigned char rs);
	uint8_t DS1307_ReadRegister(uint8_t deviceRegister);
	void DS1307_SetTime(uint8_t hour, uint8_t min);
	void DS1307_GetTime(void);

	void GetTime();

	//asm
	uint8_t Out_BCD(uint8_t n);
	uint8_t In_BCD(uint8_t a, uint8_t b, char hour);
	uint8_t Out_ASCII(uint8_t symbol);
#endif