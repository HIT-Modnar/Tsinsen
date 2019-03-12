// Source : http://www.tsinsen.com/A1032
// Author : Modnar
// Date   : 2019-01-21

#include <iostream>

int main() {
    char ch = 'A';
    char charList[26];
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < 26; i++)
        charList[i] = ch + i;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >=0; j--) 
            std::cout << charList[j];
        for (int j = 1; j <= i; j++)
            std::cout << charList[j];
        std::cout << std::endl;
    }
    return 0;
}
