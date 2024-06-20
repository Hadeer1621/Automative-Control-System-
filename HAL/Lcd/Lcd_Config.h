/*========================================================================================
 *  @file    : LCD_config.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *      _     ____ ____                     __ _         _
 *     | |   / ___|  _ \    ___ ___  _ __  / _(_) __ _  | |__
 *     | |  | |   | | | |  / __/ _ \| '_ \| |_| |/ _` | | '_ \
 *     | |__| |___| |_| | | (_| (_) | | | |  _| | (_| |_| | | |
 *     |_____\____|________\___\___/|_| |_|_| |_|\__, (_|_| |_|
 *                    |_____|                    |___/
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


/******************************************************_SELECT_LCD_MODE_***************************/

#define _8_BIT_MODE      8
#define _4_BIT_MODE      4
/*_OPTION_1 -> [ _8_BIT_MODE ]   */
/*_OPTION_2 -> [ _4_BIT_MODE ]   */
#define LCD_MODE                      _4_BIT_MODE
/*****************************************************_SELECT_LCD_PINS_***************************/
#if   LCD_MODE   ==   _8_BIT_MODE
#define LCD_DATA0_PIN                   GPIO_PIN_0
#define LCD_DATA1_PIN                   GPIO_PIN_1
#define LCD_DATA2_PIN                   GPIO_PIN_2
#define LCD_DATA3_PIN                   GPIO_PIN_3
#define LCD_DATA4_PIN                   GPIO_PIN_4
#define LCD_DATA5_PIN                   GPIO_PIN_5
#define LCD_DATA6_PIN                   GPIO_PIN_6
#define LCD_DATA7_PIN                   GPIO_PIN_7
#define LCD_EN_PIN                      GPIO_PIN_8
#define LCD_RS_PIN                      GPIO_PIN_9
#elif LCD_MODE   ==   _4_BIT_MODE

#define LCD_DATA4_PIN                   GPIO_PIN_0
#define LCD_DATA5_PIN                   GPIO_PIN_1
#define LCD_DATA6_PIN                   GPIO_PIN_2
#define LCD_DATA7_PIN                   GPIO_PIN_3
#define LCD_EN_PIN                      GPIO_PIN_8
#define LCD_RS_PIN                      GPIO_PIN_9
#endif

/*************************************************_SELECT_LCD_DATA_PORT_***************************/
#define LCD_DATA_PORT                   GPIOC_PORT

#endif /* HAL_LCD_LCD_CONFIG_H_ */
