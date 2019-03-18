// Source : http://www.tsinsen.com/1076
// Author : Modnar
// Date   : 2019-03-18

#include <iostream>

using namespace std;

/**
 * 获取n的约数个数。
 * 约定n >= 1
 */
int getNumDivisor(int n) {
    // If you want to submit at tsinsen.com, just need to copy the code in the 
    // funciton body.
    int ans = 0;
    for (int i = 1; i <= n/2; ++i)
        if (n % i == 0)
            ++ans;
    return ++ans;
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    cout << getNumDivisor(n) << endl;
    return 0;
}
