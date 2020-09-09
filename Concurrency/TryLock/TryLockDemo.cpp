//
// Created by Bohan Gao on 9/8/20.
//

#include <thread>
#include <chrono>

#include "TryLockDemo.h"

unsigned int TryLockDemo::items_on_list;
std::mutex TryLockDemo::lock_mutex;

void TryLockDemo::testWithTryLock() {
    auto start_time = std::chrono::steady_clock::now();
    std::thread ashley(searchAndUpdateWithTryLock, "Ashley");
    std::thread thomas(searchAndUpdateWithTryLock, "Thomas");
    ashley.join();
    thomas.join();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - start_time);
    printf("Elapsed Time = %.2f seconds.\n", elapsed_time/1000.0);
}

void TryLockDemo::testWithoutTryLock() {
    auto start_time = std::chrono::steady_clock::now();
    std::thread ashley(searchAndUpdateWithoutTryLock, "Ashley");
    std::thread thomas(searchAndUpdateWithoutTryLock, "Thomas");
    ashley.join();
    thomas.join();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - start_time);
    printf("Elapsed Time = %.2f seconds.\n", elapsed_time/1000.0);
}

void TryLockDemo::searchAndUpdateWithTryLock(const char *name) {
    int items_to_add = 0;
    while (items_on_list <= 20) {
        if (items_to_add > 0 && lock_mutex.try_lock()) {//if does not have the lock, go to else
            items_on_list += items_to_add;
            printf("%s added %u item(s) to list.\n", name, items_to_add);
            items_to_add = 0;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            lock_mutex.unlock();
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            items_to_add++;
            printf("%s found something else to buy.\n", name);
        }
    }
}

void TryLockDemo::searchAndUpdateWithoutTryLock(const char *name) {
    int items_to_add = 0;
    while (items_on_list <= 20) {
        if (items_to_add > 0) {
            lock_mutex.lock();//if does not get lock, block here
            items_on_list += items_to_add;
            printf("%s added u% item(s) to list.\n", name, items_to_add);
            items_to_add = 0;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            lock_mutex.unlock();
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            items_to_add++;
            printf("%s found something else to buy.\n", name);
        }
    }
}
