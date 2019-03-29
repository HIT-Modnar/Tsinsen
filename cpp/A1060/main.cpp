// Source : http://www.tsinsen.com/A1060
// Author : Modnar
// Date   : 2019-03-12

#include <iostream>
#include <cmath>
#include <cstring>

const int MAX_TIMES = 13;
const int MAX_SCORE = 125;
const int MAX_NUM = 4;

// The idea from http://www.tsinsen.com/Forum/view.page?topicid=2339
// Thanks the friend here.
int main(int argc, char *argv[]) {
    double aw[MAX_NUM], bw[MAX_NUM], a[MAX_TIMES][MAX_SCORE], b[MAX_TIMES][MAX_SCORE];
    const int vw[MAX_NUM] = {7, 8, 9, 10};
    int q[3];
    for (int i = 0; i < MAX_NUM; ++i)
        std::cin >> aw[i];
    for (int i = 0; i < MAX_NUM; ++i)
        std::cin >> bw[i];
    for (int i = 0; i < 3; ++i)
        std::cin >> q[i];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    a[0][0] = b[0][0] = 1;
    for (int i = 1; i <= 12; ++i)
        for (int j = 0; j <= 120; ++j)
            for (int w = 0; w < 4; ++w)
                if (j >= vw[w]) {
                    a[i][j] += a[i-1][j-vw[w]] * aw[w];
                    b[i][j] += b[i-1][j-vw[w]] * bw[w];
                }
    for (int i = 0; i < 3; ++i) {
        double p = 0.0;
        for (int j = 0; j <= 120; ++j)
            if ((j-q[i] >= 0) && (j-q[i] <= 120))
                p += a[12][j] * b[12][j-q[i]];
        std::cout << floor(100 * p + 0.5) << "%" << std::endl;
    }
    return 0;
}
