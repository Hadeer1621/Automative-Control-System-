/*========================================================================================
 *  @file    : BIT_MATH.h
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    : may 2023
========================================================================================*/


 #ifndef BIT_MATH_H_
 #define BIT_MATH_H_


 #define SET_BIT(REG , BITNUM) 		REG |= 1U<<BITNUM
 #define CLR_BIT(REG , BITNUM) 		REG &= ~(1U<<BITNUM)
 #define TOG_BIT(REG , BITNUM)		 REG ^= 1U<<BITNUM
 #define GET_BIT(REG , BITNUM) 		( (REG >> BITNUM) & 1U )


 #endif /* BIT_MATH_H_ */
