/*========================================================================================
 *  @file    : LCD_Prog.c
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *      _     ____ ____     ____
 *     | |   / ___|  _ \   |  _ \ _ __ ___   __ _   ___
 *     | |  | |   | | | |  | |_) | '__/ _ \ / _` | / __|
 *     | |__| |___| |_| |  |  __/| | | (_) | (_| || (__
 *     |_____\____|________|_|   |_|  \___/ \__, (_\___|
 *                    |_____|               |___/
 */

/*======================================*/
/*===========  INCLUDE HAL  ===========*/
#include "Lcd_interface.h"

/*======================================*/
/*===================START_FUNCTION=======================*/
void H_Lcd_Void_LcdInit(void)
{
	u8 i;
/*===============================LCD MODE===============================*/
#if   LCD_MODE   ==   _8_BIT_MODE
	for (i=0;i<=9;i++)
	{
		MGPIO_vSetPinMode(LCD_DATA_PORT,i,OUTPUT);
		MGPIO_vSetPinOutPutType(LCD_DATA_PORT,i,PUSH_PULL);
		MGPIO_vSetPinOutSpeed(LCD_DATA_PORT,i,LOW_SPEED);
		MGPIO_vSetPullType(LCD_DATA_PORT,i,NORMAL);
	}
	Delay_vMsIn16MHz(500);
	H_Lcd_Void_LcdWriteCommand(_8_BIT_MODE_COMAND);
	H_Lcd_Void_LcdWriteCommand(DISPLAY_ON_CURSOR_OFF);
	H_Lcd_Void_LcdWriteCommand(LCD_RETURN_HOME);
	H_Lcd_Void_LcdWriteCommand(LCD_CLEAR);

/*==================================================================*/
#elif LCD_MODE   ==   _4_BIT_MODE

	for (i=0;i<=9;i++)
	{
		if (i==4)i=8;
		MGPIO_vSetPinMode(LCD_DATA_PORT,i,OUTPUT);
		MGPIO_vSetPinOutPutType(LCD_DATA_PORT,i,PUSH_PULL);
		MGPIO_vSetPinOutSpeed(LCD_DATA_PORT,i,LOW_SPEED);
		MGPIO_vSetPullType(LCD_DATA_PORT,i,NORMAL);
	}
	Delay_vMsIn16MHz(500);
	H_Lcd_Void_LcdWriteCommand(_4_BIT_MODE_COMAND_1);
	H_Lcd_Void_LcdWriteCommand(_4_BIT_MODE_COMAND_2);
	H_Lcd_Void_LcdWriteCommand(_4_BIT_MODE_COMAND_3);
	H_Lcd_Void_LcdWriteCommand(DISPLAY_ON_CURSOR_OFF);
	H_Lcd_Void_LcdWriteCommand(LCD_RETURN_HOME);
	H_Lcd_Void_LcdWriteCommand(LCD_CLEAR);

#endif
}

/*==============================START_FUNCTION=======================*/
void H_Lcd_Void_LcdWriteCharacter(u8 Local_u8_Character)
{
#if LCD_MODE ==_8_BIT_MODE
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_RS_PIN,HIGH);
	MGPIO_vPortOutputByte(LCD_DATA_PORT,Local_u8_Character,0,8);
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,LOW);


#elif LCD_MODE ==_4_BIT_MODE
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_RS_PIN,HIGH);

	MGPIO_vPortOutputByte(LCD_DATA_PORT,Local_u8_Character>>4,0,4);

	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,LOW);
	Delay_vMsIn16MHz(1);


	MGPIO_vPortOutputByte(LCD_DATA_PORT,Local_u8_Character,0,4);

	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,LOW);
#endif
	Delay_vMsIn16MHz(5);

}

/*==============================START_FUNCTION=======================*/
void H_Lcd_Void_LcdWriteCommand(u8 Local_u8_Command)
{
#if LCD_MODE ==_8_BIT_MODE
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_RS_PIN,LOW);
	MGPIO_vPortOutputByte(LCD_DATA_PORT,Local_u8_Command,0,8);
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,LOW);
#elif LCD_MODE ==_4_BIT_MODE
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_RS_PIN,LOW);

	MGPIO_vPortOutputByte(LCD_DATA_PORT,Local_u8_Command>>4,0,4);

	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,LOW);
	Delay_vMsIn16MHz(1);


	MGPIO_vPortOutputByte(LCD_DATA_PORT,Local_u8_Command,0,4);

	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_DATA_PORT,LCD_EN_PIN,LOW);
#endif
	Delay_vMsIn16MHz(5);

}

/*==============================START_FUNCTION=======================*/
void H_Lcd_Void_LcdWriteString(u8* Local_u8_String)
{
	u8 Local_u8_Character;
	while( * Local_u8_String  !='\0')
	{
	 Local_u8_Character = * Local_u8_String;
	 H_Lcd_Void_LcdWriteCharacter(Local_u8_Character);
	 Local_u8_String ++;

	}
}
/*==============================START_FUNCTION=======================*/
void H_Lcd_Void_LcdWriteNumber(s32 Local_f32_Number)
{
	u8 Local_u8_Arr [10]={0};
	s8 Local_s8_Counter=0;
	s8 Local_s8_Decimal_Point=0;
	s32 Local_s32_Number;

	if(Local_f32_Number<0)
	{
		Local_f32_Number *= -1;
		H_Lcd_Void_LcdWriteCharacter('-');
	}

	Local_s32_Number=Local_f32_Number;

	if (Local_s32_Number==0)H_Lcd_Void_LcdWriteCharacter(48);

	while (Local_s32_Number != Local_f32_Number)
	{
		Local_f32_Number=Local_f32_Number * 10;
		Local_s32_Number=Local_f32_Number;
		Local_s8_Decimal_Point++;
	}


	while (Local_s32_Number !=0)
	{
		Local_u8_Arr[Local_s8_Counter] =Local_s32_Number %10;
		Local_s32_Number = Local_s32_Number/10;
		Local_s8_Counter ++;
	}

	Local_s8_Counter --;

	while (Local_s8_Counter >=0 )
	{
		if((Local_s8_Decimal_Point>0)&&(Local_s8_Decimal_Point -1 == Local_s8_Counter))
		{
			H_Lcd_Void_LcdWriteCharacter('.');
		}
		H_Lcd_Void_LcdWriteCharacter(Local_u8_Arr[Local_s8_Counter]+48);
		Local_s8_Counter --;
	}


}
/*==============================START_FUNCTION=======================*/
void H_Lcd_Void_LcdGoTo(u8 Local_u8_Row,u8 Local_u8_Col)
{
	u8 Local_u8_arr[2]={LCD_R0_C0_COMAND,LCD_R1_C0_COMAND};
	H_Lcd_Void_LcdWriteCommand(Local_u8_arr[Local_u8_Row]+Local_u8_Col);

}

/*==============================START_FUNCTION=======================*/
void H_Lcd_Void_LcdClr(void)
{
	H_Lcd_Void_LcdWriteCommand(LCD_CLEAR);
}




