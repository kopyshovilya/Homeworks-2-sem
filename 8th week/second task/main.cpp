#include <iostream>
#include <list>
#include <array>
#include <numeric>

int main() {
    std::array<int, 4> ar = {1, 2, 3, 4};
    std::list<int> set(4);
    std::partial_sum(ar.begin(), ar.end(), set.begin());

    for(auto i:set)
        std::cout << i << '\t';

    return 0;
}