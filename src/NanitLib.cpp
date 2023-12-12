#include "NanitLib.h"

Version getBoardVersion() {
  pinMode(BOARD_DETECT_PIN, INPUT_PULLUP);
  if (digitalRead(BOARD_DETECT_PIN)) return Version(2);
  if (!digitalRead(BOARD_DETECT_PIN)) return Version(3, 1);
}

Version getLibVersion() {
  return Version(NANIT_MAJOR_VERSION, NANIT_MINOR_VERSION, NANIT_PATCH_VERSION);
}

bool digitalRead(const uint8_t pin, const uint16_t maxValue,
                        const uint16_t minValue = 0) {
  static bool PrevState[NUM_DIGITAL_PINS]{};
  const uint16_t readedValue = analogRead(pin);
  bool State;
  if (!minValue or (minValue >= maxValue)) {
    State = readedValue > maxValue;
    return State;
  }

  if (PrevState[pin]) {
    if (readedValue >= minValue)
      return true;
    else {
      PrevState[pin] = false;
      return false;
    }
  }
  else {
    if (readedValue <= minValue)
      return false;
    else {
      PrevState[pin] = true;
      return true;
    }
  }
};

String getSerialNumber() {
  if (!checkSerialNum(getSerialNum())) {
    //Запрошення на дисплей підключити до серійного порту
    START_NANIT.Display.setCursor(10, 100);
    START_NANIT.Display.setTextSize(0);
    START_NANIT.Display.print("Please open terminal");
  }
  const long WAIT_FIRST_RUN{30};
  while (!checkSerialNum(getSerialNum())) {
    // допоки не отримаємо серійний номер нічого не вийде
    Serial.println("Please enter correct serial nummer\n");
    unsigned long unlock{millis() + (WAIT_FIRST_RUN * 1000)};
    while (Serial.available() == 0) {
      if (millis() > unlock) {
        setSerialNum(1010123000);
        Serial.println("A gray serial number");
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
  
  String StringSerialNumber = String(getSerialNum());
  while (StringSerialNumber.length() < 10) 
  StringSerialNumber = "0" + StringSerialNumber;
  return StringSerialNumber;
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
  START_NANIT.Display.print("Bat. " + String(START_NANIT.getBatteryPower()) +
                            "%");

  START_NANIT.Display.setCursor(5, 120);
  START_NANIT.Display.setTextSize(0);
  START_NANIT.Display.print(__DATE__ " " __TIME__);

  START_NANIT.Display.setCursor(15, 110);
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

  analogWrite(P4_4, red);  // 46 це або P4_4, або P4_6 (стара версія)
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

bool isClapping() {
 uint16_t signal = analogRead(P5_2);
  delayMicroseconds(300);
  static float                     //
      MiddleLine = signal,         // Рівень тишини
      SoundBorder = signal + 100;  // Рівень хлопку

  constexpr float  //
      k = 0.01,  // Коефіуцієт фільрації рівня тишини
      k2 = 0.02;  // коефіцієнт фільтрації порогового рівня

  static_assert(k < k2, "k2 не може бути меншим за k");

  MiddleLine += (signal - MiddleLine) * k;

  if (signal > MiddleLine) SoundBorder += (signal - SoundBorder) * k2;
  const float//
   KoefNoClap = 4,// Коефіцієнт не чутливості
   shift = 20;
  float //
  top = MiddleLine + (SoundBorder - MiddleLine) * KoefNoClap + shift,// Верхній поріг
  butt = MiddleLine - (SoundBorder - MiddleLine) * KoefNoClap - shift;// Нижній поріг
  return (signal > top) or (signal < butt);
}


bool isLight(){
  uint8_t light = analogRead(P10_2)>>2;
  static uint8_t min_light = light, max_light = light;
  min_light = min(min_light, light);
  max_light = max(max_light, light);

  constexpr uint8_t k_adaptation = 32;
  if((max_light - min_light)>k_adaptation){
    min_light+=1;
    max_light-=1;
  }
  uint8_t medium = min_light + ((max_light - min_light) >> 1);
  return light>medium;
}


bool isRightLine(uint8_t sen=k_adap){
  uint8_t light = analogRead(P10_2)>>2;
  static uint8_t min_light = light, max_light = light;
  min_light = min(min_light, light);
  max_light = max(max_light, light);

  if((max_light - min_light)>sen){
    min_light+=1;
    max_light-=1;
  }
  uint8_t medium = min_light + ((max_light - min_light) >> 1);

  return light<medium;
}

bool isLeftLine(uint8_t sen=k_adap){
  uint8_t light = analogRead(P10_1)>>2;
  static uint8_t min_light = light, max_light = light;
  min_light = min(min_light, light);
  max_light = max(max_light, light);

  if((max_light - min_light)>sen){
    min_light+=1;
    max_light-=1;
  }
  uint8_t medium = min_light + ((max_light - min_light) >> 1);

  return light<medium;
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

float NanitRobot::Nanit::getBatteryVoltage() const {
  return Map(analogRead(BATTERY_PIN), 0.f, 1 << ADC_BITRATE, 0.f, AVCC_REF);
}

float NanitRobot::Nanit::getBatteryPower() const {
  float voltage{getBatteryVoltage()};
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
  if (voltage > BAT_FULL_CHARGE) return 100.f;
#else
  if (voltage > 4.24f) return 100.f;
#endif
  if (4.24f > voltage and voltage > 4.08f)
    return NanitRobot::Map(voltage, 4.24f, 4.08f, 100.f, 85.f);  // 1
  if (4.08f > voltage and voltage > 4.06f)
    return NanitRobot::Map(voltage, 4.08f, 4.06f, 85.f, 81.7f);  // 2
  if (4.06f > voltage and voltage > 4.02f)
    return NanitRobot::Map(voltage, 4.06f, 4.02f, 81.7f, 76.7f);  // 3
  if (4.02f > voltage and voltage > 3.98f)
    return NanitRobot::Map(voltage, 4.02f, 3.98f, 76.7f, 73.4f);  // 4
  if (3.98f > voltage and voltage > 3.88f)
    return NanitRobot::Map(voltage, 3.98, 3.88, 73.4, 58.4);  // 5
  if (3.88f > voltage and voltage > 3.8f)
    return NanitRobot::Map(voltage, 3.88f, 3.8f, 58.4f, 22.f);  // 6
  if (3.8f > voltage and voltage > 3.68f)
    return NanitRobot::Map(voltage, 3.88f, 3.68f, 22.f, 8.7f);  // 7
  if (3.68f > voltage and voltage > 3.54f)
    return NanitRobot::Map(voltage, 3.68f, 3.54f, 8.7f, 5.4f);  // 8
  if (3.54f > voltage and voltage > 3.32f)
    return NanitRobot::Map(voltage, 3.54, 3.32, 5.4, 2.1);  // 9
  if (3.32f > voltage and voltage > 3.f)
    return NanitRobot::Map(voltage, 3.32f, 3.f, 2.1f, .5f);  // 10
  if (3.f > voltage and voltage > 2.5f)
    return NanitRobot::Map(voltage, 3.f, 2.5f, .5f, .0f);  // 11
#else
#error No battery type specified
#endif
  // if (2.5f > voltage)
  return .0f;
}

void ::NanitRobot::Nanit::DrawBattGuage(
    GuageType type = GuageType::Simple) const {
  uint8_t Power{getBatteryPower()};
  uint16_t color{};

  const int SIZE_Y = (17);

  const int X = ((160 - 15) - 2);
  const int Y = (2);

  color = _guage_20_charge_color;
  if (Power > 20) color = _guage_40_charge_color;
  if (Power > 40) color = _guage_60_charge_color;
  if (Power > 60) color = _guage_80_charge_color;
  if (Power > 80) color = _guage_full_charge_color;
  switch (type) {
    case GuageType::SmileBatt: {
      // face
      {
        Display.fillRect(X + 3, Y + 3, 10, map(Power, 0, 100, SIZE_Y - 1, 0),
                         _background_color);  // empty
        Display.fillRect(X + 3, Y + 3 + map(Power, 0, 100, SIZE_Y - 1, 0), 10,
                         map(Power, 100, 0, SIZE_Y - 1, 1), color);  // cherged

        Display.drawPixel(X + 3, Y + 3, _guage_line_color);
        Display.drawPixel(X + 12, Y + 3, _guage_line_color);
        Display.drawPixel(X + 3, Y + SIZE_Y + 2, _guage_line_color);
        Display.drawPixel(X + 12, Y + SIZE_Y + 2, _guage_line_color);
      }
      // aye
      {
        Display.drawLine(X + 4, Y + 6, X + 6, Y + 6, _guage_line_color);
        Display.drawLine(X + 9, Y + 6, X + 11, Y + 6, _guage_line_color);
        Display.drawLine(X + 10, Y + 5, X + 10, Y + 7, _guage_line_color);
      }
      {  // SMILE
        //  100
        if (color == _guage_full_charge_color) {
          Display.drawPixel(X + 10, Y + 9, _guage_line_color);
          Display.drawPixel(X + 5, Y + 9, _guage_line_color);
          Display.drawPixel(X + 9, Y + 10, _guage_line_color);
          Display.drawPixel(X + 6, Y + 10, _guage_line_color);
          Display.drawLine(X + 7, Y + 11, X + 8, Y + 11, _guage_line_color);
        }
        // 80

        if (color == _guage_80_charge_color) {
          Display.drawLine(X + 5, Y + 9, X + 6, Y + 9, _guage_line_color);
          Display.drawLine(X + 9, Y + 9, X + 10, Y + 9, _guage_line_color);
          Display.drawLine(X + 7, Y + 10, X + 8, Y + 10, _guage_line_color);
        }
        // 60

        if (color == _guage_60_charge_color)
          Display.drawLine(X + 5, Y + 10, X + 10, Y + 10, _guage_line_color);
        // 40

        if (color == _guage_40_charge_color) {
          Display.drawLine(X + 5, Y + 10, X + 6, Y + 10, _guage_line_color);
          Display.drawLine(X + 9, Y + 10, X + 10, Y + 10, _guage_line_color);
          Display.drawLine(X + 7, Y + 9, X + 8, Y + 9, _guage_line_color);
        }
        // 20

        if (color == _guage_20_charge_color) {
          Display.drawLine(X + 7, Y + 9, X + 8, Y + 9, _guage_line_color);
          Display.drawPixel(X + 6, Y + 10, _guage_line_color);
          Display.drawPixel(X + 9, Y + 10, _guage_line_color);
          Display.drawPixel(X + 5, Y + 11, _guage_line_color);
          Display.drawPixel(X + 10, Y + 11, _guage_line_color);
        }
      }  // 0
      {  // BACK_GROUND
        Display.drawLine(X + 0x5, Y, X + 0xA, Y, _background_color);
        Display.drawLine(X + 0x3, Y + 0x1, X + 12, Y + 1, _background_color);
        Display.drawLine(X + 2, Y + 2, X + 13, Y + 2, _background_color);
        Display.drawLine(X + 1, Y + 3, X + 1, Y + SIZE_Y + 2,
                         _background_color);
        Display.drawLine(X + 14, Y + 3, X + 14, Y + SIZE_Y + 2,
                         _background_color);

        Display.drawPixel(X + 2, Y + SIZE_Y + 2, _background_color);
        Display.drawPixel(X + 13, Y + SIZE_Y + 2, _background_color);

        Display.drawPixel(X + 3, Y + SIZE_Y + 3, _background_color);
        Display.drawPixel(X + 12, Y + SIZE_Y + 3, _background_color);
        Display.drawLine(X + 3, Y + SIZE_Y + 4, X + 12, Y + SIZE_Y + 4,
                         _background_color);
      }
      {  // BODY
        Display.drawLine(X + 6, Y + 1, X + 9, Y + 1, _guage_line_color);
        Display.drawLine(X + 4, Y + 2, X + 11, Y + 2, _guage_line_color);
        Display.drawLine(X + 2, Y + 4, X + 2, Y + SIZE_Y + 1,
                         _guage_line_color);
        Display.drawLine(X + 13, Y + 4, X + 13, Y + SIZE_Y + 1,
                         _guage_line_color);
        Display.drawLine(X + 4, Y + SIZE_Y + 3, X + 11, Y + SIZE_Y + 3,
                         _guage_line_color);
      }
    } break;
    case GuageType::Simple: {
      {
        Display.fillRect(X - 1, Y, map(Power, 0, 100, SIZE_Y - 1, 0), 10,
                         _background_color);

        Display.fillRect(X - 1 + map(Power, 0, 100, SIZE_Y - 1, 0) - 2, Y,
                         map(Power, 100, 0, SIZE_Y , 1), 10,
                         color);  // cherged

        Display.drawLine(X - 4, Y + 3, X - 4, Y + 6, _guage_line_color);  // |1
        Display.drawLine(X - 3, Y + 1, X - 3, Y + 8, _guage_line_color);  // |1
        Display.drawLine(SIZE_Y + X - 3, Y + 1, X + SIZE_Y - 3, Y + 8,
                         _guage_line_color);  // |2

        Display.drawLine(X - 2, Y, X + SIZE_Y - 4, Y,
                         _guage_line_color);  // _top

        Display.drawLine(X - 2, Y + 9, X + SIZE_Y - 4, Y + 9,
                         _guage_line_color);  // _buttom
      }
    } break;
    case GuageType::LAST: {
    } break;

    default:
      break;
  }
}

void ::NanitRobot::Nanit::BuildinRGB(uint8_t red, uint8_t grean, uint8_t blue,
                                     uint8_t brightness = 255) {
  _strip_led.setBrightness(brightness);
  _strip_led.setPixelColor(0, _strip_led.Color(red, grean, blue));
  _strip_led.show();
}

void ::NanitRobot::Nanit::BuildinRGB(uint32_t color, uint8_t brightness = 255) {
  _strip_led.setPixelColor(0, color);
  _strip_led.show();
}

void ::NanitRobot::Nanit::backlightOff() { backlightSet(0x00); };
void ::NanitRobot::Nanit::backlightOn() { backlightSet(0xFF); };

void ::NanitRobot::Nanit::backlightSet(uint8_t brightness) {
  analogWrite(TFT_BL, brightness);
};

uint8_t ::NanitRobot::Nanit::WireManipulate() const {
  uint8_t                                  //
      result{0};                           //
  const uint16_t                           //
                                           // VCC{1 << ADC_BITRATE},  //
      Near{20},                            //
      NearVCC{(1 << ADC_BITRATE) - Near},  //
      NearGND{Near};

  // ПЕРША ЖИЛА
  {  // todo дописатииманіпуляцію жилами
    // маніпулюємо лінією П5_1
    pinMode(P5_1, OUTPUT);
    // і слухаємо лінію П6_4
    pinMode(P6_4, INPUT_PULLUP);
    // digi
    // digitalWrire(P5_1,0);
    delay(1);
    // якщо сигнал слідує за маніпуляцією лінія ціла
    if (digitalRead(P6_4))
      // інакше позначаємо її як бита
      result |= 1 << 0;
  }

  // ДРУГА ЖИЛА
  // Читаємо аналогий сигнал П5_2 якщо сигнал близький до GND лінія ціла
  if (analogRead(P5_2) > NearGND)
    // інакше позгачаємо її битою
    result |= 1 << 1;

  // ТРЕТЯ ЖИЛА
  // читаємно аналоговий сигнал, якщо він близький до Vcc лінія ціла
  if (analogRead(P5_3) < NearVCC)
    // інакше позгачаємо її битою
    result |= 1 << 2;

  // ЧЕТВЕРТА ЖИЛА
  {
    pinMode(P5_4, OUTPUT);
    pinMode(P6_1, INPUT_PULLUP);
    // digitalWrire(33,0);
    delay(1);
    if (digitalRead(P6_1)) result |= 1 << 3;
  }

  // П'ЯТА ЖИЛА
  // Читаємо аналогий сигнал П6_2 якщо сигнал близький до GND лінія ціла
  if (analogRead(P6_2) > NearGND)
    // інакше позгначаємо її битою
    result |= 1 << 4;

  // ШОСТА ЖИЛА
  // читаємно аналоговий сигнал, якщо він близький до Vcc лінія ціла
  if (analogRead(P6_3) < NearVCC)
    // інакше позгачаємо її битою
    result |= 1 << 5;
  return result;
}
