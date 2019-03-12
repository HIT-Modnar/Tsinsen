// Source : http://www.tsinsen.com/A1029
// Author : Modnar
// Date   : 2019-01-21

#include <iostream>

using namespace std;

void maxmin_0(int a, int b, int c, int *pmax, int *pmin) {
    *pmax = a > b ? a : b;
    *pmax = *pmax > c ? *pmax : c;
    *pmin = a < b ? a : b;
    *pmin = *pmin < c ? *pmin : c;
}

void maxmin_1(int a, int b, int c, int &pmax, int &pmin) {
    pmax = a > b ? a : b;
    pmax = pmax > c ? pmax : c;
    pmin = a < b ? a : b;
    pmin = pmin < c ? pmin : c;
}

int main()
{
    int a, b, c, se, min, max;
    cin >> a >> b >> c >> se;
    if (se == 0)
        maxmin_0(a, b, c, &max, &min);
    else
        maxmin_1(a, b, c, max, min);
    cout << max << ' ' << min << endl;
}
