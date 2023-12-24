#include <ranges>

#include <matrix.hpp>

int main(int, char**) {
    matrix::Matrix<int> matrix;
    
    // При запуске программы необходимо создать матрицу с пустым значением 0, заполнить главную
    // диагональ матрицы (от [0,0] до [9,9]) значениями от 0 до 9.
    for (auto i : std::ranges::iota_view{0, 10})
        matrix[i][i] = i;

    // Второстепенную диагональ (от [0,9] до [9,0]) значениями от 9 до 0.
    for (int j = 9; auto i : std::ranges::iota_view{0, 10}) {
        matrix[i][j] = j;
        --j;
    }

    // Необходимо вывести фрагмент матрицы от [1,1] до [8,8]. Между столбцами пробел. Каждая строка
    // матрицы на новой строке консоли.
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }

    // Вывести количество занятых ячеек.
    std::cout << "Количество занятых ячеек: " << matrix.size() << '\n';

    // Вывести все занятые ячейки вместе со своими позициями.
    for (auto it = matrix.cbegin(); it != matrix.cend(); ++it)
        std::cout << "[" << it->first.x1 << ", " << it->first.x2 << "]: " << it->second << '\n';

    return 0;
}
