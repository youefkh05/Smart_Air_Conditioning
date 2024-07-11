 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Seif ayman
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
#include "common_macros.h"
#include <avr/io.h>
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 0
#define LCD_RS_PIN_ID                  2
#define RS                             A,2
#define E                              A,3
#define lcdPort                        PORTC
#define LCD_E_PORT_ID                  0
#define LCD_E_PIN_ID                   3
#define LCD_DATA_PORT_ID               2

/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80

#define A 0

/* LCD Commands */
#define LCD_CLEAR                      0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_8_BITS                     0x38
#define LCD_4_BITS                     0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8 data);
void LCD_displayChar(uint8 character);
/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row,uint8 col);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_displayStringAt(const char *str, uint8 row, uint8 col);
/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data);
void LCD_displayInteger(int integer);
/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void);

#endif /* LCD_H_ */
