// Source : http://www.tsinsen.com/A1042
// Author : Modnar
// Date   : 2019-01-22

#include <iostream>

typedef struct point {
    double x;
    double y;
} Point;

double getMin(double a, double b) {
    return a < b ? a : b;
}

double getMax(double a, double b) {
    return a > b ? a : b;
}

void swapDouble(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void format(Point &p1, Point &p2) {
    if ((p1.x-p2.x) * (p1.y-p2.y) < 0) {
        double temp1 = p1.x, temp2 = p2.x;
        p1.x = getMin(temp1, temp2);
        p2.x = getMax(temp1, temp2);
        temp1 = p1.y, temp2 = p2.y;
        p1.y = getMin(temp1, temp2);
        p2.y = getMax(temp1, temp2);
    } else if (p1.x > p2.x) {
        Point temp = p1;
        p1 = p2;
        p2 = temp;
    }
}

void quicksort(double lst[], int m, int n) {
    if (m < n) {
        int k = (m + n) / 2;
        double key = lst[k];
        int i = m + 1, j = n;
        swapDouble(lst[m], lst[k]);
        while (i <= j) {
            while (i <= n && lst[i] <= key) i++;
            while (j >= m && lst[j] > key) j--;
            if (i < j) 
                swapDouble(lst[i], lst[j]);
        }
        swapDouble(lst[m], lst[j]);
        quicksort(lst, m, j-1);
        quicksort(lst, j+1, n);
    }
}

int main() {
    Point p1, p2, q1, q2;
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> q1.x >> q1.y >> q2.x >> q2.y;
    double ans = 0.0;
    format(p1, p2);
    format(q1, q2);
    if (p1.x > q2.x || p2.x < q1.x || p1.y > q2.y || p2.y < q1.y)
        std::cout << "0.00" << std::endl;
    else {
        double X[4] = {p1.x, p2.x, q1.x, q2.x};
        double Y[4] = {p1.y, p2.y, q1.y, q2.y};
        quicksort(X, 0, 3);
        quicksort(Y, 0, 3);
        ans = (X[2] - X[1]) * (Y[2] - Y[1]);
        printf("%.2f\n", ans);
    }
    return 0;
}
