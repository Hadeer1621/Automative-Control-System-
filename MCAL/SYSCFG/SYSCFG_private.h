/*========================================================================================
 *  @file    : SYSCFG_Private.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : may 2023
========================================================================================*/
/***
 *      ______   ______   ____ _____ ____                 _            _         _
 *     / ___\ \ / / ___| / ___|  ___/ ___|     _ __  _ __(___   ____ _| |_ ___  | |__
 *     \___ \\ V /\___ \| |   | |_ | |  _     | '_ \| '__| \ \ / / _` | __/ _ \ | '_ \
 *      ___) || |  ___) | |___|  _|| |_| |    | |_) | |  | |\ V | (_| | ||  __/_| | | |
 *     |____/ |_| |____/ \____|_|   \_________| .__/|_|  |_| \_/ \__,_|\__\___(_|_| |_|
 *                                      |_____|_|
 */


#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H 

/*
 * 		->BASE ADDRESS SYSCFG
 */
#define SYSCFG_BASE_ADDRESS			0x40013800
/*
 * 		-> STRUCT FOR SYSCFG REGISTERS
 */
typedef struct
{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR[4];
	volatile u32 CMPCR;	
}SYSCFG_t;
/*
 * 		-> POINTER TO STRUCT FOR SYSCFG REGISTERS
 */
#define SYSCFG ((volatile SYSCFG_t*)(SYSCFG_BASE_ADDRESS))



#endif
