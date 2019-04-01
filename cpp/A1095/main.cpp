// Source : http://www.tsinsen.com/A1095
// Author : Modnar
// Date   : 2019-04-01

#include <iostream>
#include <vector>

const int MAX_NUM = 8;
const int DEPT_NUM = 4;

const int capacity[MAX_NUM] = {120, 40, 85, 50, 100, 140, 70, 100};
int flag[DEPT_NUM];

int main(int argc, char *argv[]) {
    int a, b, c, d;
    std::vector<int> ans;
    std::cin >> a >> b >> c >> d;
    bool found_ans = false;
    for (int ia = 0; ia < MAX_NUM; ++ia) {
        if (capacity[ia] >= a && flag[ia] == 0) {
            flag[ia] = 1;
            ans.push_back(ia+1);
        } else continue;
        for (int ib = 0; ib < MAX_NUM; ++ib) {
            if (capacity[ib] >= b && flag[ib] == 0) {
                flag[ib] = 1;
                ans.push_back(ib+1);
            } else continue;
            for (int ic = 0; ic < MAX_NUM; ++ic) {
                if (capacity[ic] >= c && flag[ic] == 0) {
                    flag[ic] = 1;
                    ans.push_back(ic+1);
                } else continue;
                for (int id = 0; id < MAX_NUM; ++id) {
                    if (capacity[id] >= d && flag[id] == 0) {
                        found_ans = true;
                        for (int x = 0; x < ans.size(); ++x)
                            std::cout << ans[x] << " ";
                        std::cout << (id+1) << std::endl;
                    }
                }
                flag[ic] = 0;
                ans.pop_back();
            }
            flag[ib] = 0;
            ans.pop_back();
        }
        flag[ia] = 0;
        ans.pop_back();
    }
    if (!found_ans)
        std::cout << -1 << std::endl;
    return 0;
}
