//
// Created by Bohan Gao on 9/9/20.
//

#include "DeadLockDemo.h"

#include <thread>

int DeadLockDemo::sushi_count = 5000;

void DeadLockDemo::testDeadLock() {
    std::mutex chopstick1, chopstick2;
    std::thread ashley(eat, std::ref(chopstick1), std::ref(chopstick2));
    std::thread thomas(eat, std::ref(chopstick2), std::ref(chopstick1));
    ashley.join();
    thomas.join();
    printf("The philosophers are done eating.\n");
}

void DeadLockDemo::testWithPriority() {
    std::mutex chopstick1, chopstick2;
    std::thread ashley(eat, std::ref(chopstick1), std::ref(chopstick2));
    std::thread thomas(eat, std::ref(chopstick1), std::ref(chopstick2));
    ashley.join();
    thomas.join();
    printf("The philosophers are done eating.\n");
}

void DeadLockDemo::testWithScopeLock() {
    std::mutex chopstick1, chopstick2;
    std::thread ashley(eatWithScopeLock, std::ref(chopstick1), std::ref(chopstick2));
    std::thread thomas(eatWithScopeLock, std::ref(chopstick2), std::ref(chopstick1));
    ashley.join();
    thomas.join();
    printf("The philosophers are done eating.\n");
}

void DeadLockDemo::eat(std::mutex & first_chopstick, std::mutex & second_chopstick) {
    while(sushi_count>0){
        first_chopstick.lock();
        second_chopstick.lock();
        if(sushi_count>0){
            sushi_count--;
        }
        second_chopstick.unlock();
        first_chopstick.unlock();
    }
}

void DeadLockDemo::eatWithScopeLock(std::mutex & first_chopstick, std::mutex & second_chopstick) {
    while(sushi_count>0){
        std::scoped_lock(first_chopstick, second_chopstick);
        //scope can achieve
        //1. acquire multiple locks at the same time;
        //2. automatic unlock when exit the scope

        if(sushi_count>0){
            sushi_count--;
        }
    }
}
