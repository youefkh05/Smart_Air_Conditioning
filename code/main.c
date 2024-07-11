/*
 * main.c
 *
 *  Created on: Apr 25, 2023
 *      Author: User
 */

#include "gpio.h"
#include "common_macros.h"
#include <avr/io.h>
#include "lcd.h"
#include <util/delay.h>
#include "Function.h"
#include <avr/interrupt.h>
#include <string.h>
#include "lm.h"

int main (){
	//----------------------------------------------------------
		//ENAPLE INTERRUPT
		setBit(GICR, 5);   //ENABLE INT2
		setBit(MCUCSR, 6); //SET INT2 TO RISING EDGE
		sei();             // SERG 7 ENABLE INTERRUPTS

		//----------------------------------------------------------
		ADC_init();
		system_init();
		uint8 temp = 0, otemp;
enterpass();
while(1){
	otemp = temp;
						temp = LM_getTemp();
						delay(250);
						if (otemp != temp) {
							LCD_displayStringAt("TEMP : ", 1, 0);
							LCD_displayInteger(temp);
							LCD_displayString("  ");
							if (temp > 50)
								analogWritePinB3(255);
							else if (temp > 40)
								analogWritePinB3(207);
							else if (temp > 27)
								analogWritePinB3(166);
							else
								analogWritePinB3(0);
						}
}
 return 0;
}

ISR(INT2_vect) {
	isrFlag = TRUE;
	analogWritePinB3(0);
	digitalWrite(greenLed, LOW);
	LCD_clear();
	LCD_displayStringAt("SYSTEM IS OFF", 0, 2);
	LCD_displayStringAt("ENTER PASS: ", 1, 0);

}

ISR(TIMER0_OVF_vect) {
	static uint8 overflow = 0;
	digitalWrite(greenLed, LOW);
	overflow++;
	if (overflow == 20) {
		alarmOff();
		TIMSK &= ~(1 << TOIE0);
		overflow = 0;
	} else if (overflow % 2)
		alarmOff();
	else
		alarmOn();
}
