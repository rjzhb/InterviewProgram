#include <iostream>
#include <utility>
#include <vector>

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

    return 0;
}
