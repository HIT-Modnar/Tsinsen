// Source : http://www.tsinsen.com/A1065
// Author : Modnar
// Date   : 2019-04-02

#include <iostream>
#include <utility>
#include <vector>

const int MAX_SIZE = 4;

double vt[MAX_SIZE], vr[MAX_SIZE];

int main(int argc, char *argv[]) {
    int n;
    double T;
    std::vector<std::pair<int, double>> path;
    std::cin >> n >> T;
    for (int i = 0; i < MAX_SIZE; ++i)
        std::cin >> vt[i];
    for (int i = 0; i < MAX_SIZE; ++i)
        std::cin >> vr[i];
    for (int i = 0; i < n; ++i) {
        int type;
        double length;
        std::cin >> type >> length;
        path.push_back(std::make_pair(type, length));
    }
    std::cout << "Finished." << std::endl;
    return 0;
}
