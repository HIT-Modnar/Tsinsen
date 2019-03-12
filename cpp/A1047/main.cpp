// Source : http://www.tsinsen.com/A1047
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>
#include <string.h>

int main() {
    int matrix[50][100];
    int ans[100] = {0};
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            std::cin >> matrix[i][j];
    for (int i = 0; i < m; i++) {
        int minCost = matrix[0][i];
        if (minCost != 0) 
            ans[i] = 1;
        else
            minCost = 100;
        for (int j = 1; j < n; j++) {
            if (matrix[j][i] != 0 && matrix[j][i] <= minCost) {
                minCost = matrix[j][i];
                ans[i] = j+1;
            }
        }
    }
    for (int i = 0; i < m; i++)
        std::cout << ans[i] << " ";
    std::cout << std::endl;
    return 0;
}

