#include <iostream>
#include <chrono>
#include <cmath>

class timer{
using clock = std::chrono::steady_clock;
using timepoint = clock::time_point;
using mcs = std::chrono::microseconds;
public:
    timer(){
        timepoint begin = clock::now();
    }
    ~timer(){
        timepoint end = clock::now();

        std::cout << std::chrono::duration_cast<mcs>(end - begin).count() << '\n';
    }
private:
    timepoint begin, end;

};


int main()
{
    return 0;
}
