/*========================================================================================
 *  @file    : LED_Prog.c
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *      _     _____ ____     ____
 *     | |   | ____|  _ \   |  _ \ _ __ ___   __ _   ___
 *     | |   |  _| | | | |  | |_) | '__/ _ \ / _` | / __|
 *     | |___| |___| |_| |  |  __/| | | (_) | (_| || (__
 *     |_____|_____|________|_|   |_|  \___/ \__, (_\___|
 *                     |_____|               |___/
 */

#include "Led_interface.h"

void H_Led_Void_LedInit(port_t Copy_u8PortName ,pin_num Copy_u8PinNum)
{
    MGPIO_vSetPinMode(Copy_u8PortName,Copy_u8PinNum,OUTPUT);
    MGPIO_vSetPinOutPutType(Copy_u8PortName,Copy_u8PinNum,PUSH_PULL);
    MGPIO_vSetPinOutSpeed(Copy_u8PortName,Copy_u8PinNum,LOW_SPEED);
    MGPIO_vSetPullType(Copy_u8PortName,Copy_u8PinNum,NORMAL);
}


void H_Led_Void_LedOn(port_t Copy_u8PortName ,pin_num Copy_u8PinNum)
{
	MGPIO_vWriteData(Copy_u8PortName, Copy_u8PinNum, HIGH);

}

void H_Led_Void_LedOff(port_t Copy_u8PortName ,pin_num Copy_u8PinNum)
{
	MGPIO_vWriteData(Copy_u8PortName, Copy_u8PinNum, LOW);
}


void H_Led_Void_LedTog(port_t Copy_u8PortName ,pin_num Copy_u8PinNum)
{
    MGPIO_vWriteData(Copy_u8PortName, Copy_u8PinNum, TOGL);

}


void H_Led_Void_LedBlink(port_t Copy_u8PortName ,pin_num Copy_u8PinNum)
{
	MGPIO_vWriteData(Copy_u8PortName, Copy_u8PinNum, HIGH);
	Delay_vMsIn16MHz(LED_DELAY_TIME);
	MGPIO_vWriteData(Copy_u8PortName, Copy_u8PinNum, LOW);
}
