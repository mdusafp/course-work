#include "FloatMatrix.h"

FloatMatrix::FloatMatrix()
    : AbstractMatrix()
{}

FloatMatrix::FloatMatrix(size_t typeSize, size_t size)
    : AbstractMatrix(typeSize, size)
{}

FloatMatrix::~FloatMatrix()
{}

std::istream &operator>>(std::istream &is, FloatMatrix &matrix) {
  if (matrix.data) {
    delete matrix.data;
  }

  std::cout << "Enter size of matrix: ";
  is >> matrix.size;
  matrix.typeSize = sizeof(float);

  float temp = 0;

  for (int i = 0; i < matrix.size; i += sizeof(float)) {
    is >> temp;
    *(float*)(matrix.data) = temp;
  }

  return is;
}

std::ostream &operator<<(std::ostream &os, const FloatMatrix &matrix) {
  for (int i = 0; i < matrix.size; i += sizeof(float)) {
    os << (float*)matrix.data[i] << (float*)(matrix.data + i) << " ";
  }
  os << std::endl;

  return os;
}


