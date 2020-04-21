#include "OLED.h"

void InitOLED()
{
	TWBR = TWBR_VALUE;
	TWSR = 0;
	i2cstart(I2CADDR);
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

void OLED_Command(uint8_t data)
{
	i2cstart(I2CADDR);
	i2cwrite(0x00);      // Co = 0, D/C = 0
	i2cwrite(data);
	i2cstop();
}
void ClearOLED()
{
	i2cstart(I2CADDR);
	i2cwrite(0x00);
	i2cwrite(SSD1306_COLUMNADDR);
	i2cwrite(0x00);
	i2cwrite(0x7F);
	i2cstop();
	
	i2cstart(I2CADDR);
	i2cwrite(0x00);
	i2cwrite(SSD1306_PAGEADDR);
	i2cwrite(0x04);
	i2cwrite(0x07);
	i2cstop();
	i2cstart(I2CADDR);

	i2cwrite(0x40);
	
	for(int kk = 0; kk < 4; kk++)
	{
		for(int k = 0; k < 128; k++)
		i2cwrite(0x00);	//LSB вверху, MSB снизу
	}
	i2cstop();
}