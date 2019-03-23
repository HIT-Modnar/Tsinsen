// Source : http://www.tsinsen.com/A1080
// Author : Modnar
// Date   : 2019-03-23

#include <iostream>
#include <algorithm>

using namespace std;

// 计算F(n)和F(n+1)除m的余数，分别放入fn和fn1中。
// Compute F(n) and F(n+1) after molding m and store them at fn and fn1.
void calcF(int n, int m, int &fn, int &fn1) {
    // If you want to submit at tsinsen.com, submit the code in the function body.
    if (n == 1) {
        fn = 1 % m;
        fn1 = 1 % m;
        return;
    } else if (n == 2) {
        fn = 1 % m;
        fn1 = 2 % m;
        return;
    }
    if (n % 2) { 
        // If n is an odd number. Then we can treat n as 2k+1.
        // Here, we need to compute f(n)[as f(2k+1)] and f(n+1)[as f(2k+2)].
        int f1, f2, f3, f4;
        // Before computing f(n)[as f(2k+1)], we need to compute f(n/2)[as f(k)] and
        // f(n/2+1)[as f(k+1)]. 
        // Then use the relationship
        //         f(2k+1) = f(k+1)*f(k+1)+f(k)*f(k)
        // to compute f(n)[as f(2k+1)].
        // Here, f1 is f(n/2)[as f(k)] and f2 is f(n/2+1)[as f(k+1)].
        calcF(n/2, m, f1, f2);
        // Before computing f(n+1)[as f(2k+2)], we need to compute f((n+1)/2)[as 
        // f(k+1)] and f((n+1)/2+1)[as f(k+2)].
        // Then use the relationship
        //         f(2k) = f(k+1)*f(k)+f(k)*f(k-1)
        //               = f(k)*[f(k+1)+f(k-1)]
        //         f(2k+2) = f(2*(k+1)) 
        //                 = f(k+1)*[f(k+2)+f(k)]
        // to compute f(n+1)[as f(2k+2)].
        // Here, f3 is f((n+1)/2)[as f(k+1)] and f4 is f((n+1)/2+1)[as f(k+2)].
        calcF((n+1)/2, m, f3, f4);
        // Here, fn is f(n)[as f(2k+1)] and fn1 is f(n+1)[as f(2k+2)].
        fn = (f1 * f1 + f2 * f2) % m;
        fn1 = f2 * (f4 + f1) % m;
    } else { 
        // Else n is an even number. Then we can treat n as 2k.
        // Here we need to compute f(n)[as f(2k)] and f(n+1)[as f(2k+1)].
        int f1, f2;
        // Before computing f(n)[as f(2k)], we need to compute f(n/2)[as f(k)] and
        // f(n/2+1)[as f(k+1)].
        // Then use the relationship
        //         f(2k) = f(k)*f(k+1)+f(k)*[f(k+1)-f(k)]
        //               = f(k)*[2*f(k+1)-f(k)]
        // to compute f(n)[as f(2k)].
        // Here, f1 is f(n/2)[as f(k)] and f2 is f(n/2+1)[as f(k+1)].
        // Besides, before computing f(n+1)[as for(2k+1)], we also need to compute
        // f(n/2)[as f(k)] and f(n/2+1)[as f(k+1)].
        // Then use the relationship
        //         f(2k+1) = f(k)*f(k)+f(k+1)*f(k+1)
        // to compute f(n+1)[as f(2k+1)].
        calcF(n/2, m, f1, f2);
        // Here, fn is f(n)[as f(2k)] (in case of the value's overflow, here need to 
        // add m) and fn1 is f(n+1)[as f(2k+1)].
        fn = (f1 * f2 + f1 * (f2 - f1 + m)) % m;
        fn1 = (f1 * f1 + f2 * f2) % m;
    }
}

int main(int argc, char *argv[]) {
    int f1, f2;
    int val = 1, m = 100;
    if (argc > 1) {
        // Test
        val = atoi(argv[1]);
        m = atoi(argv[2]);
    }
    calcF(val, m, f1, f2);
    std::cout << f1 << " " << f2 << std::endl;
    return 0;
}
