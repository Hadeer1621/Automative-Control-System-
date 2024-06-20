/*========================================================================================
 *  @file    : NVIC_config.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : may 2023
========================================================================================*/

/***
 *      _   ___     _____ ____                     __ _ _       _
 *     | \ | \ \   / |_ _/ ___|    ___ ___  _ __  / _(_| |__   | |__
 *     |  \| |\ \ / / | | |       / __/ _ \| '_ \| |_| | '_ \  | '_ \
 *     | |\  | \ V /  | | |___   | (_| (_) | | | |  _| | | | |_| | | |
 *     |_| \_|  \_/  |___\________\___\___/|_| |_|_| |_|_| |_(_|_| |_|
 *                           |_____|
 */

#ifndef MCAL_NVIC_NVIC_CONFG_H_
#define MCAL_NVIC_NVIC_CONFG_H_

/*
 * choose your PRIGROUP
 *
 * 1)  _4Bits_Group_p_0Bits_Sub_P
 * 2)  _3Bits_Group_p_1Bits_Sub_P
 * 3)  _2Bits_Group_p_2Bits_Sub_P
 * 4)  _1Bits_Group_p_3Bits_Sub_P
 * 5)  _0Bits_Group_p_4Bits_Sub_P
 */

#define PRIGROUP       _3Bits_Group_p_1Bits_Sub_P

#endif /* MCAL_NVIC_NVIC_CONFG_H_ */
