#ifndef NANITLIB_H_
#define NANITLIB_H_


#include "NanitInits.h" 


int getNanitVersion();

void Nanit_Base_Start();

void Nanit_RGB_Write(byte red, byte green, byte blue);
void Nanit_Servo_Rotate(byte angle);

void Nanit_ActiveBuzz_Scream(byte times, int duration);

bool Nanit_Sound_IsSoundDetected(int sound_limit);


/* 
inline bool Nanit_PIR_IsMotionDetected()
{
	return digitalRead(33); //33 це або P5_6 (стара версія), або P5_4
}
*/




/*
bool BUTTON_();
int ULTRASONIC();
*/

#endif

