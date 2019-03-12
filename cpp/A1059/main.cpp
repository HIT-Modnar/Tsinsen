// Source : http://www.tsinsen.com/A1059
// Author : Modnar
// Date   : 2019-03-12

#include <iostream>
#include <cstdio>

int main(int argc, char *argv[]) {
    int x, y, a, b, m;
    scanf("%d,%d,%d", &a, &b, &m);
    for (x = 1; x <= (m - b) / a; ++x)
        for (y = x; y <= (m - a) / b; ++y)
            if (a * x + b * y <= m)
                std::cout << x << "," << y << std::endl;
    return 0;
}
