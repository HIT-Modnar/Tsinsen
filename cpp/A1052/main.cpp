// Source : http://www.tsinsen.com/A1052
// Author : Modnar
// Date   : 2019-03-29

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> num = {"ling", "yi", "er", "san", "si", "wu", 
                                "liu", "qi", "ba", "jiu", "shi"};

int digit[10];

void init(int n) {
    int i = 0;
    while (n != 0) {
        digit[i++] = n % 10;
        n = n / 10;
    }
}

void process() {
    // Process the billion bit.
    if (digit[9] > 1)
        std::cout << num[digit[9]] << " ";
    if (digit[9])
        std::cout << "shi ";

    // Process the hundred million bit.
    if (digit[8])
        std::cout << num[digit[8]] << " ";
    if (digit[9] || digit[8])
        std::cout << "yi ";

    // Process the 10 million bit.
    if (digit[7])
        std::cout << num[digit[7]] << " qian ";
    else if ((digit[9] || digit[8]) && (digit[6] || digit[5] || digit[4] || digit[3]
            || digit[2] || digit[1] || digit[0]))
        std::cout << "ling ";

    // Process the million bit.
    if (digit[6])
        std::cout << num[digit[6]] << " bai ";
    else if (digit[7] && (digit[5] || digit[4]))
        std::cout << " ling ";

    // Process the hundred thousand bit.
    if (digit[5] > 1)
        std::cout << num[digit[5]] << " ";
    else if (digit[5] == 1 && (digit[9] || digit[8] || digit[7] || digit[6]))
        std::cout << "yi ";
    if (digit[5]) 
        std::cout << "shi ";
    else if (digit[6] && digit[4])
        std::cout << "ling ";

    // Process the 10 thousand bit.
    if (digit[4])
        std::cout << num[digit[4]] << " ";

    if (digit[7] || digit[6] || digit[5] || digit[4])
        std::cout << "wan ";

    // Process the thousand bit.
    if (digit[3])
        std::cout << num[digit[3]] << " qian ";
    else if ((digit[9] || digit[8] || digit[7] || digit[6] || digit[5] || digit[4]) 
             && (digit[2] || digit[1] || digit[0]))
        std::cout << "ling ";

    // Process the hundred bit.
    if (digit[2])
        std::cout << num[digit[2]] << " bai ";
    else if (digit[3] && (digit[1] || digit[0]))
        std::cout << "ling ";

    // Process the 10 bit.
    if (digit[1] > 1)
        std::cout << num[digit[1]] << " ";
    else if (digit[1] == 1 && (digit[9] || digit[8] || digit[7] || digit[6] || 
                               digit[5] || digit[4] || digit[3] || digit[2]))
        std::cout << "yi ";
    if (digit[1])
        std::cout << "shi ";
    else if (digit[2] && digit[0])
        std::cout << "ling ";

    // Process the single bit.
    if (digit[0])
        std::cout << num[digit[0]] << " ";

    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    init(n);
    process();
    return 0;
}
