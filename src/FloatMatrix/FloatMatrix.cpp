#include "FloatMatrix.h"

FloatMatrix::FloatMatrix()
{}

FloatMatrix::FloatMatrix(size_t typeSize)
    : typeSize(typeSize)
{}

size_t FloatMatrix::getTypeSize() const {
  return typeSize;
}

void FloatMatrix::setTypeSize(size_t typeSize) {
  this->typeSize = typeSize;
}

FloatMatrix &FloatMatrix::operator+(FloatMatrix &right) {
  // todo сделать матрицы разных размеров
  char* leftPtr = data;
  char* rightPtr = right.data;

  for (int i = 0; i < size * size; ++i) {
    float a = *(float*)(leftPtr);
    float b = *(float*)(rightPtr);

    float sum = a + b;

    leftPtr += sizeof(float);
    rightPtr += sizeof(float);
  }

  return *this;
}

FloatMatrix::FloatMatrix(const FloatMatrix &matrix) {
  data = nullptr;

  size = matrix.size;
  typeSize = matrix.typeSize;

  data = new char[size * size * typeSize];
  for (int i = 0; i < size * size * typeSize; ++i) {
    data[i] = matrix.data[i];
  }
}

FloatMatrix::FloatMatrix(FloatMatrix &&matrix) noexcept {
  data = matrix.data;
  size = matrix.size;
  typeSize = matrix.typeSize;

  matrix.data = nullptr;
  matrix.size = 0;
  matrix.typeSize = 0;
}


std::ostream &operator<<(std::ostream &os, const FloatMatrix &matrix) {
  for (int i = 0; i < matrix.getSize() * matrix.getSize(); i += sizeof(float)) {
    os << *(float*)matrix.getData()[i] << ' ';
  }
  return os;
}

std::ofstream &operator<<(std::ofstream &ofs, const FloatMatrix &matrix) {
  for (int i = 0; i < matrix.getSize() * matrix.getSize(); i += sizeof(float)) {
    ofs << *(float*)matrix.getData()[i] << ' ';
  }
  return ofs;
}

