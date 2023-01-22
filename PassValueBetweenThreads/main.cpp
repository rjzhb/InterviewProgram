#include <iostream>
#include <future>

/**
 * 线程之间传递信息
 * @param result_promise
 */

void func(std::promise<int> result_promise) {
    result_promise.set_value(500);
}

void receive(std::future<int> result_future, int &val){
    val = result_future.get();
}

int main() {
    int val = 0;
    std::promise<int> result_promise;
    std::future<int> result_future = result_promise.get_future();

    std::thread t1{func, std::move(result_promise)};
    std::thread t2{receive,std::move(result_future), std::ref(val)};

    t1.join();
    t2.join();

    std::cout << val << std::endl;
    return 0;
}
