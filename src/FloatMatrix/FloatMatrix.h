#ifndef COURSE_WORK_FLOATMATRIX_H
#define COURSE_WORK_FLOATMATRIX_H

#include <ostream>
#include <iostream>
#include <fstream>

#include "../AbstractMatrix/AbstractMatrix.h"

class FloatMatrix : public AbstractMatrix
{
public:
  FloatMatrix();
  FloatMatrix(size_t size, size_t typeSize);
  FloatMatrix(const FloatMatrix& matrix);
//  FloatMatrix(FloatMatrix&& matrix) noexcept;

  void sum(char *, char *, char *);
  void mn(char*, char*, char*);

  using AbstractMatrix::operator=;
  using AbstractMatrix::operator+;
  using AbstractMatrix::operator==;
  using AbstractMatrix::operator*;
};

#endif //COURSE_WORK_FLOATMATRIX_H
