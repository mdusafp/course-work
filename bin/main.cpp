#include <iostream>

#include "../src/FloatMatrix/FloatMatrix.h"

int main(int argc, const char* argv[]) {
  FloatMatrix matr(sizeof(float), 8);

//  std::cout << *(float*)(matr.data);
  std::cin >> matr;
  std::cout << *(float*)(matr.data);

  return 0;
}