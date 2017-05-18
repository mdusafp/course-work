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

