#include "AbstractMatrix.h"
#include "math.h"

AbstractMatrix::AbstractMatrix()
    : size(0), typeSize(sizeof(char)), data(nullptr)
{}

AbstractMatrix::AbstractMatrix(size_t size, size_t typeSize)
    : size(size), typeSize(typeSize), data(new char[size * size * typeSize])
{}

AbstractMatrix::~AbstractMatrix()
{
  delete []data;
}

AbstractMatrix::AbstractMatrix(const AbstractMatrix &matrix)
{
  if (data)
  {
    delete data;
  }

  size = matrix.getSize();
  typeSize = matrix.getTypeSize();
  data = new char[size * size * typeSize];
  for (unsigned int i = 0; i < size * size * typeSize; ++i)
  {
    data[i] = matrix.getData()[i];
  }
}

size_t AbstractMatrix::getTypeSize() const
{
  return this->typeSize;
}

void AbstractMatrix::setTypeSize(size_t typeSize)
{
  this->typeSize = typeSize;
}

AbstractMatrix::AbstractMatrix(AbstractMatrix &&matrix) noexcept
{
  data = matrix.getData();
  size = matrix.getSize();
  typeSize = matrix.getTypeSize();

  matrix.setData(nullptr);
  matrix.setSize(0);
  matrix.setTypeSize(0);
}

AbstractMatrix& AbstractMatrix::operator=(AbstractMatrix &matrix)
{
  if(size != matrix.size)
  {
    delete[] data;
    typeSize = matrix.typeSize;
    size = matrix.size;
    data = new char[size*size*typeSize];
  }
  memcpy(data, matrix.data, size*size*typeSize);
  return *this;
}

bool AbstractMatrix::operator==(const AbstractMatrix &matrix) const
{
  int count = 0;
  int pred = size/2;
  for (unsigned int i = 0; i < size; i++)
  {
    bool rowEq = true;
    for(unsigned int j = 0; j < size * typeSize; j = j + typeSize)
    {
      if(data[i*size * typeSize + j] != matrix.data[i*size * typeSize + j])
        rowEq = false;
    }
    if(rowEq) count++;
    if(count > pred) return true;
  }

  return false;
}


bool AbstractMatrix::operator!=(const AbstractMatrix &matrix) const
{
  return !(matrix == *this);
}

size_t AbstractMatrix::getSize() const
{
  return size;
}

void AbstractMatrix::setSize(size_t size)
{
  this->size = size;
}

char *AbstractMatrix::getData() const
{
  return data;
}

void AbstractMatrix::setData(char *data)
{
  this->data = data;
}

AbstractMatrix& AbstractMatrix::operator+(AbstractMatrix &ptr)
{
  AbstractMatrix *result = new AbstractMatrix(size, typeSize);
  for (unsigned int i = 0; i < size * size * typeSize; i += typeSize)
  {
    sum(result->data +i, data+i, ptr.data + i);
  }

  return *result;
}

AbstractMatrix& AbstractMatrix::operator*(AbstractMatrix &ptr)
{
  AbstractMatrix *result = new AbstractMatrix(size, typeSize);
  for (unsigned int i = 0; i < size * size * typeSize; i = i + typeSize)
  {
    if(data[i] == 48)
      result->data[i] = 48;
    else
      mn(result->data + i, data+i, ptr.data + i);
  }

  return *result;
}

std::istream &operator>>(std::istream &is, AbstractMatrix &matrix)
{
  for (unsigned int i = 0; i < matrix.getSize() * matrix.getSize()* matrix.getTypeSize(); i += matrix.getTypeSize())
  {
    matrix.input(is, matrix.getData() + i);
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, AbstractMatrix &matrix)
{
  for (unsigned int i = 0; i < matrix.getSize() * matrix.getSize()* matrix.getTypeSize(); i += matrix.getTypeSize())
  {
    matrix.output(os, matrix.getData() + i);
  }
  return os;
}

std::ifstream &operator>>(std::ifstream &ifs, AbstractMatrix &matrix)
{
  for (unsigned int i = 0; i < matrix.getSize() * matrix.getSize()* matrix.getTypeSize(); i += matrix.getTypeSize())
  {
    matrix.finput(ifs, matrix.getData() + i);
  }
  return ifs;
}

std::ofstream &operator<<(std::ofstream &ofs, AbstractMatrix &matrix)
{
  for (unsigned int i = 0; i < matrix.getSize() * matrix.getSize()* matrix.getTypeSize(); i += matrix.getTypeSize())
  {
    matrix.foutput(ofs, matrix.getData() + i);
  }
  return ofs;
}
