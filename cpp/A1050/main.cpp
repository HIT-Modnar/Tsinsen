// Source : http://www.tsinsen.com/A1050
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>

int main() {
    char seq[1001];
    std::cin >> seq;
    int sum = 0, i;
    for (i = 0; seq[i] != '\0'; i++)
        if (seq[i] == 'G' || seq[i] == 'C')
            sum += 1;
    int ans = (int)(((double)sum / i + 0.005) * 100);
    std::cout << ans << std::endl;
    return 0;
}

