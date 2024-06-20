/*========================================================================================
 *  @file    : Control_System.c
 *  @author  : Automotive control system
 *  @version : 1.0.0
 *  @data    :  AUG 2023
========================================================================================*/
/***
 *     _____             _             _   _____           _
 *    /  __ \           | |           | | /  ___|         | |
 *    | /  \/ ___  _ __ | |_ _ __ ___ | | \ `--. _   _ ___| |_ ___ _ __ ___    ___
 *    | |    / _ \| '_ \| __| '__/ _ \| |  `--. | | | / __| __/ _ | '_ ` _ \  / __|
 *    | \__/| (_) | | | | |_| | | (_) | | /\__/ | |_| \__ | ||  __| | | | | || (__
 *     \____/\___/|_| |_|\__|_|  \___/|_| \____/ \__, |___/\__\___|_| |_| |_(_\___|
 *                                    ______      __/ |
 *                                   |______|    |___/
 */

/*=======================INCLUBS_APP================*/
#include "Control_System.h"
/*=====================MACROS========================*/
#define LOW_BATTERY_LEVEL			10
#define LOW_TIERS_PRESSURE_LEVEL	90
#define LOW_TEMPERATURE_LEVEL		25
/*=====================CLOBAL_VARIABLES========================*/
u8 i = 5 ;
u8 StrtEngn='S' ;
u16 data [5] = {0};
/*=============================================*/
/*=============================================*/
/*==================START_FUNCTION===========================*/
void ACtrlSys_init(void){
	//Clock Initialization
	MRCC_vInitSystemCLK();
	MRCC_vEnableClock(APB2_BUS, PERIPHERAL_EN_ADC1);
	MRCC_vEnableClock(AHB1_BUS, _PERIPHERAL_EN_GPIOA);
	MRCC_vEnableClock(AHB1_BUS, _PERIPHERAL_EN_GPIOB);
	MRCC_vEnableClock(AHB1_BUS, _PERIPHERAL_EN_GPIOC);
	MRCC_vEnableClock(AHB1_BUS, _PERIPHERAL_EN_GPIOD);
	MRCC_vEnableClock(APB2_BUS,PERIPHERAL_EN_USART6);
	MRCC_vEnableClock(APB1_BUS, PERIPHERAL_EN_SPI3);

	//DAC Pins Configuration
	MGPIO_vSetPinMode(GPIOD_PORT,GPIO_PIN_0,OUTPUT);
	MGPIO_vSetPinMode(GPIOD_PORT,GPIO_PIN_1,OUTPUT);
	MGPIO_vSetPinMode(GPIOD_PORT,GPIO_PIN_2,OUTPUT);
	MGPIO_vSetPinMode(GPIOD_PORT,GPIO_PIN_3,OUTPUT);
	MGPIO_vSetPinMode(GPIOD_PORT,GPIO_PIN_4,OUTPUT);
	MGPIO_vSetPinMode(GPIOD_PORT,GPIO_PIN_5,OUTPUT);
	MGPIO_vSetPinMode(GPIOD_PORT,GPIO_PIN_6,OUTPUT);
	MGPIO_vSetPinMode(GPIOD_PORT,GPIO_PIN_7,OUTPUT);
	MGPIO_vPortOutputByte(GPIOD_PORT,0, 0, 8);

	//ADC Pins Configuration
	MGPIO_vSetPinMode(GPIOA_PORT,GPIO_PIN_0,ANALOUGE);
	MGPIO_vSetPinMode(GPIOA_PORT,GPIO_PIN_1,ANALOUGE);
	MGPIO_vSetPinMode(GPIOA_PORT,GPIO_PIN_2,ANALOUGE);
	MGPIO_vSetPinMode(GPIOA_PORT,GPIO_PIN_3,ANALOUGE);
	MGPIO_vSetPinMode(GPIOA_PORT,GPIO_PIN_4,ANALOUGE);

	//UART Pins Configuration
	MGPIO_vSetPinMode(GPIOA_PORT,GPIO_PIN_11,ALT);
	MGPIO_vSetPinMode(GPIOA_PORT,GPIO_PIN_12,ALT);
	GPIO_vSetAlternateFunction(GPIOA_PORT, GPIO_PIN_11, AF8);
	GPIO_vSetAlternateFunction(GPIOA_PORT, GPIO_PIN_12, AF8);


	//Air Conditioner Configuration
	H_DCMotor_vInit();


	//ADC_Initilization
	M_AdcInit(_ADC_REGULAR_SCAN_ONCE_MODE);
	M_AdcRegular_Sequance(CHANNEL_0,Regular_SEQUENCE_ID_0);
	M_AdcRegular_Sequance(CHANNEL_1,Regular_SEQUENCE_ID_1);
	M_AdcRegular_Sequance(CHANNEL_2,Regular_SEQUENCE_ID_2);
	M_AdcRegular_Sequance(CHANNEL_3,Regular_SEQUENCE_ID_3);
	M_AdcRegular_Sequance(CHANNEL_4,Regular_SEQUENCE_ID_4);

	//UART_Initilization
	UART6_vInit();

	//LCD_Initilization
	H_Lcd_Void_LcdInit();

	//LEDs_Initilization
	H_Led_Void_LedInit(GPIOA_PORT, GPIO_PIN_5);
	H_Led_Void_LedInit(GPIOA_PORT, GPIO_PIN_6);
	H_Led_Void_LedInit(GPIOA_PORT, GPIO_PIN_7);

	//SWITCH_Initilization
	H_PushButton_Void_PushButtonInit(GPIOA_PORT,GPIO_PIN_8);
}
/*=============================================*/
/*=============================================*/
/*==================START_FUNCTION===========================*/
void ACtrlSys_Start(void){
	/* Taking Sensors Values To Control The System*/
	MADC_RegulerScan( data,&i);
	H_Lcd_Void_LcdClr();

}
/*=============================================*/
/*=============================================*/
/*==================START_FUNCTION===========================*/

void ACtrlSys_vDisplay(void)
{
	//Getting Temperature Sensor Value and Displaying It on LCD
	data[0] = (u32) data[0] /8;
	H_Lcd_Void_LcdWriteString((u8*)"TL=");
	H_Lcd_Void_LcdGoTo(0, 4);
	H_Lcd_Void_LcdWriteNumber(data[0]);

	//Getting Speed Value and Displaying It on LCD
	data[1] = (u32) data[1] /8;
	H_Lcd_Void_LcdGoTo(0, 10);
	H_Lcd_Void_LcdWriteString((u8*)"SP=");

	//Getting Tiers Pressure Sensor Value and Displaying It on LCD

	H_Lcd_Void_LcdGoTo(1, 0);
	H_Lcd_Void_LcdWriteString((u8*)"TP=");
	H_Lcd_Void_LcdGoTo(1, 4);
	H_Lcd_Void_LcdWriteNumber(data[2]);

	//Getting Battery Level Sensor Value and Displaying It on LCD

	data[3] = (u32) data[3] /8;
	H_Lcd_Void_LcdGoTo(1, 10);
	H_Lcd_Void_LcdWriteString((u8*)"BL=");
	H_Lcd_Void_LcdGoTo(1, 13);
	H_Lcd_Void_LcdWriteNumber(data[3]);

	//Getting Distance Sensor Value

	data[4] = (u32) data[4] /8;
	Delay_vMsIn16MHz(100);

}
/*===================================================================================*/
/*===================================================================================*/
		/*==================START_FUNCTION===========================*/

void ACtrlSys_TirePressureCheck(void)
{
	if( data[2] < LOW_TIERS_PRESSURE_LEVEL )
	{
		H_Led_Void_LedOn(GPIOA_PORT, GPIO_PIN_7);
	}

	else
	{
		H_Led_Void_LedOff(GPIOA_PORT, GPIO_PIN_7);
	}

}
/*=============================================*/
/*=============================================*/
/*==================START_FUNCTION===========================*/

void ACtrlSys_BattryLevelCheck(void)
{
	if( data[3] < LOW_BATTERY_LEVEL )
	{
		H_Led_Void_LedOn(GPIOA_PORT, GPIO_PIN_5);
	}

	else
	{
		H_Led_Void_LedOff(GPIOA_PORT, GPIO_PIN_5);
	}

}
/*=============================================*/
/*=============================================*/
/*==================START_FUNCTION===========================*/

void ACtrlSys_AirCondCheck(void)
{
	if( data[0] < LOW_TEMPERATURE_LEVEL )
	{
		H_DCMotor_vStop();
	}

	else
	{
		H_DCMotor_vMove();
	}
}

/*=============================================*/
/*=============================================*/
/*==================START_FUNCTION===========================*/

void ACtrlSys_EngineStart(void)
{
	if ( ( UART6_vReceive() == StrtEngn ) && ( data[3] >= LOW_BATTERY_LEVEL )
			&& ( data[2] >= LOW_TIERS_PRESSURE_LEVEL )
			&& ( H_PushButton_U8_PushButtonRead(GPIOA_PORT, GPIO_PIN_8) == LOW )
			&&(data[4]>=20)) //StartEngine
		{
		//MOTOR On With Controlled Speed By PWM Signal Through DAC
		MGPIO_vPortOutputByte(GPIOD_PORT,data[1], 0, 8);
		H_Lcd_Void_LcdGoTo(0, 13);
		H_Lcd_Void_LcdWriteNumber(data[1]);
		}

	else
	{
		//Motor Off With Zero Speed By PWM Signal Through DAC
		H_Lcd_Void_LcdGoTo(0, 13);
		H_Lcd_Void_LcdWriteString((u8*)"00");
		MGPIO_vPortOutputByte(GPIOD_PORT,0, 0, 8);
	}

}

/*=============================================*/
/*=============================================*/
/*==================START_FUNCTION===========================*/
void ACtrlSys_DoorLocker(void){
	if(H_PushButton_U8_PushButtonRead(GPIOA_PORT, GPIO_PIN_8) == HIGH )
	{
		//Door Light Indicator Is On
		H_Led_Void_LedOn(GPIOA_PORT, GPIO_PIN_6);
	}

	else
	{
		//Door Light Indicator Is Off
		H_Led_Void_LedOff(GPIOA_PORT, GPIO_PIN_6);
	}

}

/*=============================================*/
/*=============================================*/
/*==================START_FUNCTION===========================*/

void ACtrlSys_CloseSystem(void){
	if (UART6_vReceive() == 'C')
	{
		H_Lcd_Void_LcdClr();
		H_Led_Void_LedOff(GPIOA_PORT, GPIO_PIN_7);
		H_Led_Void_LedOff(GPIOA_PORT, GPIO_PIN_5);
		H_DCMotor_vStop();
		MGPIO_vPortOutputByte(GPIOD_PORT,0, 0, 8);
		//break;
	}
}


