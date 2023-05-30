#include "Approof.hpp"
#include "../NanitLib.h"

const uint8_t k_blink_delay{80}; // Затримка між перемиканнями
const uint8_t k_port_count{12}; // Кількість зовнішніх портів
const uint8_t k_pin_count{4}; // кількість пінів в роз'ємах як ввикористовуються
                              // для обміну даними з перефірійними пристроями

// #define APROOF_MODE                                                            \


#define TOGGLE HIGH
#define IGNORE_PIN                                                             \
  (0xFF) //< Макровизначення мітка ігнорування піна. Перевірка роботи піна
         //визначено у інший спосіб
#define RESET_PIN (IGNORE_PIN)

void check_1(bool);
void check_12(bool);

bool drive = 0;

void PinTestSetup() {
  Serial.end();

  for (uint8_t pin_to_set_mode{}; pin_to_set_mode < NUM_DIGITAL_PINS;
       pin_to_set_mode++) // Всі піни
  {
    if (pin_to_set_mode == TFT_BL // окрім підсітки дисплею
        or pin_to_set_mode == TFT_CS //  пін роботи з SD та дисплею
        or pin_to_set_mode == TFT_DC // пін роботи з SD та дисплею
        or pin_to_set_mode == TFT_MOSI // пін роботи з SD та дисплею
        or pin_to_set_mode == TFT_SCK // пін роботи з SD та дисплею
        or pin_to_set_mode == TFT_RES // пін роботи з SD та дисплею
        or pin_to_set_mode == BATTARY_PIN // АЦП батареї
    )

      continue;                       // пропускаємо
    pinMode(pin_to_set_mode, OUTPUT); // інші переводимо на виведення
  }
#ifndef MEGACORE     // якщо не викостовується MEGACORE
  DDRE |= 1 << DDE6; // 71 пін висавляємо на виведення
#endif
  digitalWrite(MOTOR_ENABLE, HIGH); // вмикаємо драйвер DC двигунів
}
void PinTestLoop() {
  // Карта пінів
  const uint8_t PinMap[k_port_count][k_pin_count]{
      {IGNORE_PIN, IGNORE_PIN, IGNORE_PIN, IGNORE_PIN}, // port 1
      {P2_1, P2_2, P2_3, P2_4},                         // port 2
      {P3_1, P3_2, P3_3, P3_4},                         // port 3
      {P4_1, P4_2, P4_3, P4_4},                         // port 4
      {P5_1, P5_2, P5_3, P5_4},                         // port 5
      {P6_1, P6_2, P6_3, P6_4},                         // port 6
      {P7_1, P7_2, P7_3, P7_4},                         // port 7
      {1, 0, P8_3, RESET_PIN},                          // port 8
      {P9_1, P9_2, P9_3, P9_4},                         // port 9
      {P10_1, P10_2, P10_3, P10_4},                     // port 10
      {14, 15, P11_3, P11_4},                           // port 11
      {IGNORE_PIN, IGNORE_PIN, IGNORE_PIN, IGNORE_PIN}  // port 12
  };

  check_1(drive);
  for (uint8_t port{}; port < k_port_count; port++) // Перевіряємо кожен порт
    for (uint8_t pin{}; pin < k_pin_count; pin++) { // Перевіряємо кожен пін
      switch (PinMap[port][pin]) {
#ifndef MEGACORE
      case 71: // Перевірка піна без MegaGore
        PORTE |= 1 << PORTE6;
        delay(k_blink_delay);
        PORTE &= ~(1 << PORTE6);
        delay(k_blink_delay);
        break;
#endif
      case IGNORE_PIN: // Пропускаємо піни
        break;
      default: // Надсилаємо сигнал на піни для перевірки тестером
      {
        digitalWrite(PinMap[port][pin], HIGH);
        delay(k_blink_delay);
        digitalWrite(PinMap[port][pin], LOW);
        delay(k_blink_delay);
      } break;
      }
    }

  check_12(drive);

  drive = !drive;
}

void check_1(bool what) {
  if (what) {
    digitalWrite(MOTOR1_A, !TOGGLE);
    digitalWrite(MOTOR1_B, TOGGLE);
  } else {
    digitalWrite(MOTOR1_A, TOGGLE);
    digitalWrite(MOTOR1_B, !TOGGLE);
  }

  digitalWrite(P1_2, HIGH);
  delay(k_blink_delay);
  digitalWrite(P1_2, LOW);
  delay(k_blink_delay);

  digitalWrite(P1_1, HIGH);
  delay(k_blink_delay);
  digitalWrite(P1_1, LOW);
}

void check_12(bool what) {
  digitalWrite(P12_1, HIGH);
  delay(k_blink_delay);
  digitalWrite(P12_1, LOW);

  digitalWrite(P12_2, HIGH);
  delay(k_blink_delay);
  digitalWrite(P12_2, LOW);

  if (what) {
    digitalWrite(MOTOR2_A, !TOGGLE);
    digitalWrite(MOTOR2_B, TOGGLE);
  } else {
    digitalWrite(MOTOR2_A, TOGGLE);
    digitalWrite(MOTOR2_B, !TOGGLE);
  }
}