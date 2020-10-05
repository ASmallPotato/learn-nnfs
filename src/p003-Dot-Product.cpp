#include <iostream>
#include "../lib/matrix.hpp"

int main()
{
    Matrix<double> inputs({ 4, 1 });
    inputs.set({ 1, 2, 3, 2.5 });

    Matrix<double> weights({ 3, 4 });
    weights.set({
          0.2,   0.8, -0.5,    1,
          0.5, -0.91, 0.26, -0.5,
        -0.26, -0.27, 0.17, 0.87,
    });

    Matrix<double> biases({ 3, 1 });
    biases.set({ 2, 3, 0.5 });

    Matrix<double> output({ 3, 1 });
    weights.dot_to(inputs, output);
    output += biases;

    std::cout << output;
}
