/*========================================================================================
 *  @file    : UART_interface.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : JUN 2023
========================================================================================*/
/***
 *      _   _   _    ____ _____   ___       _             __                  _
 *     | | | | / \  |  _ |_   _| |_ _|_ __ | |_ ___ _ __ / _| __ _  ___ ___  | |__
 *     | | | |/ _ \ | |_) || |    | || '_ \| __/ _ | '__| |_ / _` |/ __/ _ \ | '_ \
 *     | |_| / ___ \|  _ < | |    | || | | | ||  __| |  |  _| (_| | (_|  __/_| | | |
 *      \___/_/   \_|_| \_\|_____|___|_| |_|\__\___|_|  |_|  \__,_|\___\___(_|_| |_|
 *                          |_____|
 */

/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API
						- The Name Of Function
						- What is The Input
						- What Is The Output
						- Macro

======================================================================================*/
#ifndef MCAL_UART_INTERFACE_H_
#define MCAL_UART_INTERFACE_H_


void UART6_vInit(void);
u8 UART6_vSendReceive(u8 Copy_u8Data);
u8 UART6_vReceive(void);
u8 UART6_vReceive2(void);
void UART6_Callback(void (*pAppParamter)(void));

#endif /* MCAL_UART_INTERFACE_H_ */
