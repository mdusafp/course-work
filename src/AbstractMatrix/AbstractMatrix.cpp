#include <cstring>
#include "AbstractMatrix.h"

AbstractMatrix::AbstractMatrix()
{
  this->size = 0;
  this->typeSize = sizeof(char);
  this->data = nullptr;
}

AbstractMatrix::AbstractMatrix(size_t typeSize, size_t size)
    : typeSize(typeSize), size(size)
{
  int fullSize = size * size * typeSize * typeSize;
  this->data = new char[fullSize];

  std::memset(this->data, 0, fullSize);
}

size_t AbstractMatrix::getTypeSize() const {
  return typeSize;
}

void AbstractMatrix::setTypeSize(size_t typeSize) {
  AbstractMatrix::typeSize = typeSize;
}

size_t AbstractMatrix::getSize() const {
  return size;
}

void AbstractMatrix::setSize(size_t size) {
  AbstractMatrix::size = size;
}

AbstractMatrix::~AbstractMatrix() {
  delete this->data;
}

