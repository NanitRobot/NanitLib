#ifndef NANITUTILS_H_
#define NANITUTILS_H_

#ifndef NANITLIB_H_
#  error "Include <NanitLib.h> instead of this file."
#endif


#include <Arduino.h>
#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>



extern Servo nanit_servo;
extern Adafruit_ST7735 tft;



#endif