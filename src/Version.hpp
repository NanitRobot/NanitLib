/**
 * @file Version.hpp
 * @author Sam4uk
 * 
 * @if English
 * @brief Classes that allow tracking the versions of libraries and boards.
 * @else
 * @brief Класи які дозволяють відслідковувати версії бібіліотеки та плати
 * @endif
 * @version 0.1
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
 public:
  /**
   * @brief Construct a new Version object
   *
   * @param major Визначає головну версію
   * @param minor Визначає мінорну версію
   * @param patch Визначає патч версію
   * @param tweak
   */
  Version(uint16_t major = {}, uint16_t minor = {}, uint16_t patch = {}, uint16_t tweak = {})
      : _major{major}, _minor{minor}, _patch{patch},_tweak{tweak} {};
  
  /**
   * @brief Отримати Версію
   *
   * @return uint16_t
   */
  uint16_t getMajor() const { return _major; }
  
  /**
   * @brief Отримати мінорну версію
   *
   * @return uint16_t
   */
  uint16_t getMinor() const { return _minor; }
  
  /**
   * @brief Отримати патч версію
   *
   * @return uint16_t
   */
  uint16_t getPatch() const { return _patch; }
  
  /**
   * @brief Отримати патч версію
   *
   * @return uint16_t
   */
  uint16_t getTweak() const { return _tweak; }
  /** @if English
   * @else
   * @todo TODO rule of 3
   * @endif
   */
  /**
   * @brief Операця порівняння \b <
   */
  friend inline bool operator<(Version lhs, Version rhs) {
    if (lhs._major < rhs._major) return true;
    if (lhs._minor < rhs._minor) return true;
    if (lhs._patch < rhs._patch) return true;
    return (lhs._tweak < rhs._tweak);
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
    return (lhs._major == rhs._major) && (lhs._minor == rhs._minor) &&
           (lhs._patch == rhs._patch) && (lhs._tweak == rhs._tweak);
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
   * демонстраційну версію. Якщо версіювання мість заввершуючі нулі то вони не
   * виводяться.
   *
   * @param ver
   * @return String
   */
  friend String StrVersion(Version ver) {
    if (!(ver._major || ver._minor || ver._patch)) return "DEMO";
    String result{ver._major};
    if (0 != ver._minor) result += '.' + String(ver._minor);
    if (0 != ver._patch) {
      if (0 == ver._minor) result += ".0";
      result += '.' + String(ver._patch);
    }
    return result;
  };

 private:
  uint16_t  //
      _major,  ///< приватне поле яке містить головну версію
      _minor,  ///< приватне поле яке містить мінорну версію
      _patch,  ///< приватне поле яке містить патч версію
      _tweak;
  /// @endcond
};
#endif