// Source : http://www.tsinsen.com/A1075
// Author : Modnar
// Date   : 2019-03-18

#include <iostream>
#include <string>
#include <map>

int main(int argc, char *argv[]) {
    // This is the C++11's new feature for std::map's initialization. 
    // If you submit to a compiler doesn't supprot C++11, the compiler will return 
    // ERROR. As for the solution, you can compile the program with g++ command 
    // under bash : $ g++ -std=c++11.
    // If you want to submit at tsinsen.com, please make sure you have select the 
    // "C++0x (MinGW g++ 4.7.2 -std=c++0x)".
    std::map<int, std::string> m = { {0, "zero"}, {1, "one"}, {2, "two"}, 
            {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, 
            {8, "eight"}, {9, "nine"}, {10, "ten"}, {11, "eleven"}, {12, "twelve"}, 
            {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, 
            {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"}, 
            {30, "thirty"}, {40, "forty"}, {50, "fifty"} };
    int hour, minute;
    std::cin >> hour >> minute;
    if (hour <= 20 || hour % 10  == 0) {
        std::cout << m[hour] << " ";
    } else {
        std::cout << m[hour-hour%10] << " " << m[hour%10] << " ";
    }
    if (minute == 0) {
        std::cout << " o'clock" << std::endl;
    } else if (minute <= 20 || minute % 10 == 0) {
        std::cout << m[minute] << std::endl;
    } else {
        std::cout << m[minute-minute%10] << " " << m[minute%10] << std::endl;
    }
    return 0;
}
