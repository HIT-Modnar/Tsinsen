// Source : http://www.tsinsen.com/A1010
// Author : Modnar
// Date   : 2019-01-17

#include <iostream>

int main() {
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char ans[10];
    int ansIndex = 0, number = 0;
    ans[0] = '0';
    std::cin >> number;
    while(number) {
        ans[ansIndex++] = hex[number%16];
        number = number / 16;
    }
    for (int i = ansIndex-1; i >= 0; i--) {
        std::cout << ans[i];
    }
    std::cout << std::endl;
    return 0;
}
