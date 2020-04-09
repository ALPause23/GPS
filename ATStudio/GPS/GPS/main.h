#ifndef MAIN_H_
	#define MAIN_H_
	
	#define F_CPU 8000000UL
	#define F_I2C 50000UL
	#define TWBR_VALUE (((F_CPU)/(F_I2C)-16)/2)
	#define RTC_RESET_POINTER   0xff

	#if ((TWBR_VALUE > 255) || (TWBR_VALUE == 0))
		#error "TWBR value is not correct"
	#endif
	
	#include <avr/io.h>
	#include <avr/interrupt.h>
	#include <util/delay.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <avr/io.h>
	#include <avr/pgmspace.h>
	#include <util/delay.h>
	
#endif /* MAIN_H_ */