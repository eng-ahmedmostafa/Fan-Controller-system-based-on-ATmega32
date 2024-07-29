/*
 * pwm.c
 *
 *  Created on: Oct 15, 2023
 *      Author: Ahmed Mostafa
 */

#include"gpio.h"/*to apply GPIO_setupPinDirection */
#include<avr/io.h>/*to apply timer registers*/
#include"pwm.h"
/***************************
 *                      Functions Definitions                                  *
 ***************************/
void PWM_Timer0_Start(uint8 duty_cycle)
{
	uint8 value=0;
	TCNT0 =0;/*initialize the timer*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	//WGM00,WGM01 To Setup FastPwm Mode,COM01 For non-inverting mode,CS01 For cpu_clk/8/

	value=(uint8)( ( (uint32) duty_cycle * 255 ) / 100 );
	/* The DutyCycle Is In Percentage So We Have To Make Some Calculations */


	OCR0  = value;/*To Generate a Waveform Output On OC0*/
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	/*To Generate The Waveform On PB3*/


}

