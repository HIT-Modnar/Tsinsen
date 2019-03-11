#include <iostream>

int number;

void An(int n, int limit) {
    if (n == limit) {
        std::cout << "sin(" << n << ")";
        return;
    }
    std::cout << "sin(" << n << (n % 2 == 0 ? "+" : "-");
    An(n+1, limit);
    std::cout << ")";
}

void Sn(int n) {
    if (n == 1) {
        An(1, number);
        std::cout << "+" << number-n+1;
        return;
    }
    std::cout << "(";
    Sn(n-1);
    std::cout << ")";
    An(number-n, number);
    std::cout << "+" << number-n+1;
}

int main(int argc, char *argv[]) {
    std::cin >> number;
    return 0;
}
