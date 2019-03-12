// Source : http://www.tsinsen.com/A1004
// Author : Modnar
// Date   : 2019-01-17

#include <iostream>

int main() {
    int width = 0, height = 0;
    std::cin >> height >> width;
    char ch[26];
    for(int i = 0; i < 26; i++) {
        ch[i] = 'A' + i;
    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j >= i) 
                std::cout << ch[j-i];
            else
                std::cout << ch[i-j];
        }
        std::cout << std::endl;
    }
    return 0;
}
