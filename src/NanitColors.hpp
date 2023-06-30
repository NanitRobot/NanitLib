/**
 * @file NanitColors.hpp
 * @author Sam4uk
 * @brief Містить макровизначення деяких кольорів
 * @version 0.1
 * @date 2023-06-20
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef _NANIT_COLORS_HPP_
#define _NANIT_COLORS_HPP_

/**
 * @brief Макрос перетворення перетворення у колір 565
 * @param RED Рівень червоного
 * @param GREEN Рівень зеленого
 * @param BLUE Рівень синього
 *
 * @details У макровизначення можна передавати 8 бітні беззнакові значення.
 * Макровизначення конвертує у 16-бітни колір
 * 
 * |RRRRR|GGG GGG|BBBBB|
 * |HHHHH HHH|LLL LLLLL|
 * 
 */
#define COLOR565(RED, GREEN, BLUE)                                             \
  (((RED & 0xF8) << 8) | ((GREEN & 0xFC) << 3) | (BLUE >> 3))


#define CYAN16         (COLOR565(0, 255, 255))
#define YELLOW16       (COLOR565(255, 255, 0))
#define MAGENTA16      (COLOR565(255, 0, 255))
#define RED16          (COLOR565(255, 0, 0))
#define GREEN16        (COLOR565(0, 255, 0))
#define BLUE16         (COLOR565(0, 0, 255))
#define ORANGE16       (COLOR565(255, 128, 0))
#define DEEP_PINK16    (COLOR565(255, 0, 128))
#define PURPLE16       (COLOR565(128, 0, 255))
#define LIGHT_BLUE16   (COLOR565(0, 128, 255))
#define BRIGHT_GREEN16 (COLOR565(0, 255, 128))
#define LEMON16        (COLOR565(128, 255, 0))

#endif