// Source : http://www.tsinsen.com/A1016
// Author : Modnar
// Date   : 2019-01-18

#include <iostream>

const double PI = 3.1415926;

int main() {
    double x = 0.0, y = 0.0;
    int n = 0;
    std::cin >> n;
    while (n--) {
        std::cin >> x >> y;
        double area = PI * (x * x + y * y) / 2;
        int year = (int)(area/50.0);
        if (year * 50 <= area) {
            year++;
        }
        std::cout << year << std::endl;
    }
    return 0;
}
