#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include"Led.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Servo.h"
#include<string.h>

void rotate90(){

	GPIO_InitPin(servo_PORT, servo_PIN, GPIO_OUTPUT);
	GPIO_WritePin(servo_PORT,servo_PIN,GPIO_HIGH);
	_delay_us(time_90deg);
	GPIO_WritePin(servo_PORT,servo_PIN,GPIO_LOW);

	_delay_ms(1000);
}

void rotate00(){
	GPIO_InitPin(servo_PORT, servo_PIN, GPIO_OUTPUT);
	GPIO_WritePin(servo_PORT,servo_PIN,GPIO_HIGH);
	_delay_us(time_00deg);
	GPIO_WritePin(servo_PORT,servo_PIN,GPIO_LOW);

	_delay_ms(1000);
}
