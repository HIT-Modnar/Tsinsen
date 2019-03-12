// Source : http://www.tsinsen.com/A1013
// Author : Modnar
// Date   : 2019-01-17

#include <iostream>
#include <cstring>

int main() {
    char numberStr[9];
    unsigned int ans = 0;
    std::cin >> numberStr;
    int len = strlen(numberStr);
    int pow = 1;
    while(len--) {
        if (numberStr[len] <= '9') {
            ans += pow * (numberStr[len] - '0');
        } else {
            ans += pow * (numberStr[len] - 'A' + 10);
        }
        pow *= 16;
    }
    std::cout << ans << std::endl;
    return 0;
}
