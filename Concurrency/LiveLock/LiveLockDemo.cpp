//
// Created by Bohan Gao on 9/10/20.
//

#include <thread>

#include "LiveLockDemo.h"

int LiveLockDemo::sushi_count = 5000;

void LiveLockDemo::testWithYeild() {
    std::mutex chopstick1, chopstick2;
    std::thread ashley(eatWithYield, std::ref(chopstick1), std::ref(chopstick2));
    std::thread thomas(eatWithYield, std::ref(chopstick2), std::ref(chopstick1));
    std::thread taro(eatWithYield, std::ref(chopstick1), std::ref(chopstick2));
    std::thread dolby(eatWithYield, std::ref(chopstick2), std::ref(chopstick1));
    ashley.join();
    thomas.join();
    taro.join();
    dolby.join();
    printf("The philosophers are done eating.\n");
}

void LiveLockDemo::testWithoutYeild() {
    std::mutex chopstick1, chopstick2;
    std::thread ashley(eatWithoutYield, std::ref(chopstick1), std::ref(chopstick2));
    std::thread thomas(eatWithoutYield, std::ref(chopstick2), std::ref(chopstick1));
    std::thread taro(eatWithoutYield, std::ref(chopstick1), std::ref(chopstick2));
    std::thread dolby(eatWithoutYield, std::ref(chopstick2), std::ref(chopstick1));
    ashley.join();
    thomas.join();
    taro.join();
    dolby.join();
    printf("The philosophers are done eating.\n");
}

void LiveLockDemo::eatWithYield(std::mutex & first_chopstick, std::mutex & second_chopstick) {
    while(sushi_count>0){
        first_chopstick.lock();
        if(!second_chopstick.try_lock()){
            first_chopstick.unlock();
            std::this_thread::yield();
            //provides a hint to the implementation to reschedule the execution of threads,
            //allowing other threads to run
        } else {
            if(sushi_count>0){
                sushi_count--;
            }
            second_chopstick.unlock();
            first_chopstick.unlock();
        }
    }
}

void LiveLockDemo::eatWithoutYield(std::mutex & first_chopstick, std::mutex & second_chopstick) {
    while(sushi_count>0){
        first_chopstick.lock();
        if(!second_chopstick.try_lock()){
            first_chopstick.unlock();
        } else {
            if(sushi_count>0){
                sushi_count--;
            }
            second_chopstick.unlock();
            first_chopstick.unlock();
        }
    }
}
