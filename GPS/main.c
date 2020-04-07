#include "ports.h"
#include "init_perif.h"
#include "uart_spi.h"
#include "delay.h"



void InitLed()
{
    int i = 0;
    for(i; i < 4; i++)
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
	}
}

// Declare your global variables here
void SPI_WriteByte()
{
   PORTB &= ~(1<<PORTB4);
   SPDR = 0b100011111111;
   while(!(SPSR & (1<<SPIF)));
   PORTB |= (1<<PORTB4);
}

void SendLed(int i)
{

    char a, b;
    a = (i >> 8);
    b = i;


    PORTB &= ~(1<<PORTB4);
    SPDR = a;
    while(!(SPSR & (1<<SPIF)));
    //PORTB |= (1<<PORTB4); //высокий уровень
    //_delay_ms(50);

    //PORTB &= ~(1<<PORTB4); //низкий уровень
    SPDR = b;
    while(!(SPSR & (1<<SPIF)));
    PORTB |= (1<<PORTB4);
}

void main(void)
{
    int qaz;

    // Declare your local variables here
    init_ports();
    init_periferal();
    //
    // Global enable interrupts
    #asm("sei")
    InitLed();


    while (1)
    {
        SendLed(0x00);
        SendLed(0x100);
        SendLed(0x200);
        SendLed(0x300);
        SendLed(0x400);
        SendLed(0x500);
        SendLed(0x600);
        SendLed(0x700);
        SendLed(0x800);
        delay_ms(1000);
    }
}