#ifndef __I2C_H__
	#define __I2C_H__
	
	#include <avr/io.h>
	#include <util/delay.h>
	#include "util/twi.h"

	
    #define F_CPU 8000000UL
    #define F_I2C 50000UL
    #define TWBR_VALUE (((F_CPU)/(F_I2C)-16)/2)
    
	#define RTC_RESET_POINTER   0xFF

    #if ((TWBR_VALUE > 255) || (TWBR_VALUE == 0))
        #error "TWBR value is not correct"
    #endif
	
	uint8_t i2cstart(uint8_t address);
	uint8_t i2cwrite(uint8_t data);
	void i2cstop(void);
	
#endif