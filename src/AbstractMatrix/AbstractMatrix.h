#ifndef COURSE_WORK_ABSTRACTMATRIX_H
#define COURSE_WORK_ABSTRACTMATRIX_H

#include <cstdlib>
#include <istream>
#include <ostream>
#include <cstring>
#include <iostream>
#include <fstream>

class AbstractMatrix
{
public:
  char* data;
  size_t size;
  size_t typeSize;

  AbstractMatrix();
  AbstractMatrix(size_t size, size_t typeSize);
  AbstractMatrix(const AbstractMatrix &matrix);
  AbstractMatrix(AbstractMatrix &&matrix) noexcept;
  virtual ~AbstractMatrix();

  AbstractMatrix& operator=(AbstractMatrix &);
  AbstractMatrix& operator+(AbstractMatrix &ptr);
  AbstractMatrix& operator*(AbstractMatrix &ptr);
  bool operator==(const AbstractMatrix &matrix) const;
  bool operator!=(const AbstractMatrix &matrix) const;

  virtual void sum(char*, char*, char*) {};
  virtual void mn(char*, char*, char*) {};

  size_t getSize() const;
  void setSize(size_t size);

  char *getData() const;
  void setData(char *data);

  size_t getTypeSize() const;
  void setTypeSize(size_t typeSize);

  friend std::istream &operator>>(std::istream &is, AbstractMatrix &matrix);
  virtual std::istream &input(std::istream &is, char *ptr);

  friend std::ostream &operator<<(std::ostream &os, AbstractMatrix &matrix);
  virtual std::ostream &output(std::ostream &os, const char *ptr);

  friend std::ifstream &operator>>(std::ifstream &ifs, AbstractMatrix &matrix);
  virtual std::ifstream &finput(std::ifstream &ifs, char *ptr);

  friend std::ofstream &operator<<(std::ofstream &ofs, AbstractMatrix &matrix);
  virtual std::ofstream &foutput(std::ofstream &ofs, const char* ptr);
};


#endif //COURSE_WORK_ABSTRACTMATRIX_H
