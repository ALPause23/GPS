#include "I2C.h"

uint8_t twi_status_register;

uint8_t i2cstart(uint8_t address)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)))
		;

	twi_status_register = TW_STATUS & 0xF8;
	if ((twi_status_register != TW_START) && (twi_status_register != TW_REP_START))
	{
		return 1;
	}

	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)))
		;

	twi_status_register = TW_STATUS & 0xF8;
	if ((twi_status_register != TW_MT_SLA_ACK) && (twi_status_register != TW_MR_SLA_ACK))
	{
		return 1;
	}
	return 0;
}

uint8_t i2cwrite(uint8_t data)
{
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	while(!(TWCR & (1<<TWINT)));

	twi_status_register = TW_STATUS & 0xF8;
	if (twi_status_register != TW_MT_DATA_ACK)
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}

void i2cstop(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	while(TWCR & (1<<TWSTO));
}