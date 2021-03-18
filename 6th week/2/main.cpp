#include <functional>
#include <vector>

template <typename t>
void func(std::function<void(std::vector<t>)> f, std::vector<t> parametrs){
    f(parametrs);
}