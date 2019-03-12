// Source : http://www.tsinsen.com/A1030
// Author : Modnar
// Date   : 2019-01-21

#include <iostream>
#include <string.h>

typedef struct team {
    char name[21];
    int score;
    int pure;
    int total;
} Team;

void sortByName(Team lst[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        Team temp = lst[i];
        for (j = i-1; j >=0 && strcmp(temp.name, lst[j].name) < 0; j--) 
            lst[j+1] = lst[j];
        lst[j+1] = temp;
    }
}

void sortByTotal(Team lst[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        Team temp = lst[i];
        for (j = i-1; j >= 0 && temp.total > lst[j].total; j--) 
            lst[j+1] = lst[j];
        lst[j+1] = temp;
    }
}

void sortByPure(Team lst[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        Team temp = lst[i];
        for (j = i-1; j >= 0 && temp.pure > lst[j].pure; j--)
            lst[j+1] = lst[j];
        lst[j+1] = temp;
    }
}

void sortByScore(Team lst[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        Team temp = lst[i];
        for (j = i-1; j >= 0 && temp.score > lst[j].score; j--)
            lst[j+1] = lst[j];
        lst[j+1] = temp;
    }
}

// void show(Team lst[], int n) {
//     for (int i = 0; i < n; i++) 
//         std::cout << lst[i].name << " " << lst[i].score << 
//             " " << lst[i].pure << " " << lst[i].total << std::endl;
// }

int main() {
    Team ans[10];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) 
        std::cin >> ans[i].name >> ans[i].score >> ans[i].pure >> ans[i].total;
    sortByName(ans, n);
    sortByTotal(ans, n);
    sortByPure(ans, n);
    sortByScore(ans, n);
//    show(ans, n);
    for (int i = 0; i < n; i++) 
        std::cout << ans[i].name << std::endl;
    return 0;
}
