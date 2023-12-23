#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include "helper.hpp"

namespace matrix {
    template <class T>
    class MatrixData {
    public:
        MatrixData() = delete;
        MatrixData(std::shared_ptr<std::map<Point, MatrixData<T>>> matrix)
            : _matrix(matrix)
        {}

        MatrixData& operator=(T value) {
            // if (value == T()) {
            //     auto it = matrix_ref.sparse_matrix.find(std::make_pair(row, col));
            //     if (it != matrix_ref.sparse_matrix.end()) {
            //         matrix_ref.sparse_matrix.erase(it);
            //     }
            //     } else {
            //     matrix_ref.sparse_matrix[std::make_pair(row, col)] = value;
            // }
            _data = value;
            return *this;
        }

        operator T() const {
            return _data;
        }

    private:
        T _data;
        std::weak_ptr<std::map<Point, MatrixData<T>>> _matrix;
    };

    template <class T>
    class PMatrix {
    public:
        PMatrix() = delete;
        PMatrix(size_t row, std::shared_ptr<std::map<Point, MatrixData<T>>> matrix)
            : _row(row),
              _matrix(matrix)
        {}

        MatrixData<T> operator[](size_t column) {
            std::cout << "MatrixData<T>& operator[](size_t column)\n";
            if (_matrix->contains({ _row, column })) {
                return _matrix->at({ _row, column }); 
            }

            return MatrixData<T>(_matrix);
        }

    private:
        size_t _row;
        std::shared_ptr<std::map<Point, MatrixData<T>>> _matrix;
    };
    
    template <class T>
    class Matrix {
    public:
        Matrix() 
            : _matrix(std::make_shared<std::map<Point, MatrixData<T>>>())
        {}

        PMatrix<T> operator[](size_t row) {
            std::cout << "PMatrix<T> operator[](size_t row)\n";
            return PMatrix<T>(row, _matrix); 
        }

        size_t size() const {
            return _matrix->size();
        }

    private:
        std::shared_ptr<std::map<Point, MatrixData<T>>> _matrix;
    };
}

#endif // MATRIX_H