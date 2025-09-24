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

/** @if English
 * @brief Class version
 * @else
 * @brief Клас Версія
 * @endif
 */
class Version {
  enum {
    MAJOR,
    MINOR,
    PATCH,
    TWEAK,
    COUNT
  };

 public:
  /**
   * @brief Construct a new Version object
   * @if English
   * @param major Specifies the major version
   * @param minor Specifies the minor version
   * @param patch Specifies the patch version
   * @else
   * @param major Визначає головну версію
   * @param minor Визначає мінорну версію
   * @param patch Визначає патч версію
   * @endif
   * @param tweak
   */
  Version(uint16_t major = {}, uint16_t minor = {}, uint16_t patch = {},
          uint16_t tweak = {}) {
    _ver[MAJOR] = major;
    _ver[MINOR] = minor;
    _ver[PATCH] = patch;
    _ver[TWEAK] = tweak;
  };

   /** @if English
   * @brief Get major version
   * @else
   * @brief Отримати мажор версію
   * @endif
   * @return uint16_t
   */
  uint16_t getMajor() const { return _ver[MAJOR]; }

   /** @if English
   * @brief Get minor version
   * @else
   * @brief Отримати мінор версію
   * @endif
   * @return uint16_t
   */
  uint16_t getMinor() const { return _ver[MINOR]; }

   /** @if English
   * @brief Get pathc version
   * @else
   * @brief Отримати патч версію
   * @endif
   * @return uint16_t
   */
  uint16_t getPatch() const { return _ver[PATCH]; }

   /** @if English
   * @brief Get tweek version
   * @else
   * @brief Отримати твік версію
   * @endif
   * @return uint16_t
   */
  uint16_t getTweak() const { return _ver[TWEAK]; }

  friend inline bool operator<(Version lhs, Version rhs) {
    for (uint8_t it{MAJOR}; it < COUNT; ++it) {
      if (lhs._ver[it] < rhs._ver[it]) return true;
    }
    return false;
  }

  friend inline bool operator>(Version lhs, Version rhs) { return (rhs < lhs); }

  friend inline bool operator<=(Version lhs, Version rhs) {
    return !(lhs > rhs);
  }

  friend inline bool operator>=(Version lhs, Version rhs) {
    return !(lhs < rhs);
  }

  friend inline bool operator==(Version lhs, Version rhs) {
    bool result{true};
    for (uint8_t it{MAJOR}; it < COUNT; ++it) {
      result = result && (lhs._ver[it] == rhs._ver[it]);
    }
    return result;
  }

  friend inline bool operator!=(Version lhs, Version rhs) {
    return !(lhs == rhs);
  }
  /** @if English
   *
   * @brief Converting a version to a string type
   *
   * @details If the version is 0.0.0, the method returns a string indicating the
   * demo version. If the versioning contains trailing zeros, they are not
   * printed.
   * @else
   *
   * @brief Ковертація версії у рядковий тип

   * @details Якщо версія 0.0.0 то метод повертає рядок що повідомляє про
   * демонстраційну версію. Якщо версіювання мість завершуючі нулі то вони не
   * виводяться.
   * @endif
   *
   * @param ver
   * @return String
   */
  friend String StrVersion(Version ver) {
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