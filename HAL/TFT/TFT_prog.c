/*========================================================================================
 *  @file    : TFT_Prog.c
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *      _____ _____ _____   ____
 *     |_   _|  ___|_   _| |  _ \ _ __ ___   __ _   ___
 *       | | | |_    | |   | |_) | '__/ _ \ / _` | / __|
 *       | | |  _|   | |   |  __/| | | (_) | (_| || (__
 *       |_| |_|     |_____|_|   |_|  \___/ \__, (_\___|
 *                    |_____|               |___/
 */

/*===========   INCLUDE LIB   ===========*/
#include "TFT_Confg.h"
#include "TFT_interface.h"
#include "TFT_Private.h"
#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "STD_TYPES.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
/*======================================*/
/*======================================*/

/*--------------------------------------------------------------------------
 -----------------------------Functions Implementations-----------
---------------------------------------------------------------------------*/
/*--------------------------------START_FUNCTION---------------------------*/

void HTFT_vTFTInit(void){

	MGPIO_vSetPinMode( TFT_RST_PORT , TFT_RST_PIN , OUTPUT ); //RES
	MGPIO_vSetPinMode( TFT_DC_PORT , TFT_DC_PIN , OUTPUT );

	MGPIO_vSetPinMode(GPIOB_PORT,GPIO_PIN_3,ALT);
	MGPIO_vSetPinMode(GPIOB_PORT,GPIO_PIN_5,ALT);

	GPIO_vSetAlternateFunction(GPIOB_PORT,GPIO_PIN_3, AF6);
	GPIO_vSetAlternateFunction(GPIOB_PORT,GPIO_PIN_5, AF6);

	MGPIO_vSetPinOutSpeed(GPIOB_PORT,GPIO_PIN_3,VERY_HIGH_SPEED);
	MGPIO_vSetPinOutSpeed(GPIOB_PORT,GPIO_PIN_5,VERY_HIGH_SPEED);

	SPI_vInit();

	/* Reset Puls To Initializing All registers*/
	MGPIO_vWriteData( TFT_RST_PORT , TFT_RST_PIN , HIGH );
	MSTK_vBusyWait(100);
	MGPIO_vWriteData( TFT_RST_PORT , TFT_RST_PIN , LOW );
	MSTK_vBusyWait(1);
	MGPIO_vWriteData( TFT_RST_PORT , TFT_RST_PIN , HIGH );
	MSTK_vBusyWait(100);
	MGPIO_vWriteData( TFT_RST_PORT , TFT_RST_PIN , LOW );
	MSTK_vBusyWait(100);
	MGPIO_vWriteData( TFT_RST_PORT , TFT_RST_PIN , HIGH );
	MSTK_vBusyWait( 120000 );
	/* 2- Sleep Out Mode */
	HTFT_vTFTWriteCommand( SLPOUT )	;
	/* 3- Waiting 150 mili sec */
	MSTK_vBusyWait   ( 150000 ) ;
	/* 4- Color Mode */
	HTFT_vTFTWriteCommand( COLMOD );
	HTFT_vTFTWriteData   ( RGB565_DATA   ) 	;
	/* 5- Display On */
	HTFT_vTFTWriteCommand( DISPON ) ;
	/* Remap TFT addresses ( x = 0 , y = 0 Start From The Left Top Of The TFT ) */
	HTFT_vTFTWriteCommand( MADCTL );
	HTFT_vTFTWriteData   ( 0xC0 );

}

/*-------------------------------END_FUNCTION----------------------------*/
/*------------------------------START_FUNCTION---------------------------*/
void HTFT_vSetCursorPosition(u16 X_Start, u16 Y_Start, u16 X_End,u16 Y_End)
{
	/*	Set X_ADRESS  */
	HTFT_vTFTWriteCommand(XASET);
	/* X Start Position*/
	HTFT_vTFTWriteData(0);      		/*send higher byte*/
	HTFT_vTFTWriteData(X_Start);		/*send lower Byte */
	/* X End Position*/
	HTFT_vTFTWriteData(0);          /*send higher byte*/
	HTFT_vTFTWriteData(X_End);    /*send lower Byte */ //63

	/*	Set Y_ADRESS */
	HTFT_vTFTWriteCommand(YASET);
	/* Y Start Position*/
	HTFT_vTFTWriteData(Y_Start >>8);      		/*send higher byte*/ //0
	HTFT_vTFTWriteData(Y_Start & 0x00ff);		/*send lower Byte */ //0
	/* Y End Position*/
	HTFT_vTFTWriteData(Y_End >>8);          /*send higher byte*/ //1
	HTFT_vTFTWriteData(Y_End & 0x00ff);    /*send lower Byte */ //63
}
/*-------------------------------END_FUNCTION----------------------------*/
/*------------------------------START_FUNCTION---------------------------*/
void HTFT_vTFTDisplayImage(const u16* Copy_Image)
{
	u32 Counter =0;
	u32 Local_u32Size = (240) * (320); 	/*calculate image element numbers*/
	HTFT_vSetCursorPosition(0, 0, 239, 319);    /*set addresses of x and y */
	/* RAM Write Command Every thing is coming After This Command Display on TFT*/
	HTFT_vTFTWriteCommand(RAMWR);
	for(Counter = 0 ; Counter < Local_u32Size; Counter ++)
	{
		HTFT_vTFTWriteData(Copy_Image[Counter] >> 8);		/* Write The High Byte */
		HTFT_vTFTWriteData(Copy_Image[Counter] & 0x00ff);	/* Write The LOW  Byte */
	}
}
/*-------------------------------END_FUNCTION----------------------------*/
/*------------------------------START_FUNCTION---------------------------*/
static void HTFT_vTFTWriteData(u16 Copy_u8Data)
{
	/* DC is 1 for data */
	MGPIO_vWriteData( TFT_DC_PORT , TFT_DC_PIN , HIGH);
	/* Send Data */
	(void)SPI_u8SendRecive( SPI_SELLECTED,Copy_u8Data ) ;
}
/*-------------------------------END_FUNCTION----------------------------*/
/*------------------------------START_FUNCTION---------------------------*/
static void HTFT_vTFTWriteCommand(u16 Copy_u8Command)
{

	/* DC is 0 for data */
	MGPIO_vWriteData( TFT_DC_PORT , TFT_DC_PIN , LOW );
	/* Send Command */
	(void)SPI_u8SendRecive( SPI_SELLECTED,Copy_u8Command ) ;
}
/*-------------------------------END_FUNCTION----------------------------*/
/*------------------------------START_FUNCTION---------------------------*/
void HTFT_voidDisplayOff(void)
{
	HTFT_vTFTWriteCommand(DISPOFF);
}
/*-------------------------------END_FUNCTION----------------------------*/
