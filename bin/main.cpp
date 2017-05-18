#include <iostream>
#include "../src/AbstractMatrix/AbstractMatrix.h"
#include "../src/FloatMatrix/FloatMatrix.h"

int main(int argc, const char* argv[]) {
  AbstractMatrix matrix1;

  std::cin >> matrix1;
  std::cout << matrix1;

  AbstractMatrix matrix2;
  std::cin >> matrix2;
  std::cout << matrix2;

  std::cout << "matrix1 == matrix2?" << std::endl;
  matrix1 == matrix2 ? std::cout << "Yep" : std::cout << "Nope";
  FloatMatrix fmatrix;
  std::cin >> fmatrix;
  std::cout << fmatrix;

  return 0;
}