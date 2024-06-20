/*========================================================================================
 *  @file    : ADC_Prog.c
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *         _    ____   ____     ____
 *        / \  |  _ \ / ___|   |  _ \ _ __ ___   __ _   ___
 *       / _ \ | | | | |       | |_) | '__/ _ \ / _` | / __|
 *      / ___ \| |_| | |___    |  __/| | | (_) | (_| || (__
 *     /_/   \_|____/ \________|_|   |_|  \___/ \__, (_\___|
 *                        |_____|               |___/
 */


/*============INCLUDES_LIB============*/
#include "ADC_Config.h"
#include "ADC_interface.h"
#include "ADC_Private.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "STD_TYPES.h"
/*===================================*/
/*============INCLUDES_MCAL============*/


/*==================GLOBAL_VARIABLES===================*/
#define _NULL   (void *)0

static ADC_Control_t  ADC_Control;

static void (* (SG_Arr_AdcMode [7]))(void);

/*==================Start Function===================*/
void M_AdcInit(AdcModeOperatin_t Copy_eAdcModeOperation )
{
	ADC_Control.ADC_Mode = _ADC_DISABLE_MODE ;
#if ADC_ENABLE_MODE  == ADC_ENABLE

	/* SELSECT THE ADC CLK */
	ADC_CCR &= 0xFF3FFFFF;
	ADC_CCR |= (ADC_PRESCALER<<16);

	/* */
	ADC_Control.SG_u8RegularSequenerIndex  =0 ;
	ADC_Control.SG_u8InjectedSequenerIndex =0 ;

	MADC1 -> CR1_.CR1.RES =  ADC_RESOLUTION ;     // ADC xbit reseloution
	MADC1 -> CR2_.CR2.ALIGN= ADC_DATA_ALIGMENT  ; // ADC_ alignment

	SG_Arr_AdcMode [0] = MAdc_vAdcInitMode;
	SG_Arr_AdcMode [1] = MAdc_vSingleRegulerMode;
	SG_Arr_AdcMode [2] = MAdc_vSingleRegulerContinuousMode;
	SG_Arr_AdcMode [3] = MAdc_vScanRegulerOnceMode;
	SG_Arr_AdcMode [4] = MAdc_v_ScanRegulerContinuousMode;
	SG_Arr_AdcMode [5] = MAdc_vScanInjectedOnce;
	SG_Arr_AdcMode [0]();
	ADC_Control.ADC_Mode = (u8)Copy_eAdcModeOperation;
	SG_Arr_AdcMode [0]();
	if ( Copy_eAdcModeOperation != 0)
	{
		SG_Arr_AdcMode [Copy_eAdcModeOperation]();
	}
	else
	{
		/*error*/
	}

	MADC1 -> CR2_.CR2.ADON = (1U);

#endif

}

/*==================End Function===================*/
/*==================Start Function===================*/
void MADC_vChangeModeOperation(AdcModeOperatin_t Copy_eAdcModeOperation)// review if i shoud wait
{
	if(ADC_Control.ADC_Mode != _ADC_DISABLE_MODE )
	{
		SG_Arr_AdcMode [0]();
		if ( Copy_eAdcModeOperation != 0)
		{
			SG_Arr_AdcMode [Copy_eAdcModeOperation]();
		}

	}

	else
	{
		/*error*/
	}
}


/*==================End Function===================*/
/*==================Start Function===================*/
void M_AdcEnable(void)
{

	MADC1 ->  CR2_.CR2.ADON =(1U);
}

/*==================End Function===================*/
/*==================Start Function===================*/
void M_AdcDisable(void)
{
	MADC1 ->  CR2_.CR2.ADON =(0U);
}

/*==================End Function===================*/
/*==================Start Function===================*/
/*Interrupt*/
void M_AdcStartConv(AdcMode_t u8_CopyAdcMode)
{
	switch(u8_CopyAdcMode){

	case ADC_MODE_REGULAR  : MADC1 -> CR2_.CR2.SWSTART   =  (1U) ; break;
	case ADC_MODE_INJECTED : MADC1 -> CR2_.CR2. JSWSTART =  (1U) ; break;
	default :													   break;

	}
}

/*==================End Function===================*/
/*==================Start Function===================*/

void M_Adc1StopConv(Channel_t Copy_u8ChannelType)
{
	MADC1 -> CR2_.CR2. ADON =  (0U) ;
}

/*==================End Function===================*/
/*==================Start Function===================*/
/* work on two case reguler scan ||cont Scan  active mode  */
RegularSequence_t  M_AdcRegular_Sequance(Channel_t Copy_eChannelType , RegularSequence_t Copy_eSequenceNum)
{

	// if -> check the mode :

	u8  L_u8_Index1, L_u8_Index2, L_u8SeqReturn =0xFF;

	if ( (Copy_eSequenceNum <= ADC_Control.SG_u8RegularSequenerIndex)&&(Copy_eSequenceNum >=0)&&(Copy_eSequenceNum <16))
	{
		L_u8_Index1 = 2 -( Copy_eSequenceNum /6) ;
		L_u8_Index2 =  Copy_eSequenceNum %6 ;
		MADC1 -> SQR[L_u8_Index1] &=  (~(((u32 )0x0000001F)<<(5* L_u8_Index2)));
		MADC1 -> SQR[L_u8_Index1] |= Copy_eChannelType << (5* L_u8_Index2);

		if  (Copy_eSequenceNum == ADC_Control.SG_u8RegularSequenerIndex)
		{
			ADC_Control.SG_u8RegularSequenerIndex ++;
			MADC1 -> SQR[0] &=  (~((u32 )0x00F00000));
			MADC1 -> SQR[0] |=  ((u32) Copy_eSequenceNum )<< 20 ;
		}
		L_u8SeqReturn = Copy_eSequenceNum; // if add or adjust is happen return the request ID
	}
	else{

		/*error */

	}
	// end the check of the mode
	return L_u8SeqReturn ;
}


/*==================End Function===================*/
/*==================Start Function===================*/


InjectedSequence_t  M_AdcInjected_Sequance(Channel_t Copy_eChannelType , InjectedSequence_t Copy_eSequenceNum)
{

	// if -> check the mode :


	u8  L_u8SeqReturn=0xFF;

	if ( (Copy_eSequenceNum <= ADC_Control.SG_u8InjectedSequenerIndex)&&(Copy_eSequenceNum >=0)&&(Copy_eSequenceNum <4))
	{

		MADC1 -> JSQR  &=  (~(((u32 )0x0000001F)<< (5 * (3-Copy_eSequenceNum))));
		MADC1 -> JSQR  |=  Copy_eChannelType    << (5 *(3- Copy_eSequenceNum));


		if  (Copy_eSequenceNum == ADC_Control.SG_u8InjectedSequenerIndex)
		{
			ADC_Control.SG_u8InjectedSequenerIndex ++;
			MADC1 -> JSQR &=  (((u32 )0xFFCFFFFF));
			MADC1 -> JSQR |=  ((u32) Copy_eSequenceNum )<< 20 ;

		}
		L_u8SeqReturn = Copy_eSequenceNum; // if add or adjust is happened return the request ID

	}
	else{

		/*error */

	}
	// end the check of the mode
	return L_u8SeqReturn ;
}

/*==================End Function===================*/
/*==================Start Function===================*/
void MADC_InjectedRead(u16 * Copy_u16Ptr)
{
	/*reguler single -DisCont by software*/
	//	MADC1 -> CR1_.CR1.JAUTO =  (0U) ;
	MADC1 -> CR2_.CR2.JSWSTART =  (1U) ;
	while (MADC1 ->SR_ .SR.JEOC == 0)
	{
	}
	//	MGPIO_vWriteData(0,0,1);

	*Copy_u16Ptr = MADC1 -> JDR[0];
	/*************************/
}


/*==================End Function===================*/
/*==================Start Function===================*/
void MADC_RegulerRead(u16 * Copy_u16Ptr)
{
	/*reguler single -DisCont by software*/
	MADC1 -> CR2_.CR2.SWSTART =  (1U);
	while (MADC1 ->SR_ .SR.EOC ==0);
	*Copy_u16Ptr = MADC1 -> DR;
}

/*==================End Function===================*/
/*==================Start Function===================*/
void MADC_RegulerScan(u16 * Copy_u16Ptr , u8* Copy_u8TotalConversion_nu)
{

	u8 L_u8Size=0;
	if ( ADC_Control.SG_u8RegularSequenerIndex > 0 &&  ADC_Control.SG_u8RegularSequenerIndex < 16 )
	{
		// once  scan

		if( ADC_Control.SG_u8RegularSequenerIndex >= *Copy_u8TotalConversion_nu )
		{
			MADC1 -> SQR[0] &=  (~((u32 )0x00F00000));
			MADC1 -> SQR[0] |=  ((u32) (*Copy_u8TotalConversion_nu-1 ))<< 20 ;

		}
		else
		{
			MADC1 -> SQR[0] &=  (~((u32 )0x00F00000));
			MADC1 -> SQR[0] |=  ((u32) (ADC_Control.SG_u8RegularSequenerIndex))<< 20 ;
			*Copy_u8TotalConversion_nu = ADC_Control.SG_u8RegularSequenerIndex;

		}
		MADC1 -> CR2_.CR2.SWSTART =  (1U) ;

		for (; L_u8Size < *Copy_u8TotalConversion_nu  ; L_u8Size ++)
		{
			while (MADC1 ->SR_ .SR.EOC ==0);
			Copy_u16Ptr [ L_u8Size]= MADC1 -> DR;
		}

	}

	else
	{
		/* error -> empty */
	}
}

/*==================End Function===================*/
/*==================Start Function===================*/
void MADCInjectedScan(u16 * Copy_u16Ptr, u8 Copy_u8TotalConversion_nu)
{
#if (1)
	u8 L_u8Size=0;
	if ( ADC_Control.SG_u8InjectedSequenerIndex > 0 &&  ADC_Control.SG_u8InjectedSequenerIndex< 4 )
	{
		// once  scan

		if( ADC_Control.SG_u8InjectedSequenerIndex <= Copy_u8TotalConversion_nu )
		{
			MADC1 -> JSQR &=  (~((u32 )0x00300000));
			MADC1 -> JSQR |=  ((u32) (Copy_u8TotalConversion_nu-1 ))<< 20 ;

		}
		MADC1 -> CR2_.CR2.JSWSTART =  (1U) ;
		for (; L_u8Size < Copy_u8TotalConversion_nu  ; L_u8Size ++)
		{

			while (MADC1 ->SR_ .SR.JEOC == 0);

			Copy_u16Ptr [ L_u8Size]= MADC1 -> JDR[L_u8Size];

		}

	}

	else
	{
		/* error -> empty */
	}
#endif



}


/*==================End Function===================*/
/*==================Start Function===================*/

void M_Adc1SetCallBack(void (* ptr)(void) , AdcIntId_t Copy_u8eSetCall)
{

	if(ptr != _NULL)
	{
		ADC_Control.ADC_SetCallBackArr[Copy_u8eSetCall] = ptr;
	}
	else
	{
	}
}


/*==================End Function===================*/
/*==================Start Function===================*/
/***************** static_function*********************/
void MAdc_vAdcInitMode(void)
{
	MADC1 -> CR1_.CR1.SCAN   = (0U) ;
	MADC1 -> CR2_.CR2.EOCS   = (0U) ;
	MADC1 -> CR2_.CR2.EXTEN  = (0U) ;
	MADC1 -> CR2_.CR2.CONT	 = (0U) ;
	MADC1 -> CR1_.CR1.DISCEN = (0U) ;
}

/*==================End Function===================*/
/*==================Start Function===================*/
static void MAdc_vSingleRegulerMode(void)
{

	MADC1 -> CR2_.CR2.EOCS   = (1U) ; 	 // GET FLAG at each channel conversion
	//MADC1 -> CR1_.CR1.SCAN   = (0U);    // disable scan mode
	//MADC1 ->  CR2_.CR2.EXTEN = (0U);	// disable external trigger
	//MADC1 -> CR2_.CR2.CONT	 = (0U);	//Continuous conversion Disable
	//MADC1 -> CR1_.CR1.DISCEN = (0U);    //Disable Discontinuous mode // important

}

/*==================End Function===================*/
/*==================Start Function===================*/

static void MAdc_vSingleRegulerContinuousMode(void)
{

	MADC1 -> CR2_.CR2.EOCS   = (1U) ;      // GET FLAG at each channel conversion
	MADC1 -> CR2_.CR2.CONT	 = (1U);     //Continuous conversion Enable
	//MADC1 -> CR1_.CR1.SCAN   = (0U);        // disable scan mode
	//MADC1 -> CR2_.CR2.EXTEN  = (0U);	  // DISable external trigger
	//MADC1 -> CR1_.CR1.DISCEN = (0U);     // Disable Discontinuous mode // important

}


/*==================End Function===================*/
/*==================Start Function===================*/

static void MAdc_vScanRegulerOnceMode(void)
{
	MADC1 -> CR1_.CR1.SCAN   =(1U);       // enable scan mode
	MADC1 -> CR2_.CR2.EOCS   =(1U) ;     // GET FLAG at each channel conversion
	//MADC1 -> CR2_.CR2.CONT	 =(0U);		//Continuous conversion Disable
	//MADC1 -> CR2_.CR2.EXTEN = (0U);	   // DISable external trigger
	//MADC1 -> CR1_.CR1.DISCEN =(0U);   // Disable Discontinuous mode // important
}

/*==================End Function===================*/
/*==================Start Function===================*/
static void MAdc_v_ScanRegulerContinuousMode(void)
{
	MADC1 -> CR1_.CR1.SCAN   =(1U);	// enable scan mode
	MADC1 -> CR2_.CR2.EOCS   =(1U) ;  // GET FLAG at each channel conversion
	MADC1 -> CR2_.CR2.CONT	 =(1U); // Enable Continuous conversion
	//MADC1 -> CR2_.CR2.EXTEN  =(0U);	  // Disable external trigger
	//MADC1 -> CR1_.CR1.DISCEN =(0U); // Disable Discontinuous mode // important
}


/*==================End Function===================*/
/*==================Start Function===================*/

static void MAdc_vScanInjectedOnce (void)
{
	MADC1 -> CR1_.CR1.SCAN   =(1U); 			// enable scan mode
}
