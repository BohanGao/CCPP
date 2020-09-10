//
// Created by Bohan Gao on 9/9/20.
//

#include <thread>

#include "AbandondedLockDemo.h"

int AbandondedLockDemo::sushi_count = 5000;

void AbandondedLockDemo::testAbandonedLock() {
    std::mutex chopsticks;
    std::thread ashley(eatWithoutScopedLock, std::ref(chopsticks));
    std::thread thomas(eatWithoutScopedLock, std::ref(chopsticks));
    ashley.join();
    thomas.join();
    printf("The philosophers are done eating.\n");
}

void AbandondedLockDemo::testScopedLock() {
    std::mutex chopsticks;
    std::thread ashley(eatWithScopedLock, std::ref(chopsticks));
    std::thread thomas(eatWithScopedLock, std::ref(chopsticks));
    ashley.join();
    thomas.join();
    printf("The philosophers are done eating.\n");
}

void AbandondedLockDemo::eatWithoutScopedLock(std::mutex & chopsticks) {
    while (sushi_count>0){
        chopsticks.lock();
        if(sushi_count>0){
            sushi_count--;
        }
        if(sushi_count == 10){
            printf("This philosopher stops eating now.\n");
            break;//leaves the lock unreleased, other thread can never acquire it.
        }
        chopsticks.unlock();
    }
}

void AbandondedLockDemo::eatWithScopedLock(std::mutex & chopsticks) {
    while (sushi_count>0){
        std::scoped_lock scopedLock(chopsticks);
        if(sushi_count>0){
            sushi_count--;
        }
        if(sushi_count == 10){
            printf("This philosopher stops eating now.\n");
            break;
        }
    }
}
