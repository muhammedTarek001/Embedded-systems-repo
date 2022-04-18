#include "Timer.h"

#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include"Led.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "Clock.h"
#include "SEVERAL_TASKS.h"
#include "Seg.h"
#include "LCD.h"
#include<string.h>

void TIMER0_Init(TIMER0_presc presc ,MODE_TIMER0 timerMode,MODE_WAVE waveMode){

	switch(presc){
          case STOP_TIMER0:
              CLEAR_BIT(TCCR0,CS00);
              CLEAR_BIT(TCCR0,CS01);
              CLEAR_BIT(TCCR0,CS02);

              break;
          case ND_PRESC:
        	  GET_BIT(TCCR0,CS00);
        	  CLEAR_BIT(TCCR0,CS01);
        	  CLEAR_BIT(TCCR0,CS02);
              break;
          case PRESC_8:

        	  CLEAR_BIT(TCCR0,CS00);
        	  GET_BIT(TCCR0,CS01);
        	  CLEAR_BIT(TCCR0,CS02);
               break;
          case PRESC_64:
        	  GET_BIT(TCCR0,CS00);
        	  GET_BIT(TCCR0,CS01);
        	  CLEAR_BIT(TCCR0,CS02);
               break;
          case PRESC_256:
        	  CLEAR_BIT(TCCR0,CS00);
        	  CLEAR_BIT(TCCR0,CS01);
        	  GET_BIT(TCCR0,CS02);
              break;
          case PRESC_1024:
        	  GET_BIT(TCCR0,CS00);
        	  CLEAR_BIT(TCCR0,CS01);
        	  GET_BIT(TCCR0,CS02);

   }
   switch(timerMode){
   case Normal:
       CLEAR_BIT(TCCR0,WGM00);
       CLEAR_BIT(TCCR0,WGM01);
	   break;
   case Phase_Correct:
          GET_BIT(TCCR0,WGM00);
          CLEAR_BIT(TCCR0,WGM01);
   	   break;
   case CTC:
          CLEAR_BIT(TCCR0,WGM00);
          GET_BIT(TCCR0,WGM01);
   	   break;
   case Fast_PWM:
           CLEAR_BIT(TCCR0,WGM00);
           GET_BIT(TCCR0,WGM01);
   }

   switch(waveMode){
   case Disconnected:
       CLEAR_BIT(TCCR0,COM00);
       CLEAR_BIT(TCCR0,COM01);
	   break;
   case Reserved:
          GET_BIT(TCCR0,COM00);
          CLEAR_BIT(TCCR0,COM01);
   	   break;
   case High_Under:
          CLEAR_BIT(TCCR0,COM00);
          GET_BIT(TCCR0,COM01);
   	   break;
   case Low_Under:
          GET_BIT(TCCR0,COM00);
          GET_BIT(TCCR0,COM01);

   }
}


void TIMER0_Enable(TIMER0_presc presc){
	switch(presc){
	          case STOP_TIMER0:
	              CLEAR_BIT(TCCR0,CS00);
	              CLEAR_BIT(TCCR0,CS01);
	              CLEAR_BIT(TCCR0,CS02);

	              break;
	          case ND_PRESC:
	        	  GET_BIT(TCCR0,CS00);
	        	  CLEAR_BIT(TCCR0,CS01);
	        	  CLEAR_BIT(TCCR0,CS02);
	              break;
	          case PRESC_8:

	        	  CLEAR_BIT(TCCR0,CS00);
	        	  GET_BIT(TCCR0,CS01);
	        	  CLEAR_BIT(TCCR0,CS02);
	               break;
	          case PRESC_64:
	        	  GET_BIT(TCCR0,CS00);
	        	  GET_BIT(TCCR0,CS01);
	        	  CLEAR_BIT(TCCR0,CS02);
	               break;
	          case PRESC_256:
	        	  CLEAR_BIT(TCCR0,CS00);
	        	  CLEAR_BIT(TCCR0,CS01);
	        	  GET_BIT(TCCR0,CS02);
	              break;
	          case PRESC_1024:
	        	  GET_BIT(TCCR0,CS00);
	        	  CLEAR_BIT(TCCR0,CS01);
	        	  GET_BIT(TCCR0,CS02);

	   }
}


