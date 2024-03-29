#ifndef NANITINITS_H_
#define NANITINITS_H_

#ifndef NANITLIB_H_
#  error "Include <NanitLib.h> instead of this file."
#endif


#include "NanitUtils.h"

/**
 * @brief Функція виконує ініціалізвцію вбудованого дисплею
 * 
 */
void Nanit_Display_Init();

void Nanit_RGB_Init();

void Nanit_Servo_Init();

void Nanit_ActiveBuzz_Init();

void Nanit_Sound_Init();

/* переробити під 3-й порт
inline void Nanit_PIR_Init()
{
	pinMode(33, INPUT); //33 це або P5_6 (стара версія), або P5_4
}
*/

#endif