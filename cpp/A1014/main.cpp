// Source : http://www.tsinsen.com/A1014 
// Author : Modnar
// Date   : 2019-03-12

#include <iostream>
#include <string>
#include <iomanip>

int getVal(const std::string &str) {
    int val = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] >= '0' && str[i] <= '9')
            val = (val << 4) + (str[i] - '0');
        else 
            val = (val << 4) + (str[i] - 'A' + 10);
    }
    return val;
}

int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    while (n--) {
        std::string data;
        std::cin >> data;
        int len = data.size(), mod = len % 3, base = 0, val = -1;
        switch (mod) {
            case 0:
                base = 3;
                val = getVal(data.substr(0, 3));
                len -= 3;
                break;
            case 1:
                base = 1;
                val = getVal(data.substr(0, 1));
                len -= 1;
                break;
            case 2:
                base = 2;
                val = getVal(data.substr(0, 2));
                len -= 2;
                break;
        }
        if (val >= 0)
            std::cout << std::oct << val;
        while (len) {
            val = getVal(data.substr(base, 3));
            std::cout << std::setw(4) << std::setfill('0') << std::oct << val;
            base += 3;
            len -= 3;
        }
        std::cout << std::endl;
    }
    return 0;
}
