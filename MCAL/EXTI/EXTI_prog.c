/*========================================================================================
 *  @file    : EXTINT_Prog.c
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : may 2023
========================================================================================*/

/***
 *      ________   _________ _____            _____  _____   ____   _____ 
 *     |  ____\ \ / /__   __|_   _|          |  __ \|  __ \ / __ \ / ____|
 *     | |__   \ V /   | |    | |    ______  | |__) | |__) | |  | | |  __ 
 *     |  __|   > <    | |    | |   |______| |  ___/|  _  /| |  | | | |_ |
 *     | |____ / . \   | |   _| |_           | |    | | \ \| |__| | |__| |
 *     |______/_/ \_\  |_|  |_____|          |_|    |_|  \_\\____/ \_____|
 *                                                                        
 *                                                                        
 */

/*============INCLUDES_LIB============*/
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "SYSCFG_private.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "STD_TYPES.h"
/*===================================*/
/*============INCLUDES_MCAL============*/
/*======================================*/
/*======================================*/
/*=============GLOBAL_VARIABLE_=========================*/
void (*EXTI_CallBack[16])(void)= {NULL};


/*====================   END_ FUNCTION   =============================*/
/*==================   Start_FUNCTION   =============================*/
void MEXTI_vEnableLine(EXTI_LINE_t Copy_eLineNum)
{
	SET_BIT(EXTI->IMR,Copy_eLineNum);
}
/*====================   END_ FUNCTION   =============================*/
/*==================   Start_FUNCTION   =============================*/
void MEXTI_vDisableLine(EXTI_LINE_t Copy_eLineNum)
{
	CLR_BIT(EXTI->IMR,Copy_eLineNum);
}
/*====================   END_ FUNCTION   =============================*/
/*==================   Start_FUNCTION   =============================*/
void MEXTI_vEventTrigger(EXTI_LINE_t Copy_eLineNum,EXTI_TRIG_t Copy_eEventTrig)
{
	switch (Copy_eEventTrig)
	{
	
		case EXTI_FALLING   :  SET_BIT(EXTI->FTSR,Copy_eLineNum); 
                               CLR_BIT(EXTI->RTSR,Copy_eLineNum);
        break;
		case EXTI_RAISING   :  SET_BIT(EXTI->RTSR,Copy_eLineNum);
                               CLR_BIT(EXTI->FTSR,Copy_eLineNum);
        break;
		case EXTI_ON_CHANGE :  SET_BIT(EXTI->FTSR,Copy_eLineNum);
                               SET_BIT(EXTI->RTSR,Copy_eLineNum);
        break;
	}
}

/*====================   END_ FUNCTION   =============================*/
/*==================   Start_FUNCTION   =============================*/
void MEXTI_vSwiTrigger(EXTI_LINE_t Copy_eLineNum)
{
	SET_BIT(EXTI-> SWIER,Copy_eLineNum);
}
/*====================   END_ FUNCTION   =============================*/
/*==================   Start_FUNCTION   =============================*/
u8 MEXTI_vGetPending(EXTI_LINE_t Copy_eLineNum)
{
	u8 L_u8GetPending=0U;
	
	L_u8GetPending = GET_BIT(EXTI-> PR,Copy_eLineNum);
	
	
	return L_u8GetPending;
}
/*====================   END_ FUNCTION   =============================*/
/*==================   Start_FUNCTION   =============================*/
void MEXTI_vPortConfig(EXTI_PORT_Num Copy_ePortNum,EXTI_LINE_t Copy_eLineNum)
{
	SYSCFG->EXTICR[(Copy_eLineNum/4)]|=(Copy_ePortNum <<(4U * (Copy_eLineNum % 4) ));
/*
	u8 L_LineNum=Copy_eLineNum;
	if(L_LineNum<=3)
	{
	   SYSCFG->EXTICR[0]|=((Copy_ePortNum<<0)<<(4U * L_LineNum ));
	}
	else if(L_LineNum<=7)
	{
		L_LineNum-=4;
		SYSCFG->EXTICR[1]|=((Copy_ePortNum<<0)<<(4U * L_LineNum ));
	}
	else if(L_LineNum<=11)
	{
		L_LineNum-=8;
		SYSCFG->EXTICR[2]|=((Copy_ePortNum<<0)<<(4U * L_LineNum ));
	}
	else if(L_LineNum<=15)
	{
		L_LineNum-=12;
		SYSCFG->EXTICR[3]|=((Copy_ePortNum<<0)<<(4U * L_LineNum ));
	}
	else 
	{
		//return error
	}
*/
}
/*====================   END_ FUNCTION   =============================*/
/*==================   Start_FUNCTION   =============================*/

void MEXTI_vSetCallBack(u8 copy_eNum,void (*Ptr)(void))
{
	EXTI_CallBack[copy_eNum]=Ptr;
}

/*====================   END_ FUNCTION   =============================*/
/*==================   Start_FUNCTION   =============================*/
 void EXTI0_IRQHandler(void)
{
	SET_BIT(EXTI->PR,0U);// clr flag
	EXTI_CallBack[0]();
}




 void EXTI1_IRQHandler(void)
{
	SET_BIT(EXTI->PR,1U);// clr flag
	EXTI_CallBack[1]();
}


 void EXTI2_IRQHandler(void)
{
	SET_BIT(EXTI->PR,2U);// clr flag
	EXTI_CallBack[2]();
}




 void EXTI3_IRQHandler(void)
{
	SET_BIT(EXTI->PR,3U);// clr flag
	EXTI_CallBack[3]();
}




 void EXTI4_IRQHandler(void)
{
	SET_BIT(EXTI->PR,4U);// clr flag
	EXTI_CallBack[4]();
}




 void EXTI9_5_IRQHandler(void)
{
	SET_BIT(EXTI->PR,5U);// clr flag
	SET_BIT(EXTI->PR,6U);// clr flag
	SET_BIT(EXTI->PR,7U);// clr flag
	SET_BIT(EXTI->PR,8U);// clr flag
	SET_BIT(EXTI->PR,9U);// clr flag

	EXTI_CallBack[5]();
	EXTI_CallBack[6]();
	EXTI_CallBack[7]();
	EXTI_CallBack[8]();
	EXTI_CallBack[9]();

}




 void EXTI15_10_IRQHandler(void)
{
	SET_BIT(EXTI->PR,10U);// clr flag
	SET_BIT(EXTI->PR,11U);// clr flag
	SET_BIT(EXTI->PR,12U);// clr flag
	SET_BIT(EXTI->PR,13U);// clr flag
	SET_BIT(EXTI->PR,14U);// clr flag
	SET_BIT(EXTI->PR,15U);// clr flag


	EXTI_CallBack[10]();
	EXTI_CallBack[11]();
	EXTI_CallBack[12]();
	EXTI_CallBack[13]();
	EXTI_CallBack[14]();
	EXTI_CallBack[15]();

}





