/*========================================================================================
 *  @file    : Delay_interface.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : may 2023
========================================================================================*/



#ifndef DELAY_INTERFACE_H
#define DELAY_INTERFACE_H
	 
#include <STD_TYPES/STD_TYPES.h>


/*========================================================================================
 *                      Functions Prototypes                                   *
========================================================================================*/
/* =============  Function To Delay By Milliseconds ( 16MHz CPU CLK )   ============= */

  extern void Delay_vMsIn16MHz(u16 copy_u16CountNum);

/* =============  Function To Delay By Microseconds ( 16MHz CPU CLK )   ============= */

  extern void Delay_vUsIn16MHzint (u16 copy_u16CountNum);






#endif //DELAY_INTERFACE_H
