/*========================================================================================
 *  @file    : ADC_interface.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *         _    ____   ____     _       _             __                  _
 *        / \  |  _ \ / ___|   (_)_ __ | |_ ___ _ __ / _| __ _  ___ ___  | |__
 *       / _ \ | | | | |       | | '_ \| __/ _ | '__| |_ / _` |/ __/ _ \ | '_ \
 *      / ___ \| |_| | |___    | | | | | ||  __| |  |  _| (_| | (_|  __/_| | | |
 *     /_/   \_|____/ \________|_|_| |_|\__\___|_|  |_|  \__,_|\___\___(_|_| |_|
 *                        |_____|
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

/*==================================== 
			-> MACROS_ADC 
=====================================*/

#define _12_BIT_RESOLUTION_ADC   ( 0U )
#define _10_BIT_RESOLUTION_ADC   ( 1U )
#define  _8_BIT_RESOLUTION_ADC   ( 2U )
#define  _6_BIT_RESOLUTION_ADC   ( 3U )

#define ADC_ENABLE   (1U)
#define ADC_DISABLE  (0U)

#define ADC_LEFT	( 1U )
#define ADC_RIGHT	( 0U )


/*==================================== 
			-> ENUM TO CHANNELS ADC
=====================================*/
typedef enum
{
	CHANNEL_0 = (0U),
	CHANNEL_1		,
	CHANNEL_2       ,
	CHANNEL_3       ,
	CHANNEL_4       ,
	CHANNEL_5       ,
	CHANNEL_6       ,
	CHANNEL_7       ,
	CHANNEL_8       ,
	CHANNEL_9       ,
	CHANNEL_10      ,
	CHANNEL_11      ,
	CHANNEL_12      ,
	CHANNEL_13      ,
	CHANNEL_14      ,
	CHANNEL_15      ,
	CHANNEL_16      ,
	CHANNEL_17      ,
	CHANNEL_18

}Channel_t;
 /*==================================== 
	-> ENUM TO REGULAR_CONVERSION_ID
=====================================*/
typedef enum
{
	Regular_SEQUENCE_ID_0 = (0U),
	Regular_SEQUENCE_ID_1		,
	Regular_SEQUENCE_ID_2       ,
	Regular_SEQUENCE_ID_3       ,
	Regular_SEQUENCE_ID_4       ,
	Regular_SEQUENCE_ID_5       ,
	Regular_SEQUENCE_ID_6       ,
	Regular_SEQUENCE_ID_7       ,
	Regular_SEQUENCE_ID_8       ,
	Regular_SEQUENCE_ID_9       ,
	Regular_SEQUENCE_ID_10      ,
	Regular_SEQUENCE_ID_11      ,
	Regular_SEQUENCE_ID_12      ,
	Regular_SEQUENCE_ID_13      ,
	Regular_SEQUENCE_ID_14      ,
	Regular_SEQUENCE_ID_15      ,
	Regular_SEQUENCE_ID_16


}RegularSequence_t;

 /*==================================== 
	-> ENUM TO  INJECTED_CONVERSION_ID
=====================================*/

typedef enum
{
	INJECTED_SEQUENCE_ID_0 = (0U),
	INJECTED_SEQUENCE_ID_1		 ,
	INJECTED_SEQUENCE_ID_2       ,
	INJECTED_SEQUENCE_ID_3       ,
	INJECTED_SEQUENCE_ID_4

} InjectedSequence_t;
 /*==================================== 
	-> ENUM TO ADC MODES OPERATIONS
=====================================*/

typedef enum
{
	_ADC_INJECTED_SINGLE_MODE 	 = (0U) ,
	_ADC_REGULAR_SINGLE_MODE    	    , 
	_ADC_SINGLE_CONTINUS_MODE           ,
	_ADC_REGULAR_SCAN_ONCE_MODE         , 
	_ADC_REGULAR_SCAN_CONTIUS_MODE		,
	_ADC_INJECTED_SCAN_ONCE_MODE		,
	_ADC_DISABLE_MODE		 = (15)

}AdcModeOperatin_t;

 /*============================================================= 
	-> ENUM TO ADC MODES (REGULAR | INJECTED ) 
=================================================================*/

typedef enum
{
	ADC_MODE_REGULAR  = (0U),
	ADC_MODE_INJECTED
}AdcMode_t;

 /*========================================================= 
	-> ENUM TO ADC MODES (REGULAR | INJECTED )INTRRUPTS
============================================================*/
typedef enum
{
	ADC_REGULAR_INT  = (0U),
	ADC_INJECTED_INT
}AdcIntId_t;

 /*==================================== 
	-> ENUM TO ADC PRESCALER
=====================================*/

typedef enum
{
	_ADC_PRESCALER_2  =(0U) ,
	_ADC_PRESCALER_4  		,
	_ADC_PRESCALER_6  		,
	_ADC_PRESCALER_8

}Adc_PRescaler_t;

 /*================================================== 
	-> DECLARATION OF FUNCTIONS ADC 
=====================================================*/

void M_AdcInit(AdcModeOperatin_t Copy_eAdcModeOperation );
// void MADC_vChangeModeOperation(AdcModeOperatin_t Copy_eAdcModeOperation);
void M_AdcEnable(void);
void M_AdcDisable(void);
void M_AdcStartConv(AdcMode_t u8_CopyAdcMode);
void M_Adc1StopConv(Channel_t Copy_u8ChannelType);

RegularSequence_t  M_AdcRegular_Sequance(Channel_t Copy_eChannelType ,   RegularSequence_t Copy_eSequenceNum);
InjectedSequence_t  M_AdcInjected_Sequance(Channel_t Copy_eChannelType , InjectedSequence_t Copy_eSequenceNum);
void MADC_InjectedRead(u16 * Copy_u16Ptr);
void MADC_RegulerRead(u16 * Copy_u16Ptr);
void MADC_RegulerScan(u16 * Copy_u16Ptr , u8* Copy_u8TotalConversion_nu);
void MADCInjectedScan(u16 * Copy_u16Ptr, u8 Copy_u8TotalConversion_nu);



void M_Adc1SetCallBack(void (* ptr)(void) , AdcIntId_t Copy_u8eSetCall);




#endif /* MCAL_ADC_ADC_H_ */
