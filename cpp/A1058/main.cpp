// Source : http://www.tsinsen.com/A1058
// Author : Modnar
// Date   : 2019-03-12

/***********************************************************
 * Idea: 
 *     The key is "the normal chip's quentity is more than 
 *   the bad chip's". As for the input matrix, the No.i 
 *   col means the other chip test the No.i chip's result. 
 *   Because there are more normal chips than bad, we can 
 *   calculate each col's sum value. If the value of one 
 *   chip is bigger than half of total chip's number, we 
 *   can make sure the chip is a noraml one. Otherwise, it 
 *   must be a bad one.
 * 
 **********************************************************/

#include <iostream>
#include <vector>

const int N = 20;

int main(int argc, char *argv[]) {
    std::vector<int> ans;
    int arr[N][N], n;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            std::cin >> arr[i][j];
    for (size_t i = 0; i < n; ++i) {
        int sum = 0;
        for (size_t j = 0; j < n; ++j)
            sum += arr[j][i];
        // The judgement is the key.
        if (sum-1 >= n/2) 
            ans.push_back(i+1);
    }
    for (size_t i = 0; i < ans.size(); ++i)
        std::cout << ans[i] << " ";
    std::cout << std::endl;
    return 0;
}
