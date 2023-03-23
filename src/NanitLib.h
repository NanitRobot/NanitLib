#ifndef NANITLIB_H_
#define NANITLIB_H_

#if defined(__AVR_ATmega2560__)

// Контроль заряду батареї
// Опорна напруга АЦП
#define AVCC_REF (5.f)
// Розрядність АЦП
#define ADC_BITRATE (10)
// #define BAT_FULL_CHARGE (4.19f)
// Пін до якого включена батарея
#define BATTARY_PIN (69)
#define BUILDIN_STRIP_LED (27)
// Яка батарея використовується
#define LI_ION
// #elif 0
#else
#error Check the project settings. Invalid microcontroller selected. This project cannot be built for this processor
#endif
#include "DependsLib.h"
#include "NanitInits.h"

// #include <Servo.h>

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

#define START_NANIT ::NanitRobot::Nanit::getNanit()
#define GET_NANIT ::NanitRobot::Nanit::getNanit()

#define INIT_NANIT(X)                                                   \
  ::NanitRobot::Nanit &X { START_NANIT }

namespace NanitRobot {
  
float Map(float inputValue, float inputMin, float inputMax, float rangeMin,
          float rangeMax);
          
class Nanit {
public:

enum class GuageType{SmileBatt,LAST};

  inline static Nanit &getNanit() {
    static Nanit instance;
    return instance;
  }
  void SelfTestMode();
  void UnitTestMode();
  float getBataryVoltage() const;
  float getBattaryPower() const;
  float getBoardVersion()const{};
  float getLibVersion()const{};
  void DrawBattGuage(GuageType type= GuageType::SmileBatt)const;
  // 1 & 12 motors
  class DCMotor {
  public:
  //   DCMotor() {}
  //   void Begin() {}
  //   void End() {}
  //   void Roll() {}
  //   void Brake() {}
  //   void Forward() {}
  //   void Reverse() {}
  //   void Run(signed short speed1, signed short speed2) {}
  // } Motors;
  // // 2 & 11
  // class Servos {
  // } Servo;
  // 3 color & PIR
  // 4 RGB
		// 4 RGB 
  // 4 RGB
  // 5 Buzzer & mic
  // 6 ultrasonic
  // 7 joy
  // 8 interfase
  // 9 Gyro
  // 10 line

  void BuildinRGB(uint8_t red, uint8_t grean, uint8_t blue,
                  uint8_t brightness = 255) {
    _strip_led.setBrightness(brightness);
    _strip_led.setPixelColor(0, _strip_led.Color(red, grean, blue));
    _strip_led.show();
  }
  void BuildinRGB(uint32_t color, uint8_t brightness = 255) {
    _strip_led.setPixelColor(0, color);
    _strip_led.show();
  }

private:
  inline Nanit()
      : Display{Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RES)}
//  ,        BoardVersion{getBoardVersion()}
  {
    if(!Serial)
    Serial.begin(9600);
    Serial.println("Nanit initialise...");
    _strip_led.begin();

    Display.initR(INITR_BLACKTAB);

    Display.fillScreen(ST7735_WHITE);
    Display.setTextColor(ST7735_BLACK);

    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
    //виводимо тестове повідомлення
    // Display.setCursor(10, 10);
    // Display.setTextWrap(true);
    Display.setRotation(1);
    // Display.setTextSize(2);
    // // pinMode(CHECKPIN, INPUT_PULLUP);
    // // if (CHECK)
    //   // print("Hello Nanit! 3.1\n");
    // // if (!CHECK)
    // //   print("Hello Nanit! 2.0\n");
    // Display.print("Hello Nanit!");
    //       //   delay(10000);
    //     };*/
    // }
    // _strip_led.show();
  };
  inline ~Nanit()=default;
  FastLED_NeoPixel<1, BUILDIN_STRIP_LED, NEO_GRB> _strip_led;
  public:
  Adafruit_ST7735 Display;
};
} // namespace NanitRobot

#endif

