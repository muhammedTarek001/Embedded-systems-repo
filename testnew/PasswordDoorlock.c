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
#include "Servo.h"
#include<string.h>

#include "PasswordDoorlock.h"

void password_checking() {
	lcd_setCursor(0, 0);
	lcd_write_string("Please enter pass");
	unit8 charNo = 0; // charEntered ???
	char passEntered[4] = "0000";

	char correctPass[4] = PASSWORD;
	char pressedKey=NO_KEY; // char or int
	lcd_setCursor(1, 0);
	while (charNo < 4) { // 4 ??
		pressedKey = detect_Button();

		if (pressedKey != NO_KEY) {

			lcd_write_charcter('*');
			passEntered[charNo] = pressedKey;
			charNo++;
		}
		_delay_ms(300);

	}

	charNo = 0;
	while (charNo < 4) {

		if (passEntered[charNo] != correctPass[charNo]) {
			break;
		}
		charNo++;

	}

	lcd_command(CLEAR);

    if(charNo < 4){

    	lcd_setCursor(0, 0);
    	lcd_write_string("Password incorrect");
    	lcd_setCursor(1, 0);
    	lcd_write_string("Please try again");
    }

    else if(charNo == 4){

    	lcd_setCursor(0, 0);
    	lcd_write_string("Password correct");
    	rotate90();
    	_delay_ms(5000);  //here we will put different condition will close door like motion sensor //
    	rotate00();

    }

}
