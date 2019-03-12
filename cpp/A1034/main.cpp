// Source : http://www.tsinsen.com/A1034
// Author : Modnar
// Date   : 2019-01-21

#include <iostream>

int main() {
    int lst[1000000] = {0};
    int ans[1000];
    int len = 0;
    int a, b;
    for (int i = 2; i <= 1000000; i++) {
        if (lst[i] == 0)
            ans[len++] = i;
        if (lst[i] == 1) 
            continue;
        for (int j = i+i; j < 1000000; j += i) {
            lst[j] = 1;
        }
    }
    std::cin >> a >> b;
    int flag = 1;
    for (int i = 0; i < len; i++) {
        int ans1 = ans[i];
        int ans2 = ans[i+1];
        if (ans1 >= a && ans2 <= b && ans2 - ans1 == 2) {
            std::cout << ans1 << " " << ans2 << std::endl;
            flag = 0;
        }
    }
    if (flag)
        std::cout << "-1" << std::endl;
    return 0;
}
