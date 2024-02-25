/**
 * @file Version.hpp
 * @author Sam4uk
 *
 * @if English
 * @brief Classes that allow tracking the versions of libraries and boards.
 * @else
 * @brief Класи які дозволяють відслідковувати версії бібіліотеки та плати
 * @endif
 * @version 0.2
 *
 * @date 27-03-23
 * @copyright Copyright (c) 2023
 * @cond
 */

#ifndef _VERSION_H_
#define _VERSION_H_
#include <WString.h>

// #define DEMO "DEMO"

/**
 * @brief Клас Версія
 *
 */
class Version {
  enum {
    MAJOR,  ///< індекс  поля, яке містить головну версію
    MINOR,  ///< індекс  поля, яке містить мінорну версію
    PATCH,  ///< індекс  поля, яке містить патч версію
    TWEAK,
    COUNT
  };

 public:
  /**
   * @brief Construct a new Version object
   *
   * @param major Визначає головну версію
   * @param minor Визначає мінорну версію
   * @param patch Визначає патч версію
   * @param tweak
   */
  Version(uint16_t major = {}, uint16_t minor = {}, uint16_t patch = {},
          uint16_t tweak = {}) {
    _ver[MAJOR] = major;
    _ver[MINOR] = minor;
    _ver[PATCH] = patch;
    _ver[TWEAK] = tweak;
  };

  /**
   * @brief Отримати Версію
   *
   * @return uint16_t
   */
  uint16_t getMajor() const { return _ver[MAJOR]; }

  /**
   * @brief Отримати мінорну версію
   *
   * @return uint16_t
   */
  uint16_t getMinor() const { return _ver[MINOR]; }

  /**
   * @brief Отримати патч версію
   *
   * @return uint16_t
   */
  uint16_t getPatch() const { return _ver[PATCH]; }

  /**
   * @brief Отримати патч версію
   *
   * @return uint16_t
   */
  uint16_t getTweak() const { return _ver[TWEAK]; }
  /** @if English
   * @else
   * @todo TODO rule of 3
   * @endif
   */
  /**
   * @brief Операця порівняння \b <
   */
  friend inline bool operator<(Version lhs, Version rhs) {
    for (uint8_t it{MAJOR}; it < COUNT; ++it) {
      if (lhs._ver[it] < rhs._ver[it]) return true;
    }
    return false;
  }
  /**
   * @brief Операця порівняння \b >
   */
  friend inline bool operator>(Version lhs, Version rhs) { return (rhs < lhs); }
  /**
   * @brief Операця порівняння \b <=
   */
  friend inline bool operator<=(Version lhs, Version rhs) {
    return !(lhs > rhs);
  }
  /**
   * @brief Операця порівняння \b >=
   */
  friend inline bool operator>=(Version lhs, Version rhs) {
    return !(lhs < rhs);
  }
  /**
   * @brief Операця порівняння \b ==
   */

  friend inline bool operator==(Version lhs, Version rhs) {
    bool result{true};
    for (uint8_t it{MAJOR}; it < COUNT; ++it) {
      result = result && (lhs._ver[it] == rhs._ver[it]);
    }
    return result;
  }
  /**
   * @brief Операця порівняння \b !=
   */
  friend inline bool operator!=(Version lhs, Version rhs) {
    return !(lhs == rhs);
  }

  /**
   * @brief Ковертація версії у рядковий тип
   *
   * @details Якщо версія 0.0.0 то метод повертає рядок що повідомляє про
   * демонстраційну версію. Якщо версіювання мість завершуючі нулі то вони не
   * виводяться.
   *
   * @param ver
   * @return String
   */
  friend String StrVersion(Version ver) {
    /**
     * Перевірка чи це не демо
     */
    {
      bool is_demo{true};
      for (uint8_t it{MAJOR}; it < COUNT; ++it) {
        is_demo = is_demo && (0 == ver._ver[it]);
      }
      if (is_demo) return "DEMO";
    }

    String result{""};
    {
      bool print_zero{false};
      for (uint8_t it{COUNT}; it != MAJOR; --it) {
        if (0 != ver._ver[it - 1] or print_zero) {
          result = String((it <= MINOR) ? "" : ".") + String(ver._ver[it - 1]) +
                   result;
          print_zero = true;
        }
      }
    }
    return result;
  };

 private:
  uint16_t  //
      _ver[COUNT];
  /// @endcond
};
#endif