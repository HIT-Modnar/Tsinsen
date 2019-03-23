// Source : http://www.tsinsen.com/A1067
// Author : Modnar
// Date   : 2019-03-23

#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    int s, t, a, b, c, d;
    std::cin >> s >> t >> a >> b >> c >> d;
    std::vector<int> fib_mod_a(t+1), fib_mod_b(t+1), fib_mod_c(t+1), fib_mod_d(t+1);
    fib_mod_a[1] = fib_mod_b[1] = fib_mod_c[1] = fib_mod_d[1] = 1;
    for (size_t i = 2; i <= t; ++i) {
        fib_mod_a[i] = (fib_mod_a[i-1] + fib_mod_a[i-2]) % a;
        fib_mod_b[i] = (fib_mod_b[i-1] + fib_mod_b[i-2]) % b;
        fib_mod_c[i] = (fib_mod_c[i-1] + fib_mod_c[i-2]) % c;
        fib_mod_d[i] = (fib_mod_d[i-1] + fib_mod_d[i-2]) % d;
    }
    for (size_t i = s; i <= t; ++i)
        if (fib_mod_a[i] && fib_mod_b[i] && fib_mod_c[i] && fib_mod_d[i])
            std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
