#ifndef ADC_H_
#define ADC_H_

#include "common_macros.h"
#include "std_types.h"
void ADC_init();

uint16 ADR_readChannel(uint8 channel_n);

#endif /* ADC_H_ */
