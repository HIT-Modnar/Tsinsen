#include <iostream>
#include <vector>

const unsigned MAX_SIZE = 10000001;

int check[MAX_SIZE];

int main(int argc, char *argv[]) {
    std::vector<int> prime;
    for (size_t i = 2; i < MAX_SIZE; ++i) {
        if (!check[i]) 
            prime.push_back(i);
        for (size_t j = 0; j < prime.size(); ++j) {
            if (i * prime[j] > MAX_SIZE)
                break;
            check[i*prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    int query;
    std::cin >> query;
    for (size_t i = 0; i < prime.size(); ++i)
        if (prime[i] == query)
            std::cout << prime[i+1] << std::endl;
    return 0;
}
