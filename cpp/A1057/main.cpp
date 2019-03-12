// Source : http://www.tsinsen.com/A1057
// Author : Modnar
// Date   : 2019-03-12

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[]) {
    std::string line("A");
    int n;
    std::cin >> n;
    for (size_t i = 1; i < n; ++i) {
        char ch = 'A' + i;
        line = line + ch + line;
    }
    std::cout << line << std::endl;
    return 0;
}
