#ifndef COURSE_WORK_FLOATMATRIX_H
#define COURSE_WORK_FLOATMATRIX_H

#include <ostream>
#include "../AbstractMatrix/AbstractMatrix.h"

class FloatMatrix : AbstractMatrix {
public:
  FloatMatrix();

  FloatMatrix(size_t typeSize, size_t size);

  std::istream &operator>>(std::istream &is);

  std::ostream &operator<<(std::ostream &os) const;

  ~FloatMatrix();
};


#endif //COURSE_WORK_FLOATMATRIX_H
