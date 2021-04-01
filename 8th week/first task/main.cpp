#include <iostream>
#include <array>
#include <algorithm>
#include <chrono>
#include <random>

std::uniform_int_distribution dist(1, 100);
std::default_random_engine engin(std::chrono::steady_clock::now().time_since_epoch().count());

int rand(){
    return dist(engin);
}

int main() {
    std::array<int, 10> set;
    std::uniform_int_distribution dist(1, 100);
    std::default_random_engine engin(std::chrono::steady_clock::now().time_since_epoch().count());

//    Так не работает почему-то:
    
//    std::generate(set.begin(), set.end(), [dist, engin](){
//        int a = dist(engin);
//        return 1;
//    });

//    а так работает:

    std::generate(set.begin(), set.end(), rand);
    
    return 0;
}
