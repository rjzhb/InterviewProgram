#include <iostream>
#include <mutex>
#include <unistd.h>
#include <thread>

std::mutex lock_1;
std::mutex lock_2;

void first_thread() {
    //先获取锁1
    std::cout << "线程1尝试获取锁1" << std::endl;
    lock_1.lock();
    std::cout << "线程1获得了锁1" << std::endl;
    //睡眠一秒
    sleep(1);
    //尝试获取锁2
    std::cout <<"线程1尝试获取锁2" <<std::endl;
    lock_2.lock();
    std::cout <<"线程1获得了锁2" <<std::endl;
    //释放锁2
    lock_2.unlock();
    //释放锁1
    lock_1.unlock();
}

void second_thread() {
    //先获取锁2
    std::cout << "线程2尝试获取锁2" << std::endl;
    lock_2.lock();
    std::cout << "线程2获得了锁2" << std::endl;
    //睡眠一秒
    sleep(1);
    //尝试获取锁1
    std::cout <<"线程2尝试获取锁1" <<std::endl;
    lock_1.lock();
    std::cout <<"线程2获得了锁1" <<std::endl;
    //释放锁1
    lock_1.unlock();
    //释放锁2
    lock_2.unlock();
}

int main() {
    std::thread t1{first_thread};
    std::thread t2{second_thread};

    t1.join();
    t2.join();
    return 0;
}
