#ifndef NANITLIB_H_
#define NANITLIB_H_

#if defined(__AVR_ATmega2560__)
#elif 0
#else
#error Check the project settings. Invalid microcontroller selected. This project cannot be built on this processor
#endif

#include "NanitInits.h"

#include <FastLED_NeoPixel.h>


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



#define BUILDIN_STRIP_LED (27)

#define START_NANIT NanitRobot::Nanit::getNanit()
#define GET_NANIT NanitRobot::Nanit::getNanit()

#define Nanit_Base_Start2(X) \
::NanitRobot::Nanit& X{::NanitRobot::Nanit::getNanit()}


namespace NanitRobot{
	class Nanit{
		public:
		// Nanit(){
		// 	_strip_led.begin();
		// }
		inline static Nanit &getNanit() {
    		static Nanit instance;
    		return instance;
  		}
		void SelfTestMode(){}
		void UnitTestMode(){}
		// 1 & 12 motors
		class DCMotor{
			public:
			DCMotor(){}
			void Begin(){}
			void End(){}
			void Roll(){}
			void Brake(){}
			void Forward(){}
			void Reverse(){}
			void Run(signed short speed1, signed short speed2){}
		} Motors;
		// 2 & 11
		class Servos{} Servo;
		// 3 color & PIR
		// 4 RGB 
		// 5 Buzzer & mic
		// 6 ultrasonic
		// 7 joy
		// 8 interfase
		// 9 Gyro
		// 10 line

		void BuildinRGB(uint8_t red, uint8_t grean, uint8_t blue, uint8_t brightness=255){
			_strip_led.setBrightness(brightness);
  			_strip_led.setPixelColor(0, _strip_led.Color(red, grean,blue));
  			_strip_led.show();
		}
		void BuildinRGB(uint32_t color, uint8_t brightness=255){
			_strip_led.setPixelColor(0, color);
			_strip_led.show();
		}
		private:
		inline Nanit(){
			_strip_led.begin();
			// _strip_led.setPixelColor(0, _strip_led.Color(255, 0, 0));
			// _strip_led.show();
		};
		inline ~Nanit(){};
		FastLED_NeoPixel<1, BUILDIN_STRIP_LED, NEO_GRB> _strip_led;

	};
}


#endif

