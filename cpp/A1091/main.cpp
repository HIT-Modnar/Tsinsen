// Source : http://www.tsinsen.com/A1091
// Author : Modnar
// Date   : 2019-03-17

#include <iostream>
#include <cstdio>

int range[12];
int depth, N;

void func(int start, int m) {
    if (start < 0 || start > N+1)
        return;
    if (m == depth) {
        for (int i = 0; i < depth; ++i) {
            std::cout << range[i] << " ";
        }
        std::cout << std::endl;
        return; 
    }
    for (int i = start; i <= N; ++i) {
        range[m] = i;
        func(i+1, m+1);
    } 
}

int main(int argc, char *argv[]) {
    std::cin >> N >> depth;
    func(1, 0); 
    return 0;
}
