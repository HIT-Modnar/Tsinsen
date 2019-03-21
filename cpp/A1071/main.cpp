// Source : http://www.tsinsen.com/A1071
// Author : Modnar
// Date   : 2019-03-17

#include <iostream>
#include <algorithm>
#include <vector>

class Person {
public:
    Person(int ID, int score) : ID(ID), score(score) { }
    int ID;
    int score;
};

bool sort_by_score(Person p1, Person p2) {
    return p1.score > p2.score;
}

bool sort_by_ID(Person p1, Person p2) {
    return p1.ID < p2.ID;
}

int main(int argc, char *argv[]) {
    int n, m, ID, score;
    std::vector<Person> ans;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> ID >> score;
        ans.push_back(Person(ID, score));
    }
    std::sort(ans.begin(), ans.end(), sort_by_score);
    int target_number =  (int)(m * 1.5);
    int score_line = ans[target_number-1].score;
    for (int i = target_number; i < ans.size(); ++i)
        if (ans[i].score == score_line)
            ++target_number;
    std::sort(ans.begin(), ans.begin()+target_number, sort_by_ID);
    std::stable_sort(ans.begin(), ans.begin()+target_number, sort_by_score);
    std::cout << score_line << " " << target_number << std::endl;
    for (int i = 0; i < target_number; ++i)
        std::cout << ans[i].ID << " " << ans[i].score << std::endl;
    return 0;
}
