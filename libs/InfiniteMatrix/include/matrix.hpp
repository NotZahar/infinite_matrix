#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <cassert>
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
        MatrixData(size_t row, size_t column, std::weak_ptr<std::map<Point, MatrixData<T>>> matrix, T data = T())
            : _row(row),
              _column(column),
              _matrix(matrix),
              _data(data)
        {}

        MatrixData& operator=(T value) {
            auto mmatrix = _matrix.lock(); 
            if (value == T() && mmatrix->contains({ _row, _column }))
                mmatrix->erase({ _row, _column });
            
            if (value != T())
                mmatrix->insert({
                    { _row, _column },
                    { _row, _column, _matrix, value }
                });

            _data = value;
            return *this;
        }

        operator T() const {
            return _data;
        }

    private:
        size_t _row;
        size_t _column;
        std::weak_ptr<std::map<Point, MatrixData<T>>> _matrix;
        T _data;
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
            if (_matrix->contains({ _row, column }))
                return _matrix->at({ _row, column });

            return MatrixData<T>(_row, column, _matrix);
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
            return PMatrix<T>(row, _matrix); 
        }

        size_t size() const {
            return _matrix->size();
        }

        std::map<Point, MatrixData<T>>::const_iterator cbegin() const {
            return _matrix->cbegin();
        }

        std::map<Point, MatrixData<T>>::const_iterator cend() const {
            return _matrix->cend();
        }

    private:
        std::shared_ptr<std::map<Point, MatrixData<T>>> _matrix;
    };
}

#endif // MATRIX_H