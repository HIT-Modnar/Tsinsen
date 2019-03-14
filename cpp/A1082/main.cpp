#include <iostream>
#include <algorithm>

int findKth(int *s, int n, int K) {
//    std::sort(s, s+n);
    return *(s+K-1);
}

int main(int argc, char *argv[]) {
    int lst[10] = {3, 2, 4, 5, 1, 7, 8, 6, 9, 0};
    std::cout << findKth(lst, 10, 1) << std::endl;
    return 0;
}
