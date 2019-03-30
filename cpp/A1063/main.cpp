// Source : http://www.tsinsen.com/A1063
// Author : Modnar
// Date   : 2019-03-30

#include <iostream>

const int MAX_SIZE = 102;

int a[MAX_SIZE], n, x, ans = 0; 

int main(int argc, char *argv[]) {
    std::cin >> n >> x;
    for (int i = 0; i <= n; ++i) {
        std::cin >> a[i];
        a[i] = a[i] % 9999;
    }
    for (int i = 0; i <= n; ++i) {
        a[i] *= i;
        a[i] %= 9999;
        for (int j = 1; j < i; ++j) {
            // Add 9999 is in order to prevent the impact of the negative on the 
            // modulo operation.
            //
            // Here also could use DP (store the result of multi)to make it quicker.
            a[i] = (a[i] * x) % 9999 + 9999;
        }
    }
    for (int i = 0; i <= n; ++i) 
        ans += a[i];
    std::cout << (ans % 9999) << std::endl;
    return 0;
}
