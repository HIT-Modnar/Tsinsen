// Source : http://www.tsinsen.com/A1022
// Author : Modnar
// Date   : 2019-01-20

#include <iostream>

int main() {
    int t = 0;
    int hour = 0, min = 0, sec = 0;
    std::cin >> t;
    hour = t / 3600;
    min = (t - hour * 3600) / 60;
    sec = t % 60;
    std::cout << hour << ':' << min << ':' << sec << std::endl;
    return 0;
}
