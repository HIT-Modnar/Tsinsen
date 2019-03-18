// Source : http://www.tsinsen.com/1078
// Author : Modnar
// Date   : 2019-03-17

#include <iostream>

const int MAX_SIZE = 100;

int main(int argc, char *argv[]) {
    int lst[MAX_SIZE], n, ans = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> lst[i];
    // Idea: bubble sort's swap times is the reverse order 2-tuple's number.
    // And the select sort couldn't reach this target.
    for (int i = 0; i < n-1; ++i) 
        for (int j = 0; j < n-i-1; ++j)
            if (lst[j] > lst[j+1]) {
                std::swap(lst[j], lst[j+1]);
                ++ans;
            }
    std::cout << ans << std::endl;
    return 0;
}
