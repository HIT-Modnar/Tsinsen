// Source : http://www.tsinsen.com/A1092
// Author : Modnar
// Date   : 2019-03-14

#include <iostream>

int main(int argc, char *argv[]) {
    int data, ans[4], i = 0;
    std::cin >> data;
    while (data) {
        ans[i++] = data % 10;
        data /= 10;
    }
    for (i = 0; i < 4; ++i)
        ans[i] = (ans[i] + 5) % 10;
    i = 0;
    while (ans[i] == 0)
        ++i;
    for (; i < 4; ++i)
        std::cout << ans[i];
    std::cout << std::endl;
    return 0;
}
