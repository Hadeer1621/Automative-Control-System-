/*========================================================================================
 *  @file    : GPIO_interface.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    :  may 2023
========================================================================================*/

/**************************************************************************************************
 *       _____ _____ _____ ____             _____ _   _ _______ ______ _____  ______      _____ ______ 
 *      / ____|  __ \_   _/ __ \           |_   _| \ | |__   __|  ____|  __ \|  ____/\   / ____|  ____|
 *     | |  __| |__) || || |  | |  ______    | | |  \| |  | |  | |__  | |__) | |__ /  \ | |    | |__   
 *     | | |_ |  ___/ | || |  | | |______|   | | | . ` |  | |  |  __| |  _  /|  __/ /\ \| |    |  __|  
 *     | |__| | |    _| || |__| |           _| |_| |\  |  | |  | |____| | \ \| | / ____ \ |____| |____ 
 *      \_____|_|   |_____\____/           |_____|_| \_|  |_|  |______|_|  \_\_|/_/    \_\_____|______|
 *                                                                                                     
 *                                                                                                     
**************************************************************************************************/
 
/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
						- Macro 
						 
======================================================================================*/ 

/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/


#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H
/*===========  Include  ===========*/
#include <MCAL/GPIO/GPIO_config.h>
#include <MCAL/GPIO/GPIO_private.h>
#include <STD_TYPES/STD_TYPES.h>

/*======== ENUM For Pins ========*/
typedef enum{
	GPIO_PIN_0 = 0U,
	GPIO_PIN_1 ,
	GPIO_PIN_2 ,
	GPIO_PIN_3 ,
	GPIO_PIN_4 ,
	GPIO_PIN_5 ,
    GPIO_PIN_6 ,
    GPIO_PIN_7 ,
    GPIO_PIN_8 ,
    GPIO_PIN_9 ,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15
}pin_num;

/*======== ENUM For PORT  ========*/
typedef enum{
	GPIOA_PORT = 0U,                           /*!< GPIO (A) PORT */
	GPIOB_PORT = 1,                                /*!< GPIO (B) PORT */
	GPIOC_PORT = 2,                                /*!< GPIO (C) PORT */
	GPIOD_PORT = 3,                                /*!< GPIO (D) PORT */
	GPIOE_PORT = 4,                                /*!< GPIO (E) PORT */
	GPIOH_PORT = 8                                /*!< GPIO (H) PORT */
}port_t;
/*======== ENUM For MODE  ========*/
typedef enum{
    INPUT = 0U,                                 /*!< MODE ---> INPUT     */
    OUTPUT,                                     /*!< MODE ---> OUTPUT    */
    ALT,                                        /*!< MODE ---> ALTF      */
    ANALOUGE                                    /*!< MODE ---> ANALOG    */
}pinmode_t;
/*======== ENUM For Output Type  ========*/
typedef enum{
    PUSH_PULL = 0U,                             /*!< OUTPUT TYPE ---> PUSH PULL   */ 
    OPEN_DRAIN                                 /*!< OUTPUT TYPE ---> OPEN DRAIN  */
}outputType_t;
/*======== ENUM For Output Speed  ========*/
typedef enum{ 
    LOW_SPEED = 0U,                             /*!< IO works at 2 MHz, please refer to the product datasheet */
    MEDIUM_SPEED,                               /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
    HIGH_SPEED,                                 /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
    VERY_HIGH_SPEED                             /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */
}OutSpeed_t;
/*======== ENUM Of Speed ========*/
typedef enum{
    NORMAL = 0U,                               /*!< No Pull-up or Pull-down activation  */
    PULL_UP,                                   /*!< Pull-up activation                  */
    PULL_DOWN                                  /*!< Pull-down activation                */
}PullType_t;


typedef enum
{
	AF0=0,
	AF1=1,
	AF2=2,
	AF3=3,
	AF4=4,
	AF5=5,
	AF6=6,
	AF7=7,
	AF8=8,
	AF9=9,
	AF10=10,
	AF11=11,
	AF12=12,
	AF13=13,
	AF14=14,
	AF15=15
}GPIO_AF;


/*===========================     Function Prototypes     ===========================*/

/*===============   1-Function Set The Mode Of Pin	 ===============*/
void MGPIO_vSetPinMode(port_t Copy_u8PortName ,pin_num Copy_u8PinNum ,pinmode_t Copy_u8Mode  );
/*===============   2-Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)  ===============*/
void MGPIO_vSetPinOutPutType(port_t Copy_u8PortName ,pin_num Copy_u8PinNum ,outputType_t Copy_u8OutPutType  );
/*===============	3-Function Set The Speed Of output pin  (LOW , Meduim , High ,VeryHaigh	===============*/
void MGPIO_vSetPinOutSpeed(port_t Copy_u8PortName ,pin_num Copy_u8PinNum ,OutSpeed_t Copy_u32OutSpeed );
/*===============   4-Function Set The PULL ( Almost Input ) ( OFF , UP , DOWN )  ===============*/
void MGPIO_vSetPullType(port_t Copy_u8PortName ,pin_num Copy_u8PinNum ,PullType_t Copy_u32PullType );
/*===============   5-Function To Read Data From IDR  ===============*/
u8 MGPIO_u8ReadData(port_t Copy_u8PortName ,pin_num Copy_u8PinNum);
/*===============   6-Function To Write Data At ODR	Value = HIGH , LOW  ===============*/
void MGPIO_vWriteData(port_t Copy_u8PortName ,pin_num Copy_u8PinNum,u8 Copy_u8State);
/*===============   7-Function To Locked   ===============*/
void MGPIO_vPinLock(port_t Copy_u8PortName ,pin_num Copy_u8PinNum);
/*===============   8-Function To Write DIR  ===============*/
void MGPIO_vWriteDataDIR(port_t Copy_u8PortName ,pin_num Copy_u8PinNum,u8 Copy_u8State);
/*===============   9-Function To Send One Byte  ===============*/
void MGPIO_vPortOutputByte(port_t Copy_u8PortName, u32 Copy_u32Data, u8 Copy_u8StartBit,u8 Copy_u8EndBit);
/*===============   10-Function To Set ALTF   ===============*/
void GPIO_vSetAlternateFunction(port_t Copy_u8PortName,pin_num Copy_u8PinNum,GPIO_AF Copy_u8AF);
/*==========================================================================================================*/

#endif //_GPIO_INTERFACE_H
/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/

