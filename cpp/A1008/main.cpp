// Source : http://www.tsinsen.com/A1008
// Author : Modnar
// Date   : 2019-01-17

#include <iostream>

int main() {
    int dig[10000];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> dig[i];
    }
    int max = dig[0], min = dig[0];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (max < dig[i]) max = dig[i];
        if (min > dig[i]) min = dig[i];
        sum += dig[i];
    }
    std::cout << max << std::endl << min << std::endl << sum << std::endl;
    return 0;
}
