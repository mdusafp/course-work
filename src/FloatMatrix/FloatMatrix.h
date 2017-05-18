#ifndef COURSE_WORK_FLOATMATRIX_H
#define COURSE_WORK_FLOATMATRIX_H

#include <ostream>
#include <iostream>
#include <fstream>

#include "../AbstractMatrix/AbstractMatrix.h"

class FloatMatrix : public AbstractMatrix {
private:
  size_t typeSize;
public:
  FloatMatrix();
  FloatMatrix(size_t typeSize);
  FloatMatrix(const FloatMatrix& matrix);
  FloatMatrix(FloatMatrix&& matrix) noexcept;

  size_t getTypeSize() const;

  void setTypeSize(size_t typeSize);

  FloatMatrix& operator+(FloatMatrix &right);
  friend std::ostream &operator<<(std::ostream &os, const FloatMatrix &matrix);
  friend std::ofstream &operator<<(std::ofstream &ofs, const FloatMatrix &matrix);
};

#endif //COURSE_WORK_FLOATMATRIX_H
