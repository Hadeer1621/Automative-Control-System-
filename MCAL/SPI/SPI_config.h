/*========================================================================================
 *  @file    : SPI_config.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUN 2023
========================================================================================*/
/***
 *      ____  ____ ___                     __ _         _
 *     / ___||  _ |_ _|    ___ ___  _ __  / _(_) __ _  | |__
 *     \___ \| |_) | |    / __/ _ \| '_ \| |_| |/ _` | | '_ \
 *      ___) |  __/| |   | (_| (_) | | | |  _| | (_| |_| | | |
 *     |____/|_|  |_______\___\___/|_| |_|_| |_|\__, (_|_| |_|
 *                   |_____|                    |___/
 */


#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


/*===============SPI1 Configuration ======================*/
#define  SPI1_ENABLED       DISABLED
/*
  UNIDIRECTIONAL 
  BIDIRECTIONAL
*/
#define SPI1_BIDIMODE_MODE  BIDIRECTIONAL
/*
 RECEIVE_ONLY 
 TRANSMIT_ONLY
*/                 
#define SPI1_BIDIOE_MODE    TRANSMIT_ONLY
/*
  CRC_DISABLE
  CRC_ENABLE 
*/
#define SPI1_CRC_EN         CRC_DISABLE
/*
  NO_CRC_PHASE
  CRC_PHASE   
*/
#define SPI1_CRC_NEXT       NO_CRC_PHASE
/*
  DATA_FRAME_8 
  DATA_FRAME_16
*/
#define SPI1_DATA_FRAME     DATA_FRAME_8
/*
  FULL_DUPLEX      
  RECEIVE_ONLY_MODE
*/
#define SPI1_RX_ONLY        FULL_DUPLEX
/*
  SSM_DISABLED 
  SSM_ENABLED  
*/
#define SPI1_SSM_MODE       SSM_DISABLED
/*
  SSI_ENABLE  
  SSI_DISABLED
*/ 
#define SPI1_SSI_MODE       SSI_DISABLED
/*
  MSB
  LSB
*/
#define SPI1_LSB_FIRST      LSB
/*
  SPI_DISABLE
  SPI_ENABLE 
*/
#define SPI1_SPI_E          SPI_ENABLE
/*
 F_CLK_2  
 F_CLK_4  
 F_CLK_8  
 F_CLK_16 
 F_CLK_32 
 F_CLK_64 
 F_CLK_128
 F_CLK_256
*/
#define SPI1_BR_CONTROL     F_CLK_128
/*
  MASTER
  SLAVE 
*/
#define SPI1_MSTR_SELECT    MASTER
/*
  LOW_POLARITY 
  HIGH_POLARITY
*/
#define SPI1_CPOL_CONTROL   LOW_POLARITY
/*
   READ_CLK_FIRST  
   WRITE_CLK_FIRST 
*/ 
#define SPI1_CPHA_CONTROL
/*=================SPI2 Configuration=============================*/
#define  SPI2_ENABLED       DISABLED
/*
  UNIDIRECTIONAL 
  BIDIRECTIONAL
*/
#define SPI2_BIDIMODE_MODE  BIDIRECTIONAL
/*
 RECEIVE_ONLY 
 TRANSMIT_ONLY
*/                 
#define SPI2_BIDIOE_MODE    TRANSMIT_ONLY
/*
  CRC_DISABLE
  CRC_ENABLE 
*/
#define SPI2_CRC_EN         CRC_DISABLE
/*
  NO_CRC_PHASE
  CRC_PHASE   
*/
#define SPI2_CRC_NEXT       NO_CRC_PHASE
/*
  DATA_FRAME_8 
  DATA_FRAME_16
*/
#define SPI2_DATA_FRAME     DATA_FRAME_8
/*
  FULL_DUPLEX      
  RECEIVE_ONLY_MODE
*/
#define SPI2_RX_ONLY        FULL_DUPLEX
/*
  SSM_DISABLED 
  SSM_ENABLED  
*/
#define SPI2_SSM_MODE       SSM_DISABLED
/*
  SSI_ENABLE  
  SSI_DISABLED
*/ 
#define SPI2_SSI_MODE       SSI_DISABLED
/*
  MSB
  LSB
*/
#define SPI2_LSB_FIRST      LSB
/*
  SPI_DISABLE
  SPI_ENABLE 
*/
#define SPI2_SPI_E          SPI_ENABLE
/*
 F_CLK_2  
 F_CLK_4  
 F_CLK_8  
 F_CLK_16 
 F_CLK_32 
 F_CLK_64 
 F_CLK_128
 F_CLK_256
*/
#define SPI2_BR_CONTROL     F_CLK_128
/*
  MASTER
  SLAVE 
*/
#define SPI2_MSTR_SELECT    MASTER
/*
  LOW_POLARITY 
  HIGH_POLARITY
*/
#define SPI2_CPOL_CONTROL   LOW_POLARITY
/*
   READ_CLK_FIRST  
   WRITE_CLK_FIRST 
*/ 
#define SPI2_CPHA_CONTROL
/*==================SPI3 Configuration======================*/
#define  SPI3_ENABLED       ENABLED
/*
  UNIDIRECTIONAL 
  BIDIRECTIONAL
*/
#define SPI3_BIDIMODE_MODE   UNIDIRECTIONAL
/*
 RECEIVE_ONLY
 TRANSMIT_ONLY
*/
#define SPI3_BIDIOE_MODE     TRANSMIT_ONLY
/*
  CRC_DISABLE
  CRC_ENABLE
*/
#define SPI3_CRC_EN          CRC_DISABLE
/*
  NO_CRC_PHASE
  CRC_PHASE
*/
#define SPI3_CRC_NEXT        NO_CRC_PHASE
/*
  DATA_FRAME_8
  DATA_FRAME_16
*/
#define SPI3_DATA_FRAME      DATA_FRAME_8
/*
  FULL_DUPLEX
  RECEIVE_ONLY_MODE
*/
#define SPI3_RX_ONLY         FULL_DUPLEX
/*
  SSM_DISABLED
  SSM_ENABLED
*/
#define SPI3_SSM_MODE        SSM_ENABLED
/*
  SSI_ENABLE
  SSI_DISABLED
*/
#define SPI3_SSI_MODE        SSI_ENABLE
/*
  MSB
  LSB
*/
#define SPI3_LSB_FIRST       MSB
/*
  SPI_DISABLE
  SPI_ENABLE
*/
#define SPI3_SPI_E           SPI_ENABLE
/*
 F_CLK_2
 F_CLK_4
 F_CLK_8
 F_CLK_16
 F_CLK_32
 F_CLK_64
 F_CLK_128
 F_CLK_256
*/
#define SPI3_BR_CONTROL      F_CLK_128
/*
  MASTER
  SLAVE
*/
#define SPI3_MSTR_SELECT     MASTER
/*
  LOW_POLARITY
  HIGH_POLARITY
*/
#define SPI3_CPOL_CONTROL    HIGH_POLARITY
/*
   READ_CLK_FIRST
   WRITE_CLK_FIRST
*/
#define SPI3_CPHA_CONTROL    WRITE_CLK_FIRST
/*===================SPI4 Configuration ========================*/
#define  SPI4_ENABLED       DISABLED
/*
  UNIDIRECTIONAL     0
  BIDIRECTIONAL      1
*/
#define SPI4_BIDIMODE_MODE  UNIDIRECTIONAL
/*
 RECEIVE_ONLY        0
 TRANSMIT_ONLY       1
*/                 
#define SPI4_BIDIOE_MODE    TRANSMIT_ONLY
/*
  CRC_DISABLE        0
  CRC_ENABLE         1
*/
#define SPI4_CRC_EN         CRC_DISABLE
/*
  NO_CRC_PHASE      0
  CRC_PHASE         1
*/
#define SPI4_CRC_NEXT       NO_CRC_PHASE
/*
  DATA_FRAME_8      0
  DATA_FRAME_16     1
*/
#define SPI4_DATA_FRAME     DATA_FRAME_8
/*
  FULL_DUPLEX        0
  RECEIVE_ONLY_MODE  1
*/
#define SPI4_RX_ONLY        FULL_DUPLEX
/*
  SSM_DISABLED       0
  SSM_ENABLED        1
*/
#define SPI4_SSM_MODE       SSM_ENABLED
/*
  SSI_ENABLE        1
  SSI_DISABLED      0
*/ 
#define SPI4_SSI_MODE       SSI_ENABLE
/*
  MSB               0
  LSB               1
*/
#define SPI4_LSB_FIRST      MSB
/*
  SPI_DISABLE       0
  SPI_ENABLE        1
*/
#define SPI4_SPI_E          SPI_ENABLE
/*
 F_CLK_2            0
 F_CLK_4            1
 F_CLK_8            2
 F_CLK_16           3
 F_CLK_32           4
 F_CLK_64           5
 F_CLK_128          6
 F_CLK_256          7
*/
#define SPI4_BR_CONTROL     F_CLK_2
/*
  MASTER           1
  SLAVE            0
*/
#define SPI4_MSTR_SELECT    MASTER
/*
  LOW_POLARITY     0
  HIGH_POLARITY    1
*/
#define SPI4_CPOL_CONTROL   HIGH_POLARITY
/*
   READ_CLK_FIRST   0
   WRITE_CLK_FIRST  1
*/ 
#define SPI4_CPHA_CONTROL   WRITE_CLK_FIRST

/*
 * NORMAL
 * TFT
 * */

#define MODE NORMAL
#endif
