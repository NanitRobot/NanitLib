/**
 * @file Offsets.hpp
 * @author Sam4uk
 * @brief  Зміщення в енерогонезалежній пам'яті де зберігаються важливі дані
 * Необхідні налаштування для роботи Nanit
 * @version 0.1
 * @date 2023-05-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NANIT_E2ROM_OFFSETS
#define NANIT_E2ROM_OFFSETS

#include <EEPROM.h>

/* В процесі вивчення програмування на платах Nanit користувачі найбільш
 * вирогідніше будуть користуватись початком адреоного простору енергонезалежної
 * пам'яті. Тому для зберігання інформації про виріб обрано кінеь адресного
 * простору Енергонезалежної пам'яті.
 *
 * Розмір EEPROM визначено у фалах заголовків для мікроконтролерів
 *
 * В нашому випадку визанчення E2END вказує розмір пам'яті
 */
// clang-format off
// +----------------------+ <------  Початок Енергонезалежної пам'яті
// |        0x0           |          Користувачам можна безпечно користуватись
// |                      |          цим адресним простором не боячись пошокодити 
// |                      |          налаштування плати збережених у пам'яті EEPROM
//...                    ...
// |                      |
// |                      |
// |                      |
//...                    ...
// |E2_DISCOVERY_SETTINGS | <------  Зарезервонвано для системнох потреб Nanit
// |                      |          Небеспечна зона EEPROM. Якщо зберігати користувацьки
// |                      |          дані в цьому адресному просторі налаштування плати 
// |                      |          пошкодяться коректна робота не ґарантується
// |                      |
// |                      |
//...                    ...
// |                      |
// | E2_VERSION_BOARD     | <-------  Програмене визначення версії плати
// |  SERIAL_NUM          | <-------  Комірки для зберігання серійного номеру
// +----------------------+ <-------  Кінець E2PROM
//

// clang-format on
#define SERIAL_NUM                                                             \
  (E2END - sizeof(uint32_t)) ///< офсет збереження серійного номеру

#define E2_VERSION_BOARD                                                       \
  (SERIAL_NUM - (sizeof(unsigned) * 3)) //Резерв для визначення версії плтати

#define SIZE_DISCOVERY_RESERVED                                                \
  (0x1FF) ///< Розмір резерву пам'яті з розрахунку на 100 модів цей парамер
          ///< критичний для працездатності прошивок. ЙОГО НЕ ЗМІНЮВАТИ Розмір
          ///< Резерву 511 байт.

#define E2_DISCOVERY_SETTINGS                                                  \
  (E2_VERSION_BOARD -                                                          \
   E2_SIZE_DISCOVERY_RESERVED) ///< офсет зарезервованої пам'яті Якщо дані
///< випадково користувачем буть записані  в цей
///< адресниq простір збереження працездатності
///< дефолтної  прошивки НЕ ГАРАНТУЄТЬСЯ
#endif