#include "AbstractMatrix.h"

AbstractMatrix::AbstractMatrix()
    : size(0), typeSize(sizeof(char)), data(nullptr)
{}

AbstractMatrix::AbstractMatrix(size_t size, size_t typeSize)
    : size(size), typeSize(typeSize), data(new char[size * size * typeSize])
{}

AbstractMatrix::AbstractMatrix(const AbstractMatrix &matrix) {
  if (data) {
    delete data;
  }

  size = matrix.getSize();
  typeSize = matrix.getTypeSize();
  data = new char[size * size * typeSize];
  for (int i = 0; i < size * size * typeSize; ++i) {
    data[i] = matrix.getData()[i];
  }
}

size_t AbstractMatrix::getTypeSize() const {
  return this->typeSize;
}

void AbstractMatrix::setTypeSize(size_t typeSize) {
  this->typeSize = typeSize;
}

AbstractMatrix::AbstractMatrix(AbstractMatrix &&matrix) noexcept {
  data = matrix.getData();
  size = matrix.getSize();
  typeSize = matrix.getTypeSize();

  matrix.setData(nullptr);
  matrix.setSize(0);
  matrix.setTypeSize(0);
}

AbstractMatrix::~AbstractMatrix() {
  delete data;
}

AbstractMatrix& AbstractMatrix::operator=(const AbstractMatrix &matrix) {
  if (this == &matrix) {
    return *this;
  }

  if (data) {
    delete data;
  }

  size = matrix.getSize();
  data = new char[size * size * typeSize];

  for (int i = 0; i < size * size * typeSize; ++i) {
    data[i] = matrix.getData()[i];
  }

  return *this;
}

bool AbstractMatrix::operator==(const AbstractMatrix &matrix) const {
  if (size != matrix.getSize() || typeSize != matrix.getTypeSize()) {
    return false;
  }

  for (int i = 0; i < size * size * typeSize; ++i) {
    if (data[i] != matrix.getData()[i]) {
      return false;
    }
  }

  return true;
}

bool AbstractMatrix::operator!=(const AbstractMatrix &matrix) const {
  return !(matrix == *this);
}

size_t AbstractMatrix::getSize() const {
  return size;
}

void AbstractMatrix::setSize(size_t size) {
  this->size = size;
}

char *AbstractMatrix::getData() const {
  return data;
}

void AbstractMatrix::setData(char *data) {
  this->data = data;
}


AbstractMatrix& AbstractMatrix::operator+(AbstractMatrix &ptr) {
  char* leftPtr = getData();
  char* rightPtr = ptr.getData();
  char* c = nullptr;

  for (int i = 0; i < size * size * typeSize; i += typeSize) {
    c = nullptr;
    c = sum(leftPtr, rightPtr);
    memcpy(data + i, c, strlen(c));
  }

  return *this;
}

std::istream &operator>>(std::istream &is, AbstractMatrix &matrix) {
  for (int i = 0; i < matrix.getSize() * matrix.getSize(); i += matrix.getTypeSize()) {
    matrix.input(is, matrix.getData() + i);
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, AbstractMatrix &matrix) {
  for (int i = 0; i < matrix.getSize(); ++i) {
    for (int j = 0; j < matrix.getSize(); ++j) {
      matrix.output(os, matrix.getData() + i * matrix.getSize() + j);
    }
    os << std::endl;
  }
  return os;
}

std::ifstream &operator>>(std::ifstream &ifs, AbstractMatrix &matrix) {
  for (int i = 0; i < matrix.getSize() * matrix.getSize(); i += matrix.getTypeSize()) {
    matrix.finput(ifs, matrix.getData() + i);
  }
  return ifs;
}

std::ofstream &operator<<(std::ofstream &ofs, AbstractMatrix &matrix) {
  for (int i = 0; i < matrix.getSize(); i += matrix.getTypeSize()) {
    for (int j = 0; j < matrix.getSize(); j += matrix.getTypeSize()) {
      matrix.output(ofs, matrix.getData() + i * matrix.getSize() + j);
    }
    ofs << std::endl;
  }
  return ofs;
}
