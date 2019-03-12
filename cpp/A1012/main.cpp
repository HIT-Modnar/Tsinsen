// Source : http://www.tsinsen.com/A1012
// Author : Modnar
// Date   : 2019-01-17

#include <iostream>

int main() {
    char base[36], ans[33];
    int ansIndex = 0;
    int number = 0, hex = 0;
    for (int i = 0; i < 36; i++) {
        if (i <= 9) 
            base[i] = '0' + i;
        else
            base[i] = 'A' + i - 10;
    }
    std::cin >> number >> hex;
    if (number == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    while (number) {
        ans[ansIndex++] = base[number%hex];
        number = number / hex;
    }
    for (int i = ansIndex-1; i >= 0; i--) {
        std::cout << ans[i];
    }
    std::cout << std::endl;
    return 0;
}

