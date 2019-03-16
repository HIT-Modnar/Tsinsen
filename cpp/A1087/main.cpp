// Source : http://www.tsinsen.com/1087
// Author : Modnar
// Date   : 2019-03-16

#include <iostream>
#include <string>
#include <vector>

const int NUM_LEN = 102;

int main(int argc, char *argv[]) {
    std::vector<int> num1, num2, ans;
    std::string num1_s, num2_s;
    std::cin >> num1_s >> num2_s;
    int len1 = num1_s.size(), len2 = num2_s.size();
    for (int i = len1-1; i >= 0; --i)
        num1.push_back(num1_s[i]-'0');
    for (int i = len2-1; i >= 0; --i)
        num2.push_back(num2_s[i]-'0');
    int carry = 0, idx = 0, add = 0;
    while (idx < len1 || idx < len2) {
        if (idx >= len1) 
            add = num2[idx] + carry;
        else if (idx >= len2) 
            add = num1[idx] + carry;
        else {
            add  = num1[idx] + num2[idx] + carry;
        }
        ans.push_back(add % 10);
        carry = add >= 10 ? 1 : 0;
        ++idx;
    }
    if (carry) { ans.push_back(1); ++idx; }
    for (--idx; idx >= 0; --idx)
        std::cout << ans[idx];
    std::cout << std::endl;
    return 0;
}
