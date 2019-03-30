// Source : http://www.tsinsen.com/A1098
// Author : Modnar
// Date   : 2019-03-30

#include <iostream>
#include <cstdio>

const int MAX_NUM = 16;

// The idea from http://www.tsinsen.com/Forum/view.page?topicid=5189
// Thanks the friend here.
int main(int argc, char *argv[]) {
    int n, m, num[MAX_NUM];
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
        num[i] = 1;
    int j = n - 1, t, y;
    if (m == 1) {
        while (1) {
            std::cout << n << "=" << num[0];
            for (int i = 1; i <= j; ++i)
                std::cout << "+" << num[i];
            std::cout << std::endl;
            if (!j) 
                break;
            t = num[j]; ++num[--j];
            while (--t)
                num[++j] = 1;
        }
    } else {
        while (1) {
            std::cout << n << "=" << num[0];
            for (int i = 1; i <= j; ++i)
                std::cout << "+" << num[i];
            std::cout << std::endl;
            if (!j)
                break;
            t = num[j]-1; y = ++num[--j];
            while (t >= y) {
                num[++j] = y;
                t -= y;
            }
            num[j] += t;
        }

    }
    return 0;
}
