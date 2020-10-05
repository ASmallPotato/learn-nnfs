#ifndef __MATRIX_HPP_
#define __MATRIX_HPP_

#include <iostream>
#include <vector>

template <typename T>
class Matrix
{
  protected:
    T *storage;
  public:
    std::vector<uint> shape;
    Matrix(std::vector<uint> dimentions);
    ~Matrix();
    void set(std::vector<T> input);
    void dot_to(Matrix<T> const rhs, Matrix<T> &output);
    void operator+=(Matrix<T> rhs);
    template<class U> friend std::ostream &operator << (std::ostream &output, const Matrix<U> &mat)
    {
      for (int d2_idx = 0; d2_idx < mat.shape[0]; d2_idx++)
      {
        for (int d1_idx = 0; d1_idx < mat.shape[1]; d1_idx++)
        {
          output << mat.storage[d1_idx + d2_idx * mat.shape[1]] << " ";
        }
        output << "\n";
      }
      return output;
    }
};

#endif // __MATRIX_H_
