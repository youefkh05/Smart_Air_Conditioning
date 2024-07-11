#include "lm.h"
#include "adc.h"

uint8 LM_getTemp() {

	uint16 adcValue = ADR_readChannel(LM_pinId);

	return ((uint32) adcValue * 500 / 1023.0);
}
