#include "I2C.h"

uint8_t twi_status_register;

void i2cInit(void)
{
	TWBR = TWBR_VALUE;
	TWSR = 0;
}

uint8_t i2cread(uint8_t ask)
{
	int i = 0;
	uint8_t data;
	while(!(TWCR & (1<<TWINT)))
	{
		i++;
		if(i == 300)
		{
			break;
		}
	}
	
	TWCR = (1<<TWINT)|(1<<TWEN)|((ask & 1) << TWEA);
	while(!(TWCR & (1<<TWINT)))
	{
		i++;
		if(i == 300)
		{
			break;
		}
	}
	
	data = TWDR;
	twi_status_register = TWSR & TWSR_MASK;
	
	if ((ask && (twi_status_register != TWI_MRX_DATA_ACK))||(!ask && (twi_status_register != TWI_MRX_DATA_NACK)))
	{
		return twi_status_register;
	}
	return data;
}

uint8_t i2cstart(uint8_t address)
{
	int i = 0;
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)))
	{
		i++;
		if(i == 300)
		{
			break;
		}
	}
	twi_status_register = TWSR & TWSR_MASK;
	if ((twi_status_register != TWI_START) && (twi_status_register != TWI_REP_START)){
		return twi_status_register;
	}
	while (!(TWCR & (1<<TWINT)))
	{
		i++;
		if(i == 300)
		{
			break;
		}
	}
	 
	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)))
	{
		i++;
		if(i == 300)
		{
			break;
		}
	}
	
	twi_status_register = TWSR & TWSR_MASK;
	if ((twi_status_register != TWI_MTX_ADR_ACK) && (twi_status_register != TWI_MRX_ADR_ACK)){
		return twi_status_register;
	}
	return 255;
}

uint8_t i2cwrite(uint8_t data)
{
	int i = 0;
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	while(!(TWCR & (1<<TWINT)))
	{
		i++;
		if(i == 300)
		{
			break;
		}
	}

	twi_status_register = TWSR & TWSR_MASK;
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
	int i = 0;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	while(TWCR & (1<<TWSTO))
	{
		i++;
		if(i == 300)
		{
			break;
		}
	}
}