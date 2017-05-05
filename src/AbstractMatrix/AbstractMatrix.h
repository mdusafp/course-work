#ifndef COURSE_WORK_ABSTRACTMATRIX_H
#define COURSE_WORK_ABSTRACTMATRIX_H

#include <cstdlib>
#include <istream>
#include <ostream>

class AbstractMatrix {
protected:
  char *data;
  size_t typeSize;
  size_t size;

public:
  AbstractMatrix();

  AbstractMatrix(size_t typeSize, size_t size);

  size_t getTypeSize() const;

  void setTypeSize(size_t typeSize);

  size_t getSize() const;

  void setSize(size_t size);

  virtual std::istream &operator>>(std::istream &is);
  // todo made it virtual
  virtual std::ostream &operator<<(std::ostream &os);

  virtual ~AbstractMatrix();
};


#endif //COURSE_WORK_ABSTRACTMATRIX_H
