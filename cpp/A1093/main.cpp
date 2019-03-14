// Source : http://www.tsinsen.com/A1093
// Author : Modnar
// Date   : 2019-03-14

#include <iostream>

int main(int argc, char *argv[]) {
    int year;
    std::cin >> year;
    if (year % 400 == 0) {
        std::cout << "yes" << std::endl;
    } else if (year % 100 != 0 && year % 4 == 0) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    return 0;
}
