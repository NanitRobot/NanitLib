/**
 * @file Approof.cpp
 * @author Sam4uk
 *
 * @if English
 * @brief Implementation of functions that help assess the operability of the
 * `Nanit` kit.
 * @else
 * @brief Реалізація функцій які допомогають оцінити працездатність набору
 * `Nanit`.
 * @endif
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "Approof.hpp"

#include "../NanitLib.h"

const uint8_t  //
    /** @if English
     * @brief Delay between switching
     * @else
     * @brief Затримка між перемиканнями
     * @endif
     */
    k_blink_delay = 80,
    /** @if English
     * @brief Number of external ports
     * @else
     * @brief Кількість зовнішніх портів
     * @endif
     */
    k_port_count = 12,
    /** @if English
     * @brief The number of pins used for data exchange with peripheral devices
     * @else
     * @brief кількість пінів в роз'ємах як ввикористовуються для обміну даними
     * з перефірійними пристроями
     * @endif
     */
    k_pin_count = 4;

// #define APROOF_MODE                                                            \


#define TOGGLE HIGH

/** @if English
 * @brief The macro definition you provided is for labeling and ignoring a pin 
 * for pin-checking purposes, and it suggests that the pin's behavior is
 * checked in a different way, not using the standard method.
 * @else
 * @brief Макровизначення мітка ігнорування піна. Перевірка роботи піна
 * визначено у інший спосіб.
 * @endif
 */
#define IGNORE_PIN   (0xFF)
/** @if English
 * @brief Controller Reset Pin.
 * @else
 * @brief Пін перезавантаження контроллера.
 * @endif
 */
#define RESET_PIN    (IGNORE_PIN)
#define PORT1_MOTOR  (0xF1)
#define PORT12_MOTOR (0xF2)

void check_1(bool);
void check_12(bool);

bool drive = 0;

void PinTestSetup() {
  Serial.end();

  for (uint8_t pin_to_set_mode = 0; pin_to_set_mode < NUM_DIGITAL_PINS;
       pin_to_set_mode++)  // Всі піни
  {
    if (pin_to_set_mode == TFT_BL  // окрім підсітки дисплею
        or pin_to_set_mode == TFT_CS  //  пін роботи з SD та дисплею
        or pin_to_set_mode == TFT_DC  // пін роботи з SD та дисплею
        or pin_to_set_mode == TFT_MOSI  // пін роботи з SD та дисплею
        or pin_to_set_mode == TFT_SCK  // пін роботи з SD та дисплею
        or pin_to_set_mode == TFT_RES  // пін роботи з SD та дисплею
        or pin_to_set_mode == BATTERY_PIN  // АЦП батареї
    )

      continue;                        // пропускаємо
    pinMode(pin_to_set_mode, OUTPUT);  // інші переводимо на виведення
  }
#ifndef MEGACORE      // якщо не викостовується MEGACORE
  DDRE |= 1 << DDE6;  // 71 пін висавляємо на виведення
#endif
  digitalWrite(MOTOR_ENABLE, HIGH);  // вмикаємо драйвер DC двигунів
}
void PinTestLoop() {
  // Карта пінів
  // clang-format off
  const uint8_t PinMap[k_port_count][k_pin_count]{
      {P1_1, P1_2, PORT1_MOTOR, IGNORE_PIN}, // port 1
      {P2_1, P2_2, P2_3, P2_4},                         // port 2
#ifdef MEGACORE      
      {P3_1, P3_2, P3_3, P3_4},                         // port 3
#else
      {71, P3_2, P3_3, P3_4},                           // port 3
#endif
      {P4_1, P4_2, P4_3, P4_4},                         // port 4
      {P5_1, P5_2, P5_3, P5_4},                         // port 5
      {P6_1, P6_2, P6_3, P6_4},                         // port 6
      {P7_1, P7_2, P7_3, P7_4},                         // port 7
      {P8_1, P8_2, P8_3, RESET_PIN},                    // port 8
      {P9_1, P9_2, P9_3, P9_4},                         // port 9
      {P10_1, P10_2, P10_3, P10_4},                     // port 10
      {P11_1, P11_2, P11_3, P11_4},                     // port 11
      {P12_1, P12_2, PORT12_MOTOR, IGNORE_PIN}  // port 12
  };
  // clang-format on
  for (uint8_t port = 0; port < k_port_count; port++)  // Перевіряємо кожен порт
    for (uint8_t pin = 0; pin < k_pin_count; pin++) {  // Перевіряємо кожен пін
      if (digitalRead(J_7)) break;
      switch (PinMap[port][pin]) {
#ifndef MEGACORE
        case 71:  // Перевірка піна без MegaGore
          PORTE |= 1 << PORTE6;
          delay(k_blink_delay);
          PORTE &= ~(1 << PORTE6);
          delay(k_blink_delay);
          break;
#endif
        case IGNORE_PIN:  // Пропускаємо піни
          break;
        case PORT1_MOTOR:  // Реверс 1 мотору
          check_1(drive);
          break;
        case PORT12_MOTOR:  // Реверс 2 мотору
          check_12(drive);
          break;
        default:  // Надсилаємо сигнал на піни для перевірки тестером
        {
          digitalWrite(PinMap[port][pin], HIGH);
          delay(k_blink_delay);
          digitalWrite(PinMap[port][pin], LOW);
          delay(k_blink_delay);
        } break;
      }
    }

  drive = !drive;
}

/** @todo Переписати функції check_1 та check_2 таким чином щоб максимально
 * перемістити перевірку пінів у `PinTestLoop`*/
void check_1(bool what) {
  if (what) {
    digitalWrite(MOTOR1_A, !TOGGLE);
    digitalWrite(MOTOR1_B, TOGGLE);
  } else {
    digitalWrite(MOTOR1_A, TOGGLE);
    digitalWrite(MOTOR1_B, !TOGGLE);
  }
}

void check_12(bool what) {
  if (what) {
    digitalWrite(MOTOR2_A, !TOGGLE);
    digitalWrite(MOTOR2_B, TOGGLE);
  } else {
    digitalWrite(MOTOR2_A, TOGGLE);
    digitalWrite(MOTOR2_B, !TOGGLE);
  }
}
