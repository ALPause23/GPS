#ifndef LED_MAX7219_H__
#define LED_MAX7219_H__
			#include <avr/io.h>
			#include <avr/interrupt.h>
			#include <util/delay.h>
			#include <stdio.h>
			#include <stdlib.h>
			#include <avr/pgmspace.h>  
			//#include "ports.h"                             

			#define NO_OP				0x00
			#define NO_DECODE_MODE		0x0900
			#define INTENSITY			0x0A00  // (ot 0 do F)
			#define SCAN_LIMIT			0x0B00	// (ot 0 do 7)
			#define SHUTDOWN			0x0C00	// (0 - shotdown, 1 - no shotdown)
			#define DISPLAY_TEST		0x0F00	// (1 - test)
			
			//#define CS					PortB4
			//#define MOSI				PortB5
			//#define SCK					PortB7
			
			void IniLed();
			void SPI_WriteStartByte(char data);
			void SPI_WriteEndByte(char data);
			void SPI_WriteByte(char data);
			void SPI_WriteByte(char data);
			void SendLed(char adr, char data);
			void ClearDisplay();
			void WriteNum(char *x, char *y, char *z);  
			                    
			static const unsigned char ONE[8] =
			{
				// @0 '1' (4 pixels wide)
				0x60, //  ##
				0xE0, // ###
				0x60, //  ##
				0x60, //  ##
				0x60, //  ##
				0x60, //  ##
				0x60, //  ##
			};
			static const unsigned char TWO[8] =
			{
				// @0 '2' (6 pixels wide)
				0x70, //  ###
				0xD8, // ## ##
				0x18, //    ##
				0x30, //   ##
				0x60, //  ##
				0xC0, // ##
				0xF8, // #####
			};
			static const unsigned char THREE[8] =
			{
				// @0 '3' (6 pixels wide)
				0x70, //  ###
				0xD8, // ## ##
				0x18, //    ##
				0x30, //   ##
				0x18, //    ##
				0xD8, // ## ##
				0x70, //  ###
			};
			static const unsigned char FOUR[8] =
			{
				// @0 '4' (6 pixels wide)
				0x18, //    ##
				0x38, //   ###
				0x78, //  ####
				0xD8, // ## ##
				0xFC, // ######
				0x18, //    ##
				0x18, //    ##
			};
			static const unsigned char FIVE[8] =
			{
				// @0 '5' (6 pixels wide)
				0xF8, // #####
				0xC0, // ##
				0xF0, // ####
				0x18, //    ##
				0x18, //    ##
				0xD8, // ## ##
				0x70, //  ###
			};
			static const unsigned char SIX[8] =
			{
				// @0 '6' (6 pixels wide)

				0x70, //  ###
				0xD8, // ## ##
				0xC0, // ##
				0xF0, // ####
				0xD8, // ## ##
				0xD8, // ## ##
				0x70, //  ###
			};
			static const unsigned char SEVEN[8] =
			{
				// @0 '7' (6 pixels wide)
				0xF8, // #####
				0x18, //    ##
				0x30, //   ##
				0x30, //   ##
				0x30, //   ##
				0x60, //  ##
				0x60, //  ##
			};
			static const unsigned char EITHT[8] =
			{
				// @0 '8' (5 pixels wide)
				0x70, //  ###
				0xD8, // ## ##
				0xD8, // ## ##
				0x70, //  ###
				0xD8, // ## ##
				0xD8, // ## ##
				0x70, //  ###
			};
			static const unsigned char NINE[8] =
			{
				// @0 '9' (5 pixels wide)
				0x70, //  ###
				0xD8, // ## ##
				0xD8, // ## ##
				0x78, //  ####
				0x18, //    ##
				0xD8, // ## ##
				0x70, //  ###
			};
			static const unsigned char ZERO[8] =
			{
				// @0 '0' (6 pixels wide)
				0x70, //  ###
				0xD8, // ## ##
				0xD8, // ## ##
				0xD8, // ## ##
				0xD8, // ## ##
				0xD8, // ## ##
				0x70, //  ###
			};

			static const unsigned char Z[8] =
			{
				0x78, //  ####
				0xCC, // ##  ##
				0xDC, // ## ###
				0xDC, // ## ###
				0xFC, // ######
				0xEC, // ### ##
				0xEC, // ### ##
				0xCC, // ##  ##
			};
			static const const unsigned char Y[8] =
			{
				// @9 '�' (7 pixels wide)
				0x00, //
				0xC6, // ##   ##
				0x6C, //  ## ##
				0x6C, //  ## ##
				0x38, //   ###
				0x38, //   ###
				0x30, //   ##
				0xE0, // ###
			};
			static const const unsigned char X[8] =
			{
				// @18 '�' (7 pixels wide)
				0x00, //
				0xC6, // ##   ##
				0x6C, //  ## ##
				0x38, //   ###
				0x38, //   ###
				0x38, //   ###
				0x6C, //  ## ##
				0xC6, // ##   ##
			};
#endif;