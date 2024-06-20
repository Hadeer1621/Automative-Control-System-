/*========================================================================================
 *  @file    : GPIO_Private.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    :  may 2023
========================================================================================*/


/****
 *       _____ _____ _____ ____             _____  _____  _______      __  _______ ______ 
 *      / ____|  __ \_   _/ __ \           |  __ \|  __ \|_   _\ \    / /\|__   __|  ____|
 *     | |  __| |__) || || |  | |  ______  | |__) | |__) | | |  \ \  / /  \  | |  | |__   
 *     | | |_ |  ___/ | || |  | | |______| |  ___/|  _  /  | |   \ \/ / /\ \ | |  |  __|  
 *     | |__| | |    _| || |__| |          | |    | | \ \ _| |_   \  / ____ \| |  | |____ 
 *      \_____|_|   |_____\____/           |_|    |_|  \_\_____|   \/_/    \_\_|  |______|
 *                                                                                        
 *                                                                                        
 **************/

/*===============================================================================================

*	 - Developer can't Edit in it
*	  - Register _ Defination
*	  - Design :
					- #define	:	YES
					- Union		:	NO
					- Struct	:	YES

===================================================================================================*/


/*=====================================================================================
===================    guard of file will call on time in .c	    ===================
=======================================================================================*/ 

#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H
#include "STD_TYPES.h"
/*=================================================================================
	-----> Macros
			*  Base_Address GPI0x				
=================================================================================*/

#define  GPIOx_BASE_ADDRESS         0x40020000   /*!<  Base_Address GPI0    */


/*================================================================
	-)Struct : General Purpose I/O				
=================================================================*/
typedef struct{
	 volatile u32 MODER  ;  /*!< GPIO port mode register,               Address offset: 0x00      */
	 volatile u32 OTYPER ;  /*!< GPIO port output type register,        Address offset: 0x04      */
	 volatile u32 OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
	 volatile u32 PUPDR  ;  /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	 volatile u32 IDR    ;  /*!< GPIO port input data register,         Address offset: 0x10      */
	 volatile u32 ODR    ;  /*!< GPIO port output data register,        Address offset: 0x14      */
	 volatile u32 BSRR   ;  /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
	 volatile u32 LCKR   ;  /*!< GPIO port configuration lock register, Address offset: 0x1C      */
	 volatile u32 AFRL[2]   ;  /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
	 //volatile u32 AFRH   ;
}GPIOx_t;
/*================================================================
	-)Struct Macros :
			*  Base_Address GPIO 				
=================================================================*/
#define MGPIO(x)             ((GPIOx_t *) (GPIOx_BASE_ADDRESS+(1024*x)))

#define _LUCKED_PIN 16U

#endif //_GPIO_PRIVATE_H

