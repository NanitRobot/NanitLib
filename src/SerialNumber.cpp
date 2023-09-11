#include "SerialNumber.hpp"
/*
    +----------1 тип виробу (1--4)
    |           1 - розумний будинок (своя)
    |           2 - Дискавері (своя)
    |           3 - Дискавері (заводська плата)
    |           4 - Розумний будинок (Заводська плата)
    | +--------2 місяць виготовлеення (01--12)
    | | +------2 цифри число місяця виготовлення (01--31)
    | | | +----2 цифри рік виготовлення (22--99)
    | | | | +--3 цифри порядковий номер в цей день (001--999)
    ^ ^ ^ ^ ^
    XXXXXXXXXX
*/
/*Прочитати серійний*/

#ifndef _UTIL_DELAY_H_
#include <util/delay.h>
#endif

serial_num getSerialNum()
{
  // 103172306
  union
  {
    uint32_t number;
    uint8_t bytes[sizeof(uint32_t)];
  };

  for (uint8_t i = 0; i < sizeof(number); i++)
  {
    bytes[i] = EEPROM.read(SERIAL_NUM + i);
  }

  return number;
}


bool checkSerialNum(serial_num num) {
  if (num >= 0xFFFFFFF0 or num <= 0x000F71E9 /**/)
    return false;

  return true;
}

bool setSerialNum(const serial_num num)
{
  constexpr uint8_t k_tryConunt = 3;
  union
  {
    uint32_t number;
    uint8_t bytes[sizeof(uint32_t)];
  };
  number = num;
  if (checkSerialNum(num))
  {
    for (uint8_t i = 0; i < sizeof(number); i++)
    {
      for (uint8_t tryes = 0; tryes < k_tryConunt; tryes++)
      {
        EEPROM.write(SERIAL_NUM + i, bytes[i]);
        _delay_ms(10);
        if (EEPROM.read(SERIAL_NUM + i) == bytes[i])
          break;
      };
    }
    return true;
  }
  return false;
}