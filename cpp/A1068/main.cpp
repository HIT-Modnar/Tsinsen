// Source : http://www.tsinsen.com/1068
// Author : Modnar
// Date   : 2019-03-21

#include <iostream>

const int MAX_SIZE = 200;

// The idea is from https://blog.csdn.net/qq_36238595/article/details/54576614
// Thanks the friend here.
int main(int argc, char *argv[]) {
    // Use the printed number's count to stop the loop.
    int m, n, ans[MAX_SIZE][MAX_SIZE], i = 0, j = 0, cnt = 0;
    std::cin >> m >> n;
    for (size_t i = 0; i < m; ++i)
        for (size_t j = 0; j < n; ++j)
            std::cin >> ans[i][j];
    std::cout << ans[0][0];
    // Judge whether the number has been printed by whether its value is -1.
    ans[0][0] = -1;
    ++cnt; 
    while (cnt < m*n) {
        while (i+1 < m && ans[i+1][j] != -1) {
            std::cout << " " << ans[++i][j];
            ans[i][j] = -1;
            ++cnt;
        }
        while (j+1 < n && ans[i][j+1] != -1) {
            std::cout << " " << ans[i][++j];
            ans[i][j] = -1;
            ++cnt;
        }
        while (i-1 >= 0 && ans[i-1][j] != -1) {
            std::cout << " " << ans[--i][j];
            ans[i][j] = -1;
            ++cnt;
        }
        while (j-1 >= 0 && ans[i][j-1] != -1) {
            std::cout << " " << ans[i][--j];
            ans[i][j] = -1;
            ++cnt;
        }
    }
    std::cout << std::endl;
    return 0;
}

/*
// Source : http://www.tsinsen.com/1068
// Author : Modnar
// Date   : 2019-03-19

// Note   : The solution here only get the score of 80 on tsinsen.com

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
    int cnt = 0;
    while (base_of_row < n-base_of_row-1 && base_of_col < m-base_of_col-1) {
        i = base_of_row;
        j = base_of_col;
        for (; i < n-base_of_row-1; ++i) {
            std::cout << matrix[i][j];
            ++cnt;
            if (cnt != m*n)
                std::cout << " ";
        }
        for (; j < m-base_of_col-1; ++j) {
            std::cout << matrix[i][j];
            ++cnt;
            if (cnt != m*n)
                std::cout << " ";
        }
        for (; i > base_of_row; --i) {
            std::cout << matrix[i][j];
            ++cnt;
            if (cnt != m*n)
                std::cout << " ";
        }
        for (; j > base_of_col; --j) {
            std::cout << matrix[i][j];
            ++cnt;
            if (cnt != m*n)
                std::cout << " ";
        }
        ++base_of_row;
        ++base_of_col;
    }
    if (m * n % 2 == 1) {
        if (n >= m)
            for (i = base_of_row; i < n-base_of_row; ++i) {
                std::cout << matrix[i][base_of_col];
                ++cnt;
                if (cnt != m*n)
                    std::cout << " ";
            }
        else 
            for (j = base_of_col; j < m-base_of_col; ++j) {
                std::cout << matrix[base_of_row][j] << " ";
                ++cnt;
                if (cnt != m*n)
                    std::cout << " ";
            }
    }
    std::cout << std::endl;
    return 0;
}
*/
