//
// Created by Bohan Gao on 9/8/20.
//

#include <thread>

#include "MutualExclusionDemo.h"

unsigned int MutualExclusionDemo::garlic_count = 0;
std::mutex MutualExclusionDemo::lock_mutex;

void MutualExclusionDemo::test() {
    std::thread ashley(inc);
    std::thread thomas(inc);

    ashley.join();
    thomas.join();

    printf("We should buy %d garlics.\n", garlic_count);
}

void MutualExclusionDemo::inc() {
    //lock_mutex.lock();
    //inefficient lock
    for (int i = 0; i < 10000000; i++) {
        lock_mutex.lock();
        //only lock the part where it needs to be locked to be more efficient.
        garlic_count++;
        lock_mutex.unlock();
    }
    //lock_mutex.unlock();
}
