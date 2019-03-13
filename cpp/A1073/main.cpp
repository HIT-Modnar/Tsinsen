// Source : http://www.tsinsen.com/A1073
// Author : Modnar
// Date   : 2019-03-13

#include <iostream>

const int N = 100;

int lst[N][N];

int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            std::cin >> lst[i][j];
    // Compute (A + A').
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i; j < n; ++j)
            lst[i][j] += lst[j][i];
        for (size_t j = 0; j < i; ++j)
            lst[i][j] = lst[j][i];
    }
    for (size_t i = 0; i < n; ++i) 
        for (size_t j = 0; j < n; ++j) {
            char ch = (j == n-1 ? '\n' : ' ');
            std::cout << lst[i][j] << ch;
        }
    return 0;
}

