// Source : http://www.tsinsen.com/A1035
// Author : Modnar
// Date   : 2019-01-21

#include <iostream>

int main() {
    int n, len = 0;
    int lst[1000000] = {0}, ans[1000];
    for (int i = 2; i <= 1000000; i++) {
        if (lst[i] == 0)
            ans[len++] = i;
        if (lst[i] == 1)
            continue;
        for (int j = i+i; j <= 1000000; j += i) {
            lst[j] = 1;
        }
    }
    std::cin >> n;
    while (true) {
        int sum = 0;
        if (n == 0) 
            break;
        for (int i = 0; ans[i] <= n; i++)
            sum += ans[i];
        std::cout << sum << std::endl;
        std::cin >> n;
    }
    return 0;
}

