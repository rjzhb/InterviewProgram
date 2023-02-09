#include <iostream>
#include <utility>
#include <vector>
#include <memory>

std::vector<int> b;

void set_test(std::vector<int> a) {
    b = std::move(a);
}

void set_test2(std::vector<int> &a) {
    b = std::move(a);
}

template<typename T>
void set_test3(T &&a) {
    b = std::forward<T>(a);
}

void ptr_test(std::shared_ptr<int> p) {
    std::shared_ptr<int> a;
    a = std::move(p);
}

int main() {
    std::vector<int> a{1, 2, 3};
    set_test(a);

    for (auto it: a) {
        std::cout << it << std::endl;
    }

    set_test3(a);
    for (auto it: a) {
        std::cout << it << std::endl;
    }

    std::shared_ptr<int> ptr = std::make_shared<int>(3);
    ptr_test(ptr);
    std::cout << *ptr << std::endl;
    return 0;
}
