// Source : http://www.tsinsen.com/A1090
// Author : Modnar
// Date   : 2019-03-24

#include <iostream>

const int MAX_SIZE = 21;

int comb[MAX_SIZE][MAX_SIZE];

/**
 * Idea:
 *   From the describe of the problem we can see, if a sequence is a swing sequence, 
 *   the sequence's odd sub-sequence and its even sub-sequence must be ascent 
 *   (descent) or descent (ascent). Because of a1 is both in its odd-sub-sequence and 
 *   its even-sub-sequence, the a1 must be the sequence's middle value.
 *   Therefore, the sequence with n numbers only has to shape when it is a swing 
 *   sequence: one is its odd-sub-sequence ascent and one is its even-sub-sequence
 *   ascent. What we need to do is find how many sub-sequence the sequence has! And 
 *   this time we just need to compute the combination number of the sequence from
 *   2 to k. Accumulate the numbers and multiply the value with 2. This is the final
 *   answer.
 */
int main(int argc, char *argv[]) {
    int k;
    std::cin >> k;
    // Initialize the combination matrix.
    comb[1][0] = 1;
    comb[1][1] = 1;
    for (int i = 2; i < MAX_SIZE; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j < i; ++j) 
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        comb[i][i] = 1;
    }
    int ans = 0;
    for (int i = 2; i <= k; ++i)
        ans += comb[k][i];
    std::cout << ans * 2 << std::endl;
    return 0;
}
