/*
 * Timer.h
 *
 *  Created on: Oct 9, 2021
 *      Author: LENOVO
 */

#ifndef TIMER_H_
#define TIMER_H_
#include <avr/io.h>
#include <util/delay.h>

typedef enum{
	STOP_TIMER0,
	ND_PRESC,
	PRESC_8,
	PRESC_64,
	PRESC_256,
	PRESC_1024
}TIMER0_presc;

typedef enum{
	Normal,
	CTC,
	Phase_Correct,
	Fast_PWM
}MODE_TIMER0;

typedef enum{
	Disconnected,
	Reserved,
	High_Under,
	Low_Under

}MODE_WAVE;


void TIMER0_Init(TIMER0_presc presc,MODE_TIMER0 timerMode,MODE_WAVE waveMode);
void TIMER0_Enable(TIMER0_presc presc);
void TIMER0_Disable();


#endif /* TIMER_H_ */
