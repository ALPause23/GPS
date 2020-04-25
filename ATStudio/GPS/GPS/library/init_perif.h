#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>



#define F_CPU 40000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void init_periferal();
