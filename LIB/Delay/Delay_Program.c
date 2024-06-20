/*========================================================================================
 *  @file    : Delay.Program.c
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    :  may 2023
========================================================================================*/


/*============= INCLUDE LIB ==============*/
#include <BIT_MATH/BIT_MATH.h>
#include <Delay/Delay_interface.h>
#include <STD_TYPES/STD_TYPES.h>
/*========================================*/	
/*============= INCLUDE HAL ==============*/ 
			
/*========================================*/





/*======================================================== Start_FUNCTION  ========================================================*/
/*
 *		Function To Delay By Milliseconds ( 16MHz CPU CLK )
 */

extern void Delay_vMsIn16MHz(u16 copy_u16CountNum)
{
	volatile u16 u16Local_Count1 ;
	volatile u16 u16Local_Count2 ;
	u16 L_Counter = 3180;
	for(u16Local_Count1 = 0 ; u16Local_Count1 < copy_u16CountNum  ; u16Local_Count1++ )
	for(u16Local_Count2  = 0 ; u16Local_Count2  < L_Counter  ; u16Local_Count2 ++ )
	{} // Do nothing for 1 ms
}



/*======================================================== END_ FUNCTION   ========================================================*/
/*======================================================== Start_FUNCTION  ========================================================*/
/*
*		Function To Delay By Microseconds ( 16MHz CPU CLK )
*/

extern void Delay_vUsIn16MHzint (u16 copy_u16CountNum)
{
	volatile u16 u16Local_Count1 ;
	volatile u16 u16Local_Count2 ;
	u16 L_Counter = 3;
	for(u16Local_Count1 = 0 ; u16Local_Count1 < copy_u16CountNum  ; u16Local_Count1++ )
	for(u16Local_Count2  = 0 ; u16Local_Count2  <  L_Counter  ; u16Local_Count2 ++ )
	{} // Do nothing for 1 ms
}



/*======================================================== END_ FUNCTION   ========================================================*/
