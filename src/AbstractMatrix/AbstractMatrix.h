#ifndef COURSE_WORK_ABSTRACTMATRIX_H
#define COURSE_WORK_ABSTRACTMATRIX_H

#include <cstdlib>
#include <istream>
#include <ostream>
#include <cstring>
#include <iostream>
#include <fstream>

class AbstractMatrix {
protected:
  char* data;
  size_t size;
public:
  AbstractMatrix();
  explicit AbstractMatrix(size_t size);
  AbstractMatrix(const AbstractMatrix &matrix);
  AbstractMatrix(AbstractMatrix &&matrix) noexcept;

  AbstractMatrix& operator=(const AbstractMatrix &matrix);
  bool operator==(const AbstractMatrix &matrix) const;
  bool operator!=(const AbstractMatrix &matrix) const;

  virtual ~AbstractMatrix();

  size_t getSize() const;
  void setSize(size_t size);

  char *getData() const;
  void setData(char *data);

  friend std::istream &operator>>(std::istream &is, AbstractMatrix &matrix);
  friend std::ostream &operator<<(std::ostream &os, const AbstractMatrix &matrix);
  friend std::ifstream &operator>>(std::ifstream &ifs, AbstractMatrix &matrix);
  friend std::ofstream &operator<<(std::ofstream &ofs, const AbstractMatrix &matrix);
};


#endif //COURSE_WORK_ABSTRACTMATRIX_H
