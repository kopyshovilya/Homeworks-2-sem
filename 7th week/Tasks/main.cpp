#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <numeric>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <typeinfo>
//#include <bits/stdc++.h>

const int sizeOfDeque = 6;


template <typename T>
void print(int i, T array){
    std::cout << std::to_string(i) << ") ";
    for(auto i : array) {
        std::cout << i << '\t';
    }
    std::cout << '\n';
}

//template <typename T>
//class d : std::deque<T>{
//    friend std::ostream& operator<<(std::ostream &out, const std::deque<T> array){
//        for(auto i : array) {
//            out << i << '\t';
//        }
//        out << '\n';
//        return out;
//    }
//};
//           Почему не работает перегрузка оператора << для очереди?

std::deque<int> deq(sizeOfDeque);

int main() {
    srand(100);
//////////// First task /////////////////////
    std::generate(deq.begin(), deq.end(), [](){return deq.size() - std::count(deq.begin(), deq.end(), 0) + 1;});
//    std::iota(deq.begin(), deq.end(), 1);  // или так :)
    print(1, deq);
//////////// Second task /////////////////////
    std::uniform_int_distribution dist(1, sizeOfDeque);
    
    std::default_random_engine engin(std::chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 1; i < dist(engin) % sizeOfDeque + 1; i++){
        deq.push_front(1 + dist(engin) % sizeOfDeque);
    }
    print(2, deq);
//////////// Third task /////////////////////
    std::vector<int> vec(deq.size());
    std::copy(deq.begin(), deq.end(), vec.begin());
    print(3, vec);
//////////// Fourth task /////////////////////
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    print(4, vec);
//////////// Fifth task /////////////////////
    std::default_random_engine engine(std::chrono::steady_clock::now().time_since_epoch().count());
    std::shuffle(std::begin(deq), std::end(deq), engine);
    print(5, deq);
//////////// Sixth task /////////////////////
    auto result = std::inner_product(vec.begin(), vec.end(), deq.begin(), 0);
    std::cout << "6) " << result << '\n';
//////////// Seventh task /////////////////////
    auto count = std::count_if(deq.begin(), deq.end(), [](int i) {return i > 4;});
    std::cout << "7) " << count << '\n';
//////////// Eighth task /////////////////////
    auto sumVec = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "8) " << sumVec << '\n';
//////////// Ninth task /////////////////////
    int proizvVec = std::accumulate(deq.begin(), deq.end(), 1, [](int x, int y){return x * y;});
    std::cout << "9) " << proizvVec << '\n';
//////////// Tenth task /////////////////////
//    print(10, vec);
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int a){return (a % 2 == 0) && (a > 3);}), vec.end());
    print(10, vec);
//////////// Eleventh task /////////////////////
//    print(11, deq);
    deq.erase(std::remove(deq.begin(), deq.end(), 4), deq.end());
    print(11, deq);
//////////// Twelfth task /////////////////////
    std::cout << "12) ";
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << '\t';
    }
//////////// Thirteenth task /////////////////////
    std::cout << "\n13) ";
    std::for_each(deq.begin(), deq.end(), [](int a){std::cout << a << "\t";return a;});
//////////// Fourteenth task /////////////////////
    auto minmaxDeq = std::minmax_element(deq.begin(), deq.end());
    auto minmaxVec = std::minmax_element(vec.begin(), vec.end());
    std::cout << "\nDeque\tmin: " << *minmaxDeq.first << "\tmax: " << *minmaxDeq.second;
    std::cout << "\nVector\tmin: " << *minmaxVec.first << "\tmax: " << *minmaxVec.second;
    return 0;
}
