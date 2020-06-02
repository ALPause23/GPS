#ifndef __ADC_H__
#define __ADC_H__
	#include "OLED.h"
		
	void init_periferal(void);
	uint16_t ADC_convert(void);
	float GetVoltage(uint16_t adc);
	void Set_OLED_voltage(void);
	
#endif
