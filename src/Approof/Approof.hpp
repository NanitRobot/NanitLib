/**
 * @file Approof.hpp
 * @author Sam4uk
 * @brief Колекція функцій які допомогають оцінити працездатність набору Nanit
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#define APROOF_MODE                                                            \
  pinMode(J_7, INPUT_PULLUP);                                                  \
  if (!digitalRead(J_7)) {                                                     \
    Display.println("Pin test mode");                                          \
    PinTestSetup();                                                            \
  }                                                                            \
  while (!digitalRead(J_7)) PinTestLoop();

/*
Підготовка до тестування пінів
*/
void PinTestSetup();
/*
Цикл тестування пінів
*/
void PinTestLoop();