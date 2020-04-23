﻿#include "OLED.h"

uint8_t oled_pointer = 0x00;

void InitOLED()
{
	TWBR = TWBR_VALUE;
	TWSR = 0;
	i2cstart(SSD1306_ADDR);
	i2cwrite(0x00);
	
	i2cwrite(SSD1306_DISPLAYOFF);                    // 0xAE
	i2cwrite(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
	i2cwrite(0x80);                                  // the suggested ratio 0x80

	i2cwrite(SSD1306_SETMULTIPLEX);                  // 0xA8
	i2cwrite(SSD1306_LCDHEIGHT - 1);

	i2cwrite(SSD1306_SETDISPLAYOFFSET);              // 0xD3
	i2cwrite(0x0);                                   // no offset
	i2cwrite(SSD1306_SETSTARTLINE | 0x0);            // line #0
	i2cwrite(SSD1306_CHARGEPUMP);                    // 0x8D
	if (0x2 == SSD1306_EXTERNALVCC)
	{
		i2cwrite(0x10);
	}
	else
	{
		i2cwrite(0x14);
	}
	i2cwrite(0x20);             					   // 0x20  SSD1306_MEMORYMODE
	i2cwrite(0x00);                       	       // 0x0 act like ks0108
	i2cwrite(SSD1306_SEGREMAP | 0x1);
	i2cwrite(SSD1306_COMSCANDEC);
	
	i2cwrite(SSD1306_SETCOMPINS);                    // 0xDA
	i2cwrite(0x02);
	i2cwrite(SSD1306_SETCONTRAST);                   // 0x81
	i2cwrite(0x8F);
	
	i2cwrite(SSD1306_SETPRECHARGE);                  // 0xd9
	if (0x2 == SSD1306_EXTERNALVCC)
	{
		i2cwrite(0x22);
	}
	else
	{
		i2cwrite(0xF1);
	}
	i2cwrite(SSD1306_SETVCOMDETECT);                 // 0xDB
	i2cwrite(0x40);
	i2cwrite(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
	i2cwrite(SSD1306_NORMALDISPLAY);                 // 0xA6

	i2cwrite(SSD1306_DEACTIVATE_SCROLL);

	i2cwrite(SSD1306_DISPLAYON);//--turn on oled panel
	i2cstop();
}
void SetPointOLED(uint8_t Start_Collumn, uint8_t End_Collumn, uint8_t Start_Page, uint8_t End_Page)
{
	i2cstart(SSD1306_ADDR);
	i2cwrite(CODE_COMMAND);
	i2cwrite(SSD1306_COLUMNADDR);
	i2cwrite(Start_Collumn);
	i2cwrite(End_Collumn);
	
	i2cwrite(CODE_COMMAND);
	i2cwrite(SSD1306_PAGEADDR);
	i2cwrite(Start_Page);
	i2cwrite(End_Page);
	i2cstop();
}
void OLED_Command(uint8_t data)
{
	i2cstart(SSD1306_ADDR);
	i2cwrite(CODE_COMMAND);      // Co = 0, D/C = 0
	i2cwrite(data);
	i2cstop();
}
void ClearOLED()
{
	SetPointOLED(0x00, 0x7F, 0x04, 0x07);
	
	i2cstart(SSD1306_ADDR);
	i2cwrite(CODE_DATA);
	
	for(int kk = 0; kk < 4; kk++)
	{
		for(int k = 0; k < 128; k++)
		{
			i2cwrite(0x00);	//LSB вверху, MSB снизу
		}
	}
	i2cstop();
}

void SetOLED(void)
{
	oled_pointer = 0x00;
	OLED_Command(SSD1306_DISPLAYOFF);
	SetPointOLED(0x00, oled_pointer += serp_logo.long_image, 0x04, (0x04 + serp_logo.height_image));

	i2cstart(SSD1306_ADDR);
	i2cwrite(CODE_DATA);
	for(int kk = 0; kk < serp_logo.long_array; kk++)
	{
		i2cwrite(serp_logo.serp[kk]);	//LSB вверху, MSB снизу
	}
	i2cstop();
	OLED_Command(SSD1306_DISPLAYON);
	
	//_delay_ms(1000);
	//OLED_Command(SSD1306_DISPLAYOFF);
	SetPointOLED(0x2a, 0x2a+bsuir_logo.long_image, 0x04, 0x04 + bsuir_logo.height_image);
	i2cstart(SSD1306_ADDR);
	i2cwrite(CODE_DATA);
	for(int kk = 0; kk < bsuir_logo.long_array; kk++)
	{
		i2cwrite(bsuir_logo.bsuir[kk]);
	}
	i2cstop();
	
	//OLED_Command(SSD1306_DISPLAYOFF);
	//i2cstart(SSD1306_ADDR);
	//i2cwrite(0x00);
	//i2cwrite(SSD1306_COLUMNADDR);
	//i2cwrite(0x2A);
	//i2cwrite(0x66);
	//i2cstop();
	//
	//i2cstart(SSD1306_ADDR);
	//i2cwrite(0x00);
	//i2cwrite(SSD1306_PAGEADDR);
	//i2cwrite(0x04);
	//i2cwrite(0x07);
	//i2cstop();
	//
	//OLED_Command(SSD1306_COLUMNADDR);
	//OLED_Command(0x00);
	//OLED_Command(0x6);
	//
	//
	//OLED_Command(SSD1306_PAGEADDR);
	//OLED_Command(0x04);
	//OLED_Command(0x07);
	//
	//i2cstart(SSD1306_ADDR);
	//i2cwrite(0x40);
	//for(int kk = 0; kk < 255; kk++)
	//{
	//i2cwrite(BGUIRlogo[kk]);	//LSB вверху, MSB снизу
	//}
	//i2cstop();
	//OLED_Command(SSD1306_DISPLAYON);
	//
	////_delay_ms(1000);
	//
	//ClearOLED();
	////_delay_ms(100);
	//
	//OLED_Command(SSD1306_DISPLAYOFF);
	//i2cstart(SSD1306_ADDR);
	//i2cwrite(0x00);
	//i2cwrite(SSD1306_COLUMNADDR);
	//i2cwrite(0x00);
	//i2cwrite(0x55);
	//i2cstop();
	//
	//i2cstart(SSD1306_ADDR);
	//i2cwrite(0x00);
	//i2cwrite(SSD1306_PAGEADDR);
	//i2cwrite(0x04);
	//i2cwrite(0x07);
	//i2cstop();
	//
	//OLED_Command(SSD1306_COLUMNADDR);
	//OLED_Command(0x00);
	//OLED_Command(0x7F);
	//
	//
	//OLED_Command(SSD1306_PAGEADDR);
	//OLED_Command(0x04);
	//OLED_Command(0x07);
	//
	//OLED_Command(SSD1306_DISPLAYON);
	//i2cstart(SSD1306_ADDR);
	//i2cwrite(0x40);
	//for(uint16_t kk = 0; kk < 512; kk++)
	//{
	//
	//i2cwrite(AVRlogo[kk]);	//LSB вверху, MSB снизу
	//}
	//i2cstop();
	
}
