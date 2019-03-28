// Source : http://www.tsinsen.com/A1043
// Author : Modnar
// Date   : 2019-03-28

#include <iostream>
#include <string>

//
// The idea from http://www.tsinsen.com/Forum/view.page?topicid=5126
// Thanks the author @zhukaihao(朱凯豪) (from tsinsen.com) here.
//
// Idea:
//   Use two pointers that one point to the start of the sequence, and the other one 
//   point to the end of the sequence. Let the two pointer move towards middle of the
//   sequence. If the first pointer (call it i) is equal to the second pointer (call 
//   it j), judge whether the length of the sequence is even. If so, that means a 
//   sequence with even length has a single character, then we can make sure the 
//   sequence can not be a perfect sequence and just print "Impossible". Otherwise, 
//   we should mark we have found a single character. If we find another single 
//   character next time, we also should print "Impossible". As for the first time we
//   find a single character, we can make sure the character should be moved to the 
//   middle, and we can make sure the move times should add 'len / 2 - i'.
//   As for the comman circumstances, we should move the character from k to len-i. 
//   Because of the i and j changes at the same time, we should add 'j - k' this time.
//   Repeat the process until the two pointers get the same position.
//
int main(int argc, char *argv[]) {
    int len, diff_char_num = 0, ans = 0; 
    std::string input;
    std::cin >> len >> input;
    for (int i = 0, j = len-1; i < j; ++i) {
        int k = j;
        while (input[i] != input[k])
            --k;
        if (i == k) {
            ++diff_char_num;
            if (len % 2 == 0 || diff_char_num > 1) {
                std::cout << "Impossible" << std::endl;
                return 0;
            } else {
                ans += len / 2 - i;
            }
        } else {
            for (int m = k; m < j; ++m)
                input[m] = input[m+1];
            ans += j - k;
            --j;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
