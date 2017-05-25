#include "FloatMatrix.h"

FloatMatrix::FloatMatrix()
    : AbstractMatrix()
{}

FloatMatrix::FloatMatrix(size_t size, size_t typeSize)
    : AbstractMatrix(size, typeSize)
{}

char* AbstractMatrix::sum(char *a, char *b)
{
  float _a = *(float*)a;
  float _b = *(float*)b;
  float* sum = new float(_a + _b);
  return (char*)sum;
}

FloatMatrix::FloatMatrix(const FloatMatrix &matrix) {
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

FloatMatrix::FloatMatrix(FloatMatrix &&matrix) noexcept {
  data = matrix.getData();
  size = matrix.getSize();
  typeSize = matrix.getTypeSize();

  matrix.setData(nullptr);
  matrix.setSize(0);
  matrix.setTypeSize(0);
}

std::istream &AbstractMatrix::input(std::istream &is, char *ptr) {
  is >> *(float*) ptr;
  return is;
}

std::ostream &AbstractMatrix::output(std::ostream &os, const char *ptr) {
  os << *(float*) ptr << ' ';
  return os;
}

std::ifstream &AbstractMatrix::finput(std::ifstream &ifs, char *ptr) {
  ifs >> *(float*) ptr;
  return ifs;
}

std::ofstream &AbstractMatrix::foutput(std::ofstream &ofs, const char *ptr) {
  ofs << *(float*) ptr << ' ';
  return ofs;
}
