#include "ruler.h"
#include <cassert>
#include <iostream>

int main() {
  Ruler r1(12);
  std::cout << r1; // -- visual check, did we print [12]" << std::endl;
  assert(r1.getLength() == 12); //&& ”r1 should have Length 12");
}
