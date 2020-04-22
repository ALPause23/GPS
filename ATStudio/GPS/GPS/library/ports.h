
#include <stdio.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/iom16.h>

#define PortA0   (1<<PORTA0)
//#define PA1   (1<<PORTA1)
//#define PA2   (1<<PORTA2)
//#define PA3   (1<<PORTA3)
//#define PA4   (1<<PORTA4)
//#define PA5   (1<<PORTA5)
//#define PA6   (1<<PORTA6)
//#define PA7   (1<<PORTA7)
//
//
//#define PiB0   (1<<PORTB0)
//#define PB1   (1<<PORTB1)
//#define PB2   (1<<PORTB2)
//#define PB3   (1<<PORTB3)
//#define PB4   (1<<PORTB4)
//#define PB5   (1<<PORTB5)
//#define PB6   (1<<PORTB6)
//#define PB7   (1<<PORTB7)
//
//
//#define PC0   (1<<0);
//#define PC1   (1<<1);
//#define PC2   (1<<2);
//#define PC3   (1<<3);
//#define PC4   (1<<4);
//#define PC5   (1<<5);
//#define PC6   (1<<6);
//#define PC7   (1<<7);
//
//
//#define PD0   (1<<0);
//#define PD1   (1<<1);
//#define PD2   (1<<2);
//#define PD3   (1<<3);
//#define PD4   (1<<4);
//#define PD5   (1<<5);
//#define PD6   (1<<6);
//#define PD7   (1<<7);


void init_ports();


