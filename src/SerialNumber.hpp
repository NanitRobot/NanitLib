#ifndef _SERIAL_NUMBER_H_
#define _SERIAL_NUMBER_H_

#include "Offsets.hpp"
// #define SERIAL_NUM (E2END - sizeof(uint32_t))
/*
    XXXXXXXXXX
    ^ ^ ^ ^ ^
    | | | | |
    | | | | +--3 цифри порядковий номер в цей день (001--999)
    | | | +----2 цифри рік виготовлення (22--99)
    | | +------2 цифри число місяця виготовлення (01--31)
    | +--------2 місяць виготовлеення (01--12)
    +----------1 тип виробу (1--9)
                1 - розумний будинок
                2 - Дискавері
                3 - Дискавері задод
                4 - 
*/
/*Прочитати серійний*/

typedef unsigned long int serial_num;

/**
 * @brief Фукція читає серійний номер виробу з енергонезалежної пам'яті
 * 
 * @return serial_num 
 * 
 */
serial_num getSerialNum();
/*Перевірити серійни на коректність*/
bool checkSerialNum(serial_num num);
/* Встановити серійний номер*/
bool setSerialNum(const serial_num num) ;
#endif
