#ifndef NANITLIB_H_
#define NANITLIB_H_

#define NANIT_MAJOR_VERSION (1)  ///< Головна версія бібліотеки
#define NANIT_MINOR_VERSION (3)  ///< Мінорна версія бібліотеки
#define NANIT_PATHC_VERSION (4)  ///< Pathc версія бібілотеки

#define NANIT_SERIAL_SPEED (9600)  ///< Швидкість серійного порту

#include "Approof/Approof.hpp"
#include "Version.hpp"

#ifdef __AVR_ATmega2560__
/**
 * @brief Пін підключення батареї вхід АЦП для перевірки стану батареї доступний
 * лише для читання
 */
#define BATTARY_PIN (69)

/**
 * @brief Пін підключення вбудованого адресного світлодіоду доступний лише для
 * запису
 */
#define BUILDIN_STRIP_LED (27)
// /**
//  * Піни які відрізняються в різних версіях плати
//  */

/** @defgroup DiffPin Ремапінг пінів
 *
 * @details
 *
 * Це група пінів які у версіях плати старішої за `3.1` мали інше
 * макровизначення.
 *
 * Для збереження сумісності з новими платами значення цих маровизначень
 * визначається в _RunTime_ - мікроконтролер апаратно чи програмно визначає
 * версію лати
 *
 * | Макровизначення |<3.1|>=3.1|
 * |:----------------|:--:|:---:|
 * | MOTOR1_A        |    |     |
 * | MOTOR1_B        |    |     |
 * | P1_4            |    |     |
 * | P1_3            |    |     |
 * | P8_3            |    |     |
 * | P10_3           |    |     |
 * | P10_2           |    |     |
 * | P7_4            |    |     |
 * | P9_4            |    |     |
 * @{
 */
/**
 * @brief Пін керування вбудованим драйвером двигуна, яки підключено
 * до виводу __А__ двигуна 1.
 *
 * @details В силу специфіки внутрішного розведення плати пін доступний лише на
 * запис (виведення інформації)
 *
 */
#define MOTOR1_A ((getBoardVersion() >= Version(3, 1)) ? (7) : (10))

/**
 * @brief Пін керування вбудованим драйвером двигуна, який підключено до виводу
 * __B__ двигуна 1.
 *
 * @details В силу специфіки внутрішного розведення плати пін доступний лише
 * на запис (виведення інформації)
 *
 */
#define MOTOR1_B ((getBoardVersion() >= Version(3, 1)) ? (8) : (9))

/**
 * @brief Четвертий пін першого порту
 */
#define P1_4 ((getBoardVersion() >= Version(3, 1)) ? (7) : (10))

/**
 * @brief Третій пін першого порту
 *
 */
#define P1_3 ((getBoardVersion() >= Version(3, 1)) ? (8) : (9))

/**
 * @brief Третій пін восьмого порту
 */
#define P8_3 ((getBoardVersion() >= Version(3, 1)) ? (5) : (54))

/**
 * @brief Третій пін десятого порту
 */
#define P10_3 ((getBoardVersion() >= Version(3, 1)) ? (24) : (5))

/**
 * @brief Другий пін десятого порту
 *
 */
#define P10_2 ((getBoardVersion() >= Version(3, 1)) ? (54) : (24))

/**
 * @brief Четвертий пін сьомого порту
 */
#define P7_4 ((getBoardVersion() >= Version(3, 1)) ? (9) : (7))

/**
 * @brief Четветрий пін дев'ятого порту
 *
 */
#define P9_4 ((getBoardVersion() >= Version(3, 1)) ? (10) : (8))

/** @}*/

/**
 * @brief Пін запуску драйверу моторів
 *
 * @details для дозволу обертання двигунів цей пін має мати високий рівень
 * доступний лише для запису
 *
 */
#define MOTOR_ENABLE (40)

/**
 * @brief Перевірка стану драйверу моторів
 *
 * @details Доступний лише для читання
 */
#define MOTOR_FAIL (41)

/**
 * @brief Пін А другого двигуна (доступний тільки на виведення)
 */
#define MOTOR2_A (11)

/**
 * @brief Пін B другого двигуна (доступний тільки на виведення)
 */
#define MOTOR2_B (12)

#define BUTTON (3)  ///< Сенсорна кнопка підключена до роз'єму \b J3
#define J_7    (18)  ///< Роз'єм на платі \b J7

//
/**
 * @brief Другий пін першого порту може використовуватися як вхід АЦП
 */
#define P1_2 (A6)

/**
 * @brief Перший пін Першого порту може використовуватися як вхід АЦП
 *
 */
#define P1_1 (A7)

//Порт 2
// #define P2_6 A8
/**
 * @brief Четвертий пін другого потру може використовувватися як вхід АЦП
 *
 */
#define P2_4 (A8)

/**
 * @brief Третій пін другого порту
 *
 */
#define P2_3 (42)

/**
 * @brief Другий пін другого потру може використовувватися як вхід АЦП
 *
 */
#define P2_2 (A9)

/**
 * @brief Перший пін другого потру може використовувватися як вхід АЦП
 *
 */
#define P2_1 (A10)

///Порт 3
// #define P3_6 31 /// Стара версія
#define P3_4 (31)
#define P3_3 (30)
#define P3_2 (25)

/**
 * @brief  Пін визначений у розширеному ядрі `MEGACORE`
 *
 * @details У стандарному інтерфейсі Arduino цей пін не доступний. На платах
 * Arduino на яких використовується мікроконтролер ATMega2560 цей виввід
 * контролера не розведений на платі. На платах Nanit цей пін розведений та
 * доступний для використання. Щоб у повній мірі використовувати всі можлтвості
 * плати потрібно встановити мануально розширене ядро `MEGACORE`, або
 * скористатись менеджером плат
 *
 * Альтернативний спосіб викорстання виводу це звернення на апаратоному рівні до
 * __PE6__
 */
#define P3_1 (71)
#ifdef MEGACORE

#else
#warning Install Nanit board manager
#warning https://nanitrobot.github.io/package_NanitRobot_index.json
#endif

//Порт 4
// #define P4_6 (46) // ШІМ, червоний світлодіод (стара версія)
#define P4_4 (46)  // ШІМ, червоний світлодіод
#define P4_3 (45)  // ШІМ, синій світлодіод
#define P4_2 (44)  // ШІМ, зелений світлодіод

/**
 * @brief Перший пін четвертого порту може використовувватися як вхід АЦП
 */
#define P4_1 (A11)

//Порт 5
// #define P5_6 33 /// Стара версія
#define P5_4 (33)

/**
 * @brief Третій пін п'ятого порту може використовувватися як вхід АЦП
 */
#define P5_3 (A12)

/**
 * @brief Другий пін п'ятого порту може використовувватися як вхід АЦП
 */
#define P5_2 (A1)

/**
 * @brief Перший пін п'ятого порту може оброблювати переривання за вектором
 *
 * INT.0
 */
#define P5_1 (2)

//Порт 6
// #define P6_6 22 /// Стара версія
/**
 * @brief Четвертий пін шостого порту
 */
#define P6_4 (22)

/**
 * @brief Третій пін шостого порту, може використовуватись як вхід АЦП
 */
#define P6_3 (A13)

/**
 * @brief Другий пін шостого порту, може використовуватись як вхід АЦП
 */
#define P6_2 (A14)

/**
 * @brief Перший пін шостого порту
 *
 */
#define P6_1 (23)

//Порт 7
/**
 * @brief Третій пін сьомого порту
 */
#define P7_3 (28)

/**
 * @brief Другий пін сьомого порту, може викорстовуватись як вхід АЦП
 */
#define P7_2 (A4)

/**
 * @brief Перший пін сьомого потру, може використовуватись як вхід АЦП
 */
#define P7_1 (A3)

//Порт 8
// #define P8_4 ()  //< RESET
#define P8_3 (5)  ///<
// #define P8_2 ()  ///<
// #define P8_1 ()  ///<

//Порт 9
/**
 * @brief Третій пін п'ятого порту може оброблювати переривання за вектором
 * INT.2 pin
 */
#define P9_3 (19)
#define P9_2 (20)  ///< SDA
#define P9_1 (21)  ///< SCL

//Порт 10
// #define P10_6 (6)  /// Стара версія
/**
 * @brief Четвертий пін десятого порту
 */
#define P10_4 (6)

/**
 * @brief Перший пін деятого порту, може використовувтись як вхід АЦП
 */
#define P10_1 (A2)
///Порт 11
// #define P11_6 (32)   /// Стара версія
#define P11_4 (32)  ///< Четрвертий пін одинадцятого порту
#define P11_3 (43)  ///< Третій пін одинадцятого порту

///Порт 12
// #define P12_6 (11)/// Мотор М2_А /// Стара версія
/**
 * @brief Четвертий пін дванадцятого порту (доступний тільки на виведення)
 */
#define P12_4 (MOTOR2_A)

/**
 * @brief Третій пін дванадцятого порту (доступний тільки на виведення)
 */
#define P12_3 (MOTOR2_B)
#define P12_2 (34)  ///< Другий пін дванадцятого порту
#define P12_1 (36)  ///< Перший пін дванадцятого порту

//порти дисплею

#define TFT_CS   (48)  ///< Пін для роботи з картою пам'яті та дисплеєм
#define TFT_RES  (37)  ///< Пін для роботи з картою пам'яті та дисплеєм
#define TFT_DC   (49)  ///< Пін для роботи з картою пам'яті та дисплеєм
#define TFT_BL   (4)  ///< Підсвідка дисплею пін доступний лише для запису
#define TFT_SCK  (52)  ///< Пін для роботи з картою пам'яті та дисплеєм
#define TFT_MOSI (51)  ///< Пін для роботи з картою пам'яті та дисплеєм

// Контроль заряду батареї
// Опорна напруга АЦП
/**
 * @brief Опорна напруга для вбулованого АЦП (5 вольт)
 */
#define AVCC_REF (5.f)
// Розрядність АЦП

/**
 * @brief Визначення розміру бітрейту АЦП
 *
 * @details ATMega2560 має 10 розрядний перетворювач
 *
 */
#define ADC_BITRATE (10)

/**
 * @brief Визначення рівня повного рівня заряду викорисатної батареї а блоці.
 * Змінна введена на випадок, якщо в подальшому модернізації плати буде замінено
 * тип батареї
 */
#define BAT_FULL_CHARGE (4.19f)

// Яка батарея використовується
/**
 * Визначає тип використаної батареї Визначення введене для випадок зміни типу
 * батареї в процесі розвитку проекту
 */
#define LI_ION

#elif 0  //
         // тут будуть знаходитись визначення якщо в процесі розвитку проекту
         // буде замінено мікроконтролер щоб зберігти сумісність з версіями
         // плати на ATmega2560
#else
// Повідомлення що потрібно використовувати розширене ядро Arduino MEGACORE
#warning Check the project settings. Invalid microcontroller selected. This project cannot be built for this processor
#endif

#include "DependsLib.h"  ///< Залежності від бібліотек третіх сторін
#include "NanitInits.h"
#include "SerialNumber.hpp"  /// < Контроль версії бібліотеки та плати під час виконання коду

/**
 * @brief Отримати версію плати
 */
Version getBoardVersion();

/**
 * @brief Отримати версію бібліотеки
 */
Version getLibVersion();

/**
 * @brief Отримати серійний номер плати
 *
 * Серійний номер плати читається з вбудованої пам'яті
 */
String getSerialNumber();

/**
 * Вивести на дисплей інформацію про \b Nanit
 */
void NanitInfo();

/**
 * @brief Керування RGB-світлодіодом.
 *
 * Функція керує режимами роботи світлодіода що підключено до порту 4
 * Таблиця підключення світлодіода
 * |Пін|Макровизначення|Вивід світлодіода|
 * |:-:|:-------------:|:---------------:|
 * | 2 |  ```P4_2```   |        G        |
 * | 3 |  ```P4_3```   |        B        |
 * | 4 |  ```P4_4```   |        R        |
 * | - |     НЕМА      |       GND       |
 *
 * Якщо світлодіод підключено до іншого порту та за іншою схемою працездатність
 * методу НЕ ҐАРАНТУЄТЬСЯ
 * @param red рівень яскравості червоного кристалу світодіода
 * @param green рівень яскравості зеленого кристалу світодіода
 * @param blue рівень яскравості синьго кристалу світодіода
 *
 * В рівні яскравості можга записувати значення від 0 до 255, де 0 -- вказує, що
 * обраний кристал світлодіода вимкнено, а 255 -- кристал світиться максимальною
 * яскравістю. Інші значення, що лежать в межах від 0 до 255 вказують ступінь
 * яскравості обраного кристалу світодіоду.
 */
void Nanit_RGB_Write(byte red, byte green, byte blue);

void Nanit_Servo_Rotate(byte angle);

void Nanit_ActiveBuzz_Scream(byte times, int duration);

bool Nanit_Sound_IsSoundDetected(int sound_limit);

#define START_NANIT ::NanitRobot::Nanit::getNanit()
#define GET_NANIT   ::NanitRobot::Nanit::getNanit()

#define NANIT_BEGIN(X)                                                         \
  ::NanitRobot::Nanit &X { START_NANIT }

/**
 * @defgroup ServiceMode Тестування цілісності кабелів
 *
 * @brief Інструкція як перевірити цілісність кабелі з роз'ємами _RJ-12_
 * @{
 *
 * Активація режиму діагностики
 * ============================
 *
 * У новій версії бібліотеки передбачена можливість самодіагностики набору.
 *  1. Вимкнути головний блок
 *  2. Підключити будь-яки кабель до головного блоку з'єднавши між собою __1__
 * та __12__ порти
 *  3. Увімкнути головни блок. Головний блок перейде в режим тестування
 * комплектних кабелів
 *  4. З'днати між собою кабелем який тестується порти 5 та 6 для перевірки його
 * цілісності
 *  6. Зчитати з дисплею результат тестування
 *  7. Від'єднати кабель, що протестовано.
 *  8. За потреби протестувати інший кабель перейти до кроку 4.
 *  9. Вимкнути головний блок.
 *  10. Відключити від головного блоку кабель активації тежиму тестування
 *  11. Діагностика кабелів завершена
 *
 *
 *
 */
/**@}*/

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
  enum class GuageType {  ///< Типи індикторів батареї
    SmileBatt,  ///< індикатор батареї у вигляді "емоційної батарейки"
    Simple,     ///< простий індикатор батарейки
    LAST
  };
  /**
   * Отримати адресу розміщення створеного об'єкту класу Nanit
   */
  inline static Nanit &getNanit() {
    static Nanit instance;
    return instance;
  }

  /**
   * @brief Увімкнути підсвідку дисплея
   *
   */
  void backlightOn();

  /**
   * @brief Вимкнути підсвідку дисплея
   *
   */
  void backlightOff();

  /**
   * @brief Встановити рівень яскравості підсвідки
   *
   * @param brightness[in] Рівень яскравості
   *
   * При яскравості рівній \b 0 робота методу тотожна \code backlightOff()
   * Максимальна можлива яскаравість \b 255 . Будьте обережні з числами що
   * перевищують значення 255 (переповнення)
   */
  void backlightSet(uint8_t brightness);

  /**
   * @brief Get the Batary Voltage object
   *
   * @return float
   */
  float getBataryVoltage() const;
  /**
   * @brief Get the Battary Power object
   *
   * @return float
   */
  float getBattaryPower() const;

  /**
   * @brief
   *
   * @param type
   */
  void DrawBattGuage(GuageType type = GuageType::Simple) const;
#if DEVELOP
  class NanitMotors {
   public:
    NanitMotors(){};
    //   void End() {}
    //   void Roll() {}
    //   void Brake() {}
    //   void Forward() {}
    //   void Reverse() {}
    //   void Run(signed short speed1, signed short speed2) {}
  } DCMotors;  // // 2 & 11
#endif
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

  /**
   * @brief Визначення кольору світіння вбудованого світлодіода
   *
   * @param red[in] Рівень яскравості червоного кристалу
   * @param grean[in] Рівень яскравості зеленого кристалу
   * @param blue[in] Рівень яскравості синього кристалу
   * @param brightness[in] Загальний рівень світіння кристалів
   *
   * Всі параметри можуть приймати значення від \b 0 до \b 255
   */
  void BuildinRGB(uint8_t red, uint8_t grean, uint8_t blue,
                  uint8_t brightness = 255);
  /**
   * @brief Визначення кольору світіння вбудованого світлодіода
   *
   * @param color[in] Визначення кольору світіння всіх трьох кристалів. Число
   * може примати 32бітне значення. Перший байт відповідає за червоний кристал,
   * другий -- зелений, третій -- синій
   * @param brightness[in] Визначає рівень яскравості світіння всіх кристалів
   * одночасно
   */
  void BuildinRGB(uint32_t color, uint8_t brightness = 255);
  Servo ServoMotor;

 private:
  /**
   * @brief Об'єк ткласу Nanit є об'єктом одинаком.
   *
   * Якщо об'єкт не був створений у оперативній пам'яті ми його створюєм. Якщо
   * об'єкт вже існував в пам'яті то ми отримаємо адресу розміщення. Такий
   * спосіб не дозволяє не обмежено створювати об'єкти і дозволяє лише один раз
   * ініціювати необхідні змінні для подальшого використання
   */
  inline Nanit() : Display{Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RES)} {
    if (!Serial) Serial.begin(NANIT_SERIAL_SPEED);
    Serial.println("Nanit initialise...");
    _strip_led.begin();

    Display.initR(INITR_BLACKTAB);

    Display.fillScreen(_background_color);
    Display.setTextColor(ST7735_BLACK);

    pinMode(TFT_BL, OUTPUT);
    backlightSet(200);
    Display.setRotation(1);
    {
      //==================================================================
      //   Сервісні режими для перевірки плати
      //==================================================================
      //------------------------------------------------------------------
      //   Діагностування портів
      //------------------------------------------------------------------
      pinMode(J_7, INPUT_PULLUP);
      if (!digitalRead(J_7)) {
        Display.println();
        Display.println(" Port diagnostics mode.");
        Display.println();
        Display.println(" You should have a probe");
        Display.println("     to connect to the  ");
        Display.println("     ports              ");
        PinTestSetup();
        while (!digitalRead(J_7)) PinTestLoop();
      }

      //------------------------------------------------------------------
      //   Кабелів
      //------------------------------------------------------------------
      pinMode(P1_2, INPUT_PULLUP);
      pinMode(P12_2, INPUT_PULLUP);
      if (!digitalRead(P1_2) and !digitalRead(P12_2)) {
        Display.fillScreen(0xFFFF);

#define PIN_COUNT  (6)
#define NO_CABLE   ((1 << PIN_COUNT) - 1)  ///< мітка
#define GOOD_CABLE (0)  ///< Мітка успішного тесту кабелю
        // Конфігурування  відображення
        const uint16_t               // Кольори
            TextColor{0x0},          // тексту
            GoodColor{0x00FF >> 3},  // цілого кабелю
            NoColor{0xC00},          // відсутнього кабелю
            BadColor{0xF800};        // пошкодженого кабелю

        //
        const char            // Умовні позначик
            CHAR('#'),        //
            CharBroken{'X'},  // пошкоджена жила
            CharGood{'Y'},    // ціла жила
            CharNO{'O'};      // відсутній кабель

        //
        uint8_t               //
            PinsPositionX,    //
            PinsPositionY,    //
            ResultPositionY,  //
            ResultPositionX;  //

        unsigned     //
            fps{2};  // Кількість "кадрів" Чатота оновлення екрану

        Display.setCursor(0, 0);
        Display.print(CHAR);
        const char CharWitdh{Display.getCursorX()};
        Display.println();
        const char CharHeiht{Display.getCursorY()};

        Display.fillRect(0, 0, CharWitdh * 2, CharHeiht, _background_color);
        Display.setCursor(0, 0);
        {
          Display.setTextColor(TextColor);
          Display.println();
          Display.println(" +--------------------+");
          Display.println(" | Cable test mode    |");
          Display.println(" |   USE 5&6 ports    |");
          Display.print(" | ");
          {
            Display.setTextColor(BadColor);
            Display.print(CharBroken);
            Display.setTextColor(TextColor);
          }

          Display.println(" - Broken         |");
          Display.print(" | ");
          {
            Display.setTextColor(GoodColor);
            Display.print(CharGood);
            Display.setTextColor(TextColor);
          }
          Display.println(" - Linked         |");
          Display.print(" | ");
          {
            Display.setTextColor(NoColor);
            Display.print(CharNO);
            Display.setTextColor(TextColor);
          }
          Display.println(" - No cable       |");
          Display.println(" |                    |");
          Display.println(" |     PORT 6         |");
          Display.println(" |    |^^^^^^|        |");
          Display.print(" |    |");

          PinsPositionX = Display.getCursorX();
          PinsPositionY = Display.getCursorY();
          Display.setTextColor(NoColor);

          for (uint8_t wire{}; wire < PIN_COUNT; wire++) {
            Display.print(CharNO);
          }

          Display.setTextColor(TextColor);
          Display.println("|        |");
          Display.println(" |    +--__--+        |");
          Display.println(" |       --           |");

          ResultPositionY = Display.getCursorY();
          Display.print(" |");
          ResultPositionX = Display.getCursorX();
          Display.println("                    |");
          Display.println(" +--------------------+");
        }
        while (true) {
          Display.fillRect(PinsPositionX, PinsPositionY, CharWitdh * PIN_COUNT,
                           CharHeiht, _background_color);
          Display.fillRect(ResultPositionX, ResultPositionY, CharWitdh * 20,
                           CharHeiht, _background_color);
          char BrokenWires = WireManipulate();
          switch (BrokenWires) {
            case NO_CABLE:
              Display.setCursor(PinsPositionX, PinsPositionY);
              Display.setTextColor(NoColor);
              for (uint8_t wire{}; wire < PIN_COUNT; wire++)
                Display.print(CharNO);
              Display.setCursor(ResultPositionX, ResultPositionY);
              Display.print("      NO CABLE");
              break;

            case GOOD_CABLE:
              Display.setCursor(PinsPositionX, PinsPositionY);
              Display.setTextColor(GoodColor);
              for (uint8_t wire{}; wire < PIN_COUNT; wire++)
                Display.print(CharGood);
              Display.setCursor(ResultPositionX, ResultPositionY);
              Display.print("       GOOD");
              break;

            default:
              Display.setCursor(PinsPositionX, PinsPositionY);
              for (uint8_t wire{}; wire < PIN_COUNT; wire++)
                if (BrokenWires & (1 << wire)) {
                  Display.setTextColor(BadColor);
                  Display.print(CharBroken);
                } else {
                  Display.setTextColor(GoodColor);
                  Display.print(CharGood);
                }

              Display.setTextColor(BadColor);
              Display.setCursor(ResultPositionX, ResultPositionY);
              Display.print("       BAD");
              break;
          }

          delay(static_cast<unsigned>(1000 / fps));
        };
        // while (!(!digitalRead(A6) and !digitalRead(34)))
        //   ;
        for (;;)  // LOCK CODE FLOW
          ;
      }
    }

    // APROOF_MODE;
  };

  /*
   * Приватний метод використовується при тестування кібелів які йдуть в
   * комплекті з Наніт Для активації режиму тестування потрібно включити кабель
   * у 12 та перший порти. Це ключ для входу в режим тестування
   *
   * Для тестування кабелів використувуються 5 та 6 порти
   *
   * @return Функція повертає цілочисельне значення яке вказує на номер
   * токоведучої жилки яка пошкоджена. Якщо кабель цілий то функція поверне
   * НУЛЬ. Всі інші значення вказують що кабель пошкоджено
   */

  uint8_t WireManipulate() const;
  /**
   * @brief Destroy the Nanit object
   *
   */
  Nanit(const Nanit &) = delete;  // rule of three
  Nanit &operator=(const Nanit &) = delete;
  inline ~Nanit() = default;
  FastLED_NeoPixel<1, BUILDIN_STRIP_LED, NEO_GRB> _strip_led;
  //
  uint16_t  //
      _background_color{
          ST7735_WHITE},  ///<  визначає колір фону вікна.
                          ///<  Використвується при замальовуванні елементів
      _guage_line_color{0x0000},  ///< Колір промальовування лійній
                                  ///< індикатора заряду
      _guage_full_charge_color{0x04A0},  ///< Колір індикатора заряду при
                                         ///< повному заряді вищому за 80%
      _guage_80_charge_color{0x06A0},  ///< Колір індикатора заряду
                                       ///< при рівні заряду нижчому за 80%
      _guage_60_charge_color{0xFF00},  ///< Колір індикатора заряду
                                       ///< при рівні заряду нижчому за 60%
      _guage_40_charge_color{0xFCA0},  ///< Колір індикатора заряду
                                       ///< при рівні заряду нижчому за 40%
      _guage_20_charge_color{0xC800};  ///< Колір індикатора заряду
                                       ///< при рівні заряду нижчому за 20%

  uint8_t                 //
      _guage_X_position,  //
      _guage_Y_position;  //

 public:
  Adafruit_ST7735  //
      Display;     ///< Дисплей Nanit
};
}  // namespace NanitRobot

/**
 * Ініціація змінних та дисплею
 *
 * Використовується для ініціалізації внутнішніх змінних та дисплею плати Наніт.
 *
 */
void Nanit_Base_Start();

#endif
