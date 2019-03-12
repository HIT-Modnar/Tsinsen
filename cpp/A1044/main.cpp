// Source : http://www.tsinsen.com/A1044
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>

int main() {
    int fib[21];
    fib[1] = 1;
    fib[2] = 1;
    int n;
    for (int i = 3; i <= 20; i++)
        fib[i] = fib[i-1] + fib[i-2];
    while (true) {
        std::cin >> n;
        if (n == 0) 
            break;
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += fib[i];
        std::cout << sum << std::endl;
    }
    return 0;
}
