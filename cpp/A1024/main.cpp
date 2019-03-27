// Source : http://www.tsinsen.com/A1024
// Author : Modnar
// Date   : 2019-03-26

#include <cstdio>

// Thanks the friend Jack from http://www.tsinsen.com/Forum/view.page?topicid=1915
// That's a so cool idea.
int main(int argc, char *argv[]) {
    int a[10][2] = {{1, 1}, {1, 0}, {3, 1}};
    // The first number represents the number of species, and the second number 
    // represents the number of species ending in 1.
    int b[10][3] = {{1, 1, 0}, {0, 0, 0}, {2, 1, 1}};
    // The first number represents the number of 1, the second number represents the 
    // number of 1s ending in 1, and the third number represents the number of 1s 
    // that do not end with 1.
    int i, n;
    for(i = 3; i < 10; ++i) {
        a[i][1] = a[i-1][0] - a[i-1][1];
        a[i][0] = a[i-3][0] + a[i-2][0] + a[i][1];
        b[i][2] = b[i-3][0] + b[i-2][0];
        b[i][1] = b[i-1][2] + a[i][1];
        b[i][0] = b[i][2] + b[i][1];
    }
    scanf("%d", &n);
    printf("%d\n%d\n", a[n-1][0], b[n-1][0]);
    return 0;
}
