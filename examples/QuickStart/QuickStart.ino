#include <NanitLib.h>

// Nanit_Base_Start2(SH);
void setup(){
  // SH.RGB(255,255,255);
}
void loop(){
  // NanitRobot::Nanit& NANIT{GET_NANIT};
  Nanit_Base_Start2(NANIT);
  NANIT.RGB(0x00ff00,255);
  delay(500);
  NANIT.RGB(0xff0000);
  delay(500);
}