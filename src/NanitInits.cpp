// #include "NanitInits.h"
#include "NanitLib.h"




Servo nanit_servo;
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RES);


void Nanit_Display_Init()
{
  tft.initR(INITR_BLACKTAB);
  
  tft.fillScreen(ST7735_WHITE);
  tft.setTextColor(ST7735_BLACK);

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  //виводимо тестове повідомлення
  tft.setCursor(10, 10);
  tft.setTextWrap(true);
  tft.setRotation(1);
  tft.setTextSize(2);
  #define HELLO "Hello Nanit      "
  tft.print(String(HELLO "ver ") + StrVersion(getBoardVersion()) +
            "   Batt Power       " +
            ::NanitRobot::Nanit::getNanit().getBattaryPower() + "%");
}


void Nanit_RGB_Init()
{
  pinMode(P4_4, OUTPUT); //red, порт або P4_6(стара версія), або P4_4
  pinMode(P4_2, OUTPUT); //green
  pinMode(P4_3, OUTPUT); //blue
}

void Nanit_Servo_Init()
{
  nanit_servo.attach(P2_3); //42 = P2_3
}


void Nanit_ActiveBuzz_Init()
{
  pinMode(P5_4, OUTPUT); // 33 - це P5_6 (стара версія), або P5_4
}

void Nanit_Sound_Init()
{
  pinMode(P5_1, INPUT);
  pinMode(P5_2, INPUT);
}





