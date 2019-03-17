// Source : http://www.tsinsen.com/1089
// Author : Modnar
// Date   : 2019-03-17

#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    int n, carry = 0;
    std::cin >> n;
    std::vector<int> ans(1, 1);
    for (size_t i = 1; i <= n; ++i) {
        carry = 0;
        for (size_t j = 0; j < ans.size(); ++j) {
            int tmpval = ans[j] * i;
            ans[j] = (tmpval + carry) % 10;
            carry = (tmpval + carry) / 10;
        }
        while (carry) {
            ans.push_back(carry%10);
            carry = carry / 10;
        }
    }
    for (int i = ans.size()-1; i > -1; --i)
        std::cout << ans[i];
    std::cout << std::endl;
    return 0;
}
