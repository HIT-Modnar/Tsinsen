// Source : http://www.tsinsen.com/A1060
// Author : Modnar
// Date   : 2019-03-12

#include <iostream>
#include <cmath>

const int N = 37;
const int M = 4;

int fact[13], comb[13][13];

// Distribution of A and B, probility of A and B.
double disA[N], disB[N], probA[M], probB[M];

// TODO
int main(int argc, char *argv[]) {
    fact[0] = 1;
    for (size_t i = 1; i <= 12; ++i)
        fact[i] = fact[i-1] * i;
    for (size_t i = 1; i <= 12; ++i) 
        for (size_t j = 0; j <= i; ++j)
            comb[i][j] = fact[i] / (fact[i-j] * fact[j]);
    for (size_t i = 0; i < 4; ++i)
        std::cin >> probA[i];
    for (size_t i = 0; i < 4; ++i)
        std::cin >> probB[i];
    int total = 12;
    double val1, val2, val3, val4;
    for (int k1 = 0; k1 <= total; ++k1) {
        if (k1 == 0) val1 = 1.0;
        else if (probA[0] == 0.0) break;
        else val1 = comb[total][k1]*std::pow(probA[0], k1);
        for (int k2 = 0; k2 <= total-k1; ++k2) {
            if (k2 == 0) val2 = 1.0;
            else if (probA[1] == 0.0) break;
            else val2 = comb[total-k1][k2]*std::pow(probA[0], k2);
            for (int k3 = 0; k3 <= total-k1-k2; ++k3) {
                if (k3 == 0) val3 = 1.0;
                else if (probA[2] == 0.0) break;
                else val3 = comb[total-k1-k2][k3]*std::pow(probA[2], k3);
                int k4 = total-k1-k2-k3;
                if (k4 == 0) val4 = 1.0;
                else if (probA[3] == 0.0) continue;
                else val4 = std::pow(probA[3], k4);
                disA[k2+k3*2+k4*3] = val1*val2*val3*val4;
            }
        }
    }
    for (int k1 = 0; k1 <= total; ++k1) {
        if (k1 == 0) val1 = 1.0;
        else if (probB[0] == 0.0) break;
        else val1 = comb[total][k1]*std::pow(probB[0], k1);
        for (int k2 = 0; k2 <= total-k1; ++k2) {
            if (k2 == 0) val2 = 1.0;
            else if (probB[1] == 0.0) break;
            else val2 = comb[total-k1][k2]*std::pow(probB[0], k2);
            for (int k3 = 0; k3 <= total-k1-k2; ++k3) {
                if (k3 == 0) val3 = 1.0;
                else if (probB[2] == 0.0) break;
                else val3 = comb[total-k1-k2][k3]*std::pow(probB[2], k3);
                int k4 = total-k1-k2-k3;
                if (k4 == 0) val4 = 1.0;
                else if (probB[3] == 0.0) continue;
                else val4 = std::pow(probB[3], k4);
                disB[k2+k3*2+k4*3] = val1*val2*val3*val4;
            }
        }
    }
    int q1, q2, q3;
    double ans1 = 0.0, ans2 = 0.0, ans3 = 0.0;
    std::cin >> q1 >> q2 >> q3;
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j) {
            if (j + q1 == i)
                ans1 += disA[i] * disB[j];
            if (j + q2 == i)
                ans2 += disA[i] * disB[j];
            if (j + q3 == i)
                ans3 += disA[i] * disB[j];
        }
    std::cout << (int)(ans1*100+0.5) << "%" << std::endl
              << (int)(ans2*100+0.5) << "%" << std::endl
              << (int)(ans3*100+0.5) << "%" << std::endl;
    return 0;
}
