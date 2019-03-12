// Source : http://www.tsinsen.com/A1033
// Author : Modnar
// Date   : 2019-01-21

#include <iostream>

int main() {
    int total = 1;
    int flag1, flag2, flag3, flag4;
    int n;
    int ans[30][30];
    std::cin >> n;
    flag1 = 0;
    flag2 = n;
    flag3 = n;
    flag4 = 0;
    for (int base = 0; base < (n+1)/2; base++) {
        int i = base, j = base;
        for (; j < n-base; j++)
            ans[i][j] = total++;
        j--;
        i++;
        for (; i < n-base; i++)
            ans[i][j] = total++;
        i--;
        j--;
        for (; j >= base; j--)
            ans[i][j] = total++;
        j++;
        i--;
        for (; i >= base+1; i--)
            ans[i][j] = total++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << ans[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}

