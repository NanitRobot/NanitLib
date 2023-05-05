#pragma once
/**
 * @author Sam4uk
 * @date 5-May-23
*/

#define APROOF_MODE                                                            \
  pinMode(J_7, INPUT_PULLUP);                                                  \
  if (!digitalRead(J_7)) {                                                     \
    Display.println("Pin test mode");                                          \
    PinTestSetup();                                                            \
  }                                                                            \
  while (!digitalRead(J_7))                                                    \
    PinTestLoop();


void PinTestSetup();
void PinTestLoop();