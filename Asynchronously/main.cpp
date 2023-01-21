#include <iostream>
#include <future>

int func() {
    int some_value = 0;
    std::cout << "异步" << std::endl;
    return some_value;
}

int main() {
    std::future<int> future_result = std::async(func);
    for (int i = 0; i < 10; i++) {
        std::cout << "h" << std::endl;
    }
    std::cout << future_result.get() << std::endl;
    return 0;
}
