// Source : http://www.tsinsen.com/A1046
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>
#include <string.h>

int getValue(char op, int val) {
    if (op == '+') 
        return val;
    else 
        return -val;
}

int main() {
    char expression[101];
    std::cin >> expression;
    int len = strlen(expression);
    int sum = 0, reg = 0;
    char op = '+';
    for (int i = 0; i < len; i++) {
        if (expression[i] == '+') {
            sum += getValue(op, reg);
            reg = 0;
            op = '+';
        } else if (expression[i] == '-') {
            sum += getValue(op, reg);
            reg = 0;
            op = '-';
        } else if (expression[i] == '=') {
            sum += getValue(op, reg);
            break;
        } else {
            reg *= 10;
            reg += expression[i] - '0';
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
