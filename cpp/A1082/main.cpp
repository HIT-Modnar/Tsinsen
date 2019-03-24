// Source : http://www.tsinsen.com/A1082
// Author : Modnar
// Date   : 2019-03-24

#include <iostream>

/**
 * Idea:
 *   Just need to find the K-th minimum number, we can use the sort algorithm to 
 *   solve the problem.
 *   First of all, we can use the algorithm like bubblesort, every time travelsing 
 *   on the sequence using bubblesort, we can get one minimum element. So if we want 
 *   to get the K-th minimum element, we need to run K times this process. If the K 
 *   is equal to n, the algorithm's complexity will reach O(n^2). Truth to be told, 
 *   if you do like this, you can only get score of 20 at tsinsen.com.
 *   Therefore, we think about the algorithm like quicksort. Every time, we choose
 *   the K-th element as the key, and use the key to compare the other elements of 
 *   the sequence. If the element is less than key, make the element be at left of 
 *   key element. Else, make the element be at right of the key. After scanning the 
 *   sequence per time, we need to know how many elements is less than the key. If 
 *   the number of the less elements (as m) is less than K, we need to repeat the 
 *   process at the position m of the sequence and find the K-m-th minimum element.
 *   Else m is greater than K, we need to repeat the process at the position s and 
 *   find the K-th minimum element again, while this time, the length of the sequence
 *   is changed to m.
 */
int findKth(int *s, int n, int K) {
    // As for requestion of tsinsen.com, submit the code in the function body.
    int key = s[K-1], temp, i = 1, j = n-1;
    temp = s[K-1];
    s[K-1] = s[0];
    s[0] = temp;
    while (i <= j) {
        while (i < n && s[i] <= key) ++i;
        while (j >= 0 && s[j] > key) --j;
        if (i < j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
    temp = s[j];
    s[j] = s[0];
    s[0] = temp;
    if (j > K-1) {
        return findKth(s, j, K);
    } else if (j < K-1) {
        return findKth(s+j, n-j, K-j);
    } else {
        return key;
    }
}

int main(int argc, char *argv[]) {
    int lst[10] = {3, 2, 4, 5, 1, 7, 8, 6, 9, 0};
    std::cout << findKth(lst, 10, 1) << std::endl;
    std::cout << findKth(lst, 10, 2) << std::endl;
    std::cout << findKth(lst, 10, 3) << std::endl;
    std::cout << findKth(lst, 10, 4) << std::endl;
    std::cout << findKth(lst, 10, 5) << std::endl;
    std::cout << findKth(lst, 10, 6) << std::endl;
    std::cout << findKth(lst, 10, 7) << std::endl;
    std::cout << findKth(lst, 10, 8) << std::endl;
    std::cout << findKth(lst, 10, 9) << std::endl;
    std::cout << findKth(lst, 10, 10) << std::endl;
    return 0;
}
