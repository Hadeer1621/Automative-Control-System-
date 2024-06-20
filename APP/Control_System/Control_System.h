/*========================================================================================
 *  @file    : Control_System.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    :  AUG 2023
========================================================================================*/
/***
 *       ____            _             _     ____            _                   _
 *      / ___|___  _ __ | |_ _ __ ___ | |   / ___| _   _ ___| |_ ___ _ __ ___   | |__
 *     | |   / _ \| '_ \| __| '__/ _ \| |   \___ \| | | / __| __/ _ | '_ ` _ \  | '_ \
 *     | |__| (_) | | | | |_| | | (_) | |    ___) | |_| \__ | ||  __| | | | | |_| | | |
 *      \____\___/|_| |_|\__|_|  \___/|_____|____/ \__, |___/\__\___|_| |_| |_(_|_| |_|
 *                                     |_____|     |___/
 */


#ifndef _APP_CONTROL_SYSTEM_H_
#define _APP_CONTROL_SYSTEM_H_

/*============INCLUDES_LIB============*/
#include "DC_Motor_interface.h"
#include "Lcd_interface.h"
#include "Led_interface.h"
#include "PushButton_interface.h"
#include "TFT_interface.h"
#include "ADC_interface.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"
#include "UART_interface.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "STD_TYPES.h"
/*===================================*/
/*============INCLUDES_MCAL============*/

/*=============================================================================================*/
				/*============DECLARATION_FUNCTIONS============*/

void ACtrlSys_init(void);
void ACtrlSys_Start(void);
void ACtrlSys_vDisplay(void);
void ACtrlSys_TirePressureCheck(void);
void ACtrlSys_BattryLevelCheck(void);
void ACtrlSys_AirCondCheck(void);
void ACtrlSys_EngineStart(void);
void ACtrlSys_DoorLocker(void);
void ACtrlSys_CloseSystem(void);





#endif /* _APP_CONTROL_SYSTEM_H_ */
