// Source : http://www.tsinsen.com/A1001
// Author : Modnar
// Date   : 2019-01-17

#include <iostream>

int main() {
    char ans[7] = "000000";
    for(int i = 0; i < 64; i++) {
        std::cout << ans << std::endl;
        for(int j = 5; j >= 0; j--) {
            if(ans[j] == '1') {
                ans[j] = '0';
                continue;
            } else {
                ans[j] = '1';
                break;
            }
        }
    }
    return 0;
}
