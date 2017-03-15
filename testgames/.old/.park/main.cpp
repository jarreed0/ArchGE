#include "park.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv) {
  try {
    Park p;
    return p.start();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
