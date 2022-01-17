#include "Message.hpp"

#include <cstdlib>
#include <iostream>

int main() {
  Message say_hello("Hello, Cmake World!");
  std::cout << say_hello << std::endl;

  return EXIT_SUCCESS;
}
