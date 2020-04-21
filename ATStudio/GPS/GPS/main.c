#include "main.h"


uint16_t i;
uint8_t a,b;
;

void ssd1306_command(uint8_t data);




void InitLed()
{
	while(i < 3){
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
	//_delay_ms(100);
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
	
	//_delay_ms(1000);
	
	ClearOLED();
	//_delay_ms(100);
	
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
	
	ssd1306_command(SSD1306_COLUMNADDR);
	ssd1306_command(0x00);
	ssd1306_command(0x7F);
	
	
	ssd1306_command(SSD1306_PAGEADDR);
	ssd1306_command(0x04);
	ssd1306_command(0x07);
	
	ssd1306_command(SSD1306_DISPLAYON);
	i2cstart();
	i2cwrite(0x40);
	for(uint16_t kk = 0; kk < 512; kk++)
	{
		
	i2cwrite(AVRlogo[kk]);	//LSB вверху, MSB снизу
	}
	i2cstop();
	
}

int main(void)
{
	DDRB |= ((1<<PORTB0)|(1<<PORTB3)|(1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //ножки SPI на выход
	
	PORTB |= ((1<<PORTB0)|(1<<PORTB3)|(1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7)); //низкий уровень
	
	
	//SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
	//SPSR=(0<<SPI2X);
	
	//InitLed();
	////InitI2C();
	//ClearDisplay();
	//
	//WriteNum(THREE, TWO,ONE );
	//_delay_ms(100);
	//WriteNum(SIX, FIVE, FOUR);
	//
	//WriteNum(NINE, EITHT, SEVEN);
	//_delay_ms(100);
	//WriteNum(Z, Y, X);
	
	PORTB |= (1<<PORTB4);
	PORTB &= ~(1<<PORTB3);
	
	//_delay_ms(10);
	InitOLED();
	PORTB |= (1<<PORTB3);
	PORTB &= ~(1<<PORTB4);
	InitOLED();
	PORTB |= (1<<PORTB4);
	PORTB &= ~(1<<PORTB3);
	ClearOLED();
	PORTB |= (1<<PORTB3);
	PORTB &= ~(1<<PORTB4);
	ClearOLED();
	PORTB |= (1<<PORTB4);
	PORTB &= ~(1<<PORTB3);
	SetOLED();
	PORTB |= (1<<PORTB3);
	PORTB &= ~(1<<PORTB4);
	SetOLED();
	
	

	while(1)
	{
		
	}
	return 0;
}
