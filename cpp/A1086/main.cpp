// Source : http://www.tsinsen.com/A1086
// Author : Modnar
// Date   : 2019-03-22

#include <iostream>
#include <vector>
#include <algorithm>

bool get_max(int a, int b) {
    return a > b;
}

int main(int argc, char *argv[]) {
    int n, tmp;
    std::vector<int> ivec;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> tmp;
        ivec.push_back(tmp);
    }
    int ans = 0;
    while (ivec.size() > 1) {
        std::sort(ivec.begin(), ivec.end(), get_max);
        size_t len = ivec.size();
        ivec[len-2] += ivec[len-1];
        ans += ivec[len-2];
        ivec.pop_back();
    }
    std::cout << ans << std::endl;
    return 0;
}
