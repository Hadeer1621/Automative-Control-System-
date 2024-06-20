/*========================================================================================
 *  @file    : TFT_interface.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *      _____ _____ _____   _       _             __                  _
 *     |_   _|  ___|_   _| (_)_ __ | |_ ___ _ __ / _| __ _  ___ ___  | |__
 *       | | | |_    | |   | | '_ \| __/ _ | '__| |_ / _` |/ __/ _ \ | '_ \
 *       | | |  _|   | |   | | | | | ||  __| |  |  _| (_| | (_|  __/_| | | |
 *       |_| |_|     |_____|_|_| |_|\__\___|_|  |_|  \__,_|\___\___(_|_| |_|
 *                    |_____|
 */

/*------------------------------------------------------------------------
 *	What i sell To Customer
 *		  The Archictect Give The API
 *						- The Name Of Function
 *						- What is The Input
 *						- What Is The Output
 *						- Macro
 *-------------------------------------------------------------------------------*/

/*================================================================================================
                       guard of file will call one time in .c
==================================================================================================*/


#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

/*======================MACROS============================================*/
//----------STANDARD_COLORS-----------------------
#define RGB444_DATA 		 0x03
#define RGB565_DATA 		 0x05
#define RGB666_DATA 		 0x06
/*-------2.4" TFT display constants------------------------*/
#define X_SIZE		 320U
#define Y_SIZE		 240U
/*-----Color constants---------------*/
#define BLACK			 	0x0000
#define BLUE 				0x001F
#define RED				 	0xF800
#define GREEN 				0x0400
#define LIME 				0x07E0
#define CYAN			    0x07FF
#define MAGENTA 			0xF81F
#define YELLOW 				0xFFE0
#define WHITE 				0xFFFF

/*==========================================================================*/
/*=============================DECLARATION_FUNCTION=========================*/

void HTFT_vTFTInit(void);
void HTFT_vTFTSetCursorPosition(u16 X_Start, u16 X_End ,u16 Y_Start,u16 Y_End);
void HTFT_vTFTDisplayImage(const u16* Copy_Image);
void HTFT_voidDisplayOff(void);

#endif /* TFT_INTERFACE_H_ */
