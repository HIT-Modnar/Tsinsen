// Source : http://www.tsinsen.com/A1025
// Author : Modnar
// Date   : 2019-01-20

#include <iostream>
#include <string.h>

int absInt(int a) {
    if (a < 0) 
        return -a;
    return a;
}

int main() {
    char str1[10], str2[10];
    int len1, len2;
    std::cin >> str1 >> str2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    int offset = 'a' - 'A';
    if (len1 != len2) {
        std::cout << "1" << std::endl;
        return 0;
    }
    int flag = 2, i = 0;
    for (i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            flag = 3;
            break;
        }
    }
    for (; i < len1; i++) {
        if (absInt(str1[i] - str2[i]) != 0 && absInt(str1[i] - str2[i]) != offset) {
            flag = 4;
            break;
        }
    }
    std::cout << flag << std::endl;
    return 0;
}

