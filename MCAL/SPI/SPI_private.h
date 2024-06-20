/*========================================================================================
 *  @file    : SPI_private.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUN 2023
========================================================================================*/
/***
 *      ____  ____ ___                 _            _         _
 *     / ___||  _ |_ _|     _ __  _ __(___   ____ _| |_ ___  | |__
 *     \___ \| |_) | |     | '_ \| '__| \ \ / / _` | __/ _ \ | '_ \
 *      ___) |  __/| |     | |_) | |  | |\ V | (_| | ||  __/_| | | |
 *     |____/|_|  |________| .__/|_|  |_| \_/ \__,_|\__\___(_|_| |_|
 *                   |_____|_|
 */


#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H
#include "STD_TYPES.h"
/*=========================================
 * 		-> BASE ADDRESS SPI
 * ==========================================*/
#define SPI1_BASE_ADDRESS  0x40013000   // APB2
#define SPI2_BASE_ADDRESS  0x40003800   // APB1
#define SPI3_BASE_ADDRESS  0x40003C00   // APB1
#define SPI4_BASE_ADDRESS  0x40013400   // APB2

/*=========================================
 * 		-> STRUCT CR REGISTERS
 * ==========================================*/

typedef struct
{
	volatile u32 CPHA    :1 ;
	volatile u32 CPOL    :1 ;
	volatile u32 MSTR    :1 ;
	volatile u32 BR      :3 ;
	volatile u32 SPE     :1 ;
	volatile u32 LSBFIRST:1 ;
	volatile u32 SSI     :1 ;
	volatile u32 SSM     :1 ;
	volatile u32 RXONLY  :1 ;
	volatile u32 DFF     :1 ;
	volatile u32 CRCNEXT :1 ;
	volatile u32 CRCEN   :1 ;
	volatile u32 BIDIOE  :1 ;
	volatile u32 BIDIMODE:1 ;
	volatile u32 RES     :16;
}CR1_t;

/*=========================================
 * 		-> STRUCT SPI REGISTERS
 * ==========================================*/
typedef struct
{
	volatile CR1_t CR1    ;
	volatile u32   CR2    ;
	volatile u32   SR     ;
	volatile u32   DR     ;
	volatile u32   CRCPR  ;
	volatile u32   RXCRCR ;
	volatile u32   TXCRCR ;
	volatile u32   I2SCFGR;
	volatile u32   I2SPR  ;
}SPI_t;

typedef SPI_t* SPI_REG;

/*=========================================
 * 		-> POINTER TO STRUCT SPI
 * ==========================================*/

#define SPI1   ((SPI_t*)(SPI1_BASE_ADDRESS))
#define SPI2   ((SPI_t*)(SPI2_BASE_ADDRESS))
#define SPI3   ((SPI_t*)(SPI3_BASE_ADDRESS))
#define SPI4   ((SPI_t*)(SPI4_BASE_ADDRESS))



/*===============================MACROES==================*/
#define BSY 7

#define DISABLED       0U
#define ENABLED        1U
/*************************/
#define UNIDIRECTIONAL 0U
#define BIDIRECTIONAL  1U
/*************************/
#define RECEIVE_ONLY   0U
#define TRANSMIT_ONLY  1U
/*************************/
#define CRC_DISABLE    0U
#define CRC_ENABLE     1U
/*************************/
#define NO_CRC_PHASE   0U
#define CRC_PHASE      1U
/*************************/
#define DATA_FRAME_8   0U
#define DATA_FRAME_16  1U
/*************************/
#define FULL_DUPLEX         0U
#define RECEIVE_ONLY_MODE   1U
/*************************/
#define SSM_DISABLED   0U
#define SSM_ENABLED    1U
/*************************/
#define SSI_ENABLE     1U
#define SSI_DISABLED   0U
/*************************/
#define MSB            0U
#define LSB            1U
/*************************/
#define SPI_DISABLE    0U
#define SPI_ENABLE     1U
/*************************/
#define F_CLK_2         0U
#define F_CLK_4         1U
#define F_CLK_8         2U
#define F_CLK_16        3U
#define F_CLK_32        4U
#define F_CLK_64        5U
#define F_CLK_128       6U
#define F_CLK_256       7U
/*************************/
#define MASTER          1U
#define SLAVE           0U
/*************************/
#define LOW_POLARITY    0U
#define HIGH_POLARITY   1U
/*************************/
#define READ_CLK_FIRST        0U     // first clock capture 
#define WRITE_CLK_FIRST       1U     // first clock send data 
/*************************/


#endif
