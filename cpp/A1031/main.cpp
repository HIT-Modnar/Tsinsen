// Source : http://www.tsinsen.com/A1031
// Author : Modnar
// Date   : 2019-01-21

#include <iostream>

int main() {
    char ch = 'A';
    char charList[26];
    for (int i = 0; i < 26; i++)
        charList[i] = ch + i;
    for (int i = 0; i < 15; i++) {
        for (int j = i; j >=0; j--) 
            std::cout << charList[j];
        for (int j = 1; j <= i; j++)
            std::cout << charList[j];
        std::cout << std::endl;
    }
    return 0;
}
