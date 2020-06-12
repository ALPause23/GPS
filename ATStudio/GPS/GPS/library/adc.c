#include "adc.h"

int i = 0, j = 0;

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
	return (((adc*13.1)/1023.0) + 1.50);
}

void Set_OLED_voltage(void)
{
	//if(i == 1000)
	//{
		ADMUX = 0x00;
		i = 0;
		SelectDisplay(2);
		ClearOLED();
		SetPointer(0x08); // set point for paint zip
		Set_OLED_Image(molnia_struct, molnia_logo);
		float volt = GetVoltage(ADC_convert());
		int voltMSB = (int)volt;
		int voltLSB = (volt - (float)voltMSB)*10.0;
		
		SetPointer(0x5B);
		Set_OLED_Num(GetNum(voltLSB));
		
		SetPointer(0x56);
		Set_OLED_Image(point_struct, point_logo);
		
		SetPointer(0x3C);
		(voltMSB >= 10) ? (Set_OLED_Num(GetNum(voltMSB - 10))) : (Set_OLED_Num(GetNum(voltMSB)));
		SetPointer(0x22);
		Set_OLED_Num(GetNum(voltMSB/10));
		
	//}
	//i++;
}

void Compare(void)
{
	if((PINA & (PortA1)) == 0)
	{
		SetIntensity(0x00);
		PORTA |= PortA4;
		PORTA &= ~PortA5;
	}
	else
	{
		SetIntensity(0x0F);
		PORTA |= PortA5;
		PORTA &= ~PortA4;
	}
}
