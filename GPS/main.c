#include "ports.h"
#include "init_perif.h"
#include "uart_spi.h"

// Declare your global variables here

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

    }
}