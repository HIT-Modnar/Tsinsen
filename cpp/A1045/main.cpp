// Source : http://www.tsinsen.com/A1045
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>

void swapInt(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int t, m, n;
    std::cin >> t;
    int lst[10000];
    for (int i = 0; i < t; i++) {
        std::cin >> n >> m;
        for (int i = 0; i < n; i++)
            std::cin >> lst[i];
        for (int i = 0; i < m; i++) {
            int index1, index2;
            std::cin >> index1 >> index2;
            swapInt(lst[index1-1], lst[index2-1]);
        }
        for (int i = 0; i < n; i++)
            std::cout << lst[i] << std::endl;
    }
    return 0;
}

