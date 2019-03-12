// Source : http://www.tsinsen.com/A1041
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>

int main() {
    int base, index;
    unsigned int ans[30][30], inputMatrix[30][30];
    unsigned int tempX[30][30];
    std::cin >> base >> index;
    for (int i = 0; i < base; i++)
        for (int j = 0; j < base; j++) {
            std::cin >> inputMatrix[i][j];
            ans[i][j] = inputMatrix[i][j];
        }
    for (int id = 1; id < index; id++) {
        for (int i = 0; i < base; i++) 
            for (int j = 0; j < base; j++) {
                unsigned int sum = 0;
                for (int k = 0; k < base; k++) {
                    sum += ans[i][k] * inputMatrix[k][j];
                }
                tempX[i][j] = sum;
            }
        for (int i = 0; i < base; i++)
            for (int j = 0; j < base; j++) 
                ans[i][j] = tempX[i][j];
    }
    if (index == 0) 
        for (int i = 0; i < base; i++) {
            for (int j = 0; j < base; j++) {
                if (i == j)
                    std::cout << "1 ";
                else
                    std::cout << "0 ";
            }
            std::cout << std::endl;
        }
    else 
        for (int i = 0; i < base; i++) {
            for (int j = 0; j < base; j++) 
                std::cout << ans[i][j] << " ";
            std::cout << std::endl;
        }
    return 0;
}
