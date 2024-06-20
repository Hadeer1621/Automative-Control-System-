/*========================================================================================
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *      ____            _     ____        _   _                  ____
 *     |  _ \ _   _ ___| |__ | __ ) _   _| |_| |_ ___  _ __     |  _ \ _ __ ___   __ _   ___
 *     | |_) | | | / __| '_ \|  _ \| | | | __| __/ _ \| '_ \    | |_) | '__/ _ \ / _` | / __|
 *     |  __/| |_| \__ | | | | |_) | |_| | |_| || (_) | | | |   |  __/| | | (_) | (_| || (__
 *     |_|    \__,_|___|_| |_|____/ \__,_|\__|\__\___/|_| |_____|_|   |_|  \___/ \__, (_\___|
 *                                                         |_____|               |___/
 */


#include "PushButton_interface.h"

void H_PushButton_Void_PushButtonInit(port_t Copy_u8PortName ,pin_num Copy_u8PinNum)
{
    MGPIO_vSetPinMode(Copy_u8PortName,Copy_u8PinNum,INPUT);
    MGPIO_vSetPinOutPutType(Copy_u8PortName,Copy_u8PinNum,PUSH_PULL);
    MGPIO_vSetPinOutSpeed(Copy_u8PortName,Copy_u8PinNum,LOW_SPEED);
    MGPIO_vSetPullType(Copy_u8PortName,Copy_u8PinNum,PUSHBUTTON_MODE);
}
u8   H_PushButton_U8_PushButtonRead(port_t Copy_u8PortName ,pin_num Copy_u8PinNum)
{
	u8 Local_u8_Reading = RELEASED;
	Local_u8_Reading = MGPIO_u8ReadData(Copy_u8PortName,Copy_u8PinNum);
	if(Local_u8_Reading == PRESSED)
	{
		Delay_vMsIn16MHz(PUSHBUTTON_DEBOUNCING_TIME);
		if(MGPIO_u8ReadData(Copy_u8PortName,Copy_u8PinNum) == PRESSED)
		{
			while(MGPIO_u8ReadData(Copy_u8PortName,Copy_u8PinNum) == PRESSED);
			Local_u8_Reading = PRESSED;
		}
	}
	return Local_u8_Reading;
}
