#ifndef __DS1307_H__
	#define __DS1307_H__
	#include "I2C.h"
	#include "ports.h"
	
	#define READ 1
	
	#define DS1307_ADDR			0xD0
	#define SECONDS_REGISTER	0x00
	#define MINUTES_REGISTER	0x01
	#define HOURS_REGISTER	    0x02
	#define DAYOFWK_REGISTER	0x03
	#define DAYS_REGISTER		0x04
	#define MONTHS_REGISTER		0x05
	#define YEARS_REGISTER		0x06
	#define CONTROL_REGISTER	0x07
	#define RAM_BEGIN			0x08
	#define RAM_END				0x3F
	
	#define TW_START 0xA4   // отправка start condition (TWINT,TWSTA,TWEN)
	#define TW_STOP 0x94    // отправка stop condition (TWINT,TWSTO,TWEN)
	#define TW_ACK 0xC4     // возврат ACK для подчиненного устройства (slave)
	#define TW_NACK 0x84    // нет возврата ACK для slave
	#define TW_SEND 0x84    // отправка данных (TWINT,TWEN)
	#define TW_READY (TWCR & 0x80)      // готовность, когда TWINT вернется в лог. 1
	#define TW_STATUS (TWSR & 0xF8)     // вернет значение из регистра статуса
	
	void DS1307_Init(unsigned char rs);
	uint8_t DS1307_ReadRegister(uint8_t deviceRegister);
	void SetTime(uint8_t hour, uint8_t min);
#endif