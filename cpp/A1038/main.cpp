// Source : http://www.tsinsen.com/A1038
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    int len = str.length();
    int maxLen = 0;
    for (int i = 0; i < len; i++) {
        for (int j = maxLen; j < len + 1; j += 2) {
            if (i + j > len) 
                break;
            std::string sub1 = str.substr(i, j/2);
            std::string sub2 = str.substr(i+j/2, j/2);
            if (sub1 == sub2)
                maxLen = j;
        }
    }
    std::cout << maxLen << std::endl;
    return 0;
}
