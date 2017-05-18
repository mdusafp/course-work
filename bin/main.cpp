#include <iostream>
#include "../src/FloatMatrix/FloatMatrix.h"

int main(int argc, const char* argv[]) {
  int choose = 0;
  FloatMatrix a;

  do {
    std::cin >> choose;

    std::cout << "Choose something" << std::endl;
    std::cout << "1. Console input" << std::endl;
    std::cout << "2. File input" << std::endl;
    std::cout << "3. Console output" << std::endl;
    std::cout << "4. File output" << std::endl;
    std::cout << "5. Sum of matrix" << std::endl;
    std::cout << "6. Equality operators" << std::endl;

    switch (choose) {
      case 1: {
        std::cin >> a;
        break;
      }
      case 2: {
//        ...
        break;
      }
      case 3: {
        std::cout << a;
        break;
      }
      case 4: {
//        ...
        break;
      }
      case 5: {
//        ...
        break;
      }
      case 6: {
//        ...
        break;
      }
      case 0: {
        exit(EXIT_SUCCESS);
      }
      default: {
        std::cout << "Miss keybord" << std::endl;
      }
    }
  } while(true);

  return 0;
}