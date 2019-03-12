// Source : http://www.tsinsen.com/A1036
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>

int main() {
    int lst[1000000] = {0}; 
    int a, b;
    std::cin >> a >> b;
    for (int i = 2; i <= b; i++) {
        if (lst[i] != 0)
            continue;
        for (int j = i+i; j <= b; j += i) {
            if (lst[j] != 0)
                continue;
            lst[j] = i;
        }
    }
    for (int i = a; i <= b; i++) {
        std::cout << i << "=";
        int tmp = i;
        while (lst[tmp] != 0) {
            std::cout << lst[tmp] << "*";
            tmp = tmp / lst[tmp];
        }
        std::cout << tmp << std::endl;
    }
    return 0;
}

