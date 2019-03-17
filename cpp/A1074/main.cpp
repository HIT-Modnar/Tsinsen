// Source : http://www.tsinsen.com/1074
// Author : Modnar
// Date   : 2019-03-17

#include <iostream>

const int N = 100;

int matrix[N][N];
int vec[N], ans[N];

int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) 
            std::cin >> matrix[i][j];
    for (int i = 0; i < n; ++i)
        std::cin >> vec[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans[i] += matrix[i][j] * vec[j];
    for (int i = 0; i < n; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}
