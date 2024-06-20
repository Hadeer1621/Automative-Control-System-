/*========================================================================================
 *  @file    : NVIC_Program.c
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : may 2023
========================================================================================*/
/***
 *      _   ___     _____ ____
 *     | \ | \ \   / |_ _/ ___|     _ __  _ __ ___   __ _   ___
 *     |  \| |\ \ / / | | |        | '_ \| '__/ _ \ / _` | / __|
 *     | |\  | \ V /  | | |___     | |_) | | | (_) | (_| || (__
 *     |_| \_|  \_/  |___\_________| .__/|_|  \___/ \__, (_\___|
 *                           |_____|_|              |___/
 */


/*===========   INCLUDE LIB   ===========*/
/*============INCLUDES_LIB============*/
#include "NVIC_confg.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "STD_TYPES.h"
/*===================================*/
/*============INCLUDES_MCAL============*/

/*======================================*/
/*=======================================*/

/*==============================IMPELEMEMTATIOM_OF_FUNCTION===================================*/

/*======================================================================*/
/*===============================   Start_FUNCTION   =====================================*/
/*_Function_Set_Enable_
 * Copy_tIRQ /32 to get number of REG Index
 * set Copy_tIRQ but reminder it 32
 * */
void MNVIC_vEnableIRQ(IRQn_t Copy_tIRQ)
{
	NVIC->ISER[(Copy_tIRQ/32)] = 1U<<(Copy_tIRQ%32);
}
/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/
/*_Function_Clear_Enable_*/
void MNVIC_vDisableIRQ(IRQn_t Copy_tIRQ)
{
	NVIC->ICER[(Copy_tIRQ/32)] = 1U<<(Copy_tIRQ%32);
}

/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/
u32  MNVIC_u32GetPendingIRQ(IRQn_t Copy_tIRQ)
{
	return GET_BIT(NVIC->ISPR[(Copy_tIRQ/32)],(Copy_tIRQ%32));
}

/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/

/*_Function_Set_Pending_
 *
 *
 * */
void MNVIC_vSetPendingIRQ(IRQn_t Copy_tIRQ)
{
	NVIC->ISPR[(Copy_tIRQ/32)] = 1U<<(Copy_tIRQ%32);
}
/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/
/*_Function_Clear_Pending_*/
void MNVIC_vClearPendingIRQ(IRQn_t Copy_tIRQ)
{
	NVIC->ICPR[(Copy_tIRQ/32)] = 1U<<(Copy_tIRQ%32);
}
/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/
/*_Function_Read_Active_Flag_*/
u32  MNVIC_u32GetActive(IRQn_t Copy_tIRQ)
{
	return GET_BIT(NVIC->IABR[(Copy_tIRQ / 32)],(Copy_tIRQ % 32));
}
/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/
/*_Function_Set_Priority_Grouping_
 * you must write 0x05FA to the VECTKEY field
 *  Interrupt priority grouping [Num of group && num of sub]
 * */
void MNVIC_vSetPriority(IRQn_t Copy_tIRQ, u8 Group_P,u8 Sub_P)
{
	AIRCR = 0x05FA0300 + (256*PRIGROUP) ;
	NVIC->IPR[Copy_tIRQ]=(Group_P<<PRIGROUP |Sub_P)<<4;
}
