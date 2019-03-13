// Source : http://www.tsinsen.com/A1061
// Author : Modnar
// Date   : 2019-03-13

#include <iostream>

int main(int argc, char *argv[]) {
    int data;
    std::cin >> data;
    int ans = 0, i;
    for (i = 1; i * i < data; ++i)
        if (data % i == 0)
            ans += 2;
    if (i * i == data)
        ++ans;
    std::cout << ans << std::endl;
    return 0;
}
