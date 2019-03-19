// Source : http://www.tsinsen.com/1078
// Author : Modnar
// Date   : 2019-03-17

#include <iostream>

const int MAX_SIZE = 100;

int ans_of_merge = 0;

// Another solution is the merge. In the merge sort's merge process, 
// the swap times is the key to compute reverse-tuple.
void merge(int lst[], int m, int n) {
    static int tmp[MAX_SIZE];
    int mid = (m + n) / 2, i = m, j = mid + 1, k = m;
    while (i <= mid && j <= n) {
        if (lst[i] > lst[j]) {
            tmp[k++] = lst[j++];
            // This is the key to compute the answer.
            ans_of_merge += mid - i + 1;
        } else {
            tmp[k++] = lst[i++];
        }
    }
    while (i <= mid) tmp[k++] = lst[i++];
    while (j <= n) tmp[k++] = lst[j++];
    for (int idx = m; idx <= n; ++idx)
        lst[idx] = tmp[idx];
}

void merge_sort(int lst[], int m, int n) {
    if (m < n) {
        int mid = (m + n) / 2;
        merge_sort(lst, m, mid);
        merge_sort(lst, mid+1, n);
        merge(lst, m, n);
    }
}

int main(int argc, char *argv[]) {
    int lst[MAX_SIZE], n, ans = 0;
//    int lst_of_merge[MAX_SIZE];
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> lst[i];
 //       lst_of_merge[i] = lst[i];
    }
    // Idea: bubble sort's swap times is the reverse order 2-tuple's number.
    // And the select sort couldn't reach this target.
    for (int i = 0; i < n-1; ++i) 
        for (int j = 0; j < n-i-1; ++j)
            if (lst[j] > lst[j+1]) {
                std::swap(lst[j], lst[j+1]);
                ++ans;
            }
//    merge_sort(lst_of_merge, 0, n-1);
    std::cout << ans << std::endl;
//    std::cout << ans_of_merge << std::endl;
    return 0;
}
