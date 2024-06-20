/*========================================================================================
 *  @file    : GPIO_Program.c
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : may 2023
========================================================================================*/

/**
 *       _____ _____ _____ ____             _____  _____   ____   _____ _____            __  __ 
 *      / ____|  __ \_   _/ __ \           |  __ \|  __ \ / __ \ / ____|  __ \     /\   |  \/  |
 *     | |  __| |__) || || |  | |  ______  | |__) | |__) | |  | | |  __| |__) |   /  \  | \  / |
 *     | | |_ |  ___/ | || |  | | |______| |  ___/|  _  /| |  | | | |_ |  _  /   / /\ \ | |\/| |
 *     | |__| | |    _| || |__| |          | |    | | \ \| |__| | |__| | | \ \  / ____ \| |  | |
 *      \_____|_|   |_____\____/           |_|    |_|  \_\\____/ \_____|_|  \_\/_/    \_\_|  |_|
 *                                                                                              
 *                                                                                              
 ********/

/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*============INCLUDES_LIB============*/
#include <MCAL/GPIO/GPIO_config.h>
#include <MCAL/GPIO/GPIO_interface.h>
#include <MCAL/GPIO/GPIO_private.h>
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "STD_TYPES.h"
/*===================================*/
/*============INCLUDES_MCAL============*/
/*===========  INCLUDE HAL   ===========*/
/*======================================*/	
/*===========  INCLUDEAPP   ===========*/
/*=====================================*/	




/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function Set The Mode Of Pin Mode Take 2Bits	
*			1- MODE_INPUT
*			2- MODE_OUTPUT
*			3- MODE_ALTF
*			4- MODE_ANALOG
*/
void MGPIO_vSetPinMode(port_t Copy_u8PortName ,pin_num Copy_u8PinNum ,pinmode_t Copy_u8Mode  )
{
	MGPIO(Copy_u8PortName)->MODER |= (u32) ( Copy_u8Mode << ( 2U* Copy_u8PinNum )) ;
}
/*====================================================   END_ FUNCTION   ====================================================*/





/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1) :
*								                         - OUTPUT_TYPE_PUSH_PULL
*								                         - OUTPUT_TYPE_OPEN_DRAIN
*/
void MGPIO_vSetPinOutPutType(port_t Copy_u8PortName ,pin_num Copy_u8PinNum ,outputType_t Copy_u8OutPutType  )
{
	MGPIO(Copy_u8PortName)->OTYPER |= (u32) ( Copy_u8OutPutType << ( Copy_u8PinNum )) ;
}
/*====================================================   END_ FUNCTION   ====================================================*/




/*====================================================   Start_FUNCTION   ====================================================*/
/* Function Set The Speed (LOW , Meduim , High ,VeryHaigh):		
*					                                 - OUTPUT_SPEED_LOW
*					                                 - OUTPUT_SPEED_MEDUIM
*					                                 - OUTPUT_SPEED_HIGH
*					                                 - OUTPUT_SPEED_VERY_HIGH
*/
void MGPIO_vSetPinOutSpeed(port_t Copy_u8PortName ,pin_num Copy_u8PinNum,OutSpeed_t Copy_u8OutSpeed )
{
	
	MGPIO(Copy_u8PortName)->OSPEEDR |= (u32) ( Copy_u8OutSpeed << ( 2U* Copy_u8PinNum )) ;
}
/*====================================================   END_ FUNCTION   ====================================================*/




/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function Set The PULL :			
*					      - PULL_OFF
*					      - PULL_UP
*					      - PULL_DOWN
*/
void MGPIO_vSetPullType(port_t Copy_u8PortName ,pin_num Copy_u8PinNum ,PullType_t Copy_u8PullType )
{
	MGPIO(Copy_u8PortName)->PUPDR   |= (u32) ( Copy_u8PullType << ( 2U* Copy_u8PinNum )) ;
	
}
/*====================================================   END_ FUNCTION   ====================================================*/



/*====================================================   Start_FUNCTION   ====================================================*/
/*		
 *Function To Read Data From IDR
 */

u8 MGPIO_u8ReadData(port_t Copy_u8PortName ,pin_num Copy_u8PinNum)
{
	return  GET_BIT(MGPIO(Copy_u8PortName)->IDR,Copy_u8PinNum ) ;
	
}
/*====================================================   END_ FUNCTION   ====================================================*/



/*====================================================   Start_FUNCTION   ====================================================*/
/*		
* Function To Write Data At ODR	Value :
*									  - LOW
*									  - HIGH
*									  - TOGL
*/
void MGPIO_vWriteData(port_t Copy_u8PortName ,pin_num Copy_u8PinNum,u8 Copy_u8State)
{
	if(Copy_u8State==HIGH)
	{
		SET_BIT(MGPIO(Copy_u8PortName) ->ODR,Copy_u8PinNum);
		
	}
	else if (Copy_u8State==TOGL)
	{
		TOG_BIT(MGPIO(Copy_u8PortName) ->ODR,Copy_u8PinNum);
	}
	else
	{
		CLR_BIT(MGPIO(Copy_u8PortName) ->ODR,Copy_u8PinNum);
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/



/*====================================================   Start_FUNCTION   ====================================================*/
/*
- Function to Lock pin :
				        1)Set Pin 
						2)Set Pin 16
						3)Wait bit 16 =high
*/
void MGPIO_vPinLock(port_t Copy_u8PortName ,pin_num Copy_u8PinNum )
{
	SET_BIT(MGPIO(Copy_u8PortName)->LCKR,Copy_u8PinNum );
	SET_BIT(MGPIO(Copy_u8PortName)->LCKR,_LUCKED_PIN );
	while(!(GET_BIT(MGPIO(Copy_u8PortName)->LCKR,_LUCKED_PIN)));
	
}
/*====================================================   END_ FUNCTION   ====================================================*/



/*====================================================   Start_FUNCTION   ====================================================*/
void MGPIO_vWriteDataDIR(port_t Copy_u8PortName ,pin_num Copy_u8PinNum,u8 Copy_u8State)
{
	if(Copy_u8State==HIGH)
	{
		MGPIO(Copy_u8PortName) ->BSRR = ( 1U << Copy_u8PinNum);
	}
	else
	{
		Copy_u8PinNum  +=16U ;
		MGPIO(Copy_u8PortName) ->BSRR = ( 1U << Copy_u8PinNum);
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/



/*====================================================   Start_FUNCTION   ====================================================*/

void MGPIO_vPortOutputByte(port_t Copy_u8PortName, u32 Copy_u32Data, u8 Copy_u8StartBit,u8 Copy_u8EndBit)
{
	 u8 i;
	 u32 Copy_32DataBit=1;
	 Copy_u8EndBit-=Copy_u8StartBit;
	for (i = 0 ; i < Copy_u8EndBit ; i++)
	{
		Copy_32DataBit = (Copy_32DataBit<<1) +1;
	}
		/* In ODR  shift ( 0000 0000 ) to the start bit & shift data to the start bit  */
	MGPIO(Copy_u8PortName) ->ODR = (MGPIO(Copy_u8PortName) ->ODR & ~(Copy_32DataBit <<Copy_u8StartBit))|(Copy_u32Data<<Copy_u8StartBit);
}


/*====================================================   END_ FUNCTION   ====================================================*/
void GPIO_vSetAlternateFunction(port_t Copy_u8PortName,pin_num Copy_u8PinNum,GPIO_AF Copy_u8AF)
{
			MGPIO(Copy_u8PortName)->AFRL[(Copy_u8PinNum/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8PinNum%8U)));
}
