/*========================================================================================
 *  @file    : TFT_Config.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *      _____ _____ _____   ____             __ _         _
 *     |_   _|  ___|_   _| / ___|___  _ __  / _(_) __ _  | |__
 *       | | | |_    | |  | |   / _ \| '_ \| |_| |/ _` | | '_ \
 *       | | |  _|   | |  | |__| (_) | | | |  _| | (_| |_| | | |
 *       |_| |_|     |_____\____\___/|_| |_|_| |_|\__, (_|_| |_|
 *                    |_____|                     |___/
 */

#ifndef TFT_CONFG_H_
#define TFT_CONFG_H_
/*======================MACROS============================================*/
/* Write pin port and pin */
#define SPI_SELLECTED   SPI3

#define TFT_RST_PORT   GPIOB_PORT
#define TFT_RST_PIN    GPIO_PIN_1


#define TFT_DC_PORT    GPIOB_PORT
#define TFT_DC_PIN     GPIO_PIN_2


/*======================MACROS============================================*/
#define SLPOUT 		0x11 				// SLEEP_OUT_COMMAND
#define DISPON 		0x29 				// DISPLAY_ON_COMMAND
#define XASET 		0x2A 				// ROW_ADDRESS_X_COMMAND
#define YASET		0x2B 				// COLUMN_ADDRESS_Y_COMMAND
#define RAMWR 		0x2C 				// RAM_WRITE_COMMAND
#define MADCTL 		0x36 				// RAM_WRITE_COMMAND_AXIS_CONTROL
#define COLMOD 		0x3A 				// COLOR_MODE_COMMAND
#define DISPOFF 	0x28 				// DISPLAY_OFF_COMMAND


#endif /* TFT_CONFG_H_ */
