#include "NanitLib.h"

Version getBoardVersion() {
  pinMode(39, INPUT_PULLUP);
  if (digitalRead(39))
    return Version(2);
  if (!digitalRead(39))
    return Version(3, 1);
}

Version getLibVersion() {
  return Version(NANIT_MAJOR_VERSION, NANIT_MINOR_VERSION, NANIT_PATHC_VERSION);
}

String getSerialNumber() {
  if(!checkSerialNum(getSerialNum())){
    //Запрошення на дисплей підключити до серійного порту    
  START_NANIT.Display.setCursor(10, 100);
  START_NANIT.Display.setTextSize(0);
    #define WAIT_FIRST_RUN (30)
  START_NANIT.Display.print("Please open terminal");
  }
  while (!checkSerialNum(getSerialNum())) {
    // допоки не отримаємо серійний номер нічого не вийде
    Serial.println("Please enter correct serial nummer");
    unsigned long unlock{millis()+(WAIT_FIRST_RUN*1000)};
    while (Serial.available() == 0) {
      if(millis()>unlock){
        setSerialNum(1010123000);
      }
    }
    serial_num SerialNumber = Serial.parseInt();

    if (checkSerialNum(SerialNumber)) {
      setSerialNum(SerialNumber);

      Serial.print("Serial number set to ");
      Serial.print(getSerialNumber());
      return String(SerialNumber);
    }
  }
  return String(getSerialNum());
};

void NanitInfo() {

  START_NANIT.Display.setCursor(10, 10);
  START_NANIT.Display.setRotation(1);
  START_NANIT.Display.setTextSize(2);
  START_NANIT.Display.print("Hello Nanit!");
  START_NANIT.Display.setCursor(10, 30);
  START_NANIT.Display.print("  v" + StrVersion(getBoardVersion()));
  START_NANIT.Display.setCursor(10, 50);
  START_NANIT.Display.print("Lib v" + StrVersion(getLibVersion()));
  START_NANIT.Display.setCursor(10, 70);
  START_NANIT.Display.print("Bat. " + String(START_NANIT.getBattaryPower()) +
                            "%");
  START_NANIT.Display.setCursor(10, 120);
  START_NANIT.Display.setTextSize(0);
  START_NANIT.Display.print("SN " + getSerialNumber());
  START_NANIT.BuildinRGB(0xff);
  delay(500);
  START_NANIT.BuildinRGB(0xff00);
  delay(500);
  START_NANIT.BuildinRGB(0xff0000);
  delay(500);
  START_NANIT.BuildinRGB(0x0);
}

void Nanit_Base_Start() { Nanit_Display_Init(); }

void Nanit_RGB_Write(byte red, byte green, byte blue) {
  red = (red >= 0 && red <= 255) ? red : 0;
  green = (green >= 0 && green <= 255) ? green : 0;
  blue = (blue >= 0 && blue <= 255) ? blue : 0;

  analogWrite(P4_4, red); // 46 це або P4_4, або P4_6 (стара версія)
  analogWrite(P4_2, green);
  analogWrite(P4_3, blue);
}

void Nanit_Servo_Rotate(byte angle) {
  angle = (angle >= 0 && angle <= 180) ? angle : 0;
  nanit_servo.write(angle);
}

void Nanit_ActiveBuzz_Scream(byte times, int duration) {
  byte i;

  times = (times > 0) ? times : 1;

  for (i = 0; i < times; i++) {
    digitalWrite(P5_4, LOW);
    delay(duration);
    digitalWrite(P5_4, HIGH);
    delay(duration);
  }

  // round(millis() / 500) % 2 == 0
}

bool Nanit_Sound_IsSoundDetected(int sound_limit) {
  return (analogRead(P5_2) > sound_limit);
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

float NanitRobot::Map(float inputValue, float inputMin, float inputMax,
                      float rangeMin, float rangeMax) {
  return static_cast<float>(inputValue - inputMin) * (rangeMax - rangeMin) /
             static_cast<float>(inputMax - inputMin) +
         rangeMin;
}

float NanitRobot::Nanit::getBataryVoltage() const {
  return Map(analogRead(BATTARY_PIN), 0.f, 1 << ADC_BITRATE, 0.f, AVCC_REF);
}

float NanitRobot::Nanit::getBattaryPower() const {
  float voltage{getBataryVoltage()};
#if defined(LI_ION)
  /*
  +---+-----------+----------+
  | # |   Volts   |    %     |
  +---+-----------+----------+
  | 1 | 4.08-4.24 | 85-100   |
  | 2 | 4.06-4.08 | 85-81.7  |
  | 3 | 4.02-4.06 | 81.7-76.7|
  | 4 | 3.98-4.02 | 73.4-76.7|
  | 5 | 3.88-3.98 | 58.4-73.4|
  | 6 | 3.8-3.88  | 22-58.4  |
  | 7 | 3.68-3.8  | 8.7-22   |
  | 8 | 3.54-3.68 | 5.4-8.7  |
  | 9 | 3.32-3.54 | 2.1-5.4  |
  | 10| 3-3.32    | 0.5-2.1  |
  | 11| 2.5-3     | 0-0.5    |
  +---+-----------+----------+
  */
#if defined(BAT_FULL_CHARGE)
  if (voltage > BAT_FULL_CHARGE)
    return 100.f;
#else
  if (voltage > 4.24f)
    return 100.f;
#endif
  if (4.24f > voltage and voltage > 4.08f)
    return NanitRobot::Map(voltage, 4.24f, 4.08f, 100.f, 85.f); // 1
  if (4.08f > voltage and voltage > 4.06f)
    return NanitRobot::Map(voltage, 4.08f, 4.06f, 85.f, 81.7f); // 2
  if (4.06f > voltage and voltage > 4.02f)
    return NanitRobot::Map(voltage, 4.06f, 4.02f, 81.7f, 76.7f); // 3
  if (4.02f > voltage and voltage > 3.98f)
    return NanitRobot::Map(voltage, 4.02f, 3.98f, 76.7f, 73.4f); // 4
  if (3.98f > voltage and voltage > 3.88f)
    return NanitRobot::Map(voltage, 3.98, 3.88, 73.4, 58.4); // 5
  if (3.88f > voltage and voltage > 3.8f)
    return NanitRobot::Map(voltage, 3.88f, 3.8f, 58.4f, 22.f); // 6
  if (3.8f > voltage and voltage > 3.68f)
    return NanitRobot::Map(voltage, 3.88f, 3.68f, 22.f, 8.7f); // 7
  if (3.68f > voltage and voltage > 3.54f)
    return NanitRobot::Map(voltage, 3.68f, 3.54f, 8.7f, 5.4f); // 8
  if (3.54f > voltage and voltage > 3.32f)
    return NanitRobot::Map(voltage, 3.54, 3.32, 5.4, 2.1); // 9
  if (3.32f > voltage and voltage > 3.f)
    return NanitRobot::Map(voltage, 3.32f, 3.f, 2.1f, .5f); // 10
  if (3.f > voltage and voltage > 2.5f)
    return NanitRobot::Map(voltage, 3.f, 2.5f, .5f, .0f); // 11
#else
#error No battery type specified
#endif
  // if (2.5f > voltage)
  return .0f;
}

void NanitRobot::Nanit::DrawBattGuage(
    GuageType type = GuageType::SmileBatt) const {
  uint8_t Power{getBattaryPower()};
  uint16_t color{};
#define SIZE_Y (17)

#define X ((160 - 15) - 2)
#define Y (2)

#define ICON_BACKGROUND_COLOR (0xffff)
#define ICON_LINE_COLOR (0x0000)
#define ICON_FULL_CHARGE_COLOR (0x04A0)
#define ICON_80_CHARGE_COLOR (0x06A0)
#define ICON_60_CHARGE_COLOR (0xFF00)
#define ICON_40_CHARGE_COLOR (0xFCA0)
#define ICON_20_CHARGE_COLOR (0xC800)

  color = ICON_20_CHARGE_COLOR;
  if (Power > 20)
    color = ICON_40_CHARGE_COLOR;
  if (Power > 40)
    color = ICON_60_CHARGE_COLOR;
  if (Power > 60)
    color = ICON_80_CHARGE_COLOR;
  if (Power > 80)
    color = ICON_FULL_CHARGE_COLOR;
  switch (type) {
  case GuageType::SmileBatt: {
    // face
    {
      Display.fillRect(X + 3, Y + 3, 10, map(Power, 0, 100, SIZE_Y - 1, 0),
                       ICON_BACKGROUND_COLOR); // empty
      Display.fillRect(X + 3, Y + 3 + map(Power, 0, 100, SIZE_Y - 1, 0), 10,
                       map(Power, 100, 0, SIZE_Y - 1, 1), color); // cherged

      Display.drawPixel(X + 3, Y + 3, ICON_LINE_COLOR);
      Display.drawPixel(X + 12, Y + 3, ICON_LINE_COLOR);
      Display.drawPixel(X + 3, Y + SIZE_Y + 2, ICON_LINE_COLOR);
      Display.drawPixel(X + 12, Y + SIZE_Y + 2, ICON_LINE_COLOR);
    }
    // aye
    {
      Display.drawLine(X + 4, Y + 6, X + 6, Y + 6, ICON_LINE_COLOR);
      Display.drawLine(X + 9, Y + 6, X + 11, Y + 6, ICON_LINE_COLOR);
      Display.drawLine(X + 10, Y + 5, X + 10, Y + 7, ICON_LINE_COLOR);
    }
    { // SMILE
      //  100
      if (color == ICON_FULL_CHARGE_COLOR) {
        Display.drawPixel(X + 10, Y + 9, ICON_LINE_COLOR);
        Display.drawPixel(X + 5, Y + 9, ICON_LINE_COLOR);
        Display.drawPixel(X + 9, Y + 10, ICON_LINE_COLOR);
        Display.drawPixel(X + 6, Y + 10, ICON_LINE_COLOR);
        Display.drawLine(X + 7, Y + 11, X + 8, Y + 11, ICON_LINE_COLOR);
      }
      // 80

      if (color == ICON_80_CHARGE_COLOR) {
        Display.drawLine(X + 5, Y + 9, X + 6, Y + 9, ICON_LINE_COLOR);
        Display.drawLine(X + 9, Y + 9, X + 10, Y + 9, ICON_LINE_COLOR);
        Display.drawLine(X + 7, Y + 10, X + 8, Y + 10, ICON_LINE_COLOR);
      }
      // 60

      if (color == ICON_60_CHARGE_COLOR)
        Display.drawLine(X + 5, Y + 10, X + 10, Y + 10, ICON_LINE_COLOR);
      // 40

      if (color == ICON_40_CHARGE_COLOR) {
        Display.drawLine(X + 5, Y + 10, X + 6, Y + 10, ICON_LINE_COLOR);
        Display.drawLine(X + 9, Y + 10, X + 10, Y + 10, ICON_LINE_COLOR);
        Display.drawLine(X + 7, Y + 9, X + 8, Y + 9, ICON_LINE_COLOR);
      }
      // 20

      if (color == ICON_20_CHARGE_COLOR) {
        Display.drawLine(X + 7, Y + 9, X + 8, Y + 9, ICON_LINE_COLOR);
        Display.drawPixel(X + 6, Y + 10, ICON_LINE_COLOR);
        Display.drawPixel(X + 9, Y + 10, ICON_LINE_COLOR);
        Display.drawPixel(X + 5, Y + 11, ICON_LINE_COLOR);
        Display.drawPixel(X + 10, Y + 11, ICON_LINE_COLOR);
      }
    } // 0
    { // BACK_GROUND
      Display.drawLine(X + 0x5, Y, X + 0xA, Y, ICON_BACKGROUND_COLOR);
      Display.drawLine(X + 0x3, Y + 0x1, X + 12, Y + 1, ICON_BACKGROUND_COLOR);
      Display.drawLine(X + 2, Y + 2, X + 13, Y + 2, ICON_BACKGROUND_COLOR);
      Display.drawLine(X + 1, Y + 3, X + 1, Y + SIZE_Y + 2,
                       ICON_BACKGROUND_COLOR);
      Display.drawLine(X + 14, Y + 3, X + 14, Y + SIZE_Y + 2,
                       ICON_BACKGROUND_COLOR);

      Display.drawPixel(X + 2, Y + SIZE_Y + 2, ICON_BACKGROUND_COLOR);
      Display.drawPixel(X + 13, Y + SIZE_Y + 2, ICON_BACKGROUND_COLOR);

      Display.drawPixel(X + 3, Y + SIZE_Y + 3, ICON_BACKGROUND_COLOR);
      Display.drawPixel(X + 12, Y + SIZE_Y + 3, ICON_BACKGROUND_COLOR);
      Display.drawLine(X + 3, Y + SIZE_Y + 4, X + 12, Y + SIZE_Y + 4,
                       ICON_BACKGROUND_COLOR);
    }
    { // BODY
      Display.drawLine(X + 6, Y + 1, X + 9, Y + 1, ICON_LINE_COLOR);
      Display.drawLine(X + 4, Y + 2, X + 11, Y + 2, ICON_LINE_COLOR);
      Display.drawLine(X + 2, Y + 4, X + 2, Y + SIZE_Y + 1, ICON_LINE_COLOR);
      Display.drawLine(X + 13, Y + 4, X + 13, Y + SIZE_Y + 1, ICON_LINE_COLOR);
      Display.drawLine(X + 4, Y + SIZE_Y + 3, X + 11, Y + SIZE_Y + 3,
                       ICON_LINE_COLOR);
    }
  } break;
  case GuageType::LAST: {
  } break;

  default:
    break;
  }
}
