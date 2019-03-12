// Source : http://www.tsinsen.com/A1019
// Author : Modnar
// Date   : 2019-01-18

#include <iostream>

int main() {
    char a = 'A', b = 'A', c = 'A', d = 'A';
    for (a = 'A'; a <= 'D'; a++) 
        for (b = 'A'; b <= 'D'; b++) 
            for (c = 'A'; c <= 'D'; c++) 
                for (d = 'A'; d <= 'D'; d++)
                    std::cout << a << b << c << d << std::endl;
    return 0;
}
