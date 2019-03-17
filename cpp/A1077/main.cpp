// Source : http://www.tsinsen.com/1077
// Author : Modnar
// Date   : 2019-03-17

#include <iostream>

using namespace std;

struct position {
    int x;
    int y;
};

void psort(position ps[], int n) {
    // If you just want to submit at tsinsen.com, copy the code in the function body.
    for (int i = 0; i < n-1; ++i) {
        int k = i;
        for (int j = i+1; j < n; ++j) {
            if (ps[j].x < ps[k].x || (ps[j].x == ps[k].x && ps[j].y < ps[k].y)) 
                k = j;
        }
        if (k != i)
            std::swap(ps[k], ps[i]);
    }
}

const int maxn = 100;
position points[maxn];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;
    psort(points, n);
    for (int i = 0; i < n; ++i)
        cout << points[i].x << " " << points[i].y << endl;
    return 0;
}

