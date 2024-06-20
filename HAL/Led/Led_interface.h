/*========================================================================================
 *  @file    : LED_Interface.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *      _     _____ ____     ___       _             __                  _
 *     | |   | ____|  _ \   |_ _|_ __ | |_ ___ _ __ / _| __ _  ___ ___  | |__
 *     | |   |  _| | | | |   | || '_ \| __/ _ | '__| |_ / _` |/ __/ _ \ | '_ \
 *     | |___| |___| |_| |   | || | | | ||  __| |  |  _| (_| | (_|  __/_| | | |
 *     |_____|_____|________|___|_| |_|\__\___|_|  |_|  \__,_|\___\___(_|_| |_|
 *                     |_____|
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

/********************************************************_INCLUDES_******************************/
/*===========   INCLUDE LIB   ===========*/
#include "Led_Config.h"
#include "GPIO_interface.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "STD_TYPES.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
/*******************************************************_PROTOTYPES_*****************************/
void H_Led_Void_LedInit(port_t Copy_u8PortName ,pin_num Copy_u8PinNum);
void H_Led_Void_LedOn(port_t Copy_u8PortName ,pin_num Copy_u8PinNum);
void H_Led_Void_LedOff(port_t Copy_u8PortName ,pin_num Copy_u8PinNum);
void H_Led_Void_LedTog(port_t Copy_u8PortName ,pin_num Copy_u8PinNum);
void H_Led_Void_LedBlink(port_t Copy_u8PortName ,pin_num Copy_u8PinNum);
#endif /* HAL_LED_LED_INTERFACE_H_ */
