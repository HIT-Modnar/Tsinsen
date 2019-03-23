// Source : http://www.tsinsen.com/A1083
// Author : Modnar
// Date   : 2019-03-23

#include <iostream>
#include <cmath>

const int MAX_SIZE = 10;

double matrix[MAX_SIZE][MAX_SIZE], vec_x[MAX_SIZE], vec_b[MAX_SIZE];

/** 
 * The solution only get score of 80 at tsinsen.com currently.
 * The program failed at the second test point.
 */
int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    if (n == 0)
        return 0;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            std::cin >> matrix[i][j];
    for (size_t i = 0; i < n; ++i)
        std::cin >> vec_b[i];
    for (size_t i = 0; i < n-1; ++i) {
        // If some line's matrix[i][i] is zero, swap the line with other line make 
        // it not equal to zero.
        if (matrix[i][i] == 0) 
            for (size_t j = i+1; j < n; ++j) {
                if (matrix[j][i] != 0) {
                    for (size_t k = i; k < n; ++k) {
                        std::swap(matrix[i][k], matrix[j][k]);
                    }
                    break;
                }
            }
        for (size_t j = i+1; j < n; ++j) {
            double val = -matrix[j][i] / matrix[i][i];
            for (size_t k = i; k < n; ++k) {
                matrix[j][k] += val * matrix[i][k];
            }
            vec_b[j] += val * vec_b[i];
        }
    }
    for (int i = n-1; i >= 0; --i) {
        double tmp = vec_b[i];
        for (int j = n-1; j > i; --j)
            tmp -= matrix[i][j] * vec_x[j];
        vec_x[i] = tmp / matrix[i][i];
    }
//    std::cout << "A:" << std::endl;
//    for (size_t i = 0; i < n; ++i) {
//        for (size_t j = 0; j < n; ++j)
//            std::cout << matrix[i][j] << " ";
//        std::cout << std::endl;
//    }
//    std::cout << "B:" << std::endl;
//    for (size_t i = 0; i < n; ++i)
//        std::cout << vec_b[i] << std::endl;
//    std::cout << std::endl << "Ans:" << std::endl;
    for (size_t i = 0; i < n; ++i)
        printf("%.2f\n", vec_x[i]);
//        std::cout << vec_x[i] << std::endl;
    return 0;
}
