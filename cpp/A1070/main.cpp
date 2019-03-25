// Source : http://www.tsinsen.com/A1070
// Author : Modnar
// Date   : 2019-03-25

#include <iostream>
#include <cmath>

const int MAX_SIZE = 102;

int k, n;
int a[MAX_SIZE], b[MAX_SIZE];

int main(int argc, char *argv[]) {
    std::cin >> k >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i] >> b[i];
    std::cout << "f";
    for (int i = 0; i < k; ++i)
        std::cout << "'";
    std::cout << "(x)=";
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j] *= b[j];
            --b[j];
        }
    }
    if (n == 1) {
        if (a[0] == 0)
            std::cout << 0;
        if (b[0] == 0)
            std::cout << a[0];
        else if (b[0] == 1) {
            if (a[0] == 1)
                std::cout << "x";
            else if (a[0] == -1)
                std::cout << "-x";
            else
                std::cout << a[0] << "*x";
        } else {
            if (a[0] == 1)
                std::cout << "x^" << b[0];
            else if (a[0] == -1)
                std::cout << "-x^" << b[0];
            else
                std::cout << a[0] << "*x^" << b[0];
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0)
                continue;
            else if (a[i] > 0) { 
                if (i != 0)
                    std::cout << "+";
                if (a[i] != 1)
                    std::cout << a[i];
            } else {
                if (a[i] == -1)
                    std::cout << "-";
                else 
                    std::cout << a[i];
            }
            if (std::fabs(a[i]) != 1 && b[i] != 0)
                std::cout << "*";
            if (b[i] == 1)
                std::cout << "x";
            else if (b[i] == 0)
                continue;
            else 
                std::cout << "x^" << b[i];
        }
    }
    std::cout << std::endl;
    return 0;
}
