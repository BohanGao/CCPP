//
// Created by Bohan Gao on 9/13/20.
//

#include <array>
#include <thread>

#include "SemaphoreDemo.h"

Semaphore SemaphoreDemo::charger(4);

void SemaphoreDemo::test() {
    std::array<std::thread, 10> phones;
    for (int i = 0; i < 10; i++) {
        phones[i] = std::thread(chargePhone, i);
    }
    for (int i = 0; i < 10; i++) {
        phones[i].join();
    }
}

void SemaphoreDemo::chargePhone(int phoneId) {
    charger.acquire();
    printf("Phone %d is charging...\n", phoneId);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    printf("Phone %d is done charging.\n", phoneId);
    charger.release();
}
