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
#ifndef _SERIAL_NUMBER_H_
#define _SERIAL_NUMBER_H_

#include "Offsets.hpp"
// #define SERIAL_NUM (E2END - sizeof(uint32_t))

typedef uint32_t serial_num;

/**
 * @brief 
 * 
 * @return serial_num 
 * 
 */
serial_num getSerialNum();

/**
 * @brief 
 * 
 * @param num 
 * @return true 
 * @return false 
 */
bool checkSerialNum(serial_num num);

/**
 * @brief 
 * 
 * @param num 
 * @return true 
 * @return false 
 */
bool setSerialNum(const serial_num num) ;
#endif
