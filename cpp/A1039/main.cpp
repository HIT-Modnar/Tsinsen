// Source : http://www.tsinsen.com/A1039
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>

void swapInt(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(int lst[], int m, int n) {
    if (m < n) {
        int k = (m + n) / 2;
        int key = lst[k];
        int i = m + 1, j = n;
        swapInt(lst[m], lst[k]);
        while (i <= j) {
            while (i <= n && lst[i] <= key) i++;
            while (j >= m && lst[j] > key) j--;
            if (i < j)
                swapInt(lst[i], lst[j]);
        }
        swapInt(lst[m], lst[j]);
        quicksort(lst, m, j-1);
        quicksort(lst, j+1, n);
    }
}

int main() {
    int lst[1000];
    int n, prevInt, currentInt;
    std::cin >> n;
    std::cin >> prevInt;
    for (int i = 0; i < n-1; i++) {
        std::cin >> currentInt;
        if (currentInt >= prevInt)
            lst[i] = currentInt - prevInt;
        else
            lst[i] = prevInt - currentInt;
        prevInt = currentInt;
    }
    quicksort(lst, 0, n-2);
    int isHappy = 1;
    for (int i = 0; i < n-1; i++) 
        if (lst[i] != i+1) {
            isHappy = 0;
            break;
        }
    if (isHappy) 
        std::cout << "I'm happy!!" << std::endl;
    else
        std::cout << "I'm unhappy!!" << std::endl;
    return 0;
}
