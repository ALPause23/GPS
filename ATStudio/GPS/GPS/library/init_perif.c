#include "init_perif.h"



void init_periferal()
{
    ADCSRA |= (1<<ADEN) // Разрешение использования АЦП

    |(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//Делитель 128 = 64 кГц
	ADMUX = 0x00; //(1<<REFS1)|(1<<REFS0); //Внутренний Источник ОН 2,56в, вход ADC0
}

//  Получение байта
uint16_t ADC_convert()
{
	ADCSRA |= (1<<ADSC); //Начинаем преобразование
	while((ADCSRA & (1<<ADSC))); //проверим закончилось ли аналого-цифровое преобразование
	return (uint16_t) ADC;
}

float GetVoltage(uint16_t adc)
{
	return ((adc*16.335)/1023);
}