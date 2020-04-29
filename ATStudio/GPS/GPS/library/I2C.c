#include "I2C.h"

uint8_t twi_status_register;

void i2cInit(void)
{
	TWBR = TWBR_VALUE;
	TWSR = 0;
}

uint8_t i2cread(uint8_t ask)
{
	uint8_t data;
	//TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	TWCR = (1<<TWINT)|(1<<TWEN)|((ask & 1) << TWEA);
	while(!(TWCR & (1<<TWINT)));
	data = TWDR;
	twi_status_register = TWSR & 0xfc;
	
	if ((ask && (twi_status_register != 0x50))||(!ask && (twi_status_register != 0x58))){
		return twi_status_register;
	}
	return data;
}

uint8_t i2cstart(uint8_t address)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)))
		;
	twi_status_register = TWSR & 0xFC;
	if ((twi_status_register != 0x08) && (twi_status_register != 0x10)){
		return twi_status_register;
	}
	//return 0xff;
	//twi_status_register = TW_STATUS & 0xF8;
	//if ((twi_status_register != TW_START) && (twi_status_register != TW_REP_START))
	//{
		//return 1;
	//}
	 while (!(TWCR & (1<<TWINT))); 
	 
	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)))
		;
	twi_status_register = TWSR & 0xfc;
	if ((twi_status_register != 0x18) && (twi_status_register != 0x40)){
		return twi_status_register;
	}
	return 255;
	//twi_status_register = TW_STATUS & 0xF8;
	//if ((twi_status_register != TW_MT_SLA_ACK) && (twi_status_register != TW_MR_SLA_ACK))
	//{
		//return 1;
	//}
	//return 0;
}

uint8_t i2cwrite(uint8_t data)
{
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	while(!(TWCR & (1<<TWINT)));

	twi_status_register = TWSR & 0xfc;
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
	//while(TWCR & (1<<TWSTO));
}