//
// Created by Bohan Gao on 9/13/20.
//

#include <array>
#include <thread>

#include "LatchDemo.h"

int LatchDemo::count = 0;
std::mutex LatchDemo::calculator;
boost::latch LatchDemo::latch(5);

void LatchDemo::test() {
    std::array<std::thread, 10> threads;
    for(int i=0;i<10;i+=2){
        threads[i] = std::thread(dubble);
        threads[i+1] = std::thread(increase);
    }
    for(int i=0;i<10;i++){
        threads[i].join();
    }
    printf("Calculated count now is %d.\n", count);
}

void LatchDemo::cpu_work(int units) {
    unsigned int x = 0;
    for (int i = 0; i < units * 1000000; i++) {
        x++;
    }
}

void LatchDemo::dubble() {
    //double threads will wait first, and once all 10 threads get to wait states,
    //barrier will be released, and all threads will proceed
    latch.wait();
    cpu_work(1);
    std::unique_lock<std::mutex> lock(calculator);
    count *= 2;
    printf("The count is dubbled.\n");
}

void LatchDemo::increase() {
    cpu_work(1);
    {
        std::unique_lock<std::mutex> lock(calculator);
        count += 3;
        printf("The count is increased by 3.\n");
    }
    latch.count_down();
    //increase thread will proceed first and wait here at the barrier.
}