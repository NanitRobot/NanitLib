/**
 * @file SerialNumber.hpp
 * @author Sam4uk
 * @if English
 * @brief Methods for working with board serial numbers.
 * @else
 * @brief Методи для роботи з серійними номерами плат.
 * @endif
 * @version 0.1
 * @date  2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
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
                0 - Інший
                1 - розумний будинок
                2 - Дискавері
                3 - Дискавері задод
                4 - 
*/

typedef uint32_t serial_num;

/**
 * @brief Фукція читає серійний номер виробу з енергонезалежної пам'яті
 * 
 * @return serial_num 
 * 
 */
serial_num getSerialNum();

/**
 * @brief Перевірка коректності серійного номеру
 * 
 * @param num 
 * @return true 
 * @return false 
 */
bool checkSerialNum(serial_num num);

/**
 * @brief Записати серйний номер в пам'ять
 * 
 * @param num 
 * @return true 
 * @return false 
 */
bool setSerialNum(const serial_num num) ;
#endif
