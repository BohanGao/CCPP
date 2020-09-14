//
// Created by Bohan Gao on 9/13/20.
//

#include <array>
#include <thread>

#include "RaceConditionDemo.h"

int RaceConditionDemo::count = 0;
std::mutex RaceConditionDemo::calculator;

void RaceConditionDemo::test() {
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

void RaceConditionDemo::cpu_work(int units) {
    unsigned int x = 0;
    for (int i = 0; i < units * 1000000; i++) {
        x++;
    }
}

void RaceConditionDemo::dubble() {
    cpu_work(1);
    std::unique_lock<std::mutex> lock(calculator);
    count *= 2;
    printf("The count is dubbled.\n");
}

void RaceConditionDemo::increase() {
    cpu_work(1);
    std::unique_lock<std::mutex> lock(calculator);
    count += 3;
    printf("The count is increased by 3.\n");
}
