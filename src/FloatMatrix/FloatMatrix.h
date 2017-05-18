#ifndef COURSE_WORK_FLOATMATRIX_H
#define COURSE_WORK_FLOATMATRIX_H

#include <ostream>
#include <iostream>

#include "../AbstractMatrix/AbstractMatrix.h"

class FloatMatrix : public AbstractMatrix {
private:
  size_t typeSize;
public:
  FloatMatrix();
  FloatMatrix(size_t typeSize);

  size_t getTypeSize() const;

  void setTypeSize(size_t typeSize);
};

#endif //COURSE_WORK_FLOATMATRIX_H
