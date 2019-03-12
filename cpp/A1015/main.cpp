// Source : http://www.tsinsen.com/A1015
// Author : Modnar
// Date   : 2019-01-17

#include <iostream>

int main() {
    int ans[35][35];
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) 
                ans[i][j] = 1;
            else
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << ans[i][j] << " ";
            if (i == j) 
                std::cout << std::endl;
        }
    }
    return 0;
}
