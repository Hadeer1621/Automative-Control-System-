/*========================================================================================
 *  @file    : NVIC_Provate.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : may 2023
========================================================================================*/
/***
 *      _   ___     _____ ____                 _            _         _
 *     | \ | \ \   / |_ _/ ___|     _ __  _ __(___   ____ _| |_ ___  | |__
 *     |  \| |\ \ / / | | |        | '_ \| '__| \ \ / / _` | __/ _ \ | '_ \
 *     | |\  | \ V /  | | |___     | |_) | |  | |\ V | (_| | ||  __/_| | | |
 *     |_| \_|  \_/  |___\_________| .__/|_|  |_| \_/ \__,_|\__\___(_|_| |_|
 *                           |_____|_|
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_
/*=================================================
 	 	 	 -> STRUCT TO NVIC REGISTERS
========================================================*/
typedef struct
{
	volatile u32 ISER[8U];
	volatile u32 RESERVED0[24U];
	volatile u32 ICER[8U];
	volatile u32 RESERVED1[24U];
	volatile u32 ISPR[8U];
	volatile u32 RESERVED2[24U];
	volatile u32 ICPR[8U];
	volatile u32 RESERVED3[24U];
	volatile u32 IABR[8U];
	volatile u32 RESERVED4[56U];
	volatile u8 IPR[240U];
	volatile u32 RESERVED5[644U];
	volatile u32 STIR;
}NVIC_t;
/*=================================================
 	 	 	 -> ENUM TO NVIC PRESCALER
========================================================*/
typedef enum
{

 _4Bits_Group_p_0Bits_Sub_P,
 _3Bits_Group_p_1Bits_Sub_P,
 _2Bits_Group_p_2Bits_Sub_P,
 _1Bits_Group_p_3Bits_Sub_P,
 _0Bits_Group_p_4Bits_Sub_P
}PRIGROUP_num;
/*=================================================
 	 	 	 -> POINTER TO STRUCT NVIC REGISTERS
========================================================*/
#define NVIC           ((NVIC_t *) (0xE000E100))
/*=================================================
 	 	 	 -> STRUCT TO SSB REGISTERS
========================================================*/
#define AIRCR          *((volatile u32*) (0xE000ED0C))


#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
