#include <iostream>
#include <semaphore.h>
#include <thread>


#define N 100

sem_t mutex;
sem_t free_space;
sem_t used_space;

//初始化信号量
void init() {
    sem_init(&mutex, 0, 1);
    sem_init(&free_space, 0, N);
    sem_init(&used_space, 0, 0);
}

void creator() {

    while (true) {
        //空槽个数减1
        sem_wait(&free_space);
        //占用缓冲区
        sem_post(&mutex);
        std::cout << "生产者生产数据入缓冲区" << std::endl;
        //释放缓冲区
        sem_wait(&mutex);
        //满槽个数+1
        sem_post(&used_space);
    }
}

void consumer() {

    while (true) {
        //满槽个数-1
        sem_wait(&used_space);
        //占用缓冲区
        sem_post(&mutex);
        std::cout << "消费者消费数据入缓冲区" << std::endl;
        //释放缓冲区
        sem_wait(&mutex);
        //空槽个数+1
        sem_post(&free_space);
    }
}

int main() {
    init();

    std::thread t1{creator};
    std::thread t2{consumer};

    t1.join();
    t2.join();
    return 0;
}
