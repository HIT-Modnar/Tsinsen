// Source : http://www.tsinsen.com/A1056
// Author : Modnar
// Date   : 2019-03-12

#include <iostream>

void An(int n, int limit) {
    if (n == limit) {
        std::cout << "sin(" << n << ")";
        return;
    }
    std::cout << "sin(" << n << (n % 2 == 0 ? "+" : "-");
    An(n+1, limit);
    std::cout << ")";
}

void Sn(int n, int limit) {
    if (n == 1) {
        An(1, n);
        std::cout << "+" << limit-n+1;
        return;
    }
    std::cout << "(";
    Sn(n-1, limit);
    std::cout << ")";
    An(1, n);
    std::cout << "+" << limit-n+1;
}

int main(int argc, char *argv[]) {
    int number;
    std::cin >> number;
    Sn(number, number);
    std::cout << std::endl;
    return 0;
}
