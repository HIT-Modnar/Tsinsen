// Source : http://www.tsinsen.com/A1027
// Author : Modnar
// Date   : 2019-03-27

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

const int MAX_SIZE = 101;

// Get the minimum from three number.
int get_min(int a, int b, int c) {
    int min_of_three = a;
    min_of_three = b < min_of_three ? b : min_of_three;
    min_of_three = c < min_of_three ? c : min_of_three;
    return min_of_three;
}

// Compute the edit distance.
int edit_dist(const std::string &str1, const std::string &str2) {
    int len1 = str1.size(), len2 = str2.size();
    int dis[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i <= len1; ++i)
        dis[i][0] = i;
    for (int i = 0; i <= len2; ++i)
        dis[0][i] = i;
    for (int i = 1; i <= len1; ++i)
        for (int j = 1; j <= len2; ++j)
            if (str1[i-1] == str2[i-1]) {
                dis[i][j] = dis[i-1][j-1];
            } else {
                dis[i][j] = get_min(dis[i-1][j]+1, dis[i][j-1]+1, dis[i-1][j-1]+1);
            }
    return dis[len1][len2];
}

// Idea:
//   Compute the edit distance between input string and other dictionary strings.
//   Use a std::vector to store the distance and string of every entry in dictionary.
//   Sort the vector by distance, then get the minimum distance's string. This is the
//   target string. However, if the string from this method still have the input's
//   length distance, should output "NOANSWER".
int main(int argc, char *argv[]) {
    std::string input, tmp;
    int n, dist;
    std::vector<std::pair<int, std::string>> dict;
    std::cin >> input >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        dist = edit_dist(input, tmp);
        dict.push_back(std::make_pair(dist, tmp));
    }
    std::stable_sort(dict.begin(), dict.end());
    if (edit_dist(dict[0].second, input) == input.size())
        std::cout << "NOANSWER" << std::endl;
    else
        std::cout << dict[0].second << std::endl;
    return 0;
}
