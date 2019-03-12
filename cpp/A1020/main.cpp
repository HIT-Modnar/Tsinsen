// Source : http://www.tsinsen.com/A1020
// Author : Modnar
// Date   : 2019-01-18

#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(int list[], int m, int n) {
    if (m < n) {
        int k = (m + n) / 2;
        int key = list[k];
        int i = m + 1, j = n;
        swap(list[m], list[k]);
        while (i <= j) {
            while (i <= n && list[i] <= key) i++;
            while (j >= m && list[j] > key) j--;
            if (i < j) 
                swap(list[i], list[j]);
        }
        swap(list[m], list[j]);
        quicksort(list, m, j - 1);
        quicksort(list, j + 1, n);
    }
}

int main() {
    int n = 0;
    int lst[200];
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> lst[i];
    }
    quicksort(lst, 0, n -1);
    for (int i = 0; i < n; i++) {
        std::cout << lst[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

