// Source : http://www.tsinsen.com/A1018
// Author : Modnar
// Date   : 2019-01-18

#include <iostream>

int main() {
    int dig[1000];
    int n = 0, find = 0, pos = -1;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> dig[i];
    }
    std::cin >> find;
    for (int i = 0; i < n; i++) {
        if (dig[i] == find) {
            pos = i + 1;
            break;
        }
    }
    std::cout << pos << std::endl;
    return 0;
}
