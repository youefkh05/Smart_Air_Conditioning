#include <avr/io.h>
#include "adc.h"

void ADC_init() {
	ADMUX |= (1 << REFS0);  // Set reference voltage to AVCC
	ADCSRA |= (1 << ADEN);  // Enable ADC
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescaler to 128
}

uint16 ADR_readChannel(uint8 channel_n) {
	ADMUX = (ADMUX & 0xF0) | (channel_n & 0x0F);  // Select ADC channel
	ADCSRA |= (1 << ADSC);  // Start ADC conversion
	while (ADCSRA & (1 << ADSC));  // Wait for conversion to complete
	return ADC;  // Return ADC result
}
