// Source : http://www.tsinsen.com/A1099
// Author : Modnar
// Date   : 2019-03-21

#include <iostream>
#include <string>

const int MAX_NUM = 8;

std::string dayStr[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", 
                      "Saturday", "Sunday"};

int get_day(const std::string &day_str) {
    switch (day_str[0]) {
        case 'M':
        case 'm':
            return 1;
        case 'T':
        case 't':
            if (day_str[1] == 'U' || day_str[1] == 'u')
                return 2;
            else 
                return 4;
        case 'W':
        case 'w':
            return 3;
        case 'F':
        case 'f':
            return 5;
        case 'S':
        case 's':
            if (day_str[1] == 'A' || day_str[1] == 'a')
                return 6;
            else 
                return 7;
    }
    return -1;
}

//
// The idea from http://www.tsinsen.com/Forum/view.page?topicid=5212
// The idea is so cool! Thanks @zhukaihao(朱凯豪) (from tsinsen.com) here.
//
// Idea:
//   From the describe of the question, everyone's statements must be one is true and 
//   the other one is false. So we can get conclusion: as for the answer x, the x can 
//   match ONE TRUE and ONE FALSE from everyone's statement. And this means if x get 
//   BOTH TRUE or BOTH FALSE from anyone's statement, the x can not be the right 
//   answer! The judgement "ans == 8" means x (ans) can get one true and one false 
//   from everyone's statement, so the ans must be the right answer!
//
int main(int argc, char *argv[]) {
    int yes[MAX_NUM], no[MAX_NUM];
    std::string day1, day2;
    size_t i, ans;
    for (i = 0; i < 8; ++i) {
        std::cin >> day1 >> day2;
        yes[i] = get_day(day1);
        no[i] = get_day(day2);
    }
    for (ans = 1; ans <= 7; ++ans) {
        for (i = 0; i < 8; ++i) {
            // This judgement is the key!
            if ((ans == yes[i] && ans != no[i]) || (ans != yes[i] && ans == no[i]))
                break;
        }
        if (i == 8)
            break;
    }
    std::cout << dayStr[ans-1] << std::endl;
    return 0;
}
