//
// Created by Bohan Gao on 9/10/20.
//

#include <array>
#include <thread>

#include "StarvationDemo.h"

int StarvationDemo::sushi_count = 5000;

void StarvationDemo::test() {
    std::mutex chopsticks;
    std::array<std::thread, 200> philosophers;
    for(int i=0;i<200;i++){
        philosophers[i] = std::thread(eatWithScopedLock, std::ref(chopsticks));
    }
    for(int i=0;i<200;i++){
        philosophers[i].join();
    }
    printf("The philosophers are done eating.\n");
}

void StarvationDemo::eatWithScopedLock(std::mutex &chopsticks) {
    int suchi_eaten = 0;
    while (sushi_count>0){
        std::scoped_lock scopedLock(chopsticks);
        if(sushi_count>0){
            sushi_count--;
            suchi_eaten++;
        }
        printf("""Philosopher %d ate %d sushi.\n", std::this_thread::get_id(), suchi_eaten);
    }
}