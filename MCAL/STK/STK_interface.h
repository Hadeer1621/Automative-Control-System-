/*========================================================================================
 *  @file    : STK_interface.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUN 2023
========================================================================================*/

/***
 *      ____ _____ _  __    _       _             __                  _
 *     / ___|_   _| |/ /   (_)_ __ | |_ ___ _ __ / _| __ _  ___ ___  | |__
 *     \___ \ | | | ' /    | | '_ \| __/ _ | '__| |_ / _` |/ __/ _ \ | '_ \
 *      ___) || | | . \    | | | | | ||  __| |  |  _| (_| | (_|  __/_| | | |
 *     |____/ |_| |_|\_____|_|_| |_|\__\___|_|  |_|  \__,_|\___\___(_|_| |_|
 *                    |_____|
 */

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H
/*===========   INCLUDE LIB   ===========*/
#include <STD_TYPES/STD_TYPES.h>

/*========================MACROS=========================*/
#define _MSTK_CLK_AHB             0U
#define _MSTK_CLK_AHB_8			  1U

#define _MODE_SINGLE              0U
#define _MODE_PERIODIC            1U
/*========================DECALARTION OF FUNCTION =========================*/

/*	1- Function Only Apply The Clock From Configer
 * ( AHB or( AHB/8---> 1MHZ) So 1 = 1Msec &
 * Disable SysTick Interrupt & Disa-ble SysTick  */
void MSTK_vInit(void);
/*  2- Function Take Count or Ticks So Timer Count Them And you Config
 * ( Tick = Time ) MSec  ---> Make Delay (Synchronous_Fun)
 * */
void MSTK_vBusyWait(u32 Copy_u32TicksNUM);
/* 	3- Function  Return The Remaining Time */
u32 MSTK_u32GetRemainingTime(void);
/*  4- Function  Return The Elapsed Time*/
u32 MSTK_u32GetElapsedTime(void);
/*  5- Function To Enable Interrupt */
void MSTK_vEnableINT(void);
/*  6- Function To Disable Interrupt */
void MSTK_vDisableINT(void);
/* - The Same Of Function (3) But Only Differant At ISR Will Not Mack Load And Value = 0 */
			 /*  Send Time To Clock it And What Will Call After Time Finsh   */						
		      /* Global Var Take Adress Of Function And
										After Time Out ISR Call The Global_Var Which Point To Function  
*/
void MSTK_vSetIntervalPeriodic(u32 Copy_u32TicksNUM , void (* ptr)(void));
/* 	- Function Asynchronous Take Tick And Start To Count Them , Give Flag And Work One Time ,
		And Give Me Function And i Will Resive In Pointer To Function To Call it After Counting Ticks .
		I Will Tick The Adress Of Function And Give It To Global Var ( Call back )  And ISR D o this Func */				
			/* Only One Time */	
void MSTK_vSetIntervalSingle(u32 Copy_u32TicksNUM , void (* ptr)(void));
/*  9-  Function Will Stop The Interval If It Was Periodic Or Single*/
void MSTK_voidStopInterval(void) ;


#endif

