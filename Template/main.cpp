#include <iostream>

template<int N>
constexpr int fact() {
    if constexpr (N != 0) {
        return N * fact<N - 1>();
    } else {
        return 1;
    }
}


int main() {
    std::cout << fact<3>() << std::endl;
    std::cout << fact<0>() << std::endl;
    return 0;
}
