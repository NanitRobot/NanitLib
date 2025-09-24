#include "SerialNumber.hpp"

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
  const uint32_t//
   EEPROM_no_data=-1,//
   EEPROM_err_data=0x9A7311;
  if (num >= EEPROM_no_data or num <= EEPROM_err_data /**/)
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