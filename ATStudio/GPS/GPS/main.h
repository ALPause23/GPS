#ifndef MAIN_H_
	#define MAIN_H_
	
	
	
	#include <avr/io.h>
	#include <avr/interrupt.h>
	#include <util/delay.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <avr/pgmspace.h>
	
	#include "util/twi.h"
	

#include "library/ports.h"



void SEND (unsigned char data);
void STOP ();
void START ();

unsigned char init[18]=
{
	0xA8,0x3F,0x00,0x40,0xA1,0xC8,0xDA,0x12,
	0x81,0x7F,0xA4,0xA6,0xD5,0x80,0x8D,0x14,0xAF,
};

#define		CL_HI		DDRC&=~(1<<0)	//PORTA.0 = SCL = SCK
#define		CL_LOW		DDRC|=(1<<0)	//PORTA.0
#define		DA_HI		DDRC&=~(1<<1)	//PORTA.1 = SDA
#define		DA_LOW		DDRC|=(1<<1)	//PORTA.1

#define		NAME		0b01111000		//����� ���������� �� ����
#define		DATS		0b01000000		//�������� ���������� ���� ������
#define		DAT			0b11000000		//�������� ������ ����� ������
#define		COM			0b10000000		//�������� ������ ����� �������



#endif /* MAIN_H_ */

