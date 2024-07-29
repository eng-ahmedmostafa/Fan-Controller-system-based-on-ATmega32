/*
 * app.c
 *
 *  Created on: Oct 16, 2023
 *      Author: Ahmed Mostafa
 */


#include "lm35_sensor.h"
#include "std_types.h"
#include "motor.h"
#include "lcd.h"
#include "avr/io.h"
int main ()
{

	SREG |= (1<<7);/* Enable Global Interrupts */

	uint8 temp ;
	LCD_init();

	DcMotor_Init();
	LCD_displayStringRowColumn( 0 , 3 ,"Fan is  ");
	LCD_displayStringRowColumn(1 , 3,"Temp =    C");

	while (1)
	{


		temp = LM35_getTemperature();
		if ((temp >=30) && (temp < 60) )
		{
			DcMotor_Rotate(ANTI_CLOCKWISE , 25);
			LCD_displayStringRowColumn(0 , 10 , "ON" );
			LCD_moveCursor(1 , 10 );
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}
		else if ((temp >=60) && (temp < 90) )
		{
			DcMotor_Rotate(ANTI_CLOCKWISE , 50);
			LCD_displayStringRowColumn(0 , 10 , "ON" );
			LCD_moveCursor(1 , 10 );
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}
		else if ((temp >=90) && (temp < 120))
		{
			DcMotor_Rotate(ANTI_CLOCKWISE , 75);
			LCD_displayStringRowColumn(0 , 10 , "ON" );
			LCD_moveCursor(1 , 10 );
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}
		else if ((temp > 120))
		{
			DcMotor_Rotate(ANTI_CLOCKWISE , 100);
			LCD_displayStringRowColumn(0 , 10 , "ON" );
			LCD_moveCursor(1 , 10 );
			LCD_intgerToString(temp);

		}
		else
		{


			DcMotor_Rotate(stop , 0);
			LCD_displayStringRowColumn(0 , 10 , "OFF" );
			LCD_moveCursor(1 , 10 );
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}




	}


}
