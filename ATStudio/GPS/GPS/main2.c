#include "ports.h"
#include "init_perif.h"
#include "uart_spi.h"
#include "delay.h"



void InitLed()
{
    int i = 0;
    while(i < 4)
    {
        // ������������� �������
        PORTB &= ~(1<<PORTB4);
        SPDR = 0x0F;
        while(!(SPSR & (1<<SPIF)));
        //PORTB |= (1<<PORTB4); //������� �������
        //_delay_ms(50);

        //PORTB &= ~(1<<PORTB4); //������ �������
        SPDR = 0x00;
        while(!(SPSR & (1<<SPIF)));
        PORTB |= (1<<PORTB4);


        PORTB &= ~(1<<PORTB4);
        SPDR = 0x0C;
        while(!(SPSR & (1<<SPIF)));
        //PORTB |= (1<<PORTB4); //������� �������
        //_delay_ms(50);

        //PORTB &= ~(1<<PORTB4); //������ �������
        SPDR = 0x01;
        while(!(SPSR & (1<<SPIF)));
        PORTB |= (1<<PORTB4);


        PORTB &= ~(1<<PORTB4);
        SPDR = 0x0A;
        while(!(SPSR & (1<<SPIF)));
        //PORTB |= (1<<PORTB4); //������� �������
        //_delay_ms(50);

        //PORTB &= ~(1<<PORTB4); //������ �������
        SPDR = 0x0F;
        while(!(SPSR & (1<<SPIF)));
        PORTB |= (1<<PORTB4);


        PORTB &= ~(1<<PORTB4);
        SPDR = 0x0B;
        while(!(SPSR & (1<<SPIF)));
        //PORTB |= (1<<PORTB4); //������� �������
        //_delay_ms(50);

        //PORTB &= ~(1<<PORTB4); //������ �������
        SPDR = 0x07;
        while(!(SPSR & (1<<SPIF)));
        PORTB |= (1<<PORTB4);


        PORTB &= ~(1<<PORTB4);
        SPDR = 0x09;
        while(!(SPSR & (1<<SPIF)));
        //PORTB |= (1<<PORTB4); //������� �������
        //_delay_ms(50);

        //PORTB &= ~(1<<PORTB4); //������ �������
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