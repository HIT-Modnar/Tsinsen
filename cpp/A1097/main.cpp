// Source : http://www.tsinsen.com/1097
// Author : Modnar
// Date   : 2019-03-16

#include <iostream>

const int MAX_LEN = 5000;

int min(int a, int b) { return a < b ? a : b; }

int max(int a, int b) { return a > b ? a : b; }

int main(int argc, char *argv[]) {
    int len, n, pos[MAX_LEN], ans_min, ans_max, val;
    std::cin >> len >> n;
    ++len;
    if (n == 0) {
        std::cout << "0 0" << std::endl;
        return 0;
    }
    for (int i = 0; i < n; ++i)
        std::cin >> pos[i];
    ans_min = min(len-pos[0], pos[0]);
    ans_max = max(len-pos[0], pos[0]);
    for (int i = 1; i < n; ++i) {
        val = min(len-pos[i], pos[i]);
        ans_min = val > ans_min ? val : ans_min;
        val = max(len-pos[i], pos[i]);
        ans_max = val > ans_max ? val : ans_max;
    }
    std::cout << ans_min << " " << ans_max << std::endl;
    return 0;
}
