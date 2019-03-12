// Source : http://www.tsinsen.com/A1040
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>

int main() {
    int n, base;
    std::cin >> n;
    for (base = 0; base < 500; base++)
        if ((base * base + base) / 2 >= n)
            break;
    base--;
    int number = n - (base * base + base) / 2;
    base += 2;
    if (base % 2 == 0)
        std::cout << base-number << "/" << number << std::endl;
    else
        std::cout << number << "/" << base-number << std::endl;
    return 0;
}

