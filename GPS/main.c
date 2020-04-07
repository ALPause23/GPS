#include "ports.h"
#include "init_perif.h"
#include "uart_spi.h"
#include "delay.h"

// Declare your global variables here
void SPI_WriteByte()
{  
   PORTB &= ~(1<<PORTB4); 
   SPDR = 0b100011111111;
   while(!(SPSR & (1<<SPIF)));
   PORTB |= (1<<PORTB4); 
}

void main(void)
{    int qaz;
    // Declare your local variables here
    init_ports();
    init_periferal();
    //
    // Global enable interrupts
    #asm("sei")

    while (1)
    {   
        // Place your code here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
        //delay_ms(100);
        //SPI_WriteByte();
        for (qaz = 0; qaz < 256; qaz++)
          {
            SPDR = qaz;
            while(!(SPSR & (1<<SPIF)));//�������� ���� ������ �����������
            //����������� ������������� ����� ��� ������ � STORAGE REGISTER
            PORTB |= (1<<PORTB4); //������� �������
            PORTB &= ~(1<<PORTB4); //������ �������
            delay_ms(5000);
          }
          qaz = 0;
    }
}