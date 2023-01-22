#include <iostream>
#include <memory>

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

int main() {
    int val = 0;
    auto p1 = factory<int>(5);
    auto p2 = factory<int>(val);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
