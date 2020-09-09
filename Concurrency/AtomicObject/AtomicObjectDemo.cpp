//
// Created by Bohan Gao on 9/8/20.
//

#include <thread>

#include "AtomicObjectDemo.h"

std::atomic<unsigned int> AtomicObjectDemo::garlic_count(0);

void AtomicObjectDemo::test() {
    std::thread ashley(inc);
    std::thread thomas(inc);

    ashley.join();
    thomas.join();

    printf("We should buy %d garlics.\n", garlic_count.load());
}

void AtomicObjectDemo::inc() {
    for (int i = 0; i < 10000000; i++) {
        garlic_count++;
    }
}
