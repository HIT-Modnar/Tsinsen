// Source : http://www.tsinsen.com/1068
// Author : Modnar
// Date   : 2019-03-19

#include <iostream>

const int MAX_SIZE = 200;

int main(int argc, char *argv[]) {
    int m, n, matrix[MAX_SIZE][MAX_SIZE];
    std::cin >> n >> m;
    int base_of_row = 0, base_of_col = 0;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j) 
            std::cin >> matrix[i][j];
    int i, j;
    while (base_of_row < n-base_of_row-1 && base_of_col < m-base_of_col-1) {
        i = base_of_row;
        j = base_of_col;
        for (; i < n-base_of_row-1; ++i)
            std::cout << matrix[i][j] << " ";
        for (; j < m-base_of_col-1; ++j)
            std::cout << matrix[i][j] << " ";
        for (; i > base_of_row; --i)
            std::cout << matrix[i][j] << " ";
        for (; j > base_of_col; --j)
            std::cout << matrix[i][j] << " ";
        ++base_of_row;
        ++base_of_col;
    }
    if (m * n % 2 == 1) {
        if (n >= m)
            for (i = base_of_row; i < n-base_of_row; ++i)
                std::cout << matrix[i][base_of_col] << " ";
        else 
            for (j = base_of_col; j < m-base_of_col; ++j)
                std::cout << matrix[base_of_row][j] << " ";
    }
    std::cout << std::endl;
    return 0;
}
