#ifndef __ADC_H__
#define __ADC_H__
	#include "ports.h"
	
	void init_periferal(void);
	uint16_t ADC_convert(void);
	float GetVoltage(uint16_t adc);
	
#endif
