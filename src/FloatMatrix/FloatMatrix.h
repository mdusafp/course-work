#ifndef COURSE_WORK_FLOATMATRIX_H
#define COURSE_WORK_FLOATMATRIX_H

#include <ostream>
#include <iostream>
#include <fstream>

#include "../AbstractMatrix/AbstractMatrix.h"

class FloatMatrix : public AbstractMatrix {
public:
  FloatMatrix();
  FloatMatrix(size_t size, size_t typeSize);
  FloatMatrix(const FloatMatrix& matrix);
  FloatMatrix(FloatMatrix&& matrix) noexcept;

//  friend std::ostream &operator<<(std::ostream &os, const FloatMatrix &matrix);
//  friend std::ofstream &operator<<(std::ofstream &ofs, const FloatMatrix &matrix);
//  friend std::istream &operator>>(std::istream &is, FloatMatrix &matrix);
//  friend std::ifstream &operator>>(std::ifstream &ifs, FloatMatrix &matrix);

  FloatMatrix& operator=(const FloatMatrix &matrix)
  {
    *this = matrix;
    return *this;
  }
  FloatMatrix& operator+(FloatMatrix &ptr)
  {
    *this = *this + ptr;
    return *this;
  }
};

#endif //COURSE_WORK_FLOATMATRIX_H
