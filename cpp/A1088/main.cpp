// Source : http://www.tsinsen.com/1088
// Author : Modnar
// Date   : 2019-03-16

#include <iostream>

const int MAX_ARR_LEN = 30;

int main(int argc, char *argv[]) {
    int len, arr[MAX_ARR_LEN], ans = 0;
    std::cin >> len;
    for (int i = 0; i < len; ++i)
        std::cin >> arr[i];
    while (--len) {
        ans += arr[len];
        for (int i = 0; i < len; ++i)
            arr[i] = arr[i+1] - arr[i];
    }
    std::cout << ans + arr[0] << std::endl;
    return 0;
}
