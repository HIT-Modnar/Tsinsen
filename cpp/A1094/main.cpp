// Source : http://www.tsinsen.com/A1094
// Author : Modnar
// Date   : 2019-03-23

#include <iostream>
#include <cstdio>
#include <cmath>

double a, b, c, d, z;

double func(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

double der_func(double x) {
    return 3 * a * x * x + 2 * b * x + c;
}

int main(int argc, char *argv[]) {
    std::cin >> a >> b >> c >> d >> z;
    int cnt = 0;
    while (std::fabs(func(z)) > 1E-7) {
        z = z - func(z) / der_func(z);
        ++cnt;
    }
    printf("%.3f %d\n", z, cnt+1);
    return 0;
}
