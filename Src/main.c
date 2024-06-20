/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Automotive Control System
 * @data    	   :  AUG 2023
 * @brief          : Main program body
 ******************************************************************************
 */

#include "Control_System.h"
#include "image.h"
#include "image2.h"
#include "image3.h"


int main(void)
{
	u8  L_u8Door = 0 ;
	u8  L_u8Key = 0 ;
	u8 	Local_U8_Counter = 0 ;
	u8 	Local_U8_Counter2 = 0;
	while(1)
	{
		//Recieveing Door Signal
		L_u8Door = UART6_vReceive();
		//Checking Weither The Door is opened or not
		if (L_u8Door == 'D')
		{
			//TFT_Initilization
			HTFT_vTFTInit();
			HTFT_vTFTDisplayImage(image);
			while( L_u8Door == 'D' ) // Door is Opened
			{
				//Checking If The Door Is closed Then Display Closed Door Image in TFT
			if(H_PushButton_U8_PushButtonRead(GPIOA_PORT, GPIO_PIN_8) == HIGH && Local_U8_Counter ==0 )
				{
					H_Led_Void_LedOn(GPIOA_PORT, GPIO_PIN_6);
					HTFT_vTFTDisplayImage(image2);
					Local_U8_Counter++ ;
					Local_U8_Counter2 = 0 ;
				}

				/*---------------------------------------------------------------*/

				//Checking If The Door Is Opened Then Display Opened Door Image in TFT
				if(H_PushButton_U8_PushButtonRead(GPIOA_PORT, GPIO_PIN_8) == LOW && Local_U8_Counter2==0 )
				{
					Local_U8_Counter2++;
					Local_U8_Counter = 0;
					H_Led_Void_LedOff(GPIOA_PORT, GPIO_PIN_6);
					HTFT_vTFTDisplayImage(image3);
				}

				/*---------------------------------------------------------------*/

				// Recieving Key Signal
				L_u8Key = UART6_vReceive();
				//Checking If The Door Is Opened and Got a Signal To Close The System
				//To Turn Off TFT
				if ((L_u8Key =='L') && (H_PushButton_U8_PushButtonRead(GPIOA_PORT, GPIO_PIN_8)==LOW))
				{
					HTFT_voidDisplayOff();
					break;
				}

				/*---------------------------------------------------------------*/

				//While Getting The Key Signal True, System Is On
				while( L_u8Key == 'K' ) //Key
				{
					/* Taking Sensors Values To Control The System*/
					ACtrlSys_Start();
					//Getting Sensors Value and Displaying It on LCD
					ACtrlSys_vDisplay();
					/*---------------------------------------------------------------*/
					//Checking Temerature Sensor Value Under Certain Condition To Control
									//The Air Conditioner
					ACtrlSys_AirCondCheck();
					/*---------------------------------------------------------------*/
					//Checking Battery Level Sensor Value Under Certain Condition To Control
								//The Car Motor
					ACtrlSys_BattryLevelCheck();
					/*---------------------------------------------------------------*/
					//Checking Tiers Pressure Level Sensor Value Under Certain Condition
								//To Control The Car Motor
					ACtrlSys_TirePressureCheck();
					/*---------------------------------------------------------------*/
					//Checking The Door Status To Control The Door Light Indicator
					ACtrlSys_DoorLocker();
					/*---------------------------------------------------------------*/
					//Engine Start Signal, Battery, Tiers Pressure and Door Status Checking
					//To Control The Motor
					ACtrlSys_EngineStart();
					/*---------------------------------------------------------------*/
					//Getting A Specific Signal To Close The System
					ACtrlSys_CloseSystem();

					MSTK_vBusyWait(200000);
				}
			}
		}
	}
}

