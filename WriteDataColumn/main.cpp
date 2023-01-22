#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::left << std::setw(24) << "John Smith"
              << std::right << std::setw(3) << 23
              << '\n';
    std::cout << std::left << std::setw(24) << "Sam Brown"
              << std::right << std::setw(3) << 8
              << '\n';
    std::cout << std::left << std::setw(24) << "test"
              << std::right << std::setw(3) << 155
              << '\n';
}
