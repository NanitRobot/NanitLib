/**
 * @file NanitLib.h
 * @author NanitRobots (https://nanitrobot.com/)
 * @authors NanitRobots,Sam4uk
 *
 * @if English
 * @brief The main file of the NanitLib library
 * @else
 * @brief Головний файл бібіліотеки NanitLib
 * @endif
 *
 * @copyright Copyright (c) NanitRobots
 *
 */
#ifndef NANITLIB_H_
#define NANITLIB_H_

/** @if English
 * @brief The main version of the library
 * @else
 * @brief Головна версія бібліотеки
 * @endif
 */

#define NANIT_MAJOR_VERSION (1)

/** @if English
 * @brief The minor version of the library
 * @else
 * @brief Мінорна версія бібліотеки
 * @endif
 */
#define NANIT_MINOR_VERSION (3)

/** @if English
 * @brief Patch version of the library
 * @else
 * @brief Pathc версія бібілотеки
 * @endif
 */
#define NANIT_PATCH_VERSION (9)

/** @if English
 * @brief Serial port baud rate
 * @else
 * @brief Швидкість серійного порту
 * @endif
 */
#define NANIT_SERIAL_SPEED (9600)

#include "Approof/Approof.hpp"
#include "DependsLib.h"  // Залежності від бібліотек третіх сторін
#include "NanitColors.hpp"
#include "NanitInits.h"
#include "SerialNumber.hpp"  // Контроль версії бібліотеки та плати під час виконання коду
#include "Version.hpp"

#ifdef __AVR_ATmega2560__

/** @if English
 * @brief Hardware version checking pin
 * @details Used to determine the board versions greater than or equal to `3.1`
 * @else
 * @brief Використовується для визначення плат версій старших  або рівних від
 * `3.1`
 * @details
 * @endif
 */
#define BOARD_DETECT_PIN (39)

/** @if English
 * @brief Hardware version checking pin
 * @details The battery status check ADC input pin is read-only
 * @else
 * @brief Пін підключення батареї вхід АЦП для перевірки стану батареї доступний
 * лише для читання
 * @details
 * @endif
 */
#define BATTERY_PIN (69)

/** @if English
 * @brief  The built-in addressable LED pin is write-only
 * @else
 * @brief Пін підключення вбудованого адресного світлодіоду доступний лише для
 * запису
 * @endif
 */
#define BUILDIN_STRIP_LED (27)

/**
 * Обмежений тираж Лед кільце отримувало сигнал з вбудованого світлодіоду
 */
#ifndef LED_RING_LIMIT_EDITION
/**
 * @if English
 * @brief The pins through which Nanit transmits commands to the LED ring
 * @else
 * @brief Піни через які `Nanit` передає команди для Лед кільця
 * @endif
 */
#define LED_RING_TX (13)
#else
#define LED_RING_TX (BUILDIN_STRIP_LED)
#endif

/**
 * @if English
 * @brief The pins through which Nanit receives data from the LED ring
 * @else
 * @brief Піни через які `Nanit` отримує дані з лед кільця
 * @endif
 */
#define LED_RING_RX (38)

/**
 * @if English
 * @brief Data exchange speed between the LED ring and `Nanit`
 * @details The LED ring operates on an external `RC` oscillator. The stability
 * of the oscillator's frequency depends on the crystal temperature and supply
 * voltage. Since the frequency can _drift_ due to external influences, the data
 * exchange speed is reduced for more stable communication.
 * @note It's not advisable to set the speed too high. While stability improves,
 * _brakes_ in the data transfer process increase (Animation effects are paused
 * during command transmission.)
 * @else
 * @brief Швидкість обмніну даними між лед кільцем та `Nanit`
 * @details Лед кільце працює не вбудованому `RC` генераторі. Стабільгість
 * частоти генератора сильно залежить від температури кристалу та напруги
 * живлення. Оскільки частота може _пливти_ від зовнішньго впливу - для більш
 * стабільного обміну даними швидкіть знижено.
 * @note Не варто сильно занищувати швидкіть. Стабільнвсть зв'язку збільшується,
 * але при цьому збільшуються _гальма_ в момент передачі ( Анімаційні ефекти
 * призупиняються в момент передачі команд.)
 * @endif
 */
#define UART_LED_SPEED (2400)

/**
 * @if English
 * @defgroup DiffPin Pin remapping
 *
 * @brief This is a group of pins with different internal connections in other
 * board versions
 *
 * @details
 *
 * This is a group of pins that had different macros defined in board versions
 * older than `3.1`. In the process of improving the board, we made some changes
 * to the internal layout and board schematics
 *
 * To maintain compatibility with new boards, the values of these macros are
 * determined at runtime, with the microcontroller hardware or software
 * detecting the board version
 *
 * @else
 *
 * @defgroup DiffPin Ремапінг пінів
 *
 * @brief Це група пінів які мають різне внутрішнє підключення в інших версія
 * плати
 *
 * @details
 *
 * Це група пінів які у версіях плати старішої за `3.1` мали інше
 * макровизначення. Ми в процесі удосконалення плати дещо змінили внутрішню
 * бутова та схему плат
 *
 * Для збереження сумісності з новими платами значення цих маровизначень
 * визначається в _RunTime_ - мікроконтролер апаратно чи програмно визначає
 * версію лати
 *
 * @endif
 *
 * <center>
 * |        MACRO         |<3.1|>=3.1|
 * |:---------------------|:--:|:---:|
 * | @ref MOTOR1_A        |  7 |  10 |
 * | @ref MOTOR1_B        |  8 |  9  |
 * | @ref P1_4            |  7 |  10 |
 * | @ref P1_3            |  8 |  9  |
 * | @ref P7_4            |  9 |  7  |
 * | @ref P8_3            |  5 |  54 |
 * | @ref P9_4            | 10 |  8  |
 * | @ref P10_3           | 24 |  5  |
 * | @ref P10_2           | 54 |  24 |
 * </center>
 *
 * @{
 */

/** @if English
 * @brief The pin for controlling the built-in motor driver, which is connected
 * to the output __A__ of motor 1
 *
 * @details Due to the internal board routing specifics, this pin is available
 * for write-only operations (outputting information)
 *
 * @else
 * @brief Пін керування вбудованим драйвером двигуна, яки підключено
 * до виводу __А__ двигуна 1
 *
 * @details В силу специфіки внутрішного розведення плати пін доступний лише на
 * запис (виведення інформації)
 * @endif
 */
#define MOTOR1_A ((getBoardVersion() >= Version(3, 1)) ? (7) : (10))

/** @if English
 * @brief The pin for controlling the built-in motor driver, which is connected
 * to the output __B__ of motor 1
 *
 * @details Due to the internal board routing specifics, this pin is available
 * for write-only operations (outputting information)
 *
 * @else
 * @brief Пін керування вбудованим драйвером двигуна, яки підключено
 * до виводу __B__ двигуна 1
 *
 * @details В силу специфіки внутрішного розведення плати пін доступний лише на
 * запис (виведення інформації)
 * @endif
 */
#define MOTOR1_B ((getBoardVersion() >= Version(3, 1)) ? (8) : (9))

/** @if English
 * @brief The fourth pin of the first port
 * @else
 * @brief Четвертий пін першого порту
 * @endif
 */
#define P1_4 ((getBoardVersion() >= Version(3, 1)) ? (7) : (10))

/** @if English
 * @brief The third pin of the first port
 * @else
 * @brief Третій пін першого порту
 * @endif
 */
#define P1_3 ((getBoardVersion() >= Version(3, 1)) ? (8) : (9))

/** @if English
 * @brief The third pin of the eighth port
 * @else
 * @brief Третій пін восьмого порту
 * @endif
 */
#define P8_3 ((getBoardVersion() >= Version(3, 1)) ? (5) : (54))

/** @if English
 * @brief The third pin  of the tenth port
 * @else
 * @brief Третій пін десятого порту
 * @endif
 */
#define P10_3 ((getBoardVersion() >= Version(3, 1)) ? (24) : (5))

/** @if English
 * @brief The second pin of the tenth port
 * @else
 * @brief Другий пін десятого порту
 * @endif
 */
#define P10_2 ((getBoardVersion() >= Version(3, 1)) ? (54) : (24))

/** @if English
 * @brief The fourth pin of the seventh port
 * @else
 * @brief Четвертий пін сьомого порту
 * @endif
 */
#define P7_4 ((getBoardVersion() >= Version(3, 1)) ? (9) : (7))

/** @if English
 * @brief The fourth pin of the ninth port
 * @else
 * @brief Четветрий пін дев'ятого порту
 * @endif
 */
#define P9_4 ((getBoardVersion() >= Version(3, 1)) ? (10) : (8))

/** @}*/

/** @if English
 * @brief Motor driver enable pin
 *
 * @details To enable motor rotation, this pin must have a high level. It is
 * available for write-only operations.
 * @else
 * @brief Пін запуску драйверу моторів
 *
 * @details для дозволу обертання двигунів цей пін має мати високий рівень
 * доступний лише для запису.
 * @endif
 */
#define MOTOR_ENABLE (40)

/** @if English
 * @brief Check the state of the motor driver
 * @details Available for read-only operations.
 * @else
 * @brief Перевірка стану драйверу моторів
 *
 * @details Доступний лише для читання.
 * @endif
 */
#define MOTOR_FAIL (41)

/** @if English
 * @brief Pin __A__ of the second motor (available for output only)
 * @else
 * @brief Пін __А__ другого двигуна (доступний тільки на виведення)
 * @endif
 */
#define MOTOR2_A (11)

/** @if English
 * @brief Pin __B__ of the second motor (available for output only)
 * @else
 * @brief Пін __B__ другого двигуна (доступний тільки на виведення)
 * @endif
 */
#define MOTOR2_B (12)

/** @if English
 * @brief A touch button is connected to connector \b J3
 * @else
 * @brief Сенсорна кнопка підключена до роз'єму \b J3
 * @endif
 */
#define BUTTON (3)

/** @if English
 * @brief Connector on the board \b J7
 * @else
 * @brief Роз'єм на платі \b J7
 * @endif
 */
#define J_7 (18)

/** @if English
 * @brief The second pin of the first port can be used as an ADC input
 * @else
 * @brief Другий пін першого порту може використовуватися як вхід АЦП
 * @endif
 */
#define P1_2 (A6)

/** @if English
 * @brief The first pin of the first port can be used as an ADC input
 * @else
 * @brief Перший пін Першого порту може використовуватися як вхід АЦП
 * @endif
 */
#define P1_1 (A7)

/** @if English
 * @brief The fourth pin of the second port can be used as an ADC input
 * @else
 * @brief Четвертий пін другого порту може використовувватися як вхід АЦП
 * @endif
 */
#define P2_4 (A8)

/** @if English
 * @brief The third pin of the second port
 * @else
 * @brief Третій пін другого порту
 * @endif
 */
#define P2_3 (42)

/** @if English
 * @brief The second pin of the second port can be used as an ADC input
 * @else
 * @brief Другий пін другого порту може використовувватися як вхід АЦП
 * @endif
 */
#define P2_2 (A9)

/** @if English
 * @brief The first pin of the second port can be used as an ADC input
 * @else
 * @brief Перший пін другого порту може використовувватися як вхід АЦП
 * @endif
 */
#define P2_1 (A10)

// Порт 3
// #define P3_6 31 /// Стара версія

/** @if English
 * @brief The fourth pin of the third port
 * @else
 * @brief Четвертий пін третього порту
 * @endif
 */
#define P3_4 (31)

/** @if English
 * @brief The third pin of the third port
 * @else
 * @brief Третій пін третього порту
 * @endif
 */
#define P3_3 (30)

/** @if English
 * @brief The second pin of the third port
 * @else
 * @brief Другий пін третього порту
 * @endif
 */
#define P3_2 (25)
// clang-format off
/** @defgroup MEGACORE MEGACORE
 *
 *
 * @if English
 * @brief About the advanced core MEGACORE
 * @else
 * @brief Про розширене ядро MEGACORE
 * @endif
 *
 *
 * @if English
 * @details In the standard Arduino interface, this pin is not available
 * On Arduino boards that use the `ATMega2560` microcontroller, this
 * microcontroller pin is not routed on the board. On `Nanit` boards, this
 * pin is routed and available for use. To fully utilize all the capabilities of
 * the board, you need to manually install the `MEGACORE` advanced core or
 * use the board manager
 * @else
 * @details У стандарному інтерфейсі Arduino цей пін не доступний. На платах
 * Arduino на яких використовується мікроконтролер `ATMega2560` цей вивід
 * мікроконтролера не розведений на платі. На платах Nanit цей пін розведений та
 * доступний для використання. Щоб у повній мірі використовувати всі можлтвості
 * плати потрібно встановити мануально розширене ядро `MEGACORE`, або
 * скористатись менеджером плат
 * @endif
 * 
 * @image html https://raw.githubusercontent.com/NanitRobot/NanitLib/main/pic/MegaCorePinOut.png "MegaCore Pinout" width=50%
 *
 * @if English
 * An alternative way to use the output is by accessing the level registers
 * of __PE6__
 * @else
 * Альтернативний спосіб викорстання виводу це звернення рівні регістрів до
 * __PE6__
 * @endif
 *
 */
// clang-format on
#ifdef MEGACORE

/** @if English
 * @brief The first pin of the third port
 *
 * @note The pin is defined in the `MEGACORE` advanced core
 *
 * @details In the standard Arduino interface, this pin is not available
 * On Arduino boards that use the ATMega2560 microcontroller, this
 * microcontroller pin is not routed on the board. On `Nanit` boards,
 * this pin is routed and available for use. To learn more, refer to the
 * @ref MEGACORE section of this documentation.
 * @else
 *
 * @brief Перший пін третього порту
 *
 * @note  Пін визначений у розширеному ядрі `MEGACORE`
 *
 * @details У стандарному інтерфейсі Arduino цей пін не доступний. На платах
 * Arduino на яких використовується мікроконтролер ATMega2560 цей вивід
 * мікроконтролера не розведений на платі. На платах Nanit цей пін розведений та
 * доступний для використання. Дізнатись більше можна у розділі @ref MEGACORE
 * цієї документації.
 * @endif
 */
#define P3_1 (71)
#else
#warning Install Nanit board manager https://nanitrobot.github.io/NanitLib/package_NanitCore_index.json
#endif

/** @}*/

// Порт 4
//  #define P4_6 (46) // ШІМ, червоний світлодіод (стара версія)

/** @if English
 * @brief The fourth pin of the fourth port
 * @else
 * @brief Четвертий пін четвертого порту
 * @endif
 */
#define P4_4 (46)  // ШІМ, червоний світлодіод

/** @if English
 * @brief The third pin of the fourth port
 * @else
 * @brief Третій пін четвертого порту
 * @endif
 */
#define P4_3 (45)  // ШІМ, синій світлодіод

/** @if English
 * @brief The second pin of the fourth port
 * @else
 * @brief Другий пін четвертого порту
 * @endif
 */
#define P4_2 (44)  // ШІМ, зелений світлодіод

/** @if English
 * @brief The first pin of the fourth port can be used as an ADC input
 * @else
 * @brief Перший пін четвертого порту може використовувватися як вхід АЦП
 * @endif
 */
#define P4_1 (A11)

// Порт 5
//  #define P5_6 33 /// Стара версія
/** @if English
 * @brief The fourth pin of the fifth port
 * @else
 * @brief Четвертий пін п'ятого порту
 * @endif
 */
#define P5_4 (33)

/** @if English
 * @brief The third pin of the fifth port can be used as an ADC input
 * @else
 * @brief Третій пін п'ятого порту може використовувватися як вхід АЦП
 * @endif
 */
#define P5_3 (A12)

/** @if English
 * @brief The second pin of the fifth port can be used as an ADC input
 * @else
 * @brief Другий пін п'ятого порту може використовувватися як вхід АЦП
 * @endif
 */
#define P5_2 (A1)

/** @if English
 * @brief The first pin of the fifth port can handle interrupts by vector
 * `INT.0`
 * @else
 * @brief Перший пін п'ятого порту може оброблювати переривання за вектором
 * `INT.0`
 * @endif
 */
#define P5_1 (2)

// Порт 6
//  #define P6_6 22 /// Стара версія
/** @if English
 * @brief The fourth pin of the sixth port
 * @else
 * @brief Четвертий пін шостого порту
 * @endif
 */
#define P6_4 (22)

/** @if English
 * @brief The third pin of the sixth port can be used as an ADC input
 * @else
 * @brief Третій пін шостого порту, може використовуватись як вхід АЦП
 * @endif
 */
#define P6_3 (A13)

/** @if English
 * @brief The second pin of the sixth port can be used as an ADC input
 * @else
 * @brief Другий пін шостого порту, може використовуватись як вхід АЦП
 * @endif
 */
#define P6_2 (A14)

/** @if English
 * @brief The first pin of the sixth port
 * @else
 * @brief Перший пін шостого порту
 * @endif
 */
#define P6_1 (23)

// Порт 7
/** @if English
 * @brief The third pin of the seventh port
 * @else
 * @brief Третій пін сьомого порту
 * @endif
 */
#define P7_3 (28)

/** @if English
 * @brief The second pin of the seventh port can be used as an ADC input
 * @else
 * @brief Другий пін сьомого порту, може викорстовуватись як вхід АЦП
 * @endif
 */
#define P7_2 (A4)

/** @if English
 * @brief The first pin of the seventh port can be used as an ADC input
 * @else
 * @brief Перший пін сьомого порту, може використовуватись як вхід АЦП
 * @endif
 */
#define P7_1 (A3)

// Порт 8
/** @if English
 * @brief The pin to which the \b RESET output of the microcontroller is
 * connected
 *
 * @details You cannot use this macro definition in your sketch code.
 * This macro definition is for documentation purposes only to explain the
 * purpose of this pin on the adapter.
 * @else
 * @brief Пін до якого під'єднано вивід  \b RESET мікроконтроллера
 *
 * @details Ви не можете фикористовувати це макровизначення в коді ваших
 * скетчів. Це макровизначення лише для генератора документації, щоб пояснити
 * призначення цього піна на адаптері.
 * @endif
 */
#define P8_4                                                                   \
  #error                                                                       \
      "U can`t use this definision in code. This definision only for "         \
      "doxygen. This is RESET pin ATMega2560"

/** @if English
 * @brief The second pin of the eighth port
 *
 * @details The `RX` of the `Serial` is routed to this pin.
 * @else
 * @brief Другий пін восьмого порту
 *
 * @details На цей пін виведено `RX` `Serial`.
 * @endif
 */
#define P8_2 (0)

/**

 */
/** @if English
 * @brief The first pin of the eighth port
 *
 * @details The `TX` of the `Serial` is routed to this pin.
 * @else
 * @brief Перший пін восьмого порту
 *
 * @details На цей пін виведено `TX` `Serial`.
 * @endif
 */
#define P8_1 (1)

// Порт 9
/** @if English
 * @brief The third pin of the ninth port can handle interrupts by vector
 * `INT.2`
 * @else
 * @brief Третій пін дев'ятого порту може оброблювати переривання за вектором
 * `INT.2`
 * @endif
 */
#define P9_3 (19)

/** @if English
 * @brief The second pin of the ninth port can. It has built-in support for the
 * data line (SDA) of the I2C protocol
 * @else
 * @brief  Другий пін дев'ятого порту може. Має апартану пітримку лінії даних
 * (SDA) пртоколу IIC
 * @endif
 */
#define P9_2 (20)

/** @if English
 * @brief The first pin of the ninth port. It has built-in support for the
 * clock line (SCL) of the I2C protocol
 * @else
 * @brief  Перший пін дев'ятого порту. Має апартану пітримку лінії
 * тактування (SDL) пртоколу IIC
 * @endif
 */
#define P9_1 (21)

// Порт 10
//  #define P10_6 (6)  /// Стара версія
/** @if English
 * @brief The fourth pin of the tenth port
 * @else
 * @brief Четвертий пін десятого порту
 * @endif
 */
#define P10_4 (6)

/** @if English
 * @brief The first pin of the tenth port can be used as an ADC input
 * @else
 * @brief Перший пін деятого порту, може використовувтись як вхід АЦП
 * @endif
 */
#define P10_1 (A2)
// Порт 11
// #define P11_6 (32)   /// Стара версія

/** @if English
 * @brief The fourth pin of the eleventh port
 * @else
 * @brief Четрвертий пін одинадцятого порту
 * @endif
 */
#define P11_4 (32)

/** @if English
 * @brief The third pin of the eleventh port
 * @else
 * @brief Третій пін одинадцятого порту
 * @endif
 */
#define P11_3 (43)

/** @if English
 * @brief The second pin of the eleventh port
 *
 * @details The `RX` of `Serial3` is routed to this pin.
 * @else
 * @brief Другий пін одинадцьятого порту
 *
 * @details На цей пін виведено `RX` `Serial3`.
 * @endif
 */
#define P11_2 (15)

/**

 */
/** @if English
 * @brief The first pin of the eleventh port
 *
 * @details The `TX` of `Serial3` is routed to this pin.
 * @else
 * @brief Перший пін одинадцятого порту
 *
 *
 * @details На цей пін виведено `TX` `Serial3`.
 * @endif
 */
#define P11_1 (14)
// Порт 12
// #define P12_6 (11)// Мотор М2_А //Стара версія

/** @if English
 * @brief The first pin of the twelfth port. (available for output only)
 * @else
 * @brief Четвертий пін дванадцятого порту (доступний тільки на виведення)
 * @endif
 */
#define P12_4 (MOTOR2_A)

/** @if English
 * @brief The third pin of the twelfth port (available for output only)
 * @else
 * @brief Третій пін дванадцятого порту (доступний тільки на виведення)
 * @endif
 */
#define P12_3 (MOTOR2_B)

/** @if English
 * @brief The second pin of the twelfth port
 * @else
 * @brief Другий пін дванадцятого порту
 * @endif
 */
#define P12_2 (34)

/** @if English
 * @brief The first pin of the twelfth port
 * @else
 * @brief Перший пін дванадцятого порту
 * @endif
 */
#define P12_1 (36)

// порти дисплею

/** @if English
 * @brief Pin for working with memory card and display
 * @else
 * @brief Пін для роботи з картою пам'яті та дисплеєм
 * @endif
 */
#define TFT_CS (48)

/** @if English
 * @brief Pin for working with memory card and display
 * @else
 * @brief Пін для роботи з картою пам'яті та дисплеєм
 * @endif
 */
#define TFT_RES (37)

/** @if English
 * @brief Pin for working with memory card and display
 * @else
 * @brief Пін для роботи з картою пам'яті та дисплеєм
 * @endif
 */
#define TFT_DC (49)

/** @if English
 * @brief Display backlight pin (write-only).
 * @else
 * @brief Підсвідка дисплею пін доступний лише для запису
 * @endif
 */
#define TFT_BL (4)

/** @if English
 * @brief Pin for working with memory card and display
 * @else
 * @brief Пін для роботи з картою пам'яті та дисплеєм
 * @endif
 */
#define TFT_SCK (52)

/** @if English
 * @brief Pin for working with memory card and display
 * @else
 * @brief Пін для роботи з картою пам'яті та дисплеєм
 * @endif
 */
#define TFT_MOSI (51)

// Перевизначення LED_BUILTIN
#if defined(LED_BUILTIN) && (LED_BUILTIN == (13))
#undef LED_BUILTIN  //< Перевизначаємо макрос якщо він об'явлений
#define LED_BUILTIN (TFT_BL)
#elif !defined(LED_BUILTIN)

/** @if English
 * @brief We will consider `LED_BUILTIN` as the display backlight in the
 * context of the Nanit board. This means you can use `LED_BUILTIN` to control
 * the backlight of the Nanit's display.
 *
 * @note In the library, the `LED_BUILTIN` value has been redefined to ensure
 * compatibility between Arduino sketches and the Nanit board. This allows you
 * to use `LED_BUILTIN` in your Arduino sketches, and it will work with the
 * `Nanit` board, making it easier to switch between different
 * Arduino-compatible boards and maintain compatibility.
 * @else
 * @brief Будемо вважати, що `LED_BUILTIN` це підсвідка дисплею.
 *
 * @note В бібліотеці ми перевизначили значення `LED_BUILTIN` для збереження
 * сумісності скетчів Ардуїно з нашою платою і навпаки (`Nanit` зі сакетчами
 * `Arduino`)
 * @endif
 */
#define LED_BUILTIN (TFT_BL)
#endif

/** @if English
 * @brief Reference voltage for the embedded ADC (5 volts)
 * @else
 * @brief Опорна напруга для вбулованого АЦП (5 вольт)
 * @endif
 */
#define AVCC_REF (5.f)

/** @if English
 * @brief Definition of the ADC bit rate
 *
 * @details The `ATMega2560` has a 10-bit converter.
 * @else
 * @brief Визначення розміру бітрейту АЦП
 *
 * @details `ATMega2560` має 10 розрядний перетворювач.
 * @endif
 */
#define ADC_BITRATE (10)

/** @if English
 * @brief Definition of the level of the full charge of the used battery in the
 * unit
 *
 * @details The variable is introduced in case the type of the battery is
 * changed in future board upgrades.
 * @else
 * @brief Визначення рівня повного рівня заряду викорисатної батареї а блоці
 *
 * @details Змінна введена на випадок, якщо в подальшому модернізації плати буде
 * замінено тип батареї
 * @endif
 */
#define BAT_FULL_CHARGE (4.19f)

/** @if English
 * @details Determines the type of battery used. This definition is introduced
 * in case the battery type changes during the project's development.
 * @else
 * @details Визначає тип використаної батареї Визначення введене для випадок
 * зміни типу батареї в процесі розвитку проекту.
 * @endif
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

/** @if English
 * @brief Get the board version
 * @else
 * @brief Отримати версію плати
 * @endif
 */
Version getBoardVersion();

/** @if English
 * @brief Get the library version
 * @else
 * @brief Отримати версію бібліотеки
 * @endif
 */
Version getLibVersion();

/** @if English
 * @brief Get the board's serial number
 *
 * The board's serial number is read from the built-in memory
 * @else
 * @brief Отримати серійний номер плати
 *
 * Серійний номер плати читається з вбудованої пам'яті
 * @endif
 */
String getSerialNumber();

/** @if English
 * @brief Display information about \b Nanit on the screen
 * @else
 * @brief Вивести на дисплей інформацію про \b Nanit
 * @endif
 */
void NanitInfo();

/** @if English
 * @brief Control the RGB LED
 *
 * This function controls the operating modes of the LED connected to port 4
 * LED connection table:
 * @else
 * @brief Керування RGB-світлодіодом
 *
 * Функція керує режимами роботи світлодіода що підключено до порту 4
 * Таблиця підключення світлодіода
 * @endif
 * <center>
 * |Pin|      MACRO    |      COLOR      |
 * |:-:|:-------------:|:---------------:|
 * | 2 |  @ref P4_2    |        G        |
 * | 3 |  @ref P4_3    |        B        |
 * | 4 |  @ref P4_4    |        R        |
 * </center>
 *
 *@if English

 * If the LED is connected to a different port and operates under a different
 * scheme, the method's functionality is NOT GUARANTEED.
 * @param [in] red the brightness level of the red LED crystal
 * @param [in] green the brightness level of the green LED crystal
 * @param [in] blue the brightness level of the blue LED crystal
 *
 * @else
 *
 * Якщо світлодіод підключено до іншого порту та за іншою схемою працездатність
 * методу НЕ ҐАРАНТУЄТЬСЯ.
 * @param [in] red рівень яскравості червоного кристалу світодіода
 * @param [in] green рівень яскравості зеленого кристалу світодіода
 * @param [in] blue рівень яскравості синьго кристалу світодіода
 *
 * @endif
 *
 * @if English
 * Brightness levels can be set from `0` to `255`, where `0` indicates that the
 * selected LED crystal is off, and `255` indicates maximum brightness. Other
 * values within the range of `0` to `255` indicate the brightness level of the
 * selected LED crystal.
 * @else
 * В рівні яскравості можга записувати значення від `0` до `255`, де `0` --
 * вказує, що обраний кристал світлодіода вимкнено, а `255` -- кристал світиться
 * максимальною яскравістю. Інші значення, що лежать в межах від `0` до `255`
 * вказують ступінь яскравості обраного кристалу світодіоду.
 * @endif
 */
void Nanit_RGB_Write(byte red, byte green, byte blue);

/** @if English
 * @brief The function detects loud shouting or clapping
 *
 * @details The function filters out any external sounds and determines the
 * level of silence. It also sets a threshold for external noises (music,
 * conversations) near the sensor. The sensor adapts to them.
 *
 * @return true - shouting or clapping detected
 * @return false - no shouts detected
 *
 * @note The function has a damping effect to avoid double triggering from
 * echoes.
 * @else
 * @brief Функція детектидь гучний вигук, або плеск долонями
 *
 * @details У функції відфільтровуються всі сторонні звуки та визначається ріень
 * звуку в стані спокою "тиша". Також задано умовний поріг сторонніх шумів
 * (музика, розмова) поряд з датчиком. Датчик адаптується до них.
 *
 * @return true - зафікосовано вигук чи сплеск дольонями
 * @return false - не зафіксовано вигуків
 *
 * @note Функція має гальмуючий ефект. Це зроблеблено для уникнення подвійного
 * спрацювання від відлуння.
 * @endif
 */
bool isClapping();

/** @if English
 * @brief The function detects changes in ambient lighting
 *
 * @return true - a decrease in the light level has been detected
 * @return false - no decrease in the light level has been detected
 * @else
 * @brief Функція детектить зміну освітлення в оточненні
 *
 * @return true - зафіксовано зниження рівня освітлення
 * @return false - не зафіксовано зниження рівня освітлення
 * @endif
 */

/** @cond */

bool isLight();

// Коефіцієнт адаптації підібрано експериментально
constexpr uint8_t k_adap = 20;

/** @if English
 * @else
 * @brief Датчик ліній правий
 *
 * @return true
 * @return false
 * @endif
 */
bool isRightLine(uint8_t sen = k_adap);
/** @if English
 * @else
 * @brief датчик ліній лівий
 *
 * @return true
 * @return false
 * @endif
 *
 */
bool isLeftLine(uint8_t sen = k_adap);

/**
 * @if English
 * 
 * @else 
 * 
 * @param pulse  Пін який генерує пульсацію
 * @param listen Пін на якому очікуємо пульсацію
 * @param repeat Кількість пульсацій
 * @param wait Затримка в мікросекундах
 * @return true Успішно отримані пульси
 * @return false Пульсацію не отримано
 * @endif
 */
bool pulseAndListen(uint8_t pulse, uint8_t listen, uint8_t repeat=0xF, uint16_t wait=500);

void Nanit_Servo_Rotate(byte angle);

void Nanit_ActiveBuzz_Scream(byte times, int duration);

bool Nanit_Sound_IsSoundDetected(int sound_limit);
/** @endcond */
/** @if English
 * @brief Using an analog input as a digital one
 *
 * @details The function returns true if the read value from the analog input
 * exceeds a certain threshold. If hysteresis is needed, the third parameter
 * specifies the value at which the function returns to the previous state.
 * If the \b minValue is zero, hysteresis is not applied.
 *
 * @param [in] pin The pin from which to read the value
 * @param [in] maxValue When this value is exceeded, the function will return
 * true
 * @param [in] minValue If the previous value returned by the function was true,
 * it will return false only after the analog input drops below this level
 *
 * @return true
 * @return false
 *
 * @else
 *
 * @brief  Використання аналогового входу як цифровий
 *
 * @details Функція повертає істуину якщопрочитане значення з аналогового входу
 * перевищує певне порогове значення. Якщо потрібен гістерезис то третім
 * параметром вказується значення при якому функція пермкнеться на попереднє
 * значення. Якщо значення \b minValue рівне нулю гістерезис не застосовується
 *
 * @param [in] pin Пін з якого потрібно прочитати значення
 * @param [in] maxValue При перевищенні цього значення функція поверне істину
 * @param [in] minValue Якщо попереднє значення повернуте функцією було істина
 * то поверне хибу тільки після того як аналоговий вхід опуститься нижче цього
 * рівня
 *
 * @return true
 * @return false
 *
 * @endif
 */
bool digitalRead(const uint8_t pin, const uint16_t maxValue,  //
                 const uint16_t minValue = 0                  // 10100000
);

/** @if English
 *
 * @brief Calling the PWM signal generation function on a pin
 *
 * @note Pay attention to the possibility of using this macro. Not all pins
 * generate PWM signals in the same way. PWM is generated hardware on some
 * microcontroller pins, while on others, it may add additional load to the
 * processor.
 *
 * @param  PIN pin number
 * @param  VALUE value
 *
 * @else
 *
 * @brief Виклик функції генерації ШІМ сигналу на пін
 *
 * @note Зверніть увагу на можливість викорисатння уього макросу
 * Не всі виводи однаково генерують ШІМ. На деяких виводах мікроконтроллера ШІМ
 * генерується апаратно, а на деяких можливе додаткове навантаження на процесор.
 *
 * @param  PIN номер піна
 * @param  VALUE значення
 * @endif
 */
#define PWM(PIN, VALUE) analogWrite(PIN, VALUE)

/** @cond */
#define START_NANIT ::NanitRobot::Nanit::getNanit()
#define GET_NANIT   ::NanitRobot::Nanit::getNanit()

#define NANIT_BEGIN(X)                                                         \
  ::NanitRobot::Nanit &X { START_NANIT }
/** @endcond */

/** @if English
 * @defgroup ServiceMode Testing cable integrity
 *
 * @brief Instructions on how to check the integrity of cables with _RJ-12_
 * connectors
 *
 * @else
 * @defgroup ServiceMode Тестування цілісності кабелів
 *
 * @brief Інструкція як перевірити цілісність кабелів з роз'ємами _RJ-12_
 *
 * @endif
 *
 * @{
 * @if English
 * Activation of diagnostic mode
 * ==============================
 * @else
 * Активація режиму діагностики
 * =============================
 * @endif
 *
 * @if English
 * In the new library version, self-diagnosis of the kit is provided as follows:
 *  1. Turn off the main block
 *  2. Connect any cable to the main block, bridging ports __1__ and __12__
 *  3. Turn on the main block. The main block will switch cable diagnostics mode
 *  4. Connect the ports __5__ and __6__ of the cable being tested with each
 * other to check its integrity
 *  5. Read the test results from the display
 *  6. Disconnect the cable that has been tested
 *  7. If necessary, test another cable and return to step _4_
 *  8. Turn off the main block
 *  9. Disconnect the activation cable from the main block, ending the testing
 * process
 *  10. Cable diagnostics are complete
 *
 * @else
 *
 * У новій версії бібліотеки передбачена можливість самодіагностики набору
 *  1. Вимкнути головний блок
 *  2. Підключити будь-який кабель до головного блоку з'єднавши між собою __1__
 * та __12__ порти
 *  3. Увімкнути головний блок. Головний блок перейде в режим тестування
 * комплектних кабелів
 *  4. З'єднати між собою кабелем, який тестується порти __5__ та __6__ для
 * перевірки його цілісності
 *  5. Зчитати з дисплею результат тестування
 *  6. Від'єднати кабель, що протестовано
 *  7. За потреби протестувати інший кабель перейти до кроку _4_
 *  8. Вимкнути головний блок
 *  9. Відключити від головного блоку кабель активації режиму тестування
 *  10. Діагностика кабелів завершена
 *
 * @endif
 * @}*/

/** @if English
 * @namespace NanitRobot is a namespace and a set of functions supported by
 * Nanit boards
 *
 * @brief NanitRobot is a namespace and a set of functions supported by
 * Nanit boards
 * @else
 *  @namespace NanitRobot Простір імен та функцій які підтримуються платами
 *
 *  @brief NanitRobot Простір імен та функцій які підтримуються платами
 * Nanit
 * @endif
 * */
namespace NanitRobot {

/** @if English
 * @brief Mapping function for floating-point numbers
 * @else
 * @brief Мапінг функція для чисел з плаваючою крапкою
 * @endif
 *
 * @if English
 *
 * @param [in] inputValue the value to be scaled
 * @param [in] inputMin the lower threshold of the values to be scaled
 * @param [in] inputMax the upper threshold of the values to be scaled
 * @param [in] rangeMin the lower boundary of the output value range
 * @param [in] rangeMax the upper boundary of the output value range
 * @return returns the scaled value
 * @else
 * @param [in] inputValue значення яке потрібно промаштабувати
 * @param [in] inputMin Нижній поріг значань які потрібно промаштабувати
 * @param [in] inputMax Верхній поріг значень, які потрібно промаштвабувати
 * @param [in] rangeMin Нижня межа значень діапазону вихідних значень
 * @param [in] rangeMax Верхня межа значень діапазону вихідних значень
 * @return повертає маштабоване значення
 * @endif
 */
float Map(float inputValue, float inputMin, float inputMax, float rangeMin,
          float rangeMax);

/** @if English
 * @brief A class that allows easy control of any Nanit board
 *
 * @details The class contains public fields and methods that allow control of
 * the Nanit board to obtain information from the outside world (read data from
 * sensors) and display it (on the built-in display or connected modules).
 * @else
 * @brief Клас яки дозволяє легко керувати будь-якою платою Nanit
 *
 * @details В класі є публічні поля та методи які дозволяють керувати платою
 * Наніт для отримання інформації з зовнішноього світу (читати дані з дачиків),
 * та виводити її (вбудований дисплей чи підключені модулі).
 * @endif
 */
class Nanit {
 public:
  // /** @if English
  //  * @brief Типи індикторів батареї
  //  */
  /// @cond
  enum class GuageType {
    SmileBatt,  //< індикатор батареї у вигляді "емоційної батарейки"
    Simple,     //< простий індикатор батарейки
    LAST
  };
  /**
   * @endcond
   *
   * @brief Get the memory address of the created Nanit class object
   * @else
   * @brief Отримати адресу розміщення створеного об'єкту класу Nanit
   * @endif
   */
  inline static Nanit &getNanit() {
    static Nanit instance;
    return instance;
  }

  /** @if English
   * @brief Turn on the display backlight
   * @else
   * @brief Увімкнути підсвідку дисплея
   * @endif
   */
  void backlightOn();

  /** @if English
   * @brief Turn off the display backlight
   * @else
   * @brief Вимкнути підсвідку дисплея
   * @endif
   */
  void backlightOff();

  /** @if English
   * @brief Turn off the display backlight
   * @else
   * @brief Встановити рівень яскравості підсвідки
   * @endif
   *
   * @if English
   * @param [in] brightness Brightness level
   * @else
   * @param [in] brightness Рівень яскравості
   * @endif
   *
   * @if English
   * @details At a brightness level of `0`, the method's operation is identical
   * to `backlightOff()`. The maximum possible brightness is `255`. Be cautious
   * with values exceeding `255` (overflow).
   * @else
   * @details При яскравості рівній  `0` робота методу тотожна  `backlightOff()`
   * Максимальна можлива яскаравість  `255` . Будьте обережні з числами що
   * перевищують значення `255` (переповнення).
   * @endif
   */
  void backlightSet(uint8_t brightness);

  /**
   * @brief Get the Batary Voltage object
   *
   * @return float
   */
  float getBatteryVoltage() const;
  /**repeat & 0b1
   * @brief Get the Battery Voltage object
   *
   * @if English
   * @details The method returns the battery charge level in percentage for the
   * Li-Ion battery.
   * @else
   * @details  Метод повертає значення рівня зараду ІонЛітієвої батареї у
   * відсотках.
   * @endif
   * <center>
   *   | # |     Volts    |       %       |
   *   |:-:|:------------:|:-------------:|
   *   | 1 | 4.08 -- 4.24 | 85.0 -- 100.0 |
   *   | 2 | 4.06 -- 4.08 | 85.0 --  81.7 |
   *   | 3 | 4.02 -- 4.06 | 81.7 --  76.7 |
   *   | 4 | 3.98 -- 4.02 | 73.4 --  76.7 |
   *   | 5 | 3.88 -- 3.98 | 58.4 --  73.4 |
   *   | 6 | 3.80 -- 3.88 | 22.0 --  58.4 |
   *   | 7 | 3.68 -- 3.8  |  8.7 --  22.0 |
   *   | 8 | 3.54 -- 3.68 |  5.4 --   8.7 |
   *   | 9 | 3.32 -- 3.54 |  2.1 --   5.4 |
   *   | 10| 3.00 -- 3.32 |  0.5 --   2.1 |
   *   | 11| 2.50 -- 3.00 |  0.0 --   0.5 |
   */
  float getBatteryPower() const;

  /**
   * @cond
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
#endif

  /**
   * @endcond
   *
   * @brief Determining the color of the built-in LED
   * @else
   * @brief Визначення кольору світіння вбудованого світлодіода
   * @endif
   *
   * @if English
   * @param [in] red Red crystal brightness level
   * @param [in] green Green crystal brightness level
   * @param [in] blue Blue crystal brightness level
   * @param [in] brightness Total crystal illumination level
   *
   * @details All parameters can take values from `0` to `255`
   * @else
   * @param [in] red Рівень яскравості червоного кристалу
   * @param [in] green Рівень яскравості зеленого кристалу
   * @param [in] blue Рівень яскравості синього кристалу
   * @param [in] brightness Загальний рівень світіння кристалів
   *
   * @details Всі параметри можуть приймати значення від `0` до `255`
   * @endif
   */
  void BuildinRGB(uint8_t red, uint8_t green, uint8_t blue,
                  uint8_t brightness = 255);
  /** @if English
   * @brief Determining the color of the built-in LED
   * @param [in] color Determining the color of the illumination of all three
   * crystals. The number can take a 32-bit value. The first byte corresponds to
   * red, the second to green, and the third to blue.
   * @param [in] brightness Determines the brightness level of the illumination
   * of all crystals simultaneously.
   * @else

   * @brief Визначення кольору світіння вбудованого світлодіода
   *
   * @param [in] color Визначення кольору світіння всіх трьох кристалів. Число
   * може примати 32бітне значення. Перший байт відповідає за червоний кристал,
   * другий -- зелений, третій -- синій.
   * @param [in] brightness Визначає рівень яскравості світіння всіх кристалів
   * одночасно.
   * @endif
   */
  void BuildinRGB(uint32_t color, uint8_t brightness = 255);
  Servo ServoMotor;
enum{
  NO_SUB_PROG=0,
  CABLE_SUB_PROG,
  PIN_SUB_PROG
};

 private:
  /** @if English
   * @brief An object of the Nanit class is a singleton object
   *
   * @details If the object has not been created in memory, we create it. If the
   * object already existed in memory, we obtain its memory address. This method
   * does not allow creating objects indefinitely and only allows initializing
   * the necessary variables for subsequent use once
   * @else
   * @brief Об'єк ткласу Nanit є об'єктом одинаком
   *
   * @details Якщо об'єкт не був створений у оперативній пам'яті ми його
   * створюєм. Якщо об'єкт вже існував в пам'яті то ми отримаємо адресу
   * розміщення. Такий спосіб не дозволяє не обмежено створювати об'єкти і
   * дозволяє лише один раз ініціювати необхідні змінні для подальшого
   * використання
   * @endif
   */
  inline Nanit() : Display{Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RES)} {
    if (!Serial) Serial.begin(NANIT_SERIAL_SPEED);
    Serial.print(R"Sam4uk(
====================================================  
Nanit initialise...
Serial number: )Sam4uk");
    {
      const uint32_t _s_n_ = getSerialNum();
      if (_s_n_ == 0xFFFFFFFF)
        Serial.println("TMMDDYYNNN");
      else
        Serial.println(_s_n_);
    }
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
        Display.fillScreen(_background_color);
      }

      //------------------------------------------------------------------
      //   Кабелів
      //------------------------------------------------------------------
      pinMode(P1_2, INPUT_PULLUP);
      pinMode(P12_2, INPUT_PULLUP);
      if (!digitalRead(P1_2) and !digitalRead(P12_2)) {
        Display.fillScreen(0xFFFF);
/** @cond */
#define PIN_COUNT  (6)
#define NO_CABLE   ((1 << PIN_COUNT) - 1)  ///< мітка
#define GOOD_CABLE (0)  ///< Мітка успішного тесту кабелю
                        /** @endcond */
        // Конфігурування  відображення
        const uint16_t               // Кольори
            TextColor{0x0},          // тексту
            GoodColor{0x00FF >> 3},  // цілого кабелю
            NoColor{0xC00},          // відсутнього кабелю
            BadColor{0xF800};        // пошкодженого кабелю

        //
        const char            // Умовні позначик
            CHAR{'#'},        //
            CharBroken{'X'},  // пошкоджена жила
            CharGood{'V'},    // ціла жила
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
        const auto CharWitdh{Display.getCursorX()};
        Display.println();
        const auto CharHeiht{Display.getCursorY()};

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
    Serial.print("Nanit started ");
    Serial.print(millis());
    Serial.print(" us OK");
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
 * @brief 
 * 
 * @return int8_t 
 */
  int8_t ApproofMode();
  /*
   * @brief Destroy the Nanit object
   *
   */
  Nanit(const Nanit &) = delete;  // rule of three
  Nanit &operator=(const Nanit &) = delete;
  inline ~Nanit() = default;
  //
  uint16_t  //
      _background_color{
          WHITE16},  ///<  визначає колір фону вікна
                     ///<  Використвується при замальовуванні елементів
      _guage_line_color{BLACK16},  ///< Колір промальовування лійній
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
  // struct {
  void setAll(uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = 0; i < 15; i++) {
      _strip_led.setPixelColor(i, red, green, blue);
    }
    _strip_led.show();
  };
  void colorWipe(byte red, byte green, byte blue, int SpeedDelay, bool *arr) {
    // pinMode(J_7, OUTPUT);
    for (uint16_t i = 0; i < 15; i++) {
      //   if (!arr)
      //     _strip_led.setPixelColor(i, red, green, blue);
      //   else if (!arr[i])
      _strip_led.setPixelColor(i, red, green, blue);
      _strip_led.show();
      delay(SpeedDelay);
    }
  }  // } Ring;
  FastLED_NeoPixel<15, BUILDIN_STRIP_LED, NEO_GRB> _strip_led;
  /** @if English
   * @brief The built-in display of `Nanit`
   *
   * To read the list of methods for controlling the display, you can go to
   * the page
   * @else
   * @brief Вбудований дисплей `Nanit``a
   *
   * @details Перелік методів для керування дисплеєм можна прочитати тут
   * @endif
   * @ref Display
   */
  Adafruit_ST7735

      //                    * |    |       |
      // * |-    |-       |
      // * |drawRGBBitmap()    |       |
      // * |initB()    |       |
      // * |initR()    |       |
      // * |setRotation()    |       |
      // * |write()    |       |
      // * |enableDisplay()    |       |
      // * |invertDisplay()    |       |
      // * |    |       |
      // * |    |       |
      // * |    |       |
      Display;
};
}  // namespace NanitRobot

/** @cond */
/*
 * Ініціація змінних та дисплею
 *
 * Використовується для ініціалізації внутнішніх змінних та дисплею плати Наніт
 *
 */
void Nanit_Base_Start();
/** @endcond */
#endif
