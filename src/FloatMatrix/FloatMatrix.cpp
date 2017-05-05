#include "FloatMatrix.h"

FloatMatrix::FloatMatrix()
{}

FloatMatrix::FloatMatrix(size_t typeSize, size_t size)
    : AbstractMatrix(typeSize, size)
{}

FloatMatrix::~FloatMatrix()
{}

std::istream &FloatMatrix::operator>>(std::istream &is) {
  if (!data) {
    data = new char[size * typeSize];
  }

  for (int i = 0; i < size * typeSize; ++i) {
    for (int j = 0; j < size * typeSize; ++j) {
      is >> data[i * size * typeSize + j];
    }
  }

  return is;
}

std::ostream &FloatMatrix::operator<<(std::ostream &os) const {
  os << "data: " << std::endl;
  for (int i = 0; i < size * typeSize; ++i) {
    for (int j = 0; j < size * typeSize; ++j) {
      os << data[i * size * typeSize + j] << " ";
    }
    os << std::endl;
  }

  return os;
}

