#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//int findName(const std::vector<std::string> &nameVec, int low, int high, 
//        std::string query) {
//    while (low < high) {
//        int mid = (low + high) / 2;
//        if (nameVec[mid] > query) {
//            high = mid - 1;
//        } else if (nameVec[mid] < query) {
//            low = mid + 1;
//        } else {
//            return mid;
//        }
//    }
//    return -1;
//}

int main(int argc, char *argv[]) {
    std::vector<std::string> nameVec;
    int n, ansIndex = 0;
    std::string query;
    std::cin >> n >> query;
    while (n--) {
        std::string tmp;
        std::cin >> tmp;
        nameVec.push_back(tmp);
    }
    std::sort(nameVec.begin(), nameVec.end());
//    ansIndex = findName(nameVec, 0, nameVec.size()-1, query);
//    if (ansIndex == nameVec.size()-1)
//        std::cout << "The End" << std::endl;
//    else 
//        std::cout << nameVec[ansIndex+1] << std::endl;
    for (size_t i = 0; i < nameVec.size(); ++i)
        if (nameVec[i] == query) {
            if (i == nameVec.size()-1) 
                std::cout << "The End" << std::endl;
            else 
                std::cout << nameVec[i+1] << std::endl;
            break;
        }
    return 0;
}
