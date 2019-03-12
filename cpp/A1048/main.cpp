// Source : http://www.tsinsen.com/A1048
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>

int main() {
    int n, total = 1;
    int matrix[10][10];
    matrix[0][0] = 1;
    std::cin >> n;
    int i, j;
    for (int base = 0; base < n/2; base += 1) {
        for (i = base * 2; i < n-base; i++)
            matrix[i][base] = total++;
        i--;
        for (j = base+1; j < n-2*base; j++)
            matrix[i][j] = total++;
        for (j = j-2; j > base; j--)
            matrix[base+j][j] = total++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}
