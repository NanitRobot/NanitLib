/**
 * @file Offsets.hpp
 * @author Sam4uk
 * 
 * @if English
 * @brief  Offset in non-volatile memory where important data is stored
 * @else
 * @brief  Зміщення в енерогонезалежній пам'яті де зберігаються важливі дані
 * Необхідні налаштування для роботи Nanit
 * @endif
 * @version 0.1
 * @date 2023-05-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NANIT_E2ROM_OFFSETS
#define NANIT_E2ROM_OFFSETS
#include "Version.hpp"

#include <EEPROM.h>

// clang-format off
// +----------------------+ 
// |        0x0           | 
// |                      | 
// |                      | 
//...                    ...
// |                      |
// |                      |
// |                      |
//...                    ...
// |E2_DISCOVERY_SETTINGS | 
// |                      | 
// |                      | 
// |                      | 
// |                      |
// |                      |
//...                    ...
// |                      |
// | E2_VERSION_BOARD     | 
// |  SERIAL_NUM          | 
// +----------------------+ 
//

// clang-format on
const uint32_t  //
    SERIAL_NUM{EEPROM.length() -
               sizeof(uint32_t)},  
    E2_VERSION_BOARD{SERIAL_NUM -
                     (sizeof(Version))}, 
    E2_SIZE_DISCOVERY_RESERVED{
        0x1FF},

    E2_DISCOVERY_SETTINGS{
        E2_VERSION_BOARD -
        E2_SIZE_DISCOVERY_RESERVED};  
#endif