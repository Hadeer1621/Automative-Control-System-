/*========================================================================================
 *  @file    : SPI_prog.c
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUN 2023
========================================================================================*/

/***
 *      ____  ____ ___
 *     / ___||  _ |_ _|     _ __  _ __ ___   __ _   ___
 *     \___ \| |_) | |     | '_ \| '__/ _ \ / _` | / __|
 *      ___) |  __/| |     | |_) | | | (_) | (_| || (__
 *     |____/|_|  |________| .__/|_|  \___/ \__, (_\___|
 *                   |_____|_|              |___/
 */

/*============INCLUDES_LIB============*/
#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "STD_TYPES.h"
/*===================================*/
/*============INCLUDES_MCAL============*/
/*======================================*/
/*======================================*/

/*===========GLOBAL_VARIABLE===========================*/
void (* MSPI3_CallBack)(void) = NULL ;

/*======================================*/
/*======================================*/


/*======================================================================*/
/*===============================   Start_FUNCTION   =====================================*/

void SPI_vInit(void)
{
#if SPI1_ENABLED  == ENABLED

	SPI1->CR1.BIDIMODE = SPI1_BIDIMODE_MODE;
	SPI1->CR1.BIDIOE   = SPI1_BIDIOE_MODE  ;
	SPI1->CR1.CRCEN    = SPI1_CRC_EN       ;
	SPI1->CR1.CRCNEXT  = SPI1_CRC_NEXT     ;
	SPI1->CR1.DFF      = SPI1_DATA_FRAME   ;
	SPI1->CR1.RXONLY   = SPI1_RX_ONLY      ;
	SPI1->CR1.SSM      = SPI1_SSM_MODE     ;
	SPI1->CR1.SSI      = SPI1_SSI_MODE     ;
	SPI1->CR1.LSBFIRST = SPI1_LSB_FIRST    ;
	SPI1->CR1.BR       = SPI1_BR_CONTROL   ;
	SPI1->CR1.MSTR     = SPI1_MSTR_SELECT  ;
	SPI1->CR1.CPOL     = SPI1_CPOL_CONTROL ;
	SPI1->CR1.CPHA     = SPI1_CPHA_CONTROL ;
	SPI1->CR1.SPE      = SPI_ENABLE        ;
#elif SPI1_ENABLED  == DISABLED
	//   SPI1->CR1.SPE= SPI_DISABLE   ;
#endif

#if SPI2_ENABLED  == ENABLED
	SPI2->CR1.BIDIMODE = SPI2_BIDIMODE_MODE;
	SPI2->CR1.BIDIOE   = SPI2_BIDIOE_MODE  ;
	SPI2->CR1.CRCEN    = SPI2_CRC_EN       ;
	SPI2->CR1.CRCNEXT  = SPI2_CRC_NEXT     ;
	SPI2->CR1.DFF      = SPI2_DATA_FRAME   ;
	SPI2->CR1.RXONLY   = SPI2_RX_ONLY      ;
	SPI2->CR1.SSM      = SPI2_SSM_MODE     ;
	SPI2->CR1.SSI      = SPI2_SSI_MODE     ;
	SPI2->CR1.LSBFIRST = SPI2_LSB_FIRST    ;
	SPI2->CR1.BR       = SPI2_BR_CONTROL   ;
	SPI2->CR1.MSTR     = SPI2_MSTR_SELECT  ;
	SPI2->CR1.CPOL     = SPI2_CPOL_CONTROL ;
	SPI2->CR1.CPHA     = SPI2_CPHA_CONTROL ;
	SPI2->CR1.SPE      = SPI2_SPI_E        ;
#elif  SPI2_ENABLED  == DISABLED
	//    SPI2->CR1.SPE= SPI_DISABLE   ;
#endif

#if SPI3_ENABLED  == ENABLED
	SPI3->CR1.BIDIMODE = SPI3_BIDIMODE_MODE;
	SPI3->CR1.BIDIOE   = SPI3_BIDIOE_MODE  ;
	SPI3->CR1.CRCEN    = SPI3_CRC_EN       ;
	SPI3->CR1.CRCNEXT  = SPI3_CRC_NEXT     ;
	SPI3->CR1.DFF      = SPI3_DATA_FRAME   ;
	SPI3->CR1.RXONLY   = SPI3_RX_ONLY      ;
	SPI3->CR1.SSM      = SPI3_SSM_MODE     ;
	SPI3->CR1.SSI      = SPI3_SSI_MODE     ;
	SPI3->CR1.LSBFIRST = SPI3_LSB_FIRST    ;
	SPI3->CR1.BR       = SPI3_BR_CONTROL   ;
	SPI3->CR1.MSTR     = SPI3_MSTR_SELECT  ;
	SPI3->CR1.CPOL     = SPI3_CPOL_CONTROL ;
	SPI3->CR1.CPHA     = SPI3_CPHA_CONTROL ;
	SPI3->CR1.SPE      = SPI3_SPI_E        ;
	//SPI3->CR2|=(1<<7); //to enable interrupt

#elif  SPI3_ENABLED  == DISABLED
	SPI3->CR1.SPE= SPI_DISABLE   ;
#endif

#if SPI4_ENABLED  == ENABLED
	SPI4->CR1.BIDIMODE = SPI4_BIDIMODE_MODE;
	SPI4->CR1.BIDIOE   = SPI4_BIDIOE_MODE  ;
	SPI4->CR1.CRCEN    = SPI4_CRC_EN       ;
	SPI4->CR1.CRCNEXT  = SPI4_CRC_NEXT     ;
	SPI4->CR1.DFF      = SPI4_DATA_FRAME   ;
	SPI4->CR1.RXONLY   = SPI4_RX_ONLY      ;
	SPI4->CR1.SSM      = SPI4_SSM_MODE     ;
	SPI4->CR1.SSI      = SPI4_SSI_MODE     ;
	SPI4->CR1.LSBFIRST = SPI4_LSB_FIRST    ;
	SPI4->CR1.BR       = SPI4_BR_CONTROL   ;
	SPI4->CR1.MSTR     = SPI4_MSTR_SELECT  ;
	SPI4->CR1.CPOL     = SPI4_CPOL_CONTROL ;
	SPI4->CR1.CPHA     = SPI4_CPHA_CONTROL ;
	SPI4->CR1.SPE      = SPI4_SPI_E        ;
#elif  SPI4_ENABLED  == DISABLED
	//  SPI4->CR1.SPE= SPI_DISABLE   ;
#endif
}

/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/
u8 SPI_u8SendRecive(SPI_t* SPI_ptrIndex,u8 Copy_u8Data)
{
	SPI_t* ptr=0;
	ptr = SPI_ptrIndex;
	u8 Local_u8Recive=0;
	ptr->DR=Copy_u8Data;
	while ((GET_BIT(ptr->SR,BSY))==1);
	Local_u8Recive=(u8)ptr->DR;

	return Local_u8Recive;
}
/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/
void MSPI3_vSetCallBack( void (* ptr)(void) )
{

	MSPI3_CallBack = ptr ;
}

/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/

void SPI3_IRQHandler(void)
{
	MSPI3_CallBack();
	SPI3->SR&=~(1<<0);
	SPI3->SR&=~(1<<1);

}
/*=================================   END_ FUNCTION   =====================================*/
/*===============================   Start_FUNCTION   =====================================*/
