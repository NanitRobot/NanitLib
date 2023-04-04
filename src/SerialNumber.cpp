#include "SerialNumber.hpp"
/*
    XXXXXXXXX
    ^ ^ ^ ^ ^
    | | | | |
    | | | | +--2 цифри порядковий номер в цей день (01--99)
    | | | +----2 цифри рік виготовлення (22--99)
    | | +------2 цифри число місяця виготовлення (01--31)
    | +--------2 місяць виготовлеення (01--12)
    +----------1 тип виробу (1--9)
                1 - розумний будинок
                2 - Дисковері
*/
/*Прочитати серійний*/

serial_num getSerialNum() {

  // 103172306
  serial_num result;
  EEPROM.get(SERIAL_NUM, result);
  return result;
}
/*Перевірити серійни на коректність*/
bool checkSerialNum(serial_num num) {
  if (num == 0xFFFFFFFF or num <= 0x000F71E9 /**/)
    return false;

  return true;
}
bool setSerialNum(const serial_num num) {
  if (checkSerialNum(num)) {
    EEPROM.put(SERIAL_NUM, num);
    return true;
  }
  return false;
}