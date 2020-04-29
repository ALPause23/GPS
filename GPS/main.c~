#include "ports.h"
#include "init_perif.h"
#include "uart_spi.h"
#include "delay.h"
#include "stdint.h"
//#include "twi.h"
#include <i2c.h>

// DS1307 Real Time Clock functions
//#include <ds1307.h>

// uint8_t twi_status_register;
//	uint8_t i2cstart(uint8_t address);
//	uint8_t i2cwrite(uint8_t data);
//	void i2cstop(void);
//uint8_t i2cstart(uint8_t address)
//{
//    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
//    while(!(TWCR & (1<<TWINT)))
//        ;
//
//    twi_status_register = TW_STATUS & 0xF8;
//    if ((twi_status_register != TW_START) && (twi_status_register != TW_REP_START))
//    {
//        return 1;
//    }
//
//    TWDR = address;
//    TWCR = (1<<TWINT) | (1<<TWEN);
//
//    while(!(TWCR & (1<<TWINT)))
//        ;
//
//    twi_status_register = TW_STATUS & 0xF8;
//    if ((twi_status_register != TW_MT_SLA_ACK) && (twi_status_register != TW_MR_SLA_ACK))
//    {
//        return 1;
//    }
//    return 0;
//}
//
//uint8_t i2cwrite(uint8_t data)
//{
//    TWDR = data;
//    TWCR = (1<<TWINT) | (1<<TWEN);
//
//    while(!(TWCR & (1<<TWINT)));
//
//    twi_status_register = TW_STATUS & 0xF8;
//    if (twi_status_register != TW_MT_DATA_ACK)
//    {
//        return 1;
//    }
//    else
//    {
//        return 0;
//    }
//}
//
//void i2cstop(void)
//{
//	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
//	while(TWCR & (1<<TWSTO));
//}

void InitLed()
{
    int i = 0;
    while(i < 4)
    {
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

// Declare your global variables here
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

void SendLed(char adr, char data)
{
    char a, b;
    a = adr;
    b = data;

    SPI_WriteStartByte(adr);
    //delay_ms(10);
    SPI_WriteEndByte(data);
    //delay_ms(10);
}

void main(void)
{

    int i = 0;// Declare your local variables here
    char j = 0;
    init_ports();
    init_periferal();
    //
    // Global enable interrupts
    #asm("sei")
    InitLed();
    TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

        // Bit-Banged I2C Bus initialization
    // I2C Port: PORTC
    // I2C SDA bit: 1
    // I2C SCL bit: 0
    // Bit Rate: 100 kHz
    // Note: I2C settings are specified in the
    // Project|Configure|C Compiler|Libraries|I2C menu.
    i2c_init();

    // DS1307 Real Time Clock initialization
    // Square wave output on pin SQW/OUT: Off
    // SQW/OUT pin state: 0
    rtc_init(0,0,0);
    while(i <= 4)
    {
        for(j = 0; j <= 8; j++)
        {
            SendLed(j,0);
        }
//        SendLed(1,0);
//        SendLed(2,0);
//        SendLed(3,0);
//        SendLed(4,0);
//        SendLed(5,0);
//        SendLed(6,0);
//        SendLed(7,0);
//        SendLed(8,0);
        i++;
        //delay_ms(10);
    }

    SendLed(0, 1);
    SendLed(5, 7);
//    delay_ms(1);
//    SendLed(1,2);
//    delay_ms(1);
//    SendLed(1,3);
//    delay_ms(1);
//    SendLed(1,4);
//    delay_ms(1);
//    SendLed(1,5);
//    delay_ms(1);
//    SendLed(2,255);

    while (1)
    {

    }
}