﻿#ifndef __OLED_H__
	#define __OLED_H__
	#include "I2C.h"
	#include "ports.h"
	
	
	#if defined SSD1306_128_64
		#define SSD1306_LCDWIDTH                  128
		#define SSD1306_LCDHEIGHT                 64
	#endif
	#if defined SSD1306_128_32
		#define SSD1306_LCDWIDTH                  128
		#define SSD1306_LCDHEIGHT                 32
	#endif
	#if defined SSD1306_96_16
		#define SSD1306_LCDWIDTH                  96
		#define SSD1306_LCDHEIGHT                 16
	#endif

	#define SSD1306_SETCONTRAST 0x81
	#define SSD1306_DISPLAYALLON_RESUME 0xA4
	#define SSD1306_DISPLAYALLON 0xA5
	#define SSD1306_NORMALDISPLAY 0xA6
	#define SSD1306_INVERTDISPLAY 0xA7
	#define SSD1306_DISPLAYOFF 0xAE
	#define SSD1306_DISPLAYON 0xAF

	#define SSD1306_SETDISPLAYOFFSET 0xD3
	#define SSD1306_SETCOMPINS 0xDA

	#define SSD1306_SETVCOMDETECT 0xDB

	#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
	#define SSD1306_SETPRECHARGE 0xD9

	#define SSD1306_SETMULTIPLEX 0xA8

	#define SSD1306_SETLOWCOLUMN 0x00
	#define SSD1306_SETHIGHCOLUMN 0x10

	#define SSD1306_SETSTARTLINE 0x40

	#define SSD1306_MEMORYMODE 0x20
	#define SSD1306_COLUMNADDR 0x21
	#define SSD1306_PAGEADDR   0x22

	#define SSD1306_COMSCANINC 0xC0
	#define SSD1306_COMSCANDEC 0xC8

	#define SSD1306_SEGREMAP 0xA0

	#define SSD1306_CHARGEPUMP 0x8D

	#define SSD1306_EXTERNALVCC 0x1
	#define SSD1306_SWITCHCAPVCC 0x2

	// Scrolling #defines
	#define SSD1306_ACTIVATE_SCROLL 0x2F
	#define SSD1306_DEACTIVATE_SCROLL 0x2E
	#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
	#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
	#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
	#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
	#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A
	#define SSD1306_LCDHEIGHT 64

	#define SSD1306_ADDR	0x78
	
	#define CODE_COMMAND	0x00
	#define CODE_DATA		0x40			
	
	extern uint8_t oled_pointer;
	
	void SetPointer(uint8_t a);
	uint8_t GetPointer(void);
	
	void SelectDisplay(int i);
	void InitOLED(void);
	void ClearOLED(void);
	void OLED_Command(uint8_t data);
	
	////uint8_t SetLOGO(int i);
	//uint8_t SetOLED2(int i);
	
	typedef struct   
	{
		int	array_size;
		uint8_t long_image;
		uint8_t height_image;
	}IMAGE_OLED;
	
	void Set_OLED_Num(unsigned char *a);
	uint8_t* GetNum(int i);
	void Set_OLED_Image(IMAGE_OLED a, unsigned char *b);
			
	static const unsigned char PROGMEM ansgrem_logo[128] = {
		// #########
		//  ##########
		//  ##############
		//       ##############
		//         #############
		//            #############
		//              ############
		//                 ############
		//                   ############
		//                     ############
		//                         ###########
		//                          ###########
		//                           ###########
		//                           ############
		//                             #############
		//                               ############
		//                                ############
		//                                 #############
		//                                   ############
		//                                    ############
		//                                     ############
		//                                      ###########
		//            ######################################
		//           ########################################
		//           ########################################
		//          ###########################################
		//          ###########################################
		//         ############################################
		//         #############################################
		//                     ############       ##############
		//                     ############       ##############
		//                    ############        ##############
		//                   ############        ##############
		//                   ############        ##############
		//                   ############        ##############
		//                  ###########         ###############
		//                  ###########         ##############
		//                  ###########        ##############
		//                 ############       ###############
		//             ###############     ################
		//            #####################################
		//            #####################################
		//            #####################################
		//            ##################################
		//            ################################
		//            ###############################
		//            #########################
		0x01, 0x03, 0x03, 0x03, 0x07, 0x06, 0x06, 0x0E, 0x1E, 0x1C, 0x1C, 0x3C, 0x78, 0x78, 0x70, 0xE0, 0xE0, 0xE0, 0xC0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x83, 0x83, 0x87, 0x8F, 0x8F, 0xBF, 0xFE, 0xFC, 0xFC, 0xF8, 0xF0, 0xF0, 0xC0, 0x80, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x0F, 0x0F, 0x0F, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x38,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF8, 0xF8, 0xF8, 0xFC, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x1F, 0x1F, 0x07, 0x01, 0x00
		};
	static const IMAGE_OLED ansgrem_struct = {128, 0x20, 0x03};
	
	static const unsigned char PROGMEM  bsuir_logo[244] = {
			//                                ###  ###  ##  ###
			//                               ####   ### #### ###
			//                              ######   ##   ##   ##
			//                            ########    ##  ###  ##
			//                           #########    ##  ###  ##
			//                          ##########    ##  ###  ##
			//                         #### ######   ###  ###  ##
			//                        ####  ######  ###  ###  ###
			//                      #####   ######  ###  ### ###
			//                     ####     ###### ###  ##   ##
			//                    ####      ######
			//                   #####      ######
			//                  ####        ######
			//                #####         ######
			//               #####  ###     ######     #####     #####
			//             #####   ####     ######   ########   #######
			//            #####  ######     ######  #########  #########
			//           #####  #######     ###### #####################
			//          #####  ########     ##### ### ###### ### #######
			//         ####   #########     ####  ##  #####  ##  #######
			//        ####     # ######     ###   #   ####       #######
			//       ####        ######     ##        ###   #    #######
			//      ####         ######     #    #    #    ##    #######
			//     ####          ######         ##        ###    #######
			//   #####           ######    #  ####   #   ####    #######
			//  ####             ######   ## #####  ## ######    #######
			// ####              ######  ######### ### ########  ####### #
			// ###               ########## #################### ##########
			// ##                #########  ########  #########  #########
			// #                 ########   #######   ########   ########
			//                   ######     ######    #######    #######
			//                   #####      #####      #####      #####
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0x78, 0x38, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x01, 0x83, 0xC7, 0xFE, 0x78, 0x03, 0x83, 0xFE, 0xFE, 0x79, 0x03, 0x83, 0xFE, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0xE0, 0xE0, 0x70, 0x78, 0x3C, 0x9E, 0xCF, 0xCF, 0xC3, 0x01, 0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x02, 0x03, 0x83, 0x81, 0xC0, 0xC2, 0xC3, 0xC1, 0xC1, 0x80, 0x03, 0x03, 0x01, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0x78, 0x3C, 0x1E, 0x0F, 0x07, 0x07, 0x03, 0x09, 0x1C, 0x0E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x3F, 0x1F, 0x0F, 0x87, 0xC3, 0x1C, 0x0E, 0x07, 0x03, 0x7F, 0x3F, 0x3F, 0x1F, 0x8F, 0xC7, 0xE3, 0x0E, 0x0E, 0x07, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
			0x3C, 0x1E, 0x0F, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x38, 0x38, 0x1C, 0x0E, 0x07, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0x38, 0x1C, 0x0E, 0x0F, 0x78, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0x3C, 0x1C, 0x08, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x38, 0x1C, 0x08, 0x00
		};
	static const IMAGE_OLED bsuir_struct = {244, 61, 0x03};

	static const unsigned char PROGMEM avr_logo[512] = {
		//                   ###########        ##############                         ############         ####################
		//                  ############        ###############                       ############        ########################
		//                 ##############        ##############                      ############        ############################
		//                ################        ##############                    #############       ##############################
		//               ##################        #############                   #############        ###############################
		//               ###################        #############                 #############        ##########          #############
		//              #####################        #############               #############        ###########          #############
		//             #######################        #############             #############        ############          #############
		//             ############ ###########        #############            ############         ###########           #############
		//            ###########    ##########        ##############          ############         ###########          ###############
		//           ############    ###########        ##############        #############        ###########           ##############
		//          ############      ###########        #############       #############        ####################################
		//         #############      ############       ##############     #############         ####################################
		//        #############       ############        ###############   #############        ##################################
		//        #############        ############        ##############  #############        ##################################
		//       ###################################        ###########################        ############  #############
		//       ####################################        #########################         ############  #############
		//      ######################################        #######################         ############    #############
		//     ########################################        #####################         ############     #############
		//    ##########################################       ####################         ############       #############
		//    ##########################################        ###################         ###########        #############
		//   #############                   ############        #################         ###########          #############
		//  #############                     ############        ################         ###########          ##############
		//  #############                      ############       ##############          ###########            ##############
		// #############                        ############       #############         ############             ##############
		// #############                         ###########        ###########         ############              ##############
		//                                                           #########
		//                                                           ########
		//                                                            #######
		//                                                              ####
		//                                                               ##
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x03, 0x01, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC, 0xF8, 0xF0, 0xE0, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x87, 0x81, 0x81, 0x80, 0x81, 0x87, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF8, 0xF0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF0, 0xE0, 0xE0, 0x80, 0x80, 0xC0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFB, 0xF9, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xFE, 0x7E, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x1F, 0x1F, 0x1F, 0x07, 0x03,
		0x00, 0xC0, 0xE0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF8, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x01, 0x03, 0x0F, 0x1F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x1F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0F, 0x1F, 0x1F, 0x3F, 0x7F, 0x7F, 0x3F, 0x1F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	};
	static const IMAGE_OLED avr_struct = {500, 125, 0x03};
	
	static const unsigned char PROGMEM sputnik_logo[512] = {
		//                           ##
		//                          ####
		//                         ### ##
		//                        ###   ##
		//                       ### #   ##
		//                      ###   #   ##
		//                     ####    # ##
		//            #        ##  #    ##
		//          ########   #    #  ##
		//          ## ##  ##  ##    ###
		//         ## ##  # ## ###   ##
		//          ###  #   ###### ##
		//          ##  #     #######
		//          #  #       ##
		//          ###         ##
		//          ###         ###
		//            ##       ## #
		//            ###     ## ##
		//        ########   ## ###
		//       ########## ## ##########
		//      ###  #### ### #####    ##
		//     ####   ###  #######     #
		//    ##   #   ##       #    ##
		//   ###    #  #        #   ##
		//  ## ##    ###        #   ## # # #
		// ##   ##   ##         # ##  ## # #
		//  ##   ## ##          ###  ## ## #
		//   ##   ###           ##     ##  #
		//    ##  ##                 ##   #
		//     ####                     ##
		//      ##                   ###
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x70, 0x78, 0x9C, 0x0E, 0x17, 0x23, 0x46, 0x8C, 0xD8, 0x70, 0x20,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xFF, 0xDB, 0xCD, 0x27, 0x13, 0x09, 0x05, 0x03, 0x06, 0x0C, 0x18, 0x3F, 0xFE, 0xDC, 0x98, 0x10, 0x19, 0x0E, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x80, 0xC0, 0xE0, 0x30, 0x38, 0x3C, 0x4C, 0x8C, 0x1C, 0x3F, 0xFF, 0x7E, 0x0C, 0x18, 0x30, 0x38, 0x2C, 0x36, 0x3B, 0xFD, 0x3E, 0x1F, 0x08, 0x88, 0xC8, 0x48, 0x38, 0x18, 0x00, 0x00, 0x00,
		0x02, 0x07, 0x0D, 0x18, 0x31, 0x63, 0x66, 0x3C, 0x18, 0x0C, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0C, 0x06, 0x02, 0x01, 0x55, 0x56, 0x4B, 0x2C, 0x27, 0x10, 0x0F,
	};
	static const IMAGE_OLED sputnik_struct = {132, 33, 0x03};
	
	static const unsigned char PROGMEM zero_logo[512] = {
			// @0 '0' (18 pixels wide)
			//     ######  ##
			//   ########  ####
			//  #########  #####
			//  #########  #####
			// ##########  ######
			// ##########  ######
			// ########    ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// #######     ######
			// ########    ######
			// ##########  ######
			// ##########  ######
			// ##########  ######
			//  #########  #####
			//   ########  ####
			0x01, 0x01, 0x01, 0x01, 0xF0, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x3F, 0x00, 0x00, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xF0, 0x01, 0x01, 0x01, 0xFF,
			0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF,
			0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF,
			0x01, 0x01, 0x01, 0x01, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7E, 0x7C, 0x7C, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x1F, 0x01, 0x01, 0x01, 0xFF
		};

	static const unsigned char PROGMEM one_logo[512] ={
			// @0 '1' (12 pixels wide)
			//       ######
			//       ######
			//       ######
			//      #######
			//     ########
			//   ##########
			// ############
			// ############
			// ############
			// ############
			// ############
			// ############
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			//       ######
			0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xC0, 0xC0, 0xE0, 0xE0, 0xF0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,
			0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,
			0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,
			0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,
		};
		
	static const unsigned char PROGMEM two_logo[512] = {
		// @0 '2' (20 pixels wide)
		//     #############
		//   ################
		//  ##################
		// ###################
		// ###################
		// #########  ########
		// ########     ######
		// #######      ######
		// ###          ######
		//              ######
		//              ######
		//              ######
		//              ######
		//              ######
		//              #####
		//              ####
		//          ##  ####
		//         ###  ###
		//        ####  ##
		//       #####
		//      ######
		//     #######
		//    ########
		//   #########
		//  ##########
		//  ###################
		//  ###################
		//  ###################
		//  ###################
		//  ###################
		//  ###################
		0x01, 0x01, 0x01, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x1F, 0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0x00, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x00, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x01, 0x01, 0xFF
	};

	static const unsigned char PROGMEM thee_logo[512] =
	{
		// @0 '3' (18 pixels wide)
		// ##########  ######
		// ##########  ######
		// ##########  ######
		// ##########  ######
		// ##########  ######
		// ##########  ######
		//             ######
		//            #######
		//           ########
		//          ########
		//         ########
		//        ########
		//       #########
		//       #########
		//       ###########
		//       ############
		//       ############
		//       ############
		//           ########
		//            #######
		//             ######
		//             ######
		//             ######
		//  ######     ######
		//  ######     ######
		//  ########   ######
		//  #########  ######
		//  #########  ######
		//   ########  ######
		//   ########  #####
		//     ######  ###
		0x01, 0x01, 0x01, 0x01, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0xC3, 0x81, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x01, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x83, 0x03, 0x03, 0x03, 0x07, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x01, 0x00, 0x0F, 0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x7E, 0x7E, 0x7C, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x3F, 0x3F, 0x1F, 0x01, 0x01, 0x01, 0xFF
	};

	static const unsigned char PROGMEM four_logo[512] =
	{
		// @0 '4' (22 pixels wide)
		//             #######
		//             #######
		//        ##   #######
		//        ##   #######
		//       ###   #######
		//       ###   #######
		//      ####   #######
		//      ####   #######
		//     #####   #######
		//     #####   #######
		//    ######   #######
		//    ######   #######
		//   #######   #######
		//   #######   #######
		//  ########   #######
		//  #######    #######
		// ########    #######
		// ########    #######
		// #######     #######
		// #########   ##########
		// #########   ##########
		// #########   ##########
		// #########   ##########
		// #########   ##########
		// #########   ##########
		//             #######
		//             #######
		//             #######
		//             #######
		//             #######
		//             #######
		0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0xFF,
		0x01, 0x01, 0x00, 0xC0, 0xF0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0xFF,
		0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xF8, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF8, 0xF8, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x01, 0x01, 0x01, 0x01, 0xFF
	};
	
	static const unsigned char PROGMEM five_logo[512] =
	{
		// @0 '5' (18 pixels wide)
		// ##################
		// ##################
		// ##################
		// ##################
		// ##################
		// #######
		// #######
		// #######
		// #######
		// #######
		// #######
		// #######
		// #######
		// ####### #######
		// ####### #########
		// ####### #########
		// ####### ##########
		// ####### ##########
		//          #########
		//            #######
		//            #######
		//             ######
		// ######      ######
		// ######     #######
		// ######     #######
		// ######   #########
		// ######  ##########
		// ######  ##########
		//  #####  ##########
		//   ####  #########
		//    ###  #######
		0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0x00, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x01, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0x03, 0x00, 0x03, 0x07, 0x07, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x01, 0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F, 0x00, 0x00, 0x7C, 0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x3F, 0x1F, 0x01, 0x01, 0x01, 0xFF
	};
	
	static const unsigned char PROGMEM six_logo[512] =
	{
		// @72 '6' (19 pixels wide)
		//      ##  ######
		//    ####  ########
		//   #####  #########
		//  ######  #########
		// #######  ##########
		// #######  ##########
		// #######     #######
		// #######     #######
		// #######      ######
		// #######
		// #######
		// #######
		// #######
		// #######  ########
		// #######  #########
		// #######  ##########
		// #######  ##########
		// #######  ##########
		// #######    ########
		// #######     #######
		// #######     #######
		// #######     #######
		// #######     #######
		// #######     #######
		// #######    ########
		// #######   #########
		// #######  ##########
		//  ######  ##########
		//  ######  ##########
		//   #####  #########
		//    ####  #######
		0x01, 0x01, 0x01, 0xF0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xF0, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0xE1, 0xE1, 0xE1, 0xE1, 0xC1, 0x81, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x03, 0x03, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x07, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F, 0x7F, 0x00, 0x00, 0x7C, 0x7E, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x3F, 0x1F, 0x01, 0x01, 0x01, 0xFF
	};
	
	static const unsigned char PROGMEM seven_logo[512] =
	{
		// @148 '7' (20 pixels wide)
		// ####################
		// ####################
		// ####################
		// ####################
		// ####################
		// ####################
		//             ########
		//             #######
		//             #######
		//             #######
		//            ########
		//            #######
		//            #######
		//            #######
		//           ########
		//           #######
		//           #######
		//           #######
		//          ########
		//          #######
		//          #######
		//          #######
		//         ########
		//         ########
		//         #######
		//         #######
		//        ########
		//        ########
		//        #######
		//        #######
		//        #######
		0x01, 0x01, 0x01, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x07, 0x00, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0xFF
	};
	
	static const unsigned char PROGMEM eitht_logo[512] =
	{
		// @228 '8' (20 pixels wide)
		//     ######   ##
		//   ########   #####
		//  #########   ######
		// ##########   ######
		// ##########   ######
		// ##########   #######
		// #########    #######
		// ########     #######
		// #######      #######
		// #######      #######
		// #######      #######
		// ########     ######
		// #########    ######
		//  #########   ######
		//   ########   #####
		//    #######   ####
		//   ########   ####
		//  #########   #####
		// ##########   ######
		// ########     ######
		// #######      #######
		// #######      #######
		// #######      #######
		// #######      #######
		// ########     #######
		// ##########   #######
		// ##########   #######
		// ##########   ######
		//  #########   ######
		//  #########   #####
		//    #######   ####
		0x01, 0x01, 0x01, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFC, 0xE0, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x07, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x07, 0x07, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF0, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x0F, 0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7E, 0x7E, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x1F, 0x07, 0x01, 0x01, 0xFF
	};
	
	static const unsigned char PROGMEM nine_logo[512] =
	{
		// @308 '9' (19 pixels wide)
		//     ######  ###
		//   ########  #####
		//  #########  ######
		// ##########  #######
		// ##########  #######
		// ##########  #######
		// ########    #######
		// #######     #######
		// #######     #######
		// #######     #######
		// #######     #######
		// #######     #######
		// ########    #######
		// ##########  #######
		// ##########  #######
		//  #########  #######
		//  #########  #######
		//   ########  #######
		//     ######  #######
		//             #######
		//             #######
		//             #######
		//             #######
		// #######     #######
		// #######     #######
		// #########   #######
		//  #########  #######
		//  #########  #######
		//  #########  ######
		//   ########  #####
		//     ######  ###
		0x01, 0x01, 0x01, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x3F, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xF8, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xE0, 0xE0, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x80, 0x81, 0x83, 0x83, 0x87, 0x87, 0x87, 0x07, 0x07, 0x07, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF,
		0x01, 0x01, 0x01, 0x03, 0x1F, 0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x7E, 0x7E, 0x7C, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x3F, 0x3F, 0x1F, 0x0F, 0x01, 0x01, 0x01, 0xFF
	};
	
	static const unsigned char PROGMEM colon_logo[512] =
	{
		// @384 ':' (5 pixels wide)
		//
		//
		//
		//
		//
		//
		//
		//
		//
		// #####
		// #####
		// #####
		// #####
		//
		//
		//
		//
		//
		//
		//
		//
		//
		//
		//
		//
		//
		//
		// #####
		// #####
		// #####
		//  ####
		0x00, 0x00, 0x00, 0x00, 0x00,
		0x1E, 0x1E, 0x1E, 0x1E, 0x1E,
		0x00, 0x00, 0x00, 0x00, 0x00,
		0x38, 0x78, 0x78, 0x78, 0x78,
	};
	static const IMAGE_OLED colon_struct = {20, 5, 0x03}; 

#endif