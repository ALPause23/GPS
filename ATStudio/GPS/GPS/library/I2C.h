#ifndef __I2C_H__
	#define __I2C_H__
	
	#include "ports.h"
	
    #define F_CPU 8000000UL
    #define F_I2C 50000UL
    #define TWBR_VALUE 1//(((F_CPU)/(F_I2C)-16)/2)
    
	#define RTC_RESET_POINTER   0xFF

    #if ((TWBR_VALUE > 255) || (TWBR_VALUE == 0))
        #error "TWBR value is not correct"
    #endif
	
	#define TWI_START					0x08	// START has been transmitted
	#define TWI_REP_START				0x10	// Repeated START has been transmitted
	#define TWI_ARB_LOST				0x38	// Arbitration lost

	#define TWI_MTX_ADR_ACK				0x18	// SLA+W has been tramsmitted and ACK received
	#define TWI_MTX_ADR_NACK			0x20	// SLA+W has been tramsmitted and NACK received
	#define TWI_MTX_DATA_ACK			0x28	// Data byte has been tramsmitted and ACK received
	#define TWI_MTX_DATA_NACK			0x30	// Data byte has been tramsmitted and NACK received


	#define TWI_MRX_ADR_ACK				0x40	// SLA+R has been tramsmitted and ACK received
	#define TWI_MRX_ADR_NACK			0x48	// SLA+R has been tramsmitted and NACK received
	#define TWI_MRX_DATA_ACK			0x50	// Data byte has been received and ACK tramsmitted
	#define TWI_MRX_DATA_NACK			0x58	// Data byte has been received and NACK tramsmitted
	#define TWSR_MASK					0xFC	// вернет значение из регистра статуса
	
	void i2cInit(void);
	uint8_t i2cstart(uint8_t address);
	uint8_t i2cwrite(uint8_t data);
	uint8_t i2cread(uint8_t ask);
	void i2cstop(void);
	
#endif