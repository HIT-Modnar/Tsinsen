// Source : http://www.tsinsen.com/1096
// Author : Modnar
// Date   : 2019-03-16

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
    std::vector<std::string> svec;
    std::string input;
    int substr_len;
    std::cin >> input >> substr_len;
    int n = input.size()-substr_len+1;
    for (int i = 0; i < n; ++i)
        svec.push_back(input.substr(i, substr_len));
    std::sort(svec.begin(), svec.end());
    for (int i = 0; i < n; ++i)
        std::cout << svec[i] << " ";
    std::cout << std::endl;
    return 0;
}
