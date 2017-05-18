#include "AbstractMatrix.h"

AbstractMatrix::AbstractMatrix()
    : data(nullptr), size(0)
{}

AbstractMatrix::AbstractMatrix(size_t size)
    : data(nullptr), size(size * size)
{}


AbstractMatrix::AbstractMatrix(const AbstractMatrix &matrix) {
  delete data;

  size = matrix.size;
  data = new char[size];
  for (int i = 0; i < size * size; ++i) {
    data[i] = matrix.data[i];
  }
}

AbstractMatrix::AbstractMatrix(AbstractMatrix &&matrix) noexcept {
  data = matrix.data;
  size = matrix.size;
  matrix.data = nullptr;
  matrix.size = 0;
}

AbstractMatrix::~AbstractMatrix() {
  delete data;
}

AbstractMatrix& AbstractMatrix::operator=(const AbstractMatrix &matrix) {
  if (data) {
    delete data;
  }

  size = matrix.size;
  data = new char[size * size];

  for (int i = 0; i < size * size; ++i) {
    data[i] = matrix.data[i];
  }

  return *this;
}

bool AbstractMatrix::operator==(const AbstractMatrix &matrix) const {
  if (size != matrix.size) {
    return false;
  }

  for (int i = 0; i < size * size; ++i) {
    if (data[i] != matrix.data[i]) {
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
  this->size = size * size;
}

char *AbstractMatrix::getData() const {
  return data;
}

void AbstractMatrix::setData(char *data) {
  this->data = data;
}

std::istream &operator>>(std::istream &is, AbstractMatrix &matrix) {
  std::cout << "Enter size of matrix: ";
  is >> matrix.size;

  if (matrix.data) {
    delete matrix.data;
  }
  matrix.data = new char[matrix.size * matrix.size];

  std::cout << "Enter the data of matrix:" << std::endl;
  for (int i = 0; i < matrix.size * matrix.size; ++i) {
    is >> matrix.data[i];
  }
  std::cout << std::endl;
  return is;
}

std::ostream &operator<<(std::ostream &os, const AbstractMatrix &matrix) {
  os << "Matrix:" << std::endl;
  for (int i = 0; i < matrix.size; ++i) {
    for (int j = 0; j < matrix.size; ++j) {
      os << matrix.data[i * matrix.size + j] << ' ';
    }
    os << std::endl;
  }
  os << std::endl;
  return os;
}

std::ifstream &operator>>(std::ifstream &ifs, AbstractMatrix &matrix) {
  ifs >> matrix.size;

  if (matrix.data) {
    delete matrix.data;
  }
  matrix.data = new char[matrix.size * matrix.size];

  for (int i = 0; i < matrix.size * matrix.size; ++i) {
    ifs >> matrix.data[i];
  }
  std::cout << std::endl;
  return ifs;
}

std::ofstream &operator<<(std::ofstream &ofs, const AbstractMatrix &matrix) {
  ofs << "Matrix:" << std::endl;

  for (int i = 0; i < matrix.size; ++i) {
    for (int j = 0; j < matrix.size; ++j) {
      ofs << matrix.data[i * matrix.size + j] << ' ';
    }
    ofs << std::endl;
  }
  ofs << std::endl;
  return ofs;
}
