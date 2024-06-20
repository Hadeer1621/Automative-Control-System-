/*========================================================================================
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *      ____            _     ____        _   _                  _       _             __                  _
 *     |  _ \ _   _ ___| |__ | __ ) _   _| |_| |_ ___  _ __     (_)_ __ | |_ ___ _ __ / _| __ _  ___ ___  | |__
 *     | |_) | | | / __| '_ \|  _ \| | | | __| __/ _ \| '_ \    | | '_ \| __/ _ | '__| |_ / _` |/ __/ _ \ | '_ \
 *     |  __/| |_| \__ | | | | |_) | |_| | |_| || (_) | | | |   | | | | | ||  __| |  |  _| (_| | (_|  __/_| | | |
 *     |_|    \__,_|___|_| |_|____/ \__,_|\__|\__\___/|_| |_____|_|_| |_|\__\___|_|  |_|  \__,_|\___\___(_|_| |_|
 *                                                         |_____|
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_

/********************************************************_INCLUDES_******************************/
/*===========   INCLUDE LIB   ===========*/
#include "PushButton_Config.h"
#include "GPIO_interface.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "STD_TYPES.h"
/*======================================*/
/*********************************************************_MACROS_*******************************/

#define ACTIVE_LOW      1
#define ACTIVE_HIGH     2

#if   PUSHBUTTON_MODE   ==   ACTIVE_LOW
#define PRESSED         0
#define RELEASED        1
#elif PUSHBUTTON_MODE   ==   ACTIVE_HIGH
#define PRESSED         1
#define RELEASED        0
#endif
/*******************************************************_PROTOTYPES_*****************************/
void H_PushButton_Void_PushButtonInit(port_t Copy_u8PortName ,pin_num Copy_u8PinNum);
u8   H_PushButton_U8_PushButtonRead(port_t Copy_u8PortName ,pin_num Copy_u8PinNum);
#endif /* HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_ */
