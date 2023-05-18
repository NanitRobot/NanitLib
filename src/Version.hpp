#ifndef _VERSION_H_
#define _VERSION_H_
#include <WString.h>
/**
 * @author Sam4uk
 * @date 27-03-23
 */

#define DEMO "DEMO"
/**
 * @brief 
 * 
 */

class Version {
public:
  Version(unsigned major = {}, unsigned minor = {}, unsigned patch = {})
      : _major{major}, _minor{minor}, _patch{patch} {};
  unsigned getMajor() const { return _major; }
  unsigned getMinor() const { return _minor; }
  unsigned getPatch() const { return _patch; }
  // TODO rule of 3
  friend inline bool operator<(Version lhs, Version rhs) {
    if (lhs._major < rhs._major)
      return true;
    if (lhs._minor < rhs._minor)
      return true;
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
  friend String StrVersion(Version ver) {
    if (!(ver._major || ver._minor || ver._patch))
      return DEMO;
    String result{ver._major};
    if (0 != ver._minor)
      result += '.' + String(ver._minor);
    if (0 != ver._patch) {
      if (0 == ver._minor)
        result += ".0";
      result += '.' + String(ver._patch);
    }
    return result;
  };

private:
  unsigned _major, _minor, _patch;
};
#endif