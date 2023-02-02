#include "NanitLib.h"


		uint8_t MOTOR1_A;
		uint8_t MOTOR1_B;
		uint8_t P1_6; 
		uint8_t P1_4;
		uint8_t P1_3;
		uint8_t P8_3;
		uint8_t P10_3;
		uint8_t P10_2;
		uint8_t P7_6;
		uint8_t P7_4;
		uint8_t P9_6;
		uint8_t P9_4;


int getNanitVersion(){
pinMode(39,INPUT_PULLUP); 
if(digitalRead(39)) return 2;
if(!digitalRead(39)) return 3;
};


void Nanit_Base_Start()
{
	

switch(getNanitVersion()){
case 2:/// Стара версія
		MOTOR1_A = 10;
		MOTOR1_B = 9;
		P1_6 = 10; 
		P1_4 = 10;
		P1_3 = 9;
		P8_3 = 54; //A0
		P10_3 = 5;
		P10_2 = 24;
		P7_6 = 7; 
		P7_4 = 7;
		P9_6 = 8;  
		P9_4 = 8;
break;
case 3:
		MOTOR1_A = 7;
		MOTOR1_B = 8;
		P1_6 = 7; 
		P1_4 = 7;
		P1_3 = 8;
		P8_3 = 5;
		P10_3 = 24;
		P10_2 = 54; //A0
		P7_6 = 9; /// 
		P7_4 = 9;
		P9_6 = 10;  /// 
		P9_4 = 10;
break;
//case 3:
//brake;
default:
break;
}

	Nanit_Display_Init();
}

void Nanit_RGB_Write(byte red, byte green, byte blue)
{
	red = (red >= 0 && red <= 255)? red : 0;
	green = (green >= 0 && green <= 255)? green : 0;
	blue = (blue >= 0 && blue <= 255)? blue : 0;

	analogWrite(46, red); //46 це або P4_4, або P4_6 (стара версія)
	analogWrite(P4_2, green);
	analogWrite(P4_3, blue);
}

void Nanit_Servo_Rotate(byte angle)
{
	angle = (angle >= 0 && angle <= 180)? angle : 0;
	nanit_servo.write(angle);
}

void Nanit_ActiveBuzz_Scream(byte times, int duration)
{
	byte i;

	times = (times > 0)? times : 1;

	for (i = 0; i < times; i++)
	{
		digitalWrite(33, LOW);
		delay(duration);
		digitalWrite(33, HIGH);
		delay(duration);
	}
	
 //round(millis() / 500) % 2 == 0
}


bool Nanit_Sound_IsSoundDetected(int sound_limit)
{
	return (analogRead(A1) > sound_limit);
}

/*
bool BUTTON_(){
pinMode(3,INPUT); delay(1);
if (digitalRead(3)) {return true;} else {return false;}
}



int ULTRASONIC(){
  pinMode(22, OUTPUT);
  pinMode(23, INPUT);
  delay(1);
  int duration, cm;
  digitalWrite(22, LOW);
  delayMicroseconds(2);
  digitalWrite(22, HIGH);
  delayMicroseconds(10);
  digitalWrite(22, LOW);
  duration = pulseIn(23, HIGH);
  cm = duration / 58;

	return cm;
}
*/
