#include "ports.h"
#include "init_perif.h"
#include "uart_spi.h"
#include "delay.h"

// Declare your global variables here
void SPI_WriteByte()
{  
   PORTB &= ~(1<<PORTB4); 
   SPDR = 0b00110000;
   while(!(SPSR & (1<<SPIF)));
   PORTB |= (1<<PORTB4); 
}

void main(void)
{
    // Declare your local variables here
    init_ports();
    init_periferal();


    // Global enable interrupts
    #asm("sei")

    while (1)
    {
        // Place your code here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
        delay_ms(100);
        SPI_WriteByte();
    }
}