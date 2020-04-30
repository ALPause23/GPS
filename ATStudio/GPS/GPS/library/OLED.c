#include "OLED.h"

uint8_t oled_pointer;

void SetPointer(uint8_t a)
{
	oled_pointer = a;
}
uint8_t GetPointer()
{
	return oled_pointer;
}

void InitOLED()
{
	
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
	oled_pointer = 0x00;
	

}

void SetPointOLED(uint8_t Start_Collumn, uint8_t End_Collumn, uint8_t Start_Page, uint8_t End_Page)
{
	i2cstart(SSD1306_ADDR);
	i2cwrite(CODE_COMMAND);
	i2cwrite(SSD1306_COLUMNADDR);
	i2cwrite(Start_Collumn);
	i2cwrite(End_Collumn);
	i2cstop();
	i2cstart(SSD1306_ADDR);
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

void SSD1306_fast_command(uint8_t command)
{
	
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
	oled_pointer = 0x00;
}

void SelectDisplay(int i)
{
	switch(i)
	{
		case 2:
		{
			PORTB |= (PortB0 | PortB1);
			break; 
		}
		case 0:
		{
			PORTB |= (PortB0);
			PORTB &= ~(PortB1);
			break;
		}
		case 1:
		{
			PORTB |= (PortB1);
			PORTB &= ~(PortB0);
			break;
		}
	}
}

void Set_OLED_Image(IMAGE_OLED a, unsigned char *b)
{
	//OLED_Command(SSD1306_DISPLAYOFF);
	SetPointOLED(oled_pointer, oled_pointer + a.long_image - 1, 0x04, (0x04 + a.height_image));
	i2cstart(SSD1306_ADDR);
	i2cwrite(CODE_DATA);
	for(long int kk = 0; kk < a.array_size; kk++)
	{
		i2cwrite(pgm_read_byte(&(b[kk])));	//LSB вверху, MSB снизу
	}
	i2cstop();
}

void Set_OLED_Num(unsigned char *a)
{
	SetPointOLED(oled_pointer, (oled_pointer + 0x19), 0x04, 0x07);
	i2cstart(SSD1306_ADDR);
	i2cwrite(CODE_DATA);
	for(int kk = 0; kk < 104; kk++)
	{
		i2cwrite(pgm_read_byte(&(a[kk])));	//LSB вверху, MSB снизу
	}
	i2cstop();
}

uint8_t* GetNum(int i)
{
	switch(i)
	{
		case 0:
		{
			return zero_logo;
			break;
		}
		case 1:
		{
			return one_logo;
			break;
		}
		case 2:
		{
			return two_logo;
			break;
		}
		case 3:
		{ 
			return thee_logo;
			break;
		}
		case 4:
		{
			return four_logo;
			break;
		}
		case 5:
		{
			return five_logo;
			break;
		}
		case 6:
		{
			return six_logo;
			break;
		}
		case 7:
		{
			return seven_logo;
			break;
		}
		case 8:
		{
			return eitht_logo;
			break;
		}
		case 9:
		{
			return nine_logo;
			break;
		}
	}
}
