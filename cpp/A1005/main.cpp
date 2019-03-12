// Source : http://www.tsinsen.com/A1005
// Author : Modnar
// Date   : 2019-01-17

#include <iostream>

int main() {
    for (int i = 100; i <= 999; i++) {
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100 % 10;
        if(i == a * a * a + b * b * b + c * c * c) 
            std::cout << i << std::endl;
    }
    return 0;
}
