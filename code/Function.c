/*
 * Function.c
 *
 *  Created on: Apr 25, 2023
 *      Author: User
 */


#include "Function.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h>
#include <util/delay.h> /* For the delay functions */
#include "lcd.h"
#include "gpio.h"
#include "keypad.h"
const uint8 pass[passnum]={1,2,3,4};
volatile boolean isrFlag = 0;

void buzzeron(void){
	 GPIO_setupPinDirection(buzzerport, buzzerpin, 1);
	  GPIO_writePin(buzzerport, buzzerpin, 1);
}

void buzzeroff(void){
	 GPIO_setupPinDirection(buzzerport, buzzerpin, 1);
	  GPIO_writePin(buzzerport, buzzerpin, 0);
}

void redon(void){
	GPIO_setupPinDirection(redport, redpin, 1);
		  GPIO_writePin(redport, redpin, 1);
}

void redoff(void){
	GPIO_setupPinDirection(redport, redpin, 1);
		  GPIO_writePin(redport, redpin, 0);
}

void greenon(void){
	GPIO_setupPinDirection(greenport, greenpin, 1);
		  GPIO_writePin(greenport, greenpin, 1);
}

void greenoff(void){
	GPIO_setupPinDirection(greenport, greenpin, 1);
		  GPIO_writePin(greenport, greenpin, 0);
}

uint8 checkpass(void){
	uint8 a[passnum];
	//get the pass from keypad
	for(int i=0;i<passnum;i++){
		a[i]=KEYPAD_getPressedKey();
		_delay_ms(10);
	 LCD_moveCursor(1,i);
	 if(a[i]==35)LCD_displayStringRowColumn(1,i,"#");
	 else if(a[i]==42)LCD_displayStringRowColumn(1,i,"*");
	 else LCD_intgerToString(a[i]);
	  KEYPAD_is_off();//wait for the next input
	}

	//if the input is right will return 1
	//check if it is the pass
	for(int i=0;i<passnum;i++){
			if(a[i]!=pass[i])return 0;
		}
	return 1;
}

void enterpass(void){
	LCD_init();
	redoff();
	buzzeroff();
	greenoff();
	LCD_displayStringRowColumn(0,0,"Enter Password");
	uint8 check =0;
	check=checkpass();
	_delay_ms(500);

	while(!check)
{
	 LCD_clearScreen();
	 LCD_displayStringRowColumn(0,0,"Wrong Password");
	 LCD_displayStringRowColumn(1,0,"Sorry my man :(");
	 redon();
	 for(int i=0;i<25;i++){
		 buzzeron();
	 _delay_ms(100);
	 buzzeroff();
	 _delay_ms(100);
	 }
	 redoff();
	 LCD_clearScreen();
	 LCD_displayStringRowColumn(0,0,"Enter Password");
	 check=checkpass();
 }

	LCD_clearScreen();
    LCD_displayStringRowColumn(0,0,"System is ON :)");
    LCD_displayStringRowColumn(1,2,"Welcome");
    greenon();
}

void pinMode(uint8 reg_n, uint8 pin, uint8 state) {
	volatile uint8 *reg = &DDRA;
	switch (reg_n) {
	case 0:
		break;
	case 1:
		reg = &DDRB;
		break;
	case 2:
		reg = &DDRC;
		break;
	case 3:
		reg = &DDRD;
		break;
	}
	if (state)
		setBit((*reg), pin);
	else
		resetBit((*reg), pin);
}

void digitalWrite(uint8 reg_n, uint8 pin, uint8 value) {
	volatile uint8 *reg = &PORTA;
	switch (reg_n) {
	case 0:
		break;
	case 1:
		reg = &PORTB;
		break;
	case 2:
		reg = &PORTC;
		break;
	case 3:
		reg = &PORTD;
		break;
	}
	if (value)
		setBit((*reg), pin);
	else
		resetBit((*reg), pin);
}

void pullupPin(uint8 reg_n, uint8 pin) {
	digitalWrite(reg_n, pin, 1);
}

uint8 digitalRead(uint8 reg_n, uint8 pin) {
	volatile uint8 *reg = &PINA;
	switch (reg_n) {
	case 0:
		break;
	case 1:
		reg = &PINB;
		break;
	case 2:
		reg = &PINC;
		break;
	case 3:
		reg = &PIND;
		break;
	}
	return (*reg) & (1 << pin);
}
void system_init(void){
//----------------------------------------------------------

pinMode(greenLed, OUTPUT);
pinMode(redLed, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(motor, OUTPUT);

digitalWrite(motor, LOW);

//----------------------------------------------------------
}

//--------------------------------------------------------------

void analogWritePinB3(uint8 ticks) {
	TCCR0 = 0;
	TCNT0 = 0;
	TCCR0 = (1 << WGM01) | (1 << WGM00) | (1 << COM01) | (1 << CS01);
	OCR0 = ticks;
}

void set_timer0_buzz() {
	TCCR0 = 0;
	TCCR0 = (1 << CS02) | (1 << CS00) | (1 << FOC0);
	TIMSK |= (1 << TOIE0);
}

void set_timer2_delay() {
	TCCR2 = 0;
	TCCR2 = (1 << FOC2) | (1 << CS22) | (1 << CS21) | (1 << CS20);
	while (!(TIFR & (1 << TOV2)))
		;
	TIFR |= (1 << TOV2);
	TCNT2 = 0;
}

void delay(uint32 duration) {
	duration = duration * 4 / 1000;
	while (duration--)
		set_timer2_delay();
}

void alarmOn() {
	digitalWrite(redLed, HIGH);
	digitalWrite(buzzer, HIGH);
}

void alarmOff() {
	digitalWrite(redLed, LOW);
	digitalWrite(buzzer, LOW);
}

//-----------------------------------------------------------------------
