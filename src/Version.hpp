/**
 * @file Version.hpp
 * @author Sam4uk
 * @brief Класи які дозволяють відслідковувати версії бібіліотеки та плати
 * @version 0.1
 *
 * @date 27-03-23
 * @copyright Copyright (c) 2023
 *
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
   */
  Version(unsigned major = {}, unsigned minor = {}, unsigned patch = {})
      : _major{major}, _minor{minor}, _patch{patch} {};
  unsigned getMajor() const { return _major; }
  unsigned getMinor() const { return _minor; }
  unsigned getPatch() const { return _patch; }
  /// @todo TODO rule of 3
  friend inline bool operator<(Version lhs, Version rhs) {
    if (lhs._major < rhs._major) return true;
    if (lhs._minor < rhs._minor) return true;
    return (lhs._patch < rhs._patch);
  }
  friend inline bool operator>(Version lhs, Version rhs) { return (rhs < lhs); }
  friend inline bool operator<=(Version lhs, Version rhs) {
    return !(lhs > rhs);
  }
  friend inline bool operator>=(Version lhs, Version rhs) {
    return !(lhs < rhs);
  }

  friend inline bool operator==(Version lhs, Version rhs) {
    return (lhs._major == rhs._major) && (lhs._minor == rhs._minor) &&
           (lhs._patch == rhs._patch);
  }
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
  unsigned  //
      _major,  ///< приватне поле яке містить головну версію
      _minor,  ///< приватне поле яке містить мінорну версію
      _patch;  ///< приватне поле яке містить патч версію
};
#endif