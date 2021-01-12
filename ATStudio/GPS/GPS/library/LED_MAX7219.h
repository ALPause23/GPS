﻿#ifndef LED_MAX7219_H__
#define LED_MAX7219_H__

		#include "ports.h"                             

		#define NO_OP				0x00
		#define NO_DECODE_MODE		(uint16_t)0x0900
		#define INTENSITY			(uint16_t)0x0A00  // (ot 0 do F)
		#define SCAN_LIMIT			(uint16_t)0x0B00	// (ot 0 do 7)
		#define SHUTDOWN			(uint16_t)0x0C00	// (0 - shotdown, 1 - no shotdown)
		#define DISPLAY_TEST		(uint16_t)0x0F00	// (1 - test)
			
		#define CS					PortB4
		#define MOSI				PortB5
		#define SCK					PortB7
			
		void InitLed();
		void ClearDisplay();
		void WriteNum(const char *z, const char *y, const char *x); 
		void SetIntensity(uint8_t a);
		const char* GetNumbers(int i);
			                    
		static const char PROGMEM ONE[8] =
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
		static const char PROGMEM TWO[8] =
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
		static const char PROGMEM THREE[8] =
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
		static const char PROGMEM FOUR[8] =
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
		static const char PROGMEM FIVE[8] =
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
		static const char PROGMEM SIX[8] =
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
		static const char PROGMEM SEVEN[8] =
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
		static const char PROGMEM EITHT[8] =
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
		static const char PROGMEM NINE[8] =
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
		static const char PROGMEM ZERO[8] =
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
		
		static const char PROGMEM G[8] = {
			0x3C,
			0x66,
			0xC0,
			0xC0,
			0xCE,
			0x66,
			0x3C,
			0x0
		};
		
		static const char PROGMEM P[8] = {
			0x7C,
			0x66,
			0x66,
			0x7C,
			0x60,
			0x60,
			0x60,
			0x0
		};
		
		static const char PROGMEM S[8] = {
			0x3C,
			0x66,
			0x70,
			0x38,
			0xE,
			0x66,
			0x3C,
			0x0
		};
		
		static const char PROGMEM EMPTY[8] = {
			0x00,
			0x00,
			0x00,
			0x00,
			0x00,
			0x00,
			0x00,
			0x00
		};
<<<<<<< HEAD
#endif //LED_MAX7219_H__ 
=======
#endif;
>>>>>>> parent of d94a2eb... предрабочая версия
