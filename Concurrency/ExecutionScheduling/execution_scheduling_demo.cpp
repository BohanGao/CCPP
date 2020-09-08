//
// Created by Bohan Gao on 9/7/20.
//

#include <thread>
#include <chrono>

#include "execution_scheduling_demo.h"

bool Execution_Scheduling_Demo::chopping = true;

void Execution_Scheduling_Demo::vegetable_chopper(const char *name) {
    unsigned int vegetable_count = 0;
    while (Execution_Scheduling_Demo::chopping) {
        vegetable_count++;
    }
    printf("%s chopped %u vegetables.\n", name, vegetable_count);
}

int Execution_Scheduling_Demo::test(){
    std::thread ashley(vegetable_chopper, "Ashley");
    std::thread thomas(vegetable_chopper, "Thomas");

    printf("Ashley and Thomas are chopping vegetables...\n");

    std::this_thread::sleep_for(std::chrono::seconds(1));

    Execution_Scheduling_Demo::chopping = false;

    ashley.join();
    thomas.join();

    return 0;
}