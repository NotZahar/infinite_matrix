#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include "helper.hpp"

namespace matrix {
    template <class T, size_t N>
    class IMatrix {
    public:
        using data_t = std::map<Point, T>;
        using dataPtr_t = std::unique_ptr<data_t>;
        using xs_t = std::vector<size_t>;

        IMatrix() = delete;
        IMatrix(dataPtr_t data, xs_t&& xs)
            : _data(std::move(data)),
              _xs(std::move(xs))
        {}

        virtual IMatrix& operator[](size_t xi) = 0;

    protected:
        dataPtr_t _data;
        xs_t _xs;
    };

    template <class T, size_t N>
    class Matrix;
    
    template <class T, size_t N>
    class PMatrix : public IMatrix<T, N> {
    public:
        using matrix_t = IMatrix<T, N>;
        using data_t = matrix_t::data_t;
        using dataPtr_t = matrix_t::dataPtr_t;
        using xs_t = matrix_t::xs_t;

        PMatrix(dataPtr_t data, xs_t&& xs)
            : matrix_t(std::move(data), std::move(xs)) 
        {}

        PMatrix<T, N - 1>& operator[](size_t xi) override {
            std::cout << "PMatrix";
            matrix_t::_xs.push_back(xi);
            return *this;
        }
    };

    template <class T, size_t N>
    class Matrix : public PMatrix<T, N> {
    public:
        using pmatrix_t = PMatrix<T, N>;
        using data_t = pmatrix_t::data_t;
        using dataPtr_t = pmatrix_t::dataPtr_t;
        using xs_t = pmatrix_t::xs_t;

        Matrix()
            : pmatrix_t({}, std::make_unique<dataPtr_t>())
        {}

        Matrix<T, N - 1>& operator[](size_t xi) override {
            std::cout << "Matrix";
            pmatrix_t::_xs.push_back(xi);
            if (N <= 1)
                return *this;
            return *this;
        }
    };
}

#endif // MATRIX_H