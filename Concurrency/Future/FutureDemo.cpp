//
// Created by Bohan Gao on 9/14/20.
//

#include <future>

#include "FutureDemo.h"

void FutureDemo::test() {
    printf("How many vegetables are there in the pantry.\n");
    std::future<int> result = std::async(std::launch::async, countVegetables);
    printf("Main thread can proceed while countVegetables is executed asynchronously.\n");
    printf("Counted result is %d.\n", result.get());
    //calling get() will return the actual result value.
    //however if the future hasn't completed execution yet,
    //then invoking the get function will block execution and wait here until it's ready.
}

int FutureDemo::countVegetables() {
    printf("Counting vegetables...\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 100;
}
