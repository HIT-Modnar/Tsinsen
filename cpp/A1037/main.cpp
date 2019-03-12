// Source : http://www.tsinsen.com/A1037
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>

int main() {
    int h;
    int ans[30];
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    std::cin >> h;
    if (h > 20) {
        std::cout << "0" << std::endl;
        return 0;
    }
    for (int i = 4; i <= h; i++)
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    std::cout << ans[h] << std::endl;
    return 0;
}
