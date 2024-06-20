/*========================================================================================
 *  @file    : UART_prog.c
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUN 2023
========================================================================================*/

/***
 *      _   _   _    ____ _____
 *     | | | | / \  |  _ |_   _|   _ __  _ __ ___   __ _   ___
 *     | | | |/ _ \ | |_) || |    | '_ \| '__/ _ \ / _` | / __|
 *     | |_| / ___ \|  _ < | |    | |_) | | | (_) | (_| || (__
 *      \___/_/   \_|_| \_\|______| .__/|_|  \___/ \__, (_\___|
 *                          |_____|_|              |___/
 */

/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*============INCLUDES_LIB============*/
#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "STD_TYPES.h"
/*===================================*/
/*============INCLUDES_MCAL============*/


/*===========GLOBAL_VARIABLES===========================*/
static void (*UART_CALLBACK)(void)=NULL;
/*====================================================*/



/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/

void UART6_vInit(void)
{
	/****************************************/
	UART6->CR1=0;
	/*Enable UART*/
	UART6->CR1 |= USART_CR1_UE;
	/*Mode*/
	/*Check Mode and apply Configuration*/
	/****************************************/
	/*Parity Mode*/
#if UART6_PARITY_MODE == UART_PARITY_DISABLE
	UART6->CR1 &=~ USART_CR1_PCE;
#elif UART6_PARITY_MODE == UART_PARITY_ODD
	UART6->CR1.PCE=1;
	UART6->CR1.PS=1;
#elif UART6_PARITY_MODE == UART_PARITY_EVEN
	UART6->CR1.PCE=1;
	UART6->CR1.PS=0;
#endif
	/****************************************/
	/*Stop Bits*/
#if UART6_STOP_BITS		== ONE_STOP_BIT
	UART6->CR2 &=~ USART_CR2_STOP;
#elif UART6_STOP_BITS		== HALF_STOP_BIT
	UART6->CR2.STOP=1;
#elif UART6_STOP_BITS		== ONE_HALF_STOP_BITS
	UART6->CR2.STOP=3;
#elif UART6_STOP_BITS		== TWO_STOP_BITS
	UART6->CR2.STOP=2;
#endif
	/****************************************/
	/*Character size*/
#if UART6_WORD		==	EIGHT_DATA_BITS
	//UART6->CR1.M=0;
#elif UART6_WORD		==	NINE_DATA_BITS
	UART6->CR1.M=1;
#endif

	/*Baud Rate*/
	/*9600*/
	UART6->BRR = 0;
	UART6->BRR = (0x3)| (0x68<<4);
	/****************************************/
	/*Enable Tx*/
	UART6->CR1|=USART_CR1_TE;
	/*Enable Rx*/
	UART6->CR1|=USART_CR1_RE;
	//UART6->CR1|=1<<5;

}

/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/
u8 UART6_vReceive(void)
{
	u8 L_u16ReceiveData;

	/*Wait till the transmisson complete*/
		while(!(UART6->SR & USART_SR_RXNE));
		L_u16ReceiveData = UART6->DR;
		/*return data*/
		return L_u16ReceiveData;
}


/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/
void UART6_Callback(void (*pAppParamter)(void))
{
	/*Check if there is a call back function*/
	if(pAppParamter != NULL)
	{
		/*Callback*/
		UART_CALLBACK = pAppParamter;
	}

}
/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/
void USART6_IRQHandler(void)
{
	if(UART_CALLBACK != NULL)
	{
		UART_CALLBACK();
	}
}

