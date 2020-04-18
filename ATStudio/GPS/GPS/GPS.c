/*
 * GPS.c
 *
 * Created: 06.04.2020 15:09:55
 *  Author: Evgeni
 */ 

#include "main.h"


uint16_t i;
uint8_t a,b;

uint8_t twi_status_register;
void ssd1306_command(uint8_t data);

uint8_t i2cstart(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));

	twi_status_register = TW_STATUS & 0xF8;
	if ((twi_status_register != TW_START) && (twi_status_register != TW_REP_START))
	return 1;

	TWDR = I2CADDR;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)));

	twi_status_register = TW_STATUS & 0xF8;
	if ((twi_status_register != TW_MT_SLA_ACK) && (twi_status_register != TW_MR_SLA_ACK))
	{
		return 1;
	}

	return 0;
}

uint8_t i2cwrite(uint8_t data)
{
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)));

	twi_status_register = TW_STATUS & 0xF8;
	if (twi_status_register != TW_MT_DATA_ACK)
	return 1;
	else
	return 0;
}

void i2cstop(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	while(TWCR & (1<<TWSTO));
}


void InitLed()
{
	while(i < 4){
	// инициализация дисплея
	PORTB &= ~(1<<PORTB4);
	SPDR = 0x0F;
	while(!(SPSR & (1<<SPIF)));
	//PORTB |= (1<<PORTB4); //высокий уровень
	//_delay_ms(50);

	//PORTB &= ~(1<<PORTB4); //низкий уровень
	SPDR = 0x00;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= (1<<PORTB4);


	PORTB &= ~(1<<PORTB4);
	SPDR = 0x0C;
	while(!(SPSR & (1<<SPIF)));
	//PORTB |= (1<<PORTB4); //высокий уровень
	//_delay_ms(50);

	//PORTB &= ~(1<<PORTB4); //низкий уровень
	SPDR = 0x01;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= (1<<PORTB4);


	PORTB &= ~(1<<PORTB4);
	SPDR = 0x0A;
	while(!(SPSR & (1<<SPIF)));
	//PORTB |= (1<<PORTB4); //высокий уровень
	//_delay_ms(50);

	//PORTB &= ~(1<<PORTB4); //низкий уровень
	SPDR = 0x0F;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= (1<<PORTB4);


	PORTB &= ~(1<<PORTB4);
	SPDR = 0x0B;
	while(!(SPSR & (1<<SPIF)));
	//PORTB |= (1<<PORTB4); //высокий уровень
	//_delay_ms(50);

	//PORTB &= ~(1<<PORTB4); //низкий уровень
	SPDR = 0x07;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= (1<<PORTB4);


	PORTB &= ~(1<<PORTB4);
	SPDR = 0x09;
	while(!(SPSR & (1<<SPIF)));
	//PORTB |= (1<<PORTB4); //высокий уровень
	//_delay_ms(50);

	//PORTB &= ~(1<<PORTB4); //низкий уровень
	SPDR = 0x00;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= (1<<PORTB4);
	
	i++;
	}
}

void SPI_WriteStartByte(char data)
{
	PORTB &= ~(1<<PORTB4);
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

void SPI_WriteEndByte(char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= (1<<PORTB4);
}

void SPI_WriteByte(char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

void SendLed(char adr, char data)
{
	SPI_WriteStartByte(adr);
	_delay_ms(10);
	SPI_WriteEndByte(data);
	_delay_ms(10);
}

void ClearDisplay()
{
	int i = 0;
    while(i <= 3)
    {
		for(char j = 1; j <= 8; j++)
		{
			SendLed(j,0);
		}
	    i++;
	    _delay_ms(1);
    }
}
	
void InitI2C()
{
	//int i = 0;
	TWBR = TWBR_VALUE;
	TWSR = 0;
	//while(1)
	//{
		//ssd1306_command(init[i]);
		//i++;
	//
	ssd1306_command(SSD1306_DISPLAYOFF);                    // 0xAE
	ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
	ssd1306_command(0x80);                                  // the suggested ratio 0x80

	ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
	ssd1306_command(SSD1306_LCDHEIGHT - 1);

	ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
	ssd1306_command(0x0);                                   // no offset
	ssd1306_command(SSD1306_SETSTARTLINE | 0x0);            // line #0
	ssd1306_command(SSD1306_CHARGEPUMP);                    // 0x8D
	if (0x2 == SSD1306_EXTERNALVCC)
	{ ssd1306_command(0x10); }
	else
	{ ssd1306_command(0x14); }
	ssd1306_command(0x20);                    // 0x20  SSD1306_MEMORYMODE
	ssd1306_command(0x00);                                  // 0x0 act like ks0108
	ssd1306_command(SSD1306_SEGREMAP | 0x1);
	ssd1306_command(SSD1306_COMSCANDEC);

	
		ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
		ssd1306_command(0x02);
		ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
		ssd1306_command(0x8F);
	
	
	ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
	if (0x2 == SSD1306_EXTERNALVCC)
	{ ssd1306_command(0x22); }
	else
	{ ssd1306_command(0xF1); }
	ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
	ssd1306_command(0x40);
	ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
	ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6

	ssd1306_command(SSD1306_DEACTIVATE_SCROLL);

	ssd1306_command(SSD1306_DISPLAYON);//--turn on oled panel
	//if(i == 18) return;
	//}
}	

void ssd1306_command(uint8_t data)
{
	i2cstart();
	i2cwrite(0x00);      // Co = 0, D/C = 0
	i2cwrite(data);
	i2cstop();
	
	//// START bit
	//TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	//while(!(TWCR & (1<<TWINT)));
	//
	//twi_status_register = TW_STATUS & 0xF8;
	//if ((twi_status_register != TW_START) && (twi_status_register != TW_REP_START))
	//return;
	//
	//
	//TWDR = 0x00;
	//TWCR = (1<<TWINT) | (1<<TWEN);
	//while(!(TWCR & (1<<TWINT)));
	//
	//TWDR = data;
	//TWCR = (1<<TWINT) | (1<<TWEN);
	//while(!(TWCR & (1<<TWINT)));
	//twi_status_register = TW_STATUS & 0xF8;
	//if (twi_status_register != TW_MT_DATA_ACK)
	//return;
	//
///*Stop bit*/
	//TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	//while(TWCR & (1<<TWSTO));
}
void ClearOLED()
{
	i2cstart();
	i2cwrite(0x00);
	i2cwrite(SSD1306_COLUMNADDR);
	i2cwrite(0x00);
	i2cwrite(0x7F);
	i2cstop();
	
	i2cstart();
	i2cwrite(0x00);
	i2cwrite(SSD1306_PAGEADDR);
	i2cwrite(0x04);
	i2cwrite(0x07);
	i2cstop();
	i2cstart();
	//i2cwrite(0b10000000);
	//i2cwrite(0x20);
	//i2cwrite(0b10000000);
	//i2cwrite(0x00);
	i2cwrite(0x40);
	
	for(int kk = 0; kk < 4; kk++)
	{
		for(int k = 0; k < 128; k++)
			i2cwrite(0x00);	//LSB вверху, MSB снизу
	}
	i2cstop();
}

void WriteNum(char *x, char *y, char *z)
{
	
	for(int i = 0; i < 8; i++)
	{
		PORTB &= ~(1 << PORTB4);
		
		SPI_WriteByte(i + 1);
		SPI_WriteByte(z[i]);
		
		SPI_WriteByte(i + 1);
		SPI_WriteByte(y[i]);
		
		SPI_WriteByte(i + 1);
		SPI_WriteByte(x[i]);
		
		PORTB |= (1<<PORTB4);
	}
	
}

void SetOLED(void)
{
	ssd1306_command(SSD1306_DISPLAYOFF);
	i2cstart();
	i2cwrite(0x00);
	i2cwrite(SSD1306_COLUMNADDR);
	i2cwrite(0x00);
	i2cwrite(0x1F);
	i2cstop();
	
	i2cstart();
	i2cwrite(0x00);
	i2cwrite(SSD1306_PAGEADDR);
	i2cwrite(0x04);
	i2cwrite(0x07);
	i2cstop();
	
	//ssd1306_command(SSD1306_COLUMNADDR);
	//ssd1306_command(0x00);	
	//ssd1306_command(0x6);
//
//
	//ssd1306_command(SSD1306_PAGEADDR);
	//ssd1306_command(0x04);
	//ssd1306_command(0x07);
	_delay_ms(100);
	i2cstart();
	i2cwrite(0x40);
	for(int kk = 0; kk < 128; kk++)
	{
		i2cwrite(serp[kk]);	//LSB вверху, MSB снизу
	}
	i2cstop();
	ssd1306_command(SSD1306_DISPLAYON);
	//i2cstart();
	//i2cwrite(0x00);
	//i2cwrite(SSD1306_COLUMNADDR);
	//i2cwrite(0x00);
	//i2cwrite(0x07);
	//i2cstop();
	//for(int kk = 0; kk < 8; kk++)
	//{
		//i2cwrite(Y1[kk]);	//LSB вверху, MSB снизу
	//}
	//for(int kk = 0; kk < 8; kk++)
	//{
		//i2cwrite(Z1[kk]);	//LSB вверху, MSB снизу
	//}
	//
	//i2cstop();
	ssd1306_command(SSD1306_DISPLAYOFF);
	i2cstart();
	i2cwrite(0x00);
	i2cwrite(SSD1306_COLUMNADDR);
	i2cwrite(0x2A);
	i2cwrite(0x66);
	i2cstop();
	
	//i2cstart();
	//i2cwrite(0x00);
	//i2cwrite(SSD1306_PAGEADDR);
	//i2cwrite(0x04);
	//i2cwrite(0x07);
	//i2cstop();
	
	//ssd1306_command(SSD1306_COLUMNADDR);
	//ssd1306_command(0x00);
	//ssd1306_command(0x6);
	//
	//
	//ssd1306_command(SSD1306_PAGEADDR);
	//ssd1306_command(0x04);
	//ssd1306_command(0x07);
	
	i2cstart();
	i2cwrite(0x40);
	for(int kk = 0; kk < 255; kk++)
	{
		i2cwrite(BGUIRlogo[kk]);	//LSB вверху, MSB снизу
	}
	i2cstop();
	ssd1306_command(SSD1306_DISPLAYON);
	
	_delay_ms(1000);
	
	ClearOLED();
	_delay_ms(100);
	
	ssd1306_command(SSD1306_DISPLAYOFF);
	i2cstart();
	i2cwrite(0x00);
	i2cwrite(SSD1306_COLUMNADDR);
	i2cwrite(0x00);
	i2cwrite(0x55);
	i2cstop();
	
	i2cstart();
	i2cwrite(0x00);
	i2cwrite(SSD1306_PAGEADDR);
	i2cwrite(0x04);
	i2cwrite(0x07);
	i2cstop();
	
	//ssd1306_command(SSD1306_COLUMNADDR);
	//ssd1306_command(0x00);
	//ssd1306_command(0x6);
	//
	//
	//ssd1306_command(SSD1306_PAGEADDR);
	//ssd1306_command(0x04);
	//ssd1306_command(0x07);
	_delay_ms(100);
	i2cstart();
	i2cwrite(0x40);
	for(long int kk = 0; kk < 319; kk++)
	{
		i2cwrite(AVRlogo[kk]);	//LSB вверху, MSB снизу
	}
	i2cstop();
	ssd1306_command(SSD1306_DISPLAYON);
}

int main(void)
{
	DDRB |= ((1<<PORTB0)|(1<<PORTB3)|(1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //ножки SPI на выход
	
	PORTB &= ~((1<<PORTB0)|(1<<PORTB3)|(1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //низкий уровень
	
	
	SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
	SPSR=(0<<SPI2X);
	
	InitLed();
	//InitI2C();
	ClearDisplay();

	WriteNum(THREE, TWO,ONE );
	_delay_ms(100);
	WriteNum(SIX, FIVE, FOUR);
	_delay_ms(100);
	WriteNum(NINE, EITHT, SEVEN);
	_delay_ms(100);
	WriteNum(Z, Y, X);
	
	InitI2C();
	PORTB |= (1<<PORTB3);
	_delay_ms(100);
	PORTB &= ~(1<<PORTB3);
	ClearOLED();
	SetOLED();
		
	while(1)
	{
		
	}
	return 0;	
}