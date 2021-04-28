#pragma once
#include <iostream>

class Ruler {
  friend std::ostream &operator<<(std::ostream &outStream, const Ruler &ruler);

public:
  explicit Ruler(int length);
  int getLength() const;
  Ruler operator+(const Ruler &other) const;
  Ruler &operator+=(const Ruler &other);

private:
  int length;
};
