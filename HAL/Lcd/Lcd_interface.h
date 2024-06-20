/*========================================================================================
 *  @file    : LCD_interface.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *      _     ____ ____     _       _             __                  _
 *     | |   / ___|  _ \   (_)_ __ | |_ ___ _ __ / _| __ _  ___ ___  | |__
 *     | |  | |   | | | |  | | '_ \| __/ _ | '__| |_ / _` |/ __/ _ \ | '_ \
 *     | |__| |___| |_| |  | | | | | ||  __| |  |  _| (_| | (_|  __/_| | | |
 *     |_____\____|________|_|_| |_|\__\___|_|  |_|  \__,_|\___\___(_|_| |_|
 *                    |_____|
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_


/********************************************************_INCLUDES_******************************/
/*============INCLUDES_LIB============*/
#include "Lcd_Config.h"
#include "GPIO_interface.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "STD_TYPES.h"
/*===================================*/
/*============INCLUDES_MCAL============*/
/*********************************************************_MACROS_*******************************/
#define LCD_RETURN_HOME                        0x02
#define LCD_CLEAR                              0x01
#define DISPLAY_ON_CURSOR_OFF                  0x0C
#define _8_BIT_MODE_COMAND                     0x38
#define _4_BIT_MODE_COMAND                     0x33
#define _4_BIT_MODE_COMAND_1                   0x33
#define _4_BIT_MODE_COMAND_2                   0x32
#define _4_BIT_MODE_COMAND_3                   0x28
#define LCD_R0_C0_COMAND                       0x80
#define LCD_R1_C0_COMAND                       0xC0

/*******************************************************_PROTOTYPES_*****************************/
void H_Lcd_Void_LcdInit(void);
void H_Lcd_Void_LcdWriteCharacter(u8);
void H_Lcd_Void_LcdWriteCommand(u8);
void H_Lcd_Void_LcdWriteString(u8*);
void H_Lcd_Void_LcdWriteNumber(s32);
void H_Lcd_Void_LcdGoTo(u8,u8);
void H_Lcd_Void_LcdClr(void);


#endif /* HAL_LCD_LCD_INTERFACE_H_ */
