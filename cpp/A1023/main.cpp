// Source : http://www.tsinsen.com/A1023
// Author : Modnar
// Date   : 2019-01-20

#include <iostream>

int main() {
    int ans[11];
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 2; i < 11; i++) 
        ans[i] = ans[i-1] + ans[i-2];
    int n = 0;
    std::cin >> n;
    std::cout << ans[n] << std::endl;
    return 0;
}

