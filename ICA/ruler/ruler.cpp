#include "ruler.h"
#include <iostream>

std::ostream &operator<<(std::ostream &outStream, const Ruler &ruler) {
  outStream << ruler.length;
  return outStream;
}

Ruler::Ruler(int length) : length{length} {}

int Ruler::getLength() const { return length; }

Ruler Ruler::operator+(const Ruler &other) const {
  return Ruler(this->length + other.length);
}

Ruler &Ruler::operator+=(const Ruler &other) {
  this->length += other.length;
  return *this;
}

