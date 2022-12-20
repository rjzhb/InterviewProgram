#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mu;
int cnt_h = 0;
std::condition_variable cv;

void print_H() {
    for (int i = 0; i < 2; i++) {
        std::unique_lock<std::mutex> lock(mu);
        while (cnt_h == 2) {
            cv.wait(lock);
        }
        std::cout << "H";
        cnt_h++;
        if (cnt_h == 2)cv.notify_all();
    }
}

void print_O() {
    std::unique_lock<std::mutex> lock(mu);
    while (cnt_h != 2) {
        cv.wait(lock);
    }
    std::cout << "O";
    cnt_h = 0;
    cv.notify_all();
}

int main() {
    std::thread t1{print_H};
    std::thread t2{print_O};

    t1.join();
    t2.join();

    return 0;
}
