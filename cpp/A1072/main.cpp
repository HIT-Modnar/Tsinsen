// Source : http://www.tsinsen.com/A1072
// Author : Modnar
// Date   : 2019-03-17

#include <iostream>
#include <string>
#include <set>

int main(int argc, char *argv[]) {
    std::string table(26, '#');
    std::string secret, message;
    std::cin >> secret >> message;
    int idx = 0;
    for (size_t i = 0; i < secret.size(); ++i) {
        idx = secret[i] - 'A';
        if (table[idx] == '#')
            table[idx] = message[i];
        else if (table[idx] != message[i]) {
            std::cout << "Failed" << std::endl;
            return 0;
        }
    }
    // Check whether there are some characters refer to a same character.
    std::set<char> check_set; 
    for (size_t i = 0; i < table.size(); ++i) {
        if (table[i] == '#') {
            std::cout << "Failed" << std::endl;
            return 0;
        }
        check_set.insert(table[i]);
    }
    // If the check_set's size is not equal to 26, means there are some characters 
    // be refered repeat.
    if (check_set.size() != 26) {
        std::cout << "Failed" << std::endl;
        return 0;
    }
    std::cin >> secret;
    for (size_t i = 0; i < secret.size(); ++i)
        std::cout << table[secret[i]-'A'];
    std::cout << std::endl;
    return 0;
} 
