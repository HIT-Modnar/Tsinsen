// Source : http://www.tsinsen.com/A1026
// Author : Modnar
// Date   : 2019-01-21

#include <iostream>

int main() {
    int ans[26] = {0};
    char inputStr[101];
    std::cin >> inputStr;
    for (int i = 0; inputStr[i] != '\0'; i++) {
        ans[inputStr[i]-'a'] += 1;
    }
    for (int i = 0; i < 26; i++) {
        if (ans[i] > 0) {
            char ch = 'a' + i;
            std::cout << ch << " " << ans[i] << std::endl;
        }
    }
    return 0;
}
