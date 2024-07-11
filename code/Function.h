/*
 * Function.h
 *
 *  Created on: Apr 25, 2023
 *      Author: User
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_
#define buzzerport 1
#define buzzerpin 7
#define redport 1
#define redpin 6
#define greenport 0
#define greenpin 7
#define passnum 4
#define greenLed A,7
#define redLed   B,6
#define buzzer   B,7
#define motor    B,3
#define A 0
#define B 1
#define C 2
#define D 3




#include "std_types.h"



void enterpass(void);
void buzzeron(void);
void buzzeroff(void);
void greenron(void);
void greenoff(void);
void redon(void);
void redoff(void);
uint8 checkpass(void);
void system_init(void);
void analogWritePinB3(uint8 ticks);

void set_timer0_buzz();

void set_timer2_delay();

void delay(uint32 duration);

void alarmOn();

void alarmOff();

//functions

//pins
void pinMode(uint8 reg_n, uint8 pin, uint8 state);

void digitalWrite(uint8 reg_n, uint8 pin, uint8 value);

void pullupPin(uint8 reg_n, uint8 pin);

uint8 digitalRead(uint8 reg_n, uint8 pin);


#endif /* FUNCTION_H_ */
