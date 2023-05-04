#include "Approof.hpp"
#include "../NanitLib.h"


#define TOGGLE HIGH

void check_port2();
void check_port3();
void check_port4();
void check_port5();
void check_port6();
void check_port7();
void check_port8();
void check_port9();
void check_port10();
void check_port11();

void check_1(bool);
void check_12(bool);

bool drive = 0;

void PinTestSetup() {
    Serial.end();
    
  digitalWrite(40, HIGH);
 #ifdef MEGACORE
  for (uint8_t pin_to_set_mode = 0; pin_to_set_mode < NUM_DIGITAL_PINS; pin_to_set_mode++) {

// #define TFT_CS (48) 
// #define TFT_RES (37)
// #define TFT_DC (49)
// #define TFT_BL (4)
// #define TFT_SCK (52)
// #define TFT_MOSI (51)
    if (
        pin_to_set_mode==TFT_BL or //
        pin_to_set_mode==TFT_CS or //
        pin_to_set_mode==TFT_DC or //
        pin_to_set_mode==TFT_MOSI or //
        pin_to_set_mode==TFT_SCK or //
        pin_to_set_mode==TFT_RES or //
        pin_to_set_mode==BATTARY_PIN// or //
        // pin_to_set_mode==TFT_CS or //
    )
    // if (pin_to_set_mode == 69)
      continue;

    pinMode(pin_to_set_mode, OUTPUT);
  }
  #else
  #endif
}
void PinTestLoop() {
    #ifdef MEGACORE
    
  check_1(drive);
check_port2();
check_port3();
check_port4();
check_port5();
check_port6();
check_port7();
check_port8();
check_port9();
check_port10();
check_port11();

  check_12(drive);

  drive = !drive;
    #else
    #endif 
    }

void check_port2() {
  digitalWrite(A8, HIGH);
  delay(100);
  digitalWrite(A8, LOW);
  digitalWrite(42, HIGH);
  delay(100);
  digitalWrite(42, LOW);
  digitalWrite(A9, HIGH);
  delay(100);
  digitalWrite(A9, LOW);
  digitalWrite(A10, HIGH);
  delay(100);
  digitalWrite(A10, LOW);

  // for (int i = 62; i <= 64; i++)
  // {
  //   digitalWrite(i, HIGH);
  //   delay(100);
  //   digitalWrite(i, LOW);
  // }
}

void check_port3() {
  digitalWrite(31, HIGH);
  delay(100);
  digitalWrite(31, LOW);
  digitalWrite(30, HIGH);
  delay(100);
  digitalWrite(30, LOW);
  digitalWrite(25, HIGH);
  delay(100);
  digitalWrite(25, LOW);
  digitalWrite(71,HIGH);
  delay(100);
  digitalWrite(71,LOW);
}

void check_port4() {
  for (int i = 46; i >= 44; i--) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  digitalWrite(PIN_A11, HIGH);
  delay(100);
  digitalWrite(PIN_A11, LOW);
}



void check_port5() {
  digitalWrite(33, HIGH);
  delay(100);
  digitalWrite(33, LOW);
  digitalWrite(PIN_A12, HIGH);
  delay(100);
  digitalWrite(PIN_A12, LOW);
  digitalWrite(PIN_A1, HIGH);
  delay(100);
  digitalWrite(PIN_A1, LOW);



  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
}


void check_port6() {
  digitalWrite(22, HIGH);
  delay(100);
  digitalWrite(22, LOW);
  digitalWrite(A13, HIGH);
  delay(100);
  digitalWrite(A13, LOW);
  digitalWrite(A14, HIGH);
  delay(100);
  digitalWrite(A14, LOW);

  digitalWrite(23, HIGH);
  delay(100);
  digitalWrite(23, LOW);
}


void check_port7() {
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(9, LOW);

  digitalWrite(28, HIGH);
  delay(100);
  digitalWrite(28, LOW);

  digitalWrite(A4, HIGH);
  delay(100);
  digitalWrite(A4, LOW);

  digitalWrite(A3, HIGH);
  delay(100);
  digitalWrite(A3, LOW);
}


void check_port8() {
  //   digitalWrite(5, HIGH);
  // delay(100);
  // digitalWrite(5, LOW);
  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(5, LOW);

  for (int i = 0; i <= 1; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}



void check_port9() {
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);

  for (int i = 19; i <= 21; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}


void check_port10() {

  digitalWrite(PIN_A2, HIGH);
  delay(100);
  digitalWrite(PIN_A2, LOW);

  digitalWrite(A0, HIGH);
  delay(100);
  digitalWrite(A0, LOW);

  digitalWrite(24, HIGH);
  delay(100);
  digitalWrite(24, LOW);

  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(6, LOW);
}

void check_port11() {
  for (int i = 14; i <= 15; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }

  digitalWrite(43, HIGH);
  delay(100);
  digitalWrite(43, LOW);

  digitalWrite(32, HIGH);
  delay(100);
  digitalWrite(32, LOW);
}


void check_1(bool what) {
  if (what == 0) {
    digitalWrite(MOTOR1_A, !TOGGLE);
    digitalWrite(MOTOR1_B, TOGGLE);
  } else if (what == 1) {
    digitalWrite(MOTOR1_A, TOGGLE);
    digitalWrite(MOTOR1_B, !TOGGLE);
  }

  digitalWrite(PIN_A6, HIGH);
  delay(100);
  digitalWrite(PIN_A6, LOW);

  digitalWrite(PIN_A7, HIGH);
  delay(100);
  digitalWrite(PIN_A7, LOW);
}

void check_12(bool what) {
  digitalWrite(34, HIGH);
  delay(100);
  digitalWrite(34, LOW);

  digitalWrite(36, HIGH);
  delay(100);
  digitalWrite(36, LOW);


  if (what == 0) {
    digitalWrite(MOTOR2_A, !TOGGLE);
    digitalWrite(MOTOR2_B, TOGGLE);
  } else if (what == 1) {
    digitalWrite(MOTOR2_A, TOGGLE);
    digitalWrite(MOTOR2_B, !TOGGLE);
  }
}