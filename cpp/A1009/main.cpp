// Source : http://www.tsinsen.com/A1009
// Author : Modnar
// Date   : 2019-01-17

#include <iostream>
#include <stdlib.h>
#include <time.h>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(int list[], int m, int n) {
    if (m < n) {
        int i = m+1, j = n;
        int mid = (m + n) / 2;
        int key = list[mid];
        swap(list[mid], list[m]);
        while(i <= j) {
            while(i <= n && list[i] <= key) i++;
            while(j >= m && list[j] > key) j--;
            if (i < j) {
                swap(list[i], list[j]);
            }
        }
        swap(list[j], list[m]);
        quicksort(list, m, j-1);
        quicksort(list, j+1, n);
    }
}

int main() {
    int dig[100];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> dig[i];
    }
    int sum = 0;
    quicksort(dig, 0, n-1);
    for (int i = 0; i < n; i++) {
        sum += dig[i] * dig[i];
    }
    
    std::cout << dig[n-2] << std::endl << dig[1] << std::endl << sum << std::endl;
    return 0;
}

