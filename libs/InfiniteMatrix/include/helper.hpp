#ifndef HELPER_H
#define HELPER_H

#include <tuple>
#include <cstddef>

namespace matrix {
    struct Point {
        size_t x1;
        size_t x2;

        friend bool operator<(const Point& lhs, const Point& rhs) {
            return std::tie(lhs.x1, lhs.x2) 
                < std::tie(rhs.x1, rhs.x2);
        }
    };
}

#endif // HELPER_H