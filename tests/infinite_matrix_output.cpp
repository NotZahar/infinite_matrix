#include <gtest/gtest.h>

#include <matrix.hpp>

TEST(InfiniteMatrix, matrix_check) {
    matrix::Matrix<int> matrix;
    EXPECT_EQ(matrix.size(), 0);

    auto a = matrix[0][0];
    EXPECT_EQ(a, int());
    EXPECT_EQ(matrix.size(), 0);

    matrix[100][100] = 314;
    EXPECT_EQ(matrix[100][100], 314);
    EXPECT_EQ(matrix.size(), 1);

    matrix[100][100] = int();
    EXPECT_EQ(matrix[100][100], int());
    EXPECT_EQ(matrix.size(), 0);

    matrix[0][0] = 1;
    EXPECT_EQ(matrix[0][0], 1);
    EXPECT_EQ(matrix.size(), 1);

    matrix[0][1] = 2;
    EXPECT_EQ(matrix[0][1], 2);
    EXPECT_EQ(matrix.size(), 2);

    matrix[0][0] = int();
    EXPECT_EQ(matrix.size(), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}