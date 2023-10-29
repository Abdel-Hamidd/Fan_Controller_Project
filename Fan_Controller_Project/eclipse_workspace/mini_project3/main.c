/*************************************************************************
 *
 *  File Name: main.c
 *
 *  Description: Application File
 *
 *  Author: Abdelhamid Tarek
 *
 *************************************************************************/

#include"lcd.h"
#include"adc.h"
#include "lm35_sensor.h"
#include"dc_motor.h"

int main(void)
{
	uint8 temprature ;

	ADC_ConfigType adc_Config = {PRESCALER_8, INTERNAL_AREF};

	LCD_init();
	ADC_init(&adc_Config);
	DcMotor_Init();

	/* Display this string fan status only once on LCD at the first row */
	LCD_displayStringRowColumn(0,0,"FAN iS    ");

	/* Display this string "Temp = C" only once on LCD at the second row */
	LCD_displayStringRowColumn(1,0,"Temp = C");

	while(1)
	{
		temprature = LM35_getTemperature();

		if(temprature<30)
		{
			DcMotor_Rotate(stop,0);
			LCD_displayStringRowColumn(0,7," OFF ");
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,7);
			LCD_intgerToString(temprature);
			LCD_displayCharacter(' ');
		}
		else if(temprature>=30 && temprature<60)
		{
			DcMotor_Rotate(cw,25);
			LCD_displayStringRowColumn(0,7," ON");
			LCD_displayCharacter(' ');
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,7);
			LCD_intgerToString(temprature);
			LCD_displayCharacter(' ');
		}
		else if(temprature>=60 && temprature<90)
		{
			DcMotor_Rotate(cw,50);
			LCD_displayStringRowColumn(0,7," ON");
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,7);
			LCD_intgerToString(temprature);
			LCD_displayCharacter(' ');
		}
		else if(temprature>=90 && temprature<120)
		{
			DcMotor_Rotate(cw,75);
			LCD_displayStringRowColumn(0,7," ON");
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,7);
			LCD_intgerToString(temprature);
			LCD_displayCharacter(' ');
		}
		else if(temprature>=120)
		{
			DcMotor_Rotate(cw,100);
			LCD_displayStringRowColumn(0,7," ON");
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,7);
			LCD_intgerToString(temprature);
		}
	}
}

