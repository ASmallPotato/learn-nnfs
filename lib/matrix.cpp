#include <vector>
#include <iostream>
#include <exception>
#include "matrix.hpp"

template <typename T>
Matrix<T>::Matrix(std::vector<uint> dimentions)
{
  uint arr_size = 1;
  for (auto dimention: dimentions) arr_size *= dimention;
  storage = new T[arr_size];
  shape = dimentions;
}

template <typename T>
Matrix<T>::~Matrix()
{
  delete[] storage;
}

template <typename T>
void Matrix<T>::set(std::vector<T> input)
{
  std::copy(input.begin(), input.end(), this->storage);
}

class UnmatchedPlusException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "lhs.shape must equal to rhs.shape";
  }
} unmatched_plus;

template <typename T>
void Matrix<T>::operator+=(Matrix<T> const rhs)
{
  if (this->shape != rhs.shape) throw unmatched_plus;
  for (uint idx = 0; idx < this->shape[0]; idx++)
  {
    this->storage[idx] += rhs.storage[idx];
  }
}

class UnbalancedDotException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "lhs.shape[0] must equal to rhs.shape[1]";
  }
} unbalanced_dot;

template <typename T>
void Matrix<T>::dot_to(Matrix<T> const rhs, Matrix<T> &output)
{
  if (this->shape[1] != rhs.shape[0]) throw unbalanced_dot;
  for (uint main_idx = this->shape[0]; main_idx--;)
  {
    output.storage[main_idx] = 0;
    for (uint sum_product_idx = this->shape[1]; sum_product_idx--;)
    {
      output.storage[main_idx] += (
        this->storage[sum_product_idx + main_idx * this->shape[1]] *
        rhs.storage[sum_product_idx * rhs.shape[1]]
      );
    }
  }
}


template class Matrix<double>;
