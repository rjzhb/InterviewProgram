#include <iostream>
#include <memory>
#include <iomanip>

//只能传左值
void func1(int &) {}

//只能传右值
void func2(int &&) {}

//万能引用，两个都行,原理：引用折叠
template<typename T>
void func3(T &&) {}

//完美转发
template<typename T, typename Arg>
std::shared_ptr<T> factory(Arg &&arg) {
    return std::shared_ptr<T>(new T(std::forward<T>(arg)));
}

//非完美转发
template<typename T, typename Arg>
std::shared_ptr<T> factory1(Arg &&arg) {
    return std::shared_ptr<T>(new T(arg));
}

int main() {
    int val = 0;
    auto p1 = factory<int>(5);
    auto p2 = factory<int>(val);
    std::cout << std::left << std::setw(3) << "id" << std::left << std::setw(3) << "name" << std::endl;
    std::cout << std::left << std::setw(3) << 1 << std::left << std::setw(3) << "jiosa" << std::endl;
    std::cout << std::setw(3) << "id" << std::setw(3) << "name" << std::endl;
    std::cout << std::setw(3) << 1 << std::setw(3) << "jiosa" << std::endl;
    return 0;
}
