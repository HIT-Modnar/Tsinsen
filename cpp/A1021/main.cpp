// Source : http://www.tsinsen.com/A1021
// Author : Modnar
// Date   : 2019-01-20

#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int min(int a, int b) {
    if (a < b) 
        return a;
    return b;
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

void compute(int lstA[], int lstB[], int lenA, int lenB, int ansA[], int ansB[], int &len1, int &len2) {
    int indexA = 0, indexB = 0;
    len1 = 0;
    len2 = 0;
    while (indexA < lenA && indexB < lenB) {
        if (lstA[indexA] == lstB[indexB]) {
            ansA[len1++] = lstA[indexA];
            ansB[len2++] = lstA[indexA];
            indexA++;
            indexB++;
        } else if (lstA[indexA] > lstB[indexB]) {
            ansB[len2++] = lstB[indexB++];
        } else {
            ansB[len2++] = lstA[indexA++];
        }
    }
    while (indexA < lenA) {
        ansB[len2++] = lstA[indexA++];
    }
    while (indexB < lenB) {
        ansB[len2++] = lstB[indexB++];
    }
}

void subset(int lstA[], int lstB[], int ansC[], int lenA, int lenB, int &len3) {
    int indexA = 0, indexB = 0;
    len3 = 0;
    while (indexA < lenA && indexB < lenB) {
        if (lstA[indexA] == lstB[indexB]) {
            indexA++;
            indexB++;
        } else {
            ansC[len3++] = lstB[indexB++];
        }
    }
    while (indexB < lenB) {
        ansC[len3++] = lstB[indexB++];
    }
}

int main() {
    int lenA = 0, lenB = 0;
    int A[1000], B[1000];
    int ansA[1000], ansB[1000], ansC[1000];
    std::cin >> lenA;
    for (int i = 0; i < lenA; i++) {
        std::cin >> A[i];
    }
    std::cin >> lenB;
    for (int i = 0; i < lenB; i++) {
        std::cin >> B[i];
    }
    quicksort(A, 0, lenA-1);
    quicksort(B, 0, lenB-1);
    int len1 = 0, len2 = 0, len3 = 0;
    compute(A, B, lenA, lenB, ansA, ansB, len1, len2);
    char ch = '\0';
    for (int i = 0; i < len1; i++) {
        ch = len1 - 1 == i ? '\n' : ' ';
        std::cout << ansA[i] << ch;
    }
    for (int i = 0; i < len2; i++) {
        ch = len2 - 1 == i ? '\n' : ' ';
        std::cout << ansB[i] << ch;
    }
    subset(ansA, A, ansC, len1, lenA, len3);
    for (int i = 0; i < len3; i++) {
        ch = len3 - 1 == i ? '\n' : ' ';
        std::cout << ansC[i] << ch;
    }
    return 0;
}
