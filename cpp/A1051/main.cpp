// Source : http://www.tsinsen.com/A1051
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>
#include <string.h>

int main() {
    char seq[10][101];
    char ans[101];
    int n;
    std::cin >> n;
    int countA = 0, countC = 0, countG = 0, countT = 0;
    for (int i = 0; i < n; i++)
        std::cin >> seq[i];
    int len = strlen(seq[0]);
    for (int j = 0; j < len; j++) {
        countA = 0; countC = 0; countG = 0; countT = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i][j] == 'A') { countA++; continue; }
            if (seq[i][j] == 'C') { countC++; continue; }
            if (seq[i][j] == 'G') { countG++; continue; }
            if (seq[i][j] == 'T') countT++;
        }
        int maxCount = countA; ans[j] = 'A';
        if (countC > maxCount) { ans[j] = 'C'; maxCount = countC; }
        if (countG > maxCount) { ans[j] = 'G'; maxCount = countG; }
        if (countT > maxCount) { ans[j] = 'T'; maxCount = countT; }
    }
    for (int i = 0; i < len; i++)
        std::cout << ans[i];
    std::cout << std::endl;
    return 0;
}

