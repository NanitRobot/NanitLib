/**
 * @file DependsLib.h
 * @author Sam4uk
 * @brief Інклюди бібілотек третіх сторін
 * @version 0.1
 * @date 2023-03-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _DEPENDS_LIB_H_
#define _DEPENDS_LIB_H_

#ifndef NANITLIB_H_
#  error "Include <NanitLib.h> instead of this file."
#endif

#include <FastLED_NeoPixel.h> ///< Стороння біблітека для керування адресними світлодіодами
#include <Adafruit_GFX.h>///< Стороня бібліотека для роботи вбудованого дисплею
#include <Adafruit_ST7735.h>///< Стороння бібіліотека для роботи вбудованого дисплею
#include <EEPROM.h>///< Стороння бібліотека для доступу до енергонезалежгої пам'яті
#include <Servo.h>///< Стороння бібліотека для роботи зі сервоприводами

// #include <SPI.h>

#endif