/*========================================================================================
 *  @file    : ADC_Config.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUL 2023
========================================================================================*/
/***
 *         _    ____   ____     ____             __ _         _
 *        / \  |  _ \ / ___|   / ___|___  _ __  / _(_) __ _  | |__
 *       / _ \ | | | | |      | |   / _ \| '_ \| |_| |/ _` | | '_ \
 *      / ___ \| |_| | |___   | |__| (_) | | | |  _| | (_| |_| | | |
 *     /_/   \_|____/ \________\____\___/|_| |_|_| |_|\__, (_|_| |_|
 *                        |_____|                     |___/
 */


#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_


/*
 * Option :
 * 		[1] ADC_ENABLE
 * 		[2] ADC_DISABLE
 */

#define ADC_ENABLE_MODE ADC_ENABLE

/*
 * Option :
 * 		[1] _12_BIT_RESOLUTION_ADC
 * 		[2] _10_BIT_RESOLUTION_ADC
 * 		[3] _8_BIT_RESOLUTION_ADC
 * 		[4] _6_BIT_RESOLUTION_ADC
 */
#define ADC_RESOLUTION  _12_BIT_RESOLUTION_ADC

/*
 * Option :
 * 		[1] ADC_LEFT
 * 		[2] ADC_RIGHT
 */
#define ADC_DATA_ALIGMENT   ADC_RIGHT


/*
 * Option :
 * 		[1]_ADC_PRESCALER_2
 * 		[2]_ADC_PRESCALER_4
 *         [3]_ADC_PRESCALER_6
 *         [4]_ADC_PRESCALER_8
 */
#define ADC_PRESCALER   _ADC_PRESCALER_2




#endif /* MCAL_ADC_ADC_CONFIG_H_ */
