// Source : http://www.tsinsen.com/A1028
// Author : Modnar
// Date   : 2019-01-21

#include <iostream>

int GCD(int a, int b) {
    int tmp = a % b;
    while (tmp) {
        tmp = a % b;
        if (tmp) {
            a = b;
            b = tmp;
        }
    }
    return b;
}

int main() {
    int x = 0, y = 0, z = 0;
    std::cin >> x >> y >> z;
    int ans = 0;
    switch (z) {
        case 1:
            ans = x + y;
            break;
        case 2:
            ans = x - y;
            break;
        case 3:
            ans = x * y;
            break;
        case 4:
            ans = x / y;
            break;
        case 5:
            ans = x % y;
            break;
        case 6:
            ans = GCD(x, y);
            break;
        case 7:
            ans = x * y / GCD(x, y);
            break;
    }
    std::cout << ans << std::endl;
    return 0;
}
