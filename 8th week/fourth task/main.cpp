#include <iostream>
#include <list>
#include <array>
#include <numeric>
#include <map>

int main() {
    const int count = 7;
    std::array<int, count> ar = {1, 2, 3, 4, 10, 3, 2};
    std::list<int> set(count);
    std::partial_sum(ar.begin(), ar.end(), set.begin());
    std::map <int, bool> chet;

    for(auto i:set){
        chet.insert(std::pair<int, bool>(i, i % 2 == 0));
    }

    for(auto i:chet)
        std::cout << i.first << '\t' << i.second << '\n';

    return 0;
}