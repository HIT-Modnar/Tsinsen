// Source : http://www.tsinsen.com/A1081
// Author : Modnar
// Date   : 2019-03-13

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

double getRoot(double (*f)(double), double a, double b) {
    // As for the question at Tsinsen.com, just need to submit the follow code 
    // in the function body.
    double mid = (a + b) / 2;
    while (std::fabs(f(mid)) >= 1E-6) {
        if (f(mid) * f(a) > 0)
            a = mid;
        else if (f(mid) * f(b) > 0)
            b = mid;
        mid = (a + b) / 2;
    }
    return mid;
}

// Root is 0
double func1(double x) {
    return x * x;
}

// Root is 0.5
double func2(double x) {
    return (x-0.5) * (x-0.5);
}

// Root is 0.999999 and -0.999999
double func3(double x) {
    return (x-0.999999) * (x+0.999999);
}

// Root is 0.9999999 and -0.9999999, while for the question, they should be
// round to 1 and -1.
double func4(double x) {
    return (x-0.9999999) * (x+0.9999999);
}

// Here, the main function is used for testing.
int main(int argc, char *argv[]) {
    std::cout << getRoot(func1, -1.0, 1.0) << std::endl;

    std::cout << getRoot(func2, -1.0, 1.0) << std::endl;

    std::cout << getRoot(func3, 0.0, 1.0) << std::endl;
    std::cout << getRoot(func3, -1.0, 0.0) << std::endl;

    std::cout << getRoot(func4, 0.0, 1.0) << std::endl;
    std::cout << getRoot(func4, -1.0, 0.0) << std::endl;
    return 0;
}
