// Source : http://www.tsinsen.com/A1070
// Author : Modnar
// Date   : 2019-03-30

#include <iostream>
#include <cmath>

const int MAX_SIZE = 102;

int k, n;
int a[MAX_SIZE], b[MAX_SIZE];

int main(int argc, char *argv[]) {
    std::cin >> k >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i] >> b[i];
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < n; ++j) {
            a[j] *= b[j];
            --b[j];
        }
    std::cout << "f";
    for (int i = 0; i < k; ++i)
        std::cout << "'";
    std::cout << "(x)=";
    // Process the first section.
    if (a[0] == 0) {
        std::cout << 0;
    } else if (a[0] == -1 || a[0] == 1) {
        if (b[0] == 0)
            std::cout << a[0];
        else {
            std::cout << (a[0] == 1 ? "x" : "-x");
            if (b[0] > 1)
                std::cout << "^" << b[0];
        }
    } else {
        if (b[0] == 0)
            std::cout << a[0];
        else {
            std::cout << a[0] << "*x";
            if (b[0] > 1)
                std::cout << "^" << b[0];
        }
    }
    // Process the remain sections.
    for (int i = 1; i < n; ++i) {
        if (a[i] == 0)
            continue;
        if (a[i] == -1 || a[i] == 1) {
            if (b[i] == 0)
                std::cout << (a[i] == 1 ? "+1" : "-1");
            else {
                std::cout << (a[i] == 1 ? "+x" : "-x");
                if (b[i] > 1)
                    std::cout << "^" << b[i];
            }
        } else if (a[i] > 0) {
            if (b[i] == 0)
                std::cout << "+" << a[i];
            else {
                std::cout << "+" << a[i] << "*x";
                if (b[i] > 1)
                    std::cout << "^" << b[i];
            }
        } else {
            if (b[i] == 0)
                std::cout << a[i];
            else {
                std::cout << a[i] << "*x";
                if (b[i] > 1)
                    std::cout << "^" << b[i];
            }
        }
    }
    std::cout << std::endl;
    return 0;
}
