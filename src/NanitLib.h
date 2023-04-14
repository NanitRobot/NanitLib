#ifndef NANITLIB_H_
#define NANITLIB_H_

#define NANIT_MAJOR_VERSION (1)
#define NANIT_MINOR_VERSION (3)
#define NANIT_PATHC_VERSION (1)

#include "Version.hpp"
#if defined(__AVR_ATmega2560__)

// Пін до якого включена батарея
#define BATTARY_PIN (69)
#define BUILDIN_STRIP_LED (27)


#define  MOTOR1_A ((getBoardVersion()>=Version(3,1))?(7):(10))
#define  MOTOR1_B ((getBoardVersion()>=Version(3,1))?(8):(9))
#define  P1_4 ((getBoardVersion()>=Version(3,1))?(7):(10))
#define  P1_3 ((getBoardVersion()>=Version(3,1))?(8):(9))
#define  P8_3 ((getBoardVersion()>=Version(3,1))?(5):(54))
#define  P10_3 ((getBoardVersion()>=Version(3,1))?(24):(5))
#define  P10_2 ((getBoardVersion()>=Version(3,1))?(54):(24))
#define  P7_4 ((getBoardVersion()>=Version(3,1))?(9):(7)) 
#define  P9_4 ((getBoardVersion()>=Version(3,1))?(10):(8))



//запустить драйвер на мотор
#define MOTOR_ENABLE (40) 

#define MOTOR2_A (11)
#define MOTOR2_B (12)

#define BUTTON (3) 

///Порт 1
#define P1_2 (A6) 
#define P1_1 (A7) 

///Порт 2
// #define P2_6 A8  
#define P2_4 (A8)
#define P2_3 (42) 
#define P2_2 (A9)
#define P2_1 (A10)

///Порт 3
// #define P3_6 31 /// Стара версія
#define P3_4 (31)
#define P3_3 (30)
#define P3_2 (25)
#ifdef MEGACORE
#define P3_1 (71)
#else
  #warning Install Nanit board manager 
  #warning https://nanitrobot.github.io/package_NanitRobot_index.json
#endif

///Порт 4
// #define P4_6 (46) // ШІМ, червоний світлодіод (стара версія)
#define P4_4 (46) // ШІМ, червоний світлодіод
#define P4_3 (45) // ШІМ, синій світлодіод
#define P4_2 (44) // ШІМ, зелений світлодіод
#define P4_1 (A11)

///Порт 5
// #define P5_6 33 /// Стара версія
#define P5_4 (33) 
#define P5_3 (A12)
#define P5_2 (A1)
#define P5_1 (2) // INT.0 pin

///Порт 6
// #define P6_6 22 /// Стара версія
#define P6_4 (22)
#define P6_3 (A13)
#define P6_2 (A14)
#define P6_1 (23)

///Порт 7
#define P7_3 (28)
#define P7_2 (A4)
#define P7_1 (A3)

///Порт 8


///Порт 9
#define P9_3 (19)  /// INT.2 pin
#define P9_2 (20) //SDA
#define P9_1 (21) //SCL

///Порт 10
// #define P10_6 (6)  /// Стара версія
#define P10_4 (6)
#define P10_1 (A2)

///Порт 11
// #define P11_6 (32)   /// Стара версія
#define P11_4 (32)
#define P11_3 (43)

///Порт 12
// #define P12_6 (11)/// Мотор М2_А /// Стара версія
#define P12_4 (11)
#define P12_3 (12)/// Мотор М2_В
#define P12_2 (34)
#define P12_1 (36)

//порти дисплею

#define TFT_CS (48) 
#define TFT_RES (37)
#define TFT_DC (49)
#define TFT_BL (4)
#define TFT_SCK (52)
#define TFT_MOSI (51)



// Контроль заряду батареї
// Опорна напруга АЦП
#define AVCC_REF (5.f)
// Розрядність АЦП
#define ADC_BITRATE (10)
#define BAT_FULL_CHARGE (4.19f)
// Яка батарея використовується
#define LI_ION
// #elif 0
#else
#error Check the project settings. Invalid microcontroller selected. This project cannot be built for this processor
#endif
#include "DependsLib.h"
#include "NanitInits.h"
#include "SerialNumber.hpp"
// #include <L298NX2.h>

// #include <Servo.h>

Version getBoardVersion();
Version getLibVersion();
String getSerialNumber();
void NanitInfo();

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

#define NANIT_BEGIN(X)                                                   \
  ::NanitRobot::Nanit &X { START_NANIT }

namespace NanitRobot {
/**
 * @brief Мапінг функція для чисел з плаваючою крапкою
 * 
 * @param inputValue[in] значення яке потрібно промаштабувати
 * @param inputMin[in] Нижній поріг значань які потрібно промаштабувати
 * @param inputMax[in] Верхній поріг значень, які потрібно промаштвабувати
 * @param rangeMin[in] Нижня межа значень діапазону вихідних значень
 * @param rangeMax[in] Верхня межа значень діапазону вихідних значень
 * @return повертає маштабоване значення
*/  
float Map(float inputValue, float inputMin, float inputMax, float rangeMin,
          float rangeMax);
          
class Nanit {
public:

enum class GuageType{SmileBatt,Volts,Percent,LAST};

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
  // L298NX2 DCMotors(MOTOR_ENABLE, MOTOR1_A, MOTOR2_A, MOTOR_ENABLE, MOTOR1_B, MOTOR2_B);
  // 1 & 12 motors
  // class DCMotor {
  // public:
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
}// namespace NanitRobot

#endif

