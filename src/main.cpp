#include <iostream>

#include <matrix.hpp>

#define THROW_IF(expr, msg) if(expr) { std::cout << msg << std::endl; throw; }

int main(int, char**) {
    matrix::Matrix<int> matrix;
    std::cout << matrix.size() << std::endl;
    // THROW_IF(matrix.size() != 0, "matrix.size() != 0");

    auto a = matrix[0][0];
    std::cout << a << "\n";
    // THROW_IF(a != int(), "a != int()");
    // THROW_IF(matrix.size() != 0, "13, matrix.size() != 0");

    // matrix[{100, 100}] = 314;
    // if(matrix[{100, 100}] != 314) {
    //     std::cout << "matrix[{100, 100}] != 314" << std::endl;
    //     throw;
    // }
    // THROW_IF(matrix.size() != 1, "matrix.size() != 1");
    // // выведется одна строка
    // // 100100314
    // for (auto it = matrix.cbegin(); it != matrix.cend(); ++it) {
    //     std::cout << it->first.x << " " << it->first.y << " " << it->second << std::endl;
    // }
    
    return 0;
}
