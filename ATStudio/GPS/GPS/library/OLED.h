﻿#ifndef __OLED_H__
	#define __OLED_H__
	#include "I2C.h"
	
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

	#define SSD1306_ADDR   0x78
	
	unsigned char ONE[8] =
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
	unsigned char TWO[8] =
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
	unsigned char THREE[8] =
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
	unsigned char FOUR[8] =
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
	unsigned char FIVE[8] =
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
	unsigned char SIX[8] =
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
	unsigned char SEVEN[8] =
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
	unsigned char EITHT[8] =
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
	unsigned char NINE[8] =
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
	unsigned char ZERO[8] =
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

	unsigned char Z[8] =
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
	unsigned char Y[8] =
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
	unsigned char X[8] =
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

	uint8_t serp [128] =
	{
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
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF8, 0xF8, 0xF8, 0xFC, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x1F, 0x1F, 0x07, 0x01, 0x00,
	};


	const uint8_t BGUIRlogo [256]=
	{
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
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0x78, 0x38, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x01, 0x83, 0xC7, 0xFE, 0x78, 0x03, 0x83, 0xFE, 0xFE, 0x79, 0x03, 0x83, 0xFE, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0xE0, 0xE0, 0x70, 0x78, 0x3C, 0x9E, 0xCF, 0xCF, 0xC3, 0x01, 0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x02, 0x03, 0x83, 0x81, 0xC0, 0xC2, 0xC3, 0xC1, 0xC1, 0x80, 0x03, 0x03, 0x01, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0x78, 0x3C, 0x1E, 0x0F, 0x07, 0x07, 0x03, 0x09, 0x1C, 0x0E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x3F, 0x1F, 0x0F, 0x87, 0xC3, 0x1C, 0x0E, 0x07, 0x03, 0x7F, 0x3F, 0x3F, 0x1F, 0x8F, 0xC7, 0xE3, 0x0E, 0x0E, 0x07, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
		0x3C, 0x1E, 0x0F, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x38, 0x38, 0x1C, 0x0E, 0x07, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0x38, 0x1C, 0x0E, 0x0F, 0x78, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0x3C, 0x1C, 0x08, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x38, 0x1C, 0x08,
	};


	const uint8_t AVRlogo [512]=



	{
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
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x03, 0x01, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC, 0xF8, 0xF0, 0xE0, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x87, 0x81, 0x81, 0x80, 0x81, 0x87, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF8, 0xF0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF0, 0xE0, 0xE0, 0x80, 0x80, 0xC0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFB, 0xF9, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xFE, 0x7E, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x1F, 0x1F, 0x1F, 0x07, 0x03, 0x00, 0x00, 0x00,
		0x00, 0xC0, 0xE0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF8, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x01, 0x03, 0x0F, 0x1F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x1F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0F, 0x1F, 0x1F, 0x3F, 0x7F, 0x7F, 0x3F, 0x1F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	};

	// Bitmap sizes for aVRlogo
	//const uint_8 aVRlogoWidthPages = 16;
	//const uint_8 aVRlogoHeightPixels = 31;



	const uint8_t X1[128] =
	{
		// ###########         ###########
		//  ##########         ##########
		//  ###########       ###########
		//   ##########      ###########
		//    ##########     ##########
		//    ###########   ###########
		//     ##########   ##########
		//      ########## ##########
		//       ###################
		//        #################
		//        ################
		//         ###############
		//          #############
		//          ############
		//           ###########
		//            #########
		//           ###########
		//          #############
		//          #############
		//         ###############
		//        #################
		//       ###################
		//       ###################
		//      ########## ##########
		//     ##########   ##########
		//    ##########    ###########
		//   ###########     ###########
		//   ##########       ##########
		//  ##########        ###########
		// ###########         ###########
		// ##########           ##########
		// ##########           ##########
		0x01, 0x07, 0x0F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF0, 0xE0, 0x80, 0x00, 0x80, 0xE0, 0xF8, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x0F, 0x07, 0x01,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x0F, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xF0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xE0, 0xF0, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF0, 0xE0,
	};
	
#endif