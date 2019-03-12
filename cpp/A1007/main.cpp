// Source : http://www.tsinsen.com/A1007
// Author : Modnar
// Date   : 2019-01-17

#include <iostream>

int main() {
    int fiveBits[1000];
    int sixBits[1000];
    int fiveIndex = 0, sixIndex = 0;
    for(int i = 100; i <= 999; i++) {
         fiveBits[fiveIndex++] = i * 100 + (i / 10 % 10) * 10 + i / 100;
         sixBits[sixIndex++] = i * 1000 + (i % 10) * 100 + (i / 10 % 10) * 10 + i / 100;
    }
    int n = 0;
    std::cin >> n;
    int tempN = n;
    for (int i = 0; i < fiveIndex; i++) {
        tempN = n - fiveBits[i] / 100 % 10;
        if(tempN % 2 == 1) 
            continue;
        tempN = tempN / 2;
        if(tempN == fiveBits[i] / 10 % 10 + fiveBits[i] % 10)
            std::cout << fiveBits[i] << std::endl;
    }
    if (n % 2 == 0) {
        tempN = n / 2;
        for (int i = 0; i < sixIndex; i++) {
            if (sixBits[i] / 100 % 10 + sixBits[i] / 10 % 10 + sixBits[i] % 10 == tempN) 
                std::cout << sixBits[i] << std::endl;
        }
    }
    return 0;
}
