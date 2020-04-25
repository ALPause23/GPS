#ifndef LED_MAX7219_H__
#define LED_MAX7219_H__
		#include <avr/io.h>
		#include <avr/interrupt.h>
		#include <util/delay.h>
		#include <stdio.h>
		#include <stdlib.h>
		#include <avr/pgmspace.h>  
		#include "ports.h"                             

		#define NO_OP				0x00
		#define NO_DECODE_MODE		0x0900
		#define INTENSITY			0x0A00  // (ot 0 do F)
		#define SCAN_LIMIT			0x0B00	// (ot 0 do 7)
		#define SHUTDOWN			0x0C00	// (0 - shotdown, 1 - no shotdown)
		#define DISPLAY_TEST		0x0F00	// (1 - test)
			
		#define CS					PortB4
		#define MOSI				PortB5
		#define SCK					PortB7
			
		void InitLed();
		void ClearDisplay();
		void WriteNum(char *x, char *y, char *z); 
		void SetIntensity(uint8_t a) ;
			                    
		static const unsigned char PROGMEM ONE[8] =
		{
			0x18,
			0x38,
			0x18,
			0x18,
			0x18,
			0x18,
			0x18,
			0x3C
		};
		static const unsigned char PROGMEM TWO[8] =
		{
			0x3C,
			0x66,
			0x6,
			0xC,
			0x18,
			0x30,
			0x60,
			0x7E
		};
		static const unsigned char PROGMEM THREE[8] =
		{
			0x7E,
			0x66,
			0xC,
			0x1C,
			0x6,
			0x6,
			0x66,
			0x3C
		};
		static const unsigned char PROGMEM FOUR[8] =
		{
			0xE,
			0x1E,
			0x36,
			0x66,
			0x7F,
			0x6,
			0x6,
			0x6
		};
		static const unsigned char PROGMEM FIVE[8] =
		{
			0x7E,
			0x60,
			0x60,
			0x7C,
			0x6,
			0x6,
			0x66,
			0x3C
		};
		static const unsigned char PROGMEM SIX[8] =
		{
			0x1C,
			0x30,
			0x60,
			0x7C,
			0x66,
			0x66,
			0x66,
			0x3C
		};
		static const unsigned char PROGMEM SEVEN[8] =
		{
			0x7E,
			0x6,
			0x6,
			0xC,
			0x18,
			0x18,
			0x18,
			0x18
		};
		static const unsigned char PROGMEM EITHT[8] =
		{
			0x3C,
			0x66,
			0x66,
			0x3C,
			0x66,
			0x66,
			0x66,
			0x3C
		};
		static const unsigned char PROGMEM NINE[8] =
		{
			0x3C,
			0x66,
			0x66,
			0x66,
			0x3E,
			0x6,
			0xC,
			0x38
		};
		static const unsigned char PROGMEM ZERO[8] =
		{
			0x3C,
			0x66,
			0x66,
			0x66,
			0x66,
			0x66,
			0x66,
			0x3C
		};
			
		static const unsigned char PROGMEM G[8] = {
			0x3C,
			0x66,
			0xC0,
			0xC0,
			0xCE,
			0x66,
			0x3C,
			0x0
		};
			
		static const unsigned char PROGMEM P[8] = {
			0x7C,
			0x66,
			0x66,
			0x7C,
			0x60,
			0x60,
			0x60,
			0x0
		};
			
		static const unsigned char PROGMEM S[8] = {
			0x3C,
			0x66,
			0x70,
			0x38,
			0xE,
			0x66,
			0x3C,
			0x0
		};
			
		static const unsigned char PROGMEM EMPTY[8] = {
			0x00,
			0x00,
			0x00,
			0x00,
			0x00,
			0x00,
			0x00,
			0x00
		};
#endif;